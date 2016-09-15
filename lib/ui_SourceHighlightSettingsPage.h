/********************************************************************************
** Form generated from reading UI file 'SourceHighlightSettingsPage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCEHIGHLIGHTSETTINGSPAGE_H
#define UI_SOURCEHIGHLIGHTSETTINGSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SourceHighlightSettingsPage
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLineEdit *sourceHighlightDataDirLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *browseButton;
    QPushButton *defaultButton;
    QLabel *errorLabel;
    QLabel *okLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SourceHighlightSettingsPage)
    {
        if (SourceHighlightSettingsPage->objectName().isEmpty())
            SourceHighlightSettingsPage->setObjectName(QStringLiteral("SourceHighlightSettingsPage"));
        SourceHighlightSettingsPage->resize(400, 300);
        gridLayout = new QGridLayout(SourceHighlightSettingsPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(SourceHighlightSettingsPage);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        sourceHighlightDataDirLineEdit = new QLineEdit(SourceHighlightSettingsPage);
        sourceHighlightDataDirLineEdit->setObjectName(QStringLiteral("sourceHighlightDataDirLineEdit"));

        verticalLayout->addWidget(sourceHighlightDataDirLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(197, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        browseButton = new QPushButton(SourceHighlightSettingsPage);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout->addWidget(browseButton);

        defaultButton = new QPushButton(SourceHighlightSettingsPage);
        defaultButton->setObjectName(QStringLiteral("defaultButton"));

        horizontalLayout->addWidget(defaultButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 2);

        errorLabel = new QLabel(SourceHighlightSettingsPage);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        errorLabel->setFont(font);

        gridLayout->addWidget(errorLabel, 2, 0, 1, 2);

        okLabel = new QLabel(SourceHighlightSettingsPage);
        okLabel->setObjectName(QStringLiteral("okLabel"));

        gridLayout->addWidget(okLabel, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 193, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(sourceHighlightDataDirLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(SourceHighlightSettingsPage);

        QMetaObject::connectSlotsByName(SourceHighlightSettingsPage);
    } // setupUi

    void retranslateUi(QWidget *SourceHighlightSettingsPage)
    {
        SourceHighlightSettingsPage->setWindowTitle(QApplication::translate("SourceHighlightSettingsPage", "Form", 0));
        label->setText(QApplication::translate("SourceHighlightSettingsPage", "Source-highlight's files path", 0));
#ifndef QT_NO_TOOLTIP
        sourceHighlightDataDirLineEdit->setToolTip(QApplication::translate("SourceHighlightSettingsPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Sets the path where source-highlight searches for all its configuration files (e.g., .lang, .outlang, etc.); this basically corresponds to source-highlight's <span style=\" font-weight:600;\">--data-dir</span> command line option.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        browseButton->setText(QApplication::translate("SourceHighlightSettingsPage", "Browse...", 0));
#ifndef QT_NO_TOOLTIP
        defaultButton->setToolTip(QApplication::translate("SourceHighlightSettingsPage", "Use the default (hardcoded) value from the source-highlight library", 0));
#endif // QT_NO_TOOLTIP
        defaultButton->setText(QApplication::translate("SourceHighlightSettingsPage", "Default", 0));
        errorLabel->setText(QApplication::translate("SourceHighlightSettingsPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">The path is not a valid source-highlight's path</span></p></body></html>", 0));
        okLabel->setText(QApplication::translate("SourceHighlightSettingsPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00aa00;\">Valid source-highlight path</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class SourceHighlightSettingsPage: public Ui_SourceHighlightSettingsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCEHIGHLIGHTSETTINGSPAGE_H
