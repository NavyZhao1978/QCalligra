/* This file is part of the KDE project
   Copyright (C)  2006 Peter Simonsson <peter.simonsson@gmail.com>
   Copyright (C)  2007 Thorsten Zachmann <zachmann@kde.okde.org>
   Copyright (C) 2010 Boudewijn Rempt <boud@valdyas.org>

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

#include "FlowDocument.h"

#include "KoDebug.h"

#include "FlowView.h"
#include "FlowFactory.h"

#include <KoPACanvasItem.h>

#include "libs/flake/commands/KoShapeCreateCommand.h"
#include "libs/flake/commands/KoShapeDeleteCommand.h"

FlowDocument::FlowDocument(KoPart *part)
  : KoPADocument(part)
{
}

FlowDocument::~FlowDocument()
{
}

KoOdf::DocumentType FlowDocument::documentType() const
{
    return KoOdf::Graphics;
}

const char * FlowDocument::odfTagName(bool withNamespace)
{
    return withNamespace ? "office:drawing": "drawing";
}

void FlowDocument::insertLayer(KoShapeLayer *layer, KoPAPageBase *pPage)
{
    layer->setParent(pPage);
    //layer->setName(name);
    QList<KoShape*> layers(pPage->shapes());
    if (!layers.isEmpty()) {
        qSort(layers.begin(), layers.end(), KoShape::compareShapeZIndex);
        layer->setZIndex(layers.last()->zIndex() + 1);
    }

    KUndo2Command *cmd = new KoShapeCreateCommand(this, layer, 0);
    cmd->setText(QObject::tr("Create Layer"));
    addCommand(cmd);
}

void FlowDocument::removeLayer(KoShapeLayer *layer, KoPAPageBase *pPage)
{
	KoShapeDeleteCommand *cmd = new KoShapeDeleteCommand(this, layer);
    cmd->setText(QObject::tr("Delete Layer"));
	addCommand(cmd);
}

QList<KoShapeLayer *> FlowDocument::layers(KoPAPageBase *pPage)
{
	QList<KoShapeLayer*> selectedLayers;

	if( !pPage )
		return selectedLayers;

	foreach(KoShape *shape, pPage->shapes()) {
		KoShapeLayer *layer = dynamic_cast<KoShapeLayer *>(shape);
		if(layer) {
			selectedLayers.append(layer);
		}
	}

	return selectedLayers;
}


//#include "FlowDocument.moc"
