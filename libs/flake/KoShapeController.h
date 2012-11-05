/* This file is part of the KDE project
 *
 * Copyright (C) 2006-2007, 2010 Thomas Zander <zander@kde.org>
 * Copyright (C) 2006-2008 Thorsten Zachmann <zachmann@kde.org>
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

#ifndef KOTABDIALOG_H
#define KOTABDIALOG_H

#include "flake_export.h"

#include <QtCore>
#include <QtGui>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class  QTabBar;
class  QTab;
class  KoTabDialogPrivate;

class FLAKE_EXPORT KoTabDialog : public QDialog
{
    Q_OBJECT
public:
    KoTabDialog(QWidget* parent=0, const char* name=0, bool modal=false, Qt::WindowFlags f=0);
    ~KoTabDialog();

    void show();
    void setFont(const QFont & font);

    void addTab(QWidget *, const QString &);
    void addTab(QWidget *child, const QIcon& iconset, const QString &label);

    void insertTab(QWidget *, const QString &, int index = -1);
    void insertTab(QWidget *child, const QIcon& iconset, const QString &label, int index = -1);

    void changeTab(QWidget *, const QString &);
    void changeTab(QWidget *child, const QIcon& iconset, const QString &label);

    bool isTabEnabled( QWidget *) const;
    void setTabEnabled(QWidget *, bool);
    bool isTabEnabled(const char*) const; // compatibility
    void setTabEnabled(const char*, bool); // compatibility

    void showPage(QWidget *);
    void removePage(QWidget *);
    QString tabLabel(QWidget *);

    QWidget * currentPage() const;

    void setDefaultButton(const QString &text);
    void setDefaultButton();
    bool hasDefaultButton() const;

    void setHelpButton(const QString &text);
    void setHelpButton();
    bool hasHelpButton() const;

    void setCancelButton(const QString &text);
    void setCancelButton();
    bool hasCancelButton() const;

    void setApplyButton(const QString &text);
    void setApplyButton();
    bool hasApplyButton() const;

#ifndef qdoc
    void setOKButton(const QString &text = QString());
#endif
    void setOkButton(const QString &text);
    void setOkButton();
    bool hasOkButton() const;

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);
    void styleChange(QStyle&);
    //void setTabBar(QTabBar*);
    //QTabBar* tabBar() const;

Q_SIGNALS:
    void aboutToShow();

    void applyButtonPressed();
    void cancelButtonPressed();
    void defaultButtonPressed();
    void helpButtonPressed();

    void currentChanged(QWidget *);
    void selected(const QString&); // obsolete

private:
    void setSizes();
    void setUpLayout();

    KoTabDialogPrivate *d;

    Q_DISABLE_COPY(KoTabDialog)
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // KOTABDIALOG_H













#ifndef KOSHAPECONTROLLER_H
#define KOSHAPECONTROLLER_H

#include "flake_export.h"

#include <QList>
#include <QMetaType>

class KoCanvasBase;
class KoShape;
class KoShapeBasedDocumentBase;
class KUndo2Command;
class KoDocumentResourceManager;

/**
 * Class used by tools to maintain the list of shapes.
 * All applications have some sort of list of all shapes that belong to the document.
 * The applications implement the KoShapeBasedDocumentBase interface (all pure virtuals)
 * to add and remove shapes from the document. To ensure that an application can expect
 * a certain protocol to be adhered to when adding/removing shapes, all tools use the API
 * from this class for maintaining the list of shapes in the document. So no tool gets
 * to access the application directly.
 */
class FLAKE_EXPORT KoShapeController
{
public:
    /**
     * Create a new Controller; typically not called by applications, only
     * by the KonCanvasBase constructor.
     * @param canvas the canvas this controller works for. The canvas can be 0
     * @param shapeController the application provided shapeBasedDocument that we can call.
     */
    KoShapeController(KoCanvasBase *canvas, KoShapeBasedDocumentBase *shapeBasedDocument);
    /// destructor
    ~KoShapeController();

    /**
     * @brief Add a shape to the document.
     * If the shape has no parent, the active layer will become its parent.
     *
     * @param shape to add to the document
     * @param parent the parent command if the resulting command is a compound undo command.
     *
     * @return command which will insert the shape into the document or 0 if the
     *         insertion was cancelled. The command is not yet executed.
     */
    KUndo2Command* addShape(KoShape *shape, KUndo2Command *parent = 0);

    /**
     * @brief Add a shape to the document, skipping any dialogs or other user interaction.
     *
     * @param shape to add to the document
     * @param parent the parent command if the resulting command is a compound undo command.
     *
     * @return command which will insert the shape into the document. The command is not yet executed.
     */
    KUndo2Command* addShapeDirect(KoShape *shape, KUndo2Command *parent = 0);

    /**
     * @brief Remove a shape from the document.
     *
     * @param shape to remove from the document
     * @param parent the parent command if the resulting command is a compound undo command.
     *
     * @return command which will remove the shape from the document.
     *         The command is not yet executed.
     */
    KUndo2Command* removeShape(KoShape *shape, KUndo2Command *parent = 0);

    /**
     * Remove a shape from the document.
     *
     * @param shapes the set of shapes to remove from the document
     * @param parent the parent command if the resulting command is a compound undo command.
     *
     * @return command which will remove the shape from the document.
     *         The command is not yet executed.
     */
    KUndo2Command* removeShapes(const QList<KoShape*> &shapes, KUndo2Command *parent = 0);

    /**
     * @brief Set the KoShapeBasedDocumentBase used to add/remove shapes.
     *
     * NOTE: only Tables uses this method. Do not use it in your application. Tables
     * has to also call:
     * <code>KoToolManager::instance()->updateShapeControllerBase(shapeBasedDocument, canvas->canvasController());</code>
     *
     * @param shapeBasedDocument the new shapeBasedDocument.
     */
    void setShapeControllerBase(KoShapeBasedDocumentBase *shapeBasedDocument);

    /**
     * Return a pointer to the resource manager associated with the
     * shape-set (typically a document). The resource manager contains
     * document wide resources * such as variable managers, the image
     * collection and others.
     */
    KoDocumentResourceManager *resourceManager() const;

private:
    class Private;
    Private * const d;
};

Q_DECLARE_METATYPE(KoShapeController *)

#endif
