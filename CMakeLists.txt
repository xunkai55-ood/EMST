cmake_minimum_required(VERSION 2.6)

project(OOP1) 
message(STATUS "OOP1: ${PROJECT_SOURCE_DIR}")
message(STATUS "OOP1: ${PROJECT_BINARY_DIR}")

set(CMAKE_BUILD_TYPE DEBUG) 

message("Build: ${CMAKE_BUILD_TYPE}")
message("Flags: ${CMAKE_CXX_FLAGS_DEBUG}")

add_subdirectory(src) 
