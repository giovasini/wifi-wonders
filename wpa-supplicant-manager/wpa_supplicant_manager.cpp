#include "wpa_supplicant_manager.h"
#include <iostream>
#include "utils.hpp"


WpaSupplicantManager::WpaSupplicantManager(const string &interface_name) {
    dispatcher = DBus::StandaloneDispatcher::create();
    conn = dispatcher->create_connection(BusType::SYSTEM);
    wpa_supplicant_obj = WpaSupplicantProxy::create(conn);                          // /fi/w1/wpa_supplicant1
    wpa_supplicant = wpa_supplicant_obj->getfi_w1_wpa_supplicant1Interface();       // fi.w1.wpa_supplicant1

    auto interface_path = wpa_supplicant->GetInterface(interface_name);             // object path

    wpa_supplicant_interface_obj = WpaSupplicantInterfaceProxy::create(conn, interface_path);                   // /fi/w1/wpa_supplicant1/Interfaces/0
    wpa_supplicant_interface = wpa_supplicant_interface_obj->getfi_w1_wpa_supplicant1_InterfaceInterface();     // fi.w1.wpa_supplicant1.Interface
    p2p_interface = wpa_supplicant_interface_obj->getfi_w1_wpa_supplicant1_Interface_P2PDeviceInterface();      // fi.w1.wpa_supplicant1.P2PDevice
    wps_interface = wpa_supplicant_interface_obj->getfi_w1_wpa_supplicant1_Interface_WPSInterface();            // fi.w1.wpa_supplicant1.WPS

    p2p_interface->signal_FindStopped()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onFindStopped));
    p2p_interface->signal_DeviceFound()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onDeviceFound));
    p2p_interface->signal_DeviceLost()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onDeviceLost));
    p2p_interface->signal_GroupStarted()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onGroupStarted));
//    p2p_interface->signal_GONegotiationRequest()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onP2PGONegReq));
//    p2p_interface->signal_GONegotiationSuccess()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onP2PGONegSuccess));
//    p2p_interface->signal_GONegotiationFailure()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onP2PGONegFailure));
    p2p_interface->signal_GroupFinished()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onGroupFinished));
    p2p_interface->signal_GroupFormationFailure()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onGroupFormationFailure));
//    p2p_interface->signal_InvitationReceived()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onInvitationReceived));
    p2p_interface->signal_ProvisionDiscoveryPBCRequest()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onProvDiscReq));
}

WpaSupplicantManager::WpaSupplicantManager(const string &interface_name,
                                           const string &conf_dir,
                                           const function<void(P2PEvent, std::map<P2PEventParamName, std::string>)>& signal_proxy)
                                           : WpaSupplicantManager(interface_name){
    this->conf_dir = conf_dir;
    this->signal_proxy = signal_proxy;
}

void WpaSupplicantManager::onFindStopped() {
    cout << "Find stopped." << endl;
    signal_proxy(P2PEvent::FIND_STOPPED, {});
}

void WpaSupplicantManager::add_peer(const Path &path) {
    Peer new_peer;
    new_peer.path = path;
    new_peer.peer_obj = WpaSupplicantPeerProxy::create(conn, path);
    new_peer.peer_interface = new_peer.peer_obj->getfi_w1_wpa_supplicant1_PeerInterface();
    new_peer.mac_address = macAddressToString(new_peer.peer_interface->m_property_DeviceAddress->value());
    new_peer.name = new_peer.peer_interface->m_property_DeviceName->value();
    new_peer.isWiFiWonders = new_peer.peer_interface->m_property_Manufacturer->value() == "WiFiWonders";
    // NB: This field is only for debugging purposes and must not be used to determine whether the peer happens to be operating a group as a GO at the moment.
    new_peer.isGO = new_peer.peer_interface->m_property_groupcapability->value() != 0;
    peers.insert(make_pair(path, new_peer));
    cout << "Peer added: " << new_peer << endl;
}

void WpaSupplicantManager::onDeviceFound(const Path &path) {
    cout << "Device found: " << path << endl;
    add_peer(path);
    if (peers.at(path).isWiFiWonders) {
        if(peers.at(path).isGO) {
            signal_proxy(P2PEvent::DEVICE_FOUND, {{P2PEventParamName::MAC_ADDRESS, peers.at(path).mac_address},
                                                  {P2PEventParamName::DEVICE_NAME, peers.at(path).name}});
        }
        else {
            cout << "WiFi Wonders device, but not GO" << endl;
        }
    }
    else {
        cout << "Not a WiFi Wonders device." << endl;
    }
}

void WpaSupplicantManager::remove_peer(const Path &path) {
    cout << "Deleting peer: " << peers.at(path) << endl;
    peers.erase(path);
}

void WpaSupplicantManager::onDeviceLost(const Path &path) {
    cout << "Device lost: " << path << endl;
    if (peers.at(path).isWiFiWonders) {
        if(peers.at(path).isGO) {
            signal_proxy(P2PEvent::DEVICE_LOST, {{P2PEventParamName::MAC_ADDRESS, peers.at(path).mac_address}});
        }
        else {
            cout << "WiFi Wonders device, but not GO" << endl;
        }
    }
    else {
        cout << "Not a WiFi Wonders device." << endl;
    }
    remove_peer(path);
}

void WpaSupplicantManager::start_p2p_find(int timeout) {
    map<string, Variant> args;
    if (timeout > 0)
        args["Timeout"] = timeout;

    p2p_interface->Find(args);
    signal_proxy(P2PEvent::FIND_STARTED, {});
}

void WpaSupplicantManager::start_p2p_group() {
    map<string, Variant> args;
    p2p_interface->GroupAdd(args);
}

void WpaSupplicantManager::onGroupStarted(const map<std::string, DBus::Variant> &properties) {
    cout << "Group added." << endl;
    for (auto &property: properties) {
        cout << " > " << property.first << ": " << property.second << endl;
    }
    add_group(properties.at("group_object").to_path(), properties.at("interface_object").to_path(), properties.at("role").to_string());
    if(group.has_value()) {
        if(group.value().GO) {
            // set ip_address & start dhcp server
            if(!setIpAddress(group.value().interface_name, GO_IP_ADDRESS)) {
                remove_p2p_group();
                return;
            }
            if(!startDhcpServer(conf_dir, group.value().interface_name)) {
                remove_p2p_group();
                return;
            }
        }
        else {
            // start dhcp client
            startDhcpClient(group.value().interface_name);
        }
    }
    signal_proxy(P2PEvent::GROUP_STARTED, {{P2PEventParamName::GROUP_NAME, group.value().ssid},
                                           {P2PEventParamName::GROUP_ROLE, group.value().GO ? "GO" : "client"}});
}

void WpaSupplicantManager::connect_to_peer(const Path &path) {
    map<string, Variant> args;
    // pass peer path as DBus object path
    args["peer"] = Variant(path); // need to create a Variant of type OBJECT_PATH
    args["wps_method"] = "pbc";
    args["join"] = true;

    // NB: This field is only for debugging purposes and must not be used to determine whether the peer happens to be operating a group as a GO at the moment.
    /*if(peers.at(path).peer_interface->m_property_groupcapability->value() != 0) {
        args["join"] = true;
    }*/

    auto gen_pin = p2p_interface->Connect(args);
    //cout << "Generated PIN: " << gen_pin << endl;
}

const map<Path, Peer> &WpaSupplicantManager::getPeers() const {
    return peers;
}

/*void WpaSupplicantManager::onP2PGONegReq(const Path &path, uint16_t dev_passwd_id, uint8_t device_go_intent) {
    cout << "GO Negotiation Request: " << endl;
    cout << " > Path: " << path << endl;
    cout << " > Dev Passwd ID: " << dev_passwd_id << endl;
    cout << " > Device GO Intent: " << device_go_intent << endl;
    connect_to_peer(path);
}*/

/*void WpaSupplicantManager::onP2PGONegSuccess(const map<std::string, DBus::Variant>& properties) {
    // print properties
    cout << "GO Negotiation Success: " << endl;
    for (auto &property: properties) {
        cout << " > " << property.first << ": " << property.second << endl;
    }
}*/

/*void WpaSupplicantManager::onP2PGONegFailure(const map<std::string, DBus::Variant>& properties) {
    // print properties
    cout << "GO Negotiation Failure: " << endl;
    for (auto &property: properties) {
        cout << " > " << property.first << ": " << property.second << endl;
    }
}*/

void WpaSupplicantManager::onGroupFinished(const map<std::string, DBus::Variant>& properties) {
    // print properties
    cout << "Group Finished: " << endl;
    for (auto &property: properties) {
        cout << " > " << property.first << ": " << property.second << endl;
    }
    signal_proxy(P2PEvent::GROUP_FINISHED, {{P2PEventParamName::GROUP_NAME, group.value().ssid},
                                            {P2PEventParamName::GROUP_ROLE, group.value().GO ? "GO" : "client"}});
    remove_group(properties.at("group_object").to_path());
}

void WpaSupplicantManager::onGroupFormationFailure(const string& reason) {
    cout << "Group Formation Failure: " << reason << endl;
    signal_proxy(P2PEvent::GROUP_FORMATION_FAILURE, {{P2PEventParamName::REASON, reason}});
}

/*void WpaSupplicantManager::onInvitationReceived(const map<std::string, DBus::Variant>& properties) {
    // print properties
    cout << "Invitation Received: " << endl;
    for (auto &property: properties) {
        cout << " > " << property.first << ": " << property.second << endl;
    }
}*/

void WpaSupplicantManager::stop_p2p_find() {
    p2p_interface->StopFind();
}

void WpaSupplicantManager::add_group(const Path &path, const Path &interface_path, const string &role) {
    group = Group();
    group->path = path;
    group->interface_path = interface_path;
    group->interface_obj = WpaSupplicantInterfaceProxy::create(conn, interface_path);

    group->interface_name = group->interface_obj->getfi_w1_wpa_supplicant1_InterfaceInterface()->m_property_Ifname->value();

    group->GO = role == "GO";
    group->group_obj = WpaSupplicantGroupProxy::create(conn, path);
    group->group_interface = group->group_obj->getfi_w1_wpa_supplicant1_GroupInterface();
    auto vec_ssid = group->group_interface->m_property_SSID->value();
    group->ssid = string(vec_ssid.begin(), vec_ssid.end()); // vector<uint8_t> to string

    group->group_interface->signal_PeerJoined()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onPeerJoined));
    group->group_interface->signal_PeerDisconnected()->connect(sigc::mem_fun(*this, &WpaSupplicantManager::onPeerDisconnected));
}

void WpaSupplicantManager::remove_group(const Path &path) {
    if(group.has_value()) {
        cout << "Deleting group: " << group.value() << endl;
        if(group.value().GO)
            stopDhcpServer();
        group.reset();
    }
    else
        cout << "No group to remove." << endl;
}

void WpaSupplicantManager::onPeerJoined(const Path &path) {
    cout << "Peer joined: " << path << endl;
    group->connected_peers.push_back(peers.at(path));
    signal_proxy(P2PEvent::PEER_JOINED, {{P2PEventParamName::MAC_ADDRESS, peers.at(path).mac_address},
                                         {P2PEventParamName::DEVICE_NAME, peers.at(path).name}});
}

void WpaSupplicantManager::onPeerDisconnected(const Path &path) {
    cout << "Peer disconnected: " << path << endl;

    for (int i=0; i<group->connected_peers.size(); i++) {
        if (group->connected_peers[i].path == path) {
            signal_proxy(P2PEvent::PEER_DISCONNECTED, {{P2PEventParamName::MAC_ADDRESS, group->connected_peers[i].mac_address}});
            group->connected_peers.erase(group->connected_peers.begin() + i);
            break;
        }
    }
}

void WpaSupplicantManager::remove_p2p_group() {
    if(group.has_value()) {
        group.value().interface_obj->getfi_w1_wpa_supplicant1_Interface_P2PDeviceInterface()->Disconnect();
    }
}

void WpaSupplicantManager::onProvDiscReq(const Path &peer_object) {
    auto peer = peers.at(peer_object);
    cout << "Provision Discovery Request: " << peer << endl;
    if (peer.isWiFiWonders) {
        map<string, Variant> args;
        args["Role"] = "enrollee";
        args["Type"] = "pbc";
        group.value().interface_obj->getfi_w1_wpa_supplicant1_Interface_WPSInterface()->Start(args);
    }
    else {
        cout << "Not a WiFi Wonders device." << endl;
    }
}

bool WpaSupplicantManager::hasP2PCapabilities(const string &interface_name) {
    auto dispatcher = DBus::StandaloneDispatcher::create();
    auto conn = dispatcher->create_connection(BusType::SYSTEM);

    auto interface_path = WpaSupplicantProxy::create(conn)->getfi_w1_wpa_supplicant1Interface()->GetInterface(interface_name);
    auto wpa_supplicant_interface = WpaSupplicantInterfaceProxy::create(conn, interface_path)->getfi_w1_wpa_supplicant1_InterfaceInterface();

    auto capabilities = wpa_supplicant_interface->m_property_Capabilities->value();
    auto modes = capabilities.at("Modes").to_vector<string>();
    // error if capabilities does not include 'p2p'
    if (find(modes.begin(), modes.end(), "p2p") == modes.end()) {
        cerr << "No p2p capabilities." << endl;
        return false;
    }
    return true;
}

void WpaSupplicantManager::connect_to_mac(const string &mac_address) {
    for (const auto &peer: peers) {
        if (peer.second.mac_address == mac_address) {
            connect_to_peer(peer.first);
            return;
        }
    }
    cerr << "No peer with MAC address " << mac_address << " found." << endl;
}

void WpaSupplicantManager::remove_client_path(const Path &path) {
    map<string, Variant> args;
    // pass peer path as DBus object path
    args["peer"] = Variant(path); // need to create a Variant of type OBJECT_PATH
    p2p_interface->RemoveClient(args);
}

void WpaSupplicantManager::remove_client(const string &mac_address) {
    for (const auto &peer: peers) {
        if (peer.second.mac_address == mac_address) {
            remove_client_path(peer.first);
            return;
        }
    }
    cerr << "No peer with MAC address " << mac_address << " found." << endl;
}

void WpaSupplicantManager::p2p_flush() {
    p2p_interface->Flush();
}