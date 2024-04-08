#ifndef WIFI_WONDERS_CASTING_SERVICE_H
#define WIFI_WONDERS_CASTING_SERVICE_H

#include <mutex>
#include <memory>
#include <unordered_set>
#include <atomic>
#include <thread>
#include <future>
#include <condition_variable>

#include "monitor.h"
#include "libav_wrapper.h"

enum RecordingStatus {
    IDLE, REC, STOP
};

class CastingService {
    static std::unique_ptr<CastingService> _instance;
    static std::once_flag _once_flag;

    LibAvWrapper &_libAV;

    RecordingStatus _recording_status;
    std::mutex _record_mutex;
    std::thread *_record_thread;

    LibAvConfig _input_config;
    LibAvConfig _output_config;

    CastingService();

    void _record(const LibAvConfig &input_config, const LibAvConfig &output_config);

public:

    ~CastingService();

    CastingService(const CastingService &) = delete;

    CastingService(const CastingService &&) = delete;

    static CastingService &getInstance();

    void start_recording(const Monitor& input, const std::string& output);

    void stop_recording();

};


#endif //WIFI_WONDERS_CASTING_SERVICE_H
