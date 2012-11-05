/********************************************************************************
** Form generated from reading UI file 'KoOpenPaneBase.ui'
**
** Created: Sat Nov 3 15:25:50 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOOPENPANEBASE_H
#define UI_KOOPENPANEBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoOpenPaneBase
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTreeWidget *m_sectionList;
    QStackedWidget *m_widgetStack;
    QWidget *WStackPage;

    void setupUi(QWidget *KoOpenPaneBase)
    {
        if (KoOpenPaneBase->objectName().isEmpty())
            KoOpenPaneBase->setObjectName(QString::fromUtf8("KoOpenPaneBase"));
        KoOpenPaneBase->resize(651, 482);
        verticalLayout = new QVBoxLayout(KoOpenPaneBase);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(KoOpenPaneBase);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        m_sectionList = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        m_sectionList->setHeaderItem(__qtreewidgetitem);
        m_sectionList->setObjectName(QString::fromUtf8("m_sectionList"));
        m_sectionList->setIconSize(QSize(48, 48));
        m_sectionList->setRootIsDecorated(false);
        m_sectionList->setUniformRowHeights(false);
        m_sectionList->setSortingEnabled(true);
        m_sectionList->setAllColumnsShowFocus(true);
        splitter->addWidget(m_sectionList);
        m_sectionList->header()->setVisible(false);
        m_widgetStack = new QStackedWidget(splitter);
        m_widgetStack->setObjectName(QString::fromUtf8("m_widgetStack"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_widgetStack->sizePolicy().hasHeightForWidth());
        m_widgetStack->setSizePolicy(sizePolicy);
        WStackPage = new QWidget();
        WStackPage->setObjectName(QString::fromUtf8("WStackPage"));
        m_widgetStack->addWidget(WStackPage);
        splitter->addWidget(m_widgetStack);

        verticalLayout->addWidget(splitter);


        retranslateUi(KoOpenPaneBase);

        QMetaObject::connectSlotsByName(KoOpenPaneBase);
    } // setupUi

    void retranslateUi(QWidget *KoOpenPaneBase)
    {
        Q_UNUSED(KoOpenPaneBase);
    } // retranslateUi

};

namespace Ui {
    class KoOpenPaneBase: public Ui_KoOpenPaneBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOOPENPANEBASE_H
