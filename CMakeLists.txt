cmake_minimum_required(VERSION 3.16)

project(wifi_wonders VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets WebEngineWidgets)

add_subdirectory("wpa-supplicant-manager")
add_subdirectory("screen-casting-service")

add_executable(wifi_wonders
        application.qrc
        main.cpp
        app_proxy.cpp
        app_proxy.h
        wpa-supplicant-manager/P2PEvent.h
)

target_link_libraries(wifi_wonders PRIVATE Qt6::Widgets Qt6::WebEngineWidgets)
target_link_libraries(wifi_wonders PUBLIC WpaSupplicantManager)
target_link_libraries(wifi_wonders PUBLIC ScreenCastingService)

#[[
set_target_properties(qt_html PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)]]
