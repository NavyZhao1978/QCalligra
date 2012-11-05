/********************************************************************************
** Form generated from reading UI file 'SpiralShapeConfigWidget.ui'
**
** Created: Sat Nov 3 15:31:04 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPIRALSHAPECONFIGWIDGET_H
#define UI_SPIRALSHAPECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpiralShapeConfigWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *spiralType;
    QLabel *label;
    QDoubleSpinBox *fade;
    QLabel *label_4;
    QComboBox *clockWise;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *SpiralShapeConfigWidget)
    {
        if (SpiralShapeConfigWidget->objectName().isEmpty())
            SpiralShapeConfigWidget->setObjectName(QString::fromUtf8("SpiralShapeConfigWidget"));
        SpiralShapeConfigWidget->resize(187, 173);
        gridLayout = new QGridLayout(SpiralShapeConfigWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(SpiralShapeConfigWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        spiralType = new QComboBox(SpiralShapeConfigWidget);
        spiralType->setObjectName(QString::fromUtf8("spiralType"));

        gridLayout->addWidget(spiralType, 0, 1, 1, 1);

        label = new QLabel(SpiralShapeConfigWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        fade = new QDoubleSpinBox(SpiralShapeConfigWidget);
        fade->setObjectName(QString::fromUtf8("fade"));
        fade->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fade->setMaximum(1);
        fade->setSingleStep(0.1);
        fade->setValue(0.5);

        gridLayout->addWidget(fade, 1, 1, 1, 1);

        label_4 = new QLabel(SpiralShapeConfigWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        clockWise = new QComboBox(SpiralShapeConfigWidget);
        clockWise->setObjectName(QString::fromUtf8("clockWise"));

        gridLayout->addWidget(clockWise, 2, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 3, 0, 1, 1);


        retranslateUi(SpiralShapeConfigWidget);

        QMetaObject::connectSlotsByName(SpiralShapeConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *SpiralShapeConfigWidget)
    {
        SpiralShapeConfigWidget->setWindowTitle(QApplication::translate("SpiralShapeConfigWidget", "Spiral Shape", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpiralShapeConfigWidget", "Type:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpiralShapeConfigWidget", "Fade:", 0, QApplication::UnicodeUTF8));
        fade->setSuffix(QString());
        label_4->setText(QApplication::translate("SpiralShapeConfigWidget", "Direction:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpiralShapeConfigWidget: public Ui_SpiralShapeConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPIRALSHAPECONFIGWIDGET_H
