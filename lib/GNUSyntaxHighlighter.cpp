/*
 *  Copyright (C) 2008-2010  Lorenzo Bettini, http://www.lorenzobettini.it
 *  License: See COPYING file that comes with this distribution
 */
#include <QString>
#include "GNUSyntaxHighlighter.h"
#include <srchilite/regexrulefactory.h>
#include <srchilite/stylefileparser.h>
#include <srchilite/fileutil.h>
#include <srchilite/instances.h>

namespace SrcHighlightQt
{

GNUSyntaxHighlighter::GNUSyntaxHighlighter() :
    sourceHighlighter(0), readOnly(false), defaultToMonospace(true),
    formatterManager(0)
{

}

GNUSyntaxHighlighter::~GNUSyntaxHighlighter()
{
    if (formatterManager)
        delete formatterManager;
    if (sourceHighlighter)
        delete sourceHighlighter;
}

srchilite::LangDefManager *GNUSyntaxHighlighter::getLangDefManager() const
{
    return srchilite::Instances::getLangDefManager();
}

srchilite::LangMap *GNUSyntaxHighlighter::getLangMap() const
{
    // make sure the lang map is loaded before returning it
    srchilite::Instances::getLangMap()->open();
    return srchilite::Instances::getLangMap();
}

srchilite::LangMap *GNUSyntaxHighlighter::getOutLangMap() const
{
    // make sure the lang map is loaded before returning it
    srchilite::Instances::getOutLangMap()->open();
    return srchilite::Instances::getOutLangMap();
}

srchilite::HighlightStatePtr GNUSyntaxHighlighter::getHighlightState(
    const QString &file)
{
    return getLangDefManager()->getHighlightState(file.toStdString());
}

void GNUSyntaxHighlighter::initHighlighter(const QString &file)
{
    // delete the possible previous highlighter
    if (sourceHighlighter)
    {
        delete sourceHighlighter;
        sourceHighlighter = 0;
    }
    srchilite::HighlightStatePtr mainState = getHighlightState(file);
    sourceHighlighter = new srchilite::SourceHighlighter(mainState);
    sourceHighlighter->setFormatterManager(formatterManager);
    sourceHighlighter->setFormatterParams(&formatterParams);
    sourceHighlighter->setOptimize(false);

    langFile = file;
}

const QString GNUSyntaxHighlighter::getMappedFileName(const QString &lang)
{
    std::string file = getLangMap()->getMappedFileName(lang.toStdString());
    return QString(file.c_str());
}

const QStringList GNUSyntaxHighlighter::getLangNames()
{
    QStringList retList;
    std::set<std::string> langs = getLangMap()->getLangNames();
    for (std::set<std::string>::iterator it = langs.begin(); it != langs.end(); ++it) {
        retList << it->c_str();
    }
    return retList;
}

const QString GNUSyntaxHighlighter::getLangDefFileFromFileName(const QString &filename)
{
    std::string file = filename.toStdString();
    return QString(getLangMap()->getMappedFileNameFromFileName(file).c_str());
}

const TextFormatterMap &GNUSyntaxHighlighter::getTextFormatterMap(
    TextFormatterFactory &formatterFactory, const QString &styleFile)
{
    // the formatter factory can have been already initialized previously
    if (formatterFactory.getTextFormatterMap().size())
    {
        return formatterFactory.getTextFormatterMap();
    }

    string bgcolor;
    std::string styleStd = styleFile.toStdString();
    if (srchilite::get_file_extension(styleStd) == "css")
    {
        srchilite::StyleFileParser::parseCssStyleFile(styleStd,
                &formatterFactory, bgcolor);
    }
    else
    {
        srchilite::StyleFileParser::parseStyleFile(styleStd,
                &formatterFactory, bgcolor);
    }

    // make sure we default background to a standard color
    if (bgcolor.empty())
        bgcolor = "white";

    // we need to transform the color string
    // since it might be in source-highlight format and not html one
    backgroundColor = QString(TextFormatterFactory::colorMap.getColor(bgcolor).c_str());

    return formatterFactory.getTextFormatterMap();
}

void GNUSyntaxHighlighter::highlightLine(const QString &line,
        HighlightStateData *&stateData)
{
    if (stateData)
    {
        sourceHighlighter->setCurrentState(stateData->currentState);
        sourceHighlighter->setStateStack(stateData->stateStack);
    }
    else
    {
        // we must make sure to reset the highlighter to the initial state
        sourceHighlighter->setCurrentState(sourceHighlighter->getMainState());
        sourceHighlighter->clearStateStack();
    }

    // this does all the highlighting
    sourceHighlighter->highlightParagraph(line.toStdString());

    // if we're not in the main initial state...
    if (!sourceHighlighter->getStateStack()->empty())
    {
        // communicate this information to the QSyntaxHighlighter
        if (!stateData)
            stateData = new HighlightStateData();

        stateData->currentState = sourceHighlighter->getCurrentState();
        stateData->stateStack = sourceHighlighter->getStateStack();
    }
    else
    {
        // simply update the previous user data information
        if (stateData)
        {
            delete stateData;
            stateData = 0;
        }
    }
}

}
