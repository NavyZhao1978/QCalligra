/*
This file is part of the KDE project
Copyright 2005 Inge Wallin <inge@lysator.liu.se>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.

*/

/********************************************************************************
** Form generated from reading UI file 'KoCsvImportDialog.ui'
**
** Created: Fri Sep 7 15:28:29 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOCSVIMPORTDIALOG_H
#define UI_KOCSVIMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <KoShapeController.h>

QT_BEGIN_NAMESPACE

class Ui_KoCsvImportWidget
{
public:
    QVBoxLayout *vboxLayout;
    KoTabDialog *m_tabWidget;
    QWidget *m_dataTab;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1_3;
    QComboBox *comboBoxEncoding;
    QSpacerItem *spacerItem;
    QCheckBox *m_firstRowHeader;
    QCheckBox *m_firstColHeader;
    QSpacerItem *spacerItem1;
    QWidget *m_formatTab;
    QGridLayout *gridLayout;
    QGroupBox *m_delimiterBox;
    QGridLayout *gridLayout1;
    QRadioButton *m_radioComma;
    QRadioButton *m_radioSemicolon;
    QRadioButton *m_radioOther;
    QRadioButton *m_radioTab;
    QRadioButton *m_radioSpace;
    QLineEdit *m_delimiterEdit;
    QSpacerItem *spacerItem2;
    QLabel *label2;
    QComboBox *m_comboQuote;
    QSpacerItem *spacerItem3;
    QLabel *label3;
    QLineEdit *m_decimalSymbol;
    QLabel *label4;
    QLineEdit *m_thousandsSeparator;
    QSpacerItem *spacerItem4;
    QCheckBox *m_ignoreDuplicates;
    QLabel *label1;
    QComboBox *m_formatComboBox;
    QWidget *m_rangesTab;
    QGridLayout *gridLayout2;
    QPushButton *m_updateButton;
    QSpacerItem *spacerItem5;
    QSpacerItem *spacerItem6;
    QSpacerItem *spacerItem7;
    QLabel *TextLabel3_2;
    QLabel *TextLabel3;
    QSpinBox *m_colEnd;
    QLabel *textLabel1_2;
    QSpinBox *m_colStart;
    QLabel *textLabel1;
    QSpinBox *m_rowStart;
    QSpinBox *m_rowEnd;
    QSpacerItem *spacerItem8;
    QTableWidget *m_sheet;

    void setupUi(QWidget *KoCsvImportWidget)
    {
        if (KoCsvImportWidget->objectName().isEmpty())
            KoCsvImportWidget->setObjectName(QString::fromUtf8("KoCsvImportWidget"));
        KoCsvImportWidget->resize(647, 475);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(KoCsvImportWidget->sizePolicy().hasHeightForWidth());
        KoCsvImportWidget->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(KoCsvImportWidget);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_tabWidget = new KoTabDialog(KoCsvImportWidget);
        m_tabWidget->setObjectName(QString::fromUtf8("m_tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_tabWidget->sizePolicy().hasHeightForWidth());
        m_tabWidget->setSizePolicy(sizePolicy1);
        m_tabWidget->setCurrentIndex(0);
        m_dataTab = new QWidget(m_tabWidget);
        m_dataTab->setObjectName(QString::fromUtf8("m_dataTab"));
        vboxLayout1 = new QVBoxLayout(m_dataTab);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1_3 = new QLabel(m_dataTab);
        textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));
        textLabel1_3->setTextFormat(Qt::PlainText);

        hboxLayout->addWidget(textLabel1_3);

        comboBoxEncoding = new QComboBox(m_dataTab);
        comboBoxEncoding->setObjectName(QString::fromUtf8("comboBoxEncoding"));
        comboBoxEncoding->setEditable(true);

        hboxLayout->addWidget(comboBoxEncoding);

        spacerItem = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        vboxLayout1->addLayout(hboxLayout);

        m_firstRowHeader = new QCheckBox(m_dataTab);
        m_firstRowHeader->setObjectName(QString::fromUtf8("m_firstRowHeader"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_firstRowHeader->sizePolicy().hasHeightForWidth());
        m_firstRowHeader->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(m_firstRowHeader);

        m_firstColHeader = new QCheckBox(m_dataTab);
        m_firstColHeader->setObjectName(QString::fromUtf8("m_firstColHeader"));
        sizePolicy2.setHeightForWidth(m_firstColHeader->sizePolicy().hasHeightForWidth());
        m_firstColHeader->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(m_firstColHeader);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem1);

        m_formatTab = new QWidget(m_tabWidget);
        m_formatTab->setObjectName(QString::fromUtf8("m_formatTab"));
        gridLayout = new QGridLayout(m_formatTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        m_delimiterBox = new QGroupBox(m_formatTab);
        m_delimiterBox->setObjectName(QString::fromUtf8("m_delimiterBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_delimiterBox->sizePolicy().hasHeightForWidth());
        m_delimiterBox->setSizePolicy(sizePolicy3);
        gridLayout1 = new QGridLayout(m_delimiterBox);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        m_radioComma = new QRadioButton(m_delimiterBox);
        m_radioComma->setObjectName(QString::fromUtf8("m_radioComma"));
        m_radioComma->setChecked(true);

        gridLayout1->addWidget(m_radioComma, 0, 0, 1, 1);

        m_radioSemicolon = new QRadioButton(m_delimiterBox);
        m_radioSemicolon->setObjectName(QString::fromUtf8("m_radioSemicolon"));

        gridLayout1->addWidget(m_radioSemicolon, 0, 1, 1, 1);

        m_radioOther = new QRadioButton(m_delimiterBox);
        m_radioOther->setObjectName(QString::fromUtf8("m_radioOther"));

        gridLayout1->addWidget(m_radioOther, 0, 2, 1, 1);

        m_radioTab = new QRadioButton(m_delimiterBox);
        m_radioTab->setObjectName(QString::fromUtf8("m_radioTab"));

        gridLayout1->addWidget(m_radioTab, 1, 0, 1, 1);

        m_radioSpace = new QRadioButton(m_delimiterBox);
        m_radioSpace->setObjectName(QString::fromUtf8("m_radioSpace"));

        gridLayout1->addWidget(m_radioSpace, 1, 1, 1, 1);

        m_delimiterEdit = new QLineEdit(m_delimiterBox);
        m_delimiterEdit->setObjectName(QString::fromUtf8("m_delimiterEdit"));
        m_delimiterEdit->setMaximumSize(QSize(50, 16777215));
        m_delimiterEdit->setMaxLength(10);

        gridLayout1->addWidget(m_delimiterEdit, 1, 2, 1, 1);


        gridLayout->addWidget(m_delimiterBox, 0, 0, 4, 1);

        spacerItem2 = new QSpacerItem(20, 111, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem2, 0, 1, 5, 1);

        label2 = new QLabel(m_formatTab);
        label2->setObjectName(QString::fromUtf8("label2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label2->sizePolicy().hasHeightForWidth());
        label2->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label2, 0, 2, 1, 1);

        m_comboQuote = new QComboBox(m_formatTab);
        m_comboQuote->setObjectName(QString::fromUtf8("m_comboQuote"));
        sizePolicy4.setHeightForWidth(m_comboQuote->sizePolicy().hasHeightForWidth());
        m_comboQuote->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(m_comboQuote, 0, 3, 1, 2);

        spacerItem3 = new QSpacerItem(90, 121, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem3, 0, 5, 5, 1);

        label3 = new QLabel(m_formatTab);
        label3->setObjectName(QString::fromUtf8("label3"));

        gridLayout->addWidget(label3, 1, 2, 1, 1);

        m_decimalSymbol = new QLineEdit(m_formatTab);
        m_decimalSymbol->setObjectName(QString::fromUtf8("m_decimalSymbol"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(m_decimalSymbol->sizePolicy().hasHeightForWidth());
        m_decimalSymbol->setSizePolicy(sizePolicy5);
        m_decimalSymbol->setMaximumSize(QSize(30, 16777215));
        m_decimalSymbol->setMaxLength(1);

        gridLayout->addWidget(m_decimalSymbol, 1, 4, 1, 1);

        label4 = new QLabel(m_formatTab);
        label4->setObjectName(QString::fromUtf8("label4"));

        gridLayout->addWidget(label4, 2, 2, 1, 2);

        m_thousandsSeparator = new QLineEdit(m_formatTab);
        m_thousandsSeparator->setObjectName(QString::fromUtf8("m_thousandsSeparator"));
        sizePolicy5.setHeightForWidth(m_thousandsSeparator->sizePolicy().hasHeightForWidth());
        m_thousandsSeparator->setSizePolicy(sizePolicy5);
        m_thousandsSeparator->setMaximumSize(QSize(30, 16777215));
        m_thousandsSeparator->setMaxLength(1);

        gridLayout->addWidget(m_thousandsSeparator, 2, 4, 1, 1);

        spacerItem4 = new QSpacerItem(211, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem4, 3, 2, 1, 3);

        m_ignoreDuplicates = new QCheckBox(m_formatTab);
        m_ignoreDuplicates->setObjectName(QString::fromUtf8("m_ignoreDuplicates"));

        gridLayout->addWidget(m_ignoreDuplicates, 4, 0, 1, 1);

        label1 = new QLabel(m_formatTab);
        label1->setObjectName(QString::fromUtf8("label1"));

        gridLayout->addWidget(label1, 4, 2, 1, 1);

        m_formatComboBox = new QComboBox(m_formatTab);
        m_formatComboBox->setObjectName(QString::fromUtf8("m_formatComboBox"));

        gridLayout->addWidget(m_formatComboBox, 4, 3, 1, 2);

        m_rangesTab = new QWidget(m_tabWidget);
        m_rangesTab->setObjectName(QString::fromUtf8("m_rangesTab"));
        gridLayout2 = new QGridLayout(m_rangesTab);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        gridLayout2->setContentsMargins(0, 0, 0, 0);
        m_updateButton = new QPushButton(m_rangesTab);
        m_updateButton->setObjectName(QString::fromUtf8("m_updateButton"));

        gridLayout2->addWidget(m_updateButton, 2, 5, 1, 1);

        spacerItem5 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem5, 2, 4, 1, 1);

        spacerItem6 = new QSpacerItem(611, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem6, 2, 0, 1, 4);

        spacerItem7 = new QSpacerItem(468, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem7, 1, 4, 1, 2);

        TextLabel3_2 = new QLabel(m_rangesTab);
        TextLabel3_2->setObjectName(QString::fromUtf8("TextLabel3_2"));
        sizePolicy4.setHeightForWidth(TextLabel3_2->sizePolicy().hasHeightForWidth());
        TextLabel3_2->setSizePolicy(sizePolicy4);
        TextLabel3_2->setFrameShape(QFrame::NoFrame);
        TextLabel3_2->setFrameShadow(QFrame::Plain);

        gridLayout2->addWidget(TextLabel3_2, 1, 0, 1, 1);

        TextLabel3 = new QLabel(m_rangesTab);
        TextLabel3->setObjectName(QString::fromUtf8("TextLabel3"));
        sizePolicy4.setHeightForWidth(TextLabel3->sizePolicy().hasHeightForWidth());
        TextLabel3->setSizePolicy(sizePolicy4);
        TextLabel3->setFrameShape(QFrame::NoFrame);
        TextLabel3->setFrameShadow(QFrame::Plain);

        gridLayout2->addWidget(TextLabel3, 0, 0, 1, 1);

        m_colEnd = new QSpinBox(m_rangesTab);
        m_colEnd->setObjectName(QString::fromUtf8("m_colEnd"));

        gridLayout2->addWidget(m_colEnd, 1, 3, 1, 1);

        textLabel1_2 = new QLabel(m_rangesTab);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setTextFormat(Qt::AutoText);
        textLabel1_2->setAlignment(Qt::AlignCenter);
        textLabel1_2->setWordWrap(true);

        gridLayout2->addWidget(textLabel1_2, 1, 2, 1, 1);

        m_colStart = new QSpinBox(m_rangesTab);
        m_colStart->setObjectName(QString::fromUtf8("m_colStart"));
        m_colStart->setValue(1);

        gridLayout2->addWidget(m_colStart, 1, 1, 1, 1);

        textLabel1 = new QLabel(m_rangesTab);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setTextFormat(Qt::AutoText);
        textLabel1->setAlignment(Qt::AlignCenter);
        textLabel1->setWordWrap(true);

        gridLayout2->addWidget(textLabel1, 0, 2, 1, 1);

        m_rowStart = new QSpinBox(m_rangesTab);
        m_rowStart->setObjectName(QString::fromUtf8("m_rowStart"));
        m_rowStart->setValue(1);

        gridLayout2->addWidget(m_rowStart, 0, 1, 1, 1);

        m_rowEnd = new QSpinBox(m_rangesTab);
        m_rowEnd->setObjectName(QString::fromUtf8("m_rowEnd"));

        gridLayout2->addWidget(m_rowEnd, 0, 3, 1, 1);

        spacerItem8 = new QSpacerItem(468, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem8, 0, 4, 1, 2);


        vboxLayout->addWidget(m_tabWidget);

        m_sheet = new QTableWidget(KoCsvImportWidget);
        m_sheet->setObjectName(QString::fromUtf8("m_sheet"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(m_sheet->sizePolicy().hasHeightForWidth());
        m_sheet->setSizePolicy(sizePolicy6);
        m_sheet->setProperty("numRows", QVariant(0));
        m_sheet->setProperty("numCols", QVariant(0));

        vboxLayout->addWidget(m_sheet);

#ifndef QT_NO_SHORTCUT
        textLabel1_3->setBuddy(comboBoxEncoding);
        label2->setBuddy(m_comboQuote);
        label3->setBuddy(m_decimalSymbol);
        label4->setBuddy(m_thousandsSeparator);
        label1->setBuddy(m_formatComboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(KoCsvImportWidget);

        QMetaObject::connectSlotsByName(KoCsvImportWidget);
    } // setupUi

    void retranslateUi(QWidget *KoCsvImportWidget)
    {
        textLabel1_3->setText(QApplication::translate("KoCsvImportWidget", "E&ncoding:", 0, QApplication::UnicodeUTF8));
        m_firstRowHeader->setText(QApplication::translate("KoCsvImportWidget", "First row contains headers", 0, QApplication::UnicodeUTF8));
        m_firstColHeader->setText(QApplication::translate("KoCsvImportWidget", "First column contains headers", 0, QApplication::UnicodeUTF8));
        m_delimiterBox->setTitle(QApplication::translate("KoCsvImportWidget", "Delimiter", 0, QApplication::UnicodeUTF8));
        m_radioComma->setText(QApplication::translate("KoCsvImportWidget", "Comma", 0, QApplication::UnicodeUTF8));
        m_radioSemicolon->setText(QApplication::translate("KoCsvImportWidget", "Semicolon", 0, QApplication::UnicodeUTF8));
        m_radioOther->setText(QApplication::translate("KoCsvImportWidget", "Other", 0, QApplication::UnicodeUTF8));
        m_radioTab->setText(QApplication::translate("KoCsvImportWidget", "Tabulator", 0, QApplication::UnicodeUTF8));
        m_radioSpace->setText(QApplication::translate("KoCsvImportWidget", "Space", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("KoCsvImportWidget", "Text&quote:", 0, QApplication::UnicodeUTF8));
        m_comboQuote->clear();
        m_comboQuote->insertItems(0, QStringList()
         << QApplication::translate("KoCsvImportWidget", "\"", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("KoCsvImportWidget", "'", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("KoCsvImportWidget", "None", 0, QApplication::UnicodeUTF8)
        );
        label3->setText(QApplication::translate("KoCsvImportWidget", "Decimal symbol:", 0, QApplication::UnicodeUTF8));
        label4->setText(QApplication::translate("KoCsvImportWidget", "Thousands separator:", 0, QApplication::UnicodeUTF8));
        m_ignoreDuplicates->setText(QApplication::translate("KoCsvImportWidget", "Ignore duplicate delimiters", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("KoCsvImportWidget", "&Format:", 0, QApplication::UnicodeUTF8));
        m_updateButton->setText(QApplication::translate("KoCsvImportWidget", "Update", 0, QApplication::UnicodeUTF8));
        TextLabel3_2->setText(QApplication::translate("KoCsvImportWidget", "Import columns:", 0, QApplication::UnicodeUTF8));
        TextLabel3->setText(QApplication::translate("KoCsvImportWidget", "Import lines:", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("KoCsvImportWidget", "to", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("KoCsvImportWidget", "to", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoCsvImportWidget);
    } // retranslateUi

};

namespace Ui {
    class KoCsvImportWidget: public Ui_KoCsvImportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOCSVIMPORTDIALOG_H
