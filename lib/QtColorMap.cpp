/*
 *  Copyright (C) 2008-2010  Lorenzo Bettini, http://www.lorenzobettini.it
 *  License: See COPYING file that comes with this distribution
 */

#include "QtColorMap.h"

#include <srchilite/utils.h>

namespace SrcHighlightQt
{

QtColorMap::QtColorMap()
{
    (*this)["aliceblue"] = "#f0f8ff";
    (*this)["antiquewhite"] = "#faebd7";
    (*this)["beige"] = "#f5f5dc";
    (*this)["black"] = "#000000";
    (*this)["blanchedalmond"] = "#ffebcd";
    (*this)["blue"] = "#3333ff";
    (*this)["blueviolet"] = "#8a2be2";
    (*this)["brightgreen"] = "#33ff33";
    (*this)["brightorange"] = "#ff9900";
    (*this)["brown"] = "#660000";
    (*this)["burlywood"] = "#deb887";
    (*this)["cadetblue"] = "#5f9ea0";
    (*this)["chocolate"] = "#d2691e";
    (*this)["coral"] = "#ff7f50";
    (*this)["cornflowerblue"] = "#6495ed";
    (*this)["cyan"] = "#66ffff";
    (*this)["darkblue"] = "#000080";
    (*this)["darkgoldenrod"] = "#b8860b";
    (*this)["darkgreen"] = "#006400";
    (*this)["darkkhaki"] = "#bdb76b";
    (*this)["darkolivegreen"] = "#556b2f";
    (*this)["darkorange"] = "#ff8c00";
    (*this)["darkorchid"] = "#9932cc";
    (*this)["darkred"] = "#990000";
    (*this)["darksalmon"] = "#e9967a";
    (*this)["darkseagreen"] = "#8fbc8f";
    (*this)["darkslateblue"] = "#483d8b";
    (*this)["darkslategray"] = "#2f4f4f";
    (*this)["darkturquoise"] = "#00ced1";
    (*this)["darkviolet"] = "#9400d3";
    (*this)["dimgray"] = "#696969";
    (*this)["firebrick"] = "#b22222";
    (*this)["floralwhite"] = "#fffaf0";
    (*this)["forestgreen"] = "#228b22";
    (*this)["gainsboro"] = "#dcdcdc";
    (*this)["ghostwhite"] = "#f8f8ff";
    (*this)["goldenrod"] = "#daa520";
    (*this)["gray"] = "#808080";
    (*this)["green"] = "#33cc00";
    (*this)["greenyellow"] = "#adff2f";
    (*this)["hotpink"] = "#ff69b4";
    (*this)["indianred"] = "#cd5c5c";
    (*this)["khaki"] = "#f0e68c";
    (*this)["lavender"] = "#e6e6fa";
    (*this)["lawngreen"] = "#7cfc00";
    (*this)["light"] = "#eedd82";
    (*this)["lightblue"] = "#add8e6";
    (*this)["lightcoral"] = "#f08080";
    (*this)["lightgoldenrodyellow"] = "#fafad2";
    (*this)["lightgray"] = "#d3d3d3";
    (*this)["lightpink"] = "#ffb6c1";
    (*this)["lightseagreen"] = "#20b2aa";
    (*this)["lightskyblue"] = "#87cefa";
    (*this)["lightslateblue"] = "#8470ff";
    (*this)["lightslategray"] = "#778899";
    (*this)["lightsteelblue"] = "#b0c4de";
    (*this)["limegreen"] = "#32cd32";
    (*this)["linen"] = "#faf0e6";
    (*this)["magenta"] = "#ff00ff";
    (*this)["maroon"] = "#b03060";
    (*this)["medium"] = "#66cdaa";
    (*this)["mediumblue"] = "#0000cd";
    (*this)["mediumorchid"] = "#ba55d3";
    (*this)["mediumpurple"] = "#9370db";
    (*this)["mediumseagreen"] = "#3cb371";
    (*this)["mediumslateblue"] = "#7b68ee";
    (*this)["mediumspringgreen"] = "#00fa9a";
    (*this)["mediumturquoise"] = "#48d1cc";
    (*this)["mediumvioletred"] = "#c71585";
    (*this)["midnightblue"] = "#191970";
    (*this)["mintcream"] = "#f5fffa";
    (*this)["moccasin"] = "#ffe4b5";
    (*this)["oldlace"] = "#fdf5e6";
    (*this)["olivedrab"] = "#6b8e23";
    (*this)["orange"] = "#ff6600";
    (*this)["orchid"] = "#da70d6";
    (*this)["pale"] = "#db7093";
    (*this)["palegoldenrod"] = "#eee8aa";
    (*this)["palegreen"] = "#98fb98";
    (*this)["paleturquoise"] = "#afeeee";
    (*this)["papayawhip"] = "#ffefd5";
    (*this)["pink"] = "#cc33cc";
    (*this)["plum"] = "#dda0dd";
    (*this)["powderblue"] = "#b0e0e6";
    (*this)["purple"] = "#993399";
    (*this)["rebeccapurple"] = "#663399";
    (*this)["red"] = "#ff0000";
    (*this)["rosybrown"] = "#bc8f8f";
    (*this)["royalblue"] = "#4169e1";
    (*this)["saddlebrown"] = "#8b4513";
    (*this)["salmon"] = "#fa8072";
    (*this)["sandybrown"] = "#f4a460";
    (*this)["sienna"] = "#a0522d";
    (*this)["skyblue"] = "#87ceeb";
    (*this)["slateblue"] = "#6a5acd";
    (*this)["slategray"] = "#708090";
    (*this)["steelblue"] = "#4682b4";
    (*this)["tan"] = "#d2b48c";
    (*this)["teal"] = "#008080";
    (*this)["thistle"] = "#d8bfd8";
    (*this)["turquoise"] = "#40e0d0";
    (*this)["violet"] = "#ee82ee";
    (*this)["violetred"] = "#d02090";
    (*this)["wheat"] = "#f5deb3";
    (*this)["white"] = "#ffffff";
    (*this)["whitesmoke"] = "#f5f5f5";
    (*this)["yellow"] = "#ffcc00";
    (*this)["yellowgreen"] = "#9acd32";
}

QtColorMap::~QtColorMap()
{
}

std::string QtColorMap::getColor(const std::string &color, const bool &rgb) const
{
    if (!rgb) {
        if (color[0] == '"' && color[color.length()-1] == '"')
        {
            return color.substr(1, color.length()-2);
        }
        else
        {
            return (*this).value(QString(color.c_str())).toStdString();
        }
    } else {
        QHash<QString, QString>::const_iterator i;
        for(i = this->begin(); i != this->end(); ++i) {
            if(i.value().compare(QString(color.data()), Qt::CaseInsensitive) == 0) {
                return i.key().toStdString();
            }
        }
        return color.data();
    }
}

}
