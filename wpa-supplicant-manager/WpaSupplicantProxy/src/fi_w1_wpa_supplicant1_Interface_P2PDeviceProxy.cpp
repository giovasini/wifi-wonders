#include "../include/fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy.h"

using WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy;

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy(std::string name)
        : DBus::InterfaceProxy(name) {
    m_method_Find = this->create_method<void(std::map<std::string, DBus::Variant>)>("Find");
    m_method_StopFind = this->create_method<void()>("StopFind");
    m_method_Listen = this->create_method<void(int32_t)>("Listen");
    m_method_ExtendedListen = this->create_method<void(std::map<std::string, DBus::Variant>)>("ExtendedListen");
    m_method_PresenceRequest = this->create_method<void(std::map<std::string, DBus::Variant>)>("PresenceRequest");
    m_method_ProvisionDiscoveryRequest = this->create_method<void(DBus::Path, std::string)>(
            "ProvisionDiscoveryRequest");
    m_method_Connect = this->create_method<std::string(std::map<std::string, DBus::Variant>)>("Connect");
    m_method_GroupAdd = this->create_method<void(std::map<std::string, DBus::Variant>)>("GroupAdd");
    m_method_Cancel = this->create_method<void()>("Cancel");
    m_method_Invite = this->create_method<void(std::map<std::string, DBus::Variant>)>("Invite");
    m_method_Disconnect = this->create_method<void()>("Disconnect");
    m_method_RejectPeer = this->create_method<void(DBus::Path)>("RejectPeer");
    m_method_RemoveClient = this->create_method<void(std::map<std::string, DBus::Variant>)>("RemoveClient");
    m_method_Flush = this->create_method<void()>("Flush");
    m_method_AddService = this->create_method<void(std::map<std::string, DBus::Variant>)>("AddService");
    m_method_DeleteService = this->create_method<void(std::map<std::string, DBus::Variant>)>("DeleteService");
    m_method_FlushService = this->create_method<void()>("FlushService");
    m_method_ServiceDiscoveryRequest = this->create_method<uint64_t(std::map<std::string, DBus::Variant>)>(
            "ServiceDiscoveryRequest");
    m_method_ServiceDiscoveryResponse = this->create_method<void(std::map<std::string, DBus::Variant>)>(
            "ServiceDiscoveryResponse");
    m_method_ServiceDiscoveryCancelRequest = this->create_method<void(uint64_t)>("ServiceDiscoveryCancelRequest");
    m_method_ServiceUpdate = this->create_method<void()>("ServiceUpdate");
    m_method_ServiceDiscoveryExternal = this->create_method<void(int32_t)>("ServiceDiscoveryExternal");
    m_method_AddPersistentGroup = this->create_method<DBus::Path(std::map<std::string, DBus::Variant>)>(
            "AddPersistentGroup");
    m_method_RemovePersistentGroup = this->create_method<void(DBus::Path)>("RemovePersistentGroup");
    m_method_RemoveAllPersistentGroups = this->create_method<void()>("RemoveAllPersistentGroups");
    m_signalproxy_DeviceFound = this->create_signal<void(DBus::Path)>("DeviceFound");
    m_signalproxy_DeviceFoundProperties = this->create_signal<void(DBus::Path, std::map<std::string, DBus::Variant>)>(
            "DeviceFoundProperties");
    m_signalproxy_DeviceLost = this->create_signal<void(DBus::Path)>("DeviceLost");
    m_signalproxy_FindStopped = this->create_signal<void()>("FindStopped");
    m_signalproxy_ProvisionDiscoveryRequestDisplayPin = this->create_signal<void(DBus::Path, std::string)>(
            "ProvisionDiscoveryRequestDisplayPin");
    m_signalproxy_ProvisionDiscoveryResponseDisplayPin = this->create_signal<void(DBus::Path, std::string)>(
            "ProvisionDiscoveryResponseDisplayPin");
    m_signalproxy_ProvisionDiscoveryRequestEnterPin = this->create_signal<void(DBus::Path)>(
            "ProvisionDiscoveryRequestEnterPin");
    m_signalproxy_ProvisionDiscoveryResponseEnterPin = this->create_signal<void(DBus::Path)>(
            "ProvisionDiscoveryResponseEnterPin");
    m_signalproxy_ProvisionDiscoveryPBCRequest = this->create_signal<void(DBus::Path)>("ProvisionDiscoveryPBCRequest");
    m_signalproxy_ProvisionDiscoveryPBCResponse = this->create_signal<void(DBus::Path)>(
            "ProvisionDiscoveryPBCResponse");
    m_signalproxy_ProvisionDiscoveryFailure = this->create_signal<void(DBus::Path, int32_t)>(
            "ProvisionDiscoveryFailure");
    m_signalproxy_GroupStarted = this->create_signal<void(std::map<std::string, DBus::Variant>)>("GroupStarted");
    m_signalproxy_GroupFormationFailure = this->create_signal<void(std::string)>("GroupFormationFailure");
    m_signalproxy_GONegotiationSuccess = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "GONegotiationSuccess");
    m_signalproxy_GONegotiationFailure = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "GONegotiationFailure");
    m_signalproxy_GONegotiationRequest = this->create_signal<void(DBus::Path, uint16_t, uint8_t)>(
            "GONegotiationRequest");
    m_signalproxy_InvitationResult = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "InvitationResult");
    m_signalproxy_GroupFinished = this->create_signal<void(std::map<std::string, DBus::Variant>)>("GroupFinished");
    m_signalproxy_ServiceDiscoveryRequest = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "ServiceDiscoveryRequest");
    m_signalproxy_ServiceDiscoveryResponse = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "ServiceDiscoveryResponse");
    m_signalproxy_PersistentGroupAdded = this->create_signal<void(DBus::Path, std::map<std::string, DBus::Variant>)>(
            "PersistentGroupAdded");
    m_signalproxy_PersistentGroupRemoved = this->create_signal<void(DBus::Path)>("PersistentGroupRemoved");
    m_signalproxy_WpsFailed = this->create_signal<void(std::string, std::map<std::string, DBus::Variant>)>("WpsFailed");
    m_signalproxy_InvitationReceived = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "InvitationReceived");
    m_property_P2PDeviceConfig = this->create_property<std::map<std::string, DBus::Variant>>("P2PDeviceConfig");
    m_property_Peers = this->create_property<std::vector<DBus::Path>>("Peers");
    m_property_Role = this->create_property<std::string>("Role");
    m_property_Group = this->create_property<DBus::Path>("Group");
    m_property_PeerGO = this->create_property<DBus::Path>("PeerGO");
    m_property_PersistentGroups = this->create_property<std::vector<DBus::Path>>("PersistentGroups");

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy>
fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::create(std::string name) {
    return std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy>(
            new WpaSupplicant::fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy(name));

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Find(std::map<std::string, DBus::Variant> args) {
    (*m_method_Find)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::StopFind() {
    (*m_method_StopFind)();

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Listen(int32_t timeout) {
    (*m_method_Listen)(timeout);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ExtendedListen(std::map<std::string, DBus::Variant> args) {
    (*m_method_ExtendedListen)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::PresenceRequest(std::map<std::string, DBus::Variant> args) {
    (*m_method_PresenceRequest)(args);

}

void
fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ProvisionDiscoveryRequest(DBus::Path peer, std::string config_method) {
    (*m_method_ProvisionDiscoveryRequest)(peer, config_method);

}

std::string fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Connect(std::map<std::string, DBus::Variant> args) {
    return (*m_method_Connect)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::GroupAdd(std::map<std::string, DBus::Variant> args) {
    (*m_method_GroupAdd)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Cancel() {
    (*m_method_Cancel)();

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Invite(std::map<std::string, DBus::Variant> args) {
    (*m_method_Invite)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Disconnect() {
    (*m_method_Disconnect)();

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::RejectPeer(DBus::Path peer) {
    (*m_method_RejectPeer)(peer);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::RemoveClient(std::map<std::string, DBus::Variant> args) {
    (*m_method_RemoveClient)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Flush() {
    (*m_method_Flush)();

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::AddService(std::map<std::string, DBus::Variant> args) {
    (*m_method_AddService)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::DeleteService(std::map<std::string, DBus::Variant> args) {
    (*m_method_DeleteService)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::FlushService() {
    (*m_method_FlushService)();

}

uint64_t
fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ServiceDiscoveryRequest(std::map<std::string, DBus::Variant> args) {
    return (*m_method_ServiceDiscoveryRequest)(args);

}

void
fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ServiceDiscoveryResponse(std::map<std::string, DBus::Variant> args) {
    (*m_method_ServiceDiscoveryResponse)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ServiceDiscoveryCancelRequest(uint64_t args) {
    (*m_method_ServiceDiscoveryCancelRequest)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ServiceUpdate() {
    (*m_method_ServiceUpdate)();

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::ServiceDiscoveryExternal(int32_t arg) {
    (*m_method_ServiceDiscoveryExternal)(arg);

}

DBus::Path
fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::AddPersistentGroup(std::map<std::string, DBus::Variant> args) {
    return (*m_method_AddPersistentGroup)(args);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::RemovePersistentGroup(DBus::Path path) {
    (*m_method_RemovePersistentGroup)(path);

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::RemoveAllPersistentGroups() {
    (*m_method_RemoveAllPersistentGroups)();

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_DeviceFound() {
    return m_signalproxy_DeviceFound;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_DeviceFoundProperties() {
    return m_signalproxy_DeviceFoundProperties;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_DeviceLost() {
    return m_signalproxy_DeviceLost;

}

std::shared_ptr<DBus::SignalProxy < void()>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_FindStopped() {
    return m_signalproxy_FindStopped;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::string)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryRequestDisplayPin() {
    return m_signalproxy_ProvisionDiscoveryRequestDisplayPin;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::string)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryResponseDisplayPin() {
    return m_signalproxy_ProvisionDiscoveryResponseDisplayPin;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryRequestEnterPin() {
    return m_signalproxy_ProvisionDiscoveryRequestEnterPin;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryResponseEnterPin() {
    return m_signalproxy_ProvisionDiscoveryResponseEnterPin;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryPBCRequest() {
    return m_signalproxy_ProvisionDiscoveryPBCRequest;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryPBCResponse() {
    return m_signalproxy_ProvisionDiscoveryPBCResponse;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, int32_t)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ProvisionDiscoveryFailure() {
    return m_signalproxy_ProvisionDiscoveryFailure;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_GroupStarted() {
    return m_signalproxy_GroupStarted;

}

std::shared_ptr<DBus::SignalProxy < void(std::string)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_GroupFormationFailure() {
    return m_signalproxy_GroupFormationFailure;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_GONegotiationSuccess() {
    return m_signalproxy_GONegotiationSuccess;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_GONegotiationFailure() {
    return m_signalproxy_GONegotiationFailure;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, uint16_t, uint8_t)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_GONegotiationRequest() {
    return m_signalproxy_GONegotiationRequest;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_InvitationResult() {
    return m_signalproxy_InvitationResult;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_GroupFinished() {
    return m_signalproxy_GroupFinished;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ServiceDiscoveryRequest() {
    return m_signalproxy_ServiceDiscoveryRequest;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_ServiceDiscoveryResponse() {
    return m_signalproxy_ServiceDiscoveryResponse;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_PersistentGroupAdded() {
    return m_signalproxy_PersistentGroupAdded;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_PersistentGroupRemoved() {
    return m_signalproxy_PersistentGroupRemoved;

}

std::shared_ptr<DBus::SignalProxy < void(std::string, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_WpsFailed() {
    return m_signalproxy_WpsFailed;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::signal_InvitationReceived() {
    return m_signalproxy_InvitationReceived;

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::setP2PDeviceConfig(std::map<std::string, DBus::Variant> value) {
    m_property_P2PDeviceConfig->set_value(value);

}

std::map<std::string, DBus::Variant> fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::P2PDeviceConfig() {
    return m_property_P2PDeviceConfig->value();

}

std::shared_ptr<DBus::PropertyProxy < std::map<std::string, DBus::Variant>>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::getProperty_P2PDeviceConfig() {
    return m_property_P2PDeviceConfig;

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::setPeers(std::vector<DBus::Path> value) {
    m_property_Peers->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Peers() {
    return m_property_Peers->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::getProperty_Peers() {
    return m_property_Peers;

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::setRole(std::string value) {
    m_property_Role->set_value(value);

}

std::string fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Role() {
    return m_property_Role->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::getProperty_Role() {
    return m_property_Role;

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::setGroup(DBus::Path value) {
    m_property_Group->set_value(value);

}

DBus::Path fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::Group() {
    return m_property_Group->value();

}

std::shared_ptr<DBus::PropertyProxy < DBus::Path>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::getProperty_Group() {
    return m_property_Group;

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::setPeerGO(DBus::Path value) {
    m_property_PeerGO->set_value(value);

}

DBus::Path fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::PeerGO() {
    return m_property_PeerGO->value();

}

std::shared_ptr<DBus::PropertyProxy < DBus::Path>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::getProperty_PeerGO() {
    return m_property_PeerGO;

}

void fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::setPersistentGroups(std::vector<DBus::Path> value) {
    m_property_PersistentGroups->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::PersistentGroups() {
    return m_property_PersistentGroups->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy::getProperty_PersistentGroups() {
    return m_property_PersistentGroups;

}
