/* This file is part of the KDE project
 * Copyright (C) 2008 Peter Simonsson <peter.simonsson@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "OdfCollectionLoader.h"

#include <KoStore.h>
#include <KoOdfReadStore.h>
#include <KoOdfLoadingContext.h>
#include <KoXmlNS.h>
#include <KoShape.h>
#include <KoShapeRegistry.h>
#include <KoShapeLoadingContext.h>
#include <KoFilterManager.h>
#include <KoOdf.h>

#include "KoDebug.h"
//#include <kmimetype.h>

#include <QTimer>
#include <QDir>
#include <QFile>
#include <QByteArray>

OdfCollectionLoader::OdfCollectionLoader(const QString& path, QObject* parent)
    : QObject(parent)
{
    m_path = path;
    m_odfStore = 0;
    m_shapeLoadingContext = 0;
    m_loadingContext = 0;
    m_filterManager = 0;

    m_loadingTimer = new QTimer(this);
    m_loadingTimer->setInterval(0);
    connect(m_loadingTimer, SIGNAL(timeout()),
            this, SLOT(loadShape()));
}

OdfCollectionLoader::~OdfCollectionLoader()
{
    delete m_filterManager;
    m_filterManager = 0;
    delete m_shapeLoadingContext;
    delete m_loadingContext;
    m_shapeLoadingContext = 0;
    m_loadingContext = 0;

    if(m_odfStore)
    {
        delete m_odfStore->store();
        delete m_odfStore;
        m_odfStore = 0;
    }
}

void OdfCollectionLoader::load()
{
    QDir dir(m_path);
    m_fileList = dir.entryList(QStringList() << "*.odg" << "*.svg", QDir::Files);

    if(m_fileList.isEmpty())
    {
        kError() << "Found no shapes in the collection!" << m_path;
        emit loadingFailed(QObject::tr("Found no shapes in the collection! %1").arg(m_path));
        return;
    }

    nextFile();
}

void OdfCollectionLoader::loadShape()
{
    //kDebug() << m_shape.tagName();
    KoShape * shape = KoShapeRegistry::instance()->createShapeFromOdf(m_shape, *m_shapeLoadingContext);

    if (shape) {
        if(!shape->parent()) {
            m_shapeList.append(shape);
        }
    }

    m_shape = m_shape.nextSibling().toElement();

    if(m_shape.isNull())
    {
        m_page = m_page.nextSibling().toElement();

        if(m_page.isNull())
        {
            m_loadingTimer->stop();

            if(m_fileList.isEmpty())
            {
                emit loadingFinished();
            }
            else
            {
                nextFile();
            }
        }
        else
        {
            m_shape = m_page.firstChild().toElement();
        }
    }
}

void OdfCollectionLoader::nextFile()
{
    QString file = m_fileList.takeFirst();
    QString filepath = m_path + file;
    QUrl u;
    u.setPath(filepath);
    QString mimetype = findMimeTypeByUrl(u);

    QString importedFile = filepath;

    if(mimetype != KoOdf::mimeType(KoOdf::Graphics))
    {
        if(!m_filterManager)
            m_filterManager = new KoFilterManager(QByteArray(KoOdf::mimeType(KoOdf::Graphics)));
        KoFilter::ConversionStatus status;
        importedFile = m_filterManager->importDocument(filepath, QString(), status);
        //kDebug() << "File:" << filepath << "Import:" << importedFile;

        if(status != KoFilter::OK)
        {
            QString msg;

            switch(status)
            {
                case KoFilter::OK: break;

                case KoFilter::CreationError:
                    msg = QObject::tr("Creation error" ); break;

                case KoFilter::FileNotFound:
                    msg = QObject::tr("File not found" ); break;

                case KoFilter::StorageCreationError:
                    msg = QObject::tr("Cannot create storage" ); break;

                case KoFilter::BadMimeType:
                    msg = QObject::tr("Bad MIME type" ); break;

                case KoFilter::EmbeddedDocError:
                    msg = QObject::tr("Error in embedded document" ); break;

                case KoFilter::WrongFormat:
                    msg = QObject::tr("Format not recognized" ); break;

                case KoFilter::NotImplemented:
                    msg = QObject::tr("Not implemented" ); break;

                case KoFilter::ParsingError:
                    msg = QObject::tr("Parsing error" ); break;

                case KoFilter::PasswordProtected:
                    msg = QObject::tr("Document is password protected" ); break;

                case KoFilter::InternalError:
                case KoFilter::UnexpectedEOF:
                case KoFilter::UnexpectedOpcode:
                case KoFilter::StupidError: // ?? what is this ??
                case KoFilter::UsageError:
                    msg = QObject::tr("Internal error" ); break;

                case KoFilter::OutOfMemory:
                    msg = QObject::tr("Out of memory" ); break;

                case KoFilter::UserCancelled:
                case KoFilter::BadConversionGraph:
                    // intentionally we do not prompt the error message here
                    break;

                    default: msg = QObject::tr("Unknown error" ); break;
            }

            if(!msg.isEmpty())
            {
                QString errorMsg(QObject::tr("Could not open\n%2.\nReason: %1").arg(msg).arg(filepath));
                emit loadingFailed(errorMsg);
            }

            return;
        }
    }

    if(!importedFile.isEmpty()) // Something to load (tmp or native file) ?
    {
        loadNativeFile(importedFile);
        if (importedFile != filepath)
        {
            QFile::remove(importedFile);
        }
    } else {
        emit loadingFailed(QObject::tr("Failed to import the file: %1").arg(filepath));
    }
}

void OdfCollectionLoader::loadNativeFile(const QString& path)
{
    delete m_shapeLoadingContext;
    delete m_loadingContext;
    m_shapeLoadingContext = 0;
    m_loadingContext = 0;

    if(m_odfStore)
    {
        delete m_odfStore->store();
        delete m_odfStore;
        m_odfStore = 0;
    }

    KoStore* store = KoStore::createStore(path, KoStore::Read);

    if(store->bad())
    {
        emit loadingFailed(QObject::tr("Not a valid Calligra file: %1").arg(m_path));
        delete store;
        return;
    }

    store->disallowNameExpansion();
    m_odfStore = new KoOdfReadStore(store); // Owns the store now
    QString errorMessage;

    if(!m_odfStore->loadAndParse(errorMessage))
    {
        emit loadingFailed(errorMessage);
        return;
    }

    KoOdfLoadingContext* m_loadingContext = new KoOdfLoadingContext(m_odfStore->styles(), m_odfStore->store());
    // it ok here to pass an empty resourceManager as we don't have a document
    // tz: not sure if that is 100% correct what if an image is loaded in the collection it needs a image collection
    m_shapeLoadingContext = new KoShapeLoadingContext(*m_loadingContext, 0);

    KoXmlElement content = m_odfStore->contentDoc().documentElement();
    KoXmlElement realBody ( KoXml::namedItemNS( content, KoXmlNS::office, "body" ) );

    if (realBody.isNull()) {
        kError() << "No body tag found!" << endl;
        emit loadingFailed(QObject::tr("No body tag found in file: %1").arg(path));
        return;
    }

    m_body = KoXml::namedItemNS(realBody, KoXmlNS::office, "drawing");

    if (m_body.isNull()) {
        kError() << "No office:drawing tag found!" << endl;
        emit loadingFailed(QObject::tr("No office:drawing tag found in file: %1").arg(path));
        return;
    }

    m_page = m_body.firstChild().toElement();

    if (m_page.isNull()) {
        kError() << "No shapes found!" << endl;
        emit loadingFailed(QObject::tr("No shapes found in file: %1").arg(path));
        return;
    }

    m_shape = m_page.firstChild().toElement();

    if (m_shape.isNull()) {
        kError() << "No shapes found!" << endl;
        emit loadingFailed(QObject::tr("No shapes found in file: %1").arg(path));
        return;
    }

    m_loadingTimer->start();
}

QString OdfCollectionLoader::findMimeTypeByUrl(const QUrl& url)
{
    //
    // The following code was copied from KoDocument::openFile()
    //
    //QString typeName = KMimeType::findByUrl(url, 0, true)->name();
	QString typeName = QString::fromLocal8Bit("typeName");

    // Allow to open backup files, don't keep the mimetype application/x-trash.
    if (typeName == "application/x-trash")
    {
        //QString path = url.path();
        //KMimeType::Ptr mime = KMimeType::mimeType(typeName);
        //QStringList patterns = mime ? mime->patterns() : QStringList();

        //// Find the extension that makes it a backup file, and remove it
        //for(QStringList::Iterator it = patterns.begin(); it != patterns.end(); ++it) {
        //    QString ext = *it;
        //    if (!ext.isEmpty() && ext[0] == '*')
        //    {
        //        ext.remove(0, 1);
        //        if (path.endsWith(ext)) {
        //            path.truncate(path.length() - ext.length());
        //            break;
        //        }
        //    }
        //}

        //typeName = KMimeType::findByPath(path, 0, true)->name();
    }

    return typeName;
}

//#include <OdfCollectionLoader.moc>
