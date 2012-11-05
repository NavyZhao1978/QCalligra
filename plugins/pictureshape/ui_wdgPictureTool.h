/********************************************************************************
** Form generated from reading UI file 'wdgPictureTool.ui'
**
** Created: Sat Nov 3 15:31:08 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WDGPICTURETOOL_H
#define UI_WDGPICTURETOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "CropWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PictureTool
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *bnImageFile;
    QFrame *separator;
    QGridLayout *gridLayout;
    QCheckBox *cbAspect;
    QDoubleSpinBox *topDoubleSpinBox;
    QLabel *leftLabel;
    QLabel *rightLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *bottomLabel;
    QDoubleSpinBox *leftDoubleSpinBox;
    QLabel *topLabel;
    QDoubleSpinBox *bottomDoubleSpinBox;
    QToolButton *bnFill;
    QDoubleSpinBox *rightDoubleSpinBox;
    QCheckBox *cbContour;
    CropWidget *cropWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cmbColorMode;
    QLabel *label_2;

    void setupUi(QWidget *PictureTool)
    {
        if (PictureTool->objectName().isEmpty())
            PictureTool->setObjectName(QString::fromUtf8("PictureTool"));
        PictureTool->resize(292, 250);
        gridLayout_2 = new QGridLayout(PictureTool);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        bnImageFile = new QPushButton(PictureTool);
        bnImageFile->setObjectName(QString::fromUtf8("bnImageFile"));

        gridLayout_2->addWidget(bnImageFile, 0, 0, 1, 1);

        separator = new QFrame(PictureTool);
        separator->setObjectName(QString::fromUtf8("separator"));

        gridLayout_2->addWidget(separator, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbAspect = new QCheckBox(PictureTool);
        cbAspect->setObjectName(QString::fromUtf8("cbAspect"));

        gridLayout->addWidget(cbAspect, 2, 0, 1, 3);

        topDoubleSpinBox = new QDoubleSpinBox(PictureTool);
        topDoubleSpinBox->setObjectName(QString::fromUtf8("topDoubleSpinBox"));
        topDoubleSpinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        topDoubleSpinBox->setSuffix(QString::fromUtf8(" pt"));
        topDoubleSpinBox->setDecimals(2);
        topDoubleSpinBox->setSingleStep(5);

        gridLayout->addWidget(topDoubleSpinBox, 0, 1, 1, 1);

        leftLabel = new QLabel(PictureTool);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));
        leftLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(leftLabel, 0, 2, 1, 1);

        rightLabel = new QLabel(PictureTool);
        rightLabel->setObjectName(QString::fromUtf8("rightLabel"));
        rightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(rightLabel, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        bottomLabel = new QLabel(PictureTool);
        bottomLabel->setObjectName(QString::fromUtf8("bottomLabel"));
        bottomLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(bottomLabel, 1, 0, 1, 1);

        leftDoubleSpinBox = new QDoubleSpinBox(PictureTool);
        leftDoubleSpinBox->setObjectName(QString::fromUtf8("leftDoubleSpinBox"));
        leftDoubleSpinBox->setSuffix(QString::fromUtf8(" pt"));
        leftDoubleSpinBox->setSingleStep(5);

        gridLayout->addWidget(leftDoubleSpinBox, 0, 3, 1, 1);

        topLabel = new QLabel(PictureTool);
        topLabel->setObjectName(QString::fromUtf8("topLabel"));
        topLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(topLabel, 0, 0, 1, 1);

        bottomDoubleSpinBox = new QDoubleSpinBox(PictureTool);
        bottomDoubleSpinBox->setObjectName(QString::fromUtf8("bottomDoubleSpinBox"));
        bottomDoubleSpinBox->setSuffix(QString::fromUtf8(" pt"));
        bottomDoubleSpinBox->setSingleStep(5);

        gridLayout->addWidget(bottomDoubleSpinBox, 1, 1, 1, 1);

        bnFill = new QToolButton(PictureTool);
        bnFill->setObjectName(QString::fromUtf8("bnFill"));

        gridLayout->addWidget(bnFill, 2, 3, 1, 1);

        rightDoubleSpinBox = new QDoubleSpinBox(PictureTool);
        rightDoubleSpinBox->setObjectName(QString::fromUtf8("rightDoubleSpinBox"));
        rightDoubleSpinBox->setSuffix(QString::fromUtf8(" pt"));
        rightDoubleSpinBox->setSingleStep(5);

        gridLayout->addWidget(rightDoubleSpinBox, 1, 3, 1, 1);

        cbContour = new QCheckBox(PictureTool);
        cbContour->setObjectName(QString::fromUtf8("cbContour"));

        gridLayout->addWidget(cbContour, 3, 0, 1, 4);


        gridLayout_2->addLayout(gridLayout, 4, 0, 1, 1);

        cropWidget = new CropWidget(PictureTool);
        cropWidget->setObjectName(QString::fromUtf8("cropWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cropWidget->sizePolicy().hasHeightForWidth());
        cropWidget->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(cropWidget, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(PictureTool);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        cmbColorMode = new QComboBox(PictureTool);
        cmbColorMode->setObjectName(QString::fromUtf8("cmbColorMode"));

        horizontalLayout->addWidget(cmbColorMode);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        label_2 = new QLabel(PictureTool);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);


        retranslateUi(PictureTool);

        QMetaObject::connectSlotsByName(PictureTool);
    } // setupUi

    void retranslateUi(QWidget *PictureTool)
    {
        PictureTool->setWindowTitle(QString());
        bnImageFile->setText(QApplication::translate("PictureTool", "Replace image...", 0, QApplication::UnicodeUTF8));
        cbAspect->setText(QApplication::translate("PictureTool", "Keep proportions", 0, QApplication::UnicodeUTF8));
        topDoubleSpinBox->setPrefix(QString());
        leftLabel->setText(QApplication::translate("PictureTool", "Left:", 0, QApplication::UnicodeUTF8));
        rightLabel->setText(QApplication::translate("PictureTool", "Right:", 0, QApplication::UnicodeUTF8));
        bottomLabel->setText(QApplication::translate("PictureTool", "Bottom:", 0, QApplication::UnicodeUTF8));
        topLabel->setText(QApplication::translate("PictureTool", "Top:", 0, QApplication::UnicodeUTF8));
        bnFill->setText(QApplication::translate("PictureTool", "Reset", 0, QApplication::UnicodeUTF8));
        cbContour->setText(QApplication::translate("PictureTool", "Contour (by image analysis)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PictureTool", "Color mode:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PictureTool", "Crop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PictureTool: public Ui_PictureTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDGPICTURETOOL_H
