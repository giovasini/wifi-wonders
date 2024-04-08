#include <iostream>
#include "monitor_service.h"
#include "casting_service.h"

int main() {

    std::vector<Monitor> monitors = MonitorService::getMonitors();
    int i = 0;
    while (true) {
        i=0;
        for (const auto &monitor: monitors) {
            std::cout << (i+1) << ". " << monitor << std::endl;
            //std::string base64 = MonitorService::getMonitorScreenshot(monitor.getX(), monitor.getY(), monitor.getWidth(),
            //                                                          monitor.getHeight());
            //std::cout << base64 << std::endl;
            i++;
        }


        int monitorIndex;
        while (true) {
            std::cout << "Select monitor: ";
            std::cin >> monitorIndex;
            if (std::cin) {
                if (monitorIndex == 0) {
                    std::cout << "Exiting..." << std::endl;
                    return 0;
                }
                if (monitorIndex > 0 && monitorIndex <= monitors.size()) {
                    break;
                }
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore line
            std::cout << "Invalid input" << std::endl;
        }

        std::cout << "Starting recording..." << std::endl;
        CastingService::getInstance().start_recording(monitors[monitorIndex-1], "rtmp://localhost/live/screen");

        do {
            std::cout << "Press 'q' to stop recording... " << std::endl;
        } while (std::cin.get() != 'q');
        std::cin.ignore();

        CastingService::getInstance().stop_recording();

        std::cout << "Press any key to exit... " << std::endl;
        std::cin.get();
    }

    return 0;
}