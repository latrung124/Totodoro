cmake_minimum_required(VERSION 3.22)
project(gateway)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

add_definitions(-DDB_SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/databases")

find_package(yaml-cpp REQUIRED)
find_package(httplib REQUIRED)
find_package(SQLiteCpp REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_subdirectory(generated/pomodoro_service.swagger_client/client)
add_subdirectory(generated/user_service.swagger_client/client)
add_subdirectory(generated/task_management_service.swagger_client/client)

set(GATEWAY_HEADERS
    connection/IDatabaseConnection.h
    connection/SQLiteConnection.h
    factory/ApiClientFactory.h
    factory/RouteHandlerFactory.h
    factory/ApiGatewayManagerFactory.h
    factory/ApiCommandFactory.h
    helper/TimeTransformer.h
    helper/SessionDataTransformer.h
    common/CommonDefine.h
    common/ApiResponse.h
    common/UserProperties.h
    common/TaskProperties.h
    common/PomodoroProperties.h
    command/IApiCommand.h
    command/pomodoro/CreateSessionCommand.h
    command/pomodoro/GetSessionByIdCommand.h
    command/pomodoro/UpdateSessionCommand.h
    command/pomodoro/GetSessionsCommand.h
    command/pomodoro/DeleteSessionCommand.h
    command/taskmanagement/CreateTaskGroupCommand.h
    command/taskmanagement/GetTaskGroupsCommand.h
    command/taskmanagement/DeleteTaskGroupCommand.h
    command/taskmanagement/UpdateTaskGroupCommand.h
    command/taskmanagement/CreateTaskCommand.h
    command/taskmanagement/DeleteTaskCommand.h
    command/taskmanagement/GetTasksCommand.h
    command/taskmanagement/UpdateTaskCommand.h
    command/user/CreateUserCommand.h
    command/user/GetUserCommand.h
    command/user/UpdateUserCommand.h
    command/user/GetSettingsCommand.h
    command/user/UpdateSettingsCommand.h
    manager/IApiGatewayManager.h
    manager/UserApiGatewayManager.h
    manager/TaskManagementApiGatewayManager.h
    manager/PomodoroApiGatewayManager.h
    routes/IRouteHandler.h
    routes/RequestRouter.h
    routes/SessionRouteHandler.h
    routes/UserRouteHandler.h
    routes/TaskManagementRouteHandler.h
    handler/IResponseHandler.h
    handler/JsonResponseHandler.h
    processor/AsyncRequestProcessor.h
    controller/PomodoroOpenApiController.h
    Gateway.h)

set(GATEWAY_SOURCES
    connection/SQLiteConnection.cpp
    factory/ApiClientFactory.cpp
    factory/RouteHandlerFactory.cpp
    factory/ApiGatewayManagerFactory.cpp
    handler/JsonResponseHandler.cpp
    helper/TimeTransformer.cpp
    helper/SessionDataTransformer.cpp
    common/PomodoroProperties.cpp
    common/TaskProperties.cpp
    common/UserProperties.cpp
    command/pomodoro/CreateSessionCommand.cpp
    command/pomodoro/GetSessionByIdCommand.cpp
    command/pomodoro/UpdateSessionCommand.cpp
    command/pomodoro/GetSessionsCommand.cpp
    command/pomodoro/DeleteSessionCommand.cpp
    command/taskmanagement/CreateTaskGroupCommand.cpp
    command/taskmanagement/GetTaskGroupsCommand.cpp
    command/taskmanagement/DeleteTaskGroupCommand.cpp
    command/taskmanagement/UpdateTaskGroupCommand.cpp
    command/taskmanagement/CreateTaskCommand.cpp
    command/taskmanagement/DeleteTaskCommand.cpp
    command/taskmanagement/GetTasksCommand.cpp
    command/taskmanagement/UpdateTaskCommand.cpp
    command/user/CreateUserCommand.cpp
    command/user/GetUserCommand.cpp
    command/user/UpdateUserCommand.cpp
    command/user/GetSettingsCommand.cpp
    command/user/UpdateSettingsCommand.cpp
    manager/UserApiGatewayManager.cpp
    manager/TaskManagementApiGatewayManager.cpp
    manager/PomodoroApiGatewayManager.cpp
    routes/RequestRouter.cpp
    routes/SessionRouteHandler.cpp
    routes/UserRouteHandler.cpp
    routes/TaskManagementRouteHandler.cpp
    processor/AsyncRequestProcessor.cpp
    controller/PomodoroOpenApiController.cpp
    Gateway.cpp)

add_library(gateway STATIC ${GATEWAY_SOURCES})

target_sources(gateway PRIVATE ${GATEWAY_HEADERS})

target_include_directories(
  gateway
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
         $<INSTALL_INTERFACE:include>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  gateway
  PUBLIC Qt6::Core Qt6::Network yaml-cpp httplib::httplib SQLiteCpp
         nlohmann_json::nlohmann_json
  PRIVATE PomodoroQtOpenAPIClient UserQtOpenAPIClient
          TaskManagementQtOpenAPIClient)

include(GNUInstallDirs)
install(
  TARGETS gateway
  EXPORT gateway-targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # For static libs
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # For shared libs
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # For executables
)

install(FILES ${GATEWAY_HEADERS} DESTINATION include/gateway)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  Config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/gatewayConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/gateway")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/gatewayConfig.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/gateway")
install(
  EXPORT gateway-targets
  FILE gateway-targets.cmake
  NAMESPACE gateway::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/gateway)
