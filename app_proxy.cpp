#include "app_proxy.h"

#include <csignal>
#include <QThread>

pid_t AppProxy::ffplay_pid = -1;

void AppProxy::interrupt_handler(int signum) {
    CastingService::getInstance().stop_recording();
    stopFFplay();

    netReset();
    std::signal(signum, SIG_DFL);
    raise(signum);
}

AppProxy::AppProxy(QObject *parent) : QObject(parent) {
    nmStopped = false;
    device_name = getHostname();
    interface_name = getWirelessInterfaceName();
    mac_address = getMacAddress(interface_name);
    confDir = getenv("HOME") + std::string("/.config/wifi_wonders/");
    if (!std::filesystem::exists(confDir)) {
        std::filesystem::create_directories(confDir);
    }
    wpaSupplicantConfPath = confDir + "wpa_supplicant.conf";
    casting_service = &CastingService::getInstance();

    QObject::connect(this, &AppProxy::groupFinished, this, &AppProxy::onGroupFinished);
}

AppProxy::~AppProxy() {
    stopCasting();
    stopFFplay();
    if (nmStopped) {
        netReset();
    }
}

void AppProxy::process_event(P2PEvent p2p_event, std::map<P2PEventParamName, std::string> args) {
    // print map
    switch (p2p_event) {
        case FIND_STARTED:
            emit findStarted();
            break;
        case FIND_STOPPED:
            emit findStopped();
            break;
        case DEVICE_FOUND:
            emit deviceFound(args[P2PEventParamName::MAC_ADDRESS].c_str(),
                             args[P2PEventParamName::DEVICE_NAME].c_str());
            break;
        case DEVICE_LOST:
            emit deviceLost(args[P2PEventParamName::MAC_ADDRESS].c_str());
            break;
        case GROUP_STARTED:
            emit groupStarted(args[P2PEventParamName::GROUP_NAME].c_str(), args[P2PEventParamName::GROUP_ROLE].c_str());
            break;
        case GROUP_FINISHED:
            emit groupFinished(args[P2PEventParamName::GROUP_NAME].c_str(),
                               args[P2PEventParamName::GROUP_ROLE].c_str());
            break;
        case GROUP_FORMATION_FAILURE:
            emit groupFormationFailure();
        case PEER_JOINED:
            emit peerJoined(args[P2PEventParamName::MAC_ADDRESS].c_str(), args[P2PEventParamName::DEVICE_NAME].c_str());
            break;
        case PEER_DISCONNECTED:
            emit peerDisconnected(args[P2PEventParamName::MAC_ADDRESS].c_str());
            break;
        case P2P_GO_NEGOTIATION_REQUEST:
            break;
        case P2P_GO_NEGOTIATION_SUCCESS:
            break;
        case P2P_GO_NEGOTIATION_FAILURE:
            break;
        case P2P_GROUP_FORMATION_FAILURE:
            break;
        case PROVISION_DISCOVERY_REQUEST:
            break;
    }
}

void AppProxy::setNmStopped(bool val) {
    if (val) {
        std::signal(SIGINT, interrupt_handler);
        std::signal(SIGABRT, interrupt_handler);
        std::signal(SIGTERM, interrupt_handler);
    } else {
        std::signal(SIGINT, SIG_DFL);
        std::signal(SIGABRT, SIG_DFL);
        std::signal(SIGTERM, SIG_DFL);
    }
    nmStopped = val;
}

void AppProxy::initialCheck() {
    if (!isRunningWithPrivileges()) {
        emit initialized(false, {{"error", "Please run as root"}});
        return;
    }

    if (interface_name.empty()) {
        emit initialized(false, {{"error", "No wireless interface found."}});
        return;
    }

    if (!WpaSupplicantManager::hasP2PCapabilities(interface_name)) {
        emit initialized(false, {{"error", "No P2P capabilities."}});
        return;
    }

    if (!std::filesystem::exists(wpaSupplicantConfPath)) {
        if (!writeWpaSupplicantConf(wpaSupplicantConfPath, device_name)) {
            emit initialized(false, {{"error", "Error writing configuration file."}});
            return;
        }
    }

/*    if (!std::filesystem::exists(udhcpdConfPath)) {
        if (!writeUdhcpdConf(udhcpdConfPath, interface_name)) {
            emit initialized(false, {{"error", "Error writing configuration file."}});
            return;
        }
    }*/

    emit initialized(true, {{"device_name", device_name.c_str()},
                            {"mac_address", mac_address.c_str()}});
}

void AppProxy::log(const QString &message) {
    cout << message.toStdString() << endl;
}

void AppProxy::enableWiFiDirectMode() {
    QThread::create([this]() {
        //TODO: le proprietà di this vanno modificate in modo "safe"!
        netStop();
        setNmStopped(true);
        startWpaSupplicant(wpaSupplicantConfPath, interface_name);
        wpa_supplicant_manager.emplace(interface_name, confDir,
                                       [this](P2PEvent e, const std::map<P2PEventParamName, std::string> &m) {
                                           this->process_event(e, m);
                                       });
        emit directModeEnabled();
    })->start();
}

void AppProxy::resetNetwork() {
    QThread::create([this]() {
        wpa_supplicant_manager.reset();
        netReset();
        setNmStopped(false);
        emit networkReset();
    })->start();
}

void AppProxy::startGroup() {
    wpa_supplicant_manager.value().start_p2p_group();
}

void AppProxy::disconnect() {
    wpa_supplicant_manager.value().remove_p2p_group();
}

void AppProxy::startFind() {
    wpa_supplicant_manager.value().p2p_flush();
    wpa_supplicant_manager.value().start_p2p_find(0);
}

void AppProxy::stopFind() {
    wpa_supplicant_manager.value().stop_p2p_find();
}

void AppProxy::connect(const QString &mac_addr) {
    wpa_supplicant_manager.value().connect_to_mac(mac_addr.toStdString());
}

void AppProxy::removeClient(const QString &mac_addr) {
    wpa_supplicant_manager.value().remove_client(mac_addr.toStdString());
}

void AppProxy::getScreenList() {
    auto screen_list = MonitorService::getMonitors();
    QVector<QString> monitors_preview_b64;

    for (int i = 0; i < screen_list.size(); i++) {
        std::cout << i + 1 << " -> " << screen_list[i] << std::endl;

        monitors.push_back(screen_list[i]);

        std::string base64Image = MonitorService::getMonitorScreenshot(screen_list[i].getX(), screen_list[i].getY(),
                                                                       screen_list[i].getWidth(),
                                                                       screen_list[i].getHeight());
        //monitors_preview_b64.push_back(screen_list[i].getName().c_str());
        monitors_preview_b64.push_back(base64Image.c_str());
    }

/*    //print previews
    for (auto &preview : monitors_preview_b64) {
        std::cout << preview.first.toStdString() << " -> " << preview.second.toStdString() << std::endl;
    }*/

    emit screenListAcquired(monitors_preview_b64);
}

void AppProxy::startCasting(int screen_index) {
    if (monitors.size() < screen_index) {
        std::cerr << "Screen unavailable" << std::endl;
        return;
    }
    Monitor screen = monitors[screen_index];
    casting_service->start_recording(screen, "rtmp://localhost/live/screen");
}

void AppProxy::stopCasting() {
    stopFFplay();
    casting_service->stop_recording();
}

void AppProxy::startFFplay(const std::string &url) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        // ffplay -fflags nobuffer -flags low_delay -vf setpts=0 rtmp://localhost/live/screen
        execl("/usr/bin/ffplay", "ffplay",
              "-fflags", "nobuffer", // Format Options
              "-flags", "low_delay", // Codec Options
              "-vf", "setpts=0", // filtergraph (video stream)
              url.c_str(), nullptr);
        exit(0);
    } else if (pid > 0) {
        // Parent process
        ffplay_pid = pid;
    } else {
        // Fork fallita
        std::cerr << "Errore nella fork" << std::endl;
    }
}

void AppProxy::stopFFplay() {
    if (ffplay_pid != -1) {
        kill(ffplay_pid, SIGKILL);
        ffplay_pid = -1;
    }
}

void AppProxy::viewScreen() {
    startFFplay("rtmp://10.0.0.1/live/screen");
}

void AppProxy::onGroupFinished(const QString &group_name, const QString &group_role) {
    stopFFplay();
}

void AppProxy::flushP2P() {
    wpa_supplicant_manager.value().p2p_flush();
}
