#ifndef FI_WI_WPA_SUPPLICANT_PROXY_H
#define FI_WI_WPA_SUPPLICANT_PROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>

namespace WpaSupplicant {
    class fi_w1_wpa_supplicant1Proxy
            : public DBus::InterfaceProxy {
    protected:
        fi_w1_wpa_supplicant1Proxy(std::string name);

    public:
        static std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1Proxy>
        create(std::string name = "fi.w1.wpa_supplicant1");

        DBus::Path CreateInterface(std::map<std::string, DBus::Variant> args);

        void RemoveInterface(DBus::Path path);

        DBus::Path GetInterface(std::string ifname);

        void ExpectDisconnect();

        std::shared_ptr<
                DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>> signal_InterfaceAdded( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_InterfaceRemoved( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_PropertiesChanged( );
    private:
        void setDebugLevel(std::string value);

        std::string DebugLevel();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_DebugLevel( );

        void setDebugTimestamp(bool value);

        bool DebugTimestamp();

        std::shared_ptr<DBus::PropertyProxy < bool>> getProperty_DebugTimestamp( );

        void setDebugShowKeys(bool value);

        bool DebugShowKeys();

        std::shared_ptr<DBus::PropertyProxy < bool>> getProperty_DebugShowKeys( );

        void setInterfaces(std::vector<DBus::Path> value);

        std::vector<DBus::Path> Interfaces();

        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

        getProperty_Interfaces();

        void setEapMethods(std::vector<std::string> value);

        std::vector<std::string> EapMethods();

        std::shared_ptr<DBus::PropertyProxy < std::vector<std::string>>>

        getProperty_EapMethods();

        void setCapabilities(std::vector<std::string> value);

        std::vector<std::string> Capabilities();

        std::shared_ptr<DBus::PropertyProxy < std::vector<std::string>>>

        getProperty_Capabilities();

        void setWFDIEs(std::vector<uint8_t> value);

        std::vector<uint8_t> WFDIEs();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_WFDIEs();

    public:
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_DebugLevel;
        std::shared_ptr<DBus::PropertyProxy < bool>> m_property_DebugTimestamp;
        std::shared_ptr<DBus::PropertyProxy < bool>> m_property_DebugShowKeys;
        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>
        m_property_Interfaces;
        std::shared_ptr<DBus::PropertyProxy < std::vector<std::string>>>
        m_property_EapMethods;
        std::shared_ptr<DBus::PropertyProxy < std::vector<std::string>>>
        m_property_Capabilities;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_WFDIEs;
    protected:
        std::shared_ptr<
                DBus::MethodProxy < DBus::Path(std::map<std::string, DBus::Variant>)>>  m_method_CreateInterface;
        std::shared_ptr<DBus::MethodProxy < void(DBus::Path)>>  m_method_RemoveInterface;
        std::shared_ptr<DBus::MethodProxy < DBus::Path(std::string)>>  m_method_GetInterface;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_ExpectDisconnect;
        std::shared_ptr<DBus::SignalProxy <
                        void(DBus::Path, std::map<std::string, DBus::Variant>)>> m_signalproxy_InterfaceAdded;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_InterfaceRemoved;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_PropertiesChanged;
    };
} /* namespace WpaSupplicant */
#endif /* FI_WI_WPA_SUPPLICANT_PROXY_H */
