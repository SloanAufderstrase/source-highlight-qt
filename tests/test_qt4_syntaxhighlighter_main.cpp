/*
 * test_qt4_syntaxhighlighter_main.cpp
 *
 * Check basic language definition file functionalities
 *
 *  Created on: Dec 3, 2008
 *      Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2008
 *  Copyright: See COPYING file that comes with this distribution
 */

#include <Qt4SyntaxHighlighter.h>
#include <Qt4TextFormatter.h>
#include <srchilite/instances.h>
#include <iostream>

#include "asserttestexit.h"

using namespace SrcHighlightQt;
using namespace srchilite;
using namespace std;

#undef main

static void printFormatter(const Qt5TextFormatter *qt4Formatter);

void printFormatter(const Qt5TextFormatter *qt4Formatter)
{
    cout << qt4Formatter->getElem() << ": ";
    const QTextCharFormat &format = qt4Formatter->getQTextCharFormat();
    if (format.fontWeight() == QFont::Bold)
        cout << "BOLD ";
    if (format.fontItalic())
        cout << "ITALIC ";
    if (format.fontUnderline())
        cout << "UNDERLINE ";
    cout << "foreground: " << format.foreground().color().name().toStdString();
    cout << " background: " << format.background().color().name().toStdString();
    cout << endl;
}

int main()
{
    Qt5SyntaxHighlighter *highlighter = new Qt5SyntaxHighlighter();

    highlighter->init("c.lang");

    FormatterManager *formatterManager = highlighter->getFormatterManager();

    Qt5TextFormatter *qt4Formatter =
        dynamic_cast<Qt5TextFormatter *> (formatterManager->getFormatter(
                "keyword").get());

    assertTrue(qt4Formatter != 0);

    printFormatter(qt4Formatter);

    // check that they do not share the same formatters (meaning their QTextCharFormat
    Qt5SyntaxHighlighter *highlighter2 = new Qt5SyntaxHighlighter(0);
    highlighter2->init("java.lang");

    assertTrue(
        &(qt4Formatter->getQTextCharFormat()) !=
        &(dynamic_cast<Qt5TextFormatter *> (highlighter2->getFormatterManager()->getFormatter(
                "keyword").get())->getQTextCharFormat()),
        "pointers should be different");

    // check that the Qt4TextFormatterMap has the same formatter
    Qt5TextFormatterMap formatterMap = highlighter->getQt5TextFormatterMap();

    Qt5TextFormatter *keywordFormatter = formatterMap["keyword"];

    assertEquals(
        &(qt4Formatter->getQTextCharFormat()),
        &(keywordFormatter->getQTextCharFormat()));

    delete highlighter;
    delete highlighter2;

    // to avoid leaks, clean source-highlight global instances
    srchilite::Instances::unload();

    return 0;
}
