/********************************************************************************
** Form generated from reading UI file 'SourceHighlightSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCEHIGHLIGHTSETTINGSDIALOG_H
#define UI_SOURCEHIGHLIGHTSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "SourceHighlightSettingsPage.h"

QT_BEGIN_NAMESPACE

class Ui_SourceHighlightSettingsDialog
{
public:
    QGridLayout *gridLayout;
    SrcHighlightQt::SourceHighlightSettingsPage *sourceHighlightSettingsPage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SourceHighlightSettingsDialog)
    {
        if (SourceHighlightSettingsDialog->objectName().isEmpty())
            SourceHighlightSettingsDialog->setObjectName(QStringLiteral("SourceHighlightSettingsDialog"));
        SourceHighlightSettingsDialog->resize(400, 300);
        gridLayout = new QGridLayout(SourceHighlightSettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sourceHighlightSettingsPage = new SrcHighlightQt::SourceHighlightSettingsPage(SourceHighlightSettingsDialog);
        sourceHighlightSettingsPage->setObjectName(QStringLiteral("sourceHighlightSettingsPage"));

        gridLayout->addWidget(sourceHighlightSettingsPage, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SourceHighlightSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SourceHighlightSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SourceHighlightSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SourceHighlightSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SourceHighlightSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SourceHighlightSettingsDialog)
    {
        SourceHighlightSettingsDialog->setWindowTitle(QApplication::translate("SourceHighlightSettingsDialog", "Source-Highlight Settings", 0));
    } // retranslateUi

};

namespace Ui
{
class SourceHighlightSettingsDialog: public Ui_SourceHighlightSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCEHIGHLIGHTSETTINGSDIALOG_H
