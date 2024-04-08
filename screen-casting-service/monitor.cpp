#include <fmt/core.h>
#include "monitor.h"

Monitor::Monitor(std::string url, std::string deviceID, std::string name,
                 int x, int y, int width, int height,
                 bool primary, std::string port) :
        url(std::move(url)),
        deviceID(std::move(deviceID)),
        name(std::move(name)),
        x(x), y(y), width(width),
        height(height), primary(primary),
        port(std::move(port)) {
    deviceAddress = fmt::format("{}:{}", deviceID, this->url);
}

const std::string &Monitor::getUrl() const {
    return url;
}

const std::string &Monitor::getDeviceId() const {
    return deviceID;
}

const std::string &Monitor::getDeviceAddress() const {
    return deviceAddress;
}

const std::string &Monitor::getName() const {
    return name;
}

int Monitor::getX() const {
    return x;
}

int Monitor::getY() const {
    return y;
}

int Monitor::getWidth() const {
    return width;
}

int Monitor::getHeight() const {
    return height;
}

bool Monitor::isPrimary() const {
    return primary;
}

const std::string &Monitor::getPort() const {
    return port;
}

Monitor::operator std::string() const {
    return fmt::format("{}, {}x{}, ({},{}){} | {}, port: {}",
                       this->name, this->width, this->height,
                       this->x, this->y,
                       this->primary ? ", primary" : "",
                       this->deviceAddress, this->port);
}

std::ostream &operator<<(std::ostream &out, const Monitor &obj) {
    return out << static_cast<std::string>(obj);
}

