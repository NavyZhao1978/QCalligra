/********************************************************************************
** Form generated from reading UI file 'DefaultToolTransformWidget.ui'
**
** Created: Sat Nov 3 15:33:52 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTTOOLTRANSFORMWIDGET_H
#define UI_DEFAULTTOOLTRANSFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMenu>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include "KoUnitDoubleSpinBox.h"

QT_BEGIN_NAMESPACE

class Ui_DefaultToolTransformWidget
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *rotateSpinBox;
    QPushButton *rotateButton;
    KoUnitDoubleSpinBox *shearXSpinBox;
    QPushButton *shearXButton;
    KoUnitDoubleSpinBox *shearYSpinBox;
    QPushButton *shearYButton;
    QDoubleSpinBox *scaleXSpinBox;
    QPushButton *scaleXButton;
    QDoubleSpinBox *scaleYSpinBox;
    QPushButton *scaleYButton;
    QCheckBox *scaleAspectCheckBox;
    QPushButton *resetButton;
    QSpacerItem *spacer;

    void setupUi(QMenu *DefaultToolTransformWidget)
    {
        if (DefaultToolTransformWidget->objectName().isEmpty())
            DefaultToolTransformWidget->setObjectName(QString::fromUtf8("DefaultToolTransformWidget"));
        DefaultToolTransformWidget->resize(222, 293);
        gridLayout = new QGridLayout(DefaultToolTransformWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rotateSpinBox = new QDoubleSpinBox(DefaultToolTransformWidget);
        rotateSpinBox->setObjectName(QString::fromUtf8("rotateSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rotateSpinBox->sizePolicy().hasHeightForWidth());
        rotateSpinBox->setSizePolicy(sizePolicy);
        rotateSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rotateSpinBox->setMinimum(-360);
        rotateSpinBox->setMaximum(360);

        gridLayout->addWidget(rotateSpinBox, 0, 0, 1, 1);

        rotateButton = new QPushButton(DefaultToolTransformWidget);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));

        gridLayout->addWidget(rotateButton, 0, 1, 1, 1);

        shearXSpinBox = new KoUnitDoubleSpinBox(DefaultToolTransformWidget);
        shearXSpinBox->setObjectName(QString::fromUtf8("shearXSpinBox"));
        sizePolicy.setHeightForWidth(shearXSpinBox->sizePolicy().hasHeightForWidth());
        shearXSpinBox->setSizePolicy(sizePolicy);
        shearXSpinBox->setMinimum(-100);
        shearXSpinBox->setMaximum(100);
        shearXSpinBox->setSingleStep(0.1);

        gridLayout->addWidget(shearXSpinBox, 1, 0, 1, 1);

        shearXButton = new QPushButton(DefaultToolTransformWidget);
        shearXButton->setObjectName(QString::fromUtf8("shearXButton"));

        gridLayout->addWidget(shearXButton, 1, 1, 1, 1);

        shearYSpinBox = new KoUnitDoubleSpinBox(DefaultToolTransformWidget);
        shearYSpinBox->setObjectName(QString::fromUtf8("shearYSpinBox"));
        sizePolicy.setHeightForWidth(shearYSpinBox->sizePolicy().hasHeightForWidth());
        shearYSpinBox->setSizePolicy(sizePolicy);
        shearYSpinBox->setMinimum(-100);
        shearYSpinBox->setMaximum(100);
        shearYSpinBox->setSingleStep(0.1);

        gridLayout->addWidget(shearYSpinBox, 2, 0, 1, 1);

        shearYButton = new QPushButton(DefaultToolTransformWidget);
        shearYButton->setObjectName(QString::fromUtf8("shearYButton"));

        gridLayout->addWidget(shearYButton, 2, 1, 1, 1);

        scaleXSpinBox = new QDoubleSpinBox(DefaultToolTransformWidget);
        scaleXSpinBox->setObjectName(QString::fromUtf8("scaleXSpinBox"));
        sizePolicy.setHeightForWidth(scaleXSpinBox->sizePolicy().hasHeightForWidth());
        scaleXSpinBox->setSizePolicy(sizePolicy);
        scaleXSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scaleXSpinBox->setMinimum(-1000);
        scaleXSpinBox->setMaximum(1000);
        scaleXSpinBox->setValue(100);

        gridLayout->addWidget(scaleXSpinBox, 3, 0, 1, 1);

        scaleXButton = new QPushButton(DefaultToolTransformWidget);
        scaleXButton->setObjectName(QString::fromUtf8("scaleXButton"));

        gridLayout->addWidget(scaleXButton, 3, 1, 1, 1);

        scaleYSpinBox = new QDoubleSpinBox(DefaultToolTransformWidget);
        scaleYSpinBox->setObjectName(QString::fromUtf8("scaleYSpinBox"));
        sizePolicy.setHeightForWidth(scaleYSpinBox->sizePolicy().hasHeightForWidth());
        scaleYSpinBox->setSizePolicy(sizePolicy);
        scaleYSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scaleYSpinBox->setMinimum(-1000);
        scaleYSpinBox->setMaximum(1000);
        scaleYSpinBox->setValue(100);

        gridLayout->addWidget(scaleYSpinBox, 4, 0, 1, 1);

        scaleYButton = new QPushButton(DefaultToolTransformWidget);
        scaleYButton->setObjectName(QString::fromUtf8("scaleYButton"));

        gridLayout->addWidget(scaleYButton, 4, 1, 1, 1);

        scaleAspectCheckBox = new QCheckBox(DefaultToolTransformWidget);
        scaleAspectCheckBox->setObjectName(QString::fromUtf8("scaleAspectCheckBox"));

        gridLayout->addWidget(scaleAspectCheckBox, 5, 0, 1, 2);

        resetButton = new QPushButton(DefaultToolTransformWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resetButton->sizePolicy().hasHeightForWidth());
        resetButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(resetButton, 6, 0, 1, 2);

        spacer = new QSpacerItem(191, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer, 7, 0, 1, 2);


        retranslateUi(DefaultToolTransformWidget);

        QMetaObject::connectSlotsByName(DefaultToolTransformWidget);
    } // setupUi

    void retranslateUi(QMenu *DefaultToolTransformWidget)
    {
        rotateSpinBox->setSuffix(QApplication::translate("DefaultToolTransformWidget", "\302\260", 0, QApplication::UnicodeUTF8));
        rotateButton->setText(QApplication::translate("DefaultToolTransformWidget", "Rotate", 0, QApplication::UnicodeUTF8));
        shearXButton->setText(QApplication::translate("DefaultToolTransformWidget", "Shear X", 0, QApplication::UnicodeUTF8));
        shearYButton->setText(QApplication::translate("DefaultToolTransformWidget", "Shear Y", 0, QApplication::UnicodeUTF8));
        scaleXSpinBox->setSuffix(QApplication::translate("DefaultToolTransformWidget", "%", 0, QApplication::UnicodeUTF8));
        scaleXButton->setText(QApplication::translate("DefaultToolTransformWidget", "Scale X", 0, QApplication::UnicodeUTF8));
        scaleYSpinBox->setSuffix(QApplication::translate("DefaultToolTransformWidget", "%", 0, QApplication::UnicodeUTF8));
        scaleYButton->setText(QApplication::translate("DefaultToolTransformWidget", "Scale Y", 0, QApplication::UnicodeUTF8));
        scaleAspectCheckBox->setText(QApplication::translate("DefaultToolTransformWidget", "Keep aspect ratio", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("DefaultToolTransformWidget", "Reset Transformations", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DefaultToolTransformWidget);
    } // retranslateUi

};

namespace Ui {
    class DefaultToolTransformWidget: public Ui_DefaultToolTransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTTOOLTRANSFORMWIDGET_H
