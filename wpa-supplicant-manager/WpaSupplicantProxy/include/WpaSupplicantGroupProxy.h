#ifndef WPASUPPLICANTGROUPPROXY_H
#define WPASUPPLICANTGROUPPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>
#include "fi_w1_wpa_supplicant1_GroupProxy.h"

namespace WpaSupplicant {
    class WpaSupplicantGroupProxy
            : public DBus::ObjectProxy {
    public:
        WpaSupplicantGroupProxy(std::shared_ptr<DBus::Connection> conn, std::string path,
                                std::string dest = "fi.w1.wpa_supplicant1");

    public:
        static std::shared_ptr<WpaSupplicantGroupProxy>
        create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest = "fi.w1.wpa_supplicant1",
               DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);

        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy> getfi_w1_wpa_supplicant1_GroupInterface();

    protected:
        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy> m_fi_w1_wpa_supplicant1_GroupProxy;
    };
} /* namespace WpaSupplicant */
#endif /* WPASUPPLICANTGROUPPROXY_H */
