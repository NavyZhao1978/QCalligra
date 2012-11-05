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
#ifndef KOEXISTINGDOCUMENTPANE_H
#define KOEXISTINGDOCUMENTPANE_H

#include <QUrl>
#include <QWidget>
#include <QStringList>
#include <QPushButton>
#include <QFileDialog>

class QPushButton;
class QFileDialog;

class KoExistingDocumentPane : public QWidget
{
    Q_OBJECT
public:
    explicit KoExistingDocumentPane(QWidget* parent, const QStringList& mimeFilter);

public slots:
    void onAccepted();

signals:
    void openExistingUrl(const QUrl& url);

private:
    QFileDialog* m_fileWidget;
    QPushButton* m_openButton;
    bool m_seen;
};

#endif //KOEXISTINGDOCUMENTPANE_H
