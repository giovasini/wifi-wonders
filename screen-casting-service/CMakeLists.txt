cmake_minimum_required(VERSION 3.16)
project(ScreenCastingService VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_FLAGS "-fPIC")
set(CMAKE_C_FLAGS "-fPIC")

find_package(fmt REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
        libavdevice
        libavfilter
        libavformat
        libavcodec
        libswscale
        libavutil
)

add_library(ScreenCastingService STATIC)

target_include_directories(ScreenCastingService
        PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(ScreenCastingService
        PRIVATE
        #list of .cpp files
        monitor.cpp
        monitor_service.cpp
        libav_wrapper.cpp
        casting_service.cpp
)

target_link_libraries(ScreenCastingService fmt::fmt)
target_link_libraries(ScreenCastingService PkgConfig::LIBAV)
target_link_libraries(ScreenCastingService X11)
target_link_libraries(ScreenCastingService Xrandr)
target_link_libraries(ScreenCastingService png)
target_link_libraries(ScreenCastingService b64)

add_executable(ScreenCastingServiceTest
        main.cpp)

target_link_libraries(ScreenCastingServiceTest ScreenCastingService)