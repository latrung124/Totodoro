cmake_minimum_required(VERSION 3.5)

project(PomodoroQtOpenAPIClient)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Gui)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(
  ${PROJECT_NAME}
  OAIPomodoroServiceApi.h
  OAIPomodoroServiceCreateSessionBody.h
  OAIPomodoroServiceUpdateSessionBody.h
  OAIPomodoro_serviceCreateSessionResponse.h
  OAIPomodoro_serviceDeleteSessionResponse.h
  OAIPomodoro_serviceGetSessionByIdResponse.h
  OAIPomodoro_serviceGetSessionsResponse.h
  OAIPomodoro_servicePomodoroSession.h
  OAIPomodoro_serviceSessionStatus.h
  OAIPomodoro_serviceSessionType.h
  OAIPomodoro_serviceUpdateSessionResponse.h
  OAIPomodoroServiceApi.cpp
  OAIPomodoroServiceCreateSessionBody.cpp
  OAIPomodoroServiceUpdateSessionBody.cpp
  OAIPomodoro_serviceCreateSessionResponse.cpp
  OAIPomodoro_serviceDeleteSessionResponse.cpp
  OAIPomodoro_serviceGetSessionByIdResponse.cpp
  OAIPomodoro_serviceGetSessionsResponse.cpp
  OAIPomodoro_servicePomodoroSession.cpp
  OAIPomodoro_serviceSessionStatus.cpp
  OAIPomodoro_serviceSessionType.cpp
  OAIPomodoro_serviceUpdateSessionResponse.cpp)

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
          INCLUDEOAIPomodoroServiceApiS
          DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")

install(FILES ${HEADER_FILES}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}Targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
