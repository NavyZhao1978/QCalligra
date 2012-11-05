/********************************************************************************
** Form generated from reading UI file 'KoZoomToolWidget.ui'
**
** Created: Sat Nov 3 15:10:57 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOZOOMTOOLWIDGET_H
#define UI_KOZOOMTOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZoomToolWidget
{
public:
    QGridLayout *gridLayout;
    QRadioButton *zoomInButton;
    QRadioButton *zoomOutButton;
    QLabel *birdEyeLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ZoomToolWidget)
    {
        if (ZoomToolWidget->objectName().isEmpty())
            ZoomToolWidget->setObjectName(QString::fromUtf8("ZoomToolWidget"));
        ZoomToolWidget->resize(212, 261);
        gridLayout = new QGridLayout(ZoomToolWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        zoomInButton = new QRadioButton(ZoomToolWidget);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
        zoomInButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(zoomInButton, 0, 0, 1, 1);

        zoomOutButton = new QRadioButton(ZoomToolWidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        zoomOutButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(zoomOutButton, 0, 1, 1, 1);

        birdEyeLabel = new QLabel(ZoomToolWidget);
        birdEyeLabel->setObjectName(QString::fromUtf8("birdEyeLabel"));

        gridLayout->addWidget(birdEyeLabel, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(ZoomToolWidget);

        QMetaObject::connectSlotsByName(ZoomToolWidget);
    } // setupUi

    void retranslateUi(QWidget *ZoomToolWidget)
    {
        zoomInButton->setText(QApplication::translate("ZoomToolWidget", "Zoom In", 0, QApplication::UnicodeUTF8));
        zoomOutButton->setText(QApplication::translate("ZoomToolWidget", "Zoom Out", 0, QApplication::UnicodeUTF8));
        birdEyeLabel->setText(QString());
        Q_UNUSED(ZoomToolWidget);
    } // retranslateUi

};

namespace Ui {
    class ZoomToolWidget: public Ui_ZoomToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOZOOMTOOLWIDGET_H
