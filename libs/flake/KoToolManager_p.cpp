/* This file is part of the KDE project
 * Copyright (C) 2006 Thomas Zander <zander@kde.org>
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

#include "KoToolManager_p.h"

#include "KoCanvasBase.h"
#include "KoToolBase.h"
#include "KoToolFactoryBase.h"
#include "KoToolManager.h"
#include "KoToolRegistry.h"
#include "KoToolProxy.h"
#include "KoToolProxy_p.h"
#include "KoShapeManager.h"
#include "KoSelection.h"
#include "KoCanvasController.h"
#include "KoCanvasControllerWidget.h"
#include "KoShape.h"
#include "KoShapeLayer.h"
#include "KoShapeRegistry.h"
#include "KoShapeManager.h"
#include "KoInputDevice.h"
#include "KoInputDeviceHandlerRegistry.h"
#include "KoInputDeviceHandlerEvent.h"
#include "KoPointerEvent.h"
#include "tools/KoCreateShapesTool.h"
#include "tools/KoZoomTool.h"
#include "tools/KoPanTool.h"

#include <time.h>

//   ************ ToolHelper **********
ToolHelper::ToolHelper(KoToolFactoryBase *tool)
{
    m_toolFactory = tool;
    //m_uniqueId = (int) random();
	m_uniqueId = rand();
}

QToolButton* ToolHelper::createButton()
{
    QToolButton *but = new QToolButton();
    but->setIcon(QIcon(m_toolFactory->iconName()));
    but->setToolTip(m_toolFactory->toolTip());
    connect(but, SIGNAL(clicked()), this, SLOT(buttonPressed()));
    return but;
}

void ToolHelper::buttonPressed()
{
    emit toolActivated(this);
}

QString ToolHelper::id() const
{
    return m_toolFactory->id();
}

QString ToolHelper::activationShapeId() const
{
    return m_toolFactory->activationShapeId();
}

QString ToolHelper::toolTip() const
{
    return m_toolFactory->toolTip();
}

KoToolBase *ToolHelper::createTool(KoCanvasBase *canvas) const
{
    if (! canCreateTool(canvas))
        return 0;
    KoToolBase *tool = m_toolFactory->createTool(canvas);
    tool->setToolId(id());
    return tool;
}

QString ToolHelper::toolType() const
{
    return m_toolFactory->toolType();
}

int ToolHelper::priority() const
{
    return m_toolFactory->priority();
}

QShortcut ToolHelper::shortcut() const
{
    return m_toolFactory->shortcut();
}

bool ToolHelper::canCreateTool(KoCanvasBase *canvas) const
{
    return m_toolFactory->canCreateTool(canvas);
}

//   ************ Connector **********
Connector::Connector(KoShapeManager *parent)
        : QObject(parent),
        m_shapeManager(parent)
{
    connect(m_shapeManager, SIGNAL(selectionChanged()), this, SLOT(selectionChanged()));
}

void Connector::selectionChanged()
{
    emit selectionChanged(m_shapeManager->selection()->selectedShapes());
}

//   ************ ToolAction **********
ToolAction::ToolAction(KoToolManager* toolManager, QString id, QString name)
    : QAction(name, toolManager),
    m_toolManager(toolManager),
    m_toolID(id)
{
    connect(this, SIGNAL(triggered(bool)), this, SLOT(actionTriggered()));
}

ToolAction::~ToolAction()
{
}

void ToolAction::actionTriggered()
{
    m_toolManager->switchToolRequested(m_toolID);
}



//#include <KoToolManager_p.moc>
