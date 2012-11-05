/* This file is part of the KDE project
   Copyright (C) 2005-2006 Peter Simonsson <psn@linux.se>
   Copyright 2012 Friedrich W. H. Kossebau <kossebau@kde.org>

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

#include "KoRecentDocumentsPane.h"

#include <QFile>
#include <QStandardItemModel>

#include <QString.h>
#include <QFileInfo>
#include <QFileInfoList>
#include <QIcon>

enum KoRecentDocumentRoles {
    PreviewRole = Qt::UserRole
};

class KoFileListItem : public QStandardItem
{
public:
    KoFileListItem(const QIcon &icon, const QString &text, const QFileInfo& item)
            : QStandardItem(icon, text)
            , m_fileItem(item){
    }

    ~KoFileListItem() {
    }

    const QFileInfo &fileItem() const {
        return m_fileItem;
    }

private:
    QFileInfo m_fileItem;
};


class KoRecentDocumentsPanePrivate
{
public:
    KoRecentDocumentsPanePrivate()
    {
    }

    ~KoRecentDocumentsPanePrivate()
    {
        //foreach(KJob* job, m_previewJobs)
        //    job->kill();
    }

    //QList<KJob*> m_previewJobs;
    QStandardItemModel* m_model;
};


KoRecentDocumentsPane::KoRecentDocumentsPane(QWidget* parent, const QString &_componentData,
        const QString& header)
        : KoDetailsPane(parent, _componentData, header)
        , d(new KoRecentDocumentsPanePrivate)
{
    setFocusProxy(m_documentList);
    //KGuiItem openGItem(QObject::tr("Open This Document"), "document-open");
    //m_openButton->setGuiItem(openGItem);
	m_openButton->setText(QObject::tr("Open This Document", "document-open"));
    m_alwaysUseCheckBox->hide();

    model()->setSortRole(0); // Disable sorting

    //KConfigGroup config(componentData().config(), "RecentFiles");

    int i = 1;
    QString path;
    QFileInfoList fileList;
    QStandardItem* rootItem = model()->invisibleRootItem();

    //do {
    //    path = config.readPathEntry(QString("File%1").arg(i), QString());

    //    if (!path.isEmpty()) {
    //        QString name = config.readPathEntry(QString("Name%1").arg(i), QString());

    //        QUrl url(path);

    //        if (name.isEmpty())
    //            name = url.toString();

    //        if (!url.isValid() || QFile::exists(url.toLocalFile())) {
    //            QFileInfo fileItem(url.toString());
    //            fileList.prepend(fileItem);
    //            //const QIcon icon = QIcon(fileItem.iconName());
    //            KoFileListItem* item = new KoFileListItem(QIcon(), name, fileItem);
    //            item->setEditable(false);
    //            rootItem->insertRow(0, item);
    //        }
    //    }

    //    i++;
    //} while (!path.isEmpty() || i <= 10);


    //Select the first file
    QModelIndex firstIndex = model()->indexFromItem(model()->item(0));
    m_documentList->selectionModel()->select(firstIndex, QItemSelectionModel::Select);
    m_documentList->selectionModel()->setCurrentIndex(firstIndex, QItemSelectionModel::Select);

//#if KDE_IS_VERSION(4,6,80)
//    QStringList availablePlugins = KIO::PreviewJob::availablePlugins();
//    KIO::PreviewJob *previewJob = KIO::filePreview(fileList, QSize(IconExtent, IconExtent), &availablePlugins);
//#else
//    KIO::PreviewJob *previewJob = KIO::filePreview(fileList, IconExtent, IconExtent, 0);
//#endif
//
//    d->m_previewJobs.append(previewJob);
//    connect(previewJob, SIGNAL(result(KJob*)), SLOT(previewResult(KJob*)));
//    connect(previewJob, SIGNAL(gotPreview(QFileInfo,QPixmap)),
//            SLOT(updateIcon(QFileInfo,QPixmap)));
}

KoRecentDocumentsPane::~KoRecentDocumentsPane()
{
    delete d;
}

void KoRecentDocumentsPane::selectionChanged(const QModelIndex& index)
{
    if (index.isValid()) {
        KoFileListItem* item = static_cast<KoFileListItem*>(model()->itemFromIndex(index));
        const QFileInfo fileItem = item->fileItem();

        m_openButton->setEnabled(true);
        m_titleLabel->setText(item->data(Qt::DisplayRole).toString());

        QPixmap preview = item->data(PreviewRole).value<QPixmap>();
//        if (preview.isNull()) {
//            // need to fetch preview
//            const QFileInfoList fileList = QFileInfoList() << fileItem;
//#if KDE_IS_VERSION(4,6,80)
//            QStringList availablePlugins = KIO::PreviewJob::availablePlugins();
//            KIO::PreviewJob *previewJob = KIO::filePreview(fileList, QSize(PreviewExtent, PreviewExtent), &availablePlugins);
//#else
//            KIO::PreviewJob *previewJob = KIO::filePreview(fileList, PreviewExtent, PreviewExtent, 0);
//#endif
//
//            d->m_previewJobs.append(previewJob);
//            connect(previewJob, SIGNAL(result(KJob*)), SLOT(previewResult(KJob*)));
//            connect(previewJob, SIGNAL(gotPreview(QFileInfo,QPixmap)),
//                    SLOT(updatePreview(QFileInfo,QPixmap)));
//
//            // for now set preview to icon
//            preview = item->icon().pixmap(PreviewExtent);
//            if (preview.width() < PreviewExtent && preview.height() < PreviewExtent) {
//                preview = preview.scaled(PreviewExtent, PreviewExtent, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//            }
//        }
        m_previewLabel->setPixmap(preview);

        if (fileItem.isFile()) {
            QString details = QString("<center>%1<br>").arg(fileItem.absolutePath());
            details += "<table border=\"0\">";
            details += QObject::tr("File modification date and time. %1 is date time")
                             .arg(fileItem.absoluteFilePath());
            details += QObject::tr("File access date and time. %1 is date time")
                             .arg(fileItem.absoluteFilePath());
            details += "</table></center>";
            m_detailsLabel->setHtml(details);
        } else {
            m_detailsLabel->clear();
        }
    } else {
        m_openButton->setEnabled(false);
        m_titleLabel->clear();
        m_previewLabel->setPixmap(QPixmap());
        m_detailsLabel->clear();
    }
}

void KoRecentDocumentsPane::openFile()
{
    KoDetailsPane::openFile();
}

void KoRecentDocumentsPane::openFile(const QModelIndex& index)
{
    if (!index.isValid()) return;

    //KConfigGroup cfgGrp(componentData().config(), "TemplateChooserDialog");
    //cfgGrp.writeEntry("LastReturnType", "File");

    KoFileListItem* item = static_cast<KoFileListItem*>(model()->itemFromIndex(index));
    QFileInfo fileItem = item->fileItem();

    if (fileItem.isFile()) {
        emit openUrl(fileItem.absoluteFilePath());
    }
}

void KoRecentDocumentsPane::previewResult(KJob* job)
{
    //d->m_previewJobs.removeOne(job);
}

void KoRecentDocumentsPane::updatePreview(const QFileInfo& fileItem, const QPixmap& preview)
{
    if (preview.isNull()) {
        return;
    }

    QStandardItem* rootItem = model()->invisibleRootItem();

    for (int i = 0; i < rootItem->rowCount(); ++i) {
        KoFileListItem* item = static_cast<KoFileListItem*>(rootItem->child(i));
        if (item->fileItem().absoluteFilePath() == fileItem.absoluteFilePath()) {
            item->setData(preview, PreviewRole);

            if (m_documentList->selectionModel()->currentIndex() == item->index()) {
                m_previewLabel->setPixmap(preview);
            }

            break;
        }
    }
}

void KoRecentDocumentsPane::updateIcon(const QFileInfo& fileItem, const QPixmap& pixmap)
{
    if (pixmap.isNull()) {
        return;
    }

    QStandardItem *rootItem = model()->invisibleRootItem();

    for (int i = 0; i < rootItem->rowCount(); ++i) {
        KoFileListItem *item = static_cast<KoFileListItem*>(rootItem->child(i));
        if (item->fileItem().absoluteFilePath() == fileItem.absoluteFilePath()) {
            // ensure squareness
            QImage icon = pixmap.toImage();
            icon = icon.convertToFormat(QImage::Format_ARGB32);
            icon = icon.copy((icon.width() - IconExtent) / 2, (icon.height() - IconExtent) / 2, IconExtent, IconExtent);

            item->setIcon(QIcon(QPixmap::fromImage(icon)));

            break;
        }
    }
}

//#include <KoRecentDocumentsPane.moc>
