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
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(service_factory
    PRIVATE
        wmedia_service
)