set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_library(srchiliteqt
    TextEditHighlighted.cpp
    GNUSyntaxHighlighter.cpp
    Qt4TextFormatterFactory.cpp
    QtColorMap.cpp
    StyleComboBox.cpp
    Qt4SourceHighlightStyleGenerator.cpp
    ParagraphMap.cpp
    SourceHighlightExceptionBox.cpp
    Qt4TextFormatter.cpp
    TextFormatter.cpp
    Qt4SyntaxHighlighter.cpp
    OutputFormatComboBox.cpp
    TextFormatterFactory.cpp
    MainColorForm.cpp
    ColorDialog.cpp
    LanguageElemColorForm.cpp
    LanguageComboBox.cpp
    SourceHighlightSettingsPage.cpp
    SourceHighlightSettingsDialog.cpp
) 

target_link_libraries(srchiliteqt Qt5::Widgets)
target_include_directories(srchiliteqt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
