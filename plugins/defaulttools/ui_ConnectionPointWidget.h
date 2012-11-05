/********************************************************************************
** Form generated from reading UI file 'ConnectionPointWidget.ui'
**
** Created: Sat Nov 3 15:33:56 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONPOINTWIDGET_H
#define UI_CONNECTIONPOINTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionPointWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *toggleEditMode;
    QLabel *labelEscape;
    QHBoxLayout *horizontalLayout;
    QToolButton *escapeAll;
    QToolButton *escapeHorz;
    QToolButton *escapeVert;
    QToolButton *escapeLeft;
    QToolButton *escapeRight;
    QToolButton *escapeUp;
    QToolButton *escapeDown;
    QLabel *labelAlign;
    QWidget *SpecialSpacer;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *alignPercent;
    QFrame *line_2;
    QToolButton *alignLeft;
    QToolButton *alignCenterH;
    QToolButton *alignRight;
    QFrame *line;
    QToolButton *alignTop;
    QToolButton *alignCenterV;
    QToolButton *alignBottom;

    void setupUi(QWidget *ConnectionPointWidget)
    {
        if (ConnectionPointWidget->objectName().isEmpty())
            ConnectionPointWidget->setObjectName(QString::fromUtf8("ConnectionPointWidget"));
        ConnectionPointWidget->resize(239, 151);
        gridLayout = new QGridLayout(ConnectionPointWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(0, 88, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 7, 1);

        toggleEditMode = new QCheckBox(ConnectionPointWidget);
        toggleEditMode->setObjectName(QString::fromUtf8("toggleEditMode"));

        gridLayout->addWidget(toggleEditMode, 0, 0, 1, 1);

        labelEscape = new QLabel(ConnectionPointWidget);
        labelEscape->setObjectName(QString::fromUtf8("labelEscape"));

        gridLayout->addWidget(labelEscape, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        escapeAll = new QToolButton(ConnectionPointWidget);
        escapeAll->setObjectName(QString::fromUtf8("escapeAll"));

        horizontalLayout->addWidget(escapeAll);

        escapeHorz = new QToolButton(ConnectionPointWidget);
        escapeHorz->setObjectName(QString::fromUtf8("escapeHorz"));

        horizontalLayout->addWidget(escapeHorz);

        escapeVert = new QToolButton(ConnectionPointWidget);
        escapeVert->setObjectName(QString::fromUtf8("escapeVert"));

        horizontalLayout->addWidget(escapeVert);

        escapeLeft = new QToolButton(ConnectionPointWidget);
        escapeLeft->setObjectName(QString::fromUtf8("escapeLeft"));

        horizontalLayout->addWidget(escapeLeft);

        escapeRight = new QToolButton(ConnectionPointWidget);
        escapeRight->setObjectName(QString::fromUtf8("escapeRight"));

        horizontalLayout->addWidget(escapeRight);

        escapeUp = new QToolButton(ConnectionPointWidget);
        escapeUp->setObjectName(QString::fromUtf8("escapeUp"));

        horizontalLayout->addWidget(escapeUp);

        escapeDown = new QToolButton(ConnectionPointWidget);
        escapeDown->setObjectName(QString::fromUtf8("escapeDown"));

        horizontalLayout->addWidget(escapeDown);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        labelAlign = new QLabel(ConnectionPointWidget);
        labelAlign->setObjectName(QString::fromUtf8("labelAlign"));

        gridLayout->addWidget(labelAlign, 3, 0, 1, 1);

        SpecialSpacer = new QWidget(ConnectionPointWidget);
        SpecialSpacer->setObjectName(QString::fromUtf8("SpecialSpacer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SpecialSpacer->sizePolicy().hasHeightForWidth());
        SpecialSpacer->setSizePolicy(sizePolicy);

        gridLayout->addWidget(SpecialSpacer, 7, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        alignPercent = new QToolButton(ConnectionPointWidget);
        alignPercent->setObjectName(QString::fromUtf8("alignPercent"));

        horizontalLayout_2->addWidget(alignPercent);

        line_2 = new QFrame(ConnectionPointWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        alignLeft = new QToolButton(ConnectionPointWidget);
        alignLeft->setObjectName(QString::fromUtf8("alignLeft"));

        horizontalLayout_2->addWidget(alignLeft);

        alignCenterH = new QToolButton(ConnectionPointWidget);
        alignCenterH->setObjectName(QString::fromUtf8("alignCenterH"));

        horizontalLayout_2->addWidget(alignCenterH);

        alignRight = new QToolButton(ConnectionPointWidget);
        alignRight->setObjectName(QString::fromUtf8("alignRight"));

        horizontalLayout_2->addWidget(alignRight);

        line = new QFrame(ConnectionPointWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        alignTop = new QToolButton(ConnectionPointWidget);
        alignTop->setObjectName(QString::fromUtf8("alignTop"));

        horizontalLayout_2->addWidget(alignTop);

        alignCenterV = new QToolButton(ConnectionPointWidget);
        alignCenterV->setObjectName(QString::fromUtf8("alignCenterV"));

        horizontalLayout_2->addWidget(alignCenterV);

        alignBottom = new QToolButton(ConnectionPointWidget);
        alignBottom->setObjectName(QString::fromUtf8("alignBottom"));

        horizontalLayout_2->addWidget(alignBottom);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);


        retranslateUi(ConnectionPointWidget);

        QMetaObject::connectSlotsByName(ConnectionPointWidget);
    } // setupUi

    void retranslateUi(QWidget *ConnectionPointWidget)
    {
        toggleEditMode->setText(QApplication::translate("ConnectionPointWidget", "Edit Mode", 0, QApplication::UnicodeUTF8));
        labelEscape->setText(QApplication::translate("ConnectionPointWidget", "Escape Direction", 0, QApplication::UnicodeUTF8));
        escapeAll->setText(QString());
        escapeHorz->setText(QString());
        escapeVert->setText(QString());
        escapeLeft->setText(QString());
        escapeRight->setText(QString());
        escapeUp->setText(QString());
        escapeDown->setText(QString());
        labelAlign->setText(QApplication::translate("ConnectionPointWidget", "Alignment", 0, QApplication::UnicodeUTF8));
        alignPercent->setText(QApplication::translate("ConnectionPointWidget", "%", 0, QApplication::UnicodeUTF8));
        alignLeft->setText(QString());
        alignCenterH->setText(QString());
        alignRight->setText(QString());
        alignTop->setText(QString());
        alignCenterV->setText(QString());
        alignBottom->setText(QString());
        Q_UNUSED(ConnectionPointWidget);
    } // retranslateUi

};

namespace Ui {
    class ConnectionPointWidget: public Ui_ConnectionPointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONPOINTWIDGET_H
