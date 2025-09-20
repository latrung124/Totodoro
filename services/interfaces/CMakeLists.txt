cmake_minimum_required(VERSION 3.22)
project(Interfaces LANGUAGES CXX)

set(INTERFACE_HEADERS
    include/IService.h
    include/IServiceFactory.h
    include/IServiceListener.h
    include/window-services/IWMediaService.h
    include/window-services/IWMediaServiceListener.h
    include/window-services/WMediaServiceUtils.h
    include/apigateway-service/IApiGatewayService.h
    include/apigateway-service/IApiGatewayServiceListener.h
    include/apigateway-service/ApiGatewayServiceUtils.h
    export-headers/ServiceExport.h
    export-headers/ServiceFactoryExport.h
    export-headers/WindowServiceExport.h)

add_library(Interfaces INTERFACE ${INTERFACE_HEADERS})

target_include_directories(
  Interfaces
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/window-services>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/apigateway-service>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export-headers>
    $<INSTALL_INTERFACE:include/services/interfaces>
    $<INSTALL_INTERFACE:include/services/interfaces/export-headers>
    $<INSTALL_INTERFACE:include/services/interfaces/include>
    $<INSTALL_INTERFACE:include/services/interfaces/include/window-services>
    $<INSTALL_INTERFACE:include/services/interfaces/include/apigateway-service>)

install(
  TARGETS Interfaces
  EXPORT ServicesTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${INTERFACE_HEADERS}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/services/interfaces)
