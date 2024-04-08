#ifndef FI_WI_WPA_SUPPLICANT__GROUPPROXY_H
#define FI_WI_WPA_SUPPLICANT__GROUPPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>

namespace WpaSupplicant {
    class fi_w1_wpa_supplicant1_GroupProxy
            : public DBus::InterfaceProxy {
    protected:
        fi_w1_wpa_supplicant1_GroupProxy(std::string name);

    public:
        static std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_GroupProxy>
        create(std::string name = "fi.w1.wpa_supplicant1.Group");

        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_PeerJoined( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_PeerDisconnected( );
    private:
        void setMembers(std::vector<DBus::Path> value);

        std::vector<DBus::Path> Members();

        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

        getProperty_Members();

        void setGroup(DBus::Path value);

        DBus::Path Group();

        std::shared_ptr<DBus::PropertyProxy < DBus::Path>> getProperty_Group( );

        void setRole(std::string value);

        std::string Role();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_Role( );

        void setSSID(std::vector<uint8_t> value);

        std::vector<uint8_t> SSID();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_SSID();

        void setBSSID(std::vector<uint8_t> value);

        std::vector<uint8_t> BSSID();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_BSSID();

        void setFrequency(uint16_t value);

        uint16_t Frequency();

        std::shared_ptr<DBus::PropertyProxy < uint16_t>> getProperty_Frequency( );

        void setPassphrase(std::string value);

        std::string Passphrase();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_Passphrase( );

        void setPSK(std::vector<uint8_t> value);

        std::vector<uint8_t> PSK();

        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>

        getProperty_PSK();

        void setWPSVendorExtensions(std::vector<std::vector<uint8_t>> value);

        std::vector<std::vector<uint8_t>> WPSVendorExtensions();

        std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>> getProperty_WPSVendorExtensions( );
    public:
        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>
        m_property_Members;
        std::shared_ptr<DBus::PropertyProxy < DBus::Path>> m_property_Group;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_Role;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_SSID;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_BSSID;
        std::shared_ptr<DBus::PropertyProxy < uint16_t>> m_property_Frequency;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_Passphrase;
        std::shared_ptr<DBus::PropertyProxy < std::vector<uint8_t>>>
        m_property_PSK;
        std::shared_ptr<DBus::PropertyProxy < std::vector<std::vector<uint8_t>>>> m_property_WPSVendorExtensions;
    protected:
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_PeerJoined;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_PeerDisconnected;
    };
} /* namespace WpaSupplicant */
#endif /* FI_WI_WPA_SUPPLICANT__GROUPPROXY_H */
