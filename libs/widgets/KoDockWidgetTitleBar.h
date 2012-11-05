/* This file is part of the KDE project
   Copyright (c) 2007 Marijn Kruisselbrink <mkruisselbrink@kde.org>

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
#ifndef KODOCKWIDGETTITLEBAR_H_
#define KODOCKWIDGETTITLEBAR_H_

#include "kowidgets_export.h"

#include <QtGui>

#include "KoIcon.h"

/**
 * @short A custom title bar for dock widgets.
 *
 * Allow customization such as collapsable, or hidding text.
 * 
 * @see KoDockWidgetTitleBarButton
 */
class KoDockWidgetTitleBarPrivate;

class KOWIDGETS_EXPORT KoDockWidgetTitleBar : public QWidget
{
    Q_OBJECT
public:
    KoDockWidgetTitleBar(QDockWidget* dockWidget);
    virtual ~KoDockWidgetTitleBar();

    virtual QSize minimumSizeHint() const; ///< reimplemented from QWidget
    virtual QSize sizeHint() const;  ///< reimplemented from QWidget

    void setCollapsed(bool collapsed);

    void setCollapsable(bool collapsable);

    enum TextVisibilityMode {TextCanBeInvisible, FullTextAlwaysVisible};
    /// Define whether the minimal width should ensure that the full text is visible.
    /// textVisibilityMode is FullTextAlwaysVisible by default
    void setTextVisibilityMode(TextVisibilityMode textVisibilityMode);

protected:
    virtual void paintEvent(QPaintEvent* event); ///< reimplemented from QWidget
    virtual void resizeEvent(QResizeEvent* event); ///< reimplemented from QWidget
private:

	friend class KoDockWidgetTitleBarPrivate;
    KoDockWidgetTitleBarPrivate * const d;

    Q_PRIVATE_SLOT(d, void toggleFloating())
    Q_PRIVATE_SLOT(d, void toggleCollapsed())
    Q_PRIVATE_SLOT(d, void featuresChanged(QDockWidget::DockWidgetFeatures))
};



class KoDockWidgetTitleBar;

class KoDockWidgetTitleBarPrivate
{
	friend class KoDockWidgetTitleBar;
public:
    KoDockWidgetTitleBarPrivate(KoDockWidgetTitleBar* thePublic)
        : thePublic(thePublic),
            openIcon(thePublic->style()->standardIcon(QStyle::SP_TitleBarShadeButton)),
            closeIcon(thePublic->style()->standardIcon(QStyle::SP_TitleBarUnshadeButton)),
            textVisibilityMode(KoDockWidgetTitleBar::FullTextAlwaysVisible),
            preCollapsedWidth(-1)
    {
        if (openIcon.isNull())
            openIcon = koIcon("arrow-down");
        if (closeIcon.isNull())
            closeIcon = koIcon("arrow-right");
    }
    KoDockWidgetTitleBar* thePublic;
    QIcon openIcon, closeIcon;
    QAbstractButton* closeButton;
    QAbstractButton* floatButton;
    QAbstractButton* collapseButton;

    KoDockWidgetTitleBar::TextVisibilityMode textVisibilityMode;

    int preCollapsedWidth;

    void toggleFloating();
    void toggleCollapsed();
    void featuresChanged(QDockWidget::DockWidgetFeatures features);
};

#endif // KODOCKWIDGETTITLEBAR_H_
