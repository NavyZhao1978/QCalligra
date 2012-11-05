/* This file is part of the KDE project
 * Copyright (C) 2006-2007 Jan Hambrecht <jaham@gmx.net>
 * Copyright (C) 2008-2009 Fredy Yanardi <fyanardi@gmail.com>
 * Copyright (C) 2009 Jean-Nicolas Artaud <jeannicolasartaud@gmail.com>
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

#include "KoPADocumentStructureDocker.h"
#include "KoPADocumentModel.h"
#include "KoPADocument.h"
#include "KoPAPageBase.h"
#include "KoPACanvas.h"
#include "KoPAView.h"
#include "KoPAMasterPage.h"
#include "KoPAPage.h"
#include "commands/KoPAPageInsertCommand.h"
#include "commands/KoPAPageDeleteCommand.h"

#include <KoShapeManager.h>
#include <KoShapeContainer.h>
#include <KoToolManager.h>
#include <KoCanvasBase.h>
#include <KoCanvasController.h>
#include <KoShapeBasedDocumentBase.h>
#include <KoSelection.h>
#include <KoShapeOdfSaveHelper.h>
#include <KoPAOdfPageSaveHelper.h>
#include <KoDrag.h>
#include <KoShapeCreateCommand.h>
#include <KoShapeDeleteCommand.h>
#include <KoShapeReorderCommand.h>
#include <KoShapeLayer.h>
#include <KoShapePaste.h>
#include <KoViewItemContextBar.h>

#include <KoIcon.h>

#include <QMenu>
#include <QInputDialog>
#include <QMessageBox>
#include "KoDebug.h"

#include <QGridLayout>
#include <QToolButton>
#include <QButtonGroup>
#include <QItemSelection>
#include <QApplication>
#include <QClipboard>

enum ButtonIds
{
    Button_Raise,
    Button_Lower,
    Button_Delete
};

KoPADocumentStructureDockerFactory::KoPADocumentStructureDockerFactory(KoDocumentSectionView::DisplayMode mode, KoPageApp::PageType pageType)
: m_mode(mode)
, m_pageType(pageType)
{
}

QString KoPADocumentStructureDockerFactory::id() const
{
    return QString("document section view");
}

QDockWidget* KoPADocumentStructureDockerFactory::createDockWidget()
{
    return new KoPADocumentStructureDocker(m_mode, m_pageType);
}

KoPADocumentStructureDocker::KoPADocumentStructureDocker(KoDocumentSectionView::DisplayMode mode, KoPageApp::PageType pageType, QWidget* parent)
: QDockWidget(parent)
, KoCanvasObserverBase()
, m_doc(0)
, m_model(0)
{
    setWindowTitle(QObject::tr("Document"));

    QWidget *mainWidget = new QWidget(this);
    QGridLayout* layout = new QGridLayout(mainWidget);
    layout->addWidget(m_sectionView = new KoDocumentSectionView(mainWidget), 0, 0, 1, -1);

    QToolButton *button = new QToolButton(mainWidget);
    button->setIcon(koIcon("list-add"));
    if (pageType == KoPageApp::Slide) {
        button->setToolTip(QObject::tr("Add a new slide or layer"));
    }
    else {
        button->setToolTip(QObject::tr("Add a new page or layer"));
    }
    layout->addWidget(button, 1, 0);

    QMenu *menu = new QMenu(button);
    button->setMenu(menu);
    button->setPopupMode(QToolButton::InstantPopup);
    menu->addAction(koIcon("document-new"),
                    (pageType == KoPageApp::Slide) ? QObject::tr("Slide") : QObject::tr("Page"),
                    this, SLOT(addPage()));
    m_addLayerAction = menu->addAction(koIcon("layer-new"), QObject::tr("Layer"), this, SLOT(addLayer()));

    m_buttonGroup = new QButtonGroup(mainWidget);
    m_buttonGroup->setExclusive(false);

    button = new QToolButton(mainWidget);
    button->setIcon(koIcon("list-remove"));
    button->setToolTip(QObject::tr("Delete selected objects"));
    m_buttonGroup->addButton(button, Button_Delete);
    layout->addWidget(button, 1, 1);

    button = new QToolButton(mainWidget);
    button->setIcon(koIcon("arrow-up"));
    button->setToolTip(QObject::tr("Raise selected objects"));
    m_buttonGroup->addButton(button, Button_Raise);
    layout->addWidget(button, 1, 3);

    button = new QToolButton(mainWidget);
    button->setIcon(koIcon("arrow-down"));
    button->setToolTip(QObject::tr("Lower selected objects"));
    m_buttonGroup->addButton(button, Button_Lower);
    layout->addWidget(button, 1, 4);

    button = new QToolButton(mainWidget);
    menu = new QMenu(this);
    QActionGroup *group = new QActionGroup(this);

    m_viewModeActions.insert(KoDocumentSectionView::MinimalMode,
                              menu->addAction(koIcon("view-list-text"), QObject::tr("Minimal View"), this, SLOT(minimalView())));
    m_viewModeActions.insert(KoDocumentSectionView::DetailedMode,
                              menu->addAction(koIcon("view-list-details"), QObject::tr("Detailed View"), this, SLOT(detailedView())));
    m_viewModeActions.insert(KoDocumentSectionView::ThumbnailMode,
                              menu->addAction(koIcon("view-preview"), QObject::tr("Thumbnail View"), this, SLOT(thumbnailView())));

    foreach (QAction* action, m_viewModeActions) {
        action->setCheckable(true);
        action->setActionGroup(group);
    }

    button->setMenu(menu);
    button->setPopupMode(QToolButton::InstantPopup);
    button->setIcon(koIcon("view-choose"));
    button->setText(QObject::tr("View mode"));
    layout->addWidget(button, 1, 5);

    layout->setSpacing(0);
    layout->setMargin(3);
    layout->setColumnStretch(2, 10);

    setWidget(mainWidget);

    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotButtonClicked(int)));

    m_model = new KoPADocumentModel(this);
    m_sectionView->setModel(m_model);
    m_sectionView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_sectionView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    m_sectionView->setDragDropMode(QAbstractItemView::InternalMove);

    connect(m_sectionView, SIGNAL(pressed(const QModelIndex&)), this, SLOT(itemClicked(const QModelIndex&)));
    connect(m_sectionView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
             this, SLOT (itemSelected(const QItemSelection&, const QItemSelection&)));

    connect(m_model, SIGNAL(requestPageSelection(int,int)), this, SLOT(selectPages(int,int)));
    connect(m_model, SIGNAL(modelReset()), this, SIGNAL(dockerReset()));

    //KConfigGroup configGroup = KGlobal::config()->group("KoPageApp/DocumentStructureDocker");
    //QString viewModeString = configGroup.readEntry("ViewMode", "");
	QString viewModeString = QString::fromLocal8Bit("Detailed");

    if (viewModeString.isEmpty())
        setViewMode(mode);
    else
        setViewMode(viewModeFromString(viewModeString));

    m_itemsContextBar = new KoViewItemContextBar(m_sectionView);
}

KoPADocumentStructureDocker::~KoPADocumentStructureDocker()
{
    //KConfigGroup configGroup = KGlobal::config()->group("KoPageApp/DocumentStructureDocker");
    //configGroup.writeEntry("ViewMode", viewModeToString(m_sectionView->displayMode()));
}

void KoPADocumentStructureDocker::updateView()
{
    m_model->update();
}

void KoPADocumentStructureDocker::slotButtonClicked(int buttonId)
{
    switch (buttonId)
    {
        case Button_Raise:
            raiseItem();
            break;
        case Button_Lower:
            lowerItem();
            break;
        case Button_Delete:
            deleteItem();
            break;
    }
}

void KoPADocumentStructureDocker::itemClicked(const QModelIndex &index)
{
    Q_ASSERT(index.internalPointer());

    if (!index.isValid())
        return;

    KoShape *shape = static_cast<KoShape*>(index.internalPointer());
    if (!shape)
        return;
    // check whether the newly selected shape is a page or shape/layer
    bool isPage = (dynamic_cast<KoPAPageBase *>(shape) != 0);
    KoCanvasController* canvasController = KoToolManager::instance()->activeCanvasController();
    KoSelection *selection = canvasController->canvas()->shapeManager()->selection();

    if (isPage) {
        // no shape is currently selected
        if (!m_selectedShapes.isEmpty()) {
            m_sectionView->clearSelection();
            selection->deselectAll();
            m_sectionView->setCurrentIndex(index);
            m_selectedShapes.clear();
            emit pageChanged(dynamic_cast<KoPAPageBase *>(shape));
        }
        else {
            // There are more than one page selected
            if (m_sectionView->selectionModel()->selectedIndexes().size() == 1) {
                emit pageChanged(dynamic_cast<KoPAPageBase *>(shape));
            }
        }
    }
    else {
        KoPAPageBase *newPageByShape = m_doc->pageByShape(shape);
        // there is already shape(s) selected
        if (!m_selectedShapes.isEmpty()) {
            // if the newly selected shape is not in the same page as previously
            // selected shape(s), then clear previous selection
            KoPAPageBase *currentPage = m_doc->pageByShape(m_selectedShapes.first());
            KoShapeLayer *layer = dynamic_cast<KoShapeLayer *>(shape);
            if (currentPage != newPageByShape) {
                m_sectionView->clearSelection();
                selection->deselectAll();
                m_sectionView->setCurrentIndex(index);
                m_selectedShapes.clear();
                emit pageChanged(newPageByShape);
                if (layer) {
                    selection->setActiveLayer(layer);
                }
                else {
                    selection->select(shape);
                    shape->update();
                }
            }
            else {
                QList<KoPAPageBase*> selectedPages;
                QList<KoShapeLayer*> selectedLayers;
                QList<KoShape*> selectedShapes;

                // separate selected layers and selected shapes
                extractSelectedLayersAndShapes(selectedPages, selectedLayers, selectedShapes);

                // XXX: Do stuff withthe selected pages!

                foreach (KoShape* shape, selection->selectedShapes()) {
                    shape->update();
                }
                selection->deselectAll();
                foreach (KoShape* shape, selectedShapes) {
                    if (shape) {
                        selection->select(shape);
                        shape->update();
                    }
                }
                // if we just selected a layer, check whether this layer is already active, if not
                // then make it active
                if (layer && selection->activeLayer() != layer && selectedLayers.count() <= 1) {
                    selection->setActiveLayer(layer);
                }
            }
        }
        // no shape is selected, meaning only page(s) is selected
        else {
            m_sectionView->clearSelection();
            m_sectionView->setCurrentIndex(index);
            selection->select(shape);
            shape->update();
            emit pageChanged(newPageByShape);
        }
        m_selectedShapes.append(shape);
    }
}

void KoPADocumentStructureDocker::addLayer()
{
	bool ok = true;
    QString name = QInputDialog::getText(this
		, QObject::tr("New Layer")
		, QObject::tr("Enter the name of the new layer:")
		, QLineEdit::Normal
        , QObject::tr("New layer")
		, &ok);

    if (ok) {
        KoShapeLayer* layer = new KoShapeLayer();
        KoPACanvas * canvas = dynamic_cast<KoPACanvas *>(KoToolManager::instance()->activeCanvasController()->canvas());
        if (canvas) {
            layer->setParent(canvas->koPAView()->activePage());
            layer->setName(name);
            QList<KoShape*> layers(canvas->koPAView()->activePage()->shapes());
            if (!layers.isEmpty()) {
                qSort(layers.begin(), layers.end(), KoShape::compareShapeZIndex);
                layer->setZIndex(layers.last()->zIndex() + 1);
            }
            KUndo2Command *cmd = new KoShapeCreateCommand(m_doc, layer, 0);
            cmd->setText(QObject::tr("Create Layer"));
            m_doc->addCommand(cmd);
            m_model->update();
        }
    }
}

void KoPADocumentStructureDocker::deleteItem()
{
    QList<KoPAPageBase*> selectedPages;
    QList<KoShapeLayer*> selectedLayers;
    QList<KoShape*> selectedShapes;

    // separate selected layers and selected shapes
    extractSelectedLayersAndShapes(selectedPages, selectedLayers, selectedShapes);

    KUndo2Command *cmd = 0;

    if (selectedLayers.count()) {
        if (m_doc->pages().count() > selectedPages.count()) {
            QList<KoShape*> deleteShapes;
            foreach(KoPAPageBase* page, selectedPages) {
                deleteShapes += page->shapes();
                deleteShapes.append(page);
            }
            cmd = new KoShapeDeleteCommand(m_doc, deleteShapes);
            cmd->setText(QObject::tr("Delete Layer"));
        }
        else {
            QMessageBox::critical(0, QObject::tr("Could not delete all layers. At least one layer is required."), QObject::tr("Error deleting layers"));
        }
    }
    else if (selectedShapes.count()) {
        cmd = new KoShapeDeleteCommand(m_doc, selectedShapes);
    }
    else if (!selectedPages.isEmpty() && selectedPages.count() < m_doc->pages().count()) {
        m_doc->removePages(selectedPages);
    }

    if (cmd) {
        m_doc->addCommand(cmd);
        m_model->update();
    }
}

void KoPADocumentStructureDocker::raiseItem()
{
	return;

    QList<KoPAPageBase*> selectedPages;
    QList<KoShapeLayer*> selectedLayers;
    QList<KoShape*> selectedShapes;

    // separate selected layers and selected shapes
    extractSelectedLayersAndShapes(selectedPages, selectedLayers, selectedShapes);

    KUndo2Command *cmd = 0;

    if (selectedLayers.count()) {
//         // check if all layers could be raised
//         foreach(KoShapeLayer* layer, selectedLayers)
//             if (! m_document->canRaiseLayer(layer))
//                 return;

//        cmd = new KoPALayerReorderCommand(m_document, selectedLayers, KoPALayerReorderCommand::RaiseLayer);
    }
    else if (selectedShapes.count()) {
        cmd = KoShapeReorderCommand::createCommand(selectedShapes,
                KoToolManager::instance()->activeCanvasController()->canvas()->shapeManager(),
                KoShapeReorderCommand::RaiseShape);
    }

    if (cmd) {
        m_doc->addCommand(cmd);
        m_model->update();
    }
}

void KoPADocumentStructureDocker::lowerItem()
{
	return;

    QList<KoPAPageBase*> selectedPages;
    QList<KoShapeLayer*> selectedLayers;
    QList<KoShape*> selectedShapes;

    // separate selected layers and selected shapes
    extractSelectedLayersAndShapes(selectedPages, selectedLayers, selectedShapes);

    KUndo2Command *cmd = 0;

    if (selectedLayers.count()) {
//         // check if all layers could be raised
//         foreach(KoShapeLayer* layer, selectedLayers)
//             if (! m_document->canLowerLayer(layer))
//                 return;

//        cmd = new KoPALayerReorderCommand(m_document, selectedLayers, KoPALayerReorderCommand::LowerLayer);
    }
    else if (selectedShapes.count()) {
        cmd = KoShapeReorderCommand::createCommand(selectedShapes,
                KoToolManager::instance()->activeCanvasController()->canvas()->shapeManager(),
                KoShapeReorderCommand::LowerShape);
    }

    if (cmd) {
        m_doc->addCommand(cmd);
        m_model->update();
    }
}

void KoPADocumentStructureDocker::extractSelectedLayersAndShapes(QList<KoPAPageBase*> &pages, QList<KoShapeLayer*> &layers, QList<KoShape*> &shapes)
{
	return;

    pages.clear();
    layers.clear();
    shapes.clear();

    QModelIndexList selectedItems = m_sectionView->selectionModel()->selectedIndexes();
    if (selectedItems.count() == 0)
        return;

    // TODO tz: I don't know what is best:
    // 1. only make it possible to select one type of object page, layer, shape
    // 2. don't add shapes when we already have the page/layer/group in the selection
    // separate selected layers and selected shapes
    foreach(const QModelIndex & index, selectedItems) {
        KoShape *shape = static_cast<KoShape*>(index.internalPointer());
        KoPAPageBase * page = dynamic_cast<KoPAPageBase*>(shape);
        if (page) {
            pages.append(page);
        }
        else {
            KoShapeLayer *layer = dynamic_cast<KoShapeLayer*>(shape);
            if (layer)
                layers.append(layer);
            else if (! selectedItems.contains(index.parent()))
                shapes.append(shape);
        }
    }
}

void KoPADocumentStructureDocker::setCanvas(KoCanvasBase* canvas)
{
    KoPACanvas * c = dynamic_cast<KoPACanvas*> (canvas);
    if (c) {
        m_doc = c->document();
        m_model->setDocument(m_doc);
        m_sectionView->setModel(m_model);
    }
}

void KoPADocumentStructureDocker::unsetCanvas()
{
    m_doc = 0;
    m_model->setDocument(0);
    m_sectionView->setModel(0);
}

void KoPADocumentStructureDocker::setActivePage(KoPAPageBase *page)
{
    if (m_doc) {
        int row = m_doc->pageIndex(page);
        QModelIndex index = m_model->index(row, 0);
        if (index != m_sectionView->currentIndex()
                && index != getRootIndex(m_sectionView->currentIndex())) {
            m_sectionView->setCurrentIndex(index);
        }
    }
}

void KoPADocumentStructureDocker::setMasterMode(bool master)
{
    m_model->setMasterMode(master);
}

void KoPADocumentStructureDocker::minimalView()
{
    setViewMode(KoDocumentSectionView::MinimalMode);
    m_itemsContextBar->disableContextBar();
}

void KoPADocumentStructureDocker::detailedView()
{
    setViewMode(KoDocumentSectionView::DetailedMode);
    m_itemsContextBar->disableContextBar();
}

void KoPADocumentStructureDocker::thumbnailView()
{
    setViewMode(KoDocumentSectionView::ThumbnailMode);
    m_itemsContextBar->enableContextBar();
}

void KoPADocumentStructureDocker::setViewMode(KoDocumentSectionView::DisplayMode mode)
{
    bool expandable = (mode != KoDocumentSectionView::ThumbnailMode);

    // if we switch to non-expandable mode (ThumbnailMode) and if current index
    // is not a page, we need to select the corresponding page first, otherwise
    // none of the page will be selected when we do collapse all
    if (!expandable) {
        QModelIndex currentIndex = m_sectionView->currentIndex();
        QModelIndex rootIndex = getRootIndex(currentIndex);
        if (currentIndex != rootIndex) {
            m_sectionView->setCurrentIndex(rootIndex);
        }
        m_sectionView->collapseAll();
    }

    m_sectionView->setDisplayMode(mode);
    m_sectionView->setItemsExpandable(expandable);
    m_sectionView->setRootIsDecorated(expandable);
    // m_sectionView->setSelectionMode(expandable ? QAbstractItemView::ExtendedSelection : QAbstractItemView::SingleSelection);

    m_viewModeActions[mode]->setChecked (true);
}

QModelIndex KoPADocumentStructureDocker::getRootIndex(const QModelIndex &index) const
{
    QModelIndex currentIndex;
    QModelIndex parentIndex = index.parent();
    if (!parentIndex.isValid()) {
        return index;
    }
    while (parentIndex.isValid()) {
        currentIndex = parentIndex;
        parentIndex = currentIndex.parent();
    }

    return currentIndex;
}

KoDocumentSectionView::DisplayMode KoPADocumentStructureDocker::viewModeFromString(const QString& mode)
{
    if (mode == "Minimal")
        return KoDocumentSectionView::MinimalMode;
    else if (mode == "Detailed")
        return KoDocumentSectionView::DetailedMode;
    else if (mode == "Thumbnail")
        return KoDocumentSectionView::ThumbnailMode;

    return KoDocumentSectionView::DetailedMode;
}

QString KoPADocumentStructureDocker::viewModeToString(KoDocumentSectionView::DisplayMode mode)
{
    switch (mode)
    {
        case KoDocumentSectionView::MinimalMode:
            return QString("Minimal");
            break;
        case KoDocumentSectionView::DetailedMode:
            return QString("Detailed");
            break;
        case KoDocumentSectionView::ThumbnailMode:
            return QString("Thumbnail");
            break;
    }

    return QString();
}

void KoPADocumentStructureDocker::itemSelected(const QItemSelection& selected, const QItemSelection& deselected)
{
	return;

    Q_UNUSED(deselected);

    if (selected.indexes().isEmpty()) {
        m_buttonGroup->button(Button_Raise)->setEnabled(false);
        m_buttonGroup->button(Button_Lower)->setEnabled(false);
        m_addLayerAction->setEnabled(false);
    }
    else {
        m_buttonGroup->button(Button_Raise)->setEnabled(true);
        m_buttonGroup->button(Button_Lower)->setEnabled(true);
        m_addLayerAction->setEnabled(true);
    }

    if (!m_sectionView->selectionModel()->selectedIndexes().empty() &&
            m_sectionView->selectionModel()->selectedIndexes().count() < m_doc->pages().count()) {
        m_buttonGroup->button(Button_Delete)->setEnabled(true);
    }
    else {
        m_buttonGroup->button(Button_Delete)->setEnabled(false);
    }
}

void KoPADocumentStructureDocker::addPage()
{
    KoPACanvas * canvas = dynamic_cast<KoPACanvas *>(KoToolManager::instance()->activeCanvasController()->canvas());
    if (canvas) {
        canvas->koPAView()->insertPage();
    }
}

void KoPADocumentStructureDocker::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu menu(this);

    // Not connected yet
    if (m_doc->pageType() == KoPageApp::Slide) {
        menu.addAction(koIcon("document-new"), QObject::tr("Add a new slide"), this, SLOT(addPage()));
    }
    else {
        menu.addAction(koIcon("document-new"), QObject::tr("Add a new page"), this, SLOT(addPage()));
    }
    menu.addAction(koIcon("edit-delete"), QObject::tr("Delete selected objects"), this, SLOT(deleteItem()));
    menu.addSeparator();
    menu.addAction(koIcon("edit-cut"), QObject::tr("Cut"), this, SLOT(editCut()));
    menu.addAction(koIcon("edit-copy"), QObject::tr("Copy"), this, SLOT(editCopy()));
    menu.addAction(koIcon("edit-paste"), QObject::tr("Paste"), this, SLOT(editPaste()));

    menu.exec(event->globalPos());
}

void KoPADocumentStructureDocker::editCut()
{
    editCopy();
    deleteItem();
}

void KoPADocumentStructureDocker::editCopy()
{
    QList<KoPAPageBase*> pages;
    QList<KoShapeLayer*> layers;
    QList<KoShape*> shapes;

    // separate selected layers and selected shapes
    extractSelectedLayersAndShapes(pages, layers, shapes);

    foreach (KoShape* shape, layers) {
        // Add layers to shapes
        shapes.append(shape);
    }

    if (!shapes.empty()) {
        // Copy Shapes or Layers
        KoShapeOdfSaveHelper saveHelper(shapes);
        KoDrag drag;
        drag.setOdf(KoOdf::mimeType(KoOdf::Text), saveHelper);
        drag.addToClipboard();
        return;
    }

    if (!pages.empty()) {
        // Copy Pages
        KoPAOdfPageSaveHelper saveHelper(m_doc, pages);
        KoDrag drag;
        drag.setOdf(KoOdf::mimeType(m_doc->documentType()), saveHelper);
        drag.addToClipboard();
    }
}

void KoPADocumentStructureDocker::editPaste()
{
    const QMimeData * data = QApplication::clipboard()->mimeData();

    if (data->hasFormat(KoOdf::mimeType(KoOdf::Text))) {
        // Paste Shapes or Layers
        KoCanvasBase* canvas = KoToolManager::instance()->activeCanvasController()->canvas();
        KoShapeManager * shapeManager = canvas->shapeManager();
        KoShapePaste paste(canvas, shapeManager->selection()->activeLayer());
        paste.paste(KoOdf::Text, data);

    }
    else {
        // Paste Pages
        KoPACanvas * canvas = dynamic_cast<KoPACanvas *>(KoToolManager::instance()->activeCanvasController()->canvas());
        canvas->koPAView()->pagePaste();
    }
}

void KoPADocumentStructureDocker::selectPages(int start, int count)
{
    if ((start < 0) || (count < 1)) {
        return;
    }
    emit pageChanged(m_doc->pageByIndex(start, false));
    m_sectionView->clearSelection();
    for (int i = start; i < (start + count); i++) {
        QModelIndex index = m_model->index(i, 0, QModelIndex());
        if (index.isValid()) {
            m_sectionView->selectionModel()->select(index, QItemSelectionModel::Select);
        }
    }
}
//#include <KoPADocumentStructureDocker.moc>

// kate: replace-tabs on; space-indent on; indent-width 4; mixedindent off; indent-mode cstyle;
