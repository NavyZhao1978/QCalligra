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
Boston, MA 02110-1301, USA.
*/

#include "KoFilterEntry.h"

#include "KoDocument.h"
#include "KoFilter.h"

#include "KoDebug.h"
#include <QFile>

#include <limits.h> // UINT_MAX


KoFilterEntry::KoFilterEntry(const QString &cfgfile)
{
	//karbon_svg_export.desktop
	//X-KDE-Export=image/svg+xml
	//X-KDE-Import=application/vnd.oasis.opendocument.graphics
	//X-KDE-Library=karbonsvgexport
	//X-KDE-Weight=1

    //import = service->property("X-KDE-Import").toStringList();
	import_.clear();
	import_ += QString::fromLocal8Bit("application/vnd.oasis.opendocument.graphics");

    //export_ = service->property("X-KDE-Export").toStringList();
	export_.clear();
	export_ += QString::fromLocal8Bit("image/svg+xml");

    int w = 1;		//service->property("X-KDE-Weight").toInt();
    weight = w < 0 ? UINT_MAX : static_cast<unsigned int>(w);

    //available = service->property("X-KDE-Available").toString();
	available = QString::fromLocal8Bit("");
}

QList<KoFilterEntry::Ptr> KoFilterEntry::query(const QString & _constr)
{
    kDebug(30500) << "KoFilterEntry::query(" << _constr << " )";
    QList<KoFilterEntry::Ptr> lst;

    //KService::List offers = KServiceTypeTrader::self()->query("CalligraFilter", _constr);

    //KService::List::ConstIterator it = offers.constBegin();
    //unsigned int max = offers.count();
    ////kDebug(30500) <<"Query returned" << max <<" offers";
    //for (unsigned int i = 0; i < max; i++) {
    //    //kDebug(30500) <<"   desktopEntryPath=" << (*it)->desktopEntryPath()
    //    //               << "   library=" << (*it)->library() << endl;
    //    // Append converted offer
    //    lst.append(KoFilterEntry::Ptr(new KoFilterEntry(*it)));
    //    // Next service
    //    it++;
    //}

	lst.append(KoFilterEntry::Ptr(new KoFilterEntry(_constr)));

    return lst;
}

KoFilter* KoFilterEntry::createFilter(KoFilterChain* chain, QObject* parent)
{
	return 0;

    //KPluginLoader loader(*m_service);
    //KLibFactory* factory = loader.factory();

    //if (!factory) {
    //    kWarning(30003) << loader.errorString();
    //    return 0;
    //}

    //QObject* obj = factory->create<KoFilter>(parent);
    //if (!obj || !obj->inherits("KoFilter")) {
    //    delete obj;
    //    return 0;
    //}

    //KoFilter* filter = static_cast<KoFilter*>(obj);
    //filter->m_chain = chain;
    //return filter;
}

