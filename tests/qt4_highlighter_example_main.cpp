/*
 * qt4_highlighter_example_main.cpp
 *
 *      Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2009
 *  Copyright: See COPYING file that comes with this distribution
 */

#include <Qt4SyntaxHighlighter.h>

#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>

#include <iostream>

#ifndef BASEDIR
#define BASEDIR "/usr/share/source-highlight/"
#endif

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QTextEdit *editor = new QTextEdit;
    srchiliteqt::Qt4SyntaxHighlighter *highlighter =
            new srchiliteqt::Qt4SyntaxHighlighter(0);


    if (argc > 1)
        highlighter->init(argv[1]);
    else {
        std::cout << "using " << BASEDIR "cpp.lang" << std::endl;
        highlighter->init(BASEDIR "cpp.lang");
    }

    highlighter->setDocument(editor->document());

    QMainWindow win(0);
    win.setCentralWidget(editor);

    win.setWindowTitle(QString("GNU Syntax Highlighter (using ") +
            QString("Test") + 
		       QString(")"));
    win.resize(700, 512);
    win.show();

    return app.exec();
}
