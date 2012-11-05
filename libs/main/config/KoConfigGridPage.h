/* This file is part of the KDE project
   Copyright (C) 2002 Laurent Montel <lmontel@mandrakesoft.com>
   Copyright (C) 2006-2007 Jan Hambrecht <jaham@gmx.net>

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

#ifndef KOGRIDCONFIGPAGE_H
#define KOGRIDCONFIGPAGE_H

#include <QWidget>

#include "komain_export.h"

class KoUnit;
class KoDocument;
class KoGridData;

class KOMAIN_EXPORT KoConfigGridPage : public QWidget
{
    Q_OBJECT

public:
    explicit KoConfigGridPage(KoDocument* doc, char* name = 0L);
    ~KoConfigGridPage();

    void apply();

public slots:
    void slotDefault();
    void slotUnitChanged(const KoUnit &unit);
    void spinBoxHSpacingChanged(qreal);
    void spinBoxVSpacingChanged(qreal);

private:
    void setValuesFromGrid(const KoGridData &grid);

    class Private;
    Private * const d;
};

#endif // KOGRIDCONFIGPAGE_H

/* This file is part of the KDE libraries
    Copyright (C) 1997 Martin Jones (mjones@kde.org)

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

#ifndef QCOLORBUTTON_H
#define QCOLORBUTTON_H

#include <QtCore>
#include <QtGui>

class QColorButtonPrivate;
/**
* @short A pushbutton to display or allow user selection of a color.
*
* This widget can be used to display or allow user selection of a color.
*
* @see QColorDialog
*
* \image html QCOLORBUTTON_H.png "Color Button"
*/

class QColorButtonPrivate;

class KOMAIN_EXPORT QColorButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY( QColor color READ color WRITE setColor NOTIFY changed USER true )
    Q_PROPERTY( QColor defaultColor READ defaultColor WRITE setDefaultColor )
    Q_PROPERTY( bool alphaChannelEnabled READ isAlphaChannelEnabled WRITE setAlphaChannelEnabled )

public:
    /**
     * Creates a color button.
     */
    explicit QColorButton( QWidget *parent = 0 );

    /**
     * Creates a color button with an initial color @p c.
     */
    explicit QColorButton( const QColor &c, QWidget *parent = 0 );

    /**
     * Creates a color button with an initial color @p c and default color @p defaultColor.
     */
    QColorButton( const QColor &c, const QColor &defaultColor, QWidget *parent = 0 );

    virtual ~QColorButton();

    /**
     * Returns the currently chosen color.
     */
    QColor color() const;

    /**
     * Sets the current color to @p c.
     */
     void setColor( const QColor &c );

     /**
      * When set to true, allow the user to change the alpha component
      * of the color. The default value is false.
      * @since 4.5
      */
     void setAlphaChannelEnabled( bool alpha );

     /**
      * Returns true if the user is allowed to change the alpha component.
      * @since 4.5
      */
     bool isAlphaChannelEnabled() const;

    /**
     * Returns the default color or an invalid color
     * if no default color is set.
     */
    QColor defaultColor() const;

    /**
     * Sets the default color to @p c.
     */
    void setDefaultColor( const QColor &c );

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

Q_SIGNALS:
    /**
     * Emitted when the color of the widget
     * is changed, either with setColor() or via user selection.
     */
    void changed( const QColor &newColor );

protected:
    virtual void paintEvent( QPaintEvent *pe );
    virtual void mousePressEvent( QMouseEvent *e );
    virtual void mouseMoveEvent( QMouseEvent *e);
    virtual void keyPressEvent( QKeyEvent *e );

private:
	friend class QColorButtonPrivate;
    QColorButtonPrivate * const d;

    Q_PRIVATE_SLOT( d, void _k_chooseColor() )
    Q_PRIVATE_SLOT( d, void _k_colorChosen() )
};


class QColorButtonPrivate
{
	friend class QColorButton;
public:
    QColorButtonPrivate(QColorButton *q);

    void _k_chooseColor();
    void _k_colorChosen();

    QColorButton *q;
    QColor m_defaultColor;
    bool m_bdefaultColor : 1;
    bool m_alphaChannel : 1;

    QColor col;
    QPoint mPos;

    QWeakPointer<QColorDialog> dialogPtr;

    void initStyleOption(QStyleOptionButton* opt) const;    
};

#endif