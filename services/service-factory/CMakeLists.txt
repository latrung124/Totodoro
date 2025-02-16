cmake_minimum_required(VERSION 3.22)
project(service_factory VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FACTORY_HEADERS
    include/ServiceFactory.h
)

set(FACTORY_SOURCES
    src/ServiceFactory.cpp
)

add_library(service_factory SHARED
    ${FACTORY_HEADERS}
    ${FACTORY_SOURCES}
)

add_dependencies(service_factory wmedia_service)

target_include_directories(service_factory
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(service_factory
    PRIVATE
        wmedia_service
)

install(TARGETS service_factory
    EXPORT ServicesTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)