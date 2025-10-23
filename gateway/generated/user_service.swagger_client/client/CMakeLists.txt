cmake_minimum_required(VERSION 3.5)

project(UserQtOpenAPIClient)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Gui)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(_DUP_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIHelpers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIHttpFileElement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIHttpRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIOauth.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIProtobufAny.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIRpcStatus.cpp)
set(_DUP_HDRS
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIEnum.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIHelpers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIHttpFileElement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIHttpRequest.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIOauth.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIObject.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIProtobufAny.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIRpcStatus.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIServerConfiguration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OAIServerVariable.h)
set_source_files_properties(${_DUP_SRCS} PROPERTIES HEADER_FILE_ONLY ON
                                                    SKIP_AUTOGEN ON)
set_source_files_properties(${_DUP_HDRS} PROPERTIES SKIP_AUTOMOC ON)

add_library(
  ${PROJECT_NAME}
  OAIUserServiceUpdateSettingsBody.h
  OAIUserServiceUpdateUserBody.h
  OAIUser_serviceCreateUserRequest.h
  OAIUser_serviceCreateUserResponse.h
  OAIUser_serviceGetSettingsResponse.h
  OAIUser_serviceGetUserResponse.h
  OAIUser_serviceSettings.h
  OAIUser_serviceUpdateSettingsResponse.h
  OAIUser_serviceUpdateUserResponse.h
  OAIUserServiceUpdateSettingsBody.cpp
  OAIUserServiceUpdateUserBody.cpp
  OAIUser_serviceCreateUserRequest.cpp
  OAIUser_serviceCreateUserResponse.cpp
  OAIUser_serviceGetSettingsResponse.cpp
  OAIUser_serviceGetUserResponse.cpp
  OAIUser_serviceSettings.cpp
  OAIUser_serviceUpdateSettingsResponse.cpp
  OAIUser_serviceUpdateUserResponse.cpp
  OAIUser_serviceUser.cpp
  OAIUserServiceApi.cpp)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../common>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network
         Qt${QT_VERSION_MAJOR}::Gui OpenAPIQtCommon)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
  INCLUDES
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")

install(FILES ${HEADER_FILES}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}Targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
