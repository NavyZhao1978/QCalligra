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

#include <KcGlobal.h>

#include <KoID.h>
#include <QList>

#include "KoCompositeOp.h"
#include "KoColorSpace.h"

KoCompositeOpRegistry::KoCompositeOpRegistry()
{
    m_categories
        << KoID("arithmetic", QObject::tr("Arithmetic"))
        << KoID("dark"      , QObject::tr("Darken"))
        << KoID("light"     , QObject::tr("Lighten"))
        << KoID("negative"  , QObject::tr("Negative"))
        << KoID("mix"       , QObject::tr("Mix"))
        << KoID("misc"      , QObject::tr("Misc"))
        << KoID("hsy"       , QObject::tr("HSY"))
        << KoID("hsi"       , QObject::tr("HSI"))
        << KoID("hsl"       , QObject::tr("HSL"))
        << KoID("hsv"       , QObject::tr("HSV"));

    m_map.insert(m_categories[0], KoID(COMPOSITE_ADD             , QObject::tr("Addition")));
    m_map.insert(m_categories[0], KoID(COMPOSITE_SUBTRACT        , QObject::tr("Subtract")));
    m_map.insert(m_categories[0], KoID(COMPOSITE_MULT            , QObject::tr("Multiply")));
    m_map.insert(m_categories[0], KoID(COMPOSITE_DIVIDE          , QObject::tr("Divide")));
    m_map.insert(m_categories[0], KoID(COMPOSITE_INVERSE_SUBTRACT, QObject::tr("Inverse Subtract")));

    m_map.insert(m_categories[1], KoID(COMPOSITE_BURN       , QObject::tr("Burn")));
    m_map.insert(m_categories[1], KoID(COMPOSITE_LINEAR_BURN, QObject::tr("Linear Burn")));
    m_map.insert(m_categories[1], KoID(COMPOSITE_DARKEN     , QObject::tr("Darken")));
    m_map.insert(m_categories[1], KoID(COMPOSITE_GAMMA_DARK , QObject::tr("Gamma Dark")));

    m_map.insert(m_categories[2], KoID(COMPOSITE_DODGE       , QObject::tr("Color Dodge")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_LINEAR_DODGE, QObject::tr("Linear Dodge")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_LIGHTEN     , QObject::tr("Lighten")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_LINEAR_LIGHT, QObject::tr("Linear Light")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_SCREEN      , QObject::tr("Screen")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_PIN_LIGHT   , QObject::tr("Pin Light")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_VIVID_LIGHT , QObject::tr("Vivid Light")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_HARD_LIGHT  , QObject::tr("Hard Light")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_SOFT_LIGHT  , QObject::tr("Soft Light")));
    m_map.insert(m_categories[2], KoID(COMPOSITE_GAMMA_LIGHT , QObject::tr("Gamma Light")));

    m_map.insert(m_categories[3], KoID(COMPOSITE_DIFF                 , QObject::tr("Difference")));
    m_map.insert(m_categories[3], KoID(COMPOSITE_EQUIVALENCE          , QObject::tr("Equivalence")));
    m_map.insert(m_categories[3], KoID(COMPOSITE_ADDITIVE_SUBTRACTIVE , QObject::tr("Additive Subtractive")));
    m_map.insert(m_categories[3], KoID(COMPOSITE_EXCLUSION            , QObject::tr("Exclusion")));
    m_map.insert(m_categories[3], KoID(COMPOSITE_ARC_TANGENT          , QObject::tr("Arcus Tangent")));

    m_map.insert(m_categories[4], KoID(COMPOSITE_OVER          , QObject::tr("Normal")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_BEHIND        , QObject::tr("Behind")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_OVERLAY       , QObject::tr("Overlay")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_ERASE         , QObject::tr("Erase")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_ALPHA_DARKEN  , QObject::tr("Alpha Darken")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_HARD_MIX      , QObject::tr("Hard Mix")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_GRAIN_MERGE   , QObject::tr("Grain Merge")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_GRAIN_EXTRACT , QObject::tr("Grain Extract")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_PARALLEL      , QObject::tr("Parallel")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_ALLANON       , QObject::tr("Allanon")));
    m_map.insert(m_categories[4], KoID(COMPOSITE_GEOMETRIC_MEAN, QObject::tr("Geometric Mean")));

    m_map.insert(m_categories[5], KoID(COMPOSITE_BUMPMAP   , QObject::tr("Bumpmap")));
    m_map.insert(m_categories[5], KoID(COMPOSITE_DISSOLVE  , QObject::tr("Dissolve")));
    m_map.insert(m_categories[5], KoID(COMPOSITE_COPY_RED  , QObject::tr("Copy Red")));
    m_map.insert(m_categories[5], KoID(COMPOSITE_COPY_GREEN, QObject::tr("Copy Green")));
    m_map.insert(m_categories[5], KoID(COMPOSITE_COPY_BLUE , QObject::tr("Copy Blue")));
    m_map.insert(m_categories[5], KoID(COMPOSITE_COPY      , QObject::tr("Copy")));

    m_map.insert(m_categories[6], KoID(COMPOSITE_COLOR         , QObject::tr("Color")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_HUE           , QObject::tr("Hue")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_SATURATION    , QObject::tr("Saturation")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_LUMINIZE      , QObject::tr("Luminosity")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_DEC_SATURATION, QObject::tr("Decrease Saturation")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_INC_SATURATION, QObject::tr("Increase Saturation")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_DEC_LUMINOSITY, QObject::tr("Decrease Luminosity")));
    m_map.insert(m_categories[6], KoID(COMPOSITE_INC_LUMINOSITY, QObject::tr("Increase Luminosity")));

    m_map.insert(m_categories[7], KoID(COMPOSITE_COLOR_HSI         , QObject::tr("Color HSI")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_HUE_HSI           , QObject::tr("Hue HSI")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_SATURATION_HSI    , QObject::tr("Saturation HSI")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_INTENSITY         , QObject::tr("Intensity")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_DEC_SATURATION_HSI, QObject::tr("Decrease Saturation HSI")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_INC_SATURATION_HSI, QObject::tr("Increase Saturation HSI")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_DEC_INTENSITY     , QObject::tr("Decrease Intensity")));
    m_map.insert(m_categories[7], KoID(COMPOSITE_INC_INTENSITY     , QObject::tr("Increase Intensity")));

    m_map.insert(m_categories[8], KoID(COMPOSITE_COLOR_HSL         , QObject::tr("Color HSL")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_HUE_HSL           , QObject::tr("Hue HSL")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_SATURATION_HSL    , QObject::tr("Saturation HSL")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_LIGHTNESS         , QObject::tr("Lightness")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_DEC_SATURATION_HSL, QObject::tr("Decrease Saturation HSL")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_INC_SATURATION_HSL, QObject::tr("Increase Saturation HSL")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_DEC_LIGHTNESS     , QObject::tr("Decrease Lightness")));
    m_map.insert(m_categories[8], KoID(COMPOSITE_INC_LIGHTNESS     , QObject::tr("Increase Lightness")));

    m_map.insert(m_categories[9], KoID(COMPOSITE_COLOR_HSV         , QObject::tr("Color HSV")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_HUE_HSV           , QObject::tr("Hue HSV")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_SATURATION_HSV    , QObject::tr("Saturation HSV")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_VALUE             , QObject::tr("Value")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_DEC_SATURATION_HSV, QObject::tr("Decrease Saturation HSV")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_INC_SATURATION_HSV, QObject::tr("Increase Saturation HSV")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_DEC_VALUE         , QObject::tr("Decrease Value")));
    m_map.insert(m_categories[9], KoID(COMPOSITE_INC_VALUE         , QObject::tr("Increase Value")));
}

const KoCompositeOpRegistry& KoCompositeOpRegistry::instance()
{
    K_GLOBAL_STATIC(KoCompositeOpRegistry, registry);
    return *registry;
}

KoID KoCompositeOpRegistry::getDefaultCompositeOp() const
{
    return KoID(COMPOSITE_OVER, QObject::tr("Normal"));
}

KoID KoCompositeOpRegistry::getKoID(const QString& compositeOpID) const
{
    KoIDMap::const_iterator itr = qFind(m_map.begin(), m_map.end(), KoID(compositeOpID));
    return (itr != m_map.end()) ? *itr : KoID();
}

KoCompositeOpRegistry::KoIDMap KoCompositeOpRegistry::getCompositeOps() const
{
    return m_map;
}

KoCompositeOpRegistry::KoIDList KoCompositeOpRegistry::getCategories() const
{
    return m_categories;
}

KoCompositeOpRegistry::KoIDList KoCompositeOpRegistry::getCompositeOps(const KoID& category, const KoColorSpace* colorSpace) const
{
    qint32                  num = m_map.count(category);
    KoIDMap::const_iterator beg = m_map.find(category);
    KoIDMap::const_iterator end = beg + num;

    KoIDList list;
#if QT_VERSION >= 0x040700
    list.reserve(num);
#endif

    if(colorSpace) {
        for(; beg!=end; ++beg){
            if(colorSpace->hasCompositeOp(beg->id()))
                list.push_back(*beg);
        }
    }
    else {
        for(; beg!=end; ++beg)
            list.push_back(*beg);
    }

    return list;
}

KoCompositeOpRegistry::KoIDList KoCompositeOpRegistry::getCompositeOps(const KoColorSpace* colorSpace) const
{
    KoIDMap::const_iterator beg = m_map.begin();
    KoIDMap::const_iterator end = m_map.end();

    KoIDList list;
#if QT_VERSION >= 0x040700
    list.reserve(m_map.size());
#endif

    if(colorSpace) {
        for(; beg!=end; ++beg){
            if(colorSpace->hasCompositeOp(beg->id()))
                list.push_back(*beg);
        }
    }
    else {
        for(; beg!=end; ++beg)
            list.push_back(*beg);
    }

    return list;
}

bool KoCompositeOpRegistry::colorSpaceHasCompositeOp(const KoColorSpace* colorSpace, const KoID& compositeOp) const
{
    return colorSpace ? colorSpace->hasCompositeOp(compositeOp.id()) : false;
}
