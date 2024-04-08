#ifndef FI_WI_WPA_SUPPLICANT__INTERFACEPROXY_H
#define FI_WI_WPA_SUPPLICANT__INTERFACEPROXY_H

#include <dbus-cxx.h>
#include <memory>
#include <cstdint>
#include <string>

namespace WpaSupplicant {
    class fi_w1_wpa_supplicant1_InterfaceProxy
            : public DBus::InterfaceProxy {
    protected:
        fi_w1_wpa_supplicant1_InterfaceProxy(std::string name);

    public:
        static std::shared_ptr<WpaSupplicant::fi_w1_wpa_supplicant1_InterfaceProxy>
        create(std::string name = "fi.w1.wpa_supplicant1.Interface");

        void Scan(std::map<std::string, DBus::Variant> args);

        std::map<std::string, DBus::Variant> SignalPoll();

        void Disconnect();

        DBus::Path AddNetwork(std::map<std::string, DBus::Variant> args);

        void Reassociate();

        void Reattach();

        void Reconnect();

        void RemoveNetwork(DBus::Path path);

        void RemoveAllNetworks();

        void SelectNetwork(DBus::Path path);

        void NetworkReply(DBus::Path path, std::string field, std::string value);

        void AddBlob(std::string name, std::vector<uint8_t> data);

        std::vector<uint8_t> GetBlob(std::string name);

        void RemoveBlob(std::string name);

        void SetPKCS11EngineAndModulePath(std::string pkcs11_engine_path, std::string pkcs11_module_path);

        void FlushBSS(uint32_t age);

        void SubscribeProbeReq();

        void UnsubscribeProbeReq();

        void EAPLogoff();

        void EAPLogon();

        void AutoScan(std::string arg);

        void TDLSDiscover(std::string peer_address);

        void TDLSSetup(std::string peer_address);

        std::string TDLSStatus(std::string peer_address);

        void TDLSTeardown(std::string peer_address);

        void TDLSChannelSwitch(std::map<std::string, DBus::Variant> args);

        void TDLSCancelChannelSwitch(std::string peer_address);

        void VendorElemAdd(int32_t frame_id, std::vector<uint8_t> ielems);

        std::vector<uint8_t> VendorElemGet(int32_t frame_id);

        void VendorElemRem(int32_t frame_id, std::vector<uint8_t> ielems);

        void SaveConfig();

        void AbortScan();

        std::shared_ptr<DBus::SignalProxy<void(bool)>> signal_ScanDone();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path, std::map<std::string, DBus::Variant>)>> signal_BSSAdded();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> signal_BSSRemoved();

        std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_BlobAdded();

        std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_BlobRemoved();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path, std::map<std::string, DBus::Variant>)>>
        signal_NetworkAdded();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> signal_NetworkRemoved();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> signal_NetworkSelected();

        std::shared_ptr<DBus::SignalProxy<void(std::map<std::string, DBus::Variant>)>> signal_PropertiesChanged();

        std::shared_ptr<DBus::SignalProxy<void(std::map<std::string, DBus::Variant>)>> signal_ProbeRequest();

        std::shared_ptr<DBus::SignalProxy<void(std::map<std::string, DBus::Variant>)>> signal_Certification();

        std::shared_ptr<DBus::SignalProxy<void(std::string, std::string)>> signal_EAP();

        std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_StaAuthorized();

        std::shared_ptr<DBus::SignalProxy<void(std::string)>> signal_StaDeauthorized();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path, std::map<std::string, DBus::Variant>)>>
        signal_StationAdded();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> signal_StationRemoved();

        std::shared_ptr<DBus::SignalProxy<void(DBus::Path, std::string, std::string)>> signal_NetworkRequest();

    private:
        void setCapabilities(std::map<std::string, DBus::Variant> value);

        std::map<std::string, DBus::Variant> Capabilities();

        std::shared_ptr<DBus::PropertyProxy<std::map<std::string, DBus::Variant>>>

        getProperty_Capabilities();

        void setState(std::string value);

        std::string State();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_State();

        void setScanning(bool value);

        bool Scanning();

        std::shared_ptr<DBus::PropertyProxy<bool>> getProperty_Scanning();

        void setApScan(uint32_t value);

        uint32_t ApScan();

        std::shared_ptr<DBus::PropertyProxy<uint32_t>> getProperty_ApScan();

        void setBSSExpireAge(uint32_t value);

        uint32_t BSSExpireAge();

        std::shared_ptr<DBus::PropertyProxy<uint32_t>> getProperty_BSSExpireAge();

        void setBSSExpireCount(uint32_t value);

        uint32_t BSSExpireCount();

        std::shared_ptr<DBus::PropertyProxy<uint32_t>> getProperty_BSSExpireCount();

        void setCountry(std::string value);

        std::string Country();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Country();

        void setIfname(std::string value);

        std::string Ifname();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Ifname();

        void setDriver(std::string value);

        std::string Driver();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Driver();

        void setBridgeIfname(std::string value);

        std::string BridgeIfname();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_BridgeIfname();

        void setConfigFile(std::string value);

        std::string ConfigFile();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ConfigFile();

        void setCurrentBSS(DBus::Path value);

        DBus::Path CurrentBSS();

        std::shared_ptr<DBus::PropertyProxy<DBus::Path>> getProperty_CurrentBSS();

        void setCurrentNetwork(DBus::Path value);

        DBus::Path CurrentNetwork();

        std::shared_ptr<DBus::PropertyProxy<DBus::Path>> getProperty_CurrentNetwork();

        void setCurrentAuthMode(std::string value);

        std::string CurrentAuthMode();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_CurrentAuthMode();

        void setBlobs(std::map<std::string, std::vector<uint8_t>> value);

        std::map<std::string, std::vector<uint8_t>> Blobs();

        std::shared_ptr<DBus::PropertyProxy<std::map<std::string, std::vector<uint8_t>>>> getProperty_Blobs();

        void setBSSs(std::vector<DBus::Path> value);

        std::vector<DBus::Path> BSSs();

        std::shared_ptr<DBus::PropertyProxy<std::vector<DBus::Path>>>

        getProperty_BSSs();

        void setNetworks(std::vector<DBus::Path> value);

        std::vector<DBus::Path> Networks();

        std::shared_ptr<DBus::PropertyProxy<std::vector<DBus::Path>>>

        getProperty_Networks();

        void setFastReauth(bool value);

        bool FastReauth();

        std::shared_ptr<DBus::PropertyProxy<bool>> getProperty_FastReauth();

        void setScanInterval(int32_t value);

        int32_t ScanInterval();

        std::shared_ptr<DBus::PropertyProxy<int32_t>> getProperty_ScanInterval();

        void setPKCS11EnginePath(std::string value);

        std::string PKCS11EnginePath();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PKCS11EnginePath();

        void setPKCS11ModulePath(std::string value);

        std::string PKCS11ModulePath();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PKCS11ModulePath();

        void setDisconnectReason(int32_t value);

        int32_t DisconnectReason();

        std::shared_ptr<DBus::PropertyProxy<int32_t>> getProperty_DisconnectReason();

        void setAuthStatusCode(int32_t value);

        int32_t AuthStatusCode();

        std::shared_ptr<DBus::PropertyProxy<int32_t>> getProperty_AuthStatusCode();

        void setAssocStatusCode(int32_t value);

        int32_t AssocStatusCode();

        std::shared_ptr<DBus::PropertyProxy<int32_t>> getProperty_AssocStatusCode();

        void setRoamTime(uint32_t value);

        uint32_t RoamTime();

        std::shared_ptr<DBus::PropertyProxy<uint32_t>> getProperty_RoamTime();

        void setRoamComplete(bool value);

        bool RoamComplete();

        std::shared_ptr<DBus::PropertyProxy<bool>> getProperty_RoamComplete();

        void setSessionLength(uint32_t value);

        uint32_t SessionLength();

        std::shared_ptr<DBus::PropertyProxy<uint32_t>> getProperty_SessionLength();

        void setBSSTMStatus(uint32_t value);

        uint32_t BSSTMStatus();

        std::shared_ptr<DBus::PropertyProxy<uint32_t>> getProperty_BSSTMStatus();

        void setStations(std::vector<DBus::Path> value);

        std::vector<DBus::Path> Stations();

        std::shared_ptr<DBus::PropertyProxy<std::vector<DBus::Path>>>

        getProperty_Stations();

        void setCtrlInterface(std::string value);

        std::string CtrlInterface();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_CtrlInterface();

        void setCtrlInterfaceGroup(std::string value);

        std::string CtrlInterfaceGroup();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_CtrlInterfaceGroup();

        void setEapolVersion(std::string value);

        std::string EapolVersion();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_EapolVersion();

        void setBgscan(std::string value);

        std::string Bgscan();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Bgscan();

        void setDisableScanOffload(std::string value);

        std::string DisableScanOffload();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DisableScanOffload();

        void setOpenscEnginePath(std::string value);

        std::string OpenscEnginePath();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_OpenscEnginePath();

        void setOpensslCiphers(std::string value);

        std::string OpensslCiphers();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_OpensslCiphers();

        void setPcscReader(std::string value);

        std::string PcscReader();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PcscReader();

        void setPcscPin(std::string value);

        std::string PcscPin();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PcscPin();

        void setExternalSim(std::string value);

        std::string ExternalSim();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ExternalSim();

        void setDriverParam(std::string value);

        std::string DriverParam();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DriverParam();

        void setDot11RSNAConfigPMKLifetime(std::string value);

        std::string Dot11RSNAConfigPMKLifetime();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Dot11RSNAConfigPMKLifetime();

        void setDot11RSNAConfigPMKReauthThreshold(std::string value);

        std::string Dot11RSNAConfigPMKReauthThreshold();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Dot11RSNAConfigPMKReauthThreshold();

        void setDot11RSNAConfigSATimeout(std::string value);

        std::string Dot11RSNAConfigSATimeout();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Dot11RSNAConfigSATimeout();

        void setUpdateConfig(std::string value);

        std::string UpdateConfig();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_UpdateConfig();

        void setUuid(std::string value);

        std::string Uuid();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Uuid();

        void setAutoUuid(std::string value);

        std::string AutoUuid();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_AutoUuid();

        void setDeviceName(std::string value);

        std::string DeviceName();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DeviceName();

        void setManufacturer(std::string value);

        std::string Manufacturer();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Manufacturer();

        void setModelName(std::string value);

        std::string ModelName();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ModelName();

        void setModelNumber(std::string value);

        std::string ModelNumber();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ModelNumber();

        void setSerialNumber(std::string value);

        std::string SerialNumber();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_SerialNumber();

        void setDeviceType(std::string value);

        std::string DeviceType();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DeviceType();

        void setOsVersion(std::string value);

        std::string OsVersion();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_OsVersion();

        void setConfigMethods(std::string value);

        std::string ConfigMethods();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ConfigMethods();

        void setWpsCredProcessing(std::string value);

        std::string WpsCredProcessing();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsCredProcessing();

        void setWpsCredAddSae(std::string value);

        std::string WpsCredAddSae();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsCredAddSae();

        void setWpsVendorExtM1(std::string value);

        std::string WpsVendorExtM1();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsVendorExtM1();

        void setSecDeviceType(std::string value);

        std::string SecDeviceType();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_SecDeviceType();

        void setP2pListenRegClass(std::string value);

        std::string P2pListenRegClass();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pListenRegClass();

        void setP2pListenChannel(std::string value);

        std::string P2pListenChannel();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pListenChannel();

        void setP2pOperRegClass(std::string value);

        std::string P2pOperRegClass();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pOperRegClass();

        void setP2pOperChannel(std::string value);

        std::string P2pOperChannel();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pOperChannel();

        void setP2pGoIntent(std::string value);

        std::string P2pGoIntent();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoIntent();

        void setP2pSsidPostfix(std::string value);

        std::string P2pSsidPostfix();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pSsidPostfix();

        void setPersistentReconnect(std::string value);

        std::string PersistentReconnect();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PersistentReconnect();

        void setP2pIntraBss(std::string value);

        std::string P2pIntraBss();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pIntraBss();

        void setP2pGroupIdle(std::string value);

        std::string P2pGroupIdle();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGroupIdle();

        void setP2pGoFreqChangePolicy(std::string value);

        std::string P2pGoFreqChangePolicy();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoFreqChangePolicy();

        void setP2pPassphraseLen(std::string value);

        std::string P2pPassphraseLen();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pPassphraseLen();

        void setP2pPrefChan(std::string value);

        std::string P2pPrefChan();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pPrefChan();

        void setP2pNoGoFreq(std::string value);

        std::string P2pNoGoFreq();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pNoGoFreq();

        void setP2pAddCliChan(std::string value);

        std::string P2pAddCliChan();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pAddCliChan();

        void setP2pOptimizeListenChan(std::string value);

        std::string P2pOptimizeListenChan();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pOptimizeListenChan();

        void setP2pGoHt40(std::string value);

        std::string P2pGoHt40();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoHt40();

        void setP2pGoVht(std::string value);

        std::string P2pGoVht();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoVht();

        void setP2pGoHe(std::string value);

        std::string P2pGoHe();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoHe();

        void setP2pDisabled(std::string value);

        std::string P2pDisabled();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pDisabled();

        void setP2pGoCtwindow(std::string value);

        std::string P2pGoCtwindow();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoCtwindow();

        void setP2pNoGroupIface(std::string value);

        std::string P2pNoGroupIface();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pNoGroupIface();

        void setP2pIgnoreSharedFreq(std::string value);

        std::string P2pIgnoreSharedFreq();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pIgnoreSharedFreq();

        void setIpAddrGo(std::string value);

        std::string IpAddrGo();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_IpAddrGo();

        void setIpAddrMask(std::string value);

        std::string IpAddrMask();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_IpAddrMask();

        void setIpAddrStart(std::string value);

        std::string IpAddrStart();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_IpAddrStart();

        void setIpAddrEnd(std::string value);

        std::string IpAddrEnd();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_IpAddrEnd();

        void setP2pCliProbe(std::string value);

        std::string P2pCliProbe();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pCliProbe();

        void setP2pDeviceRandomMacAddr(std::string value);

        std::string P2pDeviceRandomMacAddr();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pDeviceRandomMacAddr();

        void setP2pDevicePersistentMacAddr(std::string value);

        std::string P2pDevicePersistentMacAddr();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pDevicePersistentMacAddr();

        void setP2pInterfaceRandomMacAddr(std::string value);

        std::string P2pInterfaceRandomMacAddr();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pInterfaceRandomMacAddr();

        void setBssMaxCount(std::string value);

        std::string BssMaxCount();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_BssMaxCount();

        void setFilterSsids(std::string value);

        std::string FilterSsids();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FilterSsids();

        void setFilterRssi(std::string value);

        std::string FilterRssi();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FilterRssi();

        void setMaxNumSta(std::string value);

        std::string MaxNumSta();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_MaxNumSta();

        void setApIsolate(std::string value);

        std::string ApIsolate();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ApIsolate();

        void setDisassocLowAck(std::string value);

        std::string DisassocLowAck();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DisassocLowAck();

        void setHs20(std::string value);

        std::string Hs20();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Hs20();

        void setInterworking(std::string value);

        std::string Interworking();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Interworking();

        void setHessid(std::string value);

        std::string Hessid();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Hessid();

        void setAccessNetworkType(std::string value);

        std::string AccessNetworkType();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_AccessNetworkType();

        void setGoInterworking(std::string value);

        std::string GoInterworking();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GoInterworking();

        void setGoAccessNetworkType(std::string value);

        std::string GoAccessNetworkType();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GoAccessNetworkType();

        void setGoInternet(std::string value);

        std::string GoInternet();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GoInternet();

        void setGoVenueGroup(std::string value);

        std::string GoVenueGroup();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GoVenueGroup();

        void setGoVenueType(std::string value);

        std::string GoVenueType();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GoVenueType();

        void setPbcInM1(std::string value);

        std::string PbcInM1();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PbcInM1();

        void setAutoscan(std::string value);

        std::string Autoscan();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Autoscan();

        void setWpsNfcDevPwId(std::string value);

        std::string WpsNfcDevPwId();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsNfcDevPwId();

        void setWpsNfcDhPubkey(std::string value);

        std::string WpsNfcDhPubkey();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsNfcDhPubkey();

        void setWpsNfcDhPrivkey(std::string value);

        std::string WpsNfcDhPrivkey();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsNfcDhPrivkey();

        void setWpsNfcDevPw(std::string value);

        std::string WpsNfcDevPw();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsNfcDevPw();

        void setExtPasswordBackend(std::string value);

        std::string ExtPasswordBackend();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ExtPasswordBackend();

        void setP2pGoMaxInactivity(std::string value);

        std::string P2pGoMaxInactivity();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pGoMaxInactivity();

        void setAutoInterworking(std::string value);

        std::string AutoInterworking();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_AutoInterworking();

        void setOkc(std::string value);

        std::string Okc();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Okc();

        void setPmf(std::string value);

        std::string Pmf();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_Pmf();

        void setSaeGroups(std::string value);

        std::string SaeGroups();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_SaeGroups();

        void setDtimPeriod(std::string value);

        std::string DtimPeriod();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DtimPeriod();

        void setBeaconInt(std::string value);

        std::string BeaconInt();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_BeaconInt();

        void setApVendorElements(std::string value);

        std::string ApVendorElements();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ApVendorElements();

        void setIgnoreOldScanRes(std::string value);

        std::string IgnoreOldScanRes();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_IgnoreOldScanRes();

        void setFreqList(std::string value);

        std::string FreqList();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FreqList();

        void setScanCurFreq(std::string value);

        std::string ScanCurFreq();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ScanCurFreq();

        void setSchedScanInterval(std::string value);

        std::string SchedScanInterval();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_SchedScanInterval();

        void setSchedScanStartDelay(std::string value);

        std::string SchedScanStartDelay();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_SchedScanStartDelay();

        void setTdlsExternalControl(std::string value);

        std::string TdlsExternalControl();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_TdlsExternalControl();

        void setOsuDir(std::string value);

        std::string OsuDir();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_OsuDir();

        void setWowlanTriggers(std::string value);

        std::string WowlanTriggers();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WowlanTriggers();

        void setP2pSearchDelay(std::string value);

        std::string P2pSearchDelay();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_P2pSearchDelay();

        void setMacAddr(std::string value);

        std::string MacAddr();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_MacAddr();

        void setRandAddrLifetime(std::string value);

        std::string RandAddrLifetime();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_RandAddrLifetime();

        void setPreassocMacAddr(std::string value);

        std::string PreassocMacAddr();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PreassocMacAddr();

        void setKeyMgmtOffload(std::string value);

        std::string KeyMgmtOffload();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_KeyMgmtOffload();

        void setPassiveScan(std::string value);

        std::string PassiveScan();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_PassiveScan();

        void setReassocSameBssOptim(std::string value);

        std::string ReassocSameBssOptim();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ReassocSameBssOptim();

        void setWpsPriority(std::string value);

        std::string WpsPriority();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpsPriority();

        void setFstGroupId(std::string value);

        std::string FstGroupId();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FstGroupId();

        void setFstPriority(std::string value);

        std::string FstPriority();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FstPriority();

        void setFstLlt(std::string value);

        std::string FstLlt();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FstLlt();

        void setCertInCb(std::string value);

        std::string CertInCb();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_CertInCb();

        void setWpaRscRelaxation(std::string value);

        std::string WpaRscRelaxation();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_WpaRscRelaxation();

        void setSchedScanPlans(std::string value);

        std::string SchedScanPlans();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_SchedScanPlans();

        void setGasAddress3(std::string value);

        std::string GasAddress3();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GasAddress3();

        void setFtmResponder(std::string value);

        std::string FtmResponder();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FtmResponder();

        void setFtmInitiator(std::string value);

        std::string FtmInitiator();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_FtmInitiator();

        void setGasRandAddrLifetime(std::string value);

        std::string GasRandAddrLifetime();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GasRandAddrLifetime();

        void setGasRandMacAddr(std::string value);

        std::string GasRandMacAddr();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_GasRandMacAddr();

        void setDppConfigProcessing(std::string value);

        std::string DppConfigProcessing();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_DppConfigProcessing();

        void setColocIntfReporting(std::string value);

        std::string ColocIntfReporting();

        std::shared_ptr<DBus::PropertyProxy<std::string>> getProperty_ColocIntfReporting();

    public:
        std::shared_ptr<DBus::PropertyProxy<std::map<std::string, DBus::Variant>>> m_property_Capabilities;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_State;
        std::shared_ptr<DBus::PropertyProxy<bool>> m_property_Scanning;
        std::shared_ptr<DBus::PropertyProxy<uint32_t>> m_property_ApScan;
        std::shared_ptr<DBus::PropertyProxy<uint32_t>> m_property_BSSExpireAge;
        std::shared_ptr<DBus::PropertyProxy<uint32_t>> m_property_BSSExpireCount;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Country;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Ifname;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Driver;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_BridgeIfname;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ConfigFile;
        std::shared_ptr<DBus::PropertyProxy<DBus::Path>> m_property_CurrentBSS;
        std::shared_ptr<DBus::PropertyProxy<DBus::Path>> m_property_CurrentNetwork;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_CurrentAuthMode;
        std::shared_ptr<DBus::PropertyProxy<std::map<std::string, std::vector<uint8_t>>>> m_property_Blobs;
        std::shared_ptr<DBus::PropertyProxy<std::vector<DBus::Path>>> m_property_BSSs;
        std::shared_ptr<DBus::PropertyProxy<std::vector<DBus::Path>>> m_property_Networks;
        std::shared_ptr<DBus::PropertyProxy<bool>> m_property_FastReauth;
        std::shared_ptr<DBus::PropertyProxy<int32_t>> m_property_ScanInterval;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PKCS11EnginePath;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PKCS11ModulePath;
        std::shared_ptr<DBus::PropertyProxy<int32_t>> m_property_DisconnectReason;
        std::shared_ptr<DBus::PropertyProxy<int32_t>> m_property_AuthStatusCode;
        std::shared_ptr<DBus::PropertyProxy<int32_t>> m_property_AssocStatusCode;
        std::shared_ptr<DBus::PropertyProxy<uint32_t>> m_property_RoamTime;
        std::shared_ptr<DBus::PropertyProxy<bool>> m_property_RoamComplete;
        std::shared_ptr<DBus::PropertyProxy<uint32_t>> m_property_SessionLength;
        std::shared_ptr<DBus::PropertyProxy<uint32_t>> m_property_BSSTMStatus;
        std::shared_ptr<DBus::PropertyProxy<std::vector<DBus::Path>>> m_property_Stations;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_CtrlInterface;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_CtrlInterfaceGroup;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_EapolVersion;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Bgscan;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DisableScanOffload;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_OpenscEnginePath;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_OpensslCiphers;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PcscReader;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PcscPin;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ExternalSim;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DriverParam;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Dot11RSNAConfigPMKLifetime;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Dot11RSNAConfigPMKReauthThreshold;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Dot11RSNAConfigSATimeout;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_UpdateConfig;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Uuid;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_AutoUuid;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DeviceName;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Manufacturer;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ModelName;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ModelNumber;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_SerialNumber;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DeviceType;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_OsVersion;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ConfigMethods;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsCredProcessing;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsCredAddSae;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsVendorExtM1;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_SecDeviceType;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pListenRegClass;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pListenChannel;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pOperRegClass;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pOperChannel;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoIntent;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pSsidPostfix;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PersistentReconnect;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pIntraBss;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGroupIdle;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoFreqChangePolicy;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pPassphraseLen;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pPrefChan;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pNoGoFreq;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pAddCliChan;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pOptimizeListenChan;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoHt40;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoVht;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoHe;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pDisabled;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoCtwindow;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pNoGroupIface;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pIgnoreSharedFreq;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_IpAddrGo;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_IpAddrMask;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_IpAddrStart;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_IpAddrEnd;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pCliProbe;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pDeviceRandomMacAddr;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pDevicePersistentMacAddr;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pInterfaceRandomMacAddr;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_BssMaxCount;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FilterSsids;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FilterRssi;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_MaxNumSta;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ApIsolate;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DisassocLowAck;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Hs20;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Interworking;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Hessid;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_AccessNetworkType;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GoInterworking;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GoAccessNetworkType;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GoInternet;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GoVenueGroup;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GoVenueType;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PbcInM1;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Autoscan;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsNfcDevPwId;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsNfcDhPubkey;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsNfcDhPrivkey;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsNfcDevPw;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ExtPasswordBackend;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pGoMaxInactivity;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_AutoInterworking;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Okc;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_Pmf;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_SaeGroups;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DtimPeriod;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_BeaconInt;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ApVendorElements;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_IgnoreOldScanRes;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FreqList;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ScanCurFreq;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_SchedScanInterval;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_SchedScanStartDelay;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_TdlsExternalControl;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_OsuDir;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WowlanTriggers;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_P2pSearchDelay;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_MacAddr;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_RandAddrLifetime;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PreassocMacAddr;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_KeyMgmtOffload;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_PassiveScan;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ReassocSameBssOptim;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpsPriority;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FstGroupId;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FstPriority;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FstLlt;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_CertInCb;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_WpaRscRelaxation;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_SchedScanPlans;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GasAddress3;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FtmResponder;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_FtmInitiator;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GasRandAddrLifetime;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_GasRandMacAddr;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_DppConfigProcessing;
        std::shared_ptr<DBus::PropertyProxy<std::string>> m_property_ColocIntfReporting;
    protected:
        std::shared_ptr<DBus::MethodProxy<void(std::map<std::string, DBus::Variant>)>> m_method_Scan;
        std::shared_ptr<DBus::MethodProxy<std::map<std::string, DBus::Variant>()>> m_method_SignalPoll;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_Disconnect;
        std::shared_ptr<DBus::MethodProxy<DBus::Path(std::map<std::string, DBus::Variant>)>> m_method_AddNetwork;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_Reassociate;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_Reattach;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_Reconnect;
        std::shared_ptr<DBus::MethodProxy<void(DBus::Path)>> m_method_RemoveNetwork;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_RemoveAllNetworks;
        std::shared_ptr<DBus::MethodProxy<void(DBus::Path)>> m_method_SelectNetwork;
        std::shared_ptr<DBus::MethodProxy<void(DBus::Path, std::string, std::string)>> m_method_NetworkReply;
        std::shared_ptr<DBus::MethodProxy<void(std::string, std::vector<uint8_t>)>> m_method_AddBlob;
        std::shared_ptr<DBus::MethodProxy<std::vector<uint8_t>(std::string)>> m_method_GetBlob;
        std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_RemoveBlob;
        std::shared_ptr<DBus::MethodProxy<void(std::string, std::string)>> m_method_SetPKCS11EngineAndModulePath;
        std::shared_ptr<DBus::MethodProxy<void(uint32_t)>> m_method_FlushBSS;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_SubscribeProbeReq;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_UnsubscribeProbeReq;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_EAPLogoff;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_EAPLogon;
        std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_AutoScan;
        std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_TDLSDiscover;
        std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_TDLSSetup;
        std::shared_ptr<DBus::MethodProxy<std::string(std::string)>> m_method_TDLSStatus;
        std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_TDLSTeardown;
        std::shared_ptr<DBus::MethodProxy<void(std::map<std::string, DBus::Variant>)>> m_method_TDLSChannelSwitch;
        std::shared_ptr<DBus::MethodProxy<void(std::string)>> m_method_TDLSCancelChannelSwitch;
        std::shared_ptr<DBus::MethodProxy<void(int32_t, std::vector<uint8_t>)>> m_method_VendorElemAdd;
        std::shared_ptr<DBus::MethodProxy<std::vector<uint8_t>(int32_t)>> m_method_VendorElemGet;
        std::shared_ptr<DBus::MethodProxy<void(int32_t, std::vector<uint8_t>)>> m_method_VendorElemRem;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_SaveConfig;
        std::shared_ptr<DBus::MethodProxy<void()>> m_method_AbortScan;
        std::shared_ptr<DBus::SignalProxy<void(bool)>> m_signalproxy_ScanDone;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path,
                                               std::map<std::string, DBus::Variant>)>> m_signalproxy_BSSAdded;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> m_signalproxy_BSSRemoved;
        std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_BlobAdded;
        std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_BlobRemoved;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path,
                                               std::map<std::string, DBus::Variant>)>> m_signalproxy_NetworkAdded;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> m_signalproxy_NetworkRemoved;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> m_signalproxy_NetworkSelected;
        std::shared_ptr<DBus::SignalProxy<void(std::map<std::string, DBus::Variant>)>> m_signalproxy_PropertiesChanged;
        std::shared_ptr<DBus::SignalProxy<void(std::map<std::string, DBus::Variant>)>> m_signalproxy_ProbeRequest;
        std::shared_ptr<DBus::SignalProxy<void(std::map<std::string, DBus::Variant>)>> m_signalproxy_Certification;
        std::shared_ptr<DBus::SignalProxy<void(std::string, std::string)>> m_signalproxy_EAP;
        std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_StaAuthorized;
        std::shared_ptr<DBus::SignalProxy<void(std::string)>> m_signalproxy_StaDeauthorized;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path,
                                               std::map<std::string, DBus::Variant>)>> m_signalproxy_StationAdded;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path)>> m_signalproxy_StationRemoved;
        std::shared_ptr<DBus::SignalProxy<void(DBus::Path, std::string, std::string)>> m_signalproxy_NetworkRequest;
    };
} /* namespace WpaSupplicant */
#endif /* FI_WI_WPA_SUPPLICANT__INTERFACEPROXY_H */
