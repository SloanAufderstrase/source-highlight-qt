cmake_minimum_required(VERSION 3.2.3)
project(srchiliteqt)

option(BUILDTEST "Build the test binary files" OFF)

include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/editor)
link_directories(${CMAKE_BINARY_DIR}/lib)
link_directories(${CMAKE_BINARY_DIR}/editor)

add_subdirectory(lib)
add_subdirectory(editor)

if(BUILDTEST)
add_subdirectory(tests)
endif(BUILDTEST)
