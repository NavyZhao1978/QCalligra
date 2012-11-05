/********************************************************************************
** Form generated from reading UI file 'KoShadowConfigWidget.ui'
**
** Created: Sat Nov 3 15:21:39 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOSHADOWCONFIGWIDGET_H
#define UI_KOSHADOWCONFIGWIDGET_H

#include <KoSliderCombo.h>
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
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoShadowConfigWidget
{
public:
    QGridLayout *gridLayout_2;
    QCheckBox *shadowVisible;
    QWidget *shadowOptions;
    QGridLayout *gridLayout;
    QLabel *label;
    KoSliderCombo *shadowAngle;
    QLabel *label_2;
    KoUnitDoubleSpinBox *shadowOffset;
    QLabel *label_3;
    QToolButton *shadowColor;
    QLabel *label_4;
    KoUnitDoubleSpinBox *shadowBlur;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *KoShadowConfigWidget)
    {
        if (KoShadowConfigWidget->objectName().isEmpty())
            KoShadowConfigWidget->setObjectName(QString::fromUtf8("KoShadowConfigWidget"));
        KoShadowConfigWidget->resize(196, 148);
        gridLayout_2 = new QGridLayout(KoShadowConfigWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        shadowVisible = new QCheckBox(KoShadowConfigWidget);
        shadowVisible->setObjectName(QString::fromUtf8("shadowVisible"));

        gridLayout_2->addWidget(shadowVisible, 0, 0, 1, 1);

        shadowOptions = new QWidget(KoShadowConfigWidget);
        shadowOptions->setObjectName(QString::fromUtf8("shadowOptions"));
        gridLayout = new QGridLayout(shadowOptions);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(shadowOptions);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        shadowAngle = new KoSliderCombo(shadowOptions);
        shadowAngle->setObjectName(QString::fromUtf8("shadowAngle"));

        gridLayout->addWidget(shadowAngle, 0, 1, 1, 2);

        label_2 = new QLabel(shadowOptions);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        shadowOffset = new KoUnitDoubleSpinBox(shadowOptions);
        shadowOffset->setObjectName(QString::fromUtf8("shadowOffset"));

        gridLayout->addWidget(shadowOffset, 1, 1, 1, 2);

        label_3 = new QLabel(shadowOptions);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        shadowColor = new QToolButton(shadowOptions);
        shadowColor->setObjectName(QString::fromUtf8("shadowColor"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shadowColor->sizePolicy().hasHeightForWidth());
        shadowColor->setSizePolicy(sizePolicy);

        gridLayout->addWidget(shadowColor, 2, 1, 1, 2);

        label_4 = new QLabel(shadowOptions);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        shadowBlur = new KoUnitDoubleSpinBox(shadowOptions);
        shadowBlur->setObjectName(QString::fromUtf8("shadowBlur"));

        gridLayout->addWidget(shadowBlur, 3, 1, 1, 2);


        gridLayout_2->addWidget(shadowOptions, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(KoShadowConfigWidget);

        QMetaObject::connectSlotsByName(KoShadowConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *KoShadowConfigWidget)
    {
        shadowVisible->setText(QApplication::translate("KoShadowConfigWidget", "Show Shadow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("KoShadowConfigWidget", "Angle:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("KoShadowConfigWidget", "Offset:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("KoShadowConfigWidget", "Color:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("KoShadowConfigWidget", "Blur radius:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoShadowConfigWidget);
    } // retranslateUi

};

namespace Ui {
    class KoShadowConfigWidget: public Ui_KoShadowConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOSHADOWCONFIGWIDGET_H
