cmake_minimum_required(VERSION 3.22)
project(microservices)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DDB_SOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/databases")

find_package(Protobuf REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(httplib REQUIRED)
find_package(SQLiteCpp REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json REQUIRED)

file(GLOB_RECURSE PROTO_FILES proto/*.proto)
# Generate protobuf source and header files Handle the case where no .proto
# files are found
if(PROTO_FILES STREQUAL "")
  message(
    WARNING
      "No .proto files found in the proto directory. Skipping protobuf generation."
  )
  set(PROTO_SOURCES "") # Set an empty variable for PROTO_SOURCES
else()
  # Generate protobuf source and header files
  protobuf_generate(
    LANGUAGE
    cpp
    OUT_VAR
    PROTO_SOURCES
    IMPORT_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/proto
    PROTOS
    ${PROTO_FILES})
endif()

set(SOURCES
    connection/IDatabaseConnection.h connection/SQLiteConnection.cpp
    connection/SQLiteConnection.h service-discovery/IServiceDiscovery.h
    service-discovery/ConsulDiscovery.cpp service-discovery/ConsulDiscovery.h)

add_library(microservices STATIC ${SOURCES} ${PROTO_SOURCES})

target_include_directories(
  microservices
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  microservices PUBLIC protobuf::libprotobuf yaml-cpp httplib::httplib
                       SQLiteCpp nlohmann_json::nlohmann_json)

# other services
add_subdirectory(services)
