cmake_minimum_required(VERSION 3.22)
project(microservices)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DDB_SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/databases")

find_package(yaml-cpp REQUIRED)
find_package(httplib REQUIRED)
find_package(SQLiteCpp REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json REQUIRED)

file(GLOB GENERATED_SOURCES "generated/*.cpp")
file(GLOB GENERATED_HEADERS "generated/*.h")

set(SOURCES connection/IDatabaseConnection.h connection/SQLiteConnection.cpp
            connection/SQLiteConnection.h)

add_library(microservices STATIC ${SOURCES} ${GENERATED_SOURCES}
                                 ${GENERATED_HEADERS})

target_include_directories(
  microservices
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(microservices PUBLIC yaml-cpp httplib::httplib SQLiteCpp
                                           nlohmann_json::nlohmann_json)
