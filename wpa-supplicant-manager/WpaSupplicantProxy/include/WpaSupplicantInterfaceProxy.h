#ifndef WPASUPPLICANTINTERFACEPROXY_H
#define WPASUPPLICANTINTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>
#include "fi_w1_wpa_supplicant1_InterfaceProxy.h"
#include "fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy.h"
#include "fi_w1_wpa_supplicant1_Interface_WPSProxy.h"

namespace WpaSupplicant {
    class WpaSupplicantInterfaceProxy
            : public DBus::ObjectProxy {
    public:
        WpaSupplicantInterfaceProxy(std::shared_ptr<DBus::Connection> conn, std::string path,
                                    std::string dest = "fi.w1.wpa_supplicant1");

    public:
        static std::shared_ptr<WpaSupplicantInterfaceProxy>
        create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest = "fi.w1.wpa_supplicant1",
               DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);

        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy>
        getfi_w1_wpa_supplicant1_InterfaceInterface();

        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy>
        getfi_w1_wpa_supplicant1_Interface_WPSInterface();

        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy>
        getfi_w1_wpa_supplicant1_Interface_P2PDeviceInterface();

    protected:
        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy> m_fi_w1_wpa_supplicant1_InterfaceProxy;
        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy> m_fi_w1_wpa_supplicant1_Interface_WPSProxy;
        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy> m_fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy;
    };
} /* namespace WpaSupplicant */
#endif /* WPASUPPLICANTINTERFACEPROXY_H */
