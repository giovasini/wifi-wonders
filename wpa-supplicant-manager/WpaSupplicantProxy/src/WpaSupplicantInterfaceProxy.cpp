#include "../include/WpaSupplicantInterfaceProxy.h"

using WpaSupplicant::WpaSupplicantInterfaceProxy;

WpaSupplicantInterfaceProxy::WpaSupplicantInterfaceProxy(std::shared_ptr<DBus::Connection> conn, std::string path,
                                                         std::string dest) : DBus::ObjectProxy(conn, dest, path) {
    m_fi_w1_wpa_supplicant1_InterfaceProxy = WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy::create(
            "fi.w1.wpa_supplicant1.Interface");
    this->add_interface(m_fi_w1_wpa_supplicant1_InterfaceProxy);
    m_fi_w1_wpa_supplicant1_Interface_WPSProxy = WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy::create(
            "fi.w1.wpa_supplicant1.Interface.WPS");
    this->add_interface(m_fi_w1_wpa_supplicant1_Interface_WPSProxy);
    m_fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy = WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::create(
            "fi.w1.wpa_supplicant1.Interface.P2PDevice");
    this->add_interface(m_fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy);

}

std::shared_ptr<WpaSupplicantInterfaceProxy>
WpaSupplicantInterfaceProxy::create(std::shared_ptr<DBus::Connection> conn, std::string path, std::string dest,
                                    DBus::ThreadForCalling signalCallingThread) {
    std::shared_ptr<WpaSupplicantInterfaceProxy> created = std::shared_ptr<WpaSupplicantInterfaceProxy>(
            new WpaSupplicantInterfaceProxy(conn, path, dest));
    conn->register_object_proxy(created, signalCallingThread);
    return created;

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy>
WpaSupplicantInterfaceProxy::getfi_w1_wpa_supplicant1_InterfaceInterface() {
    return m_fi_w1_wpa_supplicant1_InterfaceProxy;

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy>
WpaSupplicantInterfaceProxy::getfi_w1_wpa_supplicant1_Interface_WPSInterface() {
    return m_fi_w1_wpa_supplicant1_Interface_WPSProxy;

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy>
WpaSupplicantInterfaceProxy::getfi_w1_wpa_supplicant1_Interface_P2PDeviceInterface() {
    return m_fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy;

}
