#ifndef WIFI_WONDERS_MONITOR_H
#define WIFI_WONDERS_MONITOR_H

#include <string>
#include <utility>

class Monitor {
    std::string url;
    std::string deviceID;
    std::string deviceAddress;
    std::string name;
    int x, y, width, height;
    bool primary;
    std::string port;

public:
    Monitor(std::string url, std::string deviceID, std::string name,
            int x, int y, int width, int height,
            bool primary, std::string port);

    [[nodiscard]] const std::string &getUrl() const;

    [[nodiscard]] const std::string &getDeviceId() const;

    [[nodiscard]] const std::string &getDeviceAddress() const;

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] bool isPrimary() const;

    [[nodiscard]] const std::string &getPort() const;

    explicit operator std::string() const;

    friend std::ostream & operator <<(std::ostream &out, const Monitor &obj);

};


#endif //WIFI_WONDERS_MONITOR_H
