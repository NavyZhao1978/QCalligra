/* This file is part of the KDE project
   Copyright (c) 2000 Simon Hausmann <hausmann@kde.org>
                 2006 Martin Pfeiffer <hubipete@gmx.net>
                 2012 C. Boemann <cbo@boemann.dk>

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

#include "KoConfigAuthorPage.h"

#include "ui_KoConfigAuthorPage.h"

#include <KoGlobal.h>
#include <KoIcon.h>

#include <QLineEdit>
#include <QStackedWidget>
#include <QList>
#include <QComboBox>
#include <QGridLayout>
#include <QString>
#include <QStringList>
#include <QToolButton>
#include <QInputDialog>

class KoConfigAuthorPage::Private
{
public:
    QList<Ui::KoConfigAuthorPage *> profileUiList;
    QStackedWidget *stack;
    QComboBox *combo;
    QToolButton *deleteUser;
};


KoConfigAuthorPage::KoConfigAuthorPage()
        : d(new Private)
{
    QGridLayout *layout = new QGridLayout;

    d->combo = new QComboBox;
    layout->addWidget(d->combo, 0, 0);
    QToolButton *newUser = new QToolButton;
    newUser->setIcon(koIcon("list-add-user"));
    newUser->setToolTip(QObject::tr("Add new author profile (starts out as a copy of current)"));
    layout->addWidget(newUser, 0, 1);
    d->deleteUser = new QToolButton;
    d->deleteUser->setIcon(koIcon("list-remove-user"));
    d->deleteUser->setToolTip(QObject::tr("Delete the author profile"));
    layout->addWidget(d->deleteUser, 0, 2);
    QFrame *f = new QFrame;
    f->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    layout->addWidget(f, 1, 0);
    d->stack = new QStackedWidget();
    layout->addWidget(d->stack, 2, 0, 1, 3);
    setLayout(layout);

    // Add a default profile
    Ui::KoConfigAuthorPage *aUi = new Ui::KoConfigAuthorPage();
    QWidget *w = new QWidget;
    w->setEnabled(false);
    aUi->setupUi(w);
    d->combo->addItem(QObject::tr("Default Author Profile"));
    d->stack->addWidget(w);
    //KUser user(KUser::UseRealUserID);
    //aUi->leFullName->setText(user.property(KUser::FullName).toString());
    d->profileUiList.append(aUi);

    // Add all the user defined profiles
    //KConfig *config = KoGlobal::calligraConfig();
    //KConfigGroup authorGroup(config, "Author");
	QSettings authorGroup("QCalligra", "MainApp");
	authorGroup.beginGroup("Author");
    QStringList profiles = authorGroup.value("profile-names").toStringList();
	authorGroup.endGroup();

    foreach (const QString &profile , profiles) {
        //KConfigGroup cgs(&authorGroup, "Author-" + profile);
		authorGroup.beginGroup("Author" + profile);
        aUi = new Ui::KoConfigAuthorPage();
        w = new QWidget;
        aUi->setupUi(w);
        aUi->leFullName->setText(authorGroup.value("creator", "").toString());
        aUi->leInitials->setText(authorGroup.value("initial", "").toString());
        aUi->leTitle->setText(authorGroup.value("author-title", "").toString());
        aUi->leCompany->setText(authorGroup.value("company", "").toString());
        aUi->leEmail->setText(authorGroup.value("email", "").toString());
        aUi->lePhoneWork->setText(authorGroup.value("telephone-work", "").toString());
        aUi->lePhoneHome->setText(authorGroup.value("telephone", "").toString());
        aUi->leFax->setText(authorGroup.value("fax", "").toString());
        aUi->leCountry->setText(authorGroup.value("country", "").toString());
        aUi->lePostal->setText(authorGroup.value("postal-code", "").toString());
        aUi->leCity->setText(authorGroup.value("city", "").toString());
        aUi->leStreet->setText(authorGroup.value("street", "").toString());
        aUi->lePosition->setText(authorGroup.value("position", "").toString());
		authorGroup.endGroup();

        d->combo->addItem(profile);
        d->profileUiList.append(aUi);
        d->stack->addWidget(w);
    }

    // Connect slots
    connect(d->combo, SIGNAL(currentIndexChanged(int)), this, SLOT(profileChanged(int)));
    connect(newUser, SIGNAL(clicked(bool)), this, SLOT(addUser()));
    connect(d->deleteUser, SIGNAL(clicked(bool)), this, SLOT(deleteUser()));
    profileChanged(0);
}

KoConfigAuthorPage::~KoConfigAuthorPage()
{
    delete d;
}

void KoConfigAuthorPage::profileChanged(int i)
{
    d->stack->setCurrentIndex(i);
    d->deleteUser->setEnabled(i != 0);
}

void KoConfigAuthorPage::addUser()
{
    bool ok;
    QString profileName = QInputDialog::getText(this, QObject::tr("Name of Profile"), QObject::tr("Name (not duplicate or blank name):"),QLineEdit::Normal, "", &ok);

    if (!ok) {
        return;
    }

    Ui::KoConfigAuthorPage *curUi = d->profileUiList[d->combo->currentIndex()];
    Ui::KoConfigAuthorPage *aUi = new Ui::KoConfigAuthorPage();
    QWidget *w = new QWidget;
    aUi->setupUi(w);

    aUi->leFullName->setText(curUi->leFullName->text());
    aUi->leInitials->setText(curUi->leInitials->text());
    aUi->leTitle->setText(curUi->leTitle->text());
    aUi->leCompany->setText(curUi->leCompany->text());
    aUi->leEmail->setText(curUi->leEmail->text());
    aUi->lePhoneWork->setText(curUi->lePhoneWork->text());
    aUi->lePhoneHome->setText(curUi->lePhoneHome->text());
    aUi->leFax->setText(curUi->leFax->text());
    aUi->leCountry->setText(curUi->leCountry->text());
    aUi->lePostal->setText(curUi->lePostal->text());
    aUi->leCity->setText(curUi->leCity->text());
    aUi->leStreet->setText(curUi->leStreet->text());
    aUi->lePosition->setText(curUi->lePosition->text());

    int index = d->combo->currentIndex() + 1;
    d->combo->insertItem(index, profileName);
    d->profileUiList.insert(index, aUi);
    d->stack->insertWidget(index, w);
    d->combo->setCurrentIndex(index);
}

void KoConfigAuthorPage::deleteUser()
{
    int index = d->combo->currentIndex();
    QWidget *w = d->stack->currentWidget();

    d->stack->removeWidget(w);
    d->profileUiList.removeAt(index);
    d->combo->removeItem(index);
    delete w;
}

void KoConfigAuthorPage::apply()
{
    //KConfig *config = KoGlobal::calligraConfig();
    //KConfigGroup authorGroup(config, "Author");
	QSettings authorGroup("QCalligra", "MainApp");
	authorGroup.beginGroup("Author");
    QStringList profiles;

    for (int i = 1; i < d->profileUiList.size(); i++) {
        //KConfigGroup cgs(&authorGroup, "Author-" + d->combo->itemText(i));
		authorGroup.beginGroup("Author-" + d->combo->itemText(i));
        profiles.append(d->combo->itemText(i));
        Ui::KoConfigAuthorPage *aUi = d->profileUiList[i];
        authorGroup.setValue("creator", aUi->leFullName->text());
        authorGroup.setValue("initial", aUi->leInitials->text());
        authorGroup.setValue("author-title", aUi->leTitle->text());
        authorGroup.setValue("company", aUi->leCompany->text());
        authorGroup.setValue("email", aUi->leEmail->text());
        authorGroup.setValue("telephone-work", aUi->lePhoneWork->text());
        authorGroup.setValue("telephone", aUi->lePhoneHome->text());
        authorGroup.setValue("fax", aUi->leFax->text());
        authorGroup.setValue("country", aUi->leCountry->text());
        authorGroup.setValue("postal-code", aUi->lePostal->text());
        authorGroup.setValue("city", aUi->leCity->text());
        authorGroup.setValue("street", aUi->leStreet->text());
        authorGroup.setValue("position", aUi->lePosition->text());
		authorGroup.endGroup();

        //cgs.sync();
    }
    authorGroup.setValue("profile-names", profiles);
    authorGroup.sync();
}


//#include <KoConfigAuthorPage.moc>
