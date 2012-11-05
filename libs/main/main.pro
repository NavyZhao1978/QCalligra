######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 8 18:57:39 2012
######################################################################

TEMPLATE     = lib
TARGET       = komain
DESTDIR      = ../../bin

DEPENDPATH  += . config 
DEPENDPATH  += ../odf ../pigment ../pigment/resources ../kundo2 ../flake ../flake/tools ../widgets

INCLUDEPATH += . config 
INCLUDEPATH += ../odf ../pigment ../pigment/resources ../kundo2 ../flake ../flake/tools ../widgets
INCLUDEPATH += ../../include ../../interfaces

QT          += xml svg
LIBS		+= -L../../bin
LIBS		+= -lkoodf -lpigment -lkundo2 -lkowidgets -lflake

DEFINES     += _USE_MATH_DEFINES _CRT_SECURE_NO_WARNINGS
DEFINES     += MAKE_KOMAIN_LIB 

OBJECTS_DIR	 = ../../build/obj
UI_DIR       = .
MOC_DIR		 = ../../build/moc
RCC_DIR		 = ../../build/rcc


# Input
HEADERS += calligraversion.h \
           KoApplication.h \
           KoApplicationAdaptor.h \
           KoAutoSaveRecoveryDialog.h \
           KoDetailsPane.h \
           KoDockerManager.h \
           KoDocument.h \
           KoDocument_p.h \
           KoDocumentEntry.h \
           KoDocumentInfo.h \
           KoDocumentInfoDlg.h \
           KoDocumentInfoPropsPage.h \
           KoDocumentSectionDelegate.h \
           KoDocumentSectionModel.h \
           KoDocumentSectionPropertyAction_p.h \
           KoDocumentSectionToolTip.h \
           KoDocumentSectionView.h \
           KoExistingDocumentPane.h \
           KoFactory.h \
           KoFileDialog.h \
           KoFilter.h \
           KoFilterChain.h \
           KoFilterChainLink.h \
           KoFilterChainLinkList.h \
           KoFilterEdge.h \
           KoFilterEntry.h \
           KoFilterGraph.h \
           KoFilterManager.h \
           KoFilterManager_p.h \
           KoFilterVertex.h \
           KoFindBase.h \
           KoFindMatch.h \
           KoFindOption.h \
           KoFindOptionSet.h \
           KoFindStyle.h \
           KoFindText.h \
           KoFindToolbar.h \
           KoGlobal.h \
           KoGridData.h \
           komain_export.h \
           KoMainWindow.h \
           KoModeBox_p.h \
           KoModeBoxDocker_p.h \
           KoModeBoxFactory.h \
           KoOpenPane.h \
           KoPart.h \
           KoPartAdaptor.h \
           KoPrintingDialog.h \
           KoPrintJob.h \
           KoProgressBar.h \
           KoProgressProxy.h \
           KoProgressUpdater.h \
           KoRecentDocumentsPane.h \
           KoRuler.h \
           KoRuler_p.h \
           KoRulerController.h \
           KoServiceProvider.h \
           KoStandardAction.h \
           KoTemplate.h \
           KoTemplateGroup.h \
           KoTemplates.h \
           KoTemplatesPane.h \
           KoTemplateTree.h \
           KoToolBox_p.h \
           KoToolBoxDocker_p.h \
           KoToolBoxFactory.h \
           KoToolBoxLayout_p.h \
           KoToolDocker_p.h \
           KoUndoStackAction.h \
           KoUpdater.h \
           KoUpdaterPrivate_p.h \
           KoVersionDialog.h \
           KoView.h \
           KoView_p.h \
           KoViewAdaptor.h \
           PriorityQueue_p.h \
           config/KoConfigAuthorPage.h \
           config/KoConfigDocumentPage.h \
           config/KoConfigGridPage.h \
           config/KoConfigMiscPage.h
           
FORMS += KoDetailsPaneBase.ui \
         koDocumentInfoAboutWidget.ui \
         koDocumentInfoAuthorWidget.ui \
         KoOpenPaneBase.ui \
         config/KoConfigAuthorPage.ui
         
SOURCES += calligraversion.cpp \
           KoApplication.cpp \
           KoApplicationAdaptor.cpp \
           KoAutoSaveRecoveryDialog.cpp \
           KoDetailsPane.cpp \
           KoDocInfoPropsFactory.cpp \
           KoDockerManager.cpp \
           KoDocument.cpp \
           KoDocumentEntry.cpp \
           KoDocumentInfo.cpp \
           KoDocumentInfoDlg.cpp \
           KoDocumentInfoPropsPage.cpp \
           KoDocumentSectionDelegate.cpp \
           KoDocumentSectionToolTip.cpp \
           KoDocumentSectionView.cpp \
           KoExistingDocumentPane.cpp \
           KoFactory.cpp \
           KoFileDialog.cpp \
           KoFilter.cpp \
           KoFilterChain.cpp \
           KoFilterChainLink.cpp \
           KoFilterChainLinkList.cpp \
           KoFilterEdge.cpp \
           KoFilterEntry.cpp \
           KoFilterGraph.cpp \
           KoFilterManager.cpp \
           KoFilterManager_p.cpp \
           KoFilterVertex.cpp \
           KoFindBase.cpp \
           KoFindMatch.cpp \
           KoFindOption.cpp \
           KoFindOptionSet.cpp \
           KoFindStyle.cpp \
           KoFindText.cpp \
           KoFindToolbar.cpp \
           KoGlobal.cpp \
           KoGridData.cpp \
           KoMainWindow.cpp \
           KoModeBox.cpp \
           KoModeBoxDocker.cpp \
           KoModeBoxFactory.cpp \
           KoOpenPane.cpp \
           KoPart.cpp \
           KoPartAdaptor.cpp \
           KoPrintingDialog.cpp \
           KoPrintJob.cpp \
           KoProgressBar.cpp \
           KoProgressUpdater.cpp \
           KoRecentDocumentsPane.cpp \
           KoRuler.cpp \
           KoRulerController.cpp \
           KoServiceProvider.cpp \
           KoStandardAction.cpp \
           KoTemplate.cpp \
           KoTemplateGroup.cpp \
           KoTemplates.cpp \
           KoTemplatesPane.cpp \
           KoTemplateTree.cpp \
           KoToolBox.cpp \
           KoToolBoxDocker.cpp \
           KoToolBoxFactory.cpp \
           KoToolDocker.cpp \
           KoUndoStackAction.cpp \
           KoUpdater.cpp \
           KoUpdaterPrivate_p.cpp \
           KoVersionDialog.cpp \
           KoView.cpp \
           KoViewAdaptor.cpp \
           config/KoConfigAuthorPage.cpp \
           config/KoConfigDocumentPage.cpp \
           config/KoConfigGridPage.cpp \
           config/KoConfigMiscPage.cpp
           
RESOURCES += komain.qrc
