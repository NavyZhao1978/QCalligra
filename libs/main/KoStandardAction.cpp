/* This file is part of the KDE libraries
   Copyright (C) 2009 Thomas Zander <zander@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "KoStandardAction.h"

#include <QMenu>
#include <QAction>
#include <KoIcon.h>

QAction *KoStandardAction::create(StandardAction id, const QObject *recvr, const char *slot, QObject *parent)
{
    QAction *newAction = 0;

    switch (id) {
    case ShowGuides: {
        QAction *toggle = new QAction(QObject::tr("Show Guides"), parent);
        toggle->setToolTip(QObject::tr("Shows or hides guides"));
        newAction = toggle;
        break;
    }
    case ActionNone:
        return 0;
    }

    Q_ASSERT(newAction);
    newAction->setObjectName(name(id));

    if (recvr && slot)
        QObject::connect(newAction, SIGNAL(triggered(bool)), recvr, slot);

    QMenu *collection = qobject_cast<QMenu *>(parent);
    if (collection)
        collection->addAction(newAction);

    return newAction;
}

const char* KoStandardAction::name(StandardAction id)
{
    switch (id) {
    case ShowGuides:
        return "view_show_guides";
    default:
        return 0;
    };
}

QAction *KoStandardAction::showGuides(const QObject *receiver, const char *slot, QObject *parent)
{
    return static_cast<QAction*>(create(ShowGuides, receiver, slot, parent));
}
