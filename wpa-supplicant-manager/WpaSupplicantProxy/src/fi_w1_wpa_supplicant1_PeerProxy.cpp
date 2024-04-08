#include "../include/fi_w1_wpa_supplicant1_PeerProxy.h"

using WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy;

fi_w1_wpa_supplicant1_PeerProxy::fi_w1_wpa_supplicant1_PeerProxy(std::string name) : DBus::InterfaceProxy(name) {
    m_signalproxy_PropertiesChanged = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "PropertiesChanged");
    m_property_DeviceName = this->create_property<std::string>("DeviceName");
    m_property_Manufacturer = this->create_property<std::string>("Manufacturer");
    m_property_ModelName = this->create_property<std::string>("ModelName");
    m_property_ModelNumber = this->create_property<std::string>("ModelNumber");
    m_property_SerialNumber = this->create_property<std::string>("SerialNumber");
    m_property_PrimaryDeviceType = this->create_property<std::vector<uint8_t>>("PrimaryDeviceType");
    m_property_config_method = this->create_property<uint16_t>("config_method");
    m_property_level = this->create_property<int32_t>("level");
    m_property_devicecapability = this->create_property<uint8_t>("devicecapability");
    m_property_groupcapability = this->create_property<uint8_t>("groupcapability");
    m_property_SecondaryDeviceTypes = this->create_property<std::vector<std::vector<uint8_t>>>("SecondaryDeviceTypes");
    m_property_VendorExtension = this->create_property<std::vector<std::vector<uint8_t>>>("VendorExtension");
    m_property_IEs = this->create_property<std::vector<uint8_t>>("IEs");
    m_property_DeviceAddress = this->create_property<std::vector<uint8_t>>("DeviceAddress");
    m_property_Groups = this->create_property<std::vector<DBus::Path>>("Groups");
    m_property_VSIE = this->create_property<std::vector<uint8_t>>("VSIE");

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy>
fi_w1_wpa_supplicant1_PeerProxy::create(std::string name) {
    return std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy>(
            new WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy(name));

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_PeerProxy::signal_PropertiesChanged() {
    return m_signalproxy_PropertiesChanged;

}

void fi_w1_wpa_supplicant1_PeerProxy::setDeviceName(std::string value) {
    m_property_DeviceName->set_value(value);

}

std::string fi_w1_wpa_supplicant1_PeerProxy::DeviceName() {
    return m_property_DeviceName->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_DeviceName() {
    return m_property_DeviceName;

}

void fi_w1_wpa_supplicant1_PeerProxy::setManufacturer(std::string value) {
    m_property_Manufacturer->set_value(value);

}

std::string fi_w1_wpa_supplicant1_PeerProxy::Manufacturer() {
    return m_property_Manufacturer->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_Manufacturer() {
    return m_property_Manufacturer;

}

void fi_w1_wpa_supplicant1_PeerProxy::setModelName(std::string value) {
    m_property_ModelName->set_value(value);

}

std::string fi_w1_wpa_supplicant1_PeerProxy::ModelName() {
    return m_property_ModelName->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_ModelName() {
    return m_property_ModelName;

}

void fi_w1_wpa_supplicant1_PeerProxy::setModelNumber(std::string value) {
    m_property_ModelNumber->set_value(value);

}

std::string fi_w1_wpa_supplicant1_PeerProxy::ModelNumber() {
    return m_property_ModelNumber->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_ModelNumber() {
    return m_property_ModelNumber;

}

void fi_w1_wpa_supplicant1_PeerProxy::setSerialNumber(std::string value) {
    m_property_SerialNumber->set_value(value);

}

std::string fi_w1_wpa_supplicant1_PeerProxy::SerialNumber() {
    return m_property_SerialNumber->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_SerialNumber() {
    return m_property_SerialNumber;

}

void fi_w1_wpa_supplicant1_PeerProxy::setPrimaryDeviceType(std::vector<uint8_t> value) {
    m_property_PrimaryDeviceType->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_PeerProxy::PrimaryDeviceType() {
    return m_property_PrimaryDeviceType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_PrimaryDeviceType() {
    return m_property_PrimaryDeviceType;

}

void fi_w1_wpa_supplicant1_PeerProxy::setconfig_method(uint16_t value) {
    m_property_config_method->set_value(value);

}

uint16_t fi_w1_wpa_supplicant1_PeerProxy::config_method() {
    return m_property_config_method->value();

}

std::shared_ptr<DBus::PropertyProxy < uint16_t>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_config_method() {
    return m_property_config_method;

}

void fi_w1_wpa_supplicant1_PeerProxy::setlevel(int32_t value) {
    m_property_level->set_value(value);

}

int32_t fi_w1_wpa_supplicant1_PeerProxy::level() {
    return m_property_level->value();

}

std::shared_ptr<DBus::PropertyProxy < int32_t>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_level() {
    return m_property_level;

}

void fi_w1_wpa_supplicant1_PeerProxy::setdevicecapability(uint8_t value) {
    m_property_devicecapability->set_value(value);

}

uint8_t fi_w1_wpa_supplicant1_PeerProxy::devicecapability() {
    return m_property_devicecapability->value();

}

std::shared_ptr<DBus::PropertyProxy < uint8_t>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_devicecapability() {
    return m_property_devicecapability;

}

void fi_w1_wpa_supplicant1_PeerProxy::setgroupcapability(uint8_t value) {
    m_property_groupcapability->set_value(value);

}

uint8_t fi_w1_wpa_supplicant1_PeerProxy::groupcapability() {
    return m_property_groupcapability->value();

}

std::shared_ptr<DBus::PropertyProxy < uint8_t>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_groupcapability() {
    return m_property_groupcapability;

}

void fi_w1_wpa_supplicant1_PeerProxy::setSecondaryDeviceTypes(std::vector<std::vector<uint8_t>> value) {
    m_property_SecondaryDeviceTypes->set_value(value);

}

std::vector<std::vector<uint8_t>> fi_w1_wpa_supplicant1_PeerProxy::SecondaryDeviceTypes() {
    return m_property_SecondaryDeviceTypes->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_SecondaryDeviceTypes() {
    return m_property_SecondaryDeviceTypes;

}

void fi_w1_wpa_supplicant1_PeerProxy::setVendorExtension(std::vector<std::vector<uint8_t>> value) {
    m_property_VendorExtension->set_value(value);

}

std::vector<std::vector<uint8_t>> fi_w1_wpa_supplicant1_PeerProxy::VendorExtension() {
    return m_property_VendorExtension->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_VendorExtension() {
    return m_property_VendorExtension;

}

void fi_w1_wpa_supplicant1_PeerProxy::setIEs(std::vector<uint8_t> value) {
    m_property_IEs->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_PeerProxy::IEs() {
    return m_property_IEs->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_IEs() {
    return m_property_IEs;

}

void fi_w1_wpa_supplicant1_PeerProxy::setDeviceAddress(std::vector<uint8_t> value) {
    m_property_DeviceAddress->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_PeerProxy::DeviceAddress() {
    return m_property_DeviceAddress->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_DeviceAddress() {
    return m_property_DeviceAddress;

}

void fi_w1_wpa_supplicant1_PeerProxy::setGroups(std::vector<DBus::Path> value) {
    m_property_Groups->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_PeerProxy::Groups() {
    return m_property_Groups->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_Groups() {
    return m_property_Groups;

}

void fi_w1_wpa_supplicant1_PeerProxy::setVSIE(std::vector<uint8_t> value) {
    m_property_VSIE->set_value(value);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_PeerProxy::VSIE() {
    return m_property_VSIE->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

fi_w1_wpa_supplicant1_PeerProxy::getProperty_VSIE() {
    return m_property_VSIE;

}
