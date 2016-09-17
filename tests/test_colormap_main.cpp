/*
 * test_colormap_main.cpp
 *
 * Check color map
 *
 *      Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2008
 *  Copyright: See COPYING file that comes with this distribution
 */

#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QThread>
#include "QtColorMap.h"

using namespace SrcHighlightQt;
using namespace std;

int main()
{
    QtColorMap colorMap;
    QTextStream in(stdin);
    qDebug() << "Total items: (" << colorMap.count() << ")" << endl << "Press return to continue...";

    in.readLine();
    QStringList keys = colorMap.keys();
    QStringList vals = colorMap.values();
    for(int i = 0; i < keys.size(); i++) {
        qDebug() << "Forward/Reverse #" << i+1 << ": " << colorMap.getColor(keys[i].toStdString()).c_str()
        << " / " << colorMap.getColor(vals[i].toStdString(),true).c_str();
    }

    return 0;
}
