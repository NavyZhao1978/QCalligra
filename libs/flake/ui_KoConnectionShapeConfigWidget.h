/********************************************************************************
** Form generated from reading UI file 'KoConnectionShapeConfigWidget.ui'
**
** Created: Sat Nov 3 15:11:12 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOCONNECTIONSHAPECONFIGWIDGET_H
#define UI_KOCONNECTIONSHAPECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoConnectionShapeConfigWidget
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *connectionType;
    QWidget *SpecialSpacer;

    void setupUi(QWidget *KoConnectionShapeConfigWidget)
    {
        if (KoConnectionShapeConfigWidget->objectName().isEmpty())
            KoConnectionShapeConfigWidget->setObjectName(QString::fromUtf8("KoConnectionShapeConfigWidget"));
        KoConnectionShapeConfigWidget->resize(187, 46);
        formLayout = new QFormLayout(KoConnectionShapeConfigWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(KoConnectionShapeConfigWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        connectionType = new QComboBox(KoConnectionShapeConfigWidget);
        connectionType->setObjectName(QString::fromUtf8("connectionType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, connectionType);

        SpecialSpacer = new QWidget(KoConnectionShapeConfigWidget);
        SpecialSpacer->setObjectName(QString::fromUtf8("SpecialSpacer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpecialSpacer->sizePolicy().hasHeightForWidth());
        SpecialSpacer->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, SpecialSpacer);


        retranslateUi(KoConnectionShapeConfigWidget);

        QMetaObject::connectSlotsByName(KoConnectionShapeConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *KoConnectionShapeConfigWidget)
    {
        label->setText(QApplication::translate("KoConnectionShapeConfigWidget", "Type:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoConnectionShapeConfigWidget);
    } // retranslateUi

};

namespace Ui {
    class KoConnectionShapeConfigWidget: public Ui_KoConnectionShapeConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOCONNECTIONSHAPECONFIGWIDGET_H
