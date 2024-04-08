#ifndef WI_FI_DIRECT_MANAGER_UTILS_H
#define WI_FI_DIRECT_MANAGER_UTILS_H

#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include "unistd.h"

using namespace std;

static bool isRunningWithPrivileges() {
    if (geteuid() != 0)
        return false;
    else
        return true;
}

static void netStop() {
    cout << "Stopping network... ";
    system("sudo systemctl stop NetworkManager.service");
    system("sudo killall wpa_supplicant");
    sleep(1);
    cout << "Done." << endl;
}

static void netReset() {
    cout << "Resetting network... " << flush;
    system("sudo killall wpa_supplicant");
    system("sudo systemctl restart NetworkManager");
    sleep(1);
    cout << "Done." << endl;
}

static string getHostname() {
    char hostname[32] = "";
    if (gethostname(hostname, sizeof hostname) == 0) {
        return hostname;
    }
    return "P2P-DEVICE";
}

static bool writeWpaSupplicantConf(const string &filepath, const string &device_name) {
    cout << "Writing " << filepath << "... " << endl;

    // File content
    auto configFileContent = R"(
update_config=1
ctrl_interface=/var/run/wpa_supplicant
country=IT
device_name=)" + device_name + R"(
device_type=1-0050F204-1
manufacturer=WiFiWonders
config_methods=virtual_push_button
)";

    // Write to the file
    ofstream configFile(filepath);
    if (configFile.is_open()) {
        configFile << configFileContent;
        configFile.close();
        cout << "File written successfully." << endl;
    } else {
        cerr << "Unable to open file " << filepath << " for writing." << endl;
        return false;
    }
    return true;
}

static void startWpaSupplicant(const string &filepath, const string &interface_name) {
    cout << "Starting wpa_supplicant... " << flush;
    system(("wpa_supplicant -Dnl80211 -i" + interface_name + " -c" + filepath + " -B -u").c_str());
    sleep(3);
}

static string getWirelessInterfaceName() {
    for (const auto &entry: filesystem::directory_iterator("/sys/class/net")) {
        const string if_dir = entry.path();
        const string wireless_dir = if_dir + "/wireless";

        if (filesystem::is_directory(wireless_dir)) {
            return entry.path().filename();
        }
    }
    return "";
}

static string getMacAddress(const string &interface_name) {
    std::ifstream file("/sys/class/net/" + interface_name + "/address");
    std::string macAddress;
    if (file.is_open()) {
        std::getline(file, macAddress);
        file.close();
    }
    return macAddress;
}

static string macAddressToString(vector<uint8_t> macAddress) {
    if (macAddress.size() != 6) {
        return "Invalid MAC Address";
    }

    std::ostringstream oss;
    oss << std::hex << std::setfill('0');

    for (int i = 0; i < 6; ++i) {
        oss << std::setw(2) << static_cast<unsigned int>(macAddress[i]);
        if (i < 5) {
            oss << ":";
        }
    }

    return oss.str();
}

static string getIpAddress(const string &interface_name) {
    struct ifaddrs *ifAddrStruct = nullptr;
    if (getifaddrs(&ifAddrStruct) == -1) {
        std::cerr << "getifaddrs failed" << std::endl;
        return "";
    }

    for (struct ifaddrs *ifa = ifAddrStruct; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == nullptr) {
            continue;
        }

        // Check if the interface name matches
        if (interface_name == ifa->ifa_name && ifa->ifa_addr->sa_family == AF_INET) {
            auto *sa = (struct sockaddr_in *) ifa->ifa_addr;
            char ipAddress[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(sa->sin_addr), ipAddress, INET_ADDRSTRLEN);
            return ipAddress;
        }
    }

    freeifaddrs(ifAddrStruct);
    return "";
}

static bool setIpAddress(const string &interface_name, const string &ip_address) {

    string cmd = "ip addr add " + ip_address + "/24 dev " + interface_name;
    system(cmd.c_str());

    auto ip_set = getIpAddress(interface_name);
    if (ip_set == ip_address) {
        cout << "IP address set: " << ip_set << endl;
        return true;
    }
    return false;
}

static bool writeUdhcpdConf(const string &filepath, const string &interface_name) {
    cout << "Writing " << filepath << "... " << endl;

    auto configFileContent = R"(
start   10.0.0.2
end     10.0.0.254
interface )" + interface_name + R"(
option  subnet  255.255.255.0
option  router  10.0.0.1
option  domain  local
option  lease   864000
)";

    // Write to the file
    ofstream configFile(filepath);
    if (configFile.is_open()) {
        configFile << configFileContent;
        configFile.close();
        cout << "File written successfully." << endl;
    } else {
        cerr << "Unable to open file " << filepath << " for writing." << endl;
        return false;
    }
    return true;
}

static bool isUdhcpdRunning() {
    if (system("pgrep udhcpd > /dev/null 2>&1") == 0) {
        cout << "TEST DHCP -> running" << endl;
        return true;
    } else {
        cout << "TEST DHCP -> not running" << endl;
        return false;
    }
}

static bool startDhcpServer(const string &conf_dir, const string &interface_name) {

    string filepath = conf_dir + "udhcpd.conf";

    // NB: DHCP server needs to be started on the correct interface!
    writeUdhcpdConf(filepath, interface_name);

    cout << "Starting DHCP server... " << flush;
    string cmd = "udhcpd " + string(filepath);
    if (std::system(cmd.c_str()) != 0) {
        cerr << "Error starting DHCP server." << endl;
        return false;
    }
    sleep(1);
    if (!isUdhcpdRunning()) {
        cerr << "Error starting DHCP server." << endl;
        return false;
    }
    cout << "Done." << endl;
    return true;
}

static void stopDhcpServer() {
    cout << "Stopping DHCP server... " << flush;
    system("killall udhcpd");
    cout << "Done." << endl;
}

static bool startDhcpClient(const string &interface_name) {
    string cmd = "dhclient " + interface_name;
    if (std::system(cmd.c_str()) != 0) {
        cerr << "Error in dhclient call" << endl;
        return false;
    }
    sleep(1);
    cout << "IP address set: " << getIpAddress(interface_name) << endl;
    return true;
}

#endif //WI_FI_DIRECT_MANAGER_UTILS_H