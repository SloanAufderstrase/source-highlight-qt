/*
 *  Copyright (C) 2008-2010  Lorenzo Bettini, http://www.lorenzobettini.it
 *  License: See COPYING file that comes with this distribution
 */

#ifndef QT4SOURCEHIGHLIGHTSTYLEGENERATOR_H_
#define QT4SOURCEHIGHLIGHTSTYLEGENERATOR_H_

#include <QStringList>
#include <QList>

#include "Qt4TextFormatter.h"

namespace srchiliteqt {

/**
 * Provides functionalities to generate the contents for a source-highlight
 * style file.
 */
class Qt4SourceHighlightStyleGenerator {
public:
    /**
     * Generates a string list given a list of Qt4TextFormatter
     * @param formatters a list of Qt4TextFormatter
     * @param bgColor the background color for the document
     * @return a string list corresponding to the style file contents
     */
    static QStringList createStyleContents(
            QList<Qt4TextFormatter *> &formatters, const QString &bgColor = "");
};

}

#endif /* QT4SOURCEHIGHLIGHTSTYLEGENERATOR_H_ */
