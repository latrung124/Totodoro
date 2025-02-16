cmake_minimum_required(VERSION 3.22)
project(wmedia_service VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WMEDIA_SERVICE_SOURCES
    media/include/WindowMediaService.h
    media/src/WindowMediaService.cpp
)

add_library(wmedia_service SHARED
    ${WMEDIA_SERVICE_SOURCES}
)

add_library(Services::wmedia_service ALIAS wmedia_service)

add_dependencies(service_interfaces wmedia_service)

target_include_directories(wmedia_service
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/interfaces/export-headers>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/interfaces/window-services>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/media/include>
        $<INSTALL_INTERFACE:interfaces/export-headers>
        $<INSTALL_INTERFACE:interfaces/window-services>
        $<INSTALL_INTERFACE:media/include>
)

install(TARGETS wmedia_service
    EXPORT ServicesTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
