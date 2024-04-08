#ifndef WIFI_WONDERS_LIBAV_WRAPPER_H
#define WIFI_WONDERS_LIBAV_WRAPPER_H

#include <iostream>
#include <memory>
#include <mutex>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/avutil.h>
}

struct LibAvConfig {
    std::string url;    // input="$DISPLAY+x,y";  output="rtmp://localhost/live/screen"
    std::string format; // input="x11grab";       output="flv"
    int width, height;
    int fps = 30;       // input=30;              output=input
    AVCodecID codec_id;         // input=from_stream;  output=AV_CODEC_ID_H264
    AVPixelFormat pixel_format; // input=from_stream;  output=AV_PIX_FMT_YUV420P
};

class LibAvWrapper {
    static std::unique_ptr<LibAvWrapper> _instance;
    static std::once_flag _once_flag;

    LibAvWrapper();

    AVFormatContext *_input_format_context;
    AVFormatContext *_output_format_context;
    AVStream *_input_video_stream;
    AVStream *_output_video_stream;

    SwsContext *_sws_context;

    AVCodec *_decoder_codec;
    AVCodecContext *_decoder_context;

    AVCodec *_encoder_codec;
    AVCodecContext *_encoder_context;

public:
    static LibAvWrapper &getInstance();

    ~LibAvWrapper() = default;

    LibAvWrapper(const LibAvWrapper &) = delete;

    LibAvWrapper(const LibAvWrapper &&) = delete;

    bool init(const LibAvConfig &input_config, const LibAvConfig &output_config);

    void deinit();

    bool capture_frame();

    bool write_header();

    bool write_trailer();

};


#endif //WIFI_WONDERS_LIBAV_WRAPPER_H
