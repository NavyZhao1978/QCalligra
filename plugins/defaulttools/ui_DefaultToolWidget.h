/********************************************************************************
** Form generated from reading UI file 'DefaultToolWidget.ui'
**
** Created: Sat Nov 3 15:33:51 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTTOOLWIDGET_H
#define UI_DEFAULTTOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "KoAspectButton.h"
#include "KoPositionSelector.h"
#include "KoUnitDoubleSpinBox.h"

QT_BEGIN_NAMESPACE

class Ui_DefaultToolWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    KoUnitDoubleSpinBox *positionXSpinBox;
    KoUnitDoubleSpinBox *widthSpinBox;
    KoAspectButton *aspectButton;
    KoPositionSelector *positionSelector;
    QLabel *label_2;
    KoUnitDoubleSpinBox *positionYSpinBox;
    KoUnitDoubleSpinBox *heightSpinBox;
    QWidget *SpecialSpacer;

    void setupUi(QWidget *DefaultToolWidget)
    {
        if (DefaultToolWidget->objectName().isEmpty())
            DefaultToolWidget->setObjectName(QString::fromUtf8("DefaultToolWidget"));
        DefaultToolWidget->resize(158, 64);
        DefaultToolWidget->setFocusPolicy(Qt::NoFocus);
        gridLayout = new QGridLayout(DefaultToolWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DefaultToolWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        positionXSpinBox = new KoUnitDoubleSpinBox(DefaultToolWidget);
        positionXSpinBox->setObjectName(QString::fromUtf8("positionXSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(positionXSpinBox->sizePolicy().hasHeightForWidth());
        positionXSpinBox->setSizePolicy(sizePolicy1);
        positionXSpinBox->setMinimum(-10000);
        positionXSpinBox->setMaximum(10000);

        gridLayout->addWidget(positionXSpinBox, 0, 2, 1, 1);

        widthSpinBox = new KoUnitDoubleSpinBox(DefaultToolWidget);
        widthSpinBox->setObjectName(QString::fromUtf8("widthSpinBox"));
        sizePolicy1.setHeightForWidth(widthSpinBox->sizePolicy().hasHeightForWidth());
        widthSpinBox->setSizePolicy(sizePolicy1);
        widthSpinBox->setMinimum(-10000);
        widthSpinBox->setMaximum(10000);

        gridLayout->addWidget(widthSpinBox, 0, 3, 1, 1);

        aspectButton = new KoAspectButton(DefaultToolWidget);
        aspectButton->setObjectName(QString::fromUtf8("aspectButton"));
        sizePolicy.setHeightForWidth(aspectButton->sizePolicy().hasHeightForWidth());
        aspectButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(aspectButton, 0, 4, 2, 1);

        positionSelector = new KoPositionSelector(DefaultToolWidget);
        positionSelector->setObjectName(QString::fromUtf8("positionSelector"));
        sizePolicy.setHeightForWidth(positionSelector->sizePolicy().hasHeightForWidth());
        positionSelector->setSizePolicy(sizePolicy);

        gridLayout->addWidget(positionSelector, 0, 0, 2, 1);

        label_2 = new QLabel(DefaultToolWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        positionYSpinBox = new KoUnitDoubleSpinBox(DefaultToolWidget);
        positionYSpinBox->setObjectName(QString::fromUtf8("positionYSpinBox"));
        sizePolicy1.setHeightForWidth(positionYSpinBox->sizePolicy().hasHeightForWidth());
        positionYSpinBox->setSizePolicy(sizePolicy1);
        positionYSpinBox->setMinimum(-10000);
        positionYSpinBox->setMaximum(10000);

        gridLayout->addWidget(positionYSpinBox, 1, 2, 1, 1);

        heightSpinBox = new KoUnitDoubleSpinBox(DefaultToolWidget);
        heightSpinBox->setObjectName(QString::fromUtf8("heightSpinBox"));
        sizePolicy1.setHeightForWidth(heightSpinBox->sizePolicy().hasHeightForWidth());
        heightSpinBox->setSizePolicy(sizePolicy1);
        heightSpinBox->setMinimum(-10000);
        heightSpinBox->setMaximum(10000);

        gridLayout->addWidget(heightSpinBox, 1, 3, 1, 1);

        SpecialSpacer = new QWidget(DefaultToolWidget);
        SpecialSpacer->setObjectName(QString::fromUtf8("SpecialSpacer"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SpecialSpacer->sizePolicy().hasHeightForWidth());
        SpecialSpacer->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(SpecialSpacer, 2, 2, 1, 1);

        QWidget::setTabOrder(positionXSpinBox, positionYSpinBox);
        QWidget::setTabOrder(positionYSpinBox, widthSpinBox);
        QWidget::setTabOrder(widthSpinBox, heightSpinBox);

        retranslateUi(DefaultToolWidget);

        QMetaObject::connectSlotsByName(DefaultToolWidget);
    } // setupUi

    void retranslateUi(QWidget *DefaultToolWidget)
    {
        label->setText(QApplication::translate("DefaultToolWidget", "X:", 0, QApplication::UnicodeUTF8));
        aspectButton->setText(QString());
        label_2->setText(QApplication::translate("DefaultToolWidget", "Y:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DefaultToolWidget);
    } // retranslateUi

};

namespace Ui {
    class DefaultToolWidget: public Ui_DefaultToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTTOOLWIDGET_H
