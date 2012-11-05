/********************************************************************************
** Form generated from reading UI file 'KoEditColorSet.ui'
**
** Created: Sat Nov 3 15:21:39 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOEDITCOLORSET_H
#define UI_KOEDITCOLORSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoEditColorSet
{
public:
    QVBoxLayout *vboxLayout;
    QComboBox *selector;
    QFrame *patchesFrame;
    QHBoxLayout *hboxLayout;
    QLabel *colorName;
    QToolButton *add;
    QToolButton *remove;
    QToolButton *open;
    QToolButton *save;

    void setupUi(QWidget *KoEditColorSet)
    {
        if (KoEditColorSet->objectName().isEmpty())
            KoEditColorSet->setObjectName(QString::fromUtf8("KoEditColorSet"));
        KoEditColorSet->resize(173, 106);
        vboxLayout = new QVBoxLayout(KoEditColorSet);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        selector = new QComboBox(KoEditColorSet);
        selector->setObjectName(QString::fromUtf8("selector"));
        selector->setEditable(true);

        vboxLayout->addWidget(selector);

        patchesFrame = new QFrame(KoEditColorSet);
        patchesFrame->setObjectName(QString::fromUtf8("patchesFrame"));
        patchesFrame->setFrameShape(QFrame::NoFrame);
        patchesFrame->setFrameShadow(QFrame::Plain);

        vboxLayout->addWidget(patchesFrame);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        colorName = new QLabel(KoEditColorSet);
        colorName->setObjectName(QString::fromUtf8("colorName"));
        colorName->setFrameShape(QFrame::Box);
        colorName->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(colorName);

        add = new QToolButton(KoEditColorSet);
        add->setObjectName(QString::fromUtf8("add"));

        hboxLayout->addWidget(add);

        remove = new QToolButton(KoEditColorSet);
        remove->setObjectName(QString::fromUtf8("remove"));

        hboxLayout->addWidget(remove);

        open = new QToolButton(KoEditColorSet);
        open->setObjectName(QString::fromUtf8("open"));

        hboxLayout->addWidget(open);

        save = new QToolButton(KoEditColorSet);
        save->setObjectName(QString::fromUtf8("save"));

        hboxLayout->addWidget(save);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(KoEditColorSet);

        QMetaObject::connectSlotsByName(KoEditColorSet);
    } // setupUi

    void retranslateUi(QWidget *KoEditColorSet)
    {
#ifndef QT_NO_TOOLTIP
        add->setToolTip(QApplication::translate("KoEditColorSet", "Add", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        add->setText(QApplication::translate("KoEditColorSet", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        remove->setToolTip(QApplication::translate("KoEditColorSet", "Remove", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        remove->setText(QApplication::translate("KoEditColorSet", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        open->setToolTip(QApplication::translate("KoEditColorSet", "Open palette", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        open->setText(QApplication::translate("KoEditColorSet", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        save->setToolTip(QApplication::translate("KoEditColorSet", "Save palette", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        save->setText(QApplication::translate("KoEditColorSet", "...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoEditColorSet);
    } // retranslateUi

};

namespace Ui {
    class KoEditColorSet: public Ui_KoEditColorSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOEDITCOLORSET_H
