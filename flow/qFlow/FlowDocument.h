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

#ifndef FLOWDOCUMENT_H
#define FLOWDOCUMENT_H

#include "flow_export.h"

#include <KoPADocument.h>
#include <KoPAPageBase.h>
#include <KoShapeLayer.h>

class KoPart;

class FLOW_EXPORT FlowDocument : public KoPADocument
{
    Q_OBJECT

    public:
        FlowDocument(KoPart *part);
        ~FlowDocument();

        virtual KoOdf::DocumentType documentType() const;

		QList<KoShapeLayer*> layers(KoPAPageBase *pPage=0);

		void insertLayer(KoShapeLayer *layer, KoPAPageBase *pPage=0);
		void removeLayer(KoShapeLayer *layer, KoPAPageBase *pPage=0);

    signals:
        /// Emitted when the gui needs to be updated.
        void updateGui();

    protected:
        const char *odfTagName( bool withNamespace );
};

#endif