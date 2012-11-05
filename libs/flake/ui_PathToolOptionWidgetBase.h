/********************************************************************************
** Form generated from reading UI file 'PathToolOptionWidgetBase.ui'
**
** Created: Sat Nov 3 15:10:57 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHTOOLOPTIONWIDGETBASE_H
#define UI_PATHTOOLOPTIONWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathToolOptionWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pathPage;
    QGridLayout *gridLayout;
    QToolButton *corner;
    QToolButton *smooth;
    QToolButton *symmetric;
    QSpacerItem *spacerItem;
    QToolButton *lineSegment;
    QToolButton *curveSegment;
    QToolButton *linePoint;
    QToolButton *curvePoint;
    QToolButton *addPoint;
    QToolButton *removePoint;
    QToolButton *breakPoint;
    QToolButton *breakSegment;
    QToolButton *joinSegment;
    QToolButton *mergePoints;
    QFrame *line;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *parameterPage;
    QGridLayout *gridLayout1;
    QPushButton *convertToPath;
    QSpacerItem *spacerItem1;
    QWidget *SpecialSpacer;

    void setupUi(QWidget *PathToolOptionWidgetBase)
    {
        if (PathToolOptionWidgetBase->objectName().isEmpty())
            PathToolOptionWidgetBase->setObjectName(QString::fromUtf8("PathToolOptionWidgetBase"));
        PathToolOptionWidgetBase->resize(280, 60);
        verticalLayout = new QVBoxLayout(PathToolOptionWidgetBase);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(PathToolOptionWidgetBase);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        pathPage = new QWidget();
        pathPage->setObjectName(QString::fromUtf8("pathPage"));
        gridLayout = new QGridLayout(pathPage);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        corner = new QToolButton(pathPage);
        corner->setObjectName(QString::fromUtf8("corner"));

        gridLayout->addWidget(corner, 0, 0, 1, 1);

        smooth = new QToolButton(pathPage);
        smooth->setObjectName(QString::fromUtf8("smooth"));

        gridLayout->addWidget(smooth, 0, 1, 1, 1);

        symmetric = new QToolButton(pathPage);
        symmetric->setObjectName(QString::fromUtf8("symmetric"));

        gridLayout->addWidget(symmetric, 0, 2, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 3, 1, 1);

        lineSegment = new QToolButton(pathPage);
        lineSegment->setObjectName(QString::fromUtf8("lineSegment"));

        gridLayout->addWidget(lineSegment, 0, 5, 1, 1);

        curveSegment = new QToolButton(pathPage);
        curveSegment->setObjectName(QString::fromUtf8("curveSegment"));

        gridLayout->addWidget(curveSegment, 0, 6, 1, 1);

        linePoint = new QToolButton(pathPage);
        linePoint->setObjectName(QString::fromUtf8("linePoint"));

        gridLayout->addWidget(linePoint, 0, 7, 1, 1);

        curvePoint = new QToolButton(pathPage);
        curvePoint->setObjectName(QString::fromUtf8("curvePoint"));

        gridLayout->addWidget(curvePoint, 0, 8, 1, 1);

        addPoint = new QToolButton(pathPage);
        addPoint->setObjectName(QString::fromUtf8("addPoint"));

        gridLayout->addWidget(addPoint, 1, 0, 1, 1);

        removePoint = new QToolButton(pathPage);
        removePoint->setObjectName(QString::fromUtf8("removePoint"));

        gridLayout->addWidget(removePoint, 1, 1, 1, 1);

        breakPoint = new QToolButton(pathPage);
        breakPoint->setObjectName(QString::fromUtf8("breakPoint"));

        gridLayout->addWidget(breakPoint, 1, 5, 1, 1);

        breakSegment = new QToolButton(pathPage);
        breakSegment->setObjectName(QString::fromUtf8("breakSegment"));

        gridLayout->addWidget(breakSegment, 1, 6, 1, 1);

        joinSegment = new QToolButton(pathPage);
        joinSegment->setObjectName(QString::fromUtf8("joinSegment"));

        gridLayout->addWidget(joinSegment, 1, 7, 1, 1);

        mergePoints = new QToolButton(pathPage);
        mergePoints->setObjectName(QString::fromUtf8("mergePoints"));

        gridLayout->addWidget(mergePoints, 1, 8, 1, 1);

        line = new QFrame(pathPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 4, 1, 1);

        line_2 = new QFrame(pathPage);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 2, 5, 1, 1);

        stackedWidget->addWidget(pathPage);
        parameterPage = new QWidget();
        parameterPage->setObjectName(QString::fromUtf8("parameterPage"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(parameterPage->sizePolicy().hasHeightForWidth());
        parameterPage->setSizePolicy(sizePolicy1);
        gridLayout1 = new QGridLayout(parameterPage);
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        convertToPath = new QPushButton(parameterPage);
        convertToPath->setObjectName(QString::fromUtf8("convertToPath"));

        gridLayout1->addWidget(convertToPath, 1, 0, 1, 1);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem1, 1, 1, 1, 1);

        SpecialSpacer = new QWidget(parameterPage);
        SpecialSpacer->setObjectName(QString::fromUtf8("SpecialSpacer"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SpecialSpacer->sizePolicy().hasHeightForWidth());
        SpecialSpacer->setSizePolicy(sizePolicy2);

        gridLayout1->addWidget(SpecialSpacer, 2, 0, 1, 1);

        stackedWidget->addWidget(parameterPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(PathToolOptionWidgetBase);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PathToolOptionWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *PathToolOptionWidgetBase)
    {
        corner->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        smooth->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        symmetric->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        lineSegment->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        curveSegment->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        linePoint->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        curvePoint->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        addPoint->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        removePoint->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        breakPoint->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        breakSegment->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        joinSegment->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        mergePoints->setText(QApplication::translate("PathToolOptionWidgetBase", "...", 0, QApplication::UnicodeUTF8));
        convertToPath->setText(QApplication::translate("PathToolOptionWidgetBase", "Convert To Path", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PathToolOptionWidgetBase);
    } // retranslateUi

};

namespace Ui {
    class PathToolOptionWidgetBase: public Ui_PathToolOptionWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHTOOLOPTIONWIDGETBASE_H
