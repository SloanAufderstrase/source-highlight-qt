/********************************************************************************
** Form generated from reading UI file 'LanguageElemColorForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGEELEMCOLORFORM_H
#define UI_LANGUAGEELEMCOLORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LanguageElemColorForm
{
public:
    QGridLayout *gridLayout;
    QLabel *colorLabel;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *colorButton;
    QToolButton *backgroundColorButton;
    QCheckBox *boldCheckBox;
    QCheckBox *italicCheckBox;
    QCheckBox *underlineCheckBox;
    QCheckBox *monospaceCheckBox;

    void setupUi(QWidget *LanguageElemColorForm)
    {
        if (LanguageElemColorForm->objectName().isEmpty())
            LanguageElemColorForm->setObjectName(QStringLiteral("LanguageElemColorForm"));
        LanguageElemColorForm->resize(543, 59);
        gridLayout = new QGridLayout(LanguageElemColorForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        colorLabel = new QLabel(LanguageElemColorForm);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));

        gridLayout->addWidget(colorLabel, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(4, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        colorButton = new QToolButton(LanguageElemColorForm);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        gridLayout->addWidget(colorButton, 0, 2, 1, 1);

        backgroundColorButton = new QToolButton(LanguageElemColorForm);
        backgroundColorButton->setObjectName(QStringLiteral("backgroundColorButton"));

        gridLayout->addWidget(backgroundColorButton, 0, 3, 1, 1);

        boldCheckBox = new QCheckBox(LanguageElemColorForm);
        boldCheckBox->setObjectName(QStringLiteral("boldCheckBox"));

        gridLayout->addWidget(boldCheckBox, 0, 4, 1, 1);

        italicCheckBox = new QCheckBox(LanguageElemColorForm);
        italicCheckBox->setObjectName(QStringLiteral("italicCheckBox"));

        gridLayout->addWidget(italicCheckBox, 0, 5, 1, 1);

        underlineCheckBox = new QCheckBox(LanguageElemColorForm);
        underlineCheckBox->setObjectName(QStringLiteral("underlineCheckBox"));

        gridLayout->addWidget(underlineCheckBox, 0, 6, 1, 1);

        monospaceCheckBox = new QCheckBox(LanguageElemColorForm);
        monospaceCheckBox->setObjectName(QStringLiteral("monospaceCheckBox"));

        gridLayout->addWidget(monospaceCheckBox, 0, 7, 1, 1);


        retranslateUi(LanguageElemColorForm);

        QMetaObject::connectSlotsByName(LanguageElemColorForm);
    } // setupUi

    void retranslateUi(QWidget *LanguageElemColorForm)
    {
        LanguageElemColorForm->setWindowTitle(QApplication::translate("LanguageElemColorForm", "Form", 0));
        colorLabel->setText(QApplication::translate("LanguageElemColorForm", "TextLabel", 0));
#ifndef QT_NO_TOOLTIP
        colorButton->setToolTip(QApplication::translate("LanguageElemColorForm", "foreground color", 0));
#endif // QT_NO_TOOLTIP
        colorButton->setText(QApplication::translate("LanguageElemColorForm", "...", 0));
#ifndef QT_NO_TOOLTIP
        backgroundColorButton->setToolTip(QApplication::translate("LanguageElemColorForm", "background color", 0));
#endif // QT_NO_TOOLTIP
        backgroundColorButton->setText(QApplication::translate("LanguageElemColorForm", "...", 0));
        boldCheckBox->setText(QApplication::translate("LanguageElemColorForm", "bold", 0));
        italicCheckBox->setText(QApplication::translate("LanguageElemColorForm", "italic", 0));
        underlineCheckBox->setText(QApplication::translate("LanguageElemColorForm", "underline", 0));
        monospaceCheckBox->setText(QApplication::translate("LanguageElemColorForm", "monospace", 0));
    } // retranslateUi

};

namespace Ui {
    class LanguageElemColorForm: public Ui_LanguageElemColorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGEELEMCOLORFORM_H
