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

#ifndef FLOWABOUTDATA_H
#define FLOWABOUTDATA_H

//#include <kaboutdata.h>
#include <calligraversion.h>

static const char* FLOW_DESCRIPTION = QObject::tr("Calligra Flowchart And Diagram Tool").toLocal8Bit().data();
static const char* FLOW_VERSION = CALLIGRA_VERSION_STRING;

//KAboutData* newFlowAboutData()
//{
//  KAboutData* aboutData = new KAboutData(QCoreApplication::applicationName().toLocal8Bit(), 0, ki18nc("application name", QCoreApplication::applicationName().toLocal8Bit()),
//                                FLOW_VERSION, ki18n(FLOW_DESCRIPTION), KAboutData::License_LGPL,
//                                ki18n("(C) 2000-2011, The Flow Team"), KLocalizedString(),
//                                "http://www.calligra.org/flow/");
//  aboutData->setProductName(QCoreApplication::applicationName().toLocal8Bit()); // for bugs.kde.org
//  aboutData->setProgramIconName(QCoreApplication::applicationName());
//  aboutData->addAuthor(ki18n("Yue Liu"), ki18n("Maintainer"), "yue.liu@mail.com");
//  aboutData->addAuthor(ki18n("Peter Simonsson"), ki18n("Former Maintainer"), "peter.simonsson@gmail.com");
//
//  return aboutData;
//}

#endif
