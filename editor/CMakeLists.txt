set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_library(sourceeditor
    SourceEditor.cpp
    LineNumberArea.cpp
) 

target_link_libraries(sourceeditor Qt5::Widgets)
target_include_directories(sourceeditor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
