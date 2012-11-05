######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 9 08:22:51 2012
######################################################################

TEMPLATE     = lib
TARGET       = artistictextshape
DESTDIR      = ../../bin

DEPENDPATH  += .
DEPENDPATH  += ../../libs/odf \
               ../../libs/pigment ../../libs/pigment/resources \
               ../../libs/kundo2 \
               ../../libs/flake ../../libs/flake/tools ../../libs/flake/svg ../../libs/flake/commands \
               ../../libs/widgets \
               ../../libs/main ../../libs/main/config \

INCLUDEPATH += ../../include ../../interfaces
INCLUDEPATH += . 
INCLUDEPATH += ../../libs/odf \
               ../../libs/pigment ../../libs/pigment/resources \
               ../../libs/kundo2 \
               ../../libs/flake ../../libs/flake/tools ../../libs/flake/svg ../../libs/flake/commands \
               ../../libs/widgets \
               ../../libs/main ../../libs/main/config \

QT          += xml svg
LIBS		+= -L../../bin
LIBS		+= -lkoodf -lpigment -lkundo2 -lkowidgets -lflake -lkomain

DEFINES     += _USE_MATH_DEFINES _CRT_SECURE_NO_WARNINGS
DEFINES     += MAKE_ARTISTICTEXTSHAPE_LIB 

OBJECTS_DIR	 = ../../build/obj
UI_DIR       = .
MOC_DIR		 = ../../build/moc
RCC_DIR		 = ../../build/rcc

# Input
HEADERS += AddTextRangeCommand.h \
           ArtisticTextLoadingContext.h \
           ArtisticTextRange.h \
           ArtisticTextShape.h \
           artistictextshape_export.h \
           ArtisticTextShapeConfigWidget.h \
           ArtisticTextShapeFactory.h \
           ArtisticTextShapeLoadingUpdater.h \
           ArtisticTextShapeOnPathWidget.h \
           ArtisticTextShapePlugin.h \
           ArtisticTextTool.h \
           ArtisticTextToolFactory.h \
           ArtisticTextToolSelection.h \
           AttachTextToPathCommand.h \
           ChangeTextAnchorCommand.h \
           ChangeTextFontCommand.h \
           ChangeTextOffsetCommand.h \
           DetachTextFromPathCommand.h \
           MoveStartOffsetStrategy.h \
           RemoveTextRangeCommand.h \
           ReplaceTextRangeCommand.h \
           SelectTextStrategy.h
           
FORMS += ArtisticTextShapeConfigWidget.ui ArtisticTextShapeOnPathWidget.ui

SOURCES += AddTextRangeCommand.cpp \
           ArtisticTextLoadingContext.cpp \
           ArtisticTextRange.cpp \
           ArtisticTextShape.cpp \
           ArtisticTextShapeConfigWidget.cpp \
           ArtisticTextShapeFactory.cpp \
           ArtisticTextShapeLoadingUpdater.cpp \
           ArtisticTextShapeOnPathWidget.cpp \
           ArtisticTextShapePlugin.cpp \
           ArtisticTextTool.cpp \
           ArtisticTextToolFactory.cpp \
           ArtisticTextToolSelection.cpp \
           AttachTextToPathCommand.cpp \
           ChangeTextAnchorCommand.cpp \
           ChangeTextFontCommand.cpp \
           ChangeTextOffsetCommand.cpp \
           DetachTextFromPathCommand.cpp \
           MoveStartOffsetStrategy.cpp \
           RemoveTextRangeCommand.cpp \
           ReplaceTextRangeCommand.cpp \
           SelectTextStrategy.cpp
           
RESOURCES += artistictextshape.qrc