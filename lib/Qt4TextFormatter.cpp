/*
 *  Copyright (C) 2008-2010  Lorenzo Bettini, http://www.lorenzobettini.it
 *  License: See COPYING file that comes with this distribution
 */

#include "Qt4TextFormatter.h"
#include "Qt4SyntaxHighlighter.h"
#include "QtColorMap.h"

#include <srchilite/formatterparams.h>

//#define SHOW_DEBUG_INFO 1

#ifdef SHOW_DEBUG_INFO
#include <iostream>
#define DEBUG_INFO(x,y) std::cout << x << y << std::endl;
#else
#define DEBUG_INFO(x,y)
#endif

namespace SrcHighlightQt
{

Qt5TextFormatter::Qt5TextFormatter(const std::string &elem_) :
    TextFormatter(elem_), qSyntaxHighlighter(0)
{
}

Qt5TextFormatter::~Qt5TextFormatter()
{
}

void Qt5TextFormatter::setQSyntaxHighlighter(
    QSyntaxHighlighter *qSyntaxHighlighter_)
{
    qSyntaxHighlighter
        = dynamic_cast<Qt5SyntaxHighlighter *> (qSyntaxHighlighter_);
}

void Qt5TextFormatter::format(const std::string &s,
                              const srchilite::FormatterParams *params)
{

    qSyntaxHighlighter->formatString(params->start, s.size(), textFormat);

    DEBUG_INFO (s + "\n", toString().toStdString());
}

void Qt5TextFormatter::setForegroundColor(const QColor &color)
{
    textFormat.setForeground(QBrush(color));
    foregroundColor = color;
}

void Qt5TextFormatter::setBackgroundColor(const QColor &color)
{
    textFormat.setBackground(QBrush(color));
    backgroundColor = color;
}

const QString Qt5TextFormatter::toString() const
{
    QString s = QString(getElem().c_str()) + ": ";
    const QTextCharFormat & format = getQTextCharFormat();
    if (format.fontWeight() == QFont::Bold)
        s += "BOLD ";
    if (format.fontItalic())
        s += "ITALIC ";
    if (format.fontUnderline())
        s += "UNDERLINE ";
    if (getForegroundColor().isValid())
        s += "foreground: " + format.foreground().color().name();
    else
        s += "no foreground";
    if (getBackgroundColor().isValid())
        s += " background: " + format.background().color().name();
    else
        s += " no background";
    s += "\n";

    return s;
}

const QString Qt5TextFormatter::toSourceHighlightStyleString() const
{
    QString s = QString(getElem().c_str()) + " ";
    const QTextCharFormat & format = getQTextCharFormat();
    std::string color;

    if (getForegroundColor().isValid())
    {
        color = colorMap.getColor(format.foreground().color().name().toStdString(), true);
        if (color[0] == '#')
            s += "\"" + QString(color.c_str()) + "\" ";
        else
            s += QString(color.c_str()) + " ";
    }

    if (getBackgroundColor().isValid())
    {
        s += "bg:";
        color = colorMap.getColor(format.background().color().name().toStdString(), true);
        if (color[0] == '#')
            s += "\"" + QString(color.c_str()) + "\" ";
        else
            s += QString(color.c_str()) + " ";
    }

    QString styleConstants;
    if (format.fontWeight() == QFont::Bold)
        styleConstants += "b";
    if (format.fontItalic())
        styleConstants += (styleConstants.size() ? ", " : "") + QString("i");
    if (format.fontUnderline())
        styleConstants += (styleConstants.size() ? ", " : "") + QString("u");
    if (isMonospace())
        styleConstants += (styleConstants.size() ? ", " : "") + QString("f");

    return s + styleConstants + ";";
}

}
