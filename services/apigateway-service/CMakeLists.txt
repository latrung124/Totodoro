cmake_minimum_required(VERSION 3.22)
project(ApiGatewayService LANGUAGES CXX)

set(APIGATEWAY_SERVICE_SOURCES include/ApiGatewayService.h
                               src/ApiGatewayService.cpp)

add_library(ApiGatewayService SHARED ${APIGATEWAY_SERVICE_SOURCES})

add_library(Services::ApiGatewayService ALIAS ApiGatewayService)

add_dependencies(Interfaces ApiGatewayService)

target_include_directories(
  ApiGatewayService
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/export-headers>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/include/apigateway-service>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/services/interfaces>)

install(
  TARGETS ApiGatewayService
  EXPORT ServicesTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

enable_testing()
