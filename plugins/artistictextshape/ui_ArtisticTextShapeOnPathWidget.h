/********************************************************************************
** Form generated from reading UI file 'ArtisticTextShapeOnPathWidget.ui'
**
** Created: Sat Nov 3 15:33:05 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTISTICTEXTSHAPEONPATHWIDGET_H
#define UI_ARTISTICTEXTSHAPEONPATHWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArtisticTextShapeOnPathWidget
{
public:
    QGridLayout *gridLayout;
    QToolButton *detachFromPath;
    QFrame *line;
    QToolButton *convertToPath;
    QSpacerItem *horizontalSpacer;
    QSlider *startOffset;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ArtisticTextShapeOnPathWidget)
    {
        if (ArtisticTextShapeOnPathWidget->objectName().isEmpty())
            ArtisticTextShapeOnPathWidget->setObjectName(QString::fromUtf8("ArtisticTextShapeOnPathWidget"));
        ArtisticTextShapeOnPathWidget->resize(208, 59);
        gridLayout = new QGridLayout(ArtisticTextShapeOnPathWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        detachFromPath = new QToolButton(ArtisticTextShapeOnPathWidget);
        detachFromPath->setObjectName(QString::fromUtf8("detachFromPath"));

        gridLayout->addWidget(detachFromPath, 0, 0, 1, 1);

        line = new QFrame(ArtisticTextShapeOnPathWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        convertToPath = new QToolButton(ArtisticTextShapeOnPathWidget);
        convertToPath->setObjectName(QString::fromUtf8("convertToPath"));

        gridLayout->addWidget(convertToPath, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(138, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        startOffset = new QSlider(ArtisticTextShapeOnPathWidget);
        startOffset->setObjectName(QString::fromUtf8("startOffset"));
        startOffset->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(startOffset, 1, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 75, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(ArtisticTextShapeOnPathWidget);

        QMetaObject::connectSlotsByName(ArtisticTextShapeOnPathWidget);
    } // setupUi

    void retranslateUi(QWidget *ArtisticTextShapeOnPathWidget)
    {
        detachFromPath->setText(QString());
        convertToPath->setText(QString());
        Q_UNUSED(ArtisticTextShapeOnPathWidget);
    } // retranslateUi

};

namespace Ui {
    class ArtisticTextShapeOnPathWidget: public Ui_ArtisticTextShapeOnPathWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTISTICTEXTSHAPEONPATHWIDGET_H
