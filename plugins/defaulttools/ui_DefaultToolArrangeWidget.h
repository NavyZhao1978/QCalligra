/********************************************************************************
** Form generated from reading UI file 'DefaultToolArrangeWidget.ui'
**
** Created: Sat Nov 3 15:33:53 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTTOOLARRANGEWIDGET_H
#define UI_DEFAULTTOOLARRANGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefaultToolArrangeWidget
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QToolButton *leftAlign;
    QToolButton *hCenterAlign;
    QToolButton *rightAlign;
    QToolButton *topAlign;
    QToolButton *vCenterAlign;
    QToolButton *bottomAlign;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QToolButton *bringToFront;
    QToolButton *raiseLevel;
    QToolButton *sendBack;
    QToolButton *lowerLevel;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QToolButton *ungroup;
    QToolButton *group;
    QSpacerItem *horizontalSpacer;
    QWidget *SpecialSpacer;

    void setupUi(QWidget *DefaultToolArrangeWidget)
    {
        if (DefaultToolArrangeWidget->objectName().isEmpty())
            DefaultToolArrangeWidget->setObjectName(QString::fromUtf8("DefaultToolArrangeWidget"));
        DefaultToolArrangeWidget->resize(208, 70);
        gridLayout_4 = new QGridLayout(DefaultToolArrangeWidget);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        leftAlign = new QToolButton(DefaultToolArrangeWidget);
        leftAlign->setObjectName(QString::fromUtf8("leftAlign"));

        gridLayout->addWidget(leftAlign, 0, 0, 1, 1);

        hCenterAlign = new QToolButton(DefaultToolArrangeWidget);
        hCenterAlign->setObjectName(QString::fromUtf8("hCenterAlign"));

        gridLayout->addWidget(hCenterAlign, 0, 1, 1, 1);

        rightAlign = new QToolButton(DefaultToolArrangeWidget);
        rightAlign->setObjectName(QString::fromUtf8("rightAlign"));

        gridLayout->addWidget(rightAlign, 0, 2, 1, 1);

        topAlign = new QToolButton(DefaultToolArrangeWidget);
        topAlign->setObjectName(QString::fromUtf8("topAlign"));

        gridLayout->addWidget(topAlign, 1, 0, 1, 1);

        vCenterAlign = new QToolButton(DefaultToolArrangeWidget);
        vCenterAlign->setObjectName(QString::fromUtf8("vCenterAlign"));

        gridLayout->addWidget(vCenterAlign, 1, 1, 1, 1);

        bottomAlign = new QToolButton(DefaultToolArrangeWidget);
        bottomAlign->setObjectName(QString::fromUtf8("bottomAlign"));

        gridLayout->addWidget(bottomAlign, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        frame = new QFrame(DefaultToolArrangeWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(frame, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        bringToFront = new QToolButton(DefaultToolArrangeWidget);
        bringToFront->setObjectName(QString::fromUtf8("bringToFront"));

        gridLayout_2->addWidget(bringToFront, 0, 0, 1, 1);

        raiseLevel = new QToolButton(DefaultToolArrangeWidget);
        raiseLevel->setObjectName(QString::fromUtf8("raiseLevel"));

        gridLayout_2->addWidget(raiseLevel, 0, 1, 1, 1);

        sendBack = new QToolButton(DefaultToolArrangeWidget);
        sendBack->setObjectName(QString::fromUtf8("sendBack"));

        gridLayout_2->addWidget(sendBack, 1, 0, 1, 1);

        lowerLevel = new QToolButton(DefaultToolArrangeWidget);
        lowerLevel->setObjectName(QString::fromUtf8("lowerLevel"));

        gridLayout_2->addWidget(lowerLevel, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 2, 1, 1);

        frame_2 = new QFrame(DefaultToolArrangeWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::VLine);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(frame_2, 0, 3, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(2);
        ungroup = new QToolButton(DefaultToolArrangeWidget);
        ungroup->setObjectName(QString::fromUtf8("ungroup"));

        gridLayout_3->addWidget(ungroup, 1, 0, 1, 1);

        group = new QToolButton(DefaultToolArrangeWidget);
        group->setObjectName(QString::fromUtf8("group"));

        gridLayout_3->addWidget(group, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 5, 1, 1);

        SpecialSpacer = new QWidget(DefaultToolArrangeWidget);
        SpecialSpacer->setObjectName(QString::fromUtf8("SpecialSpacer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpecialSpacer->sizePolicy().hasHeightForWidth());
        SpecialSpacer->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(SpecialSpacer, 1, 0, 1, 1);


        retranslateUi(DefaultToolArrangeWidget);

        QMetaObject::connectSlotsByName(DefaultToolArrangeWidget);
    } // setupUi

    void retranslateUi(QWidget *DefaultToolArrangeWidget)
    {
        leftAlign->setText(QString());
        hCenterAlign->setText(QString());
        rightAlign->setText(QString());
        topAlign->setText(QString());
        vCenterAlign->setText(QString());
        bottomAlign->setText(QString());
        bringToFront->setText(QString());
        raiseLevel->setText(QString());
        sendBack->setText(QString());
        lowerLevel->setText(QString());
        ungroup->setText(QString());
        group->setText(QString());
        Q_UNUSED(DefaultToolArrangeWidget);
    } // retranslateUi

};

namespace Ui {
    class DefaultToolArrangeWidget: public Ui_DefaultToolArrangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTTOOLARRANGEWIDGET_H
