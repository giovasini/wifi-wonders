#include <fmt/core.h>
#include "casting_service.h"

std::unique_ptr<CastingService>   CastingService::_instance{nullptr};
std::once_flag                    CastingService::_once_flag{};

CastingService::CastingService() : _libAV(LibAvWrapper::getInstance()) {
    _recording_status = RecordingStatus::IDLE;
    _record_thread = nullptr;
}

CastingService::~CastingService() {
    if (_record_thread) {
        _record_thread->join();
        delete _record_thread;
        _record_thread = nullptr;
    }
}

CastingService &CastingService::getInstance() {
    std::call_once(_once_flag, [&]() { _instance.reset(new CastingService()); });
    return *_instance;
}

void CastingService::_record(const LibAvConfig &input_config, const LibAvConfig &output_config) {
    if(!_libAV.init(input_config, output_config)) {
        return;
    }
    if(!_libAV.write_header()){
        _libAV.deinit();
        return;
    }
    while (true) {
        {
            std::unique_lock<std::mutex> lock{_record_mutex};
            if (_recording_status != RecordingStatus::REC) {
                break;
            }
        }
        // do recording
        if(!_libAV.capture_frame()) {
            _libAV.deinit();
            return;
        }
    }
    _libAV.write_trailer();
    _libAV.deinit();
}

void CastingService::start_recording(const Monitor &input, const std::string &output) {
    {
        std::unique_lock<std::mutex> lock{_record_mutex};
        if (_recording_status == RecordingStatus::IDLE) {
            _recording_status = RecordingStatus::REC;
        } else {
            return;
        }
    }

    _input_config = LibAvConfig{
            .url = fmt::format("{}+{},{}", input.getUrl(), input.getX(), input.getY()),
            .format = input.getDeviceId(),
            .width = input.getWidth(),
            .height = input.getHeight(),
            .fps = 30
    };

    _output_config = LibAvConfig{
            .url = output,
            .format = "flv",
            .width = input.getWidth(),
            .height = input.getHeight(),
            .fps = 30,
            .codec_id = AV_CODEC_ID_H264,
            .pixel_format = AV_PIX_FMT_YUV420P
    };

    _record_thread = new std::thread(&CastingService::_record, this,
                                     std::ref(_input_config), std::ref(_output_config));

}

void CastingService::stop_recording() {
    {
        std::unique_lock<std::mutex> lock{_record_mutex};
        if (_recording_status != RecordingStatus::REC) {
            return;
        }
        _recording_status = RecordingStatus::STOP;
    }
    if (_record_thread) {
        _record_thread->join();
        delete _record_thread;
        _record_thread = nullptr;

        std::unique_lock<std::mutex> lock{_record_mutex};
        _recording_status = RecordingStatus::IDLE;
    }
}
