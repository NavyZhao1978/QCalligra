######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 7 15:25:00 2012
######################################################################

TEMPLATE     = lib
TARGET       = koodf
DESTDIR      = ../../bin
DEPENDPATH  += . 
INCLUDEPATH += . 
INCLUDEPATH += . ../../include ../../interfaces

QT          += xml
LIBS        += -L../../bin

DEFINES     += _USE_MATH_DEFINES _CRT_SECURE_NO_WARNINGS
DEFINES     += MAKE_KOODF_LIB 

OBJECTS_DIR	 = ../../build/obj
UI_DIR       = .
MOC_DIR		 = ../../build/moc
RCC_DIR		 = ../../build/rcc

# Input
HEADERS += kcarchive.h \
           kcfilterbase.h \
           kcfilterdev.h \
           kcgzipfilter.h \
           kclimitediodevice_p.h \
           kctar.h \
           kczip.h \
           Ko3dScene.h \
           koarchive_export.h \
           KoBorder.h \
           KoCell.h \
           KoCellChild.h \
           KoCellStyle.h \
           KoCellValue.h \
           KoColumn.h \
           KoColumns.h \
           KoColumnStyle.h \
           KoDirectoryStore.h \
           KoDom.h \
           KoDummyCellValue.h \
           KoElementReference.h \
           KoEmbeddedDocumentSaver.h \
           KoEncryptedStore.h \
           KoEncryptionChecker.h \
           KoFontFace.h \
           KoGenChange.h \
           KoGenChanges.h \
           KoGenStyle.h \
           KoGenStyles.h \
           KoOasisSettings.h \
           KoOdf.h \
           koodf_export.h \
           KoOdfBibliographyConfiguration.h \
           KoOdfDocument.h \
           KoOdfGraphicStyles.h \
           KoOdfLineNumberingConfiguration.h \
           KoOdfLoadingContext.h \
           KoOdfManifestEntry.h \
           KoOdfNotesConfiguration.h \
           KoOdfNumberDefinition.h \
           KoOdfNumberStyles.h \
           KoOdfPaste.h \
           KoOdfReadStore.h \
           KoOdfStylesReader.h \
           KoOdfWriteStore.h \
           KoPageFormat.h \
           KoPageLayout.h \
           KoProperties.h \
           KoRawCellChild.h \
           KoRow.h \
           KoRowStyle.h \
           KoShadowStyle.h \
           KoStore.h \
           KoStore_p.h \
           KoStoreDevice.h \
           KoStyle.h \
           KoStyleStack.h \
           KoTable.h \
           KoTableProperties.h \
           KoTableTemplate.h \
           KoTarStore.h \
           KoTblStyle.h \
           KoUnit.h \
           KoXmlNS.h \
           KoXmlReader.h \
           KoXmlReaderForward.h \
           KoXmlWriter.h \
           KoZipStore.h
           
SOURCES += kcarchive.cpp \
           kcfilterbase.cpp \
           kcfilterdev.cpp \
           kcgzipfilter.cpp \
           kclimitediodevice.cpp \
           kctar.cpp \
           kczip.cpp \
           Ko3dScene.cpp \
           KoBorder.cpp \
           KoCell.cpp \
           KoCellChild.cpp \
           KoCellStyle.cpp \
           KoCellValue.cpp \
           KoColumn.cpp \
           KoColumns.cpp \
           KoColumnStyle.cpp \
           KoDirectoryStore.cpp \
           KoDom.cpp \
           KoDummyCellValue.cpp \
           KoElementReference.cpp \
           KoEmbeddedDocumentSaver.cpp \
           KoEncryptedStore.cpp \
           KoEncryptionChecker.cpp \
           KoFontFace.cpp \
           KoGenChange.cpp \
           KoGenChanges.cpp \
           KoGenStyle.cpp \
           KoGenStyles.cpp \
           KoOasisSettings.cpp \
           KoOdf.cpp \
           KoOdfBibliographyConfiguration.cpp \
           KoOdfDocument.cpp \
           KoOdfGraphicStyles.cpp \
           KoOdfLineNumberingConfiguration.cpp \
           KoOdfLoadingContext.cpp \
           KoOdfManifestEntry.cpp \
           KoOdfNotesConfiguration.cpp \
           KoOdfNumberDefinition.cpp \
           KoOdfNumberStyles.cpp \
           KoOdfPaste.cpp \
           KoOdfReadStore.cpp \
           KoOdfStylesReader.cpp \
           KoOdfWriteStore.cpp \
           KoPageFormat.cpp \
           KoPageLayout.cpp \
           KoProperties.cpp \
           KoRawCellChild.cpp \
           KoRow.cpp \
           KoRowStyle.cpp \
           KoShadowStyle.cpp \
           KoStore.cpp \
           KoStyle.cpp \
           KoStyleStack.cpp \
           KoTable.cpp \
           KoTarStore.cpp \
           KoTblStyle.cpp \
           KoUnit.cpp \
           KoXmlNS.cpp \
           KoXmlReader.cpp \
           KoXmlWriter.cpp \
           KoZipStore.cpp
           
RESOURCES += koodf.qrc
