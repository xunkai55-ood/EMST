cmake_minimum_required(VERSION 2.6)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(GENERATOR_SRC_LIST
    main.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(generator ${GENERATOR_SRC_LIST})