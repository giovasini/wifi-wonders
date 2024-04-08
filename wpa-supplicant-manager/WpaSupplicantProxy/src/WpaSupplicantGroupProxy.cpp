#include "../include/WpaSupplicantGroupProxy.h"

using WpaSupplicant::WpaSupplicantGroupProxy;

WpaSupplicantGroupProxy::WpaSupplicantGroupProxy(std::shared_ptr<DBus::Connection> conn, std::string path,
                                                 std::string dest) : DBus::ObjectProxy(conn, dest, path) {
    m_fi_w1_wpa_supplicant1_GroupProxy = WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy::create(
            "fi.w1.wpa_supplicant1.Group");
    this->add_interface(m_fi_w1_wpa_supplicant1_GroupProxy);

}

std::shared_ptr<WpaSupplicantGroupProxy>
WpaSupplicantGroupProxy::create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest,
                                DBus::ThreadForCalling signalCallingThread) {
    std::shared_ptr<WpaSupplicantGroupProxy> created = std::shared_ptr<WpaSupplicantGroupProxy>(
            new WpaSupplicantGroupProxy(conn, path, dest));
    conn->register_object_proxy(created, signalCallingThread);
    return created;

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy>
WpaSupplicantGroupProxy::getfi_w1_wpa_supplicant1_GroupInterface() {
    return m_fi_w1_wpa_supplicant1_GroupProxy;

}
