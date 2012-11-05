/********************************************************************************
** Form generated from reading UI file 'GuidesToolOptionWidget.ui'
**
** Created: Sat Nov 3 15:33:47 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDESTOOLOPTIONWIDGET_H
#define UI_GUIDESTOOLOPTIONWIDGET_H

#include <KoUnitDoubleSpinBox.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuidesToolOptionWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *orientation;
    QListWidget *positionList;
    QLabel *label_2;
    KoUnitDoubleSpinBox *position;
    QPushButton *addButton;
    QPushButton *removeButton;

    void setupUi(QWidget *GuidesToolOptionWidget)
    {
        if (GuidesToolOptionWidget->objectName().isEmpty())
            GuidesToolOptionWidget->setObjectName(QString::fromUtf8("GuidesToolOptionWidget"));
        GuidesToolOptionWidget->resize(268, 252);
        gridLayout = new QGridLayout(GuidesToolOptionWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(GuidesToolOptionWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        orientation = new QComboBox(GuidesToolOptionWidget);
        orientation->setObjectName(QString::fromUtf8("orientation"));

        gridLayout->addWidget(orientation, 0, 1, 1, 1);

        positionList = new QListWidget(GuidesToolOptionWidget);
        positionList->setObjectName(QString::fromUtf8("positionList"));

        gridLayout->addWidget(positionList, 1, 0, 1, 2);

        label_2 = new QLabel(GuidesToolOptionWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        position = new KoUnitDoubleSpinBox(GuidesToolOptionWidget);
        position->setObjectName(QString::fromUtf8("position"));

        gridLayout->addWidget(position, 2, 1, 1, 1);

        addButton = new QPushButton(GuidesToolOptionWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 3, 0, 1, 1);

        removeButton = new QPushButton(GuidesToolOptionWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        gridLayout->addWidget(removeButton, 3, 1, 1, 1);


        retranslateUi(GuidesToolOptionWidget);

        QMetaObject::connectSlotsByName(GuidesToolOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *GuidesToolOptionWidget)
    {
        label->setText(QApplication::translate("GuidesToolOptionWidget", "Orientation:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GuidesToolOptionWidget", "Position:", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("GuidesToolOptionWidget", "Add", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("GuidesToolOptionWidget", "Remove", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GuidesToolOptionWidget);
    } // retranslateUi

};

namespace Ui {
    class GuidesToolOptionWidget: public Ui_GuidesToolOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDESTOOLOPTIONWIDGET_H
