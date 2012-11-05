/* This file is part of the KDE project
 * Copyright (C) 2006-2007 Thomas Zander <zander@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "KoPasteController.h"

#include <KoCanvasBase.h>
#include <KoToolProxy.h>

#include "KoDebug.h"
#include <QAction>

//class KoPasteControllerPrivate {
//public:
//    KoPasteControllerPrivate(KoPasteController *p, KoCanvasBase *c, QAction *a) : parent(p), canvas(c), action(a) {
//    }
//
//    void paste() {
//        kDebug(30004) <<"Paste!";
//        canvas->toolProxy()->paste();
//    }
//
//    KoPasteController *parent;
//    KoCanvasBase *canvas;
//    QAction *action;
//};

KoPasteController::KoPasteController(KoCanvasBase *canvas, QAction *pasteAction)
    : QObject(pasteAction),
    d(new KoPasteControllerPrivate(this, canvas, pasteAction))
{
    //connect(canvas->toolProxy(), SIGNAL(selectionChanged(bool)), this, SLOT(selectionChanged(bool)));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));
}

KoPasteController::~KoPasteController()
{
    delete d;
}

//#include <KoPasteController.moc>
