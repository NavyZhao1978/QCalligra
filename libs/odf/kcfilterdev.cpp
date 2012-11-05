/* This file is part of the KDE libraries
   Copyright (C) 2000, 2006 David Faure <faure@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "kcfilterdev.h"
#include "kcfilterbase.h"
#include <QDebug>
#include <stdio.h> // for EOF
#include <stdlib.h>
#include <assert.h>
#include <QtCore/QFile>

#define BUFFER_SIZE 8*1024

class KoFilterDev::Private
{
public:
    Private() : bNeedHeader(true), bSkipHeaders(false),
                          autoDeleteFilterBase(false), bOpenedUnderlyingDevice(false),
                          bIgnoreData(false){}
    bool bNeedHeader;
    bool bSkipHeaders;
    bool autoDeleteFilterBase;
    bool bOpenedUnderlyingDevice;
    bool bIgnoreData;
    QByteArray buffer; // Used as 'input buffer' when reading, as 'output buffer' when writing
    QByteArray origFileName;
    KoFilterBase::Result result;
    KoFilterBase *filter;
};

KoFilterDev::KoFilterDev( KoFilterBase * _filter, bool autoDeleteFilterBase )
    : d(new Private)
{
    assert(_filter);
    d->filter = _filter;
    d->autoDeleteFilterBase = autoDeleteFilterBase;
}

KoFilterDev::~KoFilterDev()
{
    if ( isOpen() )
        close();
    if ( d->autoDeleteFilterBase )
        delete d->filter;
    delete d;
}

//static
QIODevice * KoFilterDev::deviceForFile( const QString & fileName, const QString & mimetype,
                                       bool forceFilter )
{
    QFile * f = new QFile( fileName );
    KoFilterBase * base = mimetype.isEmpty() ? KoFilterBase::findFilterByFileName( fileName )
                         : KoFilterBase::findFilterByMimeType( mimetype );
    if ( base )
    {
        base->setDevice(f, true);
        return new KoFilterDev(base, true);
    }
    if(!forceFilter)
        return f;
    else
    {
        delete f;
        return 0L;
    }
}

QIODevice * KoFilterDev::device( QIODevice* inDevice, const QString & mimetype, bool autoDeleteInDevice )
{
   if (inDevice==0)
      return 0;
   KoFilterBase * base = KoFilterBase::findFilterByMimeType(mimetype);
   if ( base )
   {
      base->setDevice(inDevice, autoDeleteInDevice);
      return new KoFilterDev(base, true /* auto-delete "base" */);
   }
   return 0;
}

bool KoFilterDev::open( QIODevice::OpenMode mode )
{
    if (isOpen()) {
        qWarning() << "KoFilterDev::open: device is already open";
        return true; // QFile returns false, but well, the device -is- open...
    }
    //kDebug(7005) << mode;
    if ( mode == QIODevice::ReadOnly )
    {
        d->buffer.resize(0);
    }
    else
    {
        d->buffer.resize( BUFFER_SIZE );
        d->filter->setOutBuffer( d->buffer.data(), d->buffer.size() );
    }
    d->bNeedHeader = !d->bSkipHeaders;
    d->filter->setFilterFlags(d->bSkipHeaders ? KoFilterBase::NoHeaders : KoFilterBase::WithHeaders);
    d->filter->init( mode );
    d->bOpenedUnderlyingDevice = !d->filter->device()->isOpen();
    bool ret = d->bOpenedUnderlyingDevice ? d->filter->device()->open( mode ) : true;
    d->result = KoFilterBase::Ok;

    if ( !ret )
        qWarning() << "KoFilterDev::open: Couldn't open underlying device";
    else
        setOpenMode( mode );

    return ret;
}

void KoFilterDev::close()
{
    if ( !isOpen() )
        return;
    if ( d->filter->mode() == QIODevice::WriteOnly )
        write( 0L, 0 ); // finish writing
    //kDebug(7005) << "Calling terminate().";

    d->filter->terminate();
    if ( d->bOpenedUnderlyingDevice )
        d->filter->device()->close();
    setOpenMode( QIODevice::NotOpen );
}

bool KoFilterDev::seek( qint64 pos )
{
    qint64 ioIndex = this->pos(); // current position
    if ( ioIndex == pos )
        return true;

    //kDebug(7005) << "seek(" << pos << ") called";

    Q_ASSERT ( d->filter->mode() == QIODevice::ReadOnly );

    if ( pos == 0 )
    {
        // We can forget about the cached data
        d->bNeedHeader = !d->bSkipHeaders;
        d->result = KoFilterBase::Ok;
        d->filter->setInBuffer(0L,0);
        d->filter->reset();
        QIODevice::seek(pos);
        return d->filter->device()->reset();
    }

    if ( ioIndex > pos ) // we can start from here
        pos = pos - ioIndex;
    else
    {
        // we have to start from 0 ! Ugly and slow, but better than the previous
        // solution (KTarGz was allocating everything into memory)
        if (!seek(0)) // recursive
            return false;
    }

    //kDebug(7005) << "reading " << pos << " dummy bytes";
    QByteArray dummy( qMin( pos, (qint64)3*BUFFER_SIZE ), 0 );
    d->bIgnoreData = true;
    bool result = ( read( dummy.data(), pos ) == pos );
    d->bIgnoreData = false;
    QIODevice::seek(pos);
    return result;
}

bool KoFilterDev::atEnd() const
{
    return (d->result == KoFilterBase::End)
        && QIODevice::atEnd() // take QIODevice's internal buffer into account
        && d->filter->device()->atEnd();
}

qint64 KoFilterDev::readData( char *data, qint64 maxlen )
{
    Q_ASSERT ( d->filter->mode() == QIODevice::ReadOnly );
    //kDebug(7005) << "maxlen=" << maxlen;
    KoFilterBase* filter = d->filter;

    uint dataReceived = 0;

    // We came to the end of the stream
    if ( d->result == KoFilterBase::End )
        return dataReceived;

    // If we had an error, return -1.
    if ( d->result != KoFilterBase::Ok )
        return -1;


    qint64 outBufferSize;
    if ( d->bIgnoreData )
    {
        outBufferSize = qMin( maxlen, (qint64)3*BUFFER_SIZE );
    }
    else
    {
        outBufferSize = maxlen;
    }
    outBufferSize -= dataReceived;
    qint64 availOut = outBufferSize;
    filter->setOutBuffer( data, outBufferSize );

    while ( dataReceived < maxlen )
    {
        if (filter->inBufferEmpty())
        {
            // Not sure about the best size to set there.
            // For sure, it should be bigger than the header size (see comment in readHeader)
            d->buffer.resize( BUFFER_SIZE );
            // Request data from underlying device
            int size = filter->device()->read( d->buffer.data(),
                                               d->buffer.size() );
            //kDebug(7005) << "got" << size << "bytes from device";
            if (size) {
                filter->setInBuffer( d->buffer.data(), size );
            } else {
                // Not enough data available in underlying device for now
                break;
            }
        }
        if (d->bNeedHeader)
        {
            (void) filter->readHeader();
            d->bNeedHeader = false;
        }

        d->result = filter->uncompress();

        if (d->result == KoFilterBase::Error)
        {
            qWarning() << "KoFilterDev: Error when uncompressing data";
            break;
        }

        // We got that much data since the last time we went here
        uint outReceived = availOut - filter->outBufferAvailable();
        //kDebug(7005) << "avail_out = " << filter->outBufferAvailable() << " result=" << d->result << " outReceived=" << outReceived;
        if( availOut < (uint)filter->outBufferAvailable() )
            qWarning() << " last availOut " << availOut << " smaller than new avail_out=" << filter->outBufferAvailable() << " !";

        dataReceived += outReceived;
        if ( !d->bIgnoreData )  // Move on in the output buffer
        {
            data += outReceived;
            availOut = maxlen - dataReceived;
        }
        else if ( maxlen - dataReceived < outBufferSize )
        {
            availOut = maxlen - dataReceived;
        }
        if (d->result == KoFilterBase::End)
        {
            //kDebug(7005) << "got END. dataReceived=" << dataReceived;
            break; // Finished.
        }
        filter->setOutBuffer( data, availOut );
    }

    return dataReceived;
}

qint64 KoFilterDev::writeData( const char *data /*0 to finish*/, qint64 len )
{
    KoFilterBase* filter = d->filter;
    Q_ASSERT ( filter->mode() == QIODevice::WriteOnly );
    // If we had an error, return 0.
    if ( d->result != KoFilterBase::Ok )
        return 0;

    bool finish = (data == 0L);
    if (!finish)
    {
        filter->setInBuffer( data, len );
        if (d->bNeedHeader)
        {
            (void)filter->writeHeader( d->origFileName );
            d->bNeedHeader = false;
        }
    }

    uint dataWritten = 0;
    uint availIn = len;
    while ( dataWritten < len || finish )
    {

        d->result = filter->compress( finish );

        if (d->result == KoFilterBase::Error)
        {
            qWarning() << "KoFilterDev: Error when compressing data";
            // What to do ?
            break;
        }

        // Wrote everything ?
        if (filter->inBufferEmpty() || (d->result == KoFilterBase::End))
        {
            // We got that much data since the last time we went here
            uint wrote = availIn - filter->inBufferAvailable();

            //kDebug(7005) << " Wrote everything for now. avail_in=" << filter->inBufferAvailable() << "result=" << d->result << "wrote=" << wrote;

            // Move on in the input buffer
            data += wrote;
            dataWritten += wrote;

            availIn = len - dataWritten;
            //kDebug(7005) << " availIn=" << availIn << "dataWritten=" << dataWritten << "pos=" << pos();
            if ( availIn > 0 )
                filter->setInBuffer( data, availIn );
        }

        if (filter->outBufferFull() || (d->result == KoFilterBase::End) || finish)
        {
            //kDebug(7005) << " writing to underlying. avail_out=" << filter->outBufferAvailable();
            int towrite = d->buffer.size() - filter->outBufferAvailable();
            if ( towrite > 0 )
            {
                // Write compressed data to underlying device
                int size = filter->device()->write( d->buffer.data(), towrite );
                if ( size != towrite ) {
                    qWarning() << "KoFilterDev::write. Could only write " << size << " out of " << towrite << " bytes";
                    return 0; // indicate an error (happens on disk full)
                }
                //else
                    //kDebug(7005) << " wrote " << size << " bytes";
            }
            if (d->result == KoFilterBase::End)
            {
                //kDebug(7005) << " END";
                Q_ASSERT(finish); // hopefully we don't get end before finishing
                break;
            }
            d->buffer.resize(BUFFER_SIZE);
            filter->setOutBuffer( d->buffer.data(), d->buffer.size() );
        }
    }

    return dataWritten;
}

void KoFilterDev::setOrigFileName( const QByteArray & fileName )
{
    d->origFileName = fileName;
}

void KoFilterDev::setSkipHeaders()
{
    d->bSkipHeaders = true;
}
