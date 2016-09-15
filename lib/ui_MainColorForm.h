/********************************************************************************
** Form generated from reading UI file 'MainColorForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCOLORFORM_H
#define UI_MAINCOLORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainColorForm
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *colorButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QToolButton *backgroundColorButton;

    void setupUi(QWidget *MainColorForm)
    {
        if (MainColorForm->objectName().isEmpty())
            MainColorForm->setObjectName(QStringLiteral("MainColorForm"));
        MainColorForm->resize(314, 96);
        gridLayout_2 = new QGridLayout(MainColorForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(MainColorForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        colorButton = new QToolButton(groupBox);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        horizontalLayout->addWidget(colorButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        backgroundColorButton = new QToolButton(groupBox);
        backgroundColorButton->setObjectName(QStringLiteral("backgroundColorButton"));

        horizontalLayout->addWidget(backgroundColorButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(MainColorForm);

        QMetaObject::connectSlotsByName(MainColorForm);
    } // setupUi

    void retranslateUi(QWidget *MainColorForm)
    {
        MainColorForm->setWindowTitle(QApplication::translate("MainColorForm", "Form", 0));
        groupBox->setTitle(QApplication::translate("MainColorForm", "Main Color", 0));
        label->setText(QApplication::translate("MainColorForm", "Foreground", 0));
#ifndef QT_NO_TOOLTIP
        colorButton->setToolTip(QApplication::translate("MainColorForm", "foreground color", 0));
#endif // QT_NO_TOOLTIP
        colorButton->setText(QApplication::translate("MainColorForm", "...", 0));
        label_2->setText(QApplication::translate("MainColorForm", "Background", 0));
#ifndef QT_NO_TOOLTIP
        backgroundColorButton->setToolTip(QApplication::translate("MainColorForm", "background color", 0));
#endif // QT_NO_TOOLTIP
        backgroundColorButton->setText(QApplication::translate("MainColorForm", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainColorForm: public Ui_MainColorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCOLORFORM_H
