#include <iostream>
#include <WpaSupplicantProxy.h>
#include <WpaSupplicantInterfaceProxy.h>
#include <csignal>
#include "utils.hpp"
#include "wpa_supplicant_manager.h"

using namespace std;
using namespace DBus;
using namespace WpaSupplicant;

void interrupt_handler(int signum) {
    netReset();
    signal(signum, SIG_DFL);
    raise(signum);
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "0. Exit\n";
    cout << "1. Start Group\n";
    cout << "2. Start Find\n";
    cout << "3. Connect\n";
    cout << "4. Delete group\n";
}

int main() {

    if (!isRunningWithPrivileges()) {
        cout << "Please run as root\n";
        return 1;
    }

    std::signal(SIGINT, interrupt_handler);
    std::signal(SIGABRT, interrupt_handler);
    std::signal(SIGTERM, interrupt_handler);

    netStop();

    auto filename = "wpa_supplicant.conf";
    if (!writeWpaSupplicantConf(filename)) {
        return 1;
    }

    string interface_name = getWirelessInterfaceName();
    if (interface_name.empty()) {
        cerr << "No wireless interface found." << endl;
        netReset();
        return 1;
    }
    cout << "Wireless interface: " << interface_name << endl;

    startWpaSupplicant(filename, interface_name);

    auto dispatcher = DBus::StandaloneDispatcher::create();
    auto conn = dispatcher->create_connection(BusType::SYSTEM);
    auto wpa_supplicant_obj = WpaSupplicantProxy::create(conn);
    auto wpa_supplicant = wpa_supplicant_obj->getfi_w1_wpa_supplicant1Interface();

    auto interface_path = wpa_supplicant->GetInterface(interface_name);
    cout << "Interface path: " << interface_path << endl;

    auto wpa_supplicant_interface_obj = WpaSupplicantInterfaceProxy::create(conn, interface_path);
    auto wpa_supplicant_interface = wpa_supplicant_interface_obj->getfi_w1_wpa_supplicant1_InterfaceInterface();

//    Issue #128 GitHub -> resolved
    auto capabilities = wpa_supplicant_interface->m_property_Capabilities->value();
    auto modes = capabilities.at("Modes").to_vector<string>();
    // error if capabilities does not include 'p2p'
    if (find(modes.begin(), modes.end(), "p2p") == modes.end()) {
        cerr << "No p2p capabilities." << endl;
        netReset();
        return 1;
    }

    WpaSupplicantManager wpa_supplicant_manager(interface_name);

    int choice;

    do {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            choice = -1;
            cin.clear(); // Clear the error flag
            cin.ignore(); // Discard invalid input
            cout << "Invalid input." << endl;
            continue;
        }

        switch (choice) {
            case 0:
                cout << "Exiting...\n";
                break;
            case 1:
                cout << "*START GROUP*\n";
                wpa_supplicant_manager.start_p2p_group();
                break;
            case 2:
                cout << "*START FIND*\n";
                wpa_supplicant_manager.start_p2p_find();
                break;
            case 3:
                cout << "*CONNECT*\n";
                wpa_supplicant_manager.stop_p2p_find();
                {
                    auto peers = wpa_supplicant_manager.getPeers();
                    int peer_number = 0;
                    for (const auto &peer: peers) {
                        cout << ++peer_number << ". " << peer.second << endl;
                    }
                    cout << "Select peer: ";
                    cin >> peer_number;
                    if (cin.fail()) {
                        peer_number = 0;
                        cin.clear(); // Clear the error flag
                        cin.ignore(); // Discard invalid input
                        cout << "Invalid input." << endl;
                        break;
                    } else if (peer_number < 1 || peer_number > peers.size()) {
                        cout << "Invalid peer number.\n";
                    }

                    auto it = peers.begin();
                    advance(it, peer_number - 1);
                    wpa_supplicant_manager.connect_to_peer(it->first);
                }
                break;
            case 4:
                cout << "*REMOVE GROUP*\n";
                wpa_supplicant_manager.remove_p2p_group();
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    netReset();

    return 0;
}
