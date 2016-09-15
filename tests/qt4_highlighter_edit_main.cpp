/*
 * qt4_highlighter_edit_main.cpp
 *
 * Differently from qt4_highlighter_example_main.cpp, this takes as the
 * first command line argument the filename to edit, and uses the
 * highlighting for the syntax detected from the filename itself
 * (e.g., it uses cpp.lang for foo.cpp, changelog.lang for ChangeLog, etc.)
 *
 *      Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2009
 *  Copyright: See COPYING file that comes with this distribution
 */

#include <Qt4SyntaxHighlighter.h>

#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QTextStream>
#include <QFile>

#include <iostream>

// TEXINFOINCLUDE
int main(int argc, char **argv) {
    QApplication app(argc, argv);

    if (argc <= 1) {
        std::cerr << "you must specify the file to edit" << std::endl;
        return 1;
    }

    QTextEdit *editor = new QTextEdit;
    srchiliteqt::Qt4SyntaxHighlighter *highlighter =
            new srchiliteqt::Qt4SyntaxHighlighter(editor->document());

    QMainWindow win(0);
    win.setCentralWidget(editor);

    QFile file(argv[1]);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << QString("Cannot read file %1:\n%2.") .arg(argv[1]) .arg(
                file.errorString()).toStdString() << std::endl;
        return 1;
    }

    if (!highlighter->initFromFileName(argv[1])) {
        std::cerr << "cannot find an highlighting scheme for " << argv[1]
                << std::endl;
        return 1;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    editor->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    win.setWindowTitle(QString("GNU Syntax"));
    win.resize(700, 512);
    win.show();

    return app.exec();
}
// TEXINFOINCLUDE
