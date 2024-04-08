# wifiwonders
A software Wi-Fi Direct based to cast your screen to other devices developed as Thesis project at Politecnico di Torino.

# Requirements

- Application requires root privileges

# Dependencies

```bash
sudo apt install -y g++ cmake make mesa-common-dev pkg-config locate

sudo apt install -y qt6-base-dev qt6-base-dev-tools qt6-webengine-dev qt6-webengine-dev-tools libqt6webenginecore6-bin libxkbcommon-dev

sudo apt install -y ffmpeg libavfilter-dev libfmt-dev libavdevice-dev libxrandr-dev libpng-dev libb64-dev

sudo apt install -y udhcpd

sudo apt install -y libdbus-1-dev libexpat1-dev 

```

## libsigc++
```bash
cd ~
wget https://github.com/dbus-cxx/libsigc--3.0/archive/refs/heads/master.zip
unzip master.zip
rm master.zip
cd libsigc--3.0-master
mkdir libsigcplusplus_build
cd libsigcplusplus_build
cmake ..
make
sudo make install
updatedb
```

## dbus-cxx
```bash
cd ~
wget https://github.com/dbus-cxx/dbus-cxx/archive/refs/tags/2.5.1.zip
unzip 2.5.1.zip
rm 2.5.1.zip
cd dbus-cxx-2.5.1
mkdir build
cd build
cmake ..
make
sudo make install
updatedb
```

## Nginx-RTMP server

```bash
sudo apt install libnginx-mod-rtmp
```

Add this configuration block to the end of the file
```bash
sudo nano /etc/nginx/nginx.conf
```

```
. . .
rtmp {
        server {
                listen 1935;
                chunk_size 4096;
                allow publish 127.0.0.1;
                deny publish all;

                application live {
                        live on;
                        record off;
                }
        }
}
```

Run the following command and restart the service.

```bash
sudo ufw allow 1935/tcp
sudo systemctl reload nginx.service
```