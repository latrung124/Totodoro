cmake_minimum_required(VERSION 3.22)
project(
  Services
  VERSION 1.0.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_definitions(-DSERVICE_LIBRARY_EXPORTS)
add_definitions(-DWMEDIA_SERVICE_LIBRARY_EXPORTS)
add_definitions(-DAPIGATEWAY_SERVICE_LIBRARY_EXPORTS)
add_definitions(-DSERVICE_FACTORY_LIBRARY_EXPORTS)

add_subdirectory(interfaces)
add_subdirectory(window-services)
add_subdirectory(service-factory)
add_subdirectory(apigateway-service)

install(
  EXPORT ServicesTargets
  FILE ServicesTargets.cmake
  NAMESPACE Services::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Services)

export(
  EXPORT ServicesTargets
  FILE ${CMAKE_CURRENT_BINARY_DIR}/ServicesTargets.cmake
  NAMESPACE Services::)

set(ConfigPackageLocation ${CMAKE_INSTALL_LIBDIR}/cmake/Services)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/ServicesConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/ServicesConfig.cmake
  INSTALL_DESTINATION ${ConfigPackageLocation})

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/ServicesConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ServicesConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ServicesConfigVersion.cmake
        DESTINATION ${ConfigPackageLocation})
