#include "../include/fi_w1_wpa_supplicant1_InterfaceProxy.h"

using WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy;

fi_w1_wpa_supplicant1_InterfaceProxy::fi_w1_wpa_supplicant1_InterfaceProxy(std::string name) : DBus::InterfaceProxy(
        name) {
    m_method_Scan = this->create_method<void(std::map<std::string, DBus::Variant>)>("Scan");
    m_method_SignalPoll = this->create_method<std::map<std::string, DBus::Variant>()>("SignalPoll");
    m_method_Disconnect = this->create_method<void()>("Disconnect");
    m_method_AddNetwork = this->create_method<DBus::Path(std::map<std::string, DBus::Variant>)>("AddNetwork");
    m_method_Reassociate = this->create_method<void()>("Reassociate");
    m_method_Reattach = this->create_method<void()>("Reattach");
    m_method_Reconnect = this->create_method<void()>("Reconnect");
    m_method_RemoveNetwork = this->create_method<void(DBus::Path)>("RemoveNetwork");
    m_method_RemoveAllNetworks = this->create_method<void()>("RemoveAllNetworks");
    m_method_SelectNetwork = this->create_method<void(DBus::Path)>("SelectNetwork");
    m_method_NetworkReply = this->create_method<void(DBus::Path, std::string, std::string)>("NetworkReply");
    m_method_AddBlob = this->create_method<void(std::string, std::vector<uint8_t>)>("AddBlob");
    m_method_GetBlob = this->create_method<std::vector<uint8_t>(std::string)>("GetBlob");
    m_method_RemoveBlob = this->create_method<void(std::string)>("RemoveBlob");
    m_method_SetPKCS11EngineAndModulePath = this->create_method<void(std::string, std::string)>(
            "SetPKCS11EngineAndModulePath");
    m_method_FlushBSS = this->create_method<void(uint32_t)>("FlushBSS");
    m_method_SubscribeProbeReq = this->create_method<void()>("SubscribeProbeReq");
    m_method_UnsubscribeProbeReq = this->create_method<void()>("UnsubscribeProbeReq");
    m_method_EAPLogoff = this->create_method<void()>("EAPLogoff");
    m_method_EAPLogon = this->create_method<void()>("EAPLogon");
    m_method_AutoScan = this->create_method<void(std::string)>("AutoScan");
    m_method_TDLSDiscover = this->create_method<void(std::string)>("TDLSDiscover");
    m_method_TDLSSetup = this->create_method<void(std::string)>("TDLSSetup");
    m_method_TDLSStatus = this->create_method<std::string(std::string)>("TDLSStatus");
    m_method_TDLSTeardown = this->create_method<void(std::string)>("TDLSTeardown");
    m_method_TDLSChannelSwitch = this->create_method<void(std::map<std::string, DBus::Variant>)>("TDLSChannelSwitch");
    m_method_TDLSCancelChannelSwitch = this->create_method<void(std::string)>("TDLSCancelChannelSwitch");
    m_method_VendorElemAdd = this->create_method<void(int32_t, std::vector<uint8_t>)>("VendorElemAdd");
    m_method_VendorElemGet = this->create_method<std::vector<uint8_t>(int32_t)>("VendorElemGet");
    m_method_VendorElemRem = this->create_method<void(int32_t, std::vector<uint8_t>)>("VendorElemRem");
    m_method_SaveConfig = this->create_method<void()>("SaveConfig");
    m_method_AbortScan = this->create_method<void()>("AbortScan");
    m_signalproxy_ScanDone = this->create_signal<void(bool)>("ScanDone");
    m_signalproxy_BSSAdded = this->create_signal<void(DBus::Path, std::map<std::string, DBus::Variant>)>("BSSAdded");
    m_signalproxy_BSSRemoved = this->create_signal<void(DBus::Path)>("BSSRemoved");
    m_signalproxy_BlobAdded = this->create_signal<void(std::string)>("BlobAdded");
    m_signalproxy_BlobRemoved = this->create_signal<void(std::string)>("BlobRemoved");
    m_signalproxy_NetworkAdded = this->create_signal<void(DBus::Path, std::map<std::string, DBus::Variant>)>(
            "NetworkAdded");
    m_signalproxy_NetworkRemoved = this->create_signal<void(DBus::Path)>("NetworkRemoved");
    m_signalproxy_NetworkSelected = this->create_signal<void(DBus::Path)>("NetworkSelected");
    m_signalproxy_PropertiesChanged = this->create_signal<void(std::map<std::string, DBus::Variant>)>(
            "PropertiesChanged");
    m_signalproxy_ProbeRequest = this->create_signal<void(std::map<std::string, DBus::Variant>)>("ProbeRequest");
    m_signalproxy_Certification = this->create_signal<void(std::map<std::string, DBus::Variant>)>("Certification");
    m_signalproxy_EAP = this->create_signal<void(std::string, std::string)>("EAP");
    m_signalproxy_StaAuthorized = this->create_signal<void(std::string)>("StaAuthorized");
    m_signalproxy_StaDeauthorized = this->create_signal<void(std::string)>("StaDeauthorized");
    m_signalproxy_StationAdded = this->create_signal<void(DBus::Path, std::map<std::string, DBus::Variant>)>(
            "StationAdded");
    m_signalproxy_StationRemoved = this->create_signal<void(DBus::Path)>("StationRemoved");
    m_signalproxy_NetworkRequest = this->create_signal<void(DBus::Path, std::string, std::string)>("NetworkRequest");
    m_property_Capabilities = this->create_property<std::map<std::string, DBus::Variant>>("Capabilities");
    m_property_State = this->create_property<std::string>("State");
    m_property_Scanning = this->create_property<bool>("Scanning");
    m_property_ApScan = this->create_property<uint32_t>("ApScan");
    m_property_BSSExpireAge = this->create_property<uint32_t>("BSSExpireAge");
    m_property_BSSExpireCount = this->create_property<uint32_t>("BSSExpireCount");
    m_property_Country = this->create_property<std::string>("Country");
    m_property_Ifname = this->create_property<std::string>("Ifname");
    m_property_Driver = this->create_property<std::string>("Driver");
    m_property_BridgeIfname = this->create_property<std::string>("BridgeIfname");
    m_property_ConfigFile = this->create_property<std::string>("ConfigFile");
    m_property_CurrentBSS = this->create_property<DBus::Path>("CurrentBSS");
    m_property_CurrentNetwork = this->create_property<DBus::Path>("CurrentNetwork");
    m_property_CurrentAuthMode = this->create_property<std::string>("CurrentAuthMode");
    m_property_Blobs = this->create_property<std::map<std::string, std::vector<uint8_t>>>("Blobs");
    m_property_BSSs = this->create_property<std::vector<DBus::Path>>("BSSs");
    m_property_Networks = this->create_property<std::vector<DBus::Path>>("Networks");
    m_property_FastReauth = this->create_property<bool>("FastReauth");
    m_property_ScanInterval = this->create_property<int32_t>("ScanInterval");
    m_property_PKCS11EnginePath = this->create_property<std::string>("PKCS11EnginePath");
    m_property_PKCS11ModulePath = this->create_property<std::string>("PKCS11ModulePath");
    m_property_DisconnectReason = this->create_property<int32_t>("DisconnectReason");
    m_property_AuthStatusCode = this->create_property<int32_t>("AuthStatusCode");
    m_property_AssocStatusCode = this->create_property<int32_t>("AssocStatusCode");
    m_property_RoamTime = this->create_property<uint32_t>("RoamTime");
    m_property_RoamComplete = this->create_property<bool>("RoamComplete");
    m_property_SessionLength = this->create_property<uint32_t>("SessionLength");
    m_property_BSSTMStatus = this->create_property<uint32_t>("BSSTMStatus");
    m_property_Stations = this->create_property<std::vector<DBus::Path>>("Stations");
    m_property_CtrlInterface = this->create_property<std::string>("CtrlInterface");
    m_property_CtrlInterfaceGroup = this->create_property<std::string>("CtrlInterfaceGroup");
    m_property_EapolVersion = this->create_property<std::string>("EapolVersion");
    m_property_Bgscan = this->create_property<std::string>("Bgscan");
    m_property_DisableScanOffload = this->create_property<std::string>("DisableScanOffload");
    m_property_OpenscEnginePath = this->create_property<std::string>("OpenscEnginePath");
    m_property_OpensslCiphers = this->create_property<std::string>("OpensslCiphers");
    m_property_PcscReader = this->create_property<std::string>("PcscReader");
    m_property_PcscPin = this->create_property<std::string>("PcscPin");
    m_property_ExternalSim = this->create_property<std::string>("ExternalSim");
    m_property_DriverParam = this->create_property<std::string>("DriverParam");
    m_property_Dot11RSNAConfigPMKLifetime = this->create_property<std::string>("Dot11RSNAConfigPMKLifetime");
    m_property_Dot11RSNAConfigPMKReauthThreshold = this->create_property<std::string>(
            "Dot11RSNAConfigPMKReauthThreshold");
    m_property_Dot11RSNAConfigSATimeout = this->create_property<std::string>("Dot11RSNAConfigSATimeout");
    m_property_UpdateConfig = this->create_property<std::string>("UpdateConfig");
    m_property_Uuid = this->create_property<std::string>("Uuid");
    m_property_AutoUuid = this->create_property<std::string>("AutoUuid");
    m_property_DeviceName = this->create_property<std::string>("DeviceName");
    m_property_Manufacturer = this->create_property<std::string>("Manufacturer");
    m_property_ModelName = this->create_property<std::string>("ModelName");
    m_property_ModelNumber = this->create_property<std::string>("ModelNumber");
    m_property_SerialNumber = this->create_property<std::string>("SerialNumber");
    m_property_DeviceType = this->create_property<std::string>("DeviceType");
    m_property_OsVersion = this->create_property<std::string>("OsVersion");
    m_property_ConfigMethods = this->create_property<std::string>("ConfigMethods");
    m_property_WpsCredProcessing = this->create_property<std::string>("WpsCredProcessing");
    m_property_WpsCredAddSae = this->create_property<std::string>("WpsCredAddSae");
    m_property_WpsVendorExtM1 = this->create_property<std::string>("WpsVendorExtM1");
    m_property_SecDeviceType = this->create_property<std::string>("SecDeviceType");
    m_property_P2pListenRegClass = this->create_property<std::string>("P2pListenRegClass");
    m_property_P2pListenChannel = this->create_property<std::string>("P2pListenChannel");
    m_property_P2pOperRegClass = this->create_property<std::string>("P2pOperRegClass");
    m_property_P2pOperChannel = this->create_property<std::string>("P2pOperChannel");
    m_property_P2pGoIntent = this->create_property<std::string>("P2pGoIntent");
    m_property_P2pSsidPostfix = this->create_property<std::string>("P2pSsidPostfix");
    m_property_PersistentReconnect = this->create_property<std::string>("PersistentReconnect");
    m_property_P2pIntraBss = this->create_property<std::string>("P2pIntraBss");
    m_property_P2pGroupIdle = this->create_property<std::string>("P2pGroupIdle");
    m_property_P2pGoFreqChangePolicy = this->create_property<std::string>("P2pGoFreqChangePolicy");
    m_property_P2pPassphraseLen = this->create_property<std::string>("P2pPassphraseLen");
    m_property_P2pPrefChan = this->create_property<std::string>("P2pPrefChan");
    m_property_P2pNoGoFreq = this->create_property<std::string>("P2pNoGoFreq");
    m_property_P2pAddCliChan = this->create_property<std::string>("P2pAddCliChan");
    m_property_P2pOptimizeListenChan = this->create_property<std::string>("P2pOptimizeListenChan");
    m_property_P2pGoHt40 = this->create_property<std::string>("P2pGoHt40");
    m_property_P2pGoVht = this->create_property<std::string>("P2pGoVht");
    m_property_P2pGoHe = this->create_property<std::string>("P2pGoHe");
    m_property_P2pDisabled = this->create_property<std::string>("P2pDisabled");
    m_property_P2pGoCtwindow = this->create_property<std::string>("P2pGoCtwindow");
    m_property_P2pNoGroupIface = this->create_property<std::string>("P2pNoGroupIface");
    m_property_P2pIgnoreSharedFreq = this->create_property<std::string>("P2pIgnoreSharedFreq");
    m_property_IpAddrGo = this->create_property<std::string>("IpAddrGo");
    m_property_IpAddrMask = this->create_property<std::string>("IpAddrMask");
    m_property_IpAddrStart = this->create_property<std::string>("IpAddrStart");
    m_property_IpAddrEnd = this->create_property<std::string>("IpAddrEnd");
    m_property_P2pCliProbe = this->create_property<std::string>("P2pCliProbe");
    m_property_P2pDeviceRandomMacAddr = this->create_property<std::string>("P2pDeviceRandomMacAddr");
    m_property_P2pDevicePersistentMacAddr = this->create_property<std::string>("P2pDevicePersistentMacAddr");
    m_property_P2pInterfaceRandomMacAddr = this->create_property<std::string>("P2pInterfaceRandomMacAddr");
    m_property_BssMaxCount = this->create_property<std::string>("BssMaxCount");
    m_property_FilterSsids = this->create_property<std::string>("FilterSsids");
    m_property_FilterRssi = this->create_property<std::string>("FilterRssi");
    m_property_MaxNumSta = this->create_property<std::string>("MaxNumSta");
    m_property_ApIsolate = this->create_property<std::string>("ApIsolate");
    m_property_DisassocLowAck = this->create_property<std::string>("DisassocLowAck");
    m_property_Hs20 = this->create_property<std::string>("Hs20");
    m_property_Interworking = this->create_property<std::string>("Interworking");
    m_property_Hessid = this->create_property<std::string>("Hessid");
    m_property_AccessNetworkType = this->create_property<std::string>("AccessNetworkType");
    m_property_GoInterworking = this->create_property<std::string>("GoInterworking");
    m_property_GoAccessNetworkType = this->create_property<std::string>("GoAccessNetworkType");
    m_property_GoInternet = this->create_property<std::string>("GoInternet");
    m_property_GoVenueGroup = this->create_property<std::string>("GoVenueGroup");
    m_property_GoVenueType = this->create_property<std::string>("GoVenueType");
    m_property_PbcInM1 = this->create_property<std::string>("PbcInM1");
    m_property_Autoscan = this->create_property<std::string>("Autoscan");
    m_property_WpsNfcDevPwId = this->create_property<std::string>("WpsNfcDevPwId");
    m_property_WpsNfcDhPubkey = this->create_property<std::string>("WpsNfcDhPubkey");
    m_property_WpsNfcDhPrivkey = this->create_property<std::string>("WpsNfcDhPrivkey");
    m_property_WpsNfcDevPw = this->create_property<std::string>("WpsNfcDevPw");
    m_property_ExtPasswordBackend = this->create_property<std::string>("ExtPasswordBackend");
    m_property_P2pGoMaxInactivity = this->create_property<std::string>("P2pGoMaxInactivity");
    m_property_AutoInterworking = this->create_property<std::string>("AutoInterworking");
    m_property_Okc = this->create_property<std::string>("Okc");
    m_property_Pmf = this->create_property<std::string>("Pmf");
    m_property_SaeGroups = this->create_property<std::string>("SaeGroups");
    m_property_DtimPeriod = this->create_property<std::string>("DtimPeriod");
    m_property_BeaconInt = this->create_property<std::string>("BeaconInt");
    m_property_ApVendorElements = this->create_property<std::string>("ApVendorElements");
    m_property_IgnoreOldScanRes = this->create_property<std::string>("IgnoreOldScanRes");
    m_property_FreqList = this->create_property<std::string>("FreqList");
    m_property_ScanCurFreq = this->create_property<std::string>("ScanCurFreq");
    m_property_SchedScanInterval = this->create_property<std::string>("SchedScanInterval");
    m_property_SchedScanStartDelay = this->create_property<std::string>("SchedScanStartDelay");
    m_property_TdlsExternalControl = this->create_property<std::string>("TdlsExternalControl");
    m_property_OsuDir = this->create_property<std::string>("OsuDir");
    m_property_WowlanTriggers = this->create_property<std::string>("WowlanTriggers");
    m_property_P2pSearchDelay = this->create_property<std::string>("P2pSearchDelay");
    m_property_MacAddr = this->create_property<std::string>("MacAddr");
    m_property_RandAddrLifetime = this->create_property<std::string>("RandAddrLifetime");
    m_property_PreassocMacAddr = this->create_property<std::string>("PreassocMacAddr");
    m_property_KeyMgmtOffload = this->create_property<std::string>("KeyMgmtOffload");
    m_property_PassiveScan = this->create_property<std::string>("PassiveScan");
    m_property_ReassocSameBssOptim = this->create_property<std::string>("ReassocSameBssOptim");
    m_property_WpsPriority = this->create_property<std::string>("WpsPriority");
    m_property_FstGroupId = this->create_property<std::string>("FstGroupId");
    m_property_FstPriority = this->create_property<std::string>("FstPriority");
    m_property_FstLlt = this->create_property<std::string>("FstLlt");
    m_property_CertInCb = this->create_property<std::string>("CertInCb");
    m_property_WpaRscRelaxation = this->create_property<std::string>("WpaRscRelaxation");
    m_property_SchedScanPlans = this->create_property<std::string>("SchedScanPlans");
    m_property_GasAddress3 = this->create_property<std::string>("GasAddress3");
    m_property_FtmResponder = this->create_property<std::string>("FtmResponder");
    m_property_FtmInitiator = this->create_property<std::string>("FtmInitiator");
    m_property_GasRandAddrLifetime = this->create_property<std::string>("GasRandAddrLifetime");
    m_property_GasRandMacAddr = this->create_property<std::string>("GasRandMacAddr");
    m_property_DppConfigProcessing = this->create_property<std::string>("DppConfigProcessing");
    m_property_ColocIntfReporting = this->create_property<std::string>("ColocIntfReporting");

}

std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy>
fi_w1_wpa_supplicant1_InterfaceProxy::create(std::string name) {
    return std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy>(
            new WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy(name));

}

void fi_w1_wpa_supplicant1_InterfaceProxy::Scan(std::map<std::string, DBus::Variant> args) {
    (*m_method_Scan)(args);

}

std::map<std::string, DBus::Variant> fi_w1_wpa_supplicant1_InterfaceProxy::SignalPoll() {
    return (*m_method_SignalPoll)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::Disconnect() {
    (*m_method_Disconnect)();

}

DBus::Path fi_w1_wpa_supplicant1_InterfaceProxy::AddNetwork(std::map<std::string, DBus::Variant> args) {
    return (*m_method_AddNetwork)(args);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::Reassociate() {
    (*m_method_Reassociate)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::Reattach() {
    (*m_method_Reattach)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::Reconnect() {
    (*m_method_Reconnect)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::RemoveNetwork(DBus::Path path) {
    (*m_method_RemoveNetwork)(path);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::RemoveAllNetworks() {
    (*m_method_RemoveAllNetworks)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::SelectNetwork(DBus::Path path) {
    (*m_method_SelectNetwork)(path);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::NetworkReply(DBus::Path path, std::string field, std::string value) {
    (*m_method_NetworkReply)(path, field, value);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::AddBlob(std::string name, std::vector<uint8_t> data) {
    (*m_method_AddBlob)(name, data);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_InterfaceProxy::GetBlob(std::string name) {
    return (*m_method_GetBlob)(name);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::RemoveBlob(std::string name) {
    (*m_method_RemoveBlob)(name);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::SetPKCS11EngineAndModulePath(std::string pkcs11_engine_path,
                                                                        std::string pkcs11_module_path) {
    (*m_method_SetPKCS11EngineAndModulePath)(pkcs11_engine_path, pkcs11_module_path);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::FlushBSS(uint32_t age) {
    (*m_method_FlushBSS)(age);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::SubscribeProbeReq() {
    (*m_method_SubscribeProbeReq)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::UnsubscribeProbeReq() {
    (*m_method_UnsubscribeProbeReq)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::EAPLogoff() {
    (*m_method_EAPLogoff)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::EAPLogon() {
    (*m_method_EAPLogon)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::AutoScan(std::string arg) {
    (*m_method_AutoScan)(arg);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::TDLSDiscover(std::string peer_address) {
    (*m_method_TDLSDiscover)(peer_address);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::TDLSSetup(std::string peer_address) {
    (*m_method_TDLSSetup)(peer_address);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::TDLSStatus(std::string peer_address) {
    return (*m_method_TDLSStatus)(peer_address);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::TDLSTeardown(std::string peer_address) {
    (*m_method_TDLSTeardown)(peer_address);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::TDLSChannelSwitch(std::map<std::string, DBus::Variant> args) {
    (*m_method_TDLSChannelSwitch)(args);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::TDLSCancelChannelSwitch(std::string peer_address) {
    (*m_method_TDLSCancelChannelSwitch)(peer_address);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::VendorElemAdd(int32_t frame_id, std::vector<uint8_t> ielems) {
    (*m_method_VendorElemAdd)(frame_id, ielems);

}

std::vector<uint8_t> fi_w1_wpa_supplicant1_InterfaceProxy::VendorElemGet(int32_t frame_id) {
    return (*m_method_VendorElemGet)(frame_id);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::VendorElemRem(int32_t frame_id, std::vector<uint8_t> ielems) {
    (*m_method_VendorElemRem)(frame_id, ielems);

}

void fi_w1_wpa_supplicant1_InterfaceProxy::SaveConfig() {
    (*m_method_SaveConfig)();

}

void fi_w1_wpa_supplicant1_InterfaceProxy::AbortScan() {
    (*m_method_AbortScan)();

}

std::shared_ptr<DBus::SignalProxy < void(bool)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_ScanDone() {
    return m_signalproxy_ScanDone;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_BSSAdded() {
    return m_signalproxy_BSSAdded;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_BSSRemoved() {
    return m_signalproxy_BSSRemoved;

}

std::shared_ptr<DBus::SignalProxy < void(std::string)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_BlobAdded() {
    return m_signalproxy_BlobAdded;

}

std::shared_ptr<DBus::SignalProxy < void(std::string)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_BlobRemoved() {
    return m_signalproxy_BlobRemoved;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_NetworkAdded() {
    return m_signalproxy_NetworkAdded;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_NetworkRemoved() {
    return m_signalproxy_NetworkRemoved;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_NetworkSelected() {
    return m_signalproxy_NetworkSelected;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_PropertiesChanged() {
    return m_signalproxy_PropertiesChanged;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_ProbeRequest() {
    return m_signalproxy_ProbeRequest;

}

std::shared_ptr<DBus::SignalProxy < void(std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_Certification() {
    return m_signalproxy_Certification;

}

std::shared_ptr<DBus::SignalProxy < void(std::string, std::string)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_EAP() {
    return m_signalproxy_EAP;

}

std::shared_ptr<DBus::SignalProxy < void(std::string)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_StaAuthorized() {
    return m_signalproxy_StaAuthorized;

}

std::shared_ptr<DBus::SignalProxy < void(std::string)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_StaDeauthorized() {
    return m_signalproxy_StaDeauthorized;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::map<std::string, DBus::Variant>)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_StationAdded() {
    return m_signalproxy_StationAdded;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_StationRemoved() {
    return m_signalproxy_StationRemoved;

}

std::shared_ptr<DBus::SignalProxy < void(DBus::Path, std::string, std::string)>>

fi_w1_wpa_supplicant1_InterfaceProxy::signal_NetworkRequest() {
    return m_signalproxy_NetworkRequest;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCapabilities(std::map<std::string, DBus::Variant> value) {
    m_property_Capabilities->set_value(value);

}

std::map<std::string, DBus::Variant> fi_w1_wpa_supplicant1_InterfaceProxy::Capabilities() {
    return m_property_Capabilities->value();

}

std::shared_ptr<DBus::PropertyProxy < std::map<std::string, DBus::Variant>>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Capabilities() {
    return m_property_Capabilities;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setState(std::string value) {
    m_property_State->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::State() {
    return m_property_State->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_State() {
    return m_property_State;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setScanning(bool value) {
    m_property_Scanning->set_value(value);

}

bool fi_w1_wpa_supplicant1_InterfaceProxy::Scanning() {
    return m_property_Scanning->value();

}

std::shared_ptr<DBus::PropertyProxy < bool>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Scanning() {
    return m_property_Scanning;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setApScan(uint32_t value) {
    m_property_ApScan->set_value(value);

}

uint32_t fi_w1_wpa_supplicant1_InterfaceProxy::ApScan() {
    return m_property_ApScan->value();

}

std::shared_ptr<DBus::PropertyProxy < uint32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ApScan() {
    return m_property_ApScan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBSSExpireAge(uint32_t value) {
    m_property_BSSExpireAge->set_value(value);

}

uint32_t fi_w1_wpa_supplicant1_InterfaceProxy::BSSExpireAge() {
    return m_property_BSSExpireAge->value();

}

std::shared_ptr<DBus::PropertyProxy < uint32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BSSExpireAge() {
    return m_property_BSSExpireAge;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBSSExpireCount(uint32_t value) {
    m_property_BSSExpireCount->set_value(value);

}

uint32_t fi_w1_wpa_supplicant1_InterfaceProxy::BSSExpireCount() {
    return m_property_BSSExpireCount->value();

}

std::shared_ptr<DBus::PropertyProxy < uint32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BSSExpireCount() {
    return m_property_BSSExpireCount;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCountry(std::string value) {
    m_property_Country->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Country() {
    return m_property_Country->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Country() {
    return m_property_Country;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setIfname(std::string value) {
    m_property_Ifname->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Ifname() {
    return m_property_Ifname->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Ifname() {
    return m_property_Ifname;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDriver(std::string value) {
    m_property_Driver->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Driver() {
    return m_property_Driver->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Driver() {
    return m_property_Driver;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBridgeIfname(std::string value) {
    m_property_BridgeIfname->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::BridgeIfname() {
    return m_property_BridgeIfname->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BridgeIfname() {
    return m_property_BridgeIfname;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setConfigFile(std::string value) {
    m_property_ConfigFile->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ConfigFile() {
    return m_property_ConfigFile->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ConfigFile() {
    return m_property_ConfigFile;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCurrentBSS(DBus::Path value) {
    m_property_CurrentBSS->set_value(value);

}

DBus::Path fi_w1_wpa_supplicant1_InterfaceProxy::CurrentBSS() {
    return m_property_CurrentBSS->value();

}

std::shared_ptr<DBus::PropertyProxy < DBus::Path>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_CurrentBSS() {
    return m_property_CurrentBSS;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCurrentNetwork(DBus::Path value) {
    m_property_CurrentNetwork->set_value(value);

}

DBus::Path fi_w1_wpa_supplicant1_InterfaceProxy::CurrentNetwork() {
    return m_property_CurrentNetwork->value();

}

std::shared_ptr<DBus::PropertyProxy < DBus::Path>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_CurrentNetwork() {
    return m_property_CurrentNetwork;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCurrentAuthMode(std::string value) {
    m_property_CurrentAuthMode->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::CurrentAuthMode() {
    return m_property_CurrentAuthMode->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_CurrentAuthMode() {
    return m_property_CurrentAuthMode;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBlobs(std::map<std::string, std::vector<uint8_t>> value) {
    m_property_Blobs->set_value(value);

}

std::map<std::string, std::vector<uint8_t>> fi_w1_wpa_supplicant1_InterfaceProxy::Blobs() {
    return m_property_Blobs->value();

}

std::shared_ptr<DBus::PropertyProxy < std::map<std::string, std::vector<uint8_t>>>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Blobs() {
    return m_property_Blobs;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBSSs(std::vector<DBus::Path> value) {
    m_property_BSSs->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_InterfaceProxy::BSSs() {
    return m_property_BSSs->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BSSs() {
    return m_property_BSSs;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setNetworks(std::vector<DBus::Path> value) {
    m_property_Networks->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_InterfaceProxy::Networks() {
    return m_property_Networks->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Networks() {
    return m_property_Networks;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFastReauth(bool value) {
    m_property_FastReauth->set_value(value);

}

bool fi_w1_wpa_supplicant1_InterfaceProxy::FastReauth() {
    return m_property_FastReauth->value();

}

std::shared_ptr<DBus::PropertyProxy < bool>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FastReauth() {
    return m_property_FastReauth;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setScanInterval(int32_t value) {
    m_property_ScanInterval->set_value(value);

}

int32_t fi_w1_wpa_supplicant1_InterfaceProxy::ScanInterval() {
    return m_property_ScanInterval->value();

}

std::shared_ptr<DBus::PropertyProxy < int32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ScanInterval() {
    return m_property_ScanInterval;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPKCS11EnginePath(std::string value) {
    m_property_PKCS11EnginePath->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PKCS11EnginePath() {
    return m_property_PKCS11EnginePath->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PKCS11EnginePath() {
    return m_property_PKCS11EnginePath;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPKCS11ModulePath(std::string value) {
    m_property_PKCS11ModulePath->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PKCS11ModulePath() {
    return m_property_PKCS11ModulePath->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PKCS11ModulePath() {
    return m_property_PKCS11ModulePath;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDisconnectReason(int32_t value) {
    m_property_DisconnectReason->set_value(value);

}

int32_t fi_w1_wpa_supplicant1_InterfaceProxy::DisconnectReason() {
    return m_property_DisconnectReason->value();

}

std::shared_ptr<DBus::PropertyProxy < int32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DisconnectReason() {
    return m_property_DisconnectReason;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setAuthStatusCode(int32_t value) {
    m_property_AuthStatusCode->set_value(value);

}

int32_t fi_w1_wpa_supplicant1_InterfaceProxy::AuthStatusCode() {
    return m_property_AuthStatusCode->value();

}

std::shared_ptr<DBus::PropertyProxy < int32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_AuthStatusCode() {
    return m_property_AuthStatusCode;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setAssocStatusCode(int32_t value) {
    m_property_AssocStatusCode->set_value(value);

}

int32_t fi_w1_wpa_supplicant1_InterfaceProxy::AssocStatusCode() {
    return m_property_AssocStatusCode->value();

}

std::shared_ptr<DBus::PropertyProxy < int32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_AssocStatusCode() {
    return m_property_AssocStatusCode;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setRoamTime(uint32_t value) {
    m_property_RoamTime->set_value(value);

}

uint32_t fi_w1_wpa_supplicant1_InterfaceProxy::RoamTime() {
    return m_property_RoamTime->value();

}

std::shared_ptr<DBus::PropertyProxy < uint32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_RoamTime() {
    return m_property_RoamTime;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setRoamComplete(bool value) {
    m_property_RoamComplete->set_value(value);

}

bool fi_w1_wpa_supplicant1_InterfaceProxy::RoamComplete() {
    return m_property_RoamComplete->value();

}

std::shared_ptr<DBus::PropertyProxy < bool>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_RoamComplete() {
    return m_property_RoamComplete;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSessionLength(uint32_t value) {
    m_property_SessionLength->set_value(value);

}

uint32_t fi_w1_wpa_supplicant1_InterfaceProxy::SessionLength() {
    return m_property_SessionLength->value();

}

std::shared_ptr<DBus::PropertyProxy < uint32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SessionLength() {
    return m_property_SessionLength;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBSSTMStatus(uint32_t value) {
    m_property_BSSTMStatus->set_value(value);

}

uint32_t fi_w1_wpa_supplicant1_InterfaceProxy::BSSTMStatus() {
    return m_property_BSSTMStatus->value();

}

std::shared_ptr<DBus::PropertyProxy < uint32_t>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BSSTMStatus() {
    return m_property_BSSTMStatus;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setStations(std::vector<DBus::Path> value) {
    m_property_Stations->set_value(value);

}

std::vector<DBus::Path> fi_w1_wpa_supplicant1_InterfaceProxy::Stations() {
    return m_property_Stations->value();

}

std::shared_ptr<DBus::PropertyProxy < std::vector<DBus::Path>>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Stations() {
    return m_property_Stations;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCtrlInterface(std::string value) {
    m_property_CtrlInterface->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::CtrlInterface() {
    return m_property_CtrlInterface->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_CtrlInterface() {
    return m_property_CtrlInterface;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCtrlInterfaceGroup(std::string value) {
    m_property_CtrlInterfaceGroup->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::CtrlInterfaceGroup() {
    return m_property_CtrlInterfaceGroup->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_CtrlInterfaceGroup() {
    return m_property_CtrlInterfaceGroup;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setEapolVersion(std::string value) {
    m_property_EapolVersion->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::EapolVersion() {
    return m_property_EapolVersion->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_EapolVersion() {
    return m_property_EapolVersion;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBgscan(std::string value) {
    m_property_Bgscan->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Bgscan() {
    return m_property_Bgscan->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Bgscan() {
    return m_property_Bgscan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDisableScanOffload(std::string value) {
    m_property_DisableScanOffload->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DisableScanOffload() {
    return m_property_DisableScanOffload->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DisableScanOffload() {
    return m_property_DisableScanOffload;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setOpenscEnginePath(std::string value) {
    m_property_OpenscEnginePath->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::OpenscEnginePath() {
    return m_property_OpenscEnginePath->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_OpenscEnginePath() {
    return m_property_OpenscEnginePath;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setOpensslCiphers(std::string value) {
    m_property_OpensslCiphers->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::OpensslCiphers() {
    return m_property_OpensslCiphers->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_OpensslCiphers() {
    return m_property_OpensslCiphers;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPcscReader(std::string value) {
    m_property_PcscReader->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PcscReader() {
    return m_property_PcscReader->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PcscReader() {
    return m_property_PcscReader;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPcscPin(std::string value) {
    m_property_PcscPin->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PcscPin() {
    return m_property_PcscPin->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PcscPin() {
    return m_property_PcscPin;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setExternalSim(std::string value) {
    m_property_ExternalSim->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ExternalSim() {
    return m_property_ExternalSim->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ExternalSim() {
    return m_property_ExternalSim;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDriverParam(std::string value) {
    m_property_DriverParam->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DriverParam() {
    return m_property_DriverParam->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DriverParam() {
    return m_property_DriverParam;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDot11RSNAConfigPMKLifetime(std::string value) {
    m_property_Dot11RSNAConfigPMKLifetime->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Dot11RSNAConfigPMKLifetime() {
    return m_property_Dot11RSNAConfigPMKLifetime->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Dot11RSNAConfigPMKLifetime() {
    return m_property_Dot11RSNAConfigPMKLifetime;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDot11RSNAConfigPMKReauthThreshold(std::string value) {
    m_property_Dot11RSNAConfigPMKReauthThreshold->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Dot11RSNAConfigPMKReauthThreshold() {
    return m_property_Dot11RSNAConfigPMKReauthThreshold->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Dot11RSNAConfigPMKReauthThreshold() {
    return m_property_Dot11RSNAConfigPMKReauthThreshold;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDot11RSNAConfigSATimeout(std::string value) {
    m_property_Dot11RSNAConfigSATimeout->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Dot11RSNAConfigSATimeout() {
    return m_property_Dot11RSNAConfigSATimeout->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Dot11RSNAConfigSATimeout() {
    return m_property_Dot11RSNAConfigSATimeout;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setUpdateConfig(std::string value) {
    m_property_UpdateConfig->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::UpdateConfig() {
    return m_property_UpdateConfig->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_UpdateConfig() {
    return m_property_UpdateConfig;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setUuid(std::string value) {
    m_property_Uuid->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Uuid() {
    return m_property_Uuid->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Uuid() {
    return m_property_Uuid;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setAutoUuid(std::string value) {
    m_property_AutoUuid->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::AutoUuid() {
    return m_property_AutoUuid->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_AutoUuid() {
    return m_property_AutoUuid;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDeviceName(std::string value) {
    m_property_DeviceName->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DeviceName() {
    return m_property_DeviceName->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DeviceName() {
    return m_property_DeviceName;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setManufacturer(std::string value) {
    m_property_Manufacturer->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Manufacturer() {
    return m_property_Manufacturer->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Manufacturer() {
    return m_property_Manufacturer;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setModelName(std::string value) {
    m_property_ModelName->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ModelName() {
    return m_property_ModelName->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ModelName() {
    return m_property_ModelName;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setModelNumber(std::string value) {
    m_property_ModelNumber->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ModelNumber() {
    return m_property_ModelNumber->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ModelNumber() {
    return m_property_ModelNumber;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSerialNumber(std::string value) {
    m_property_SerialNumber->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::SerialNumber() {
    return m_property_SerialNumber->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SerialNumber() {
    return m_property_SerialNumber;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDeviceType(std::string value) {
    m_property_DeviceType->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DeviceType() {
    return m_property_DeviceType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DeviceType() {
    return m_property_DeviceType;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setOsVersion(std::string value) {
    m_property_OsVersion->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::OsVersion() {
    return m_property_OsVersion->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_OsVersion() {
    return m_property_OsVersion;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setConfigMethods(std::string value) {
    m_property_ConfigMethods->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ConfigMethods() {
    return m_property_ConfigMethods->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ConfigMethods() {
    return m_property_ConfigMethods;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsCredProcessing(std::string value) {
    m_property_WpsCredProcessing->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsCredProcessing() {
    return m_property_WpsCredProcessing->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsCredProcessing() {
    return m_property_WpsCredProcessing;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsCredAddSae(std::string value) {
    m_property_WpsCredAddSae->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsCredAddSae() {
    return m_property_WpsCredAddSae->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsCredAddSae() {
    return m_property_WpsCredAddSae;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsVendorExtM1(std::string value) {
    m_property_WpsVendorExtM1->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsVendorExtM1() {
    return m_property_WpsVendorExtM1->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsVendorExtM1() {
    return m_property_WpsVendorExtM1;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSecDeviceType(std::string value) {
    m_property_SecDeviceType->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::SecDeviceType() {
    return m_property_SecDeviceType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SecDeviceType() {
    return m_property_SecDeviceType;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pListenRegClass(std::string value) {
    m_property_P2pListenRegClass->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pListenRegClass() {
    return m_property_P2pListenRegClass->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pListenRegClass() {
    return m_property_P2pListenRegClass;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pListenChannel(std::string value) {
    m_property_P2pListenChannel->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pListenChannel() {
    return m_property_P2pListenChannel->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pListenChannel() {
    return m_property_P2pListenChannel;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pOperRegClass(std::string value) {
    m_property_P2pOperRegClass->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pOperRegClass() {
    return m_property_P2pOperRegClass->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pOperRegClass() {
    return m_property_P2pOperRegClass;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pOperChannel(std::string value) {
    m_property_P2pOperChannel->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pOperChannel() {
    return m_property_P2pOperChannel->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pOperChannel() {
    return m_property_P2pOperChannel;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoIntent(std::string value) {
    m_property_P2pGoIntent->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoIntent() {
    return m_property_P2pGoIntent->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoIntent() {
    return m_property_P2pGoIntent;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pSsidPostfix(std::string value) {
    m_property_P2pSsidPostfix->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pSsidPostfix() {
    return m_property_P2pSsidPostfix->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pSsidPostfix() {
    return m_property_P2pSsidPostfix;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPersistentReconnect(std::string value) {
    m_property_PersistentReconnect->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PersistentReconnect() {
    return m_property_PersistentReconnect->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PersistentReconnect() {
    return m_property_PersistentReconnect;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pIntraBss(std::string value) {
    m_property_P2pIntraBss->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pIntraBss() {
    return m_property_P2pIntraBss->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pIntraBss() {
    return m_property_P2pIntraBss;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGroupIdle(std::string value) {
    m_property_P2pGroupIdle->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGroupIdle() {
    return m_property_P2pGroupIdle->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGroupIdle() {
    return m_property_P2pGroupIdle;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoFreqChangePolicy(std::string value) {
    m_property_P2pGoFreqChangePolicy->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoFreqChangePolicy() {
    return m_property_P2pGoFreqChangePolicy->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoFreqChangePolicy() {
    return m_property_P2pGoFreqChangePolicy;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pPassphraseLen(std::string value) {
    m_property_P2pPassphraseLen->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pPassphraseLen() {
    return m_property_P2pPassphraseLen->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pPassphraseLen() {
    return m_property_P2pPassphraseLen;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pPrefChan(std::string value) {
    m_property_P2pPrefChan->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pPrefChan() {
    return m_property_P2pPrefChan->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pPrefChan() {
    return m_property_P2pPrefChan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pNoGoFreq(std::string value) {
    m_property_P2pNoGoFreq->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pNoGoFreq() {
    return m_property_P2pNoGoFreq->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pNoGoFreq() {
    return m_property_P2pNoGoFreq;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pAddCliChan(std::string value) {
    m_property_P2pAddCliChan->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pAddCliChan() {
    return m_property_P2pAddCliChan->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pAddCliChan() {
    return m_property_P2pAddCliChan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pOptimizeListenChan(std::string value) {
    m_property_P2pOptimizeListenChan->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pOptimizeListenChan() {
    return m_property_P2pOptimizeListenChan->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pOptimizeListenChan() {
    return m_property_P2pOptimizeListenChan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoHt40(std::string value) {
    m_property_P2pGoHt40->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoHt40() {
    return m_property_P2pGoHt40->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoHt40() {
    return m_property_P2pGoHt40;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoVht(std::string value) {
    m_property_P2pGoVht->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoVht() {
    return m_property_P2pGoVht->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoVht() {
    return m_property_P2pGoVht;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoHe(std::string value) {
    m_property_P2pGoHe->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoHe() {
    return m_property_P2pGoHe->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoHe() {
    return m_property_P2pGoHe;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pDisabled(std::string value) {
    m_property_P2pDisabled->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pDisabled() {
    return m_property_P2pDisabled->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pDisabled() {
    return m_property_P2pDisabled;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoCtwindow(std::string value) {
    m_property_P2pGoCtwindow->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoCtwindow() {
    return m_property_P2pGoCtwindow->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoCtwindow() {
    return m_property_P2pGoCtwindow;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pNoGroupIface(std::string value) {
    m_property_P2pNoGroupIface->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pNoGroupIface() {
    return m_property_P2pNoGroupIface->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pNoGroupIface() {
    return m_property_P2pNoGroupIface;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pIgnoreSharedFreq(std::string value) {
    m_property_P2pIgnoreSharedFreq->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pIgnoreSharedFreq() {
    return m_property_P2pIgnoreSharedFreq->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pIgnoreSharedFreq() {
    return m_property_P2pIgnoreSharedFreq;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setIpAddrGo(std::string value) {
    m_property_IpAddrGo->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::IpAddrGo() {
    return m_property_IpAddrGo->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_IpAddrGo() {
    return m_property_IpAddrGo;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setIpAddrMask(std::string value) {
    m_property_IpAddrMask->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::IpAddrMask() {
    return m_property_IpAddrMask->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_IpAddrMask() {
    return m_property_IpAddrMask;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setIpAddrStart(std::string value) {
    m_property_IpAddrStart->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::IpAddrStart() {
    return m_property_IpAddrStart->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_IpAddrStart() {
    return m_property_IpAddrStart;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setIpAddrEnd(std::string value) {
    m_property_IpAddrEnd->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::IpAddrEnd() {
    return m_property_IpAddrEnd->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_IpAddrEnd() {
    return m_property_IpAddrEnd;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pCliProbe(std::string value) {
    m_property_P2pCliProbe->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pCliProbe() {
    return m_property_P2pCliProbe->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pCliProbe() {
    return m_property_P2pCliProbe;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pDeviceRandomMacAddr(std::string value) {
    m_property_P2pDeviceRandomMacAddr->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pDeviceRandomMacAddr() {
    return m_property_P2pDeviceRandomMacAddr->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pDeviceRandomMacAddr() {
    return m_property_P2pDeviceRandomMacAddr;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pDevicePersistentMacAddr(std::string value) {
    m_property_P2pDevicePersistentMacAddr->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pDevicePersistentMacAddr() {
    return m_property_P2pDevicePersistentMacAddr->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pDevicePersistentMacAddr() {
    return m_property_P2pDevicePersistentMacAddr;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pInterfaceRandomMacAddr(std::string value) {
    m_property_P2pInterfaceRandomMacAddr->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pInterfaceRandomMacAddr() {
    return m_property_P2pInterfaceRandomMacAddr->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pInterfaceRandomMacAddr() {
    return m_property_P2pInterfaceRandomMacAddr;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBssMaxCount(std::string value) {
    m_property_BssMaxCount->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::BssMaxCount() {
    return m_property_BssMaxCount->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BssMaxCount() {
    return m_property_BssMaxCount;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFilterSsids(std::string value) {
    m_property_FilterSsids->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FilterSsids() {
    return m_property_FilterSsids->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FilterSsids() {
    return m_property_FilterSsids;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFilterRssi(std::string value) {
    m_property_FilterRssi->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FilterRssi() {
    return m_property_FilterRssi->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FilterRssi() {
    return m_property_FilterRssi;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setMaxNumSta(std::string value) {
    m_property_MaxNumSta->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::MaxNumSta() {
    return m_property_MaxNumSta->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_MaxNumSta() {
    return m_property_MaxNumSta;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setApIsolate(std::string value) {
    m_property_ApIsolate->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ApIsolate() {
    return m_property_ApIsolate->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ApIsolate() {
    return m_property_ApIsolate;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDisassocLowAck(std::string value) {
    m_property_DisassocLowAck->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DisassocLowAck() {
    return m_property_DisassocLowAck->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DisassocLowAck() {
    return m_property_DisassocLowAck;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setHs20(std::string value) {
    m_property_Hs20->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Hs20() {
    return m_property_Hs20->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Hs20() {
    return m_property_Hs20;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setInterworking(std::string value) {
    m_property_Interworking->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Interworking() {
    return m_property_Interworking->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Interworking() {
    return m_property_Interworking;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setHessid(std::string value) {
    m_property_Hessid->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Hessid() {
    return m_property_Hessid->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Hessid() {
    return m_property_Hessid;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setAccessNetworkType(std::string value) {
    m_property_AccessNetworkType->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::AccessNetworkType() {
    return m_property_AccessNetworkType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_AccessNetworkType() {
    return m_property_AccessNetworkType;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGoInterworking(std::string value) {
    m_property_GoInterworking->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GoInterworking() {
    return m_property_GoInterworking->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GoInterworking() {
    return m_property_GoInterworking;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGoAccessNetworkType(std::string value) {
    m_property_GoAccessNetworkType->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GoAccessNetworkType() {
    return m_property_GoAccessNetworkType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GoAccessNetworkType() {
    return m_property_GoAccessNetworkType;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGoInternet(std::string value) {
    m_property_GoInternet->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GoInternet() {
    return m_property_GoInternet->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GoInternet() {
    return m_property_GoInternet;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGoVenueGroup(std::string value) {
    m_property_GoVenueGroup->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GoVenueGroup() {
    return m_property_GoVenueGroup->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GoVenueGroup() {
    return m_property_GoVenueGroup;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGoVenueType(std::string value) {
    m_property_GoVenueType->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GoVenueType() {
    return m_property_GoVenueType->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GoVenueType() {
    return m_property_GoVenueType;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPbcInM1(std::string value) {
    m_property_PbcInM1->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PbcInM1() {
    return m_property_PbcInM1->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PbcInM1() {
    return m_property_PbcInM1;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setAutoscan(std::string value) {
    m_property_Autoscan->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Autoscan() {
    return m_property_Autoscan->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Autoscan() {
    return m_property_Autoscan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsNfcDevPwId(std::string value) {
    m_property_WpsNfcDevPwId->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsNfcDevPwId() {
    return m_property_WpsNfcDevPwId->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsNfcDevPwId() {
    return m_property_WpsNfcDevPwId;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsNfcDhPubkey(std::string value) {
    m_property_WpsNfcDhPubkey->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsNfcDhPubkey() {
    return m_property_WpsNfcDhPubkey->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsNfcDhPubkey() {
    return m_property_WpsNfcDhPubkey;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsNfcDhPrivkey(std::string value) {
    m_property_WpsNfcDhPrivkey->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsNfcDhPrivkey() {
    return m_property_WpsNfcDhPrivkey->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsNfcDhPrivkey() {
    return m_property_WpsNfcDhPrivkey;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsNfcDevPw(std::string value) {
    m_property_WpsNfcDevPw->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsNfcDevPw() {
    return m_property_WpsNfcDevPw->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsNfcDevPw() {
    return m_property_WpsNfcDevPw;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setExtPasswordBackend(std::string value) {
    m_property_ExtPasswordBackend->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ExtPasswordBackend() {
    return m_property_ExtPasswordBackend->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ExtPasswordBackend() {
    return m_property_ExtPasswordBackend;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pGoMaxInactivity(std::string value) {
    m_property_P2pGoMaxInactivity->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pGoMaxInactivity() {
    return m_property_P2pGoMaxInactivity->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pGoMaxInactivity() {
    return m_property_P2pGoMaxInactivity;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setAutoInterworking(std::string value) {
    m_property_AutoInterworking->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::AutoInterworking() {
    return m_property_AutoInterworking->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_AutoInterworking() {
    return m_property_AutoInterworking;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setOkc(std::string value) {
    m_property_Okc->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Okc() {
    return m_property_Okc->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Okc() {
    return m_property_Okc;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPmf(std::string value) {
    m_property_Pmf->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::Pmf() {
    return m_property_Pmf->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_Pmf() {
    return m_property_Pmf;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSaeGroups(std::string value) {
    m_property_SaeGroups->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::SaeGroups() {
    return m_property_SaeGroups->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SaeGroups() {
    return m_property_SaeGroups;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDtimPeriod(std::string value) {
    m_property_DtimPeriod->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DtimPeriod() {
    return m_property_DtimPeriod->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DtimPeriod() {
    return m_property_DtimPeriod;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setBeaconInt(std::string value) {
    m_property_BeaconInt->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::BeaconInt() {
    return m_property_BeaconInt->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_BeaconInt() {
    return m_property_BeaconInt;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setApVendorElements(std::string value) {
    m_property_ApVendorElements->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ApVendorElements() {
    return m_property_ApVendorElements->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ApVendorElements() {
    return m_property_ApVendorElements;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setIgnoreOldScanRes(std::string value) {
    m_property_IgnoreOldScanRes->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::IgnoreOldScanRes() {
    return m_property_IgnoreOldScanRes->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_IgnoreOldScanRes() {
    return m_property_IgnoreOldScanRes;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFreqList(std::string value) {
    m_property_FreqList->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FreqList() {
    return m_property_FreqList->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FreqList() {
    return m_property_FreqList;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setScanCurFreq(std::string value) {
    m_property_ScanCurFreq->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ScanCurFreq() {
    return m_property_ScanCurFreq->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ScanCurFreq() {
    return m_property_ScanCurFreq;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSchedScanInterval(std::string value) {
    m_property_SchedScanInterval->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::SchedScanInterval() {
    return m_property_SchedScanInterval->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SchedScanInterval() {
    return m_property_SchedScanInterval;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSchedScanStartDelay(std::string value) {
    m_property_SchedScanStartDelay->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::SchedScanStartDelay() {
    return m_property_SchedScanStartDelay->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SchedScanStartDelay() {
    return m_property_SchedScanStartDelay;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setTdlsExternalControl(std::string value) {
    m_property_TdlsExternalControl->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::TdlsExternalControl() {
    return m_property_TdlsExternalControl->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_TdlsExternalControl() {
    return m_property_TdlsExternalControl;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setOsuDir(std::string value) {
    m_property_OsuDir->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::OsuDir() {
    return m_property_OsuDir->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_OsuDir() {
    return m_property_OsuDir;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWowlanTriggers(std::string value) {
    m_property_WowlanTriggers->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WowlanTriggers() {
    return m_property_WowlanTriggers->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WowlanTriggers() {
    return m_property_WowlanTriggers;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setP2pSearchDelay(std::string value) {
    m_property_P2pSearchDelay->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::P2pSearchDelay() {
    return m_property_P2pSearchDelay->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_P2pSearchDelay() {
    return m_property_P2pSearchDelay;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setMacAddr(std::string value) {
    m_property_MacAddr->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::MacAddr() {
    return m_property_MacAddr->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_MacAddr() {
    return m_property_MacAddr;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setRandAddrLifetime(std::string value) {
    m_property_RandAddrLifetime->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::RandAddrLifetime() {
    return m_property_RandAddrLifetime->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_RandAddrLifetime() {
    return m_property_RandAddrLifetime;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPreassocMacAddr(std::string value) {
    m_property_PreassocMacAddr->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PreassocMacAddr() {
    return m_property_PreassocMacAddr->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PreassocMacAddr() {
    return m_property_PreassocMacAddr;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setKeyMgmtOffload(std::string value) {
    m_property_KeyMgmtOffload->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::KeyMgmtOffload() {
    return m_property_KeyMgmtOffload->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_KeyMgmtOffload() {
    return m_property_KeyMgmtOffload;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setPassiveScan(std::string value) {
    m_property_PassiveScan->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::PassiveScan() {
    return m_property_PassiveScan->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_PassiveScan() {
    return m_property_PassiveScan;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setReassocSameBssOptim(std::string value) {
    m_property_ReassocSameBssOptim->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ReassocSameBssOptim() {
    return m_property_ReassocSameBssOptim->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ReassocSameBssOptim() {
    return m_property_ReassocSameBssOptim;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpsPriority(std::string value) {
    m_property_WpsPriority->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpsPriority() {
    return m_property_WpsPriority->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpsPriority() {
    return m_property_WpsPriority;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFstGroupId(std::string value) {
    m_property_FstGroupId->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FstGroupId() {
    return m_property_FstGroupId->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FstGroupId() {
    return m_property_FstGroupId;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFstPriority(std::string value) {
    m_property_FstPriority->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FstPriority() {
    return m_property_FstPriority->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FstPriority() {
    return m_property_FstPriority;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFstLlt(std::string value) {
    m_property_FstLlt->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FstLlt() {
    return m_property_FstLlt->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FstLlt() {
    return m_property_FstLlt;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setCertInCb(std::string value) {
    m_property_CertInCb->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::CertInCb() {
    return m_property_CertInCb->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_CertInCb() {
    return m_property_CertInCb;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setWpaRscRelaxation(std::string value) {
    m_property_WpaRscRelaxation->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::WpaRscRelaxation() {
    return m_property_WpaRscRelaxation->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_WpaRscRelaxation() {
    return m_property_WpaRscRelaxation;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setSchedScanPlans(std::string value) {
    m_property_SchedScanPlans->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::SchedScanPlans() {
    return m_property_SchedScanPlans->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_SchedScanPlans() {
    return m_property_SchedScanPlans;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGasAddress3(std::string value) {
    m_property_GasAddress3->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GasAddress3() {
    return m_property_GasAddress3->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GasAddress3() {
    return m_property_GasAddress3;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFtmResponder(std::string value) {
    m_property_FtmResponder->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FtmResponder() {
    return m_property_FtmResponder->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FtmResponder() {
    return m_property_FtmResponder;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setFtmInitiator(std::string value) {
    m_property_FtmInitiator->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::FtmInitiator() {
    return m_property_FtmInitiator->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_FtmInitiator() {
    return m_property_FtmInitiator;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGasRandAddrLifetime(std::string value) {
    m_property_GasRandAddrLifetime->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GasRandAddrLifetime() {
    return m_property_GasRandAddrLifetime->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GasRandAddrLifetime() {
    return m_property_GasRandAddrLifetime;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setGasRandMacAddr(std::string value) {
    m_property_GasRandMacAddr->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::GasRandMacAddr() {
    return m_property_GasRandMacAddr->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_GasRandMacAddr() {
    return m_property_GasRandMacAddr;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setDppConfigProcessing(std::string value) {
    m_property_DppConfigProcessing->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::DppConfigProcessing() {
    return m_property_DppConfigProcessing->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_DppConfigProcessing() {
    return m_property_DppConfigProcessing;

}

void fi_w1_wpa_supplicant1_InterfaceProxy::setColocIntfReporting(std::string value) {
    m_property_ColocIntfReporting->set_value(value);

}

std::string fi_w1_wpa_supplicant1_InterfaceProxy::ColocIntfReporting() {
    return m_property_ColocIntfReporting->value();

}

std::shared_ptr<DBus::PropertyProxy < std::string>>

fi_w1_wpa_supplicant1_InterfaceProxy::getProperty_ColocIntfReporting() {
    return m_property_ColocIntfReporting;

}
