/* This file is part of the KDE project
Copyright (C) 2002, 2003 Laurent Montel <lmontel@mandrakesoft.com>
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

#include "KoConfigGridPage.h"

#include <KoDocument.h>
#include <KoGridData.h>
#include <KoUnitDoubleSpinBox.h>
#include <KoAspectButton.h>
#include <KoPart.h>

#include <QDialog>

#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QSettings>






















/*  This file is part of the KDE libraries
    Copyright (C) 1997 Martin Jones (mjones@kde.org)
    Copyright (C) 1999 Cristian Tibirna (ctibirna@kde.org)

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

#include <QtCore/QPointer>
#include <QtGui/QPainter>
#include <QtGui/qdrawutil.h>
#include <QtGui/QApplication>
#include <QtGui/QClipboard>
#include <QtGui/QStyle>
#include <QMouseEvent>
#include <QStyleOptionButton>

QColorButtonPrivate::QColorButtonPrivate(QColorButton *q)
    : q(q)
{
  m_bdefaultColor = false;
  m_alphaChannel = false;
  q->setAcceptDrops(true);

  q->connect(q, SIGNAL(clicked()), q, SLOT(_k_chooseColor()));
}

QColorButton::QColorButton( QWidget *parent )
  : QPushButton( parent )
  , d( new QColorButtonPrivate(this) )
{
}

QColorButton::QColorButton( const QColor &c, QWidget *parent )
  : QPushButton( parent )
  , d( new QColorButtonPrivate(this) )
{
  d->col = c;
}

QColorButton::QColorButton( const QColor &c, const QColor &defaultColor, QWidget *parent )
  : QPushButton( parent )
  , d( new QColorButtonPrivate(this) )
{
  d->col = c;
  setDefaultColor(defaultColor);
}

QColorButton::~QColorButton()
{
  delete d;
}

QColor QColorButton::color() const
{
  return d->col;
}

void QColorButton::setColor( const QColor &c )
{
  if ( d->col != c ) {
    d->col = c;
    update();
    emit changed( d->col );
  }
}

void QColorButton::setAlphaChannelEnabled( bool alpha )
{
    d->m_alphaChannel = alpha;
}

bool QColorButton::isAlphaChannelEnabled() const
{
    return d->m_alphaChannel;
}

QColor QColorButton::defaultColor() const
{
  return d->m_defaultColor;
}

void QColorButton::setDefaultColor( const QColor &c )
{
  d->m_bdefaultColor = c.isValid();
  d->m_defaultColor = c;
}

void QColorButtonPrivate::initStyleOption(QStyleOptionButton* opt) const
{
    opt->initFrom(q);
    opt->state |= q->isDown() ? QStyle::State_Sunken : QStyle::State_Raised;
    opt->features = QStyleOptionButton::None;
    if (q->isDefault())
      opt->features |= QStyleOptionButton::DefaultButton;
    opt->text.clear();
    opt->icon = QIcon();
}

void QColorButton::paintEvent( QPaintEvent* )
{
  QPainter painter(this);
  QStyle *style = QWidget::style();

  //First, we need to draw the bevel.
  QStyleOptionButton butOpt;
  d->initStyleOption(&butOpt);
  style->drawControl( QStyle::CE_PushButtonBevel, &butOpt, &painter, this );

  //OK, now we can muck around with drawing out pretty little color box
  //First, sort out where it goes
  QRect labelRect = style->subElementRect( QStyle::SE_PushButtonContents,
      &butOpt, this );
  int shift = style->pixelMetric( QStyle::PM_ButtonMargin, &butOpt, this ) / 2;
  labelRect.adjust(shift, shift, -shift, -shift);
  int x, y, w, h;
  labelRect.getRect(&x, &y, &w, &h);

  if (isChecked() || isDown()) {
    x += style->pixelMetric( QStyle::PM_ButtonShiftHorizontal, &butOpt, this );
    y += style->pixelMetric( QStyle::PM_ButtonShiftVertical, &butOpt, this );
  }

  QColor fillCol = isEnabled() ? d->col : palette().color(backgroundRole());
  //qDrawShadePanel( &painter, x, y, w, h, palette(), true, 1, NULL);
  if ( fillCol.isValid() ) {
    painter.fillRect( QRect( x+1, y+1, w-2, h-2), fillCol );
  }

  if ( hasFocus() ) {
    QRect focusRect = style->subElementRect( QStyle::SE_PushButtonFocusRect, &butOpt, this );
    QStyleOptionFocusRect focusOpt;
    focusOpt.init(this);
    focusOpt.rect            = focusRect;
    focusOpt.backgroundColor = palette().background().color();
    style->drawPrimitive( QStyle::PE_FrameFocusRect, &focusOpt, &painter, this );
  }
}

QSize QColorButton::sizeHint() const
{
    QStyleOptionButton opt;
    d->initStyleOption(&opt);
    return style()->sizeFromContents(QStyle::CT_PushButton, &opt, QSize(40, 15), this).
	  	expandedTo(QApplication::globalStrut());
}

QSize QColorButton::minimumSizeHint() const
{
    QStyleOptionButton opt;
    d->initStyleOption(&opt);
    return style()->sizeFromContents(QStyle::CT_PushButton, &opt, QSize(3, 3), this).
	  	expandedTo(QApplication::globalStrut());
}

void QColorButton::keyPressEvent( QKeyEvent *e )
{
   QPushButton::keyPressEvent( e );
}

void QColorButton::mousePressEvent( QMouseEvent *e)
{
  d->mPos = e->pos();
  QPushButton::mousePressEvent(e);
}

void QColorButton::mouseMoveEvent( QMouseEvent *e)
{
  //if( (e->buttons() & Qt::LeftButton) &&
  //  (e->pos()-d->mPos).manhattanLength() > KGlobalSettings::dndEventDelay() )
  //{
  //  
  //  setDown(false);
  //}
}

void QColorButtonPrivate::_k_chooseColor()
{
    QColorDialog *dialog = dialogPtr.data();
    if (dialog) {
        dialog->show();
        
        return;
    }

    dialog = new QColorDialog(q);
    //dialog->setAlphaChannelEnabled(m_alphaChannel);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    q->connect(dialog, SIGNAL(applyClicked()), q, SLOT(_k_colorChosen()));
    q->connect(dialog, SIGNAL(okClicked()), q, SLOT(_k_colorChosen()));
    dialogPtr = dialog;
    dialog->show();
}

void QColorButtonPrivate::_k_colorChosen()
{
    QColorDialog *dialog = dialogPtr.data();
    if (!dialog) {
        return;
    }

    if (dialog->getColor().isValid()) {
        q->setColor(dialog->getColor());
    } else if (m_bdefaultColor) {
        q->setColor(m_defaultColor);
    }
}

///////////////////////////////////////////////////////////////////////

class KoConfigGridPage::Private
{
public:
    Private(KoDocument* doc)
    : doc(doc)
    {}

    KoDocument *doc;

    KoUnitDoubleSpinBox* spaceHorizUSpin;
    KoUnitDoubleSpinBox* spaceVertUSpin;
    QCheckBox* gridChBox;
    QCheckBox* snapChBox;
    QColorButton* gridColorBtn;
    //KSharedConfigPtr config;
    KoAspectButton * bnLinkSpacing;
};

KoConfigGridPage::KoConfigGridPage(KoDocument* doc, char* name)
: d(new Private(doc))
{
    setObjectName(name);

    //d->config = d->doc->documentPart()->componentData().config();

    KoUnit unit = d->doc->unit();
    KoGridData &gd = d->doc->gridData();

    QGroupBox* generalGrp = new QGroupBox(QObject::tr("Grid"), this);
    QFormLayout *layoutGeneral = new QFormLayout(generalGrp);
    d->gridChBox = new QCheckBox(generalGrp);
    d->gridChBox->setChecked(gd.showGrid());
    d->snapChBox = new QCheckBox(generalGrp);
    d->snapChBox->setChecked(gd.snapToGrid());
    d->gridColorBtn = new QColorButton(gd.gridColor(), generalGrp);
//#if KDE_IS_VERSION(4,5,0)
//    d->gridColorBtn->setAlphaChannelEnabled(true);
//#endif
    layoutGeneral->addRow(QObject::tr("Show grid:"), d->gridChBox);
    layoutGeneral->addRow(QObject::tr("Snap to grid:"), d->snapChBox);
    layoutGeneral->addRow(QObject::tr("Grid color:"), d->gridColorBtn);

    QGroupBox* spacingGrp = new QGroupBox(QObject::tr("Spacing"), this);
    QHBoxLayout *hboxLayout = new QHBoxLayout(spacingGrp);
    QFormLayout *layoutSpacingGrp = new QFormLayout();
    d->spaceHorizUSpin = new KoUnitDoubleSpinBox(spacingGrp);
    d->spaceHorizUSpin->setMinMaxStep(0.0, 1000, 0.1);
    d->spaceHorizUSpin->setUnit(unit);
    d->spaceHorizUSpin->changeValue(gd.gridX());
    d->spaceVertUSpin = new KoUnitDoubleSpinBox(spacingGrp);
    d->spaceVertUSpin->setMinMaxStep(0.0, 1000, 0.1);
    d->spaceVertUSpin->setUnit(unit);
    d->spaceVertUSpin->changeValue(gd.gridY());
    layoutSpacingGrp->addRow(QObject::tr("Horizontal grid spacing:"), d->spaceHorizUSpin );
    layoutSpacingGrp->addRow(QObject::tr("Vertical grid spacing:"), d->spaceVertUSpin );
    hboxLayout->addLayout(layoutSpacingGrp);
    d->bnLinkSpacing = new KoAspectButton(spacingGrp);
    d->bnLinkSpacing->setKeepAspectRatio(gd.gridX() == gd.gridY());
    hboxLayout->addWidget(d->bnLinkSpacing);
    hboxLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(generalGrp);
    mainLayout->addWidget(spacingGrp);
    mainLayout->addStretch();

    setValuesFromGrid(d->doc->gridData());

    connect(d->spaceHorizUSpin, SIGNAL(valueChangedPt(qreal)),this,SLOT(spinBoxHSpacingChanged(qreal)));
    connect(d->spaceVertUSpin, SIGNAL(valueChangedPt(qreal)),this,SLOT(spinBoxVSpacingChanged(qreal)));
}

KoConfigGridPage::~KoConfigGridPage()
{
    delete d;
}

void KoConfigGridPage::slotUnitChanged(const KoUnit &unit)
{
    d->spaceHorizUSpin->blockSignals(true);
    d->spaceVertUSpin->blockSignals(true);
    d->spaceHorizUSpin->setUnit(unit);
    d->spaceVertUSpin->setUnit(unit);
    d->spaceHorizUSpin->blockSignals(false);
    d->spaceVertUSpin->blockSignals(false);
}

void KoConfigGridPage::apply()
{
    KoGridData &gd = d->doc->gridData();
    gd.setGrid(d->spaceHorizUSpin->value(), d->spaceVertUSpin->value());
    gd.setShowGrid(d->gridChBox->isChecked());
    gd.setSnapToGrid(d->snapChBox->isChecked());
    gd.setGridColor(d->gridColorBtn->color());

    //KConfigGroup gridGroup = d->config->group("Grid");
	QSettings gridGroup("QCalligra", QCoreApplication::applicationName());
	gridGroup.beginGroup("Grid");
    gridGroup.setValue("SpacingX", gd.gridX());
    gridGroup.setValue("SpacingY", gd.gridY());
    gridGroup.setValue("Color", gd.gridColor().value());
	gridGroup.endGroup();
}

void KoConfigGridPage::slotDefault()
{
    KoGridData defGrid;
    setValuesFromGrid(defGrid);
}

void KoConfigGridPage::setValuesFromGrid(const KoGridData &grid)
{
    d->spaceHorizUSpin->changeValue(grid.gridX());
    d->spaceVertUSpin->changeValue(grid.gridY());

    d->gridChBox->setChecked(grid.showGrid());
    d->snapChBox->setChecked(grid.snapToGrid());
    d->gridColorBtn->setColor(grid.gridColor());
}

void KoConfigGridPage::spinBoxHSpacingChanged(qreal v)
{
    if (d->bnLinkSpacing->keepAspectRatio())
        d->spaceVertUSpin->changeValue(v);
}

void KoConfigGridPage::spinBoxVSpacingChanged(qreal v)
{
    if (d->bnLinkSpacing->keepAspectRatio())
        d->spaceHorizUSpin->changeValue(v);
}

//#include <KoConfigGridPage.moc>
