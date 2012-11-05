/*
 *  Copyright (c) 2007 Cyrille Berger <cberger@cberger.net>
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

#include "KoColorModelStandardIds.h"

const KoID AlphaColorModelID("A", QObject::tr("Alpha"));
const KoID RGBAColorModelID("RGBA", QObject::tr("Red Green Blue"));
const KoID XYZAColorModelID("XYZA", QObject::tr("XYZ"));
const KoID LABAColorModelID("LABA", QObject::tr("L a* b*"));
const KoID CMYKAColorModelID("CMYKA", QObject::tr("Cyan Magenta Yellow Black"));
const KoID GrayAColorModelID("GRAYA", QObject::tr("Grayscale"));
const KoID GrayColorModelID("GRAY", QObject::tr("Grayscale (without transparency)"));
const KoID YCbCrAColorModelID("YCbCrA", QObject::tr("YCbCr"));

const KoID Integer8BitsColorDepthID("U8", QObject::tr("8 Bits"));
const KoID Integer16BitsColorDepthID("U16", QObject::tr("16 Bits"));
const KoID Float16BitsColorDepthID("F16", QObject::tr("16 Bits Float"));
const KoID Float32BitsColorDepthID("F32", QObject::tr("32 Bits Float"));
const KoID Float64BitsColorDepthID("F64", QObject::tr("64 Bits Float"));
