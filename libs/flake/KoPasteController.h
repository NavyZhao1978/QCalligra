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
#ifndef KOPASTECONTROLLER_H
#define KOPASTECONTROLLER_H

#include "flake_export.h"

#include <QObject>

class QAction;
class KoCanvasBase;
class KoPasteControllerPrivate;

/**
 * This class takes care of the paste actions integration into flake.
 * Whenever the paste (KStandardAction::Paste) action is triggered the controller
 * will use the currently selected tool and try to paste using that tool.
 * Additionally; when the tool does not allow pasting (KoToolBase::hasSelection() returns false)
 * the signal pasteRequested will be emitted for applications to connect to.
 */
class FLAKE_EXPORT KoPasteController : public QObject
{
    Q_OBJECT
public:
    /**
     * Constructor
     * @param canvas the canvas this controller will work on.
     * @param pasteAction the action that we will listen to and respond to when it is activated.  Additionally, the
     *     action is used as a parent for the QObject for memory management purposes.
     */
    KoPasteController(KoCanvasBase *canvas, QAction *pasteAction);
    ~KoPasteController();

private:
    Q_PRIVATE_SLOT(d, void paste())

    KoPasteControllerPrivate * const d;
};

#include <KoCanvasBase.h>
#include <KoToolProxy.h>

class KoPasteControllerPrivate {
public:
    KoPasteControllerPrivate(KoPasteController *p, KoCanvasBase *c, QAction *a) : parent(p), canvas(c), action(a) {
    }

    void paste() {
        //qDebug() <<"Paste!";
        canvas->toolProxy()->paste();
    }

    KoPasteController *parent;
    KoCanvasBase *canvas;
    QAction *action;
};


#endif
