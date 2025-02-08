set(WMEDIA_SERVICE_SOURCES
    media/include/WindowMediaService.h
    media/src/WindowMediaService.cpp
)

add_library(wmedia_service STATIC
    ${WMEDIA_SERVICE_SOURCES}
)

target_include_directories(wmedia_service
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/media/include
)
