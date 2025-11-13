cmake_minimum_required(VERSION 3.22)
project(ServiceFactory LANGUAGES CXX)

set(FACTORY_HEADERS include/ServiceFactory.h)

set(FACTORY_SOURCES src/ServiceFactory.cpp)

add_library(ServiceFactory SHARED ${FACTORY_HEADERS} ${FACTORY_SOURCES})

add_dependencies(ServiceFactory WMediaService ApiGatewayService)

target_include_directories(
  ServiceFactory
  PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/services/interfaces/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include/services/interfaces>)

target_link_libraries(ServiceFactory PRIVATE WMediaService ApiGatewayService)

install(
  TARGETS ServiceFactory
  EXPORT ServicesTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${FACTORY_HEADERS}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/services/service-factory)
