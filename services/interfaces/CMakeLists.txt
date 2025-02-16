cmake_minimum_required(VERSION 3.22)
project(services_interfaces VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INTERFACE_HEADERS
    include/IService.h
    include/IServiceFactory.h
    include/IServiceListener.h
    include/window-services/IWMediaService.h
    include/window-services/IWMediaServiceListener.h
    include/window-services/WMediaServiceUtils.h
    export-headers/ServiceExport.h
    export-headers/ServiceFactoryExport.h
    export-headers/WindowServiceExport.h
)

add_library(service_interfaces INTERFACE
    ${INTERFACE_HEADERS}
)

target_include_directories(service_interfaces
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:interfaces>
)

install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/interfaces
)
