/*
 *  Copyright (c) 2005 Adrian Page <adrian@pagenet.plus.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
*/

#include <KoID.h>
#include <QList>

#include "KoCompositeOp.h"
#include "KoColorSpace.h"

QString KoCompositeOp::categoryColor()
{
    return QObject::tr("Color");
}

QString KoCompositeOp::categoryArithmetic() { return QObject::tr("Arithmetic"); }
QString KoCompositeOp::categoryNegative()   { return QObject::tr("Negative");   }
QString KoCompositeOp::categoryLight()      { return QObject::tr("Lighten");    }
QString KoCompositeOp::categoryDark()       { return QObject::tr("Darken");     }
QString KoCompositeOp::categoryHSY()        { return QObject::tr("HSY");        }
QString KoCompositeOp::categoryHSI()        { return QObject::tr("HSI");        }
QString KoCompositeOp::categoryHSL()        { return QObject::tr("HSL");        }
QString KoCompositeOp::categoryHSV()        { return QObject::tr("HSV");        }
QString KoCompositeOp::categoryMix()        { return QObject::tr("Mix");        }
QString KoCompositeOp::categoryMisc()       { return QObject::tr("Misc");       }

struct KoCompositeOp::Private {
    const KoColorSpace * colorSpace;
    QString id;
    QString description;
    QString category;
    QBitArray defaultChannelFlags;
};

KoCompositeOp::KoCompositeOp() : d(new Private)
{

}

KoCompositeOp::~KoCompositeOp()
{
    delete d;
}

KoCompositeOp::KoCompositeOp(const KoColorSpace * cs, const QString& id,  const QString& description, const QString & category)
        : d(new Private)
{
    d->colorSpace = cs;
    d->id = id;
    d->description = description;
    d->category = category;
    if (d->category.isEmpty()) {
        d->category = categoryMisc();
    }
}

void KoCompositeOp::composite(quint8 *dstRowStart, qint32 dstRowStride,
                              const quint8 *srcRowStart, qint32 srcRowStride,
                              const quint8 *maskRowStart, qint32 maskRowStride,
                              qint32 rows, qint32 numColumns,
                              quint8 opacity, const QBitArray& channelFlags) const
{
    KoCompositeOp::ParameterInfo params;
    params.dstRowStart   = dstRowStart;
    params.dstRowStride  = dstRowStride;
    params.srcRowStart   = srcRowStart;
    params.srcRowStride  = srcRowStride;
    params.maskRowStart  = maskRowStart;
    params.maskRowStride = maskRowStride;
    params.rows          = rows;
    params.cols          = numColumns;
    params.opacity       = float(opacity) / 255.0f;
    params.flow          = 1.0f;
    params.channelFlags  = channelFlags;
    composite(params);
}

void KoCompositeOp::composite(const KoCompositeOp::ParameterInfo& params) const
{
    composite(params.dstRowStart           , params.dstRowStride ,
              params.srcRowStart           , params.srcRowStride ,
              params.maskRowStart          , params.maskRowStride,
              params.rows                  , params.cols         ,
              quint8(params.opacity*255.0f), params.channelFlags );
}


QString KoCompositeOp::category() const
{
    return d->category;
}

QString KoCompositeOp::id() const
{
    return d->id;
}

QString KoCompositeOp::description() const
{
    return d->description;
}

const KoColorSpace * KoCompositeOp::colorSpace() const
{
    return d->colorSpace;
}
