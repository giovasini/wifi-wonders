#include "../include/fi_w1_wpa_supplicant1_GroupProxy.h"

using WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy;

fi_w1_wpa_supplicant1_GroupProxy::fi_w1_wpa_supplicant1_GroupProxy(std::string name) : DBus::InterfaceProxy(name) {
    m_signalproxy_PeerJoined = this->create_signal<void(DBus::Path)>("PeerJoined");
    m_signalproxy_PeerDisconnected = this->create_signal<void(DBus::Path)>("PeerDisconnected");
    m_property_Members = this->create_property<std::vector<DBus::Path>>("Members");
    m_property_Group = this->create_property<DBus::Path>("Group");
    m_property_Role = this->create_property<std::string>("Role");
    m_property_SSID = this->create_property<std::vector<uint8_t>>("SSID");
    m_property_BSSID = this->create_property<std::vector<uint8_t>>("BSSID");
    m_property_Frequency = this->create_property<uint16_t>("Frequency");
    m_property_Passphrase = this->create_property<std::string>("Passphrase");
    m_property_PSK = this->create_property<std::vector<uint8_t>>("PSK");
    m_property_WPSVendorExtensions = this->create_property<std::vector<std::vector<uint8_t>>>("WPSVendorExtensions");

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy>
fi_w1_wpa_supplicant1_GroupProxy::create(std::string name) {
    return std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy>(
            new WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy(name));

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_GroupProxy::signal_PeerJoined() {
    return m_signalproxy_PeerJoined;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_GroupProxy::signal_PeerDisconnected() {
    return m_signalproxy_PeerDisconnected;

}

void fi_w1_wpa_supplicant1_GroupProxy::setMembers(std::vector<DBus::Path> value) {
    m_property_Members->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_GroupProxy::Members() {
    return m_property_Members->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_Members() {
    return m_property_Members;

}

void fi_w1_wpa_supplicant1_GroupProxy::setGroup(DBus::Path value) {
    m_property_Group->set_value(value);

}

DBus::Path fi_w1_wpa_supplicant1_GroupProxy::Group() {
    return m_property_Group->value();

}

std::shared_ptr<DBus::PropertyProxy < DBus::Path>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_Group() {
    return m_property_Group;

}

void fi_w1_wpa_supplicant1_GroupProxy::setRole(std::string value) {
    m_property_Role->set_value(value);

}

std::string fi_w1_wpa_supplicant1_GroupProxy::Role() {
    return m_property_Role->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_Role() {
    return m_property_Role;

}

void fi_w1_wpa_supplicant1_GroupProxy::setSSID(std::vector<uint8_t> value) {
    m_property_SSID->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_GroupProxy::SSID() {
    return m_property_SSID->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_SSID() {
    return m_property_SSID;

}

void fi_w1_wpa_supplicant1_GroupProxy::setBSSID(std::vector<uint8_t> value) {
    m_property_BSSID->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_GroupProxy::BSSID() {
    return m_property_BSSID->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_BSSID() {
    return m_property_BSSID;

}

void fi_w1_wpa_supplicant1_GroupProxy::setFrequency(uint16_t value) {
    m_property_Frequency->set_value(value);

}

uint16_t fi_w1_wpa_supplicant1_GroupProxy::Frequency() {
    return m_property_Frequency->value();

}

std::shared_ptr<DBus::PropertyProxy < uint16_t>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_Frequency() {
    return m_property_Frequency;

}

void fi_w1_wpa_supplicant1_GroupProxy::setPassphrase(std::string value) {
    m_property_Passphrase->set_value(value);

}

std::string fi_w1_wpa_supplicant1_GroupProxy::Passphrase() {
    return m_property_Passphrase->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_Passphrase() {
    return m_property_Passphrase;

}

void fi_w1_wpa_supplicant1_GroupProxy::setPSK(std::vector<uint8_t> value) {
    m_property_PSK->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_GroupProxy::PSK() {
    return m_property_PSK->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_PSK() {
    return m_property_PSK;

}

void fi_w1_wpa_supplicant1_GroupProxy::setWPSVendorExtensions(std::vector<std::vector<uint8_t>> value) {
    m_property_WPSVendorExtensions->set_value(value);

}

std::vector<std::vector<uint8_t>> fi_w1_wpa_supplicant1_GroupProxy::WPSVendorExtensions() {
    return m_property_WPSVendorExtensions->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>>

fi_w1_wpa_supplicant1_GroupProxy::getProperty_WPSVendorExtensions() {
    return m_property_WPSVendorExtensions;

}
