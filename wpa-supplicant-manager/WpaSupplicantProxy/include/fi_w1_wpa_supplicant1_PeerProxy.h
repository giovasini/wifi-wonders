#ifndef FI_WI_WPA_SUPPLICANT__PEERPROXY_H
#define FI_WI_WPA_SUPPLICANT__PEERPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>

namespace WpaSupplicant {
    class fi_w1_wpa_supplicant1_PeerProxy
            : public DBus::InterfaceProxy {
    protected:
        fi_w1_wpa_supplicant1_PeerProxy(std::string name);

    public:
        static std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_PeerProxy>
        create(std::string name = "fi.w1.wpa_supplicant1.Peer");

        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_PropertiesChanged( );
    private:
        void setDeviceName(std::string value);

        std::string DeviceName();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_DeviceName( );

        void setManufacturer(std::string value);

        std::string Manufacturer();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_Manufacturer( );

        void setModelName(std::string value);

        std::string ModelName();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_ModelName( );

        void setModelNumber(std::string value);

        std::string ModelNumber();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_ModelNumber( );

        void setSerialNumber(std::string value);

        std::string SerialNumber();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_SerialNumber( );

        void setPrimaryDeviceType(std::vector<uint8_t> value);

        std::vector<uint8_t> PrimaryDeviceType();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_PrimaryDeviceType();

        void setconfig_method(uint16_t value);

        uint16_t config_method();

        std::shared_ptr<DBus::PropertyProxy < uint16_t>> getProperty_config_method( );

        void setlevel(int32_t value);

        int32_t level();

        std::shared_ptr<DBus::PropertyProxy < int32_t>> getProperty_level( );

        void setdevicecapability(uint8_t value);

        uint8_t devicecapability();

        std::shared_ptr<DBus::PropertyProxy < uint8_t>> getProperty_devicecapability( );

        void setgroupcapability(uint8_t value);

        uint8_t groupcapability();

        std::shared_ptr<DBus::PropertyProxy < uint8_t>> getProperty_groupcapability( );

        void setSecondaryDeviceTypes(std::vector<std::vector<uint8_t>> value);

        std::vector<std::vector<uint8_t>> SecondaryDeviceTypes();

        std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>> getProperty_SecondaryDeviceTypes( );

        void setVendorExtension(std::vector<std::vector<uint8_t>> value);

        std::vector<std::vector<uint8_t>> VendorExtension();

        std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>> getProperty_VendorExtension( );

        void setIEs(std::vector<uint8_t> value);

        std::vector<uint8_t> IEs();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_IEs();

        void setDeviceAddress(std::vector<uint8_t> value);

        std::vector<uint8_t> DeviceAddress();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_DeviceAddress();

        void setGroups(std::vector<DBus::Path> value);

        std::vector<DBus::Path> Groups();

        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

        getProperty_Groups();

        void setVSIE(std::vector<uint8_t> value);

        std::vector<uint8_t> VSIE();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_VSIE();

    public:
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_DeviceName;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_Manufacturer;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_ModelName;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_ModelNumber;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_SerialNumber;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_PrimaryDeviceType;
        std::shared_ptr<DBus::PropertyProxy < uint16_t>> m_property_config_method;
        std::shared_ptr<DBus::PropertyProxy < int32_t>> m_property_level;
        std::shared_ptr<DBus::PropertyProxy < uint8_t>> m_property_devicecapability;
        std::shared_ptr<DBus::PropertyProxy < uint8_t>> m_property_groupcapability;
        std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>> m_property_SecondaryDeviceTypes;
        std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>> m_property_VendorExtension;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_IEs;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_DeviceAddress;
        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>
        m_property_Groups;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_VSIE;
    protected:
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_PropertiesChanged;
    };
} /* namespace WpaSupplicant */
#endif /* FI_WI_WPA_SUPPLICANT__PEERPROXY_H */
