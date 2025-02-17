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
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/export-headers>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/include/window-services>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/media/include>
        $<INSTALL_INTERFACE:interfaces>
)

install(TARGETS wmedia_service
    EXPORT ServicesTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
