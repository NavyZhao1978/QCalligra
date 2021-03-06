/* This file is part of the KDE project
   Copyright (C) 2002-2005 David Faure <faure@kde.org>
   Copyright (C) 2002-2004 Clarence Dang <dang@kde.org>

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

#include "KoFileDialog.h"

#include "KoDocument.h"
//#include <KMimeType>
#include "KoDebug.h"

KoFileDialog::KoFileDialog(const QString& startDir, QWidget *parent)
        : QFileDialog(parent, QString(), startDir)
{
    //connect(filterWidget(), SIGNAL(activated(int)),
    //        this, SLOT(slotChangedfilter(int)));
}

void KoFileDialog::slotChangedfilter(int index)
{
    // Switch to "directory selection" mode for SaveAsDirectoryStore,
    // switch back to "file selection" mode otherwise.
    QFileDialog::FileMode newMode = QFileDialog::AnyFile;
    if (index >= 1 && index <= (int)m_specialFormats.count()
            && m_specialFormats[index-1] == KoDocument::SaveAsDirectoryStore) {
        newMode = QFileDialog::Directory;
    }
    if (newMode != fileMode())
        QFileDialog::setFileMode(newMode);
}

void KoFileDialog::setSpecialMimeFilter(QStringList& mimeFilter,
                                        const QString& currentFormat, const int specialOutputFlag,
                                        const QString& nativeFormat,
                                        int supportedSpecialFormats)
{
    Q_ASSERT(!mimeFilter.isEmpty());
    Q_ASSERT(mimeFilter[0] == nativeFormat);

    bool addUncompressed = supportedSpecialFormats & KoDocument::SaveAsDirectoryStore;
    bool addFlatXML = supportedSpecialFormats & KoDocument::SaveAsFlatXML;
    bool addEncrypted = supportedSpecialFormats & KoDocument::SaveEncrypted;

    int idxSpecialOutputFlag = 0;
    int numSpecialEntries = 0;
    if (addUncompressed) {
        ++numSpecialEntries;
        m_specialFormats.append(KoDocument::SaveAsDirectoryStore);
        if (specialOutputFlag == KoDocument::SaveAsDirectoryStore)
            idxSpecialOutputFlag = numSpecialEntries;
    }
    if (addFlatXML) {
        ++numSpecialEntries;
        m_specialFormats.append(KoDocument::SaveAsFlatXML);
        if (specialOutputFlag == KoDocument::SaveAsFlatXML)
            idxSpecialOutputFlag = numSpecialEntries;
    }
    if (addEncrypted) {
        ++numSpecialEntries;
        m_specialFormats.append(KoDocument::SaveEncrypted);
        if (specialOutputFlag == KoDocument::SaveEncrypted)
            idxSpecialOutputFlag = numSpecialEntries;
    }

    // Insert numSpecialEntries entries with native mimetypes, for the special entries.
    for (int i = 0; i < numSpecialEntries; ++i)
        mimeFilter.insert(1, nativeFormat);

    // Fill in filter combo
    // Note: if currentFormat doesn't exist in mimeFilter, filterWidget()
    //       will default to the first item (native format)
    //setNameFilters(mimeFilter, currentFormat.isEmpty() ? nativeFormat : currentFormat);
	//setNameFilters(mimeFilter);

    // To get a different description in the combo, we need to change its entries afterwards
    //KMimeType::Ptr type = KMimeType::mimeType(nativeFormat);
    //if (! type)
    //    type = KMimeType::defaultMimeTypePtr();
    int idx = 1; // 0 is the native format

    if (addUncompressed)
        //filterWidget()->setItemText(idx++, QObject::tr("%1 (Uncompressed XML Files)", type->comment()));
		mimeFilter.append(QObject::tr("%1 (Uncompressed XML Files)").arg(nativeFormat));
    if (addFlatXML)
        //filterWidget()->setItemText(idx++, QObject::tr("%1 (Flat XML File)", type->comment()));
		mimeFilter.append(QObject::tr("%1 (Flat XML File)").arg(nativeFormat));
    if (addEncrypted)
        //filterWidget()->setItemText(idx++, QObject::tr("%1 (Encrypted)", type->comment()));
		mimeFilter.append(QObject::tr("%1 (Encrypted)").arg(nativeFormat));
    // if you add an entry here, update numSpecialEntries above and specialEntrySelected() below

    // For native format...
    if (currentFormat == nativeFormat || currentFormat.isEmpty()) {
        // KFileFilterCombo selected the _last_ "native mimetype" entry, select the correct one
        //filterWidget()->setCurrentIndex(idxSpecialOutputFlag);
        //slotChangedfilter(filterWidget()->currentIndex());
    }
	setNameFilters(mimeFilter);

    // [Mainly Words] Tell MS Office users that they can save in RTF!
    int itemIndex = 0;
    QString compatString;
    //foreach(const QString & tmpString, mimeFilter) {
    //    KMimeType::Ptr mime = KMimeType::mimeType(tmpString);
    //    if (! mime)
    //        mime = KMimeType::defaultMimeTypePtr();
    //    compatString = mime->property("X-KDE-CompatibleApplication").toString();
    //    if (!compatString.isEmpty())
    //        filterWidget()->setItemText(itemIndex, QObject::tr("%1 (%2 Compatible)", mime->comment(), compatString));
    //    itemIndex++;
    //}
}

int KoFileDialog::specialEntrySelected()
{
    //int i = filterWidget()->currentIndex();
    //// Item 0 is the native format, the following ones are the special formats
    //if (i >= 1 && i <= (int)m_specialFormats.count())
    //    return m_specialFormats[i-1];
    return 0;
}

//#include <KoFileDialog.moc>
