/* This file is part of the KDE project
 *
 * Copyright (c) 2005-2006 Boudewijn Rempt <boud@valdyas.org>
 * Copyright (c) 2006 Thomas Zander <zander@kde.org>
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
#ifndef KO_TOOL_DOCKER_H
#define KO_TOOL_DOCKER_H

#include <QDockWidget>

class QWidget;

/**
 * The tool docker shows the tool option widget associated with the
 * current tool and the current canvas.
 */
class KoToolDocker : public QDockWidget
{
    Q_OBJECT
public:
    explicit KoToolDocker(QWidget *parent = 0);
    ~KoToolDocker();

    void resetWidgets();

protected:
    virtual void resizeEvent(QResizeEvent* event); ///< reimplemented from QWidget
public slots:
    /**
     * Update the option widgets to the argument one, removing the currently set widget.
     */
    void setOptionWidgets(const QList<QWidget *> &optionWidgetList);

    /**
     * Returns whether the docker has an optionwidget attached
     */
    bool hasOptionWidget();

    /**
     * set the tab option
     */
    void setTabEnabled(bool enabled);

private:
    Q_PRIVATE_SLOT(d, void toggleTab())
    Q_PRIVATE_SLOT(d, void locationChanged(Qt::DockWidgetArea area))

    class Private;
    Private * const d;
};






#include <KoIcon.h>
#include "KoDebug.h"
#include "KoShapeController.h"
#include <KoDockWidgetTitleBarButton.h>
#include <KoDockWidgetTitleBar.h>

class KoToolDocker::Private {
public:
    Private(KoToolDocker *dock)
            : q(dock)
            , tabbed(false)
            , tabIcon(koIconName("tab-new"))
            , unTabIcon(koIconName("tab-close"))
    {
    }

    QList<QWidget *> currentWidgetList;
    QSet<QWidget *> currentAuxWidgets;
    QScrollArea *scrollArea;
    QWidget *hiderWidget; // non current widgets are hidden by being children of this
    QWidget *housekeeperWidget;
    QGridLayout *housekeeperLayout;
    KoToolDocker *q;
    Qt::DockWidgetArea dockingArea;
    bool tabbed;
    QIcon tabIcon;
    QIcon unTabIcon;
    QToolButton *tabButton;


    void resetWidgets()
    {
        currentWidgetList.clear();
        qDeleteAll(currentAuxWidgets);
        currentAuxWidgets.clear();
    }

    void recreateLayout(const QList<QWidget *> &optionWidgetList)
    {
        foreach(QWidget* widget, currentWidgetList) {
            widget->setParent(hiderWidget);
        }
        qDeleteAll(currentAuxWidgets);
        currentAuxWidgets.clear();

        currentWidgetList = optionWidgetList;

        // need to unstretch row that have previously been stretched
        housekeeperLayout->setRowStretch(housekeeperLayout->rowCount()-1, 0);

        if (tabbed && currentWidgetList.size() > 1) {
            KoTabDialog *t;
            housekeeperLayout->addWidget(t = new KoTabDialog(), 0, 0);
            currentAuxWidgets.insert(t);
            foreach(QWidget *widget, currentWidgetList) {
                if (widget->objectName().isEmpty()) {
                    Q_ASSERT(!(widget->objectName().isEmpty()));
                    continue; // skip this docker in release build when assert don't crash
                }
                t->addTab(widget, widget->windowTitle());
            }
        } else {
            int cnt = 0;
            QFrame *s;
            QLabel *l;
            switch(dockingArea) {
            case Qt::TopDockWidgetArea:
            case Qt::BottomDockWidgetArea:
                housekeeperLayout->setHorizontalSpacing(2);
                housekeeperLayout->setVerticalSpacing(0);
                foreach(QWidget* widget, currentWidgetList) {
                    if (widget->objectName().isEmpty()) {
                        continue; // skip this docker in release build when assert don't crash
                    }
                    if (!widget->windowTitle().isEmpty()) {
                        housekeeperLayout->addWidget(l = new QLabel(widget->windowTitle()), 0, 2*cnt);
                        currentAuxWidgets.insert(l);
                    }
                    housekeeperLayout->addWidget(widget, 1, 2*cnt);
                    widget->show();
                    if (widget != currentWidgetList.last()) {
                        housekeeperLayout->addWidget(s = new QFrame(), 0, 2*cnt+1, 2, 1);
                        s->setFrameShape(QFrame::VLine);
                        currentAuxWidgets.insert(s);
                    }
                    cnt++;
                }
                break;
            case Qt::LeftDockWidgetArea:
            case Qt::RightDockWidgetArea: {
                housekeeperLayout->setHorizontalSpacing(0);
                housekeeperLayout->setVerticalSpacing(2);
                int specialCount = 0;
                foreach(QWidget *widget, currentWidgetList) {
                    if (widget->objectName().isEmpty()) {
                        Q_ASSERT(!(widget->objectName().isEmpty()));
                        continue; // skip this docker in release build when assert don't crash
                    }
                    if (!widget->windowTitle().isEmpty()) {
                        housekeeperLayout->addWidget(l = new QLabel(widget->windowTitle()), cnt++, 0);
                        currentAuxWidgets.insert(l);
                    }
                    housekeeperLayout->addWidget(widget, cnt++, 0);
                    QLayout *subLayout = widget->layout();
                    if (subLayout) {
                        for (int i = 0; i < subLayout->count(); ++i) {
                            QWidget *spacerWidget = subLayout->itemAt(i)->widget();
                            if (spacerWidget && spacerWidget->objectName().contains("SpecialSpacer")) {
                                specialCount++;
                            }
                        }
                    }
                    widget->show();
                    if (widget != currentWidgetList.last()) {
                        housekeeperLayout->addWidget(s = new QFrame(), cnt++, 0);
                        s->setFrameShape(QFrame::HLine);
                        currentAuxWidgets.insert(s);
                    }
                }
                if (specialCount == currentWidgetList.count()) {
                    housekeeperLayout->setRowStretch(cnt, 100);
                }
                break;
            }
            default:
                break;
            }
        }
        housekeeperLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        housekeeperLayout->invalidate();
    }

    void locationChanged(Qt::DockWidgetArea area)
    {
        dockingArea = area;
        recreateLayout(currentWidgetList);
    }

    void toggleTab()
    {
        if (!tabbed) {
            tabbed = true;
            tabButton->setIcon(unTabIcon);
        } else {
            tabbed = false;
            tabButton->setIcon(tabIcon);
        }
        recreateLayout(currentWidgetList);
    }
};

#endif
