/* This file is part of the KDE project
   Copyright (C) 2000 Werner Trobin <trobin@kde.org>

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

#include "KoTemplateTree.h"

#include <QDir>
#include <QImage>
#include <QPixmap>
#include <QPrinter>

#include "KoDebug.h"

#include <QString.h>
#include <QSettings>
#include <stdlib.h>

#include <KoTemplate.h>
#include <KoTemplateGroup.h>
#include <KoTemplates.h>

KoTemplateTree::KoTemplateTree(const QByteArray &templateType,
                               const QString &componentData, bool readTree) :
        m_templateType(templateType), m_componentData(componentData), m_defaultGroup(0),
        m_defaultTemplate(0)
{
    if (readTree)
        readTemplateTree();
}

KoTemplateTree::~KoTemplateTree()
{
    qDeleteAll(m_groups);
}

void KoTemplateTree::readTemplateTree()
{

    readGroups();
    readTemplates();
}

void KoTemplateTree::writeTemplateTree()
{
    //QString localDir = m_componentData.dirs()->saveLocation(m_templateType);

    //foreach (KoTemplateGroup *group, m_groups) {
    //    //kDebug( 30003 ) <<"---------------------------------";
    //    //kDebug( 30003 ) <<"group:" << group->name();

    //    bool touched = false;
    //    QList<KoTemplate*> templates = group->templates();
    //    QList<KoTemplate*>::iterator it = templates.begin();
    //    for (; it != templates.end() && !touched && !group->touched(); ++it)
    //        touched = (*it)->touched();

    //    if (group->touched() || touched) {
    //        //kDebug( 30003 ) <<"touched";
    //        if (!group->isHidden()) {
    //            //kDebug( 30003 ) <<"not hidden";
    //            //KStandardDirs::makeDir(localDir + group->name()); // create the local group dir
				//QDir dir(localDir);
				//dir.mkpath(localDir + group->name());
    //        } else {
    //            //kDebug( 30003 ) <<"hidden";
    //            if (group->dirs().count() == 1 && group->dirs().contains(localDir)) {
    //                //kDebug( 30003 ) <<"local only";
    //                //KIO::NetAccess::del(group->dirs().first(), 0);
				//	QFile::remove(group->dirs().first());
    //                //kDebug( 30003 ) <<"removing:" << group->dirs().first();
    //            } else {
    //                //kDebug( 30003 ) <<"global";
    //                //KStandardDirs::makeDir(localDir + group->name());
				//	QDir dir(localDir);
				//	dir.mkpath(localDir + group->name());
    //            }
    //        }
    //    }
    //    foreach (KoTemplate *t, templates) {
    //        if (t->touched()) {
    //            //kDebug( 30003 ) <<"++template:" << t->name();
    //            writeTemplate(t, group, localDir);
    //        }
    //        if (t->isHidden() && t->touched()) {
    //            //kDebug( 30003 ) <<"+++ delete local template ##############";
    //            writeTemplate(t, group, localDir);
    //            QFile::remove(t->file());
    //            QFile::remove(t->picture());
    //        }
    //    }
    //}
}

void KoTemplateTree::add(KoTemplateGroup *g)
{

    KoTemplateGroup *group = find(g->name());
    if (group == NULL)
        m_groups.append(g);
    else {
        group->addDir(g->dirs().first()); // "...there can be only one..." (Queen)
        delete g;
        g = NULL;
    }
}

KoTemplateGroup *KoTemplateTree::find(const QString &name) const
{
    QList<KoTemplateGroup*>::const_iterator it = m_groups.begin();
    KoTemplateGroup* ret = NULL;

    while (it != m_groups.end()) {
        if ((*it)->name() == name) {
            ret = *it;
            break;
        }

        ++it;
    }

    return ret;
}

void KoTemplateTree::readGroups()
{

    //QStringList dirs = m_componentData.dirs()->resourceDirs(m_templateType);
    //foreach(const QString & dirName, dirs) {
    //    //kDebug( 30003 ) <<"dir:" << *it;
    //    QDir dir(dirName);
    //    // avoid the annoying warning
    //    if (!dir.exists())
    //        continue;
    //    QStringList templateDirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    //    foreach(const QString & templateDirName, templateDirs) {
    //        QDir templateDir(dirName + templateDirName);
    //        QString name = templateDirName;
    //        QString defaultTab;
    //        int sortingWeight = 1000;
    //        if (templateDir.exists(".directory")) {
    //            KDesktopFile config(templateDir.absoluteFilePath(".directory"));
    //            KConfigGroup dg = config.desktopGroup();
    //            name = dg.readEntry("Name");
    //            defaultTab = dg.readEntry("X-KDE-DefaultTab");
    //            sortingWeight = dg.readEntry("X-KDE-SortingWeight", 1000);
    //            //kDebug( 30003 ) <<"name:" << name;
    //        }
    //        KoTemplateGroup *g = new KoTemplateGroup(name, templateDir.absolutePath() + QDir::separator(), sortingWeight);
    //        add(g);
    //        if (defaultTab == "true")
    //            m_defaultGroup = g;
    //    }
    //}
}

void KoTemplateTree::readTemplates()
{
    QString dontShow = "imperial";

    //if (KGlobal::locale()->pageSize() == QPrinter::Letter) {
    //    dontShow = "metric";
    //}

    //foreach (KoTemplateGroup* group, m_groups) {
    //    QStringList dirs = group->dirs();
    //    for (QStringList::ConstIterator it = dirs.constBegin(); it != dirs.constEnd(); ++it) {
    //        QDir d(*it);
    //        if (!d.exists())
    //            continue;
    //        QStringList files = d.entryList(QDir::Files | QDir::Readable, QDir::Name);
    //        for (int i = 0; i < files.count(); ++i) {
    //            QString filePath = *it + files[i];
    //            //kDebug( 30003 ) <<"filePath:" << filePath;
    //            QString icon;
    //            QString text;
    //            QString description;
    //            QString hidden_str;
    //            QString fileName;
    //            bool hidden = false;
    //            bool defaultTemplate = false;
    //            QString templatePath;
    //            QString measureSystem;
    //            // If a desktop file, then read the name from it.
    //            // Otherwise (or if no name in it?) use file name
    //            if (KDesktopFile::isDesktopFile(filePath)) {
    //                KConfig _config(filePath, KConfig::SimpleConfig);
    //                KConfigGroup config(&_config, "Desktop Entry");
    //                if (config.readEntry("Type") == "Link") {
    //                    text = config.readEntry("Name");
    //                    fileName = filePath;
    //                    description = config.readEntry("Comment");
    //                    //kDebug( 30003 ) <<"name:" << text;
    //                    icon = config.readEntry("Icon");
    //                    if (icon[0] != '/' && // allow absolute paths for icons
    //                            QFile::exists(*it + icon)) // allow icons from icontheme
    //                        icon = *it + icon;
    //                    //kDebug( 30003 ) <<"icon2:" << icon;
    //                    hidden = config.readEntry("X-KDE-Hidden", false);
    //                    defaultTemplate = config.readEntry("X-KDE-DefaultTemplate", false);
    //                    measureSystem = config.readEntry("X-KDE-MeasureSystem").toLower();

    //                    // Don't add a template that is for the wrong measure system
    //                    if (measureSystem == dontShow)
    //                        continue;

    //                    //kDebug( 30003 ) <<"hidden:" << hidden_str;
    //                    templatePath = config.readPathEntry("URL", QString());
    //                    //kDebug( 30003 ) <<"Link to :" << templatePath;
    //                    if (templatePath[0] != '/') {
    //                        if (templatePath.left(6) == "file:/") // I doubt this will happen
    //                            templatePath = templatePath.right(templatePath.length() - 6);
    //                        //else
    //                        //  kDebug( 30003 ) <<"dirname=" << *it;
    //                        templatePath = *it + templatePath;
    //                        //kDebug( 30003 ) <<"templatePath:" << templatePath;
    //                    }
    //                } else
    //                    continue; // Invalid
    //            }
    //            // The else if and the else branch are here for compat. with the old system
    //            else if (files[i].right(4) != ".png")
    //                // Ignore everything that is not a PNG file
    //                continue;
    //            else {
    //                // Found a PNG file - the template must be here in the same dir.
    //                icon = filePath;
    //                QFileInfo fi(filePath);
    //                text = fi.baseName();
    //                templatePath = filePath; // Note that we store the .png file as the template !
    //                // That's the way it's always been done. Then the app replaces the extension...
    //            }
    //            KoTemplate *t = new KoTemplate(text, description, templatePath, icon, fileName,
    //                                           measureSystem, hidden);
    //            group->add(t, false, false); // false -> we aren't a "user", false -> don't
    //            // "touch" the group to avoid useless
    //            // creation of dirs in .kde/blah/...
    //            if (defaultTemplate)
    //                m_defaultTemplate = t;
    //        }
    //    }
    //}
}

void KoTemplateTree::writeTemplate(KoTemplate *t, KoTemplateGroup *group,
                                   const QString &localDir)
{
    QString fileName;
    if (t->isHidden()) {
        fileName = t->fileName();
        // try to remove the file
        if (QFile::remove(fileName) || !QFile::exists(fileName)) {
            QFile::remove(t->name());
            QFile::remove(t->picture());
            return;
        }
    }
    // be sure that the template's file name is unique so we don't overwrite an other
    QString const path = localDir + group->name() + '/';
    QString const name = KoTemplates::trimmed(t->name());
    fileName = path + name + ".desktop";
    if (t->isHidden() && QFile::exists(fileName))
        return;
    QString fill;
    //while (KIO::NetAccess::exists(fileName, KIO::NetAccess::SourceSide, 0)) {
	while (QFile::exists(fileName)) {
        fill += '_';
        fileName = path + fill + name + ".desktop";
    }

    //KConfig _config(fileName, KConfig::SimpleConfig);
    //KConfigGroup config(&_config, "Desktop Entry");
	QSettings config(fileName, QSettings::IniFormat);
	config.beginGroup("Desktop Entry");
    config.setValue("Type", "Link");
    config.setValue("URL", t->file());
    config.setValue("Name", t->name());
    config.setValue("Icon", t->picture());
    config.setValue("X-KDE-Hidden", t->isHidden());
	config.endGroup();
}
