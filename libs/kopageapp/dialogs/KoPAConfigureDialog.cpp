/* This file is part of the KDE project
   Copyright (C) 2009 Thorsten Zachmann <zachmann@kde.org>

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
 * Boston, MA 02110-1301, USA.
*/

#include "KoPAConfigureDialog.h"

#include "KoPAView.h"
#include <KoConfigDocumentPage.h>
#include <KoConfigGridPage.h>
#include <KoConfigMiscPage.h>
#include <KoConfigAuthorPage.h>
#include <KoPACanvasBase.h>
#include <KoShapeController.h>

#include "KoIcon.h"

KoPAConfigureDialog::KoPAConfigureDialog(KoPAView* parent)
: KoTabDialog(parent)
{
    //setFaceType(List);
    setWindowTitle("Configure");
    //setButtons(QDialog::Accepted | QDialog::Apply | QDialog::Rejected | QDialog::Default);
    //setDefaultButton(QDialog::Accepted);

    //m_miscPage = new KoConfigMiscPage( parent->koDocument(), parent->kopaCanvas()->shapeController()->resourceManager() );
    //QWidget *item = addTab( m_miscPage, QObject::tr("Misc" ) );
    //item->setHeader( QObject::tr("Misc" ) );
    //item->setIcon(KoIcon("preferences-other"));

    //m_gridPage = new KoConfigGridPage(parent->koDocument());
    //QWidget *item = addTab(m_gridPage, QObject::tr("Grid"));
    //item->setHeader(QObject::tr("Grid"));
    //item->setIcon(KoIcon("grid"));

    //connect(m_miscPage, SIGNAL(unitChanged(KoUnit)), m_gridPage, SLOT(slotUnitChanged(KoUnit)));

    //m_docPage = new KoConfigDocumentPage( parent->koDocument() );
    //item = addTab( m_docPage, QObject::tr( "Document" ) );
    //item->setHeader( QObject::tr("Document Settings" ) );
    //item->setIcon(KoIcon("document-properties"));

    //m_authorPage = new KoConfigAuthorPage();
    //item = addTab(m_authorPage, QObject::tr("Author"));
    //item->setHeader(QObject::tr("Author"));
    //item->setIcon(KoIcon("user-identity"));

    connect( this, SIGNAL( okClicked() ), this, SLOT( slotApply() ) );
    connect( this, SIGNAL( defaultClicked() ), this, SLOT( slotDefault() ) );
    connect( this, SIGNAL( applyClicked() ), this, SLOT( slotApply() ) );
}

void KoPAConfigureDialog::slotApply()
{
    m_docPage->apply();
    m_gridPage->apply();
    m_miscPage->apply();
    m_authorPage->apply();
}

void KoPAConfigureDialog::slotDefault()
{
    //QWidget* curr = currentPage()->widget();

    //if (curr == m_gridPage) {
    //    m_gridPage->slotDefault();
    //}
    //else if (curr == m_docPage) {
    //    m_docPage->slotDefault();
    //}
}
