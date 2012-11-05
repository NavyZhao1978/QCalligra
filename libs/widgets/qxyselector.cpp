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

#include "qxyselector.h"

#include <QStyle>
#include <QPainter>
#include <QStyleOptionFrame>
#include <QMouseEvent>

//-----------------------------------------------------------------------------
/*
 * 2D value selector.
 * The contents of the selector are drawn by derived class.
 */

class QXYSelector::Private
{
public:
  Private(QXYSelector *q):
    q(q),
    xPos(0),
    yPos(0),
    minX(0),
    maxX(100),
    minY(0),
    maxY(100),
    m_markerColor(Qt::white)
  {}

  void setValues(int _xPos, int _yPos);

  QXYSelector *q;
  int px;
  int py;
  int xPos;
  int yPos;
  int minX;
  int maxX;
  int minY;
  int maxY;  
  QColor m_markerColor;
};

QXYSelector::QXYSelector( QWidget *parent )
  : QWidget( parent )
    , d(new Private(this))
{
}


QXYSelector::~QXYSelector()
{
  delete d;
}

int QXYSelector::xValue() const
{
  return d->xPos;
}

int QXYSelector::yValue() const
{
  return d->yPos;
}

void QXYSelector::setRange( int _minX, int _minY, int _maxX, int _maxY )
{
  if (_maxX == _minX) {
     qWarning() << "QXYSelector::setRange invalid range: " << _maxX << " == " << _minX << " (for X) ";
     return;
  }
  if (_maxY == _minY) {
     qWarning() << "QXYSelector::setRange invalid range: " << _maxY << " == " << _minY << " (for Y) ";
     return;
  }


  int w = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  d->px = w;
  d->py = w;
  d->minX = _minX;
  d->minY = _minY;
  d->maxX = _maxX;
  d->maxY = _maxY;
}

void QXYSelector::setXValue( int _xPos )
{
  setValues(_xPos, d->yPos);
}

void QXYSelector::setYValue( int _yPos )
{
  setValues(d->xPos, _yPos);
}

void QXYSelector::setValues( int _xPos, int _yPos )
{
  d->setValues(_xPos, _yPos);
}

void QXYSelector::Private::setValues(int _xPos, int _yPos )
{
  int w = q->style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  
  xPos = _xPos;
  yPos = _yPos;

  if ( xPos > maxX )
    xPos = maxX;
  else if ( xPos < minX )
    xPos = minX;

  if ( yPos > maxY )
    yPos = maxY;
  else if ( yPos < minY )
    yPos = minY;

  Q_ASSERT(maxX != minX);
  int xp = w + (q->width() - 2 * w) * xPos / (maxX - minX);
  
  Q_ASSERT(maxY != minY);
  int yp = q->height() - w - (q->height() - 2 * w) * yPos / (maxY - minY);

  q->setPosition( xp, yp );
}

void QXYSelector::setMarkerColor( const QColor &col )
{
    d->m_markerColor =  col;
}

QRect QXYSelector::contentsRect() const
{
  int w = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  return rect().adjusted(w, w, -w, -w);
}

QSize QXYSelector::minimumSizeHint() const
{
  int w = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  return QSize( 2 * w, 2 * w );
}

void QXYSelector::paintEvent( QPaintEvent * /* ev */ )
{
  QStyleOptionFrame opt;
  opt.initFrom(this);

  QPainter painter;
  painter.begin( this );

  drawContents( &painter );
  drawMarker( &painter, d->px, d->py );

  style()->drawPrimitive( QStyle::PE_Frame, &opt, &painter, this );

  painter.end();
}

void QXYSelector::mousePressEvent( QMouseEvent *e )
{
  mouseMoveEvent( e );
}

void QXYSelector::mouseMoveEvent( QMouseEvent *e )
{
  int xVal, yVal;
  int w = style()->pixelMetric( QStyle::PM_DefaultFrameWidth );
  valuesFromPosition( e->pos().x() - w, e->pos().y() - w, xVal, yVal );
  setValues( xVal, yVal );

  emit valueChanged( d->xPos, d->yPos );
}

void QXYSelector::wheelEvent( QWheelEvent *e )
{
  if ( e->orientation() == Qt::Horizontal )
    setValues( xValue() + e->delta()/120, yValue() );
  else
    setValues( xValue(), yValue() + e->delta()/120 );

  emit valueChanged( d->xPos, d->yPos );
}

void QXYSelector::valuesFromPosition( int x, int y, int &xVal, int &yVal ) const
{
  int w = style()->pixelMetric( QStyle::PM_DefaultFrameWidth );

  xVal = ( ( d->maxX - d->minX ) * ( x - w ) ) / ( width() - 2 * w );
  yVal = d->maxY - ( ( ( d->maxY - d->minY ) * (y - w) ) / ( height() - 2 * w ) );

  if ( xVal > d->maxX )
    xVal = d->maxX;
  else if ( xVal < d->minX )
    xVal = d->minX;

  if ( yVal > d->maxY )
    yVal = d->maxY;
  else if ( yVal < d->minY )
    yVal = d->minY;
}

void QXYSelector::setPosition( int xp, int yp )
{
  int w = style()->pixelMetric( QStyle::PM_DefaultFrameWidth );

  if ( xp < w )
    xp = w;
  else if ( xp > width() - w )
    xp = width() - w;

  if ( yp < w )
    yp = w;
  else if ( yp > height() - w )
    yp = height() - w;

  d->px = xp;
  d->py = yp;

  update();
}

void QXYSelector::drawContents( QPainter * )
{}


void QXYSelector::drawMarker( QPainter *p, int xp, int yp )
{
    QPen pen( d->m_markerColor );
    p->setPen( pen );

/*
  p->drawLine( xp - 6, yp - 6, xp - 2, yp - 2 );
  p->drawLine( xp - 6, yp + 6, xp - 2, yp + 2 );
  p->drawLine( xp + 6, yp - 6, xp + 2, yp - 2 );
  p->drawLine( xp + 6, yp + 6, xp + 2, yp + 2 );
*/
    p->drawEllipse(xp - 4, yp - 4, 8, 8);
}



//#include "qxyselector.moc"
