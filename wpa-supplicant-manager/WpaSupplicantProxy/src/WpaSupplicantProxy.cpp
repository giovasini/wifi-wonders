#include "../include/WpaSupplicantProxy.h"

using WpaSupplicant::WpaSupplicantProxy;

WpaSupplicantProxy::WpaSupplicantProxy(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest)
        : DBus::ObjectProxy(conn, dest, path) {
    m_fi_w1_wpa_supplicant1Proxy = WpaSupplicant::fi_w1_wpa_supplicant1Proxy::create("fi.w1.wpa_supplicant1");
    this->add_interface(m_fi_w1_wpa_supplicant1Proxy);

}

std::shared_ptr<WpaSupplicantProxy>
WpaSupplicantProxy::create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest,
                           DBus::ThreadForCalling signalCallingThread) {
    std::shared_ptr<WpaSupplicantProxy> created = std::shared_ptr<WpaSupplicantProxy>(
            new WpaSupplicantProxy(conn, path, dest));
    conn->register_object_proxy(created, signalCallingThread);
    return created;

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1Proxy> WpaSupplicantProxy::getfi_w1_wpa_supplicant1Interface() {
    return m_fi_w1_wpa_supplicant1Proxy;

}
