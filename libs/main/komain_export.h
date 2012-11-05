/*  This file is part of the KDE project
    Copyright (C) 2006 David Faure <faure@kde.org>
    Copyright (C) 2006 Thomas Zander <zander@kde.org>

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

#ifndef KOMAIN_EXPORT_H
#define KOMAIN_EXPORT_H

#include <QtCore>
#include <QtGui>

#ifndef KOMAIN_EXPORT

# if defined(MAKE_KOMAIN_LIB)
/* We are building this library */
#  define KOMAIN_EXPORT Q_DECL_EXPORT
# else
/* We are using this library */
#  define KOMAIN_EXPORT Q_DECL_IMPORT
# endif

#endif

/* Now the same for KOMAIN_TEST_EXPORT, if compiling with unit tests enabled */

#ifdef COMPILING_TESTS

# if defined(MAKE_KOMAIN_LIB)
#       define KOMAIN_TEST_EXPORT Q_DECL_EXPORT
# else
#       define KOMAIN_TEST_EXPORT Q_DECL_IMPORT
# endif

#else
# define KOMAIN_TEST_EXPORT
#endif //KOMAIN_EXPORT

#endif //KOMAIN_EXPORT_H
