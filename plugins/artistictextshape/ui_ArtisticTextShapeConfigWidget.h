/********************************************************************************
** Form generated from reading UI file 'ArtisticTextShapeConfigWidget.ui'
**
** Created: Sat Nov 3 15:33:04 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTISTICTEXTSHAPECONFIGWIDGET_H
#define UI_ARTISTICTEXTSHAPECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArtisticTextShapeConfigWidget
{
public:
    QGridLayout *gridLayout;
    QFontComboBox *fontFamily;
    QSpinBox *fontSize;
    QHBoxLayout *horizontalLayout;
    QToolButton *anchorStart;
    QToolButton *anchorMiddle;
    QToolButton *anchorEnd;
    QFrame *line;
    QToolButton *bold;
    QToolButton *italic;
    QFrame *line_2;
    QToolButton *superScript;
    QToolButton *subScript;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ArtisticTextShapeConfigWidget)
    {
        if (ArtisticTextShapeConfigWidget->objectName().isEmpty())
            ArtisticTextShapeConfigWidget->setObjectName(QString::fromUtf8("ArtisticTextShapeConfigWidget"));
        ArtisticTextShapeConfigWidget->resize(259, 73);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ArtisticTextShapeConfigWidget->sizePolicy().hasHeightForWidth());
        ArtisticTextShapeConfigWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ArtisticTextShapeConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fontFamily = new QFontComboBox(ArtisticTextShapeConfigWidget);
        fontFamily->setObjectName(QString::fromUtf8("fontFamily"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fontFamily->sizePolicy().hasHeightForWidth());
        fontFamily->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(fontFamily, 0, 0, 1, 1);

        fontSize = new QSpinBox(ArtisticTextShapeConfigWidget);
        fontSize->setObjectName(QString::fromUtf8("fontSize"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fontSize->sizePolicy().hasHeightForWidth());
        fontSize->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(fontSize, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        anchorStart = new QToolButton(ArtisticTextShapeConfigWidget);
        anchorStart->setObjectName(QString::fromUtf8("anchorStart"));

        horizontalLayout->addWidget(anchorStart);

        anchorMiddle = new QToolButton(ArtisticTextShapeConfigWidget);
        anchorMiddle->setObjectName(QString::fromUtf8("anchorMiddle"));

        horizontalLayout->addWidget(anchorMiddle);

        anchorEnd = new QToolButton(ArtisticTextShapeConfigWidget);
        anchorEnd->setObjectName(QString::fromUtf8("anchorEnd"));

        horizontalLayout->addWidget(anchorEnd);

        line = new QFrame(ArtisticTextShapeConfigWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        bold = new QToolButton(ArtisticTextShapeConfigWidget);
        bold->setObjectName(QString::fromUtf8("bold"));

        horizontalLayout->addWidget(bold);

        italic = new QToolButton(ArtisticTextShapeConfigWidget);
        italic->setObjectName(QString::fromUtf8("italic"));

        horizontalLayout->addWidget(italic);

        line_2 = new QFrame(ArtisticTextShapeConfigWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        superScript = new QToolButton(ArtisticTextShapeConfigWidget);
        superScript->setObjectName(QString::fromUtf8("superScript"));

        horizontalLayout->addWidget(superScript);

        subScript = new QToolButton(ArtisticTextShapeConfigWidget);
        subScript->setObjectName(QString::fromUtf8("subScript"));

        horizontalLayout->addWidget(subScript);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);


        retranslateUi(ArtisticTextShapeConfigWidget);

        QMetaObject::connectSlotsByName(ArtisticTextShapeConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *ArtisticTextShapeConfigWidget)
    {
        anchorStart->setText(QString());
        anchorMiddle->setText(QString());
        anchorEnd->setText(QString());
        bold->setText(QString());
        italic->setText(QString());
        superScript->setText(QString());
        subScript->setText(QString());
        Q_UNUSED(ArtisticTextShapeConfigWidget);
    } // retranslateUi

};

namespace Ui {
    class ArtisticTextShapeConfigWidget: public Ui_ArtisticTextShapeConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTISTICTEXTSHAPECONFIGWIDGET_H
