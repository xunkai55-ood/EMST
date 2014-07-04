include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_LIST
    main.cpp
    enp/brute_force_enp.cpp
    mst/mst.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(emst ${SRC_LIST})

add_subdirectory(viewer)
add_subdirectory(generator)