/* This file is part of the KDE libraries
   Copyright (C) 2000-2005 David Faure <faure@kde.org>

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

#include "kcfilterbase.h"

#include <QDebug>
#include <QtCore/QIODevice>
//#include <kmimetype.h>

#include "kcgzipfilter.h"
//#if HAVE_BZIP2_SUPPORT
//#include "kbzip2filter.h"
//#endif
//#if HAVE_XZ_SUPPORT
//#include "kxzfilter.h"
//#endif

class KoFilterBase::Private
{
public:
    Private()
        : m_flags(WithHeaders) {}
    FilterFlags m_flags;
};

KoFilterBase::KoFilterBase()
    : m_dev( 0L ), m_bAutoDel( false ), d(new Private)
{
}

KoFilterBase::~KoFilterBase()
{
    if ( m_bAutoDel )
        delete m_dev;
    delete d;
}

void KoFilterBase::setDevice( QIODevice * dev, bool autodelete )
{
    m_dev = dev;
    m_bAutoDel = autodelete;
}

QIODevice * KoFilterBase::device()
{
    return m_dev;
}

bool KoFilterBase::inBufferEmpty() const
{
    return inBufferAvailable() == 0;
}

bool KoFilterBase::outBufferFull() const
{
    return outBufferAvailable() == 0;
}

KoFilterBase * KoFilterBase::findFilterByFileName( const QString & fileName )
{
    if ( fileName.endsWith( QLatin1String(".gz"), Qt::CaseInsensitive ) )
    {
        return new KoGzipFilter;
    }
//#if HAVE_BZIP2_SUPPORT
//    if ( fileName.endsWith( QLatin1String(".bz2"), Qt::CaseInsensitive ) )
//    {
//        return new KBzip2Filter;
//    }
//#endif
//#if HAVE_XZ_SUPPORT
//    if ( fileName.endsWith( QLatin1String(".lzma"), Qt::CaseInsensitive ) || fileName.endsWith( QLatin1String(".xz"), Qt::CaseInsensitive ) )
//    {
//        return new KXzFilter;
//    }
//#endif
//    else
//    {
//        // not a warning, since this is called often with other mimetypes (see #88574)...
//        // maybe we can avoid that though?
//        //qDebug() << "KoFilterBase::findFilterByFileName : no filter found for " << fileName;
//    }

    return 0;
}

KoFilterBase * KoFilterBase::findFilterByMimeType( const QString & mimeType )
{
    if (mimeType == QLatin1String("application/x-gzip")) {
        return new KoGzipFilter;
    }
//#if HAVE_BZIP2_SUPPORT
//    if (mimeType == QLatin1String("application/x-bzip")
//        || mimeType == QLatin1String("application/x-bzip2") // old name, kept for compatibility
//       ) {
//        return new KBzip2Filter;
//    }
//#endif
//#if HAVE_XZ_SUPPORT
//    if ( mimeType == QLatin1String( "application/x-lzma" ) // legacy name, still used
//        || mimeType == QLatin1String( "application/x-xz" ) // current naming
//       ) {
//        return new KXzFilter;
//    }
//#endif
    //const KMimeType::Ptr mime = KMimeType::mimeType(mimeType);
    //if (mime) {
    //    if (mime->is(QString::fromLatin1("application/x-gzip"))) {
    //        return new KoGzipFilter;
    //    }
//#if HAVE_BZIP2_SUPPORT
//        if (mime->is(QString::fromLatin1("application/x-bzip"))) {
//            return new KBzip2Filter;
//        }
//#endif
//#if HAVE_XZ_SUPPORT
//        if (mime->is(QString::fromLatin1("application/x-lzma"))) {
//            return new KXzFilter;
//        }
//
//        if (mime->is(QString::fromLatin1("application/x-xz"))) {
//            return new KXzFilter;
//        }
//#endif
//    }

    // not a warning, since this is called often with other mimetypes (see #88574)...
    // maybe we can avoid that though?
    //qDebug() << "no filter found for" << mimeType;
    return 0;
}

void KoFilterBase::terminate()
{
}

void KoFilterBase::reset()
{
}

void KoFilterBase::setFilterFlags(FilterFlags flags)
{
    d->m_flags = flags;
}

KoFilterBase::FilterFlags KoFilterBase::filterFlags() const
{
    return d->m_flags;
}

void KoFilterBase::virtual_hook( int, void* )
{ /*BASE::virtual_hook( id, data );*/ }
