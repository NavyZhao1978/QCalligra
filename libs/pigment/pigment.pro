######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 7 14:41:10 2012
######################################################################

TEMPLATE     = lib
TARGET       = pigment
DESTDIR      = ../../bin
DEPENDPATH  += . colorprofiles colorspaces resources compositeops
INCLUDEPATH += . colorprofiles colorspaces resources compositeops
INCLUDEPATH += ../../include ../../interfaces

QT          += xml
LIBS        += -L../../bin
LIBS		+= -lWs2_32

DEFINES     += _USE_MATH_DEFINES _CRT_SECURE_NO_WARNINGS
DEFINES     += MAKE_PIGMENT_LIB 

OBJECTS_DIR	 = ../../build/obj
UI_DIR       = .
MOC_DIR		 = ../../build/moc
RCC_DIR		 = ../../build/rcc


# Input
HEADERS += DebugPigment.h \
           KoBasicHistogramProducers.h \
           KoBgrColorSpaceTraits.h \
           KoChannelInfo.h \
           KoChromaticities.h \
           KoCmykColorSpaceTraits.h \
           KoColor.h \
           KoColorConversionAlphaTransformation.h \
           KoColorConversionCache.h \
           KoColorConversions.h \
           KoColorConversionSystem.h \
           KoColorConversionSystem_p.h \
           KoColorConversionTransformation.h \
           KoColorConversionTransformationAbstractFactory.h \
           KoColorConversionTransformationFactory.h \
           KoColorModelStandardIds.h \
           KoColorProfile.h \
           KoColorSpace.h \
           KoColorSpace_p.h \
           KoColorSpaceAbstract.h \
           KoColorSpaceConstants.h \
           KoColorSpaceEngine.h \
           KoColorSpaceFactory.h \
           KoColorSpaceMaths.h \
           KoColorSpaceRegistry.h \
           KoColorSpaceTraits.h \
           KoColorTransformation.h \
           KoColorTransformationFactory.h \
           KoColorTransformationFactoryRegistry.h \
           KoCompositeOp.h \
           KoCompositeOpRegistry.h \
           KoConvolutionOp.h \
           KoConvolutionOpImpl.h \
           KoCopyColorConversionTransformation.h \
           KoFallBackColorTransformation.h \
           KoGrayColorSpaceTraits.h \
           KoHistogramProducer.h \
           KoIncompleteColorSpace.h \
           KoIntegerMaths.h \
           KoInvertColorTransformation.h \
           KoLabColorSpaceTraits.h \
           KoLabDarkenColorTransformation.h \
           KoLut.h \
           KoMixColorsOp.h \
           KoMixColorsOpImpl.h \
           KoMultipleColorConversionTransformation.h \
           KoRgbColorSpaceTraits.h \
           KoScaleColorConversionTransformation.h \
           KoUniqueNumberForIdServer.h \
           KoXyzColorSpaceTraits.h \
           KoYcbcrColorSpaceTraits.h \
           lut.h \
           pigment_export.h \
           colorprofiles/KoDummyColorProfile.h \
           colorspaces/KoAlphaColorSpace.h \
           colorspaces/KoLabColorSpace.h \
           colorspaces/KoRgbU16ColorSpace.h \
           colorspaces/KoRgbU8ColorSpace.h \
           colorspaces/KoSimpleColorSpace.h \
           colorspaces/KoSimpleColorSpaceEngine.h \
           colorspaces/KoSimpleColorSpaceFactory.h \
           compositeops/KoCompositeOpAdd.h \
           compositeops/KoCompositeOpAlphaBase.h \
           compositeops/KoCompositeOpAlphaDarken.h \
           compositeops/KoCompositeOpBase.h \
           compositeops/KoCompositeOpBehind.h \
           compositeops/KoCompositeOpBurn.h \
           compositeops/KoCompositeOpCopy.h \
           compositeops/KoCompositeOpCopy2.h \
           compositeops/KoCompositeOpCopyChannel.h \
           compositeops/KoCompositeOpDissolve.h \
           compositeops/KoCompositeOpDivide.h \
           compositeops/KoCompositeOpDodge.h \
           compositeops/KoCompositeOpErase.h \
           compositeops/KoCompositeOpFunctions.h \
           compositeops/KoCompositeOpGeneric.h \
           compositeops/KoCompositeOpHardlight.h \
           compositeops/KoCompositeOpInversedSubtract.h \
           compositeops/KoCompositeOpMultiply.h \
           compositeops/KoCompositeOpOver.h \
           compositeops/KoCompositeOpOverlay.h \
           compositeops/KoCompositeOps.h \
           compositeops/KoCompositeOpScreen.h \
           compositeops/KoCompositeOpSoftlight.h \
           compositeops/KoCompositeOpSubtract.h \
           resources/KoAbstractGradient.h \
           resources/KoColorSet.h \
           resources/KoPattern.h \
           resources/KoResource.h \
           resources/KoSegmentGradient.h \
           resources/KoStopGradient.h
           
SOURCES += KoBasicHistogramProducers.cpp \
           KoColor.cpp \
           KoColorConversionAlphaTransformation.cpp \
           KoColorConversionCache.cpp \
           KoColorConversions.cpp \
           KoColorConversionSystem.cpp \
           KoColorConversionTransformation.cpp \
           KoColorConversionTransformationFactory.cpp \
           KoColorModelStandardIds.cpp \
           KoColorProfile.cpp \
           KoColorSpace.cpp \
           KoColorSpaceEngine.cpp \
           KoColorSpaceFactory.cpp \
           KoColorSpaceMaths.cpp \
           KoColorSpaceRegistry.cpp \
           KoColorTransformation.cpp \
           KoColorTransformationFactory.cpp \
           KoColorTransformationFactoryRegistry.cpp \
           KoCompositeOp.cpp \
           KoCompositeOpRegistry.cpp \
           KoCopyColorConversionTransformation.cpp \
           KoFallBackColorTransformation.cpp \
           KoHistogramProducer.cpp \
           KoMultipleColorConversionTransformation.cpp \
           KoUniqueNumberForIdServer.cpp \
           colorprofiles/KoDummyColorProfile.cpp \
           colorspaces/KoAlphaColorSpace.cpp \
           colorspaces/KoLabColorSpace.cpp \
           colorspaces/KoRgbU16ColorSpace.cpp \
           colorspaces/KoRgbU8ColorSpace.cpp \
           colorspaces/KoSimpleColorSpaceEngine.cpp \
           resources/KoAbstractGradient.cpp \
           resources/KoColorSet.cpp \
           resources/KoPattern.cpp \
           resources/KoResource.cpp \
           resources/KoSegmentGradient.cpp \
           resources/KoStopGradient.cpp
           
RESOURCES += pigment.qrc
