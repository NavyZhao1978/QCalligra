/* This file is part of the KDE project
   Copyright (C)  2006 Peter Simonsson <peter.simonsson@gmail.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "FlowView.h"

#include "FlowDocument.h"
#include "FlowPart.h"

#include <KoShape.h>
#include <KoShapeLayer.h>
#include <KoShapeGroup.h>
#include <KoShapeManager.h>
#include <KoSelection.h>
#include <QMessageBox>
#include <SvgWriter.h>
#include <KoPAPageBase.h>
#include "libs/main/KoFilterChain.h"
#include "libs/flake/svg/SvgParser.h"
#include "libs/flake/commands/KoShapeUngroupCommand.h"
#include "libs/flake/commands/KoShapeCreateCommand.h"
#include "libs/flake/commands/KoShapeDeleteCommand.h"

FlowView::FlowView(FlowPart *part, FlowDocument* document, QWidget* parent)
  : KoPAView(part, document, parent), m_document(document)
{
    Q_ASSERT(m_document);

    //setXMLFile("flow.rc");

    initializeActions();
    initializeGUI();

    connect(m_document, SIGNAL(updateGui()), this, SLOT(updateGui()));

    setAcceptDrops(true);
}

FlowView::~FlowView()
{
}

FlowDocument* FlowView::document() const
{
    return m_document;
}

void FlowView::initializeGUI()
{
}

void FlowView::initializeActions()
{
    //actionCollection()->action("configure")->setText(QObject::tr("Configure Flow..."));

	//QAction *exportSvg  = actionCollection()->action("file_export_svg");
 //   connect(exportSvg, SIGNAL(triggered()), this, SLOT(exportToSvg()));

	//QAction *importSvg  = actionCollection()->action("file_import_svg");
 //   connect(importSvg, SIGNAL(triggered()), this, SLOT(importFromSvg()));
}

void FlowView::updateGui()
{
    selectionChanged();
}

void FlowView::exportToSvg(QString filename)
{
	QString svgFileName = filename;
	/////////////////////////////////////////////////////////////
	if (svgFileName.isEmpty()) {
        QUrl startUrl = QUrl("");
        KoDocument* pDoc = document();
        /** if document has a file name, take file name and replace extension with .pdf */
        if (pDoc && pDoc->url().isValid()) {
            startUrl = pDoc->url();
            QString fileName = startUrl.toLocalFile();
            fileName = fileName.replace( QRegExp( "\\.\\w{2,5}$", Qt::CaseInsensitive ), ".svg" );
            startUrl.fromLocalFile( fileName );
        }

        if (QFile::exists(startUrl.toLocalFile())) {
            bool overwrite = QMessageBox::question(this,
											QObject::tr("Warning"),
                                            QObject::tr("A document with this name already exists.\n"\
                                                "Do you want to overwrite it?"),
											QMessageBox::Yes,
                                            QMessageBox::No) == QMessageBox::Yes;
            if (!overwrite) {
                return;
            }
        }

        svgFileName = startUrl.toLocalFile();
        if (svgFileName.isEmpty())
            return;

		/////////////////////
		const FlowDocument *pFlowDoc = document();
		const KoPAPageBase *pPage = pFlowDoc->pageByIndex(0, false);

		SvgWriter writer(pPage->shapes(), QSizeF(pPage->pageLayout().width, pPage->pageLayout().height) ) ;
		if (!writer.save(svgFileName, true))
			return;
    }
}

void FlowView::replaceActivePage(KoPAPageBase *page, KoPAPageBase *newActivePage)
{
    if (page == activePage() ) {
        viewMode()->updateActivePage(newActivePage);
    }
}

void FlowView::importFromSvg(QString filename)
{
	//QString svgFileName = filename;

	///////////////////////////////////////////////////////////////
	//if (svgFileName.isEmpty()) {
	//	QUrl startUrl = QUrl("");
	//	KoDocument* pDoc = document();
	//	/** if document has a file name, take file name and replace extension with .pdf */
	//	if (pDoc && pDoc->url().isValid()) {
	//		startUrl = pDoc->url();
	//		QString fileName = startUrl.fileName();
	//		fileName = fileName.replace( QRegExp( "\\.\\w{2,5}$", Qt::CaseInsensitive ), ".svg" );
	//		startUrl.setFileName( fileName );
	//	}

	//	if (!QFile::exists(startUrl.fileName())) {
	//		QMessageBox::questionYesNo(this,
	//									QObject::tr("File is not Exist!"),
	//									QObject::tr("Warning"));
	//		return;
	//	}

	//	svgFileName = startUrl.toLocalFile();
	//	if (svgFileName.isEmpty())
	//		return;
	//}

	////Find the last extension
 //   QString strExt;
 //   QString fileIn = svgFileName;
 //   const int result = fileIn.lastIndexOf('.');
 //   if (result >= 0)
 //       strExt = fileIn.mid(result).toLower();

 //   QString strMime; // Mime type of the compressor
 //   if ((strExt == ".gz")    //in case of .svg.gz (logical extension)
 //           || (strExt == ".svgz")) //in case of .svgz (extension used prioritary)
 //       strMime = "application/x-gzip"; // Compressed with gzip
 //   else if (strExt == ".bz2") //in case of .svg.bz2 (logical extension)
 //       strMime = "application/x-bzip2"; // Compressed with bzip2
 //   else
 //       strMime = "text/plain";

 //   QIODevice* in = KoFilterDev::deviceForFile(fileIn, strMime);

 //   if (!in->open(QIODevice::ReadOnly)) {
 //       kError(30514) << "Cannot open file! Aborting!" << endl;
 //       delete in;
 //       return;
 //   }

 //   int line, col;
 //   QString errormessage;

 //   KoXmlDocument inputDoc;

 //   const bool parsed = inputDoc.setContent(in, &errormessage, &line, &col);

 //   in->close();
 //   delete in;

 //   if (! parsed) {
 //       kError(30514) << "Error while parsing file: "
 //       << "at line " << line << " column: " << col
 //       << " message: " << errormessage << endl;
 //       // ### TODO: feedback to the user
 //       return;
 //   }

	//const FlowDocument *pFlowDoc = document();
	//const KoPAPageBase *pPage = pFlowDoc->pageByIndex(0, false);

 //   // Do the conversion!
 //   convert(fileIn, inputDoc.documentElement());

 //   return;

}
/*
void FlowView::convert(QString fileIn, const KoXmlElement &rootElement)
{
    if (! m_document)
        return;

    // set default page size to A4
    QSizeF pageSize(550.0, 841.0);

    SvgParser parser(m_document->resourceManager());

    parser.setXmlBaseDir(QFileInfo(fileIn).filePath());

    QList<KoShape*> toplevelShapes = parser.parseSvg(rootElement, &pageSize);
    // parse the root svg element
    buildDocument(toplevelShapes, parser.shapes());

    // set the page size
    //m_document->setPageSize(pageSize);
}

void FlowView::buildDocument(const QList<KoShape*> &toplevelShapes, const QList<KoShape*> &shapes)
{
	FlowDocument *pFlowDoc = document();
	KoPAPageBase *pPage = pFlowDoc->pageByIndex(0, false);

    // if we have only top level groups, make them layers
    bool onlyTopLevelGroups = true;
    foreach(KoShape * shape, toplevelShapes) {
        if (! dynamic_cast<KoShapeGroup*>(shape) || shape->filterEffectStack()) {
            onlyTopLevelGroups = false;
            break;
        }
    }

    // add all shapes to the document
    foreach(KoShape * shape, shapes) {
        m_document->addShape(shape);
    }
	
    KoShapeLayer * oldLayer = 0;
    if (m_document->layers(pPage).count())
        oldLayer = m_document->layers(pPage).first();

    if (onlyTopLevelGroups) {
        foreach(KoShape * shape, toplevelShapes) {
            // ungroup toplevel groups
            KoShapeGroup * group = dynamic_cast<KoShapeGroup*>(shape);
            QList<KoShape*> children = group->shapes();
            KoShapeUngroupCommand cmd(group, children, QList<KoShape*>() << group);
            cmd.redo();

            KoShapeLayer * layer = new KoShapeLayer();
            foreach(KoShape * child, children) {
                m_document->addShape(child);
                layer->addShape(child);
            }
            if (! group->name().isEmpty())
                layer->setName(group->name());
            layer->setVisible(group->isVisible());
            layer->setZIndex(group->zIndex());
            m_document->insertLayer(layer, pPage);
            delete group;
        }
    } else {
        KoShapeLayer * layer = new KoShapeLayer();
        foreach(KoShape * shape, toplevelShapes) {
            m_document->addShape(shape);
            layer->addShape(shape);
        }
        m_document->insertLayer(layer, pPage);
    }

    if (oldLayer) {
        m_document->removeLayer(oldLayer, pPage);
    }

	emit updateGui();
}
//*/
//#include "FlowView.moc"
