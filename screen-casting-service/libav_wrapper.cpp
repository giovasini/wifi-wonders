#include <map>
#include <fmt/core.h>
#include "libav_wrapper.h"

std::unique_ptr<LibAvWrapper>   LibAvWrapper::_instance{nullptr};
std::once_flag                  LibAvWrapper::_once_flag{};

LibAvWrapper::LibAvWrapper() {
    _input_format_context = nullptr;
    _output_format_context = nullptr;
    _input_video_stream = nullptr;
    _output_video_stream = nullptr;

    _sws_context = nullptr;

    _decoder_codec = nullptr;
    _decoder_context = nullptr;

    _encoder_codec = nullptr;
    _encoder_context = nullptr;
}

LibAvWrapper &LibAvWrapper::getInstance() {
    std::call_once(_once_flag, [&]() { _instance.reset(new LibAvWrapper()); });
    return *_instance;
}

bool LibAvWrapper::init(const LibAvConfig &input_config, const LibAvConfig &output_config) {

    avdevice_register_all();
    avformat_network_init();

    int ret;

    /* INPUT CONTEXT */

    // Allocate a context for the device
    _input_format_context = avformat_alloc_context();
    if (!_input_format_context) {
        return false;
    }

    // Find the input format associated to the input device
    auto inputFormat = av_find_input_format(input_config.format.c_str());
    if (!inputFormat) {
        return false;
    }

    // Build the av_options for the device
    std::map<std::string, std::string> options = {
            {"framerate",  std::to_string(input_config.fps)},
            {"video_size", fmt::format("{}x{}", input_config.width, input_config.height)}
    };
    AVDictionary *av_options = nullptr;
    for (const auto &option: options) {
        ret = av_dict_set(&av_options, option.first.c_str(), option.second.c_str(), 0);
        if (ret < 0) {
            return false;
        }
    }

    auto inputURL = input_config.url.c_str();

    // Open the input device
    ret = avformat_open_input(&_input_format_context, inputURL, inputFormat, &av_options);
    if (ret < 0) {
        return false;
    }

    // Find device's streams info
    _input_format_context->probesize = 32000000;  // size of the buffer containing the frames used to get streams info
    ret = avformat_find_stream_info(_input_format_context, nullptr);
    if (ret < 0) {
        return false;
    }

    // Find the main video stream
    int streamIndex = av_find_best_stream(_input_format_context, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
    if (streamIndex < 0) {
        return false;
    }
    _input_video_stream = _input_format_context->streams[streamIndex];


    /* OUTPUT CONTEXT */

    // Allocate a context for the output
    ret = avformat_alloc_output_context2(&_output_format_context,
                                         nullptr,
                                         output_config.format.c_str(),
                                         output_config.url.c_str());
    if (ret < 0) {
        return false;
    }

    if (_output_format_context->oformat->flags & AVFMT_GLOBALHEADER)
        _output_format_context->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

    if (!(_output_format_context->oformat->flags & AVFMT_NOFILE)) {
        ret = avio_open(&_output_format_context->pb, output_config.url.c_str(), AVIO_FLAG_WRITE);
        if (ret < 0) {
            return false;
        }
    }

    // Add new output video stream
    _output_video_stream = avformat_new_stream(_output_format_context, nullptr);
    if (!_output_video_stream) {
        return false;
    }
    _output_video_stream->time_base = {1, output_config.fps};


    /* DECODER */

    _decoder_codec = avcodec_find_decoder(_input_video_stream->codecpar->codec_id);
    if (!_decoder_codec) {
        return false;
    }

    _decoder_context = avcodec_alloc_context3(_decoder_codec);
    if (!_decoder_context) {
        return false;
    }

    ret = avcodec_parameters_to_context(_decoder_context, _input_video_stream->codecpar);
    if (ret < 0) {
        return false;
    }

    ret = avcodec_open2(_decoder_context, _decoder_codec, nullptr);
    if (ret < 0) {
        return false;
    }

    /* ENCODER */

    // Find encoder for output stream
    _encoder_codec = avcodec_find_encoder(output_config.codec_id);
    if (!_encoder_codec) {
        return false;
    }

    // Allocate context for the encoder
    _encoder_context = avcodec_alloc_context3(_encoder_codec);
    if (!_encoder_context) {
        return false;
    }

    // Set encoder options
    av_opt_set(_encoder_context->priv_data, "preset", "ultrafast", 0);
    av_opt_set(_encoder_context->priv_data, "tune", "zerolatency", 0);
    _encoder_context->width = output_config.width;
    _encoder_context->height = output_config.height;
    _encoder_context->pix_fmt = output_config.pixel_format;
    _encoder_context->time_base = {1, output_config.fps};
    //_encoder_context->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

    // Set codec to automatically determine how many threads suits best for the decoding job
    _encoder_context->thread_count = 1;

    // Open encoder
    ret = avcodec_open2(_encoder_context, _encoder_codec, nullptr);
    if (ret < 0) {
        return false;
    }

    // Copy encoder parameter to stream
    ret = avcodec_parameters_from_context(_output_video_stream->codecpar, _encoder_context);
    if (ret < 0) {
        return false;
    }

    /* FILTER */
    _sws_context = sws_getContext(_decoder_context->width, _decoder_context->height,
                                  _decoder_context->pix_fmt,
                                  _encoder_context->width,
                                  _encoder_context->height,
                                  _encoder_context->pix_fmt,
                                  SWS_BICUBIC, nullptr, nullptr, nullptr);
    if (!_sws_context) {
        return false;
    }


    return true;
}

bool LibAvWrapper::capture_frame() {
    int ret;

    auto input_packet = av_packet_alloc();

    // Read a frame from the input
    ret = av_read_frame(_input_format_context, input_packet);
    if (ret < 0) {
        return false;
    }

    ret = avcodec_send_packet(_decoder_context, input_packet);
    if (ret < 0) {
        return false;
    }

    auto decoded_frame = av_frame_alloc();
    if (!decoded_frame) {
        return false;
    }

    ret = avcodec_receive_frame(_decoder_context, decoded_frame);
    if (ret < 0) {
        return false;
    }

    // Convert the frame to the output format
    auto converted_frame = av_frame_alloc();
    if (!converted_frame) {
        return false;
    }

    converted_frame->width = _encoder_context->width;
    converted_frame->height = _encoder_context->height;
    converted_frame->format = _encoder_context->pix_fmt;

    ret = av_frame_get_buffer(converted_frame, 0);
    if (ret < 0) {
        return false;
    }

    ret = sws_scale(_sws_context,
                    decoded_frame->data, decoded_frame->linesize,
                    0, decoded_frame->height,
                    converted_frame->data, converted_frame->linesize);
    if (ret < 0) {
        return false;
    }

    converted_frame->pts = av_rescale_q(input_packet->pts,
                                        _input_video_stream->time_base,
                                        _encoder_context->time_base);

    // Encode the frame
    auto encoded_packet = av_packet_alloc();
    if (!encoded_packet) {
        return false;
    }

    ret = avcodec_send_frame(_encoder_context, converted_frame);
    if (ret < 0) {
        return false;
    }

    ret = avcodec_receive_packet(_encoder_context, encoded_packet);
    if (ret < 0) {
        return false;
    }

    encoded_packet->stream_index = _output_video_stream->index;
    av_packet_rescale_ts(encoded_packet, _encoder_context->time_base, _output_video_stream->time_base);

    // Write the packet to the output
    ret = av_interleaved_write_frame(_output_format_context, encoded_packet);
    if (ret < 0) {
        return false;
    }

    av_packet_unref(encoded_packet);
    av_packet_free(&encoded_packet);
    av_frame_free(&converted_frame);
    av_frame_free(&decoded_frame);
    av_packet_unref(input_packet);
    av_packet_free(&input_packet);

    return true;
}

bool LibAvWrapper::write_header() {
    int ret = avformat_write_header(_output_format_context, nullptr);
    if (ret < 0) {
        return false;
    }
    return true;
}

bool LibAvWrapper::write_trailer() {
    int ret;

    // Flush encoder
    avcodec_send_frame(_encoder_context, nullptr);

    // Retrieve and write remaining packets
    auto last_packet = av_packet_alloc();
    do {
        ret = avcodec_receive_packet(_encoder_context, last_packet);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
            break;
        } else if (ret < 0) {
            return false;
        }

        last_packet->stream_index = _output_video_stream->index;
        av_packet_rescale_ts(last_packet, _encoder_context->time_base, _output_video_stream->time_base);

        ret = av_interleaved_write_frame(_output_format_context, last_packet);
        if (ret < 0) {
            return false;
        }
    } while (ret == 0);
    av_packet_unref(last_packet);

    ret = av_write_trailer(_output_format_context);
    if (ret < 0) {
        return false;
    }

    return true;
}

void LibAvWrapper::deinit() {
    // controlli interni su nullptr
    avformat_close_input(&_input_format_context);
    avformat_free_context(_input_format_context);
    avformat_close_input(&_output_format_context);
    avformat_free_context(_output_format_context);
    avcodec_close(_decoder_context);
    avcodec_close(_encoder_context);
    avcodec_free_context(&_decoder_context);
    avcodec_free_context(&_encoder_context);
    sws_freeContext(_sws_context);
    avformat_network_deinit();

    _input_format_context = nullptr;
    _output_format_context = nullptr;
    _input_video_stream = nullptr;
    _output_video_stream = nullptr;
    _sws_context = nullptr;
    _decoder_codec = nullptr;
    _decoder_context = nullptr;
    _encoder_codec = nullptr;
    _encoder_context = nullptr;
}
