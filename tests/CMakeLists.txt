cmake_minimum_required(VERSION 3.2.3)
project(tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_Package(Qt5Core REQUIRED)

add_executable(qt4_highlighter_edit_main qt4_highlighter_edit_main.cpp)

target_link_libraries(qt4_highlighter_edit_main LINK_PUBLIC sourceeditor srchiliteqt -lsource-highlight Qt5::Widgets Qt5::Core)
