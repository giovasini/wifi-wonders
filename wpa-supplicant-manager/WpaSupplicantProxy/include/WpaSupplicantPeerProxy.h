#ifndef WPASUPPLICANTPEERPROXY_H
#define WPASUPPLICANTPEERPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>
#include "fi_w1_wpa_supplicant1_PeerProxy.h"

namespace WpaSupplicant {
    class WpaSupplicantPeerProxy
            : public DBus::ObjectProxy {
    public:
        WpaSupplicantPeerProxy(std::shared_ptr<DBus::Connection> conn, std::string path,
                               std::string dest = "fi.w1.wpa_supplicant1");

    public:
        static std::shared_ptr<WpaSupplicantPeerProxy>
        create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest = "fi.w1.wpa_supplicant1",
               DBus::ThreadForCalling signalCallingThread = DBus::ThreadForCalling::DispatcherThread);

        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy> getfi_w1_wpa_supplicant1_PeerInterface();

    protected:
        std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy> m_fi_w1_wpa_supplicant1_PeerProxy;
    };
} /* namespace WpaSupplicant */
#endif /* WPASUPPLICANTPEERPROXY_H */
