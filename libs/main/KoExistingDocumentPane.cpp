/* Copyright 2008  Peter Simonsson <peter.simonsson@gmail.com>
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

#include "KoExistingDocumentPane.h"

#include "KoDebug.h"

#include <QDialog>
#include <QGridLayout>
#include <QStringList>
#include <QFileDialog>
#include <QPushButton>

KoExistingDocumentPane::KoExistingDocumentPane(QWidget* parent, const QStringList& mimeFilter)
        : QWidget(parent)
        , m_seen(false)
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setMargin(0);

    m_fileWidget  = new QFileDialog(this);
    m_fileWidget->setAcceptMode(QFileDialog::AcceptOpen);
    m_fileWidget->setFilter(mimeFilter.join(" "));
    layout->addWidget(m_fileWidget, 0, 0, 1, -1);

    layout->setColumnStretch(0, 10);

    m_openButton = new QPushButton(QObject::tr("Open Document"), this);
    layout->addWidget(m_openButton, 1, 1);

    connect(m_openButton, SIGNAL(clicked()),
            m_fileWidget, SLOT(slotOk()));
    connect(m_fileWidget, SIGNAL(accepted()),
            this, SLOT(onAccepted()));
}

void KoExistingDocumentPane::onAccepted()
{
    // When double clicked on a file, onAccepted will be called twice
    // To overcome the problem, we set a flag to check onAccepted is called already
    if (!m_seen) {
        m_seen = true;
        m_fileWidget->exec();
        emit openExistingUrl( m_fileWidget->directory().absoluteFilePath(m_fileWidget->selectedFiles().first()) );
    } else {
        // Flag needs to be reset, As while importing the document we can cancel
        // the dialog and come back to the same window
        m_seen = false;
    }
    // Don't set the flag after emiting Signal, Then end up emiting the signal twice
    // before setting the flag
}

//#include <KoExistingDocumentPane.moc>
