cmake_minimum_required(VERSION 3.22)
project(WindowServices LANGUAGES CXX)

set(WMEDIA_SERVICE_SOURCES
    media/include/WindowSystemMedia.h media/include/WindowMediaService.h
    media/src/WindowSystemMedia.cpp media/src/WindowMediaService.cpp)

add_library(WMediaService SHARED ${WMEDIA_SERVICE_SOURCES})

add_library(Services::WMediaService ALIAS WMediaService)

add_dependencies(Interfaces WMediaService)

target_include_directories(
  WMediaService
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/export-headers>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/include/window-services>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/media/include>
    $<INSTALL_INTERFACE:include/services/interfaces>)

install(
  TARGETS WMediaService
  EXPORT ServicesTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

enable_testing()

add_subdirectory(tests)
