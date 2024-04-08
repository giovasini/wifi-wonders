#ifndef WI_FI_DIRECT_MANAGER_WPA_SUPPLICANT_MANAGER_H
#define WI_FI_DIRECT_MANAGER_WPA_SUPPLICANT_MANAGER_H

#include <WpaSupplicantProxy.h>
#include <WpaSupplicantInterfaceProxy.h>
#include <WpaSupplicantPeerProxy.h>
#include <WpaSupplicantGroupProxy.h>
#include <ostream>
#include <optional>
#include <map>
#include "P2PEvent.h"

using namespace std;
using namespace DBus;
using namespace WpaSupplicant;

#define GO_IP_ADDRESS "10.0.0.1"

struct Peer {
    friend ostream &operator<<(ostream &os, const Peer &peer) {
        os << peer.name << " (" << peer.mac_address << ")";
        return os;
    }

    Path path;
    string name;
    bool isWiFiWonders;
    bool isGO;
    string mac_address;
    shared_ptr<WpaSupplicantPeerProxy> peer_obj;
    shared_ptr<fi_w1_wpa_supplicant1_PeerProxy> peer_interface;
};

struct Group {
    friend ostream &operator<<(ostream &os, const Group &group) {
        os << group.ssid << " (Role:" << (group.GO ? "GO" : "client") << ")";
        return os;
    }

    Path path;
    Path interface_path;
    shared_ptr<WpaSupplicantInterfaceProxy> interface_obj;
    string interface_name;
    string ssid;
    bool GO;
    vector<Peer> connected_peers;
    shared_ptr<WpaSupplicantGroupProxy> group_obj;
    shared_ptr<fi_w1_wpa_supplicant1_GroupProxy> group_interface;
};

class WpaSupplicantManager {

    shared_ptr<StandaloneDispatcher> dispatcher;
    shared_ptr<Connection> conn;
    shared_ptr<WpaSupplicantProxy> wpa_supplicant_obj;
    shared_ptr<fi_w1_wpa_supplicant1Proxy> wpa_supplicant;

    shared_ptr<WpaSupplicantInterfaceProxy> wpa_supplicant_interface_obj;
    shared_ptr<fi_w1_wpa_supplicant1_InterfaceProxy> wpa_supplicant_interface;
    shared_ptr<fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy> p2p_interface;
    shared_ptr<fi_w1_wpa_supplicant1_Interface_WPSProxy> wps_interface;

    function<void(P2PEvent, std::map<P2PEventParamName, std::string>)> signal_proxy;
    string conf_dir;

    map<Path, Peer> peers;
    optional<Group> group;

    // Callbacks
    void onFindStopped();

    void onDeviceFound(const Path &path);

    void onDeviceLost(const Path &path);

    void onGroupStarted(const map<std::string, DBus::Variant> &properties);

//    void onP2PGONegReq(const Path &path, uint16_t dev_passwd_id, uint8_t device_go_intent);

//    void onP2PGONegSuccess(const map<std::string, DBus::Variant> &properties);

//    void onP2PGONegFailure(const map<std::string, DBus::Variant> &properties);

    void onGroupFinished(const map<std::string, DBus::Variant> &properties);

    void onGroupFormationFailure(const string &reason);

//    void onInvitationReceived(const map<std::string, DBus::Variant> &properties);

    void onProvDiscReq(const Path &peer_object);

    void add_peer(const Path &path);

    void remove_peer(const Path &path);

    void add_group(const Path &path, const Path &interface_path, const string &role);

    void remove_group(const Path &path);

    void remove_client_path(const Path &path);

    void onPeerJoined(const Path &path);

    void onPeerDisconnected(const Path &path);

public:
    explicit WpaSupplicantManager(const string &interface_name);

    explicit WpaSupplicantManager(const string &interface_name, const string &conf_dir, const function<void(P2PEvent p2p_event, std::map<P2PEventParamName,std::string> data)>& signal_proxy);

    static bool hasP2PCapabilities(const string &interface_name);

    [[nodiscard]] const map<Path, Peer> &getPeers() const;

    void start_p2p_find(int timeout = 30);

    void stop_p2p_find();

    void p2p_flush();

    void start_p2p_group();

    void remove_p2p_group();

    void connect_to_peer(const Path &path);

    void connect_to_mac(const string &mac_address);

    void remove_client(const string &mac_address);
};


#endif //WI_FI_DIRECT_MANAGER_WPA_SUPPLICANT_MANAGER_H
