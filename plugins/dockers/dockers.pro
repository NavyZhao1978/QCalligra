######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 9 08:35:48 2012
######################################################################

TEMPLATE     = lib
TARGET       = dockers
DESTDIR      = ../../bin

DEPENDPATH  += . colordocker shadowdocker shapecollection shapeproperties strokedocker styledocker
DEPENDPATH  += ../../libs/odf \
               ../../libs/pigment ../../libs/pigment/resources \
               ../../libs/kundo2 \
               ../../libs/flake ../../libs/flake/tools ../../libs/flake/svg ../../libs/flake/commands \
               ../../libs/widgets \
               ../../libs/main ../../libs/main/config \
               ../../libs/kopageapp \

INCLUDEPATH += ../../include ../../interfaces
INCLUDEPATH += . colordocker shadowdocker shapecollection shapeproperties strokedocker styledocker
INCLUDEPATH += ../../libs/odf \
               ../../libs/pigment ../../libs/pigment/resources \
               ../../libs/kundo2 \
               ../../libs/flake ../../libs/flake/tools ../../libs/flake/svg ../../libs/flake/commands \
               ../../libs/widgets \
               ../../libs/main ../../libs/main/config \
               ../../libs/kopageapp \

QT          += xml svg
LIBS		+= -L../../bin
LIBS		+= -lkoodf -lpigment -lkundo2 -lkowidgets -lflake -lkomain

DEFINES     += _USE_MATH_DEFINES _CRT_SECURE_NO_WARNINGS
DEFINES     += MAKE_CALLIGRADOCKERS_LIB 

OBJECTS_DIR	 = ../../build/obj
UI_DIR       = .
MOC_DIR		 = ../../build/moc
RCC_DIR		 = ../../build/rcc

# Input
HEADERS += dockers_export.h \
           DockersPlugin.h \
           colordocker/ColorDocker.h \
           colordocker/ColorDockerFactory.h \
           shadowdocker/ShadowDocker.h \
           shadowdocker/ShadowDockerFactory.h \
           shapecollection/CollectionItemModel.h \
           shapecollection/CollectionShapeFactory.h \
           shapecollection/OdfCollectionLoader.h \
           shapecollection/ShapeCollectionDocker.h \
           shapeproperties/ShapePropertiesDocker.h \
           shapeproperties/ShapePropertiesDockerFactory.h \
           strokedocker/StrokeDocker.h \
           strokedocker/StrokeDockerFactory.h \
           styledocker/StyleButtonBox.h \
           styledocker/StyleDocker.h \
           styledocker/StyleDockerFactory.h \
           styledocker/StylePreview.h
SOURCES += DockersPlugin.cpp \
           colordocker/ColorDocker.cpp \
           colordocker/ColorDockerFactory.cpp \
           shadowdocker/ShadowDocker.cpp \
           shadowdocker/ShadowDockerFactory.cpp \
           shapecollection/CollectionItemModel.cpp \
           shapecollection/CollectionShapeFactory.cpp \
           shapecollection/OdfCollectionLoader.cpp \
           shapecollection/ShapeCollectionDocker.cpp \
           shapeproperties/ShapePropertiesDocker.cpp \
           shapeproperties/ShapePropertiesDockerFactory.cpp \
           strokedocker/StrokeDocker.cpp \
           strokedocker/StrokeDockerFactory.cpp \
           styledocker/StyleButtonBox.cpp \
           styledocker/StyleDocker.cpp \
           styledocker/StyleDockerFactory.cpp \
           styledocker/StylePreview.cpp

RESOURCES += dockers.qrc