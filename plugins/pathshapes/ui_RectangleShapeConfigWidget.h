/********************************************************************************
** Form generated from reading UI file 'RectangleShapeConfigWidget.ui'
**
** Created: Sat Nov 3 15:31:06 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLESHAPECONFIGWIDGET_H
#define UI_RECTANGLESHAPECONFIGWIDGET_H

#include <KoUnitDoubleSpinBox.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectangleShapeConfigWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    KoUnitDoubleSpinBox *cornerRadiusX;
    QLabel *label_2;
    KoUnitDoubleSpinBox *cornerRadiusY;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *RectangleShapeConfigWidget)
    {
        if (RectangleShapeConfigWidget->objectName().isEmpty())
            RectangleShapeConfigWidget->setObjectName(QString::fromUtf8("RectangleShapeConfigWidget"));
        RectangleShapeConfigWidget->resize(198, 108);
        gridLayout = new QGridLayout(RectangleShapeConfigWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RectangleShapeConfigWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cornerRadiusX = new KoUnitDoubleSpinBox(RectangleShapeConfigWidget);
        cornerRadiusX->setObjectName(QString::fromUtf8("cornerRadiusX"));

        gridLayout->addWidget(cornerRadiusX, 0, 1, 1, 1);

        label_2 = new QLabel(RectangleShapeConfigWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cornerRadiusY = new KoUnitDoubleSpinBox(RectangleShapeConfigWidget);
        cornerRadiusY->setObjectName(QString::fromUtf8("cornerRadiusY"));

        gridLayout->addWidget(cornerRadiusY, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 2, 0, 1, 1);


        retranslateUi(RectangleShapeConfigWidget);

        QMetaObject::connectSlotsByName(RectangleShapeConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *RectangleShapeConfigWidget)
    {
        RectangleShapeConfigWidget->setWindowTitle(QApplication::translate("RectangleShapeConfigWidget", "Rectangle Shape", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RectangleShapeConfigWidget", "Corner radius x:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RectangleShapeConfigWidget", "Corner radius y:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RectangleShapeConfigWidget: public Ui_RectangleShapeConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLESHAPECONFIGWIDGET_H
