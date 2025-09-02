cmake_minimum_required(VERSION 3.5)

project(TaskManagementQtOpenAPIClient)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Gui)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(
  ${PROJECT_NAME}
  OAIProtobufAny.h
  OAIRpcStatus.h
  OAITaskManagementServiceCreateTaskBody.h
  OAITaskManagementServiceUpdateTaskBody.h
  OAITaskManagementServiceUpdateTaskGroupBody.h
  OAITask_managementCreateTaskGroupRequest.h
  OAITask_managementCreateTaskGroupResponse.h
  OAITask_managementCreateTaskResponse.h
  OAITask_managementDeleteTaskGroupResponse.h
  OAITask_managementDeleteTaskResponse.h
  OAITask_managementGetTaskGroupsResponse.h
  OAITask_managementGetTasksResponse.h
  OAITask_managementTask.h
  OAITask_managementTaskGroup.h
  OAITask_managementTaskGroupPriority.h
  OAITask_managementTaskGroupStatus.h
  OAITask_managementTaskPriority.h
  OAITask_managementTaskStatus.h
  OAITask_managementUpdateTaskGroupResponse.h
  OAITask_managementUpdateTaskResponse.h
  OAITaskManagementServiceApi.h
  OAIHelpers.h
  OAIHttpRequest.h
  OAIObject.h
  OAIEnum.h
  OAIHttpFileElement.h
  OAIServerConfiguration.h
  OAIServerVariable.h
  OAIOauth.h
  OAIProtobufAny.cpp
  OAIRpcStatus.cpp
  OAITaskManagementServiceCreateTaskBody.cpp
  OAITaskManagementServiceUpdateTaskBody.cpp
  OAITaskManagementServiceUpdateTaskGroupBody.cpp
  OAITask_managementCreateTaskGroupRequest.cpp
  OAITask_managementCreateTaskGroupResponse.cpp
  OAITask_managementCreateTaskResponse.cpp
  OAITask_managementDeleteTaskGroupResponse.cpp
  OAITask_managementDeleteTaskResponse.cpp
  OAITask_managementGetTaskGroupsResponse.cpp
  OAITask_managementGetTasksResponse.cpp
  OAITask_managementTask.cpp
  OAITask_managementTaskGroup.cpp
  OAITask_managementTaskGroupPriority.cpp
  OAITask_managementTaskGroupStatus.cpp
  OAITask_managementTaskPriority.cpp
  OAITask_managementTaskStatus.cpp
  OAITask_managementUpdateTaskGroupResponse.cpp
  OAITask_managementUpdateTaskResponse.cpp
  OAITaskManagementServiceApi.cpp
  OAIHelpers.cpp
  OAIHttpRequest.cpp
  OAIHttpFileElement.cpp
  OAIOauth.cpp)

target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network
         Qt${QT_VERSION_MAJOR}::Gui)

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
