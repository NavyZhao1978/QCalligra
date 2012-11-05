/********************************************************************************
** Form generated from reading UI file 'KoDetailsPaneBase.ui'
**
** Created: Sat Nov 3 15:25:51 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KODETAILSPANEBASE_H
#define UI_KODETAILSPANEBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTextBrowser>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoDetailsPaneBase
{
public:
    QGridLayout *gridLayout;
    QSplitter *m_splitter;
    QTreeView *m_documentList;
    QWidget *layoutWidget;
    QGridLayout *gridLayout1;
    QLabel *m_previewLabel;
    QLabel *m_titleLabel;
    QSpacerItem *spacerItem;
    QCheckBox *m_alwaysUseCheckBox;
    QSpacerItem *spacerItem1;
    QFrame *line1;
    QTextBrowser *m_detailsLabel;
    QPushButton *m_openButton;
    QSpacerItem *spacerItem2;

    void setupUi(QWidget *KoDetailsPaneBase)
    {
        if (KoDetailsPaneBase->objectName().isEmpty())
            KoDetailsPaneBase->setObjectName(QString::fromUtf8("KoDetailsPaneBase"));
        KoDetailsPaneBase->resize(598, 556);
        gridLayout = new QGridLayout(KoDetailsPaneBase);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_splitter = new QSplitter(KoDetailsPaneBase);
        m_splitter->setObjectName(QString::fromUtf8("m_splitter"));
        m_splitter->setOrientation(Qt::Horizontal);
        m_documentList = new QTreeView(m_splitter);
        m_documentList->setObjectName(QString::fromUtf8("m_documentList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_documentList->sizePolicy().hasHeightForWidth());
        m_documentList->setSizePolicy(sizePolicy);
        m_documentList->setRootIsDecorated(false);
        m_documentList->setItemsExpandable(false);
        m_splitter->addWidget(m_documentList);
        layoutWidget = new QWidget(m_splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        gridLayout1 = new QGridLayout(layoutWidget);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        m_previewLabel = new QLabel(layoutWidget);
        m_previewLabel->setObjectName(QString::fromUtf8("m_previewLabel"));
        m_previewLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(m_previewLabel, 0, 0, 1, 3);

        m_titleLabel = new QLabel(layoutWidget);
        m_titleLabel->setObjectName(QString::fromUtf8("m_titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        m_titleLabel->setFont(font);
        m_titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(m_titleLabel, 1, 0, 1, 3);

        spacerItem = new QSpacerItem(81, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem, 2, 0, 1, 1);

        m_alwaysUseCheckBox = new QCheckBox(layoutWidget);
        m_alwaysUseCheckBox->setObjectName(QString::fromUtf8("m_alwaysUseCheckBox"));
        m_alwaysUseCheckBox->setEnabled(false);

        gridLayout1->addWidget(m_alwaysUseCheckBox, 2, 1, 1, 1);

        spacerItem1 = new QSpacerItem(81, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem1, 2, 2, 1, 1);

        line1 = new QFrame(layoutWidget);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);
        line1->setFrameShape(QFrame::HLine);

        gridLayout1->addWidget(line1, 4, 0, 1, 3);

        m_detailsLabel = new QTextBrowser(layoutWidget);
        m_detailsLabel->setObjectName(QString::fromUtf8("m_detailsLabel"));
        m_detailsLabel->setFrameShape(QFrame::NoFrame);

        gridLayout1->addWidget(m_detailsLabel, 5, 0, 1, 3);

        m_openButton = new QPushButton(layoutWidget);
        m_openButton->setObjectName(QString::fromUtf8("m_openButton"));
        m_openButton->setEnabled(false);
        m_openButton->setAutoDefault(true);
        m_openButton->setDefault(true);

        gridLayout1->addWidget(m_openButton, 6, 2, 1, 1);

        spacerItem2 = new QSpacerItem(461, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem2, 6, 1, 1, 1);

        m_splitter->addWidget(layoutWidget);

        gridLayout->addWidget(m_splitter, 0, 0, 1, 2);

        QWidget::setTabOrder(m_documentList, m_alwaysUseCheckBox);
        QWidget::setTabOrder(m_alwaysUseCheckBox, m_detailsLabel);

        retranslateUi(KoDetailsPaneBase);

        QMetaObject::connectSlotsByName(KoDetailsPaneBase);
    } // setupUi

    void retranslateUi(QWidget *KoDetailsPaneBase)
    {
        KoDetailsPaneBase->setWindowTitle(QApplication::translate("KoDetailsPaneBase", "DetailsPaneBase", 0, QApplication::UnicodeUTF8));
        m_previewLabel->setText(QString());
        m_titleLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        m_alwaysUseCheckBox->setToolTip(QApplication::translate("KoDetailsPaneBase", "Always use this template at application start up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_alwaysUseCheckBox->setText(QApplication::translate("KoDetailsPaneBase", "Always use this template", 0, QApplication::UnicodeUTF8));
        m_openButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KoDetailsPaneBase: public Ui_KoDetailsPaneBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KODETAILSPANEBASE_H
