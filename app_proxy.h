#ifndef WIFI_WONDERS_APP_PROXY_H
#define WIFI_WONDERS_APP_PROXY_H

#include <QObject>
#include <QMap>
#include <QString>

#undef slots
#undef signals
#undef emit

#include "wpa-supplicant-manager/utils.hpp"
#include "wpa-supplicant-manager/wpa_supplicant_manager.h"
#include "wpa-supplicant-manager/P2PEvent.h"

#include "screen-casting-service/monitor_service.h"
#include "screen-casting-service/casting_service.h"

#define slots Q_SLOTS
#define signals Q_SIGNALS
#define emit

class AppProxy : public QObject {
Q_OBJECT

private:
    static pid_t ffplay_pid;
    static void startFFplay(const std::string &url);
    static void stopFFplay();
    static void interrupt_handler(int signum);

    bool nmStopped;
    void setNmStopped(bool val);

    std::string device_name;
    std::string interface_name;
    std::string mac_address;
    std::string confDir;
    std::string wpaSupplicantConfPath;

    std::optional<WpaSupplicantManager> wpa_supplicant_manager;
    std::vector<Monitor> monitors;
    CastingService *casting_service;


    void process_event(P2PEvent p2p_event, std::map<P2PEventParamName, std::string> args);

public:
    explicit AppProxy(QObject *parent = nullptr);

    ~AppProxy() override;

    Q_INVOKABLE void log(const QString &message);

    Q_INVOKABLE void initialCheck();

    Q_INVOKABLE void enableWiFiDirectMode();

    Q_INVOKABLE void resetNetwork();

    Q_INVOKABLE void startGroup();

    Q_INVOKABLE void disconnect();

    Q_INVOKABLE void startFind();

    Q_INVOKABLE void stopFind();

    Q_INVOKABLE void flushP2P();

    Q_INVOKABLE void connect(const QString& mac_addr);

    Q_INVOKABLE void removeClient(const QString& mac_addr);

    Q_INVOKABLE void getScreenList();

    Q_INVOKABLE void startCasting(int screen_index);

    Q_INVOKABLE void stopCasting();

    Q_INVOKABLE void viewScreen();

public slots:
    void onGroupFinished(const QString& group_name, const QString& group_role);

signals:

    void initialized(bool success, const QMap<QString, QString>& data);

    void directModeEnabled();

    void networkReset();

    void findStarted();

    void findStopped();

    void deviceFound(QString mac_addr, QString device_name);

    void deviceLost(QString mac_addr);

    void groupStarted(QString group_name, QString group_role);

    void groupFinished(QString group_name, QString group_role);

    void groupFormationFailure();

    void peerJoined(QString mac_addr, QString device_name);

    void peerDisconnected(QString mac_addr);

    void screenListAcquired(QVector<QString> screens_preview_base64);

};


#endif //WIFI_WONDERS_APP_PROXY_H
