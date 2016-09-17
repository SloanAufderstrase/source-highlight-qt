/*
 *  Copyright (C) 2008-2010  Lorenzo Bettini, http://www.lorenzobettini.it
 *  License: See COPYING file that comes with this distribution
 */

#include "Qt4SourceHighlightStyleGenerator.h"
#include "QtColorMap.h"

namespace SrcHighlightQt
{

QStringList Qt5SourceHighlightStyleGenerator::createStyleContents(QList<
        Qt5TextFormatter *> &formatters, const QString &bgColor)
{
    QtColorMap colorMap;
    QStringList l;

    if (!bgColor.isEmpty())
    {
        std::string color = colorMap.getColor(bgColor.toStdString(), true);
        if (color[0] == '#')
            l << "bgcolor \"" + QString(color.c_str()) + "\";";
        else
            l << "bgcolor " + QString(color.c_str()) + ";";
    }

    for (QList<Qt5TextFormatter *>::const_iterator it = formatters.begin(); it
            != formatters.end(); ++it)
    {
        l << (*it)->toSourceHighlightStyleString();
    }

    return l;
}

}
