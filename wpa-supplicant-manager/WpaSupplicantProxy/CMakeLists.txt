cmake_minimum_required(VERSION 3.16)
project(WpaSupplicantProxy)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig REQUIRED)
pkg_check_modules(DBUS_CXX REQUIRED dbus-cxx-2.0)

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(${PROJECT_NAME}
        PRIVATE
        src/WpaSupplicantProxy.cpp
        src/WpaSupplicantPeerProxy.cpp
        src/WpaSupplicantInterfaceProxy.cpp
        src/WpaSupplicantGroupProxy.cpp
        src/fi_w1_wpa_supplicant1Proxy.cpp
        src/fi_w1_wpa_supplicant1_PeerProxy.cpp
        src/fi_w1_wpa_supplicant1_Interface_WPSProxy.cpp
        src/fi_w1_wpa_supplicant1_InterfaceProxy.cpp
        src/fi_w1_wpa_supplicant1_Interface_P2PDeviceProxy.cpp
        src/fi_w1_wpa_supplicant1_GroupProxy.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${DBUS_CXX_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DBUS_CXX_LDFLAGS})
