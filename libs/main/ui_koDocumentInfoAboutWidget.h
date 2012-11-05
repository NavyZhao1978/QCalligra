/********************************************************************************
** Form generated from reading UI file 'koDocumentInfoAboutWidget.ui'
**
** Created: Sat Nov 3 15:25:50 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KODOCUMENTINFOABOUTWIDGET_H
#define UI_KODOCUMENTINFOABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoDocumentInfoAboutWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *filePathInfoLabel;
    QLabel *filePathLabel;
    QFrame *line;
    QLabel *lblTitleDesc;
    QLineEdit *leTitle;
    QLabel *lblSubjectDesc;
    QLineEdit *leSubject;
    QLabel *lblKeywordsDesc;
    QLineEdit *leKeywords;
    QLabel *lbCommentsDesc;
    QTextEdit *meComments;
    QFrame *line_2;
    QLabel *lblTypeDesc;
    QLabel *lblType;
    QLabel *lblCreatedDesc;
    QLabel *lblCreated;
    QLabel *lblModifiedDesc;
    QLabel *lblModified;
    QLabel *lblLastPrintedDesc;
    QLabel *lblLastPrinted;
    QLabel *lblEditingDesc;
    QLabel *lblEditing;
    QPushButton *pbReset;
    QLabel *lblRevisionDesc;
    QLabel *lblRevision;
    QLabel *lblEncryptedDesc;
    QHBoxLayout *hboxLayout;
    QLabel *lblEncryptedPic;
    QLabel *lblEncrypted;
    QSpacerItem *spacerItem;
    QPushButton *pbEncrypt;

    void setupUi(QWidget *KoDocumentInfoAboutWidget)
    {
        if (KoDocumentInfoAboutWidget->objectName().isEmpty())
            KoDocumentInfoAboutWidget->setObjectName(QString::fromUtf8("KoDocumentInfoAboutWidget"));
        KoDocumentInfoAboutWidget->resize(443, 546);
        gridLayout = new QGridLayout(KoDocumentInfoAboutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        filePathInfoLabel = new QLabel(KoDocumentInfoAboutWidget);
        filePathInfoLabel->setObjectName(QString::fromUtf8("filePathInfoLabel"));
        filePathInfoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(filePathInfoLabel, 0, 0, 1, 1);

        filePathLabel = new QLabel(KoDocumentInfoAboutWidget);
        filePathLabel->setObjectName(QString::fromUtf8("filePathLabel"));

        gridLayout->addWidget(filePathLabel, 0, 1, 1, 2);

        line = new QFrame(KoDocumentInfoAboutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 3);

        lblTitleDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblTitleDesc->setObjectName(QString::fromUtf8("lblTitleDesc"));
        lblTitleDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblTitleDesc, 2, 0, 1, 1);

        leTitle = new QLineEdit(KoDocumentInfoAboutWidget);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));

        gridLayout->addWidget(leTitle, 2, 1, 1, 2);

        lblSubjectDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblSubjectDesc->setObjectName(QString::fromUtf8("lblSubjectDesc"));
        lblSubjectDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblSubjectDesc, 3, 0, 1, 1);

        leSubject = new QLineEdit(KoDocumentInfoAboutWidget);
        leSubject->setObjectName(QString::fromUtf8("leSubject"));

        gridLayout->addWidget(leSubject, 3, 1, 1, 2);

        lblKeywordsDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblKeywordsDesc->setObjectName(QString::fromUtf8("lblKeywordsDesc"));
        lblKeywordsDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblKeywordsDesc, 4, 0, 1, 1);

        leKeywords = new QLineEdit(KoDocumentInfoAboutWidget);
        leKeywords->setObjectName(QString::fromUtf8("leKeywords"));

        gridLayout->addWidget(leKeywords, 4, 1, 1, 2);

        lbCommentsDesc = new QLabel(KoDocumentInfoAboutWidget);
        lbCommentsDesc->setObjectName(QString::fromUtf8("lbCommentsDesc"));
        lbCommentsDesc->setAlignment(Qt::AlignLeading|Qt::AlignRight|Qt::AlignTop);

        gridLayout->addWidget(lbCommentsDesc, 5, 0, 1, 1);

        meComments = new QTextEdit(KoDocumentInfoAboutWidget);
        meComments->setObjectName(QString::fromUtf8("meComments"));

        gridLayout->addWidget(meComments, 5, 1, 1, 2);

        line_2 = new QFrame(KoDocumentInfoAboutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 6, 0, 1, 3);

        lblTypeDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblTypeDesc->setObjectName(QString::fromUtf8("lblTypeDesc"));
        lblTypeDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblTypeDesc, 7, 0, 1, 1);

        lblType = new QLabel(KoDocumentInfoAboutWidget);
        lblType->setObjectName(QString::fromUtf8("lblType"));

        gridLayout->addWidget(lblType, 7, 1, 1, 1);

        lblCreatedDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblCreatedDesc->setObjectName(QString::fromUtf8("lblCreatedDesc"));
        lblCreatedDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCreatedDesc, 8, 0, 1, 1);

        lblCreated = new QLabel(KoDocumentInfoAboutWidget);
        lblCreated->setObjectName(QString::fromUtf8("lblCreated"));

        gridLayout->addWidget(lblCreated, 8, 1, 1, 1);

        lblModifiedDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblModifiedDesc->setObjectName(QString::fromUtf8("lblModifiedDesc"));
        lblModifiedDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblModifiedDesc, 9, 0, 1, 1);

        lblModified = new QLabel(KoDocumentInfoAboutWidget);
        lblModified->setObjectName(QString::fromUtf8("lblModified"));

        gridLayout->addWidget(lblModified, 9, 1, 1, 1);

        lblLastPrintedDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblLastPrintedDesc->setObjectName(QString::fromUtf8("lblLastPrintedDesc"));
        lblLastPrintedDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblLastPrintedDesc, 10, 0, 1, 1);

        lblLastPrinted = new QLabel(KoDocumentInfoAboutWidget);
        lblLastPrinted->setObjectName(QString::fromUtf8("lblLastPrinted"));

        gridLayout->addWidget(lblLastPrinted, 10, 1, 1, 1);

        lblEditingDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblEditingDesc->setObjectName(QString::fromUtf8("lblEditingDesc"));
        lblEditingDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblEditingDesc, 11, 0, 1, 1);

        lblEditing = new QLabel(KoDocumentInfoAboutWidget);
        lblEditing->setObjectName(QString::fromUtf8("lblEditing"));

        gridLayout->addWidget(lblEditing, 11, 1, 1, 1);

        pbReset = new QPushButton(KoDocumentInfoAboutWidget);
        pbReset->setObjectName(QString::fromUtf8("pbReset"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbReset->sizePolicy().hasHeightForWidth());
        pbReset->setSizePolicy(sizePolicy);
        pbReset->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(pbReset, 11, 2, 1, 1);

        lblRevisionDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblRevisionDesc->setObjectName(QString::fromUtf8("lblRevisionDesc"));
        lblRevisionDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblRevisionDesc, 12, 0, 1, 1);

        lblRevision = new QLabel(KoDocumentInfoAboutWidget);
        lblRevision->setObjectName(QString::fromUtf8("lblRevision"));

        gridLayout->addWidget(lblRevision, 12, 1, 1, 1);

        lblEncryptedDesc = new QLabel(KoDocumentInfoAboutWidget);
        lblEncryptedDesc->setObjectName(QString::fromUtf8("lblEncryptedDesc"));
        lblEncryptedDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblEncryptedDesc, 13, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        lblEncryptedPic = new QLabel(KoDocumentInfoAboutWidget);
        lblEncryptedPic->setObjectName(QString::fromUtf8("lblEncryptedPic"));

        hboxLayout->addWidget(lblEncryptedPic);

        lblEncrypted = new QLabel(KoDocumentInfoAboutWidget);
        lblEncrypted->setObjectName(QString::fromUtf8("lblEncrypted"));

        hboxLayout->addWidget(lblEncrypted);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        gridLayout->addLayout(hboxLayout, 13, 1, 1, 1);

        pbEncrypt = new QPushButton(KoDocumentInfoAboutWidget);
        pbEncrypt->setObjectName(QString::fromUtf8("pbEncrypt"));
        sizePolicy.setHeightForWidth(pbEncrypt->sizePolicy().hasHeightForWidth());
        pbEncrypt->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pbEncrypt, 13, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        lblTitleDesc->setBuddy(leTitle);
        lblSubjectDesc->setBuddy(leSubject);
        lblKeywordsDesc->setBuddy(leKeywords);
        lbCommentsDesc->setBuddy(meComments);
        lblEditingDesc->setBuddy(pbReset);
#endif // QT_NO_SHORTCUT

        retranslateUi(KoDocumentInfoAboutWidget);

        QMetaObject::connectSlotsByName(KoDocumentInfoAboutWidget);
    } // setupUi

    void retranslateUi(QWidget *KoDocumentInfoAboutWidget)
    {
        filePathInfoLabel->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Path:", 0, QApplication::UnicodeUTF8));
        filePathLabel->setText(QString());
        lblTitleDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Title:", 0, QApplication::UnicodeUTF8));
        lblSubjectDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Subject:", 0, QApplication::UnicodeUTF8));
        lblKeywordsDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Keywords:", 0, QApplication::UnicodeUTF8));
        leKeywords->setText(QString());
        lbCommentsDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Comments:", 0, QApplication::UnicodeUTF8));
        lblTypeDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Type:", 0, QApplication::UnicodeUTF8));
        lblType->setText(QString());
        lblCreatedDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Created:", 0, QApplication::UnicodeUTF8));
        lblCreated->setText(QString());
        lblModifiedDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Modified:", 0, QApplication::UnicodeUTF8));
        lblModified->setText(QString());
        lblLastPrintedDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Last printed:", 0, QApplication::UnicodeUTF8));
        lblLastPrinted->setText(QString());
        lblEditingDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Total editing time:", 0, QApplication::UnicodeUTF8));
        lblEditing->setText(QString());
        pbReset->setText(QApplication::translate("KoDocumentInfoAboutWidget", "&Reset", 0, QApplication::UnicodeUTF8));
        lblRevisionDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Revision number:", 0, QApplication::UnicodeUTF8));
        lblRevision->setText(QString());
        lblEncryptedDesc->setText(QApplication::translate("KoDocumentInfoAboutWidget", "Encryption:", 0, QApplication::UnicodeUTF8));
        lblEncryptedPic->setText(QString());
        lblEncrypted->setText(QString());
        pbEncrypt->setText(QApplication::translate("KoDocumentInfoAboutWidget", "&Encrypt", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoDocumentInfoAboutWidget);
    } // retranslateUi

};

namespace Ui {
    class KoDocumentInfoAboutWidget: public Ui_KoDocumentInfoAboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KODOCUMENTINFOABOUTWIDGET_H
