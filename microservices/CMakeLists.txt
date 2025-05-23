cmake_minimum_required(VERSION 3.22)
project(microservices-system)

# Run script to install conan dependencies
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/conan_done.txt")
  execute_process(COMMAND conan remote add conancenter https://center.conan.io
                          --force RESULT_VARIABLE CONAN_REMOTE_RESULT)
  if(CONAN_REMOTE_RESULT)
    message(
      FATAL_ERROR
        "Failed to add conan remote with error code ${CONAN_REMOTE_RESULT}")
  endif()

  execute_process(
    COMMAND conan install . --build=missing --remote=conancenter
            --output-folder=${CMAKE_CURRENT_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE CONAN_RESULT)
  if(CONAN_RESULT)
    message(FATAL_ERROR "Conan install failed with error code ${CONAN_RESULT}")
  endif()
  message(STATUS "Conan dependencies installed successfully.")

  file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/conan_done.txt" "")
endif()

# Run command set conan build environment
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conanbuild.bat")
  message(
    FATAL_ERROR "conanbuild.bat not found. Please run 'conan install .' first.")
endif()
# Set up the build environment for conan
if(WIN32)
  execute_process(
    COMMAND cmd /c conanbuild.bat
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    RESULT_VARIABLE CONAN_BUILD_RESULT)
else()
  message(FATAL_ERROR "This script is intended to be run on Windows.")
endif()

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DDB_SOURCE_PATH="${CMAKE_SOURCE_DIR}/databases")

find_package(protobuf REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(httplib REQUIRED)
find_package(SQLiteCpp REQUIRED)
find_package(nlohmann_json REQUIRED)

file(GLOB_RECURSE PROTO_FILES common/proto/*.proto)
# Generate protobuf source and header files protobuf_generate( LANGUAGE cpp
# OUT_VAR PROTO_SOURCES IMPORT_DIRS ${CMAKE_SOURCE_DIR}/common/proto PROTOS
# ${PROTO_FILES} )

set(COMMON_SOURCES
    common/database/IDatabaseConnection.h
    common/database/SQLiteConnection.h
    common/database/SQLiteConnection.cpp
    common/service-discovery/IServiceDiscovery.h
    common/service-discovery/ConsulDiscovery.h
    common/service-discovery/ConsulDiscovery.cpp
    common/ConfigManager.h
    common/ConfigManager.cpp)

# common library defines the common code shared by all services: proto messages,
# config manager, etc.
add_library(common STATIC ${PROTO_SOURCES} ${COMMON_SOURCES})

target_include_directories(
  common
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  common PUBLIC httplib::httplib nlohmann_json::nlohmann_json
                protobuf::protobuf yaml-cpp SQLiteCpp)

# Define each service as an executable target.
set(SERVICES TaskManagement)
set(TASK_MANAGEMENT_SOURCES services/task-management/main.cpp)

add_executable(TaskManagement_service ${TASK_MANAGEMENT_SOURCES})

target_include_directories(
  TaskManagement_service
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

foreach(SERVICE ${SERVICES})
  target_link_libraries(${SERVICE}_service common)
endforeach()

# Install targets
install(
  TARGETS common TaskManagement_service
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
