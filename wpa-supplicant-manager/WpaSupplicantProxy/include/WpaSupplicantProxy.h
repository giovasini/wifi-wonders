#ifndef WPASUPPLICANTPROXY_H
#define WPASUPPLICANTPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>
#include "fi_w1_wpa_supplicant1Proxy.h"

namespace WpaSupplicant {
    class WpaSupplicantProxy
            : public DBus::ObjectProxy {
    public:
        WpaSupplicantProxy(std::shared_ptr<DBus::Connection> conn, std::string path = "/fi/w1/wpa_supplicant1",
                           std::string dest = "fi.w1.wpa_supplicant1");

    public:
        static std::shared_ptr<WpaSupplicantProxy>
        create(std::shared_ptr<DBus::Connection> conn, std::string path = "/fi/w1/wpa_supplicant1",
               std::string dest = "fi.w1.wpa_supplicant1",
               DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);

        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1Proxy> getfi_w1_wpa_supplicant1Interface();

    protected:
        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1Proxy> m_fi_w1_wpa_supplicant1Proxy;
    };
} /* namespace WpaSupplicant */
#endif /* WPASUPPLICANTPROXY_H */
