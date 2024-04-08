#ifndef WIFI_WONDERS_MONITOR_SERVICE_H
#define WIFI_WONDERS_MONITOR_SERVICE_H

#include <vector>
#include "monitor.h"

class MonitorService {

public:
    static std::vector<Monitor> getMonitors();

    static std::string getMonitorScreenshot(int x, int y, int width, int height);

};


#endif //WIFI_WONDERS_MONITOR_SERVICE_H
