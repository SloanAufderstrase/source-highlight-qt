/*
 *  Copyright (C) 2008-2010  Lorenzo Bettini, http://www.lorenzobettini.it
 *  License: See COPYING file that comes with this distribution
 */

#ifndef QTCOLORMAP_H_
#define QTCOLORMAP_H_

#include <QHash>
#include <string>

namespace SrcHighlightQt
{

/**
 * Map for source-highlight colors into qt colors (actually, into the
 * format "#RRGGBB")
 */
class QtColorMap : public QHash<QString, QString>
{
public:
    QtColorMap();
    ~QtColorMap();

    /**
     * Returns the color associated to the passed string (if the
     * string is already of the shape "#RRGGBB", then it returns the
     * string "#RRGGBB" itself, without the quotes)
     * @param color
     * @return the color associated to the passed string
     */
    std::string getColor(const std::string &color, const bool &rgb = false) const;
};

}

#endif /* QTCOLORMAP_H_ */
