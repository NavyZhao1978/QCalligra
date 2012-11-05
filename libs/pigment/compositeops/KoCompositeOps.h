/*
 *  Copyright (c) 2007 Cyrille Berger <cberger@cberger.net>
 *  Copyright (c) 2011 Silvio Heinrich <plassy@web.de>
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

#ifndef _KOCOMPOSITEOPS_H_
#define _KOCOMPOSITEOPS_H_

//#include <boost/type_traits.hpp>

#include <KoColorSpace.h>
#include <KoColorSpaceTraits.h>
#include <KoColorSpaceMaths.h>

#include "compositeops/KoCompositeOpGeneric.h"
#include "compositeops/KoCompositeOpOver.h"
#include "compositeops/KoCompositeOpCopyChannel.h"
#include "compositeops/KoCompositeOpAlphaDarken.h"
#include "compositeops/KoCompositeOpErase.h"
#include "compositeops/KoCompositeOpCopy2.h"
#include "compositeops/KoCompositeOpDissolve.h"

#include "compositeops/KoCompositeOpAdd.h"
#include "compositeops/KoCompositeOpBurn.h"
#include "compositeops/KoCompositeOpDivide.h"
#include "compositeops/KoCompositeOpDodge.h"
#include "compositeops/KoCompositeOpMultiply.h"
#include "compositeops/KoCompositeOpOverlay.h"
#include "compositeops/KoCompositeOpScreen.h"
#include "compositeops/KoCompositeOpSubtract.h"
#include "compositeops/KoCompositeOpInversedSubtract.h"
#include "compositeops/KoCompositeOpSoftlight.h"
#include "compositeops/KoCompositeOpHardlight.h"

#include "compositeops/KoCompositeOpBehind.h"

namespace _Private {

template<class Traits, bool flag>
struct AddGeneralOps
{
    static void add(KoColorSpace* cs) { Q_UNUSED(cs); }
};

template<class Traits>
struct AddGeneralOps<Traits, true>
{
     typedef typename Traits::channels_type Arg;
     typedef Arg (*CompositeFunc)(Arg, Arg);
     static const qint32 alpha_pos = Traits::alpha_pos;

     template<CompositeFunc func>
     static void add(KoColorSpace* cs, const QString& id, const QString& description, const QString& category) {
         cs->addCompositeOp(new KoCompositeOpGenericSC<Traits, func>(cs, id, description, category));
     }

     static void add(KoColorSpace* cs) {
         cs->addCompositeOp(new KoCompositeOpOver<Traits>(cs));
         cs->addCompositeOp(new KoCompositeOpAlphaDarken<Traits>(cs));
         cs->addCompositeOp(new KoCompositeOpCopy2<Traits>(cs));
         cs->addCompositeOp(new KoCompositeOpErase<Traits>(cs));
         cs->addCompositeOp(new KoCompositeOpBehind<Traits>(cs));

         add<&cfOverlay<Arg>       >(cs, COMPOSITE_OVERLAY       , QObject::tr("Overlay")       , KoCompositeOp::categoryMix());
         add<&cfGrainMerge<Arg>    >(cs, COMPOSITE_GRAIN_MERGE   , QObject::tr("Grain Merge")   , KoCompositeOp::categoryMix());
         add<&cfGrainExtract<Arg>  >(cs, COMPOSITE_GRAIN_EXTRACT , QObject::tr("Grain Extract") , KoCompositeOp::categoryMix());
         add<&cfHardMix<Arg>       >(cs, COMPOSITE_HARD_MIX      , QObject::tr("Hard Mix")      , KoCompositeOp::categoryMix());
         add<&cfGeometricMean<Arg> >(cs, COMPOSITE_GEOMETRIC_MEAN, QObject::tr("Geometric Mean"), KoCompositeOp::categoryMix());
         add<&cfParallel<Arg>      >(cs, COMPOSITE_PARALLEL      , QObject::tr("Parallel")      , KoCompositeOp::categoryMix());
         add<&cfAllanon<Arg>       >(cs, COMPOSITE_ALLANON       , QObject::tr("Allanon")       , KoCompositeOp::categoryMix());

         add<&cfScreen<Arg>      >(cs, COMPOSITE_SCREEN      , QObject::tr("Screen")      , KoCompositeOp::categoryLight());
         add<&cfColorDodge<Arg>  >(cs, COMPOSITE_DODGE       , QObject::tr("Color Dodge") , KoCompositeOp::categoryLight());
         add<&cfAddition<Arg>    >(cs, COMPOSITE_LINEAR_DODGE, QObject::tr("Linear Dodge"), KoCompositeOp::categoryLight());
         add<&cfLightenOnly<Arg> >(cs, COMPOSITE_LIGHTEN     , QObject::tr("Lighten")     , KoCompositeOp::categoryLight());
         add<&cfHardLight<Arg>   >(cs, COMPOSITE_HARD_LIGHT  , QObject::tr("Hard Light")  , KoCompositeOp::categoryLight());
         add<&cfSoftLight<Arg>   >(cs, COMPOSITE_SOFT_LIGHT  , QObject::tr("Soft Light")  , KoCompositeOp::categoryLight());
         add<&cfGammaLight<Arg>  >(cs, COMPOSITE_GAMMA_LIGHT , QObject::tr("Gamma Light") , KoCompositeOp::categoryLight());
         add<&cfVividLight<Arg>  >(cs, COMPOSITE_VIVID_LIGHT , QObject::tr("Vivid Light") , KoCompositeOp::categoryLight());
         add<&cfPinLight<Arg>    >(cs, COMPOSITE_PIN_LIGHT   , QObject::tr("Pin Light")   , KoCompositeOp::categoryLight());
         add<&cfLinearLight<Arg> >(cs, COMPOSITE_LINEAR_LIGHT, QObject::tr("Linear Light"), KoCompositeOp::categoryLight());

         add<&cfColorBurn<Arg>  >(cs, COMPOSITE_BURN        , QObject::tr("Color Burn") , KoCompositeOp::categoryDark());
         add<&cfLinearBurn<Arg> >(cs, COMPOSITE_LINEAR_BURN , QObject::tr("Linear Burn"), KoCompositeOp::categoryDark());
         add<&cfDarkenOnly<Arg> >(cs, COMPOSITE_DARKEN      , QObject::tr("Darken")     , KoCompositeOp::categoryDark());
         add<&cfGammaDark<Arg>  >(cs, COMPOSITE_GAMMA_DARK  , QObject::tr("Gamma Dark") , KoCompositeOp::categoryDark());

         add<&cfAddition<Arg>        >(cs, COMPOSITE_ADD             , QObject::tr("Addition")         , KoCompositeOp::categoryArithmetic());
         add<&cfSubtract<Arg>        >(cs, COMPOSITE_SUBTRACT        , QObject::tr("Subtract")         , KoCompositeOp::categoryArithmetic());
         add<&cfInverseSubtract<Arg> >(cs, COMPOSITE_INVERSE_SUBTRACT, QObject::tr("Inversed-Subtract"), KoCompositeOp::categoryArithmetic());
         add<&cfMultiply<Arg>        >(cs, COMPOSITE_MULT            , QObject::tr("Multiply")         , KoCompositeOp::categoryArithmetic());
         add<&cfDivide<Arg>          >(cs, COMPOSITE_DIVIDE          , QObject::tr("Divide")           , KoCompositeOp::categoryArithmetic());

         add<&cfArcTangent<Arg>           >(cs, COMPOSITE_ARC_TANGENT          , QObject::tr("Arcus Tangent")        , KoCompositeOp::categoryNegative());
         add<&cfDifference<Arg>           >(cs, COMPOSITE_DIFF                 , QObject::tr("Difference")           , KoCompositeOp::categoryNegative());
         add<&cfExclusion<Arg>            >(cs, COMPOSITE_EXCLUSION            , QObject::tr("Exclusion")            , KoCompositeOp::categoryNegative());
         add<&cfEquivalence<Arg>          >(cs, COMPOSITE_EQUIVALENCE          , QObject::tr("Equivalence")          , KoCompositeOp::categoryNegative());
         add<&cfAdditiveSubtractive<Arg>  >(cs, COMPOSITE_ADDITIVE_SUBTRACTIVE , QObject::tr("Additive-Subtractive") , KoCompositeOp::categoryNegative());

         cs->addCompositeOp(new KoCompositeOpDissolve<Traits>(cs, KoCompositeOp::categoryMisc()));
     }
};

template<class Traits, bool flag>
struct AddRGBOps
{
    static void add(KoColorSpace* cs) { Q_UNUSED(cs); }
};

template<class Traits>
struct AddRGBOps<Traits, true>
{
    typedef float Arg;
    
    static const qint32 red_pos   = Traits::red_pos;
    static const qint32 green_pos = Traits::green_pos;
    static const qint32 blue_pos  = Traits::blue_pos;
    
    template<void compositeFunc(Arg, Arg, Arg, Arg&, Arg&, Arg&)>
    static void add(KoColorSpace* cs, const QString& id, const QString& description, const QString& category) {
        cs->addCompositeOp(new KoCompositeOpGenericHSL<Traits, compositeFunc>(cs, id, description, category));
    }
    
    static void add(KoColorSpace* cs) {
        cs->addCompositeOp(new KoCompositeOpCopyChannel<Traits,red_pos  >(cs, COMPOSITE_COPY_RED  , QObject::tr("Copy Red")  , KoCompositeOp::categoryMisc()));
        cs->addCompositeOp(new KoCompositeOpCopyChannel<Traits,green_pos>(cs, COMPOSITE_COPY_GREEN, QObject::tr("Copy Green"), KoCompositeOp::categoryMisc()));
        cs->addCompositeOp(new KoCompositeOpCopyChannel<Traits,blue_pos >(cs, COMPOSITE_COPY_BLUE , QObject::tr("Copy Blue") , KoCompositeOp::categoryMisc()));
        
        add<&cfColor             <HSYType,Arg> >(cs, COMPOSITE_COLOR         , QObject::tr("Color")              , KoCompositeOp::categoryHSY());
        add<&cfHue               <HSYType,Arg> >(cs, COMPOSITE_HUE           , QObject::tr("Hue")                , KoCompositeOp::categoryHSY());
        add<&cfSaturation        <HSYType,Arg> >(cs, COMPOSITE_SATURATION    , QObject::tr("Saturation")         , KoCompositeOp::categoryHSY());
        add<&cfIncreaseSaturation<HSYType,Arg> >(cs, COMPOSITE_INC_SATURATION, QObject::tr("Increase Saturation"), KoCompositeOp::categoryHSY());
        add<&cfDecreaseSaturation<HSYType,Arg> >(cs, COMPOSITE_DEC_SATURATION, QObject::tr("Decrease Saturation"), KoCompositeOp::categoryHSY());
        add<&cfLightness         <HSYType,Arg> >(cs, COMPOSITE_LUMINIZE      , QObject::tr("Luminosity")         , KoCompositeOp::categoryHSY());
        add<&cfIncreaseLightness <HSYType,Arg> >(cs, COMPOSITE_INC_LUMINOSITY, QObject::tr("Increase Luminosity"), KoCompositeOp::categoryHSY());
        add<&cfDecreaseLightness <HSYType,Arg> >(cs, COMPOSITE_DEC_LUMINOSITY, QObject::tr("Decrease Luminosity"), KoCompositeOp::categoryHSY());
        
        add<&cfColor             <HSIType,Arg> >(cs, COMPOSITE_COLOR_HSI         , QObject::tr("Color HSI")              , KoCompositeOp::categoryHSI());
        add<&cfHue               <HSIType,Arg> >(cs, COMPOSITE_HUE_HSI           , QObject::tr("Hue HSI")                , KoCompositeOp::categoryHSI());
        add<&cfSaturation        <HSIType,Arg> >(cs, COMPOSITE_SATURATION_HSI    , QObject::tr("Saturation HSI")         , KoCompositeOp::categoryHSI());
        add<&cfIncreaseSaturation<HSIType,Arg> >(cs, COMPOSITE_INC_SATURATION_HSI, QObject::tr("Increase Saturation HSI"), KoCompositeOp::categoryHSI());
        add<&cfDecreaseSaturation<HSIType,Arg> >(cs, COMPOSITE_DEC_SATURATION_HSI, QObject::tr("Decrease Saturation HSI"), KoCompositeOp::categoryHSI());
        add<&cfLightness         <HSIType,Arg> >(cs, COMPOSITE_INTENSITY         , QObject::tr("Intensity")              , KoCompositeOp::categoryHSI());
        add<&cfIncreaseLightness <HSIType,Arg> >(cs, COMPOSITE_INC_INTENSITY     , QObject::tr("Increase Intensity")     , KoCompositeOp::categoryHSI());
        add<&cfDecreaseLightness <HSIType,Arg> >(cs, COMPOSITE_DEC_INTENSITY     , QObject::tr("Decrease Intensity")     , KoCompositeOp::categoryHSI());
        
        add<&cfColor             <HSLType,Arg> >(cs, COMPOSITE_COLOR_HSL         , QObject::tr("Color HSL")              , KoCompositeOp::categoryHSL());
        add<&cfHue               <HSLType,Arg> >(cs, COMPOSITE_HUE_HSL           , QObject::tr("Hue HSL")                , KoCompositeOp::categoryHSL());
        add<&cfSaturation        <HSLType,Arg> >(cs, COMPOSITE_SATURATION_HSL    , QObject::tr("Saturation HSL")         , KoCompositeOp::categoryHSL());
        add<&cfIncreaseSaturation<HSLType,Arg> >(cs, COMPOSITE_INC_SATURATION_HSL, QObject::tr("Increase Saturation HSL"), KoCompositeOp::categoryHSL());
        add<&cfDecreaseSaturation<HSLType,Arg> >(cs, COMPOSITE_DEC_SATURATION_HSL, QObject::tr("Decrease Saturation HSL"), KoCompositeOp::categoryHSL());
        add<&cfLightness         <HSLType,Arg> >(cs, COMPOSITE_LIGHTNESS         , QObject::tr("Lightness")              , KoCompositeOp::categoryHSL());
        add<&cfIncreaseLightness <HSLType,Arg> >(cs, COMPOSITE_INC_LIGHTNESS     , QObject::tr("Increase Lightness")     , KoCompositeOp::categoryHSL());
        add<&cfDecreaseLightness <HSLType,Arg> >(cs, COMPOSITE_DEC_LIGHTNESS     , QObject::tr("Decrease Lightness")     , KoCompositeOp::categoryHSL());
        
        add<&cfColor             <HSVType,Arg> >(cs, COMPOSITE_COLOR_HSV         , QObject::tr("Color HSV")              , KoCompositeOp::categoryHSV());
        add<&cfHue               <HSVType,Arg> >(cs, COMPOSITE_HUE_HSV           , QObject::tr("Hue HSV")                , KoCompositeOp::categoryHSV());
        add<&cfSaturation        <HSVType,Arg> >(cs, COMPOSITE_SATURATION_HSV    , QObject::tr("Saturation HSV")         , KoCompositeOp::categoryHSV());
        add<&cfIncreaseSaturation<HSVType,Arg> >(cs, COMPOSITE_INC_SATURATION_HSV, QObject::tr("Increase Saturation HSV"), KoCompositeOp::categoryHSV());
        add<&cfDecreaseSaturation<HSVType,Arg> >(cs, COMPOSITE_DEC_SATURATION_HSV, QObject::tr("Decrease Saturation HSV"), KoCompositeOp::categoryHSV());
        add<&cfLightness         <HSVType,Arg> >(cs, COMPOSITE_VALUE             , QObject::tr("Value")                  , KoCompositeOp::categoryHSV());
        add<&cfIncreaseLightness <HSVType,Arg> >(cs, COMPOSITE_INC_VALUE         , QObject::tr("Increase Value")         , KoCompositeOp::categoryHSV());
        add<&cfDecreaseLightness <HSVType,Arg> >(cs, COMPOSITE_DEC_VALUE         , QObject::tr("Decrease Value")         , KoCompositeOp::categoryHSV());
    }
};

}

/**
 * This function add to the colorspace all the composite ops defined by
 * the pigment library.
 */
template<class _Traits_>
void addStandardCompositeOps(KoColorSpace* cs)
{
    typedef typename _Traits_::channels_type channels_type;
    
    static const bool useGeneralOps = true;
    static const bool useRGBOps     = false;	//boost::is_base_of<KoBgrTraits<channels_type>, _Traits_>::value;
    
    _Private::AddGeneralOps<_Traits_, useGeneralOps>::add(cs);
    _Private::AddRGBOps    <_Traits_, useRGBOps    >::add(cs);
}

template<class _Traits_>
void addOldCompositeOps(KoColorSpace* cs)
{
    cs->addCompositeOp(new KoCompositeOpAdd<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpAlphaDarken<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpBurn<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpCopy2<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpDivide<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpDodge<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpErase<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpMultiply<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpOver<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpOverlay<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpScreen<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpSubtract<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpSoftlight<_Traits_>(cs));
    cs->addCompositeOp(new KoCompositeOpHardlight<_Traits_>(cs));
}

#endif
