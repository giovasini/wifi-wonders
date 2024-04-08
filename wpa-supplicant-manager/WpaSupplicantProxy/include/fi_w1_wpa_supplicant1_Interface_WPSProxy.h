#ifndef FI_WI_WPA_SUPPLICANT__INTERFACE_WPSPROXY_H
#define FI_WI_WPA_SUPPLICANT__INTERFACE_WPSPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>

namespace WpaSupplicant {
    class fi_w1_wpa_supplicant1_Interface_WPSProxy
            : public DBus::InterfaceProxy {
    protected:
        fi_w1_wpa_supplicant1_Interface_WPSProxy(std::string name);

    public:
        static std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_WPSProxy>
        create(std::string name = "fi.w1.wpa_supplicant1.Interface.WPS");

        std::map<std::string, DBus::Variant> Start(std::map<std::string, DBus::Variant> args);

        void Cancel();

        std::shared_ptr<DBus::SignalProxy < void(std::string, std::map<std::string, DBus::Variant>)>> signal_Event( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_Credentials( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_PropertiesChanged( );
    private:
        void setProcessCredentials(bool value);

        bool ProcessCredentials();

        std::shared_ptr<DBus::PropertyProxy < bool>> getProperty_ProcessCredentials( );

        void setConfigMethods(std::string value);

        std::string ConfigMethods();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_ConfigMethods( );

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

        void setDeviceType(std::vector<uint8_t> value);

        std::vector<uint8_t> DeviceType();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_DeviceType();

    public:
        std::shared_ptr<DBus::PropertyProxy < bool>> m_property_ProcessCredentials;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_ConfigMethods;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_DeviceName;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_Manufacturer;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_ModelName;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_ModelNumber;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_SerialNumber;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_DeviceType;
    protected:
        std::shared_ptr<DBus::MethodProxy <
                        std::map<std::string, DBus::Variant>(std::map<std::string, DBus::Variant>)>>  m_method_Start;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_Cancel;
        std::shared_ptr<
                DBus::SignalProxy < void(std::string, std::map<std::string, DBus::Variant>)>> m_signalproxy_Event;
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_Credentials;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_PropertiesChanged;
    };
} /* namespace WpaSupplicant */
#endif /* FI_WI_WPA_SUPPLICANT__INTERFACE_WPSPROXY_H */
