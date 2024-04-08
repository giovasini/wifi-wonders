#ifndef FI_WI_WPA_SUPPLICANT__INTERFACE_P_PDEVICEPROXY_H
#define FI_WI_WPA_SUPPLICANT__INTERFACE_P_PDEVICEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>

namespace WpaSupplicant {
    class fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy
            : public DBus::InterfaceProxy {
    protected:
        fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy(std::string name);

    public:
        static std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy>
        create(std::string name = "fi.w1.wpa_supplicant1.Interface.P2PDevice");

        void Find(std::map<std::string, DBus::Variant> args);

        void StopFind();

        void Listen(int32_t timeout);

        void ExtendedListen(std::map<std::string, DBus::Variant> args);

        void PresenceRequest(std::map<std::string, DBus::Variant> args);

        void ProvisionDiscoveryRequest(DBus::Path peer, std::string config_method);

        std::string Connect(std::map<std::string, DBus::Variant> args);

        void GroupAdd(std::map<std::string, DBus::Variant> args);

        void Cancel();

        void Invite(std::map<std::string, DBus::Variant> args);

        void Disconnect();

        void RejectPeer(DBus::Path peer);

        void RemoveClient(std::map<std::string, DBus::Variant> args);

        void Flush();

        void AddService(std::map<std::string, DBus::Variant> args);

        void DeleteService(std::map<std::string, DBus::Variant> args);

        void FlushService();

        uint64_t ServiceDiscoveryRequest(std::map<std::string, DBus::Variant> args);

        void ServiceDiscoveryResponse(std::map<std::string, DBus::Variant> args);

        void ServiceDiscoveryCancelRequest(uint64_t args);

        void ServiceUpdate();

        void ServiceDiscoveryExternal(int32_t arg);

        DBus::Path AddPersistentGroup(std::map<std::string, DBus::Variant> args);

        void RemovePersistentGroup(DBus::Path path);

        void RemoveAllPersistentGroups();

        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_DeviceFound( );
        std::shared_ptr<DBus::SignalProxy <
                        void(DBus::Path, std::map<std::string, DBus::Variant>)>> signal_DeviceFoundProperties( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_DeviceLost( );
        std::shared_ptr<DBus::SignalProxy < void()>> signal_FindStopped( );
        std::shared_ptr<
                DBus::SignalProxy < void(DBus::Path, std::string)>> signal_ProvisionDiscoveryRequestDisplayPin( );
        std::shared_ptr<
                DBus::SignalProxy < void(DBus::Path, std::string)>> signal_ProvisionDiscoveryResponseDisplayPin( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_ProvisionDiscoveryRequestEnterPin( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_ProvisionDiscoveryResponseEnterPin( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_ProvisionDiscoveryPBCRequest( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_ProvisionDiscoveryPBCResponse( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path, int32_t)>> signal_ProvisionDiscoveryFailure( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_GroupStarted( );
        std::shared_ptr<DBus::SignalProxy < void(std::string)>> signal_GroupFormationFailure( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_GONegotiationSuccess( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_GONegotiationFailure( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path, uint16_t, uint8_t)>> signal_GONegotiationRequest( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_InvitationResult( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_GroupFinished( );
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_ServiceDiscoveryRequest( );
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_ServiceDiscoveryResponse( );
        std::shared_ptr<DBus::SignalProxy <
                        void(DBus::Path, std::map<std::string, DBus::Variant>)>> signal_PersistentGroupAdded( );
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> signal_PersistentGroupRemoved( );
        std::shared_ptr<
                DBus::SignalProxy < void(std::string, std::map<std::string, DBus::Variant>)>> signal_WpsFailed( );
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> signal_InvitationReceived( );
    private:
        void setP2PDeviceConfig(std::map<std::string, DBus::Variant> value);

        std::map<std::string, DBus::Variant> P2PDeviceConfig();

        std::shared_ptr<DBus::PropertyProxy < std::map<std::string, DBus::Variant>>>

        getProperty_P2PDeviceConfig();

        void setPeers(std::vector<DBus::Path> value);

        std::vector<DBus::Path> Peers();

        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

        getProperty_Peers();

        void setRole(std::string value);

        std::string Role();

        std::shared_ptr<DBus::PropertyProxy < std::string>> getProperty_Role( );

        void setGroup(DBus::Path value);

        DBus::Path Group();

        std::shared_ptr<DBus::PropertyProxy < DBus::Path>> getProperty_Group( );

        void setPeerGO(DBus::Path value);

        DBus::Path PeerGO();

        std::shared_ptr<DBus::PropertyProxy < DBus::Path>> getProperty_PeerGO( );

        void setPersistentGroups(std::vector<DBus::Path> value);

        std::vector<DBus::Path> PersistentGroups();

        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

        getProperty_PersistentGroups();

    public:
        std::shared_ptr<DBus::PropertyProxy < std::map<std::string, DBus::Variant>>>
        m_property_P2PDeviceConfig;
        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>
        m_property_Peers;
        std::shared_ptr<DBus::PropertyProxy < std::string>> m_property_Role;
        std::shared_ptr<DBus::PropertyProxy < DBus::Path>> m_property_Group;
        std::shared_ptr<DBus::PropertyProxy < DBus::Path>> m_property_PeerGO;
        std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>
        m_property_PersistentGroups;
    protected:
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_Find;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_StopFind;
        std::shared_ptr<DBus::MethodProxy < void(int32_t)>>  m_method_Listen;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_ExtendedListen;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_PresenceRequest;
        std::shared_ptr<DBus::MethodProxy < void(DBus::Path, std::string)>>  m_method_ProvisionDiscoveryRequest;
        std::shared_ptr<DBus::MethodProxy < std::string(std::map<std::string, DBus::Variant>)>>  m_method_Connect;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_GroupAdd;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_Cancel;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_Invite;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_Disconnect;
        std::shared_ptr<DBus::MethodProxy < void(DBus::Path)>>  m_method_RejectPeer;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_RemoveClient;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_Flush;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_AddService;
        std::shared_ptr<DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_DeleteService;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_FlushService;
        std::shared_ptr<
                DBus::MethodProxy < uint64_t(std::map<std::string, DBus::Variant>)>>  m_method_ServiceDiscoveryRequest;
        std::shared_ptr<
                DBus::MethodProxy < void(std::map<std::string, DBus::Variant>)>>  m_method_ServiceDiscoveryResponse;
        std::shared_ptr<DBus::MethodProxy < void(uint64_t)>>  m_method_ServiceDiscoveryCancelRequest;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_ServiceUpdate;
        std::shared_ptr<DBus::MethodProxy < void(int32_t)>>  m_method_ServiceDiscoveryExternal;
        std::shared_ptr<
                DBus::MethodProxy < DBus::Path(std::map<std::string, DBus::Variant>)>>  m_method_AddPersistentGroup;
        std::shared_ptr<DBus::MethodProxy < void(DBus::Path)>>  m_method_RemovePersistentGroup;
        std::shared_ptr<DBus::MethodProxy < void()>>  m_method_RemoveAllPersistentGroups;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_DeviceFound;
        std::shared_ptr<DBus::SignalProxy <
                        void(DBus::Path, std::map<std::string, DBus::Variant>)>> m_signalproxy_DeviceFoundProperties;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_DeviceLost;
        std::shared_ptr<DBus::SignalProxy < void()>> m_signalproxy_FindStopped;
        std::shared_ptr<
                DBus::SignalProxy < void(DBus::Path, std::string)>> m_signalproxy_ProvisionDiscoveryRequestDisplayPin;
        std::shared_ptr<
                DBus::SignalProxy < void(DBus::Path, std::string)>> m_signalproxy_ProvisionDiscoveryResponseDisplayPin;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_ProvisionDiscoveryRequestEnterPin;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_ProvisionDiscoveryResponseEnterPin;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_ProvisionDiscoveryPBCRequest;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_ProvisionDiscoveryPBCResponse;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path, int32_t)>> m_signalproxy_ProvisionDiscoveryFailure;
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_GroupStarted;
        std::shared_ptr<DBus::SignalProxy < void(std::string)>> m_signalproxy_GroupFormationFailure;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_GONegotiationSuccess;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_GONegotiationFailure;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path, uint16_t, uint8_t)>> m_signalproxy_GONegotiationRequest;
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_InvitationResult;
        std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_GroupFinished;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_ServiceDiscoveryRequest;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_ServiceDiscoveryResponse;
        std::shared_ptr<DBus::SignalProxy <
                        void(DBus::Path, std::map<std::string, DBus::Variant>)>> m_signalproxy_PersistentGroupAdded;
        std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>> m_signalproxy_PersistentGroupRemoved;
        std::shared_ptr<
                DBus::SignalProxy < void(std::string, std::map<std::string, DBus::Variant>)>> m_signalproxy_WpsFailed;
        std::shared_ptr<
                DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>> m_signalproxy_InvitationReceived;
    };
} /* namespace WpaSupplicant */
#endif /* FI_WI_WPA_SUPPLICANT__INTERFACE_P_PDEVICEPROXY_H */
