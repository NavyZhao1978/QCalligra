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

#include "qselector.h"

#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QStyle>
#include <QStyleOption>

//using KDEPrivate::fillOpaqueRect;

//-----------------------------------------------------------------------------
/*
 * 1D value selector with contents drawn by derived class.
 * See KColorDialog for example.
 */

#define ARROWSIZE 5

class QSelector::Private
{
	friend class QSelector;
public:
    Private()
    {
        arrowPE = QStyle::PE_IndicatorArrowLeft;
        m_indent = true;
    }

    bool m_indent;
    QStyle::PrimitiveElement arrowPE;
};

class QGradientSelector::QGradientSelectorPrivate
{
public:
  QGradientSelectorPrivate(QGradientSelector *q): q(q) {}

  QGradientSelector *q;
  QLinearGradient gradient;
  QString text1;
  QString text2;
};

QSelector::QSelector( QWidget *parent )
  : QAbstractSlider( parent )
 , d(new Private)
{
    setOrientation(Qt::Horizontal);
}

QSelector::QSelector( Qt::Orientation o, QWidget *parent )
  : QAbstractSlider( parent )
 , d(new Private)
{
    setOrientation(o);
    if(o == Qt::Horizontal)
        setArrowDirection(Qt::UpArrow);
}

QSelector::~QSelector()
{
    delete d;
}

void QSelector::setIndent( bool i )
{
    d->m_indent = i;
}

bool QSelector::indent() const
{
    return d->m_indent;
}

QRect QSelector::contentsRect() const
{
    int w = indent() ? style()->pixelMetric( QStyle::PM_DefaultFrameWidth ) : 0;
    //TODO: is the height:width ratio of an indicator arrow always 2:1? hm.
    int iw = (w < ARROWSIZE) ? ARROWSIZE : w;

    if ( orientation() == Qt::Vertical ) {
        if ( arrowDirection() == Qt::RightArrow ) {
            return QRect( w + ARROWSIZE, iw,
                          width() - w*2 - ARROWSIZE,
                          height() - iw*2 );
        } else {
            return QRect( w, iw,
                          width() - w*2 - ARROWSIZE,
                          height() - iw*2 );
        }
    } else { // Qt::Horizontal
        if ( arrowDirection() == Qt::UpArrow ) {
            return QRect( iw, w,
                          width() - 2*iw,
                          height() - w*2 - ARROWSIZE );
        } else {
            return QRect( iw, w + ARROWSIZE,
                          width() - 2*iw,
                          height() - w*2 - ARROWSIZE );
        }
    }
}

void QSelector::paintEvent( QPaintEvent * )
{
  QPainter painter;
  int w = style()->pixelMetric( QStyle::PM_DefaultFrameWidth );
  int iw = (w < ARROWSIZE) ? ARROWSIZE : w;

  painter.begin( this );

  drawContents( &painter );

  QBrush brush;

  QPoint pos = calcArrowPos( value() );
  drawArrow( &painter, pos );

  if ( indent() )
  {
    QStyleOptionFrame opt;
    opt.initFrom( this );
    opt.state = QStyle::State_Sunken;
    if ( orientation() == Qt::Vertical )
      opt.rect.adjust( 0, iw - w, -5, w - iw );
    else
      opt.rect.adjust(iw - w, 0, w - iw, -5);
    QBrush oldBrush = painter.brush();
    painter.setBrush( Qt::NoBrush );
    style()->drawPrimitive( QStyle::PE_Frame, &opt, &painter, this );
    painter.setBrush( oldBrush );
  }


  painter.end();
}

void QSelector::mousePressEvent( QMouseEvent *e )
{
    setSliderDown(true);
    moveArrow( e->pos() );
}

void QSelector::mouseMoveEvent( QMouseEvent *e )
{
  moveArrow( e->pos() );
}

void QSelector::mouseReleaseEvent( QMouseEvent *e )
{
    moveArrow( e->pos() );
    setSliderDown(false);
}

void QSelector::wheelEvent( QWheelEvent *e )
{
    int val = value() + e->delta()/120;
    setSliderDown(true);
    setValue( val );
    setSliderDown(false);
}

void QSelector::moveArrow( const QPoint &pos )
{
    int val;
    int w = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    int iw = (w < ARROWSIZE) ? ARROWSIZE : w;

    if ( orientation() == Qt::Vertical )
        val = ( maximum() - minimum() ) * (height() - pos.y() - iw)
            / (height() - iw * 2) + minimum();
    else
        val = ( maximum() - minimum() ) * ( pos.x() - iw)
            / (width() - iw * 2) + minimum();

    setValue( val );
    update();
}

QPoint QSelector::calcArrowPos( int val )
{
    QPoint p;
    int w = style()->pixelMetric( QStyle::PM_DefaultFrameWidth );
    int iw = ( w < ARROWSIZE ) ? ARROWSIZE : w;

    if ( orientation() == Qt::Vertical )
    {
        p.setY( height() - iw - 1 - (height() - 2 * iw - 1) * val  / ( maximum() - minimum() ) );

        if ( d->arrowPE == QStyle::PE_IndicatorArrowRight ) {
            p.setX( 0 );
        } else {
            p.setX( width() - 5 );
        }
    }
    else
    {
        p.setX( iw + (width() - 2 * iw - 1) * val  / ( maximum() - minimum() ) );

        if ( d->arrowPE == QStyle::PE_IndicatorArrowDown ) {
            p.setY( 0 );
        } else {
            p.setY( height() - 5 );
        }
    }

    return p;
}

void QSelector::setArrowDirection( Qt::ArrowType direction )
{
    switch ( direction ) {
        case Qt::UpArrow:
            if ( orientation() == Qt::Horizontal ) {
                d->arrowPE = QStyle::PE_IndicatorArrowUp;
            } else {
                d->arrowPE = QStyle::PE_IndicatorArrowLeft;
            }
            break;
        case Qt::DownArrow:
            if ( orientation() == Qt::Horizontal ) {
                d->arrowPE = QStyle::PE_IndicatorArrowDown;
            } else {
                d->arrowPE = QStyle::PE_IndicatorArrowRight;
            }
            break;
        case Qt::LeftArrow:
            if ( orientation() == Qt::Vertical ) {
                d->arrowPE = QStyle::PE_IndicatorArrowLeft;
            } else {
                d->arrowPE = QStyle::PE_IndicatorArrowDown;
            }
            break;
        case Qt::RightArrow:
            if ( orientation() == Qt::Vertical ) {
                d->arrowPE = QStyle::PE_IndicatorArrowRight;
            } else {
                d->arrowPE = QStyle::PE_IndicatorArrowUp;
            }
            break;

        case Qt::NoArrow:
            break;
    }
}

Qt::ArrowType QSelector::arrowDirection() const
{
    switch ( d->arrowPE ) {
        case QStyle::PE_IndicatorArrowUp:
            return Qt::UpArrow;
            break;
        case QStyle::PE_IndicatorArrowDown:
            return Qt::DownArrow;
            break;
        case QStyle::PE_IndicatorArrowRight:
            return Qt::RightArrow;
            break;
        case QStyle::PE_IndicatorArrowLeft:
        default:
            return Qt::LeftArrow;
            break;
    }
}

void QSelector::drawContents( QPainter * )
{}

void QSelector::drawArrow( QPainter *painter, const QPoint &pos )
{
    painter->setPen( QPen() );
    painter->setBrush( QBrush( palette().color(QPalette::ButtonText) ) );

    QStyleOption o;

    if ( orientation() == Qt::Vertical ) {
        o.rect = QRect( pos.x(), pos.y() - ARROWSIZE / 2,
                        ARROWSIZE, ARROWSIZE );
    } else {
        o.rect = QRect( pos.x() - ARROWSIZE / 2, pos.y(),
                        ARROWSIZE, ARROWSIZE );

    }
    style()->drawPrimitive( d->arrowPE, &o, painter, this );
}

//----------------------------------------------------------------------------

QGradientSelector::QGradientSelector( QWidget *parent )
    : QSelector( parent ), d(new QGradientSelectorPrivate(this))
{
}


QGradientSelector::QGradientSelector( Qt::Orientation o, QWidget *parent )
    : QSelector( o, parent ), d(new QGradientSelectorPrivate(this))
{
}


QGradientSelector::~QGradientSelector()
{
    delete d;
}


void QGradientSelector::drawContents( QPainter *painter )
{
  d->gradient.setStart(contentsRect().topLeft());
  if (orientation() == Qt::Vertical) {
      d->gradient.setFinalStop(contentsRect().bottomLeft());
  } else {
      d->gradient.setFinalStop(contentsRect().topRight());
  }
  QBrush gradientBrush(d->gradient);

  //fillOpaqueRect(painter, contentsRect(), gradientBrush);
  painter->setBrush(gradientBrush);
  painter->drawRect(contentsRect());

  if ( orientation() == Qt::Vertical )
  {
    int yPos = contentsRect().top() + painter->fontMetrics().ascent() + 2;
    int xPos = contentsRect().left() + (contentsRect().width() -
       painter->fontMetrics().width( d->text2 )) / 2;
    QPen pen( qGray(firstColor().rgb()) > 180 ? Qt::black : Qt::white );
    painter->setPen( pen );
    painter->drawText( xPos, yPos, d->text2 );

    yPos = contentsRect().bottom() - painter->fontMetrics().descent() - 2;
    xPos = contentsRect().left() + (contentsRect().width() -
      painter->fontMetrics().width( d->text1 )) / 2;
    pen.setColor( qGray(secondColor().rgb()) > 180 ? Qt::black : Qt::white );
    painter->setPen( pen );
    painter->drawText( xPos, yPos, d->text1 );
  }
  else
  {
    int yPos = contentsRect().bottom()-painter->fontMetrics().descent()-2;

    QPen pen( qGray(firstColor().rgb()) > 180 ? Qt::black : Qt::white );
    painter->setPen( pen );
    painter->drawText( contentsRect().left() + 2, yPos, d->text1 );

    pen.setColor( qGray(secondColor().rgb()) > 180 ? Qt::black : Qt::white );
    painter->setPen( pen );
    painter->drawText( contentsRect().right() -
       painter->fontMetrics().width( d->text2 ) - 2, yPos, d->text2 );
  }
}

QSize QGradientSelector::minimumSize() const
{
    return sizeHint();
}

void QGradientSelector::setStops( const QGradientStops &stops )
{
    d->gradient.setStops(stops);
    update();
}

QGradientStops QGradientSelector::stops() const
{
    return d->gradient.stops();
}

void QGradientSelector::setColors( const QColor &col1, const QColor &col2 )
{
  d->gradient.setColorAt(0.0, col1);
  d->gradient.setColorAt(1.0, col2);
  update();
}

void QGradientSelector::setText( const QString &t1, const QString &t2 )
{
  d->text1 = t1;
  d->text2 = t2;
  update();
}

void QGradientSelector::setFirstColor( const QColor &col )
{
  d->gradient.setColorAt(0.0, col);
  update();
}

void QGradientSelector::setSecondColor( const QColor &col )
{
  d->gradient.setColorAt(1.0, col);
  update();
}

void QGradientSelector::setFirstText( const QString &t )
{
  d->text1 = t;
  update();
}

void QGradientSelector::setSecondText( const QString &t )
{
  d->text2 = t;
  update();
}

QColor QGradientSelector::firstColor() const
{
  return d->gradient.stops().first().second;
}

QColor QGradientSelector::secondColor() const
{
  return d->gradient.stops().last().second;
}

QString QGradientSelector::firstText() const
{
  return d->text1;
}

QString QGradientSelector::secondText() const
{
  return d->text2;
}

//#include "qselector.moc"
