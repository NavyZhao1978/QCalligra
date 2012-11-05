/********************************************************************************
** Form generated from reading UI file 'SnapGuideConfigWidget.ui'
**
** Created: Sat Nov 3 15:10:57 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPGUIDECONFIGWIDGET_H
#define UI_SNAPGUIDECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnapGuideConfigWidget
{
public:
    QGridLayout *gridLayout;
    QCheckBox *useSnapGuides;
    QToolButton *nodeSnapGuide;
    QToolButton *extensionSnapGuide;
    QToolButton *boundingBoxSnapGuide;
    QSpinBox *snapDistance;
    QToolButton *orthogonalSnapGuide;
    QToolButton *intersectionSnapGuide;
    QToolButton *lineGuideSnapGuide;
    QWidget *SpecialSpacer;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *SnapGuideConfigWidget)
    {
        if (SnapGuideConfigWidget->objectName().isEmpty())
            SnapGuideConfigWidget->setObjectName(QString::fromUtf8("SnapGuideConfigWidget"));
        SnapGuideConfigWidget->resize(218, 66);
        gridLayout = new QGridLayout(SnapGuideConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        useSnapGuides = new QCheckBox(SnapGuideConfigWidget);
        useSnapGuides->setObjectName(QString::fromUtf8("useSnapGuides"));

        gridLayout->addWidget(useSnapGuides, 0, 0, 1, 1);

        nodeSnapGuide = new QToolButton(SnapGuideConfigWidget);
        nodeSnapGuide->setObjectName(QString::fromUtf8("nodeSnapGuide"));
        nodeSnapGuide->setCheckable(true);

        gridLayout->addWidget(nodeSnapGuide, 0, 1, 1, 1);

        extensionSnapGuide = new QToolButton(SnapGuideConfigWidget);
        extensionSnapGuide->setObjectName(QString::fromUtf8("extensionSnapGuide"));
        extensionSnapGuide->setCheckable(true);

        gridLayout->addWidget(extensionSnapGuide, 0, 2, 1, 1);

        boundingBoxSnapGuide = new QToolButton(SnapGuideConfigWidget);
        boundingBoxSnapGuide->setObjectName(QString::fromUtf8("boundingBoxSnapGuide"));
        boundingBoxSnapGuide->setCheckable(true);

        gridLayout->addWidget(boundingBoxSnapGuide, 0, 3, 1, 1);

        snapDistance = new QSpinBox(SnapGuideConfigWidget);
        snapDistance->setObjectName(QString::fromUtf8("snapDistance"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(snapDistance->sizePolicy().hasHeightForWidth());
        snapDistance->setSizePolicy(sizePolicy);

        gridLayout->addWidget(snapDistance, 1, 0, 1, 1);

        orthogonalSnapGuide = new QToolButton(SnapGuideConfigWidget);
        orthogonalSnapGuide->setObjectName(QString::fromUtf8("orthogonalSnapGuide"));
        orthogonalSnapGuide->setCheckable(true);

        gridLayout->addWidget(orthogonalSnapGuide, 1, 1, 1, 1);

        intersectionSnapGuide = new QToolButton(SnapGuideConfigWidget);
        intersectionSnapGuide->setObjectName(QString::fromUtf8("intersectionSnapGuide"));
        intersectionSnapGuide->setCheckable(true);

        gridLayout->addWidget(intersectionSnapGuide, 1, 2, 1, 1);

        lineGuideSnapGuide = new QToolButton(SnapGuideConfigWidget);
        lineGuideSnapGuide->setObjectName(QString::fromUtf8("lineGuideSnapGuide"));
        lineGuideSnapGuide->setCheckable(true);

        gridLayout->addWidget(lineGuideSnapGuide, 1, 3, 1, 1);

        SpecialSpacer = new QWidget(SnapGuideConfigWidget);
        SpecialSpacer->setObjectName(QString::fromUtf8("SpecialSpacer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SpecialSpacer->sizePolicy().hasHeightForWidth());
        SpecialSpacer->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(SpecialSpacer, 2, 1, 1, 1);

        spacerItem = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 4, 1, 1);

        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(4, 1);

        retranslateUi(SnapGuideConfigWidget);

        QMetaObject::connectSlotsByName(SnapGuideConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *SnapGuideConfigWidget)
    {
        useSnapGuides->setText(QString());
#ifndef QT_NO_TOOLTIP
        nodeSnapGuide->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Nodes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nodeSnapGuide->setText(QString());
#ifndef QT_NO_TOOLTIP
        extensionSnapGuide->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Extension of lines", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        extensionSnapGuide->setText(QString());
#ifndef QT_NO_TOOLTIP
        boundingBoxSnapGuide->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Bounding box of shape", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        boundingBoxSnapGuide->setText(QString());
#ifndef QT_NO_TOOLTIP
        snapDistance->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Proximity distance where snapping happens", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        snapDistance->setSuffix(QApplication::translate("SnapGuideConfigWidget", " px", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        orthogonalSnapGuide->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Orthogonal", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        orthogonalSnapGuide->setText(QString());
#ifndef QT_NO_TOOLTIP
        intersectionSnapGuide->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Intersection of lines", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        intersectionSnapGuide->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineGuideSnapGuide->setToolTip(QApplication::translate("SnapGuideConfigWidget", "Guide lines", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineGuideSnapGuide->setText(QString());
        Q_UNUSED(SnapGuideConfigWidget);
    } // retranslateUi

};

namespace Ui {
    class SnapGuideConfigWidget: public Ui_SnapGuideConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPGUIDECONFIGWIDGET_H
