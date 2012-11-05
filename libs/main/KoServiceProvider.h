/* This file is part of the KDE project
   Copyright (C) 1998, 1999 Torben Weis <weis@kde.org>
   Copyright (C) 2000-2005 David Faure <faure@kde.org>
   Copyright (C) 2007 Thorsten Zachmann <zachmann@kde.org>
   Copyright (C) 2010 Boudewijn Rempt <boud@kogmbh.com>

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
#ifndef KOSERVICEPROVIDER_H
#define KOSERVICEPROVIDER_H

#include <QByteArray>
#include <QStringList>

#include "komain_export.h"

class KOMAIN_EXPORT KoServiceProvider
{
public:
    /**
     * @brief Used by KoApplication, and by KoMainWindow, when no document exists yet.
     *
     * With the help of @p instance or KApplication::componentData() this
     * method figures out which .desktop file matches this application. In this
     * file it searches for the "X-KDE-NativeMimeType" entry and returns it.
     *
     * @see KService
     * @see KDesktopFile
     */
    static QByteArray readNativeFormatMimeType();

    /**
     * Used by KoMainWindow, when no document exists yet.
     *
     * With the help of @p instance or KApplication::componentData() this
     * method figures out which .desktop file matches this application. In this
     * file it searches for the "X-KDE-ExtraNativeMimeTypes" entry and returns it.
     *
     * @see KService
     * @see KDesktopFile
     */
    static QStringList readExtraNativeMimeTypes();

    /**
     * With the help of @p instance or KApplication::componentData() this
     * method figures out which .desktop file matches this application,
     * and returns the KService instance for it.
     */
    //static KService::Ptr readNativeService(const QString &instance = QString());

};

#endif // KOSERVICEPROVIDER_H