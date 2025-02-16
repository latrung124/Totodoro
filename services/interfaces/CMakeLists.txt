cmake_minimum_required(VERSION 3.22)
project(services_interfaces VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INTERFACE_HEADERS
    IService.h
    IServiceFactory.h
    IServiceListener.h
    export-headers/ServiceFactoryExport.h
    export-headers/WindowServiceExport.h
    window-services/IWMediaService.h
    window-services/IWMediaServiceListener.h
    window-services/WMediaServiceUtils.h
)

add_library(service_interfaces INTERFACE
    ${INTERFACE_HEADERS}
)

target_include_directories(service_interfaces
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export-headers>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/window-services>
        $<INSTALL_INTERFACE:export-headers>
        $<INSTALL_INTERFACE:window-services>
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/IService.h
    ${CMAKE_CURRENT_SOURCE_DIR}/IServiceFactory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/IServiceListener.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/interfaces
)

install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/export-headers
    ${CMAKE_CURRENT_SOURCE_DIR}/window-services
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/interfaces
)
