#include "../include/WpaSupplicantPeerProxy.h"

using WpaSupplicant::WpaSupplicantPeerProxy;

WpaSupplicantPeerProxy::WpaSupplicantPeerProxy(std::shared_ptr<DBus::Connection> conn, std::string path,
                                               std::string dest) : DBus::ObjectProxy(conn, dest, path) {
    m_fi_w1_wpa_supplicant1_PeerProxy = WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy::create(
            "fi.w1.wpa_supplicant1.Peer");
    this->add_interface(m_fi_w1_wpa_supplicant1_PeerProxy);

}

std::shared_ptr<WpaSupplicantPeerProxy>
WpaSupplicantPeerProxy::create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest,
                               DBus::ThreadForCalling signalCallingThread) {
    std::shared_ptr<WpaSupplicantPeerProxy> created = std::shared_ptr<WpaSupplicantPeerProxy>(
            new WpaSupplicantPeerProxy(conn, path, dest));
    conn->register_object_proxy(created, signalCallingThread);
    return created;

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy>
WpaSupplicantPeerProxy::getfi_w1_wpa_supplicant1_PeerInterface() {
    return m_fi_w1_wpa_supplicant1_PeerProxy;

}
