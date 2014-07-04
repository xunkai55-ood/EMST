cmake_minimum_required(VERSION 2.6)

find_package(OpenCV REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(VIEWER_SRC_LIST
    main.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(viewer ${VIEWER_SRC_LIST})
target_link_libraries(viewer ${OpenCV_LIBS})