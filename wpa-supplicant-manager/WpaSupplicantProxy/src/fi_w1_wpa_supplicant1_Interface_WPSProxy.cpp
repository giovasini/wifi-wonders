#include "../include/fi_w1_wpa_supplicant1_Interface_WPSProxy.h"

using WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy;

fi_w1_wpa_supplicant1_Interface_WPSProxy::fi_w1_wpa_supplicant1_Interface_WPSProxy(std::string name)
        : DBus::InterfaceProxy(name) {
    m_method_Start = this->create_method<std::map<std::string, DBus::Variant>(std::map<std::string, DBus::Variant>)>(
            "Start");
    m_method_Cancel = this->create_method<void()>("Cancel");
    m_signalproxy_Event = this->create_signal<void(std::string, std::map<std::string, DBus::Variant>)>("Event");
    m_signalproxy_Credentials = this->create_signal<void(std::map<std::string, DBus::Variant>)>("Credentials");
    m_signalproxy_PropertiesChanged = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "PropertiesChanged");
    m_property_ProcessCredentials = this->create_property<bool>("ProcessCredentials");
    m_property_ConfigMethods = this->create_property<std::string>("ConfigMethods");
    m_property_DeviceName = this->create_property<std::string>("DeviceName");
    m_property_Manufacturer = this->create_property<std::string>("Manufacturer");
    m_property_ModelName = this->create_property<std::string>("ModelName");
    m_property_ModelNumber = this->create_property<std::string>("ModelNumber");
    m_property_SerialNumber = this->create_property<std::string>("SerialNumber");
    m_property_DeviceType = this->create_property<std::vector<uint8_t>>("DeviceType");

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy>
fi_w1_wpa_supplicant1_Interface_WPSProxy::create(std::string name) {
    return std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy>(
            new WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy(name));

}

std::map<std::string, DBus::Variant>
fi_w1_wpa_supplicant1_Interface_WPSProxy::Start(std::map<std::string, DBus::Variant> args) {
    return (*m_method_Start)(args);

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::Cancel() {
    (*m_method_Cancel)();

}

std::shared_ptr<DBus::SignalProxy < void(std::string, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::signal_Event() {
    return m_signalproxy_Event;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::signal_Credentials() {
    return m_signalproxy_Credentials;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::signal_PropertiesChanged() {
    return m_signalproxy_PropertiesChanged;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setProcessCredentials(bool value) {
    m_property_ProcessCredentials->set_value(value);

}

bool fi_w1_wpa_supplicant1_Interface_WPSProxy::ProcessCredentials() {
    return m_property_ProcessCredentials->value();

}

std::shared_ptr<DBus::PropertyProxy < bool>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_ProcessCredentials() {
    return m_property_ProcessCredentials;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setConfigMethods(std::string value) {
    m_property_ConfigMethods->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_WPSProxy::ConfigMethods() {
    return m_property_ConfigMethods->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_ConfigMethods() {
    return m_property_ConfigMethods;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setDeviceName(std::string value) {
    m_property_DeviceName->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_WPSProxy::DeviceName() {
    return m_property_DeviceName->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_DeviceName() {
    return m_property_DeviceName;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setManufacturer(std::string value) {
    m_property_Manufacturer->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_WPSProxy::Manufacturer() {
    return m_property_Manufacturer->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_Manufacturer() {
    return m_property_Manufacturer;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setModelName(std::string value) {
    m_property_ModelName->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_WPSProxy::ModelName() {
    return m_property_ModelName->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_ModelName() {
    return m_property_ModelName;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setModelNumber(std::string value) {
    m_property_ModelNumber->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_WPSProxy::ModelNumber() {
    return m_property_ModelNumber->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_ModelNumber() {
    return m_property_ModelNumber;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setSerialNumber(std::string value) {
    m_property_SerialNumber->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_WPSProxy::SerialNumber() {
    return m_property_SerialNumber->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_SerialNumber() {
    return m_property_SerialNumber;

}

void fi_w1_wpa_supplicant1_Interface_WPSProxy::setDeviceType(std::vector<uint8_t> value) {
    m_property_DeviceType->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_Interface_WPSProxy::DeviceType() {
    return m_property_DeviceType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_Interface_WPSProxy::getProperty_DeviceType() {
    return m_property_DeviceType;

}
