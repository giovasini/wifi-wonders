cmake_minimum_required(VERSION 3.16)
project(WpaSupplicantManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory ("WpaSupplicantProxy")

add_library(WpaSupplicantManager STATIC
        P2PEvent.h)

target_include_directories(WpaSupplicantManager
        PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(WpaSupplicantManager
        PRIVATE
        wpa_supplicant_manager.cpp
)

target_link_libraries(WpaSupplicantManager PUBLIC WpaSupplicantProxy)
