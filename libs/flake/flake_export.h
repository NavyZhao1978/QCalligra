/*  This file is part of the KDE project
    Copyright (C) 2006 David Faure <faure@kde.org>

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

#ifndef FLAKE_EXPORT_H
#define FLAKE_EXPORT_H

#include <QtCore>
#include <QtGui>

#ifndef FLAKE_EXPORT

# if defined(MAKE_FLAKE_LIB)
/* We are building this library */
#  define FLAKE_EXPORT Q_DECL_EXPORT
#  define FLAKE_TEST_EXPORT Q_DECL_EXPORT
# else
/* We are using this library */
#  define FLAKE_EXPORT Q_DECL_IMPORT
#  define FLAKE_TEST_EXPORT Q_DECL_IMPORT
# endif

#endif //FLAKE_EXPORT

#endif //FLAKE_EXPORT_H
