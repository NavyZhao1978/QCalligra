/********************************************************************************
** Form generated from reading UI file 'StarShapeConfigWidget.ui'
**
** Created: Sat Nov 3 15:31:03 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARSHAPECONFIGWIDGET_H
#define UI_STARSHAPECONFIGWIDGET_H

#include <KoUnitDoubleSpinBox.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StarShapeConfigWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QCheckBox *convex;
    QLabel *label;
    QSpinBox *corners;
    QLabel *label_2;
    KoUnitDoubleSpinBox *innerRadius;
    QLabel *label_3;
    KoUnitDoubleSpinBox *outerRadius;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *StarShapeConfigWidget)
    {
        if (StarShapeConfigWidget->objectName().isEmpty())
            StarShapeConfigWidget->setObjectName(QString::fromUtf8("StarShapeConfigWidget"));
        StarShapeConfigWidget->resize(189, 175);
        gridLayout = new QGridLayout(StarShapeConfigWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(StarShapeConfigWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        convex = new QCheckBox(StarShapeConfigWidget);
        convex->setObjectName(QString::fromUtf8("convex"));
        convex->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(convex, 0, 1, 1, 1);

        label = new QLabel(StarShapeConfigWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        corners = new QSpinBox(StarShapeConfigWidget);
        corners->setObjectName(QString::fromUtf8("corners"));

        gridLayout->addWidget(corners, 1, 1, 1, 1);

        label_2 = new QLabel(StarShapeConfigWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        innerRadius = new KoUnitDoubleSpinBox(StarShapeConfigWidget);
        innerRadius->setObjectName(QString::fromUtf8("innerRadius"));
        innerRadius->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(innerRadius, 2, 1, 1, 1);

        label_3 = new QLabel(StarShapeConfigWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        outerRadius = new KoUnitDoubleSpinBox(StarShapeConfigWidget);
        outerRadius->setObjectName(QString::fromUtf8("outerRadius"));
        outerRadius->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(outerRadius, 3, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 4, 0, 1, 1);


        retranslateUi(StarShapeConfigWidget);

        QMetaObject::connectSlotsByName(StarShapeConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *StarShapeConfigWidget)
    {
        StarShapeConfigWidget->setWindowTitle(QApplication::translate("StarShapeConfigWidget", "Star shape", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StarShapeConfigWidget", "Polygon:", 0, QApplication::UnicodeUTF8));
        convex->setText(QString());
        label->setText(QApplication::translate("StarShapeConfigWidget", "Corners:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StarShapeConfigWidget", "Inner radius:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StarShapeConfigWidget", "Outer radius:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StarShapeConfigWidget: public Ui_StarShapeConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARSHAPECONFIGWIDGET_H
