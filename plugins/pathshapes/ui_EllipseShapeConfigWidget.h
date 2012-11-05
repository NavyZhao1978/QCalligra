/********************************************************************************
** Form generated from reading UI file 'EllipseShapeConfigWidget.ui'
**
** Created: Sat Nov 3 15:31:09 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELLIPSESHAPECONFIGWIDGET_H
#define UI_ELLIPSESHAPECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EllipseShapeConfigWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *ellipseType;
    QLabel *label;
    QDoubleSpinBox *startAngle;
    QLabel *label_2;
    QDoubleSpinBox *endAngle;
    QPushButton *closeEllipse;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *EllipseShapeConfigWidget)
    {
        if (EllipseShapeConfigWidget->objectName().isEmpty())
            EllipseShapeConfigWidget->setObjectName(QString::fromUtf8("EllipseShapeConfigWidget"));
        EllipseShapeConfigWidget->resize(187, 173);
        gridLayout = new QGridLayout(EllipseShapeConfigWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(EllipseShapeConfigWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        ellipseType = new QComboBox(EllipseShapeConfigWidget);
        ellipseType->setObjectName(QString::fromUtf8("ellipseType"));

        gridLayout->addWidget(ellipseType, 0, 1, 1, 1);

        label = new QLabel(EllipseShapeConfigWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        startAngle = new QDoubleSpinBox(EllipseShapeConfigWidget);
        startAngle->setObjectName(QString::fromUtf8("startAngle"));
        startAngle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(startAngle, 1, 1, 1, 1);

        label_2 = new QLabel(EllipseShapeConfigWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        endAngle = new QDoubleSpinBox(EllipseShapeConfigWidget);
        endAngle->setObjectName(QString::fromUtf8("endAngle"));
        endAngle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(endAngle, 2, 1, 1, 1);

        closeEllipse = new QPushButton(EllipseShapeConfigWidget);
        closeEllipse->setObjectName(QString::fromUtf8("closeEllipse"));

        gridLayout->addWidget(closeEllipse, 3, 0, 1, 2);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 4, 0, 1, 1);


        retranslateUi(EllipseShapeConfigWidget);

        QMetaObject::connectSlotsByName(EllipseShapeConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *EllipseShapeConfigWidget)
    {
        EllipseShapeConfigWidget->setWindowTitle(QApplication::translate("EllipseShapeConfigWidget", "Ellipse Shape", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EllipseShapeConfigWidget", "Type:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EllipseShapeConfigWidget", "Start angle:", 0, QApplication::UnicodeUTF8));
        startAngle->setSuffix(QApplication::translate("EllipseShapeConfigWidget", "\302\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EllipseShapeConfigWidget", "End angle:", 0, QApplication::UnicodeUTF8));
        endAngle->setSuffix(QApplication::translate("EllipseShapeConfigWidget", "\302\260", 0, QApplication::UnicodeUTF8));
        closeEllipse->setText(QApplication::translate("EllipseShapeConfigWidget", "Close ellipse", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EllipseShapeConfigWidget: public Ui_EllipseShapeConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELLIPSESHAPECONFIGWIDGET_H
