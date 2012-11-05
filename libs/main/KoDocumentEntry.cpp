/* This file is part of the KDE project
   Copyright (C) 1998, 1999 Torben Weis <weis@kde.org>
   Copyright     2007       David Faure <faure@kde.org>

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
 * Boston, MA 02110-1301, USA.
*/

#include "KoDocumentEntry.h"

#include "KoPart.h"
#include "KoDocument.h"
#include "KoFilter.h"

#include "KoDebug.h"
#include <QFile>

#include <limits.h> // UINT_MAX

KoDocumentEntry::KoDocumentEntry()
{
}

//KoDocumentEntry::KoDocumentEntry(const KService::Ptr& service)
//        : m_service(service)
//{
//}

KoDocumentEntry::~KoDocumentEntry()
{
}

#include "KoDockRegistry.h"

KoPart *KoDocumentEntry::createKoPart(QString* errorMsg) const
{
    QString error;
    //KoPart* part = m_service->createInstance<KoPart>(0, QVariantList(), &error);
	KoPart *part = 0;
	//if( g_pFunCreateDocument )
	//	part = g_pFunCreateDocument();

	KoPluginFactory *factory = KoPluginRegistry::instance()->value("Flow");
    if (factory) {
		part = (KoPart *)factory->create(0, 0);
    }

    if (!part) {
        kWarning(30003) << error;
        if (errorMsg)
            *errorMsg = error;
        return 0;
    }

    return part;
}

KoDocumentEntry KoDocumentEntry::queryByMimeType(const QString & mimetype)
{
	return KoDocumentEntry();

}

QList<KoDocumentEntry> KoDocumentEntry::query(QueryFlags flags, const QString & _constr)
{

    QList<KoDocumentEntry> lst;

    return lst;
}
