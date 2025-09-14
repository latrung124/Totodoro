cmake_minimum_required(VERSION 3.22)
project(gateway)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DDB_SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/databases")

find_package(yaml-cpp REQUIRED)
find_package(httplib REQUIRED)
find_package(SQLiteCpp REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(generated/pomodoro_service.swagger_client/client)
add_subdirectory(generated/user_service.swagger_client/client)
add_subdirectory(generated/task_management_service.swagger_client/client)

set(GATEWAY_HEADERS
    connection/IDatabaseConnection.h
    connection/SQLiteConnection.h
    factory/ApiClientFactory.h
    factory/RouteHandlerFactory.h
    helper/TimeTransformer.h
    helper/SessionDataTransformer.h
    common/CommonDefine.h
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
    routes/IRouteHandler.h
    routes/RequestRouter.h
    routes/SessionRouteHandler.h
    handler/IResponseHandler.h
    handler/JsonResponseHandler.h
    processor/AsyncRequestProcessor.h
    controller/PomodoroOpenApiController.h
    Gateway.h)

set(GATEWAY_SOURCES
    connection/SQLiteConnection.cpp
    factory/ApiClientFactory.cpp
    factory/RouteHandlerFactory.cpp
    handler/JsonResponseHandler.cpp
    helper/TimeTransformer.cpp
    helper/SessionDataTransformer.cpp
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
    routes/RequestRouter.cpp
    routes/SessionRouteHandler.cpp
    processor/AsyncRequestProcessor.cpp
    controller/PomodoroOpenApiController.cpp
    Gateway.cpp)

add_library(gateway STATIC ${GATEWAY_SOURCES} ${GATEWAY_HEADERS})

target_include_directories(
  gateway
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/connection
    ${CMAKE_CURRENT_SOURCE_DIR}/controller
    ${CMAKE_CURRENT_SOURCE_DIR}/config
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/helper
    ${CMAKE_CURRENT_SOURCE_DIR}/command
    ${CMAKE_CURRENT_SOURCE_DIR}/command/pomodoro
    ${CMAKE_CURRENT_SOURCE_DIR}/factory
    ${CMAKE_CURRENT_SOURCE_DIR}/processor
    ${CMAKE_CURRENT_SOURCE_DIR}/handler
    ${CMAKE_CURRENT_SOURCE_DIR}/routes
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/pomodoro_service.swagger_client/client
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/user_service.swagger_client/client
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/task_management_service.swagger_client/client
)

target_link_libraries(
  gateway
  PUBLIC Qt6::Core
         Qt6::Network
         yaml-cpp
         httplib::httplib
         SQLiteCpp
         nlohmann_json::nlohmann_json
         PomodoroQtOpenAPIClient
         UserQtOpenAPIClient
         TaskManagementQtOpenAPIClient)

include(GNUInstallDirs)
install(
  TARGETS gateway
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
