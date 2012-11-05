/********************************************************************************
** Form generated from reading UI file 'InsertGuidesToolOptionWidget.ui'
**
** Created: Sat Nov 3 15:33:47 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTGUIDESTOOLOPTIONWIDGET_H
#define UI_INSERTGUIDESTOOLOPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertGuidesToolOptionWidget
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QDoubleSpinBox *m_horizontalSpinBox;
    QToolButton *m_horizontalEdgesCheckBox;
    QHBoxLayout *hboxLayout1;
    QLabel *label1;
    QDoubleSpinBox *m_verticalSpinBox;
    QToolButton *m_verticalEdgesCheckBox;
    QHBoxLayout *hboxLayout2;
    QCheckBox *m_erasePreviousCheckBox;
    QPushButton *m_createButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *InsertGuidesToolOptionWidget)
    {
        if (InsertGuidesToolOptionWidget->objectName().isEmpty())
            InsertGuidesToolOptionWidget->setObjectName(QString::fromUtf8("InsertGuidesToolOptionWidget"));
        InsertGuidesToolOptionWidget->resize(230, 103);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InsertGuidesToolOptionWidget->sizePolicy().hasHeightForWidth());
        InsertGuidesToolOptionWidget->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(InsertGuidesToolOptionWidget);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(InsertGuidesToolOptionWidget);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        m_horizontalSpinBox = new QDoubleSpinBox(InsertGuidesToolOptionWidget);
        m_horizontalSpinBox->setObjectName(QString::fromUtf8("m_horizontalSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_horizontalSpinBox->sizePolicy().hasHeightForWidth());
        m_horizontalSpinBox->setSizePolicy(sizePolicy1);
        m_horizontalSpinBox->setMinimum(0);
        m_horizontalSpinBox->setMaximum(100);

        hboxLayout->addWidget(m_horizontalSpinBox);

        m_horizontalEdgesCheckBox = new QToolButton(InsertGuidesToolOptionWidget);
        m_horizontalEdgesCheckBox->setObjectName(QString::fromUtf8("m_horizontalEdgesCheckBox"));
        m_horizontalEdgesCheckBox->setCheckable(true);

        hboxLayout->addWidget(m_horizontalEdgesCheckBox);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label1 = new QLabel(InsertGuidesToolOptionWidget);
        label1->setObjectName(QString::fromUtf8("label1"));

        hboxLayout1->addWidget(label1);

        m_verticalSpinBox = new QDoubleSpinBox(InsertGuidesToolOptionWidget);
        m_verticalSpinBox->setObjectName(QString::fromUtf8("m_verticalSpinBox"));
        sizePolicy1.setHeightForWidth(m_verticalSpinBox->sizePolicy().hasHeightForWidth());
        m_verticalSpinBox->setSizePolicy(sizePolicy1);
        m_verticalSpinBox->setMinimum(0);
        m_verticalSpinBox->setMaximum(100);

        hboxLayout1->addWidget(m_verticalSpinBox);

        m_verticalEdgesCheckBox = new QToolButton(InsertGuidesToolOptionWidget);
        m_verticalEdgesCheckBox->setObjectName(QString::fromUtf8("m_verticalEdgesCheckBox"));
        m_verticalEdgesCheckBox->setCheckable(true);

        hboxLayout1->addWidget(m_verticalEdgesCheckBox);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        m_erasePreviousCheckBox = new QCheckBox(InsertGuidesToolOptionWidget);
        m_erasePreviousCheckBox->setObjectName(QString::fromUtf8("m_erasePreviousCheckBox"));

        hboxLayout2->addWidget(m_erasePreviousCheckBox);

        m_createButton = new QPushButton(InsertGuidesToolOptionWidget);
        m_createButton->setObjectName(QString::fromUtf8("m_createButton"));

        hboxLayout2->addWidget(m_createButton);


        vboxLayout->addLayout(hboxLayout2);

        verticalSpacer = new QSpacerItem(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout->addItem(verticalSpacer);


        retranslateUi(InsertGuidesToolOptionWidget);

        QMetaObject::connectSlotsByName(InsertGuidesToolOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *InsertGuidesToolOptionWidget)
    {
        label->setText(QApplication::translate("InsertGuidesToolOptionWidget", "Horizontal", 0, QApplication::UnicodeUTF8));
        m_horizontalSpinBox->setSpecialValueText(QApplication::translate("InsertGuidesToolOptionWidget", "None", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_horizontalSpinBox->setToolTip(QApplication::translate("InsertGuidesToolOptionWidget", "Insert this number of horizontal equally spaced guides.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_horizontalEdgesCheckBox->setToolTip(QApplication::translate("InsertGuidesToolOptionWidget", "Insert guides at the horizontal edges.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label1->setText(QApplication::translate("InsertGuidesToolOptionWidget", "Vertical", 0, QApplication::UnicodeUTF8));
        m_verticalSpinBox->setSpecialValueText(QApplication::translate("InsertGuidesToolOptionWidget", "None", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_verticalSpinBox->setToolTip(QApplication::translate("InsertGuidesToolOptionWidget", "Insert this number of vertical equally spaced guides.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_verticalEdgesCheckBox->setToolTip(QApplication::translate("InsertGuidesToolOptionWidget", "Insert guides at the vertical edges.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_erasePreviousCheckBox->setText(QApplication::translate("InsertGuidesToolOptionWidget", "Erase previous guides", 0, QApplication::UnicodeUTF8));
        m_createButton->setText(QApplication::translate("InsertGuidesToolOptionWidget", "Create", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(InsertGuidesToolOptionWidget);
    } // retranslateUi

};

namespace Ui {
    class InsertGuidesToolOptionWidget: public Ui_InsertGuidesToolOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTGUIDESTOOLOPTIONWIDGET_H
