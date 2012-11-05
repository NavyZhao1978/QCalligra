/* This file is part of the KDE project
   Copyright (C) 1998, 1999 Torben Weis <weis@kde.org>
   Copyright (C) 2007 Thomas Zander <zander@kde.org>
   Copyright (C) 2010 Benjamin Port <port.benjamin@gmail.com>

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
#ifndef __koView_h__
#define __koView_h__

#include <QtCore>
#include <QtGui>
#include <QtXml>

#include "komain_export.h"

class KoPart;
class KoDocument;
class KoMainWindow;
class KoPrintJob;
class KoViewPrivate;
class KoZoomController;
class KoPageLayout;

class QStatusBar;
class QMainWindow;
class QAction;
class QToolBar;
class QDragEnterEvent;
class QDropEvent;
class QPrintDialog;

class KOMAIN_EXPORT KoView : public QWidget
{
    Q_OBJECT

public:

    KoView(KoPart *part, KoDocument *document, QWidget *parent = 0);

    virtual ~KoView();

    // QWidget overrides
protected:

    virtual void dragEnterEvent(QDragEnterEvent * event);

    virtual void dropEvent(QDropEvent * event);

    virtual void addImages(const QList<QImage> &imageList, const QPoint &insertAt);

public:

    KoDocument *koDocument() const;

    void setDocumentDeleted();

    bool documentDeleted() const;

    virtual QAction *action(const QDomElement &element) const;

    virtual QAction *action(const char* name) const;

    virtual KoDocument *hitTest(const QPoint &pos);

    virtual int leftBorder() const;
    /**
     * @see #leftBorder
     */
    virtual int rightBorder() const;
    /**
     * @see #leftBorder
     */
    virtual int topBorder() const;
    /**
     * @see #leftBorder
     */
    virtual int bottomBorder() const;

    /**
     * Overload this function if the content will be displayed
     * on some child widget instead of the view directly.
     *
     * By default this function returns a pointer to the view.
     */
    virtual QWidget *canvas() const;

    /**
     * Overload this function if the content will be displayed
     * with an offset relative to the upper left corner
     * of the canvas widget.
     *
     * By default this function returns 0.
     */
    virtual int canvasXOffset() const;

    /**
     * Overload this function if the content will be displayed
     * with an offset relative to the upper left corner
     * of the canvas widget.
     *
     * By default this function returns 0.
     */
    virtual int canvasYOffset() const;

    /**
     * Sets up so that autoScroll signals are emitted when the mouse pointer is outside the view
     */
    void enableAutoScroll();

    /**
     * Stops the emitting of autoScroll signals
     */
    void disableAutoScroll();

    /**
     * In order to print the document represented by this view a new print job should
     * be constructed that is capable of doing the printing.
     * The default implementation returns 0, which silently cancels printing.
     */
    virtual KoPrintJob * createPrintJob();

    /**
     * In order to export the document represented by this view a new print job should
     * be constructed that is capable of doing the printing.
     * The default implementation call createPrintJob.
     */
    virtual KoPrintJob * createPdfPrintJob();

    /**
     * @return the page layout to be used for printing.
     * Default is the documents layout.
     * Reimplement if your application needs to use a different layout.
     */
    virtual KoPageLayout pageLayout() const;

    /**
     * Create a QPrintDialog based on the @p printJob
     */
    virtual QPrintDialog *createPrintDialog(KoPrintJob *printJob, QWidget *parent);

    KoMainWindow * shell() const;

    QMainWindow* mainWindow() const;

    QStatusBar * statusBar() const;

    void addStatusBarItem(QWidget * widget, int stretch = 0, bool permanent = false);

    void removeStatusBarItem(QWidget * widget);

    void showAllStatusBarItems(bool show);

    virtual void updateReadWrite(bool readwrite) = 0;

    /**
     * Return the zoomController for this view.
     */
    virtual KoZoomController *zoomController() const = 0;

    /**
     * @return the view bar. The bar is created only if this function is called.
     */
    QToolBar* viewBar();

    /// create a list of actions that when activated will change the unit on the document.
    QList<QAction*> createChangeUnitActions();

public slots:
    /**
     * Slot to create a new view around the contained @ref #koDocument.
     */
    virtual void newView();

    /**
     * Display a message in the status bar (calls QStatusBar::message())
     * @todo rename to something more generic
     */
    void slotActionStatusText(const QString &text);

    /**
     * End of the message in the status bar (calls QStatusBar::clear())
     * @todo rename to something more generic
     */
    void slotClearStatusText();

protected:

    /**
       Generate a name for this view.
    */
    QString newObjectName();

signals:
    void activated(bool active);
    void selected(bool select);

    void autoScroll(const QPoint &scrollDistance);

    void regionInvalidated(const QRegion &region, bool erase);

    void invalidated();

// KDE invents public signals :)
#undef signals
#define signals public
signals:

    /**
      * Make it possible for plugins to request
      * the embedding of an image into the current
      * document. Used e.g. by the scan-plugin
    */
    void embedImage(const QString &filename);

#undef signals
#define signals protected

protected slots:
    virtual void slotAutoScroll();
    virtual void changeAuthorProfile(const QString &profileName);

private:
    virtual void setupGlobalActions(void);
    KoViewPrivate * const d;
    int autoScrollAcceleration(int offset) const;

};

#endif
