/* global bootstrap: false */

// TODO: creare un flusso "coerente" show/hide di tutti gli elementi per tutti gli stati

let p2p_enabled = false;
let p2p_group_role = "";

(() => {
    'use strict'

    document.addEventListener('contextmenu', e => e.preventDefault());

    const popoverTriggerList = document.querySelectorAll('[data-bs-toggle="popover"]');
    const popoverList = [...popoverTriggerList].map(popoverTriggerEl => new bootstrap.Popover(popoverTriggerEl));

    function setStatusPanel(status, message) {
        document.getElementById('text-status').innerHTML = status;
        document.getElementById('circle-status').classList.remove('text-warning', 'text-warning', 'text-danger', 'blink');
        switch (status) {
            case "Ready":
            case "Connected":
            case "Finding":
                document.getElementById('circle-status').classList.add('text-success');
                break;
            case "Setup missing":
                document.getElementById('circle-status').classList.add('text-warning');
                break;
            case "Error":
                document.getElementById('circle-status').classList.add('text-danger');
                break;
            case "Sharing":
                document.getElementById('circle-status').classList.add('text-danger', 'blink');
                break;
            default:
                break;
        }
        popoverList.forEach(popover => popover.setContent({'.popover-body': message}));
    }

    document.getElementById('btn-home').addEventListener('click', function () {
        document.getElementById('home').classList.remove('d-none');
        document.getElementById('share-screen').classList.add('d-none');
        document.getElementById('view-screen').classList.add('d-none');

        document.getElementById('btn-home').classList.add('active');
        document.getElementById('btn-share-screen').classList.remove('active');
        document.getElementById('btn-view-screen').classList.remove('active');
    });

    document.getElementById('btn-share-screen').addEventListener('click', function () {
        document.getElementById('home').classList.add('d-none');
        document.getElementById('share-screen').classList.remove('d-none');
        document.getElementById('view-screen').classList.add('d-none');

        document.getElementById('btn-home').classList.remove('active');
        document.getElementById('btn-share-screen').classList.add('active');
        document.getElementById('btn-view-screen').classList.remove('active');
    });

    document.getElementById('btn-view-screen').addEventListener('click', function () {
        document.getElementById('home').classList.add('d-none');
        document.getElementById('share-screen').classList.add('d-none');
        document.getElementById('view-screen').classList.remove('d-none');

        document.getElementById('btn-home').classList.remove('active');
        document.getElementById('btn-share-screen').classList.remove('active');
        document.getElementById('btn-view-screen').classList.add('active');
    });

    new QWebChannel(qt.webChannelTransport, function (channel) {
        // now you can access the object registered at the C++ side
        const appProxy = channel.objects.app_proxy;
        let available_peers = 0;
        let connected_peers = 0;
        let selectedScreen = -1;

        appProxy.initialized.connect(function (success, data) {
            appProxy.log("initialized: " + success);
            if (success) {
                setStatusPanel('Setup missing', 'Please enable WiFi Direct mode');
                for (const element of document.getElementsByClassName('alert-setup-missing')) {
                    element.classList.remove('d-none');
                }
                for (const element of document.getElementsByClassName('device-name')) {
                    element.innerHTML = data["device_name"];
                }
                for (const element of document.getElementsByClassName('device-mac-addr')) {
                    element.innerHTML = data["mac_address"];
                }
                for (const element of document.getElementsByClassName('panelDeviceInfo')) {
                    element.classList.remove('d-none');
                }
            } else {
                appProxy.log(data["error"]);
                setStatusPanel('Error', data["error"]);
                for (const element of document.getElementsByClassName('alert-error-start')) {
                    element.classList.remove('d-none');
                    element.innerHTML = data["error"];
                }
            }
        });

        document.getElementById('btnEnableWifiDirectMode').addEventListener('click', function () {
            document.getElementById('btnEnableWifiDirectMode').classList.add('d-none');
            document.getElementById('spinnerEnableWifiDirectMode').classList.remove('d-none');
            appProxy.enableWiFiDirectMode();
        });

        appProxy.directModeEnabled.connect(function () {
            p2p_enabled = true;

            for (const element of document.getElementsByClassName('alert-setup-missing')) {
                element.classList.add('d-none');
            }
            document.getElementById('panelResetNetwork').classList.remove('d-none');

            document.getElementById('btnEnableWifiDirectMode').classList.remove('d-none');
            document.getElementById('spinnerEnableWifiDirectMode').classList.add('d-none');

            setStatusPanel('Ready', 'Status: OK');

            document.getElementById('panelShareScreen').classList.remove('d-none');
            document.getElementById('btnSelectScreen').classList.remove('d-none');

            document.getElementById('panelViewScreen').classList.remove('d-none');
            document.getElementById('listAvailablePeers').innerHTML = '';
            available_peers = 0;
        });

        document.getElementById('btnResetNetwork').addEventListener('click', function () {
            if (p2p_group_role !== "") {
                appProxy.disconnect();
            }

            document.getElementById('btnResetNetwork').classList.add('d-none');
            document.getElementById('spinnerResetNetwork').classList.remove('d-none');

            appProxy.resetNetwork();
        });

        appProxy.networkReset.connect(function () {
            p2p_enabled = false;

            setStatusPanel('Setup missing', 'Please enable WiFi Direct mode');

            document.getElementById('panelEnableWifiDirectMode').classList.remove('d-none');
            document.getElementById('panelResetNetwork').classList.add('d-none');

            document.getElementById('spinnerResetNetwork').classList.add('d-none');
            document.getElementById('btnResetNetwork').classList.remove('d-none');

            for (const element of document.getElementsByClassName('alert-setup-missing')) {
                element.classList.remove('d-none');
            }

            document.getElementById('panelSelectScreen').classList.add('d-none');
            document.getElementById('panelShareScreen').classList.add('d-none');
            document.getElementById('panelGroup').classList.add('d-none');
            document.getElementById('btnStopShare').classList.add('d-none');
            document.getElementById('btnPreviewScreen').classList.add('d-none');
            document.getElementById('btnStartShare').classList.add('d-none');
            document.getElementById('btnSelectScreen').classList.add('d-none');

            document.getElementById('panelViewScreen').classList.add('d-none');
        });

        document.getElementById('btnSelectScreen').addEventListener('click', function () {
            appProxy.getScreenList();
        });

        document.getElementById('btnStartShare').addEventListener('click', function () {
            appProxy.log(" > selected screen: " + selectedScreen);
            if (selectedScreen !== -1) {
                appProxy.startGroup();
                appProxy.startCasting(selectedScreen);
            }
        });

        appProxy.screenListAcquired.connect(function (screens_preview_base64) {
            appProxy.log(" > screen list acquired");

            document.getElementById('btnSelectScreen').classList.add('d-none');

            document.getElementById('listScreen').innerHTML = '';

            let screenIndex = 0;
            for (const preview of screens_preview_base64) {
                appProxy.log("   monitor: Display " + (screenIndex + 1));
                const newMonitorDiv =
                    '<div class="card" data-screen-index="' + screenIndex + '">' +
                    '    <img class="card-img-top" src="data:image/png;base64,' + preview + '" alt="Preview">' +
                    '    <div class="card-body d-flex flex-column align-items-center justify-content-center p-1">' +
                    '        <h5 class="card-title"> Display ' + (screenIndex + 1) + '</h5>' +
                    '    </div>' +
                    '</div>';
                document.getElementById('listScreen').innerHTML += newMonitorDiv;
                screenIndex++;
            }

            document.getElementById('panelSelectScreen').classList.remove('d-none');
            document.getElementById('btnStartShare').classList.remove('d-none');
            document.getElementById('btnStartShare').disabled = true;

            // set selected card when clicked
            const cardList = document.querySelectorAll('.card');
            cardList.forEach(card => card.addEventListener('click', function () {
                cardList.forEach(card => card.classList.remove('selected'));
                card.classList.add('selected');
                selectedScreen = card.getAttribute('data-screen-index');
                appProxy.log(" > selected screen: " + selectedScreen);
                document.getElementById('btnStartShare').disabled = false;
            }));
        });

        appProxy.groupStarted.connect(function (group_name, group_role) {
            appProxy.log(" > group started");

            p2p_group_role = group_role;

            if (group_role === "GO") {
                setStatusPanel('Sharing', 'IP address: 10.0.0.1');

                document.getElementById('btnStartShare').classList.add('d-none');
                document.getElementById('btnStopShare').classList.remove('d-none');
                document.getElementById('btnPreviewScreen').classList.remove('d-none');

                document.getElementById('panelSelectScreen').classList.add('d-none');
                document.getElementById('panelGroup').classList.remove('d-none');
                document.getElementById('group-name-owner').innerHTML = "Group " + group_name;

                document.getElementById('listConnectedPeers').innerHTML = '';
                connected_peers = 0;

                document.getElementById('errorShareInProgress').classList.remove('d-none');
                document.getElementById('panelViewScreen').classList.add('d-none');

            } else {
                setStatusPanel('Connected', 'Connected');

                document.querySelectorAll('.spinnerConnectPeer').forEach(btnConnectPeer => btnConnectPeer.classList.add('d-none'));
                document.querySelectorAll('.btnConnectPeer').forEach(btnConnectPeer => btnConnectPeer.classList.remove('d-none'));

                document.getElementById('panelFindMode').classList.add('d-none');

                document.getElementById('panelConnected').classList.remove('d-none');
                document.getElementById('group-name-client').innerHTML = "Group " + group_name;

                document.getElementById('errorViewInProgress').classList.remove('d-none');
                document.getElementById('panelShareScreen').classList.add('d-none');

                appProxy.viewScreen();
                setTimeout(function() {
                    document.getElementById('btnStartFFplayClient_spinner').classList.add('d-none');
                    document.getElementById('btnStartFFplayClient').classList.remove('d-none');
                }, 15000); 
            }
        });

        appProxy.peerJoined.connect(function (mac_addr, device_name) {
            appProxy.log(" > peer joined");

            const newPeerDiv =
                '<div id="peer_' + mac_addr + '" class="peer-item d-flex align-items-end ps-3 py-1">' +
                '    <span class="peer-name fs-5 fw-medium me-2">' + device_name + '</span>' +
                '    <span class="peer-mac-addr text-muted">' + mac_addr + '</span>' +
                '    <button id="btn_remove_client_' + mac_addr + '" class="btn btn-sm btn-outline-danger ms-auto">Remove</button>' +
                '</div>';

            document.getElementById('listConnectedPeers').innerHTML += newPeerDiv;
            connected_peers++;
            if (connected_peers > 0) {
                document.getElementById('listConnectedPeers').classList.remove('d-none');
                document.getElementById('noPeersConnected').classList.add('d-none');
            }

            document.getElementById('btn_remove_client_' + mac_addr).addEventListener('click', function () {
                appProxy.log(" > remove client " + mac_addr);
                appProxy.removeClient(mac_addr);
            });
        });

        appProxy.peerDisconnected.connect(function (mac_addr) {
            appProxy.log(" > peer disconnected");

            document.getElementById('peer_' + mac_addr).remove();
            connected_peers--;
            if (connected_peers <= 0) {
                document.getElementById('noPeersConnected').classList.remove('d-none');
                document.getElementById('listConnectedPeers').classList.add('d-none');
            }
        });

        document.getElementById('btnStopShare').addEventListener('click', function () {
            appProxy.stopCasting();
            appProxy.disconnect();
        });

        document.getElementById('btnDisconnect').addEventListener('click', function () {
            appProxy.disconnect();
        });

        appProxy.groupFinished.connect(function (group_name, group_role) {
            appProxy.log(" > group finished");

            if (group_role === "GO") {
                setStatusPanel('Ready', 'Status: OK');

                document.getElementById('btnStopShare').classList.add('d-none');
                document.getElementById('btnPreviewScreen').classList.add('d-none');
                document.getElementById('btnSelectScreen').classList.remove('d-none');

                document.getElementById('panelGroup').classList.add('d-none');

                if (connected_peers !== 0) {
                    appProxy.log("!? connected_peers=" + connected_peers + " but groupFinished");
                }

                document.getElementById('errorShareInProgress').classList.add('d-none');
                document.getElementById('panelViewScreen').classList.remove('d-none');
            } else {
                document.getElementById('errorViewInProgress').classList.add('d-none');
                document.getElementById('panelShareScreen').classList.remove('d-none');

                document.getElementById('panelConnected').classList.add('d-none');
                document.getElementById('panelFindMode').classList.remove('d-none');

                if (p2p_enabled)
                    appProxy.startFind();
            }
            p2p_group_role = "";
        });

        appProxy.groupFormationFailure.connect(function () {
            appProxy.log(" > group formation failure " );
            appProxy.flushP2P();
        });

        document.getElementById('btn-view-screen').addEventListener('click', function () {
            if (p2p_enabled && p2p_group_role === "")
                appProxy.startFind();
        });

        appProxy.findStarted.connect(function () {
            appProxy.log(" > find started");
            setStatusPanel('Finding', 'Searching for peers...');
            //document.getElementById('listAvailablePeers').innerHTML = '';
        });

        appProxy.deviceFound.connect(function (mac_addr, device_name) {
            if (p2p_group_role === "") {
                appProxy.log(" > device found");

                const newPeerDiv =
                    '<div id="peer_' + mac_addr + '" class="peer-item d-flex align-items-end ps-3 py-1">' +
                    '    <span class="peer-name fs-5 fw-medium me-2">' + device_name + '</span>' +
                    '    <span class="peer-mac-addr text-muted">' + mac_addr + '</span>' +
                    '    <button id="btn_connect_peer_' + mac_addr + '" class="btnConnectPeer btn btn-sm btn-outline-primary ms-auto">Connect</button>' +
                    '    <button id="spinner_connect_peer_' + mac_addr + '" class="spinnerConnectPeer btn btn-sm btn-outline-primary ms-auto d-none">' +
                    '         <span class="spinner-border spinner-border-sm" aria-hidden="true"></span> <span role="status">Connect</span>' +
                    '    </button>' +
                    '</div>';

                if (document.getElementById('peer_' + mac_addr) === null) {
                    document.getElementById('listAvailablePeers').innerHTML += newPeerDiv;
                    available_peers++;
                }

                if (available_peers > 0) {
                    document.getElementById('listAvailablePeers').classList.remove('d-none');
                    document.getElementById('noPeersAvailable').classList.add('d-none');
                }

                //NB: l'evento viene chiamato più volte se il peer era già stato trovato
                document.getElementById('btn_connect_peer_' + mac_addr).addEventListener('click', function () {
                    appProxy.log(" > connect to peer " + mac_addr);
                    document.getElementById('btn_connect_peer_' + mac_addr).classList.add('d-none');
                    document.getElementById('spinner_connect_peer_' + mac_addr).classList.remove('d-none');
                    appProxy.connect(mac_addr);
                });
            }
        });

        appProxy.deviceLost.connect(function (mac_addr) {
            if (p2p_group_role === "") {
                appProxy.log(" > device lost");
                document.getElementById('peer_' + mac_addr).remove();
                available_peers--;
                if (available_peers === 0) {
                    document.getElementById('listAvailablePeers').classList.add('d-none');
                    document.getElementById('noPeersAvailable').classList.remove('d-none');
                }
                if (available_peers < 0) {
                    appProxy.log("!? available_peers < 0");
                }
            }
        });

        document.getElementById('btn-home').addEventListener('click', function () {
            if (p2p_enabled)
                appProxy.stopFind();
        });

        document.getElementById('btn-share-screen').addEventListener('click', function () {
            if (p2p_enabled)
                appProxy.stopFind();
        });

        appProxy.findStopped.connect(function () {
            appProxy.log(" > find stopped");
            setStatusPanel('Ready', 'Status: OK');
        });

        document.getElementById('btnStartFFplayClient').addEventListener('click', function () {
            document.getElementById('btnStartFFplayClient_spinner').classList.remove('d-none');
            document.getElementById('btnStartFFplayClient').classList.add('d-none');
            
            appProxy.viewScreen();
            
            setTimeout(function() {
                document.getElementById('btnStartFFplayClient_spinner').classList.add('d-none');
                document.getElementById('btnStartFFplayClient').classList.remove('d-none');
            }, 15000); 
        });

        document.getElementById('btnPreviewScreen').addEventListener('click', function () {
            appProxy.viewScreen();
        });

        appProxy.initialCheck();
    });

})()
