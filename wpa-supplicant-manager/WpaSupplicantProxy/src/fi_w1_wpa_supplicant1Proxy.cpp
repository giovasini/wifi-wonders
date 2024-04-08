#include "../include/fi_w1_wpa_supplicant1Proxy.h"

using WpaSupplicant::fi_w1_wpa_supplicant1Proxy;

fi_w1_wpa_supplicant1Proxy::fi_w1_wpa_supplicant1Proxy(std::string name) : DBus::InterfaceProxy(name) {
    m_method_CreateInterface = this->create_method<DBus::Path(std::map<std::string, DBus::Variant>)>("CreateInterface");
    m_method_RemoveInterface = this->create_method<void(DBus::Path)>("RemoveInterface");
    m_method_GetInterface = this->create_method<DBus::Path(std::string)>("GetInterface");
    m_method_ExpectDisconnect = this->create_method<void()>("ExpectDisconnect");
    m_signalproxy_InterfaceAdded = this->create_signal<void(DBus::Path, std::map<std::string, DBus::Variant>)>(
            "InterfaceAdded");
    m_signalproxy_InterfaceRemoved = this->create_signal<void(DBus::Path)>("InterfaceRemoved");
    m_signalproxy_PropertiesChanged = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "PropertiesChanged");
    m_property_DebugLevel = this->create_property<std::string>("DebugLevel");
    m_property_DebugTimestamp = this->create_property<bool>("DebugTimestamp");
    m_property_DebugShowKeys = this->create_property<bool>("DebugShowKeys");
    m_property_Interfaces = this->create_property<std::vector<DBus::Path>>("Interfaces");
    m_property_EapMethods = this->create_property<std::vector<std::string>>("EapMethods");
    m_property_Capabilities = this->create_property<std::vector<std::string>>("Capabilities");
    m_property_WFDIEs = this->create_property<std::vector<uint8_t>>("WFDIEs");

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1Proxy> fi_w1_wpa_supplicant1Proxy::create(std::string name) {
    return std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1Proxy>(
            new WpaSupplicant::fi_w1_wpa_supplicant1Proxy(name));

}

DBus::Path fi_w1_wpa_supplicant1Proxy::CreateInterface(std::map<std::string, DBus::Variant> args) {
    return (*m_method_CreateInterface)(args);

}

void fi_w1_wpa_supplicant1Proxy::RemoveInterface(DBus::Path path) {
    (*m_method_RemoveInterface)(path);

}

DBus::Path fi_w1_wpa_supplicant1Proxy::GetInterface(std::string ifname) {
    return (*m_method_GetInterface)(ifname);

}

void fi_w1_wpa_supplicant1Proxy::ExpectDisconnect() {
    (*m_method_ExpectDisconnect)();

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1Proxy::signal_InterfaceAdded() {
    return m_signalproxy_InterfaceAdded;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1Proxy::signal_InterfaceRemoved() {
    return m_signalproxy_InterfaceRemoved;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1Proxy::signal_PropertiesChanged() {
    return m_signalproxy_PropertiesChanged;

}

void fi_w1_wpa_supplicant1Proxy::setDebugLevel(std::string value) {
    m_property_DebugLevel->set_value(value);

}

std::string fi_w1_wpa_supplicant1Proxy::DebugLevel() {
    return m_property_DebugLevel->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1Proxy::getProperty_DebugLevel() {
    return m_property_DebugLevel;

}

void fi_w1_wpa_supplicant1Proxy::setDebugTimestamp(bool value) {
    m_property_DebugTimestamp->set_value(value);

}

bool fi_w1_wpa_supplicant1Proxy::DebugTimestamp() {
    return m_property_DebugTimestamp->value();

}

std::shared_ptr<DBus::PropertyProxy < bool>>

fi_w1_wpa_supplicant1Proxy::getProperty_DebugTimestamp() {
    return m_property_DebugTimestamp;

}

void fi_w1_wpa_supplicant1Proxy::setDebugShowKeys(bool value) {
    m_property_DebugShowKeys->set_value(value);

}

bool fi_w1_wpa_supplicant1Proxy::DebugShowKeys() {
    return m_property_DebugShowKeys->value();

}

std::shared_ptr<DBus::PropertyProxy < bool>>

fi_w1_wpa_supplicant1Proxy::getProperty_DebugShowKeys() {
    return m_property_DebugShowKeys;

}

void fi_w1_wpa_supplicant1Proxy::setInterfaces(std::vector<DBus::Path> value) {
    m_property_Interfaces->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1Proxy::Interfaces() {
    return m_property_Interfaces->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1Proxy::getProperty_Interfaces() {
    return m_property_Interfaces;

}

void fi_w1_wpa_supplicant1Proxy::setEapMethods(std::vector<std::string> value) {
    m_property_EapMethods->set_value(value);

}

std::vector<std::string> fi_w1_wpa_supplicant1Proxy::EapMethods() {
    return m_property_EapMethods->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<std::string>>>

fi_w1_wpa_supplicant1Proxy::getProperty_EapMethods() {
    return m_property_EapMethods;

}

void fi_w1_wpa_supplicant1Proxy::setCapabilities(std::vector<std::string> value) {
    m_property_Capabilities->set_value(value);

}

std::vector<std::string> fi_w1_wpa_supplicant1Proxy::Capabilities() {
    return m_property_Capabilities->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<std::string>>>

fi_w1_wpa_supplicant1Proxy::getProperty_Capabilities() {
    return m_property_Capabilities;

}

void fi_w1_wpa_supplicant1Proxy::setWFDIEs(std::vector<uint8_t> value) {
    m_property_WFDIEs->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1Proxy::WFDIEs() {
    return m_property_WFDIEs->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1Proxy::getProperty_WFDIEs() {
    return m_property_WFDIEs;

}
