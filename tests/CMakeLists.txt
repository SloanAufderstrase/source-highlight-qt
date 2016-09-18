cmake_minimum_required(VERSION 3.2.3)
project(tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_Package(Qt5Core REQUIRED)

add_executable(example example.cpp)

target_link_libraries(example LINK_PUBLIC 
    sourceeditor 
    srchiliteqt 
    -lsource-highlight 
    Qt5::Widgets 
    Qt5::Core)
