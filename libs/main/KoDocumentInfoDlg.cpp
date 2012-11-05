/* This file is part of the KDE project
   Copyright (c) 2000 Simon Hausmann <hausmann@kde.org>
                 2006 Martin Pfeiffer <hubipete@gmx.net>

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

#include "KoDocumentInfoDlg.h"

#include "ui_koDocumentInfoAboutWidget.h"
#include "ui_koDocumentInfoAuthorWidget.h"

#include "KoDocumentInfo.h"
#include "KoDocument.h"
#include "KoMainWindow.h"

#include "KoIcon.h"

//#include <kmimetype.h>
#include <QMessageBox>

//#ifdef KDEPIMLIBS_FOUND
//#include <kabc/addressee.h>
//#include <kabc/stdaddressbook.h>
//#endif

//#include <KoEncryptionChecker.h>

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPixmap>
#include <QDateTime>


class KoDocumentInfoDlg::KoDocumentInfoDlgPrivate
{
public:
    KoDocumentInfoDlgPrivate() :
            m_rdf(0),
            m_toggleEncryption(false),
            m_applyToggleEncryption(false),
            m_documentSaved(false) {}
    ~KoDocumentInfoDlgPrivate() {}

    KoDocumentInfo* m_info;
    QList<QWidget *> m_pages;
    Ui::KoDocumentInfoAboutWidget* m_aboutUi;
    Ui::KoDocumentInfoAuthorWidget* m_authorUi;
    KoDocumentRdfBase* m_rdf;

    bool m_toggleEncryption;
    bool m_applyToggleEncryption;
    bool m_documentSaved;
};


KoDocumentInfoDlg::KoDocumentInfoDlg(QWidget* parent, KoDocumentInfo* docInfo, KoDocumentRdfBase* docRdf)
        : KoTabDialog(parent)
        , d(new KoDocumentInfoDlgPrivate)
{
    d->m_info = docInfo;
    d->m_rdf = docRdf;

    //setWindowTitle(QObject::tr("Document Information"));
    //setInitialSize(QSize(500, 500));
    //setFaceType(KoTabDialog::List);
    //setButtons(QDialog::Accepted | QDialog::Rejected);
    //setDefaultButton(QDialog::Accepted);

    d->m_aboutUi = new Ui::KoDocumentInfoAboutWidget();
    QWidget *infodlg = new QWidget();
    d->m_aboutUi->setupUi(infodlg);
    //if (!KoEncryptionChecker::isEncryptionSupported()) {
    //    d->m_aboutUi->lblEncryptedDesc->setVisible(false);
    //    d->m_aboutUi->lblEncrypted->setVisible(false);
    //    d->m_aboutUi->pbEncrypt->setVisible(false);
    //    d->m_aboutUi->lblEncryptedPic->setVisible(false);
    //}
    //KPageWidgetItem *page = new KPageWidgetItem(infodlg, QObject::tr("General"));
	QWidget *page = infodlg;
    //page->setHeader(QObject::tr("General"));

    // Ugly hack, the mimetype should be a parameter, instead
    //KoDocument* doc = dynamic_cast< KoDocument* >(d->m_info->parent());
    //if (doc) {
    //    KMimeType::Ptr mime = KMimeType::mimeType(doc->mimeType());
    //    if (! mime)
    //        mime = KMimeType::defaultMimeTypePtr();
    //    page->setIcon(QIcon(mime->iconName()));
    //}
    addTab(page, QObject::tr("General"));
    d->m_pages.append(page);

    initAboutTab();

    d->m_authorUi = new Ui::KoDocumentInfoAuthorWidget();
    QWidget *authordlg = new QWidget();
    d->m_authorUi->setupUi(authordlg);
    //page = new KPageWidgetItem(authordlg, QObject::tr("Author"));
	page = authordlg;
    //page->setHeader(QObject::tr("Last saved by"));
    //page->setIcon(QIcon("user-identity"));
    addTab(page, QObject::tr("Author"));
    d->m_pages.append(page);

    initAuthorTab();

    // Saving encryption implies saving the document, this is done after closing the dialog
    connect(this, SIGNAL(hidden()), this, SLOT(slotSaveEncryption()));



}

KoDocumentInfoDlg::~KoDocumentInfoDlg()
{
    delete d->m_authorUi;
    delete d->m_aboutUi;
    delete d;
}

void KoDocumentInfoDlg::slotButtonClicked(int button)
{
    //emit buttonClicked(static_cast<QDialog::ButtonCode>(button));
    //switch (button) {
    //case Ok:

    //    slotApply();
    //    accept();
    //    return;
    //}
    //KoTabDialog::slotButtonClicked(button);
}

bool KoDocumentInfoDlg::isDocumentSaved()
{
    return d->m_documentSaved;
}

void KoDocumentInfoDlg::initAboutTab()
{
    KoDocument* doc = dynamic_cast< KoDocument* >(d->m_info->parent());
    if (!doc)
        return;

    d->m_aboutUi->filePathLabel->setText(doc->localFilePath());

    d->m_aboutUi->leTitle->setText(d->m_info->aboutInfo("title"));
    d->m_aboutUi->leSubject->setText(d->m_info->aboutInfo("subject"));

    d->m_aboutUi->leKeywords->setToolTip(QObject::tr("Use ';' (Example: Office;KDE;Calligra)"));
    if (!d->m_info->aboutInfo("keyword").isEmpty())
        d->m_aboutUi->leKeywords->setText(d->m_info->aboutInfo("keyword"));

    d->m_aboutUi->meComments->setPlainText(d->m_info->aboutInfo("description"));
    if (!doc->mimeType().isEmpty()) {
        //KMimeType::Ptr docmime = KMimeType::mimeType(doc->mimeType());
        //if (docmime)
        //    d->m_aboutUi->lblType->setText(docmime->comment());
    }
    if (!d->m_info->aboutInfo("creation-date").isEmpty()) {
        QDateTime t = QDateTime::fromString(d->m_info->aboutInfo("creation-date"),
                                            Qt::ISODate);
        QString s = t.toString();	//KGlobal::locale()->formatDateTime(t);
        d->m_aboutUi->lblCreated->setText(s + ", " +
                                          d->m_info->aboutInfo("initial-creator"));
    }

    if (!d->m_info->aboutInfo("date").isEmpty()) {
        QDateTime t = QDateTime::fromString(d->m_info->aboutInfo("date"), Qt::ISODate);
        QString s = t.toString();	//KGlobal::locale()->formatDateTime(t);
        d->m_aboutUi->lblModified->setText(s + ", " + d->m_info->authorInfo("creator"));
    }

    d->m_aboutUi->lblRevision->setText(d->m_info->aboutInfo("editing-cycles"));

    if ( doc->supportedSpecialFormats() & KoDocument::SaveEncrypted ) {
        if (doc->specialOutputFlag() == KoDocument::SaveEncrypted) {
            if (d->m_toggleEncryption) {
                d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document will be decrypted"));
                d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-unlocked").pixmap(16));
                d->m_aboutUi->pbEncrypt->setText(QObject::tr("Do not decrypt"));
            } else {
                d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document is encrypted"));
                d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-locked").pixmap(16));
                d->m_aboutUi->pbEncrypt->setText(QObject::tr("D&ecrypt"));
            }
        } else {
            if (d->m_toggleEncryption) {
                d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document will be encrypted."));
                d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-locked").pixmap(16));
                d->m_aboutUi->pbEncrypt->setText(QObject::tr("Do not encrypt"));
            } else {
                d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document is not encrypted"));
                d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-unlocked").pixmap(16));
                d->m_aboutUi->pbEncrypt->setText(QObject::tr("&Encrypt"));
            }
        }
    } else {
        d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document does not support encryption"));
        d->m_aboutUi->pbEncrypt->setEnabled( false );
    }
    connect(d->m_aboutUi->pbReset, SIGNAL(clicked()),
            this, SLOT(slotResetMetaData()));
    connect(d->m_aboutUi->pbEncrypt, SIGNAL(clicked()),
            this, SLOT(slotToggleEncryption()));
}

void KoDocumentInfoDlg::initAuthorTab()
{
    d->m_authorUi->fullName->setText(d->m_info->authorInfo("creator"));
    d->m_authorUi->initials->setText(d->m_info->authorInfo("initial"));
    d->m_authorUi->title->setText(d->m_info->authorInfo("author-title"));
    d->m_authorUi->company->setText(d->m_info->authorInfo("company"));
    d->m_authorUi->email->setText(d->m_info->authorInfo("email"));
    d->m_authorUi->phoneWork->setText(d->m_info->authorInfo("telephone-work"));
    d->m_authorUi->phoneHome->setText(d->m_info->authorInfo("telephone"));
    d->m_authorUi->fax->setText(d->m_info->authorInfo("fax"));
    d->m_authorUi->country->setText(d->m_info->authorInfo("country"));
    d->m_authorUi->postal->setText(d->m_info->authorInfo("postal-code"));
    d->m_authorUi->city->setText(d->m_info->authorInfo("city"));
    d->m_authorUi->street->setText(d->m_info->authorInfo("street"));
    d->m_authorUi->position->setText(d->m_info->authorInfo("position"));
}

void KoDocumentInfoDlg::slotApply()
{
    saveAboutData();

}

void KoDocumentInfoDlg::saveAboutData()
{
    d->m_info->setAboutInfo("keyword", d->m_aboutUi->leKeywords->text());
    d->m_info->setAboutInfo("title", d->m_aboutUi->leTitle->text());
    d->m_info->setAboutInfo("subject", d->m_aboutUi->leSubject->text());
    d->m_info->setAboutInfo("description", d->m_aboutUi->meComments->toPlainText());
    d->m_applyToggleEncryption = d->m_toggleEncryption;
}

void KoDocumentInfoDlg::slotResetMetaData()
{
    d->m_info->resetMetaData();

    if (!d->m_info->aboutInfo("creation-date").isEmpty()) {
        QDateTime t = QDateTime::fromString(d->m_info->aboutInfo("creation-date"),
                                            Qt::ISODate);
        QString s = t.toString();	//KGlobal::locale()->formatDateTime(t);
        d->m_aboutUi->lblCreated->setText(s + ", " +
                                          d->m_info->aboutInfo("initial-creator"));
    }

    if (!d->m_info->aboutInfo("date").isEmpty()) {
        QDateTime t = QDateTime::fromString(d->m_info->aboutInfo("date"), Qt::ISODate);
        QString s = t.toString();	//KGlobal::locale()->formatDateTime(t);
        d->m_aboutUi->lblModified->setText(s + ", " + d->m_info->authorInfo("creator"));
    }

    d->m_aboutUi->lblRevision->setText(d->m_info->aboutInfo("editing-cycles"));
}

void KoDocumentInfoDlg::slotToggleEncryption()
{
    KoDocument* doc = dynamic_cast< KoDocument* >(d->m_info->parent());
    if (!doc)
        return;

    d->m_toggleEncryption = !d->m_toggleEncryption;

    if (doc->specialOutputFlag() == KoDocument::SaveEncrypted) {
        if (d->m_toggleEncryption) {
            d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document will be decrypted"));
            d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-unlocked").pixmap(16));
            d->m_aboutUi->pbEncrypt->setText(QObject::tr("Do not decrypt"));
        } else {
            d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document is encrypted"));
            d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-locked").pixmap(16));
            d->m_aboutUi->pbEncrypt->setText(QObject::tr("D&ecrypt"));
        }
    } else {
        if (d->m_toggleEncryption) {
            d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document will be encrypted."));
            d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-locked").pixmap(16));
            d->m_aboutUi->pbEncrypt->setText(QObject::tr("Do not encrypt"));
        } else {
            d->m_aboutUi->lblEncrypted->setText(QObject::tr("This document is not encrypted"));
            d->m_aboutUi->lblEncryptedPic->setPixmap(koSmallIcon("object-unlocked").pixmap(16));
            d->m_aboutUi->pbEncrypt->setText(QObject::tr("&Encrypt"));
        }
    }
}

void KoDocumentInfoDlg::slotSaveEncryption()
{
    if (!d->m_applyToggleEncryption)
        return;

    KoDocument* doc = dynamic_cast< KoDocument* >(d->m_info->parent());
    if (!doc)
        return;
    KoMainWindow* mainWindow = dynamic_cast< KoMainWindow* >(parent());

    if (doc->specialOutputFlag() == KoDocument::SaveEncrypted) {
        // Decrypt
        if (QMessageBox::warning(
                    this,
					QObject::tr("Confirm Decrypt"),
                    QObject::tr("<qt>Decrypting the document will remove the password protection from it."
                         "<p>Do you still want to decrypt the file?</qt>"),
                    QMessageBox::Yes,
					QMessageBox::No                    
                ) != QMessageBox::Yes) {
            return;
        }
        bool modified = doc->isModified();
        doc->setOutputMimeType(doc->outputMimeType(), doc->specialOutputFlag() & ~KoDocument::SaveEncrypted);
        if (!mainWindow) {
            QMessageBox::information(
                this,
                QObject::tr("<qt>Your document could not be saved automatically."
                     "<p>To complete the decryption, please save the document.</qt>"),
                QObject::tr("Save Document"),
                "DecryptSaveMessage");
            return;
        }
        if (modified && QMessageBox::question(
                    this,
					QObject::tr("Save Document"),
                    QObject::tr("<qt>The document has been changed since it was opened. To complete the decryption the document needs to be saved."
                         "<p>Do you want to save the document now?</qt>"),                    
                    QMessageBox::Yes,
                    QMessageBox::No                    
                ) != QMessageBox::Yes) {
            return;
        }
    } else {
        // Encrypt
        bool modified = doc->isModified();
        if (!doc->url().isEmpty() && !(doc->mimeType().startsWith("application/vnd.oasis.opendocument.") && doc->specialOutputFlag() == 0)) {
      //      KMimeType::Ptr mime = KMimeType::mimeType(doc->mimeType());
      //      QString comment = mime ? mime->comment() : QObject::tr("%1 (unknown file type)").arg(QString::fromLatin1(doc->mimeType()));
      //      if (QMessageBox::warning(
      //                  this,
						//QObject::tr("Change Filetype"),
      //                  QObject::tr("<qt>The document is currently saved as %1. The document needs to be changed to <b>OASIS OpenDocument</b> to be encrypted."
      //                       "<p>Do you want to change the file to OASIS OpenDocument?</qt>").arg(QString("<b>%1</b>").arg(comment)),                        
      //                  QMessageBox::Yes,
      //                  QMessageBox::No
      //              ) != QMessageBox::Yes) {
      //          return;
      //      }
            doc->resetURL();
        }
        doc->setMimeType(doc->nativeOasisMimeType());
        doc->setOutputMimeType(doc->nativeOasisMimeType(), KoDocument::SaveEncrypted);
        if (!mainWindow) {
            QMessageBox::information(
                this,
                QObject::tr("<qt>Your document could not be saved automatically."
                     "<p>To complete the encryption, please save the document.</qt>"),
                QObject::tr("Save Document"),
                "EncryptSaveMessage");
            return;
        }
        if (modified && QMessageBox::question(
                    this,
					QObject::tr("Save Document"),
                    QObject::tr("<qt>The document has been changed since it was opened. To complete the encryption the document needs to be saved."
                         "<p>Do you want to save the document now?</qt>"),
                    QMessageBox::Yes,
                    QMessageBox::No
                ) != QMessageBox::Yes) {
            return;
        }
    }
    // Why do the dirty work ourselves?
    mainWindow->slotFileSave();
    d->m_toggleEncryption = false;
    d->m_applyToggleEncryption = false;
    // Detects when the user cancelled saving
    d->m_documentSaved = !doc->url().isEmpty();
}

QList<QWidget *> KoDocumentInfoDlg::pages() const
{
    return d->m_pages;
}

void KoDocumentInfoDlg::setReadOnly(bool ro)
{
    d->m_aboutUi->meComments->setReadOnly(ro);

    Q_FOREACH(QWidget* page, d->m_pages) {
        Q_FOREACH(QLineEdit* le, page->findChildren<QLineEdit *>()) {
            le->setReadOnly(ro);
        }
        Q_FOREACH(QPushButton* le, page->findChildren<QPushButton *>()) {
            le->setDisabled(ro);
        }
    }
}

//#include <KoDocumentInfoDlg.moc>
