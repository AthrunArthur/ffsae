project(ffsae)
cmake_minimum_required(VERSION 2.8)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

MESSAGE(STATUS "This is BINARY dir" ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir" ${PROJECT_SOURCE_DIR})
add_definitions(-std=c++11)

set(ffsae_dir ${PROJECT_SOURCE_DIR}/src)
set(ffsae_lib_dir ${LIBRARY_OUTPUT_PATH})

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(tools)

