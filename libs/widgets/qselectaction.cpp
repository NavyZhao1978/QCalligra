/* This file is part of the KDE libraries
    Copyright (C) 1999 Reginald Stadlbauer <reggie@kde.org>
              (C) 1999 Simon Hausmann <hausmann@kde.org>
              (C) 2000 Nicolas Hadacek <haadcek@kde.org>
              (C) 2000 Kurt Granroth <granroth@kde.org>
              (C) 2000 Michael Koch <koch@kde.org>
              (C) 2001 Holger Freyther <freyther@kde.org>
              (C) 2002 Ellis Whitehead <ellis@kde.org>
              (C) 2002 Joseph Wenninger <jowenn@kde.org>
              (C) 2003 Andras Mantia <amantia@kde.org>
              (C) 2005-2006 Hamish Rodda <rodda@kde.org>
              (C) 2006 Albert Astals Cid <aacid@kde.org>
              (C) 2006 Clarence Dang <dang@kde.org>
              (C) 2006 Michel Hermier <michel.hermier@gmail.com>
              (C) 2007 Nick Shaforostoff <shafff@ukr.net>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License version 2 as published by the Free Software Foundation.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "qselectaction.h"

#include <QActionEvent>
#include <QEvent>
#include <QToolButton>
#include <QToolBar>
#include <QStandardItem>
#include <QIcon>

#include <QComboBox>
#include <QMenu.h>

#include <QtCore>
#include <QtGui>


  QSelectActionPrivate::QSelectActionPrivate()
    : q_ptr(0)
  {
    m_edit = false;
    m_menuAccelsEnabled = true;
    m_comboWidth = -1;
    m_maxComboViewCount = -1;

    m_toolBarMode = QSelectAction::ComboBoxMode;
    m_toolButtonPopupMode = QToolButton::InstantPopup; //InstantPopup by default because there is no default action

    m_actionGroup = new QActionGroup(0L);
  }

  QSelectActionPrivate::~QSelectActionPrivate()
  {
    // unhook the event filter, as the deletion of the actiongroup
    // will trigger it
    Q_FOREACH( QComboBox* box, m_comboBoxes )
        box->removeEventFilter( q_ptr );
    Q_FOREACH( QToolButton* button, m_buttons )
        button->removeEventFilter( q_ptr );
    delete m_actionGroup;
  }

  QString QSelectActionPrivate::makeMenuText( const QString &_text )
  {
      if ( m_menuAccelsEnabled )
        return _text;
      QString text = _text;
      int i = 0;
      while ( i < text.length() ) {
          if ( text[ i ] == '&' ) {
              text.insert( i, '&' );
              i += 2;
          }
          else
              ++i;
      }
      return text;
  }

// QAction::setText("Hi") and then KPopupAccelManager exec'ing, causes
// QAction::text() to return "&Hi" :(  Comboboxes don't have accels and
// display ampersands literally.
static QString DropAmpersands(const QString &text)
{
    //return KGlobal::locale()->removeAcceleratorMarker(text);
	return (text);
}


QSelectAction::QSelectAction(QObject *parent)
  : QAction(parent)
  , d_ptr(new QSelectActionPrivate())
{
  Q_D(QSelectAction);
  d->init(this);
}

QSelectAction::QSelectAction(const QString &text, QObject *parent)
  : QAction(parent)
  , d_ptr(new QSelectActionPrivate())
{
  Q_D(QSelectAction);
  d->init(this);
  setText(text);
}

QSelectAction::QSelectAction(const QIcon & icon, const QString &text, QObject *parent)
  : QAction(icon, text, parent)
  , d_ptr(new QSelectActionPrivate())
{
  Q_D(QSelectAction);
  d->init(this);
}

QSelectAction::QSelectAction(QSelectActionPrivate &dd, QObject *parent)
  : QAction(parent)
  , d_ptr(&dd)
{
  Q_D(QSelectAction);
  d->init(this);
}

QSelectAction::~QSelectAction()
{
  delete d_ptr;
  delete menu();
}

void QSelectActionPrivate::init(QSelectAction *q)
{
  q_ptr = q;
  QObject::connect(q_ptr->selectableActionGroup(), SIGNAL(triggered(QAction*)), q_ptr, SLOT(actionTriggered(QAction*)));
  QObject::connect(q_ptr, SIGNAL(toggled(bool)), q_ptr, SLOT(slotToggled(bool)));
  q_ptr->setMenu(new QMenu());
  q_ptr->setEnabled( false );
}

QActionGroup * QSelectAction::selectableActionGroup( ) const
{
  Q_D(const QSelectAction);
  return d->m_actionGroup;
}

QList<QAction*> QSelectAction::actions( ) const
{
  return selectableActionGroup()->actions();
}

QAction* QSelectAction::currentAction() const
{
  return selectableActionGroup()->checkedAction();
}

int QSelectAction::currentItem() const
{
  return selectableActionGroup()->actions().indexOf(currentAction());
}

QString QSelectAction::currentText( ) const
{
  if (QAction* a = currentAction())
    return ::DropAmpersands(a->text());

  return QString();
}

bool QSelectAction::setCurrentAction(QAction* action)
{
  //kDebug (129) << "QSelectAction::setCurrentAction(" << action << ")";
  if (action) {
    if (actions().contains(action)) {
      if (action->isVisible() && action->isEnabled() && action->isCheckable()) {
        action->setChecked(true);
        if (isCheckable())
            setChecked(true);
        return true;
      } else
        qWarning() << "Action does not have the correct properties to be current:" << action->text();
    } else
      qWarning() << "Action does not belong to group:" << action->text();
    return false;
  }

  if (currentAction())
    currentAction()->setChecked(false);

  return false;
}

bool QSelectAction::setCurrentItem( int index )
{
  //kDebug (129) << "QSelectAction::setCurrentIndex(" << index << ")";
  return setCurrentAction(action(index));
}

QAction * QSelectAction::action( int index ) const
{
  if (index >= 0 && index < selectableActionGroup()->actions().count())
    return selectableActionGroup()->actions().at(index);

  return 0L;
}

QAction * QSelectAction::action( const QString & text, Qt::CaseSensitivity cs ) const
{
  QString compare;
  if (cs == Qt::CaseSensitive)
    compare = text;
  else
    compare = text.toLower();

  foreach (QAction* action, selectableActionGroup()->actions()) {
    const QString text = ::DropAmpersands(action->text());
    if (cs == Qt::CaseSensitive) {
      if (text == compare) {
        return action;
      }

    } else if (cs == Qt::CaseInsensitive) {
      if (text.toLower() == compare) {
        return action;
      }
    }
  }

  return 0L;
}

bool QSelectAction::setCurrentAction( const QString & text, Qt::CaseSensitivity cs)
{
  //kDebug (129) << "QSelectAction::setCurrentAction(" << text << ",cs=" << cs << ")";
  return setCurrentAction(action(text, cs));
}

void QSelectAction::setComboWidth( int width )
{
  Q_D(QSelectAction);
  if ( width < 0 )
    return;

  d->m_comboWidth = width;

  foreach (QComboBox* box, d->m_comboBoxes)
    box->setMaximumWidth(d->m_comboWidth);

  emit changed();
}

void QSelectAction::setMaxComboViewCount( int n )
{
  Q_D(QSelectAction);
  d->m_maxComboViewCount = n;

  foreach (QComboBox* box, d->m_comboBoxes)
    if ( d->m_maxComboViewCount != -1 )
      box->setMaxVisibleItems(d->m_maxComboViewCount);
    else
      // hardcoded qt default
      box->setMaxVisibleItems(10);

  emit changed();
}

void QSelectAction::addAction(QAction* action)
{
  Q_D(QSelectAction);
  //kDebug (129) << "QSelectAction::addAction(" << action << ")";

  action->setActionGroup(selectableActionGroup());

  // Re-Enable when an action is added
  setEnabled(true);

  // Keep in sync with createToolBarWidget()
  foreach (QToolButton* button, d->m_buttons) {
    button->setEnabled(true);
    button->addAction(action);
  }

  foreach (QComboBox* comboBox, d->m_comboBoxes) {
    comboBox->setEnabled(true);
    comboBox->addAction(action);
  }

  menu()->addAction(action);
}

QAction* QSelectAction::addAction(const QString &text)
{
  Q_D(QSelectAction);
  QAction* newAction = new QAction(parent());
  newAction->setText(text);
  newAction->setCheckable( true );
  //newAction->setShortcutConfigurable(false);

  if (!d->m_menuAccelsEnabled) {
    newAction->setText(text);
    newAction->setShortcut(QKeySequence());
  }

  addAction(newAction);
  return newAction;
}

QAction* QSelectAction::addAction(const QIcon& icon, const QString& text)
{
  QAction* newAction = addAction(text);
  newAction->setIcon(icon);
  return newAction;
}

QAction* QSelectAction::removeAction(QAction* action)
{
  Q_D(QSelectAction);
  //kDebug (129) << "QSelectAction::removeAction(" << action << ")";
  //int index = selectableActionGroup()->actions().indexOf(action);
  //kDebug (129) << "\tindex=" << index;

  // Removes the action from the group and sets its parent to null.
  d->m_actionGroup->removeAction(action);

  // Disable when no action is in the group
  bool hasActions = selectableActionGroup()->actions().isEmpty();
  setEnabled( !hasActions );

  foreach (QToolButton* button, d->m_buttons) {
    button->setEnabled( !hasActions );
    button->removeAction(action);
  }

  foreach (QComboBox* comboBox, d->m_comboBoxes)
  {
    comboBox->setEnabled( !hasActions );
    comboBox->removeAction(action);
  }

  menu()->removeAction(action);


  return action;
}

void QSelectAction::actionTriggered(QAction* action)
{
  // cache values so we don't need access to members in the action
  // after we've done an emit()
  const QString text = ::DropAmpersands(action->text());
  const int index = selectableActionGroup()->actions().indexOf(action);
  //kDebug (129) << "QSelectAction::actionTriggered(" << action << ") text=" << text
  //          << " index=" << index  << " emitting triggered()" << endl;

  if (isCheckable()) // if this is subsidiary of other QSelectAction-derived class
    trigger();       // then imitate usual QAction behaviour so that other submenus (and their items) become unchecked

  emit triggered(action);
  emit triggered(index);
  emit triggered(text);
}

QStringList QSelectAction::items() const
{
  Q_D(const QSelectAction);
  QStringList ret;

  foreach (QAction* action, d->m_actionGroup->actions())
    ret << ::DropAmpersands(action->text());

  return ret;
}

void QSelectAction::changeItem( int index, const QString& text )
{
  Q_D(QSelectAction);
  if ( index < 0 || index >= actions().count() )
  {
    qWarning() << "QSelectAction::changeItem Index out of scope";
    return;
  }

  actions()[index]->setText( d->makeMenuText( text ) );
}

void QSelectAction::setItems( const QStringList &lst )
{
  Q_D(QSelectAction);
  //kDebug (129) << "QSelectAction::setItems(" << lst << ")";

  clear();

  foreach (const QString& string, lst) {
    if ( !string.isEmpty() ) {
      addAction(string);
    } else {
      QAction* action = new QAction(this);
      action->setSeparator(true);
      addAction(action);
    }
  }

  // Disable if empty and not editable
  setEnabled( lst.count() > 0 || d->m_edit );
}

int QSelectAction::comboWidth() const
{
  Q_D(const QSelectAction);
  return d->m_comboWidth;
}

void QSelectAction::clear()
{
  Q_D(QSelectAction);
  //kDebug (129) << "QSelectAction::clear()";

  // we need to delete the actions later since we may get a call to clear()
  // from a method called due to a triggered(...) signal
  const QList<QAction*> actions = d->m_actionGroup->actions();
  for (int i = 0; i < actions.count(); ++i)
  {
    // deleteLater() only removes us from the actions() list (among
    // other things) on the next entry into the event loop.  Until then,
    // e.g. action() and setCurrentItem() will be working on items
    // that are supposed to have been deleted.  So detach the action to
    // prevent this from happening.
    removeAction(actions[i]);

    actions[i]->deleteLater();
  }
}

void QSelectAction::removeAllActions( )
{
  Q_D(QSelectAction);
  while (d->m_actionGroup->actions().count())
    removeAction(d->m_actionGroup->actions().first());
}

void QSelectAction::setEditable( bool edit )
{
  Q_D(QSelectAction);
  d->m_edit = edit;

  foreach (QComboBox* comboBox, d->m_comboBoxes)
    comboBox->setEditable(edit);

  emit changed();
}

bool QSelectAction::isEditable() const
{
  Q_D(const QSelectAction);
  return d->m_edit;
}

void QSelectAction::slotToggled(bool checked)
{
    //if (checked && selectableActionGroup()->checkedAction())
    if (!checked && currentAction()) // other's submenu item has been selected
        currentAction()->setChecked(false);
}

QSelectAction::ToolBarMode QSelectAction::toolBarMode() const
{
  Q_D(const QSelectAction);
  return d->m_toolBarMode;
}

void QSelectAction::setToolBarMode( ToolBarMode mode )
{
  Q_D(QSelectAction);
  d->m_toolBarMode = mode;
}

QToolButton::ToolButtonPopupMode QSelectAction::toolButtonPopupMode( ) const
{
  Q_D(const QSelectAction);
  return d->m_toolButtonPopupMode;
}

void QSelectAction::setToolButtonPopupMode( QToolButton::ToolButtonPopupMode mode )
{
  Q_D(QSelectAction);
  d->m_toolButtonPopupMode = mode;
}

void QSelectActionPrivate::_k_comboBoxDeleted(QObject* object)
{
  foreach (QComboBox* comboBox, m_comboBoxes)
    if (object == comboBox) {
      m_comboBoxes.removeAll(static_cast<QComboBox*>(object));
      break;
    }
}

void QSelectActionPrivate::_k_comboBoxCurrentIndexChanged(int index)
{
    Q_Q(QSelectAction);
  //kDebug (129) << "QSelectActionPrivate::_k_comboBoxCurrentIndexChanged(" << index << ")";

  QComboBox *triggeringCombo = qobject_cast <QComboBox *> (q->sender ());

  QAction *a = q->action(index);
  //kDebug (129) << "\ta=" << a;
  if (a) {
    //kDebug (129) << "\t\tsetting as current action";
    a->trigger();

  } else if (q->isEditable () &&
    triggeringCombo && triggeringCombo->count () > 0 &&
    index == triggeringCombo->count () - 1) {

    // User must have added a new item by typing and pressing enter.
    const QString newItemText = triggeringCombo->currentText ();
    //kDebug (129) << "\t\tuser typed new item '" << newItemText << "'";

    // Only 1 combobox contains this and it's not a proper action.
    bool blocked = triggeringCombo->blockSignals (true);
    triggeringCombo->removeItem (index);
    triggeringCombo->blockSignals (blocked);

    QAction *newAction = q->addAction (newItemText);

    newAction->trigger();
  } else {
    if (q->selectableActionGroup()->checkedAction())
      q->selectableActionGroup()->checkedAction()->setChecked(false);
  }
}

// TODO: DropAmpersands() certainly makes sure this doesn't work.  But I don't
// think it did anyway esp. in the presence KCheckAccelerator - Clarence.
void QSelectAction::setMenuAccelsEnabled( bool b )
{
  Q_D(QSelectAction);
  d->m_menuAccelsEnabled = b;
}

bool QSelectAction::menuAccelsEnabled() const
{
  Q_D(const QSelectAction);
  return d->m_menuAccelsEnabled;
}

QWidget * QSelectAction::createWidget( QWidget * parent )
{
  Q_D(QSelectAction);
    QMenu *menu = qobject_cast<QMenu *>(parent);
    if (menu) // If used in a menu want to return 0 and use only the text, not a widget
        return 0;
    ToolBarMode mode = toolBarMode();
    QToolBar *toolBar = qobject_cast<QToolBar *>(parent);
    if (!toolBar && mode != ComboBoxMode) { // we can return a combobox just fine.
        return 0;
    }
    switch (mode) {
    case MenuMode: {
      QToolButton* button = new QToolButton(toolBar);
      button->setToolTip(toolTip());
      button->setWhatsThis(whatsThis());
      button->setStatusTip(statusTip());
      button->setAutoRaise(true);
      button->setFocusPolicy(Qt::NoFocus);
      button->setIconSize(toolBar->iconSize());
      button->setToolButtonStyle(toolBar->toolButtonStyle());
      QObject::connect(toolBar, SIGNAL(iconSizeChanged(const QSize&)),
                       button, SLOT(setIconSize(const QSize&)));
      QObject::connect(toolBar, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)),
                       button, SLOT(setToolButtonStyle(Qt::ToolButtonStyle)));
      button->setDefaultAction(this);
      QObject::connect(button, SIGNAL(triggered(QAction*)), toolBar, SIGNAL(actionTriggered(QAction*)));

      button->setPopupMode(toolButtonPopupMode());

      button->addActions(selectableActionGroup()->actions());

      d->m_buttons.append(button);
      return button;
    }

    case ComboBoxMode: {
      QComboBox* comboBox = new QComboBox(parent);
      comboBox->installEventFilter (this);

      if ( d->m_maxComboViewCount != -1 )
        comboBox->setMaxVisibleItems( d->m_maxComboViewCount );

      if ( d->m_comboWidth > 0 )
        comboBox->setMaximumWidth( d->m_comboWidth );

      comboBox->setEditable(isEditable());
      comboBox->setToolTip(toolTip());
      comboBox->setWhatsThis(whatsThis());
      comboBox->setStatusTip(statusTip());

      foreach (QAction* action, selectableActionGroup()->actions())
        comboBox->addAction(action);

      if (selectableActionGroup()->actions().isEmpty())
          comboBox->setEnabled(false);

      connect(comboBox, SIGNAL(destroyed(QObject*)), SLOT(_k_comboBoxDeleted(QObject*)));
      connect(comboBox, SIGNAL(currentIndexChanged(int)), SLOT(_k_comboBoxCurrentIndexChanged(int)));
      d->m_comboBoxes.append(comboBox);

      return comboBox;
    }
  }

  return 0L;
}

void QSelectAction::deleteWidget(QWidget *widget)
{
    Q_D(QSelectAction);
    if (QToolButton *toolButton = qobject_cast<QToolButton *>(widget))
        d->m_buttons.removeAll(toolButton);
    else if (QComboBox *comboBox = qobject_cast<QComboBox *>(widget))
        d->m_comboBoxes.removeAll(comboBox);
    //QAction::deleteWidget(widget);
}

bool QSelectAction::event(QEvent *event)
{
    Q_D(QSelectAction);
    if (event->type() == QEvent::ActionChanged) {
        Q_FOREACH(QComboBox* comboBox, d->m_comboBoxes) {
            comboBox->setToolTip(toolTip());
            comboBox->setWhatsThis(whatsThis());
            comboBox->setStatusTip(statusTip());
        }
        Q_FOREACH(QToolButton* toolButton, d->m_buttons) {
            toolButton->setToolTip(toolTip());
            toolButton->setWhatsThis(whatsThis());
            toolButton->setStatusTip(statusTip());
        }
    }
    return QAction::event(event);
}

// QSelectAction::eventFilter() is called before action->setChecked()
// invokes the signal to update QActionGroup so QSelectAction::currentItem()
// returns an old value.  There are 3 possibilities, where n actions will
// report QAction::isChecked() where n is:
//
// 0: the checked action was unchecked
// 1: the checked action did not change
// 2: another action was checked but QActionGroup has not been invoked yet
//    to uncheck the one that was checked before
//
// TODO: we might want to cache this since QEvent::ActionChanged is fired
//       often.
static int TrueCurrentItem (QSelectAction *sa)
{
  QAction *curAction = sa->currentAction ();
  //kDebug (129) << "\tTrueCurrentItem(" << sa << ") curAction=" << curAction;

  foreach (QAction *action, sa->actions ())
  {
    if (action->isChecked ())
    {
       //kDebug (129) << "\t\taction " << action << " (text=" << action->text () << ") isChecked";

       // 2 actions checked case?
       if (action != curAction)
       {
         //kDebug (129) << "\t\t\tmust be newly selected one";
         return sa->actions ().indexOf (action);
       }
    }
  }

  //kDebug (129) << "\t\tcurrent action still selected? " << (curAction && curAction->isChecked ());
  // 1 or 0 actions checked case (in that order)?
  return (curAction && curAction->isChecked ()) ? sa->actions ().indexOf (curAction) : -1;
}

// We store the QAction* as the userData of each combobox item
Q_DECLARE_METATYPE(QAction*)

bool QSelectAction::eventFilter (QObject *watched, QEvent *event)
{
  QComboBox *comboBox = qobject_cast <QComboBox *> (watched);
  if (!comboBox)
    return false/*propagate event*/;


  // If focus is lost, replace any edited text with the currently selected
  // item.
  if (event->type () == QEvent::FocusOut) {
    QFocusEvent * const e = static_cast <QFocusEvent *> (event);
    //kDebug (129) << "QSelectAction::eventFilter(FocusOut)"
    //  << "    comboBox: ptr=" << comboBox
    //  << " reason=" << e->reason ()
    //  << endl;

    if (e->reason () != Qt::ActiveWindowFocusReason/*switch window*/ &&
        e->reason () != Qt::PopupFocusReason/*menu*/ &&
        e->reason () != Qt::OtherFocusReason/*inconsistently reproduceable actions...*/) {

      //kDebug (129) << "\tkilling text";
      comboBox->setEditText (comboBox->itemText (comboBox->currentIndex ()));
    }

    return false/*propagate event*/;
  }

  bool blocked = comboBox->blockSignals (true);

  if (event->type () == QEvent::ActionAdded)
  {
    QActionEvent * const e = static_cast <QActionEvent *> (event);

    const int index = e->before () ?
      comboBox->findData (QVariant::fromValue (e->before ())) :
      comboBox->count ();
    const int newItem = ::TrueCurrentItem (this);
    //kDebug (129) << "QSelectAction::eventFilter(ActionAdded)"
    //          << "    comboBox: ptr=" << comboBox
    //          << " currentItem=" << comboBox->currentIndex ()
    //          << "    add index=" << index
    //          << "    action new: e->before=" << e->before ()
    //          << " ptr=" << e->action ()
    //          << " icon=" << e->action ()->icon ()
    //          << " text=" << e->action ()->text ()
    //          << " currentItem=" << newItem
    //          << endl;
    comboBox->insertItem (index,
      e->action()->icon(),
      ::DropAmpersands (e->action()->text()),
      QVariant::fromValue (e->action ()));
    if (QStandardItemModel *model = qobject_cast<QStandardItemModel *>(comboBox->model())) {
        QStandardItem *item = model->item(index);
        item->setEnabled(e->action()->isEnabled());
    }

    // Inserting an item into a combobox can change the current item so
    // make sure the item corresponding to the checked action is selected.
    comboBox->setCurrentIndex (newItem);
  }
  else if (event->type () == QEvent::ActionChanged)
  {
    QActionEvent * const e = static_cast <QActionEvent *> (event);

    const int index = comboBox->findData (QVariant::fromValue (e->action ()));
    const int newItem = ::TrueCurrentItem (this);
    //kDebug (129) << "QSelectAction::eventFilter(ActionChanged)"
    //          << "    comboBox: ptr=" << comboBox
    //          << " currentItem=" << comboBox->currentIndex ()
    //          << "    changed action's index=" << index
    //          << "    action new: ptr=" << e->action ()
    //          << " icon=" << e->action ()->icon ()
    //          << " text=" << e->action ()->text ()
    //          << " currentItem=" << newItem
    //          << endl;
    comboBox->setItemIcon (index, e->action ()->icon ());
    comboBox->setItemText (index, ::DropAmpersands (e->action ()->text ()));
    if (QStandardItemModel *model = qobject_cast<QStandardItemModel *>(comboBox->model())) {
        QStandardItem *item = model->item(index);
        item->setEnabled(e->action()->isEnabled());
    }

    // The checked action may have become unchecked so
    // make sure the item corresponding to the checked action is selected.
    comboBox->setCurrentIndex (newItem);
  }
  else if (event->type () == QEvent::ActionRemoved)
  {
    QActionEvent * const e = static_cast <QActionEvent *> (event);

    const int index = comboBox->findData (QVariant::fromValue (e->action ()));
    const int newItem = ::TrueCurrentItem (this);
    //kDebug (129) << "QSelectAction::eventFilter(ActionRemoved)"
    //          << "    comboBox: ptr=" << comboBox
    //          << " currentItem=" << comboBox->currentIndex ()
    //          << "    delete action index=" << index
    //          << "    new: currentItem=" << newItem
    //          << endl;
    comboBox->removeItem (index);

    // Removing an item from a combobox can change the current item so
    // make sure the item corresponding to the checked action is selected.
    comboBox->setCurrentIndex (newItem);
  }

  comboBox->blockSignals (blocked);

  return false/*propagate event*/;
}

// END

/* vim: et sw=2 ts=2
 */

//#include "qselectaction.moc"
