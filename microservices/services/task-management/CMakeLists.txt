cmake_minimum_required(VERSION 3.22)
project(TaskManagement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PKGS
    protobuf
    yaml-cpp
    httplib
    SQLiteCpp
    OpenSSL::SSL
    OpenSSL::Crypto
    nlohmann_json)

foreach(pkg ${PKGS})
  find_package(${pkg} REQUIRED)
  if(NOT ${pkg}_FOUND)
    message(FATAL_ERROR "Package ${pkg} not found")
  endif()
endforeach()

set(SOURCES main.cpp TaskManagementService.h TaskManagementService.cpp)

add_executable(TaskManagementService ${SOURCES})
