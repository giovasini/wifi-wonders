# Wi-Fi direct manager
Tool per la gestione del Wi-Fi direct

L'applicazione cerca l'interfaccia wireless disponibile.  
Se nessuna interfaccia wireless è disponibile viene segnalato un errore e il programma si chiude.


# Dependencies
- [dbus-cxx (fix #136)](https://github.com/dbus-cxx/dbus-cxx)
- udhcpd  
    Install running `sudo apt install udhcpd`

## TODO
- [x]  Includere DBus e WpaSupplicant Proxy
- [x]  p2p find
- [ ]  Aggiungere variabile di stato per non stampare menu durante Find o altri processi?
- [x]  p2p group add
- [x]  p2p connect
- [x]  dhcp
- [x]  ip addr add
- [ ]  AddService
- [x]  ServiceDiscoveryRequest
- [x]  p2p disconnect
- [ ]  p2p remove client
- [x]  p2p group remove
- [ ]  callback per la gestione dei signal
  - [x]  GONegotiationSuccess
  - [x]  GONegotiationFailure
  - [x]  GONegotiationRequest
  - [x]  GroupStarted
  - [x]  GroupFormationFailure
  - [x]  GroupFinished
  - [x]  InvitationReceived
  - [x]  PeerJoined
  - [x]  PeerDisconnected