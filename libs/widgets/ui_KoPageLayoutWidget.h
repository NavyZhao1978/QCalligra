/********************************************************************************
** Form generated from reading UI file 'KoPageLayoutWidget.ui'
**
** Created: Sat Nov 3 15:21:39 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOPAGELAYOUTWIDGET_H
#define UI_KOPAGELAYOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "KoUnitDoubleSpinBox.h"

QT_BEGIN_NAMESPACE

class Ui_KoPageLayoutWidget
{
public:
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLabel *unitsLabel;
    QComboBox *units;
    QLabel *stylesLabel;
    QComboBox *pageStyle;
    QLabel *sizeLabel;
    QComboBox *sizes;
    QLabel *widthLabel;
    QHBoxLayout *hboxLayout;
    KoUnitDoubleSpinBox *width;
    QLabel *label;
    KoUnitDoubleSpinBox *height;
    QLabel *orientlabel;
    QRadioButton *portrait;
    QRadioButton *landscape;
    QLabel *facingPageLabel;
    QRadioButton *singleSided;
    QRadioButton *facingPages;
    QLabel *directionLabel;
    QComboBox *textDirection;
    QGroupBox *margins;
    QFormLayout *formLayout;
    QLabel *topLabel;
    KoUnitDoubleSpinBox *topMargin;
    QLabel *leftLabel;
    KoUnitDoubleSpinBox *bindingEdgeMargin;
    QLabel *rightLabel;
    KoUnitDoubleSpinBox *pageEdgeMargin;
    QLabel *bottomLabel;
    KoUnitDoubleSpinBox *bottomMargin;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *KoPageLayoutWidget)
    {
        if (KoPageLayoutWidget->objectName().isEmpty())
            KoPageLayoutWidget->setObjectName(QString::fromUtf8("KoPageLayoutWidget"));
        KoPageLayoutWidget->resize(341, 417);
        vboxLayout = new QVBoxLayout(KoPageLayoutWidget);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        unitsLabel = new QLabel(KoPageLayoutWidget);
        unitsLabel->setObjectName(QString::fromUtf8("unitsLabel"));
        unitsLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(unitsLabel, 0, 0, 1, 1);

        units = new QComboBox(KoPageLayoutWidget);
        units->setObjectName(QString::fromUtf8("units"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(units->sizePolicy().hasHeightForWidth());
        units->setSizePolicy(sizePolicy);

        gridLayout->addWidget(units, 0, 1, 1, 2);

        stylesLabel = new QLabel(KoPageLayoutWidget);
        stylesLabel->setObjectName(QString::fromUtf8("stylesLabel"));
        stylesLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(stylesLabel, 1, 0, 1, 1);

        pageStyle = new QComboBox(KoPageLayoutWidget);
        pageStyle->setObjectName(QString::fromUtf8("pageStyle"));

        gridLayout->addWidget(pageStyle, 1, 1, 1, 2);

        sizeLabel = new QLabel(KoPageLayoutWidget);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));
        sizeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(sizeLabel, 2, 0, 1, 1);

        sizes = new QComboBox(KoPageLayoutWidget);
        sizes->setObjectName(QString::fromUtf8("sizes"));

        gridLayout->addWidget(sizes, 2, 1, 1, 2);

        widthLabel = new QLabel(KoPageLayoutWidget);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));
        widthLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(widthLabel, 3, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        width = new KoUnitDoubleSpinBox(KoPageLayoutWidget);
        width->setObjectName(QString::fromUtf8("width"));

        hboxLayout->addWidget(width);

        label = new QLabel(KoPageLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(label);

        height = new KoUnitDoubleSpinBox(KoPageLayoutWidget);
        height->setObjectName(QString::fromUtf8("height"));

        hboxLayout->addWidget(height);


        gridLayout->addLayout(hboxLayout, 3, 1, 1, 2);

        orientlabel = new QLabel(KoPageLayoutWidget);
        orientlabel->setObjectName(QString::fromUtf8("orientlabel"));
        orientlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(orientlabel, 4, 0, 1, 1);

        portrait = new QRadioButton(KoPageLayoutWidget);
        portrait->setObjectName(QString::fromUtf8("portrait"));

        gridLayout->addWidget(portrait, 4, 1, 1, 1);

        landscape = new QRadioButton(KoPageLayoutWidget);
        landscape->setObjectName(QString::fromUtf8("landscape"));

        gridLayout->addWidget(landscape, 4, 2, 1, 1);

        facingPageLabel = new QLabel(KoPageLayoutWidget);
        facingPageLabel->setObjectName(QString::fromUtf8("facingPageLabel"));
        facingPageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(facingPageLabel, 5, 0, 1, 1);

        singleSided = new QRadioButton(KoPageLayoutWidget);
        singleSided->setObjectName(QString::fromUtf8("singleSided"));

        gridLayout->addWidget(singleSided, 5, 1, 1, 1);

        facingPages = new QRadioButton(KoPageLayoutWidget);
        facingPages->setObjectName(QString::fromUtf8("facingPages"));

        gridLayout->addWidget(facingPages, 5, 2, 1, 1);

        directionLabel = new QLabel(KoPageLayoutWidget);
        directionLabel->setObjectName(QString::fromUtf8("directionLabel"));
        directionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(directionLabel, 6, 0, 1, 1);

        textDirection = new QComboBox(KoPageLayoutWidget);
        textDirection->setObjectName(QString::fromUtf8("textDirection"));
        sizePolicy.setHeightForWidth(textDirection->sizePolicy().hasHeightForWidth());
        textDirection->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textDirection, 6, 1, 1, 2);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        vboxLayout->addLayout(gridLayout);

        margins = new QGroupBox(KoPageLayoutWidget);
        margins->setObjectName(QString::fromUtf8("margins"));
        formLayout = new QFormLayout(margins);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        topLabel = new QLabel(margins);
        topLabel->setObjectName(QString::fromUtf8("topLabel"));
        topLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, topLabel);

        topMargin = new KoUnitDoubleSpinBox(margins);
        topMargin->setObjectName(QString::fromUtf8("topMargin"));
        topMargin->setMaximum(999.99);

        formLayout->setWidget(0, QFormLayout::FieldRole, topMargin);

        leftLabel = new QLabel(margins);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));
        leftLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, leftLabel);

        bindingEdgeMargin = new KoUnitDoubleSpinBox(margins);
        bindingEdgeMargin->setObjectName(QString::fromUtf8("bindingEdgeMargin"));
        bindingEdgeMargin->setMaximum(999.99);

        formLayout->setWidget(1, QFormLayout::FieldRole, bindingEdgeMargin);

        rightLabel = new QLabel(margins);
        rightLabel->setObjectName(QString::fromUtf8("rightLabel"));
        rightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, rightLabel);

        pageEdgeMargin = new KoUnitDoubleSpinBox(margins);
        pageEdgeMargin->setObjectName(QString::fromUtf8("pageEdgeMargin"));
        pageEdgeMargin->setMaximum(999.99);

        formLayout->setWidget(2, QFormLayout::FieldRole, pageEdgeMargin);

        bottomLabel = new QLabel(margins);
        bottomLabel->setObjectName(QString::fromUtf8("bottomLabel"));
        bottomLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, bottomLabel);

        bottomMargin = new KoUnitDoubleSpinBox(margins);
        bottomMargin->setObjectName(QString::fromUtf8("bottomMargin"));
        bottomMargin->setMaximum(999.99);

        formLayout->setWidget(3, QFormLayout::FieldRole, bottomMargin);


        vboxLayout->addWidget(margins);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout->addItem(spacerItem);

#ifndef QT_NO_SHORTCUT
        unitsLabel->setBuddy(units);
        stylesLabel->setBuddy(pageStyle);
        sizeLabel->setBuddy(sizes);
        widthLabel->setBuddy(width);
        label->setBuddy(height);
        directionLabel->setBuddy(textDirection);
        topLabel->setBuddy(topMargin);
        leftLabel->setBuddy(bindingEdgeMargin);
        rightLabel->setBuddy(pageEdgeMargin);
        bottomLabel->setBuddy(bottomMargin);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(units, sizes);
        QWidget::setTabOrder(sizes, width);
        QWidget::setTabOrder(width, height);
        QWidget::setTabOrder(height, portrait);
        QWidget::setTabOrder(portrait, landscape);
        QWidget::setTabOrder(landscape, singleSided);
        QWidget::setTabOrder(singleSided, facingPages);
        QWidget::setTabOrder(facingPages, textDirection);
        QWidget::setTabOrder(textDirection, topMargin);
        QWidget::setTabOrder(topMargin, bindingEdgeMargin);
        QWidget::setTabOrder(bindingEdgeMargin, pageEdgeMargin);
        QWidget::setTabOrder(pageEdgeMargin, bottomMargin);

        retranslateUi(KoPageLayoutWidget);

        QMetaObject::connectSlotsByName(KoPageLayoutWidget);
    } // setupUi

    void retranslateUi(QWidget *KoPageLayoutWidget)
    {
        unitsLabel->setText(QApplication::translate("KoPageLayoutWidget", "Unit:", 0, QApplication::UnicodeUTF8));
        stylesLabel->setText(QApplication::translate("KoPageLayoutWidget", "Follow style:", 0, QApplication::UnicodeUTF8));
        sizeLabel->setText(QApplication::translate("KoPageLayoutWidget", "Size:", 0, QApplication::UnicodeUTF8));
        widthLabel->setText(QApplication::translate("KoPageLayoutWidget", "Width:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("KoPageLayoutWidget", "Height:", 0, QApplication::UnicodeUTF8));
        orientlabel->setText(QApplication::translate("KoPageLayoutWidget", "Orientation:", 0, QApplication::UnicodeUTF8));
        portrait->setText(QApplication::translate("KoPageLayoutWidget", "Portrait", 0, QApplication::UnicodeUTF8));
        landscape->setText(QApplication::translate("KoPageLayoutWidget", "Landscape", 0, QApplication::UnicodeUTF8));
        facingPageLabel->setText(QApplication::translate("KoPageLayoutWidget", "Facing pages:", 0, QApplication::UnicodeUTF8));
        singleSided->setText(QApplication::translate("KoPageLayoutWidget", "Single sided", 0, QApplication::UnicodeUTF8));
        facingPages->setText(QApplication::translate("KoPageLayoutWidget", "Facing pages", 0, QApplication::UnicodeUTF8));
        directionLabel->setText(QApplication::translate("KoPageLayoutWidget", "Text direction:", 0, QApplication::UnicodeUTF8));
        textDirection->clear();
        textDirection->insertItems(0, QStringList()
         << QApplication::translate("KoPageLayoutWidget", "Automatic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("KoPageLayoutWidget", "Left to right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("KoPageLayoutWidget", "Right to left", 0, QApplication::UnicodeUTF8)
        );
        margins->setTitle(QApplication::translate("KoPageLayoutWidget", "Margins", 0, QApplication::UnicodeUTF8));
        topLabel->setText(QApplication::translate("KoPageLayoutWidget", "Top:", 0, QApplication::UnicodeUTF8));
        leftLabel->setText(QApplication::translate("KoPageLayoutWidget", "Binding edge:", 0, QApplication::UnicodeUTF8));
        rightLabel->setText(QApplication::translate("KoPageLayoutWidget", "Page edge:", 0, QApplication::UnicodeUTF8));
        bottomLabel->setText(QApplication::translate("KoPageLayoutWidget", "Bottom:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoPageLayoutWidget);
    } // retranslateUi

};

namespace Ui {
    class KoPageLayoutWidget: public Ui_KoPageLayoutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOPAGELAYOUTWIDGET_H
