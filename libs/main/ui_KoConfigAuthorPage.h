/********************************************************************************
** Form generated from reading UI file 'KoConfigAuthorPage.ui'
**
** Created: Sat Nov 3 15:25:51 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOCONFIGAUTHORPAGE_H
#define UI_KOCONFIGAUTHORPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoConfigAuthorPage
{
public:
    QGridLayout *gridLayout;
    QLabel *fullNameLabel;
    QLineEdit *leFullName;
    QLabel *lblInitialsDesc;
    QLineEdit *leInitials;
    QLabel *lblTitleDesc;
    QLineEdit *leTitle;
    QLabel *lblPositionDesc;
    QLineEdit *lePosition;
    QLabel *lblCompanyDesc;
    QLineEdit *leCompany;
    QLabel *lblEmailDesc;
    QLineEdit *leEmail;
    QLabel *lblPhoneHome;
    QLineEdit *lePhoneHome;
    QLabel *lblPhoneWork;
    QLineEdit *lePhoneWork;
    QLabel *lblFaxDesc;
    QLineEdit *leFax;
    QLabel *lblStreetDesc;
    QLineEdit *leStreet;
    QLabel *lblPostalDesc;
    QLineEdit *lePostal;
    QLabel *lblCityDesc;
    QLineEdit *leCity;
    QLabel *lblCountryDesc;
    QLineEdit *leCountry;
    QSpacerItem *spacerItem;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *KoConfigAuthorPage)
    {
        if (KoConfigAuthorPage->objectName().isEmpty())
            KoConfigAuthorPage->setObjectName(QString::fromUtf8("KoConfigAuthorPage"));
        KoConfigAuthorPage->resize(462, 386);
        gridLayout = new QGridLayout(KoConfigAuthorPage);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fullNameLabel = new QLabel(KoConfigAuthorPage);
        fullNameLabel->setObjectName(QString::fromUtf8("fullNameLabel"));
        fullNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(fullNameLabel, 0, 1, 1, 1);

        leFullName = new QLineEdit(KoConfigAuthorPage);
        leFullName->setObjectName(QString::fromUtf8("leFullName"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leFullName->sizePolicy().hasHeightForWidth());
        leFullName->setSizePolicy(sizePolicy);

        gridLayout->addWidget(leFullName, 0, 2, 1, 1);

        lblInitialsDesc = new QLabel(KoConfigAuthorPage);
        lblInitialsDesc->setObjectName(QString::fromUtf8("lblInitialsDesc"));
        lblInitialsDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblInitialsDesc, 1, 0, 1, 2);

        leInitials = new QLineEdit(KoConfigAuthorPage);
        leInitials->setObjectName(QString::fromUtf8("leInitials"));
        sizePolicy.setHeightForWidth(leInitials->sizePolicy().hasHeightForWidth());
        leInitials->setSizePolicy(sizePolicy);

        gridLayout->addWidget(leInitials, 1, 2, 1, 1);

        lblTitleDesc = new QLabel(KoConfigAuthorPage);
        lblTitleDesc->setObjectName(QString::fromUtf8("lblTitleDesc"));
        lblTitleDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblTitleDesc, 2, 0, 1, 2);

        leTitle = new QLineEdit(KoConfigAuthorPage);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));

        gridLayout->addWidget(leTitle, 2, 2, 1, 1);

        lblPositionDesc = new QLabel(KoConfigAuthorPage);
        lblPositionDesc->setObjectName(QString::fromUtf8("lblPositionDesc"));
        lblPositionDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPositionDesc, 3, 0, 1, 2);

        lePosition = new QLineEdit(KoConfigAuthorPage);
        lePosition->setObjectName(QString::fromUtf8("lePosition"));

        gridLayout->addWidget(lePosition, 3, 2, 1, 1);

        lblCompanyDesc = new QLabel(KoConfigAuthorPage);
        lblCompanyDesc->setObjectName(QString::fromUtf8("lblCompanyDesc"));
        lblCompanyDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCompanyDesc, 4, 0, 1, 2);

        leCompany = new QLineEdit(KoConfigAuthorPage);
        leCompany->setObjectName(QString::fromUtf8("leCompany"));

        gridLayout->addWidget(leCompany, 4, 2, 1, 1);

        lblEmailDesc = new QLabel(KoConfigAuthorPage);
        lblEmailDesc->setObjectName(QString::fromUtf8("lblEmailDesc"));
        lblEmailDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblEmailDesc, 5, 0, 1, 2);

        leEmail = new QLineEdit(KoConfigAuthorPage);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 5, 2, 1, 1);

        lblPhoneHome = new QLabel(KoConfigAuthorPage);
        lblPhoneHome->setObjectName(QString::fromUtf8("lblPhoneHome"));
        lblPhoneHome->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPhoneHome, 6, 0, 1, 2);

        lePhoneHome = new QLineEdit(KoConfigAuthorPage);
        lePhoneHome->setObjectName(QString::fromUtf8("lePhoneHome"));

        gridLayout->addWidget(lePhoneHome, 6, 2, 1, 1);

        lblPhoneWork = new QLabel(KoConfigAuthorPage);
        lblPhoneWork->setObjectName(QString::fromUtf8("lblPhoneWork"));
        lblPhoneWork->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPhoneWork, 7, 0, 1, 2);

        lePhoneWork = new QLineEdit(KoConfigAuthorPage);
        lePhoneWork->setObjectName(QString::fromUtf8("lePhoneWork"));

        gridLayout->addWidget(lePhoneWork, 7, 2, 1, 1);

        lblFaxDesc = new QLabel(KoConfigAuthorPage);
        lblFaxDesc->setObjectName(QString::fromUtf8("lblFaxDesc"));
        lblFaxDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblFaxDesc, 8, 0, 1, 2);

        leFax = new QLineEdit(KoConfigAuthorPage);
        leFax->setObjectName(QString::fromUtf8("leFax"));

        gridLayout->addWidget(leFax, 8, 2, 1, 1);

        lblStreetDesc = new QLabel(KoConfigAuthorPage);
        lblStreetDesc->setObjectName(QString::fromUtf8("lblStreetDesc"));
        lblStreetDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblStreetDesc, 9, 0, 1, 2);

        leStreet = new QLineEdit(KoConfigAuthorPage);
        leStreet->setObjectName(QString::fromUtf8("leStreet"));

        gridLayout->addWidget(leStreet, 9, 2, 1, 1);

        lblPostalDesc = new QLabel(KoConfigAuthorPage);
        lblPostalDesc->setObjectName(QString::fromUtf8("lblPostalDesc"));
        lblPostalDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPostalDesc, 10, 0, 1, 2);

        lePostal = new QLineEdit(KoConfigAuthorPage);
        lePostal->setObjectName(QString::fromUtf8("lePostal"));

        gridLayout->addWidget(lePostal, 10, 2, 1, 1);

        lblCityDesc = new QLabel(KoConfigAuthorPage);
        lblCityDesc->setObjectName(QString::fromUtf8("lblCityDesc"));
        lblCityDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCityDesc, 11, 0, 1, 2);

        leCity = new QLineEdit(KoConfigAuthorPage);
        leCity->setObjectName(QString::fromUtf8("leCity"));

        gridLayout->addWidget(leCity, 11, 2, 1, 1);

        lblCountryDesc = new QLabel(KoConfigAuthorPage);
        lblCountryDesc->setObjectName(QString::fromUtf8("lblCountryDesc"));
        lblCountryDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCountryDesc, 12, 0, 1, 2);

        leCountry = new QLineEdit(KoConfigAuthorPage);
        leCountry->setObjectName(QString::fromUtf8("leCountry"));

        gridLayout->addWidget(leCountry, 12, 2, 1, 1);

        spacerItem = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 14, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 13, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        lblInitialsDesc->setBuddy(leInitials);
        lblTitleDesc->setBuddy(leTitle);
        lblPositionDesc->setBuddy(lePosition);
        lblCompanyDesc->setBuddy(leCompany);
        lblEmailDesc->setBuddy(leEmail);
        lblPhoneHome->setBuddy(lePhoneHome);
        lblPhoneWork->setBuddy(lePhoneWork);
        lblFaxDesc->setBuddy(leFax);
        lblStreetDesc->setBuddy(leStreet);
        lblPostalDesc->setBuddy(lePostal);
        lblCityDesc->setBuddy(leCity);
        lblCountryDesc->setBuddy(leCountry);
#endif // QT_NO_SHORTCUT

        retranslateUi(KoConfigAuthorPage);

        QMetaObject::connectSlotsByName(KoConfigAuthorPage);
    } // setupUi

    void retranslateUi(QWidget *KoConfigAuthorPage)
    {
        fullNameLabel->setText(QApplication::translate("KoConfigAuthorPage", "Name:", 0, QApplication::UnicodeUTF8));
        lblInitialsDesc->setText(QApplication::translate("KoConfigAuthorPage", "Initials:", 0, QApplication::UnicodeUTF8));
        lblTitleDesc->setText(QApplication::translate("KoConfigAuthorPage", "Title:", 0, QApplication::UnicodeUTF8));
        lblPositionDesc->setText(QApplication::translate("KoConfigAuthorPage", "Position:", 0, QApplication::UnicodeUTF8));
        lblCompanyDesc->setText(QApplication::translate("KoConfigAuthorPage", "Company:", 0, QApplication::UnicodeUTF8));
        lblEmailDesc->setText(QApplication::translate("KoConfigAuthorPage", "Email:", 0, QApplication::UnicodeUTF8));
        lblPhoneHome->setText(QApplication::translate("KoConfigAuthorPage", "Telephone (home):", 0, QApplication::UnicodeUTF8));
        lblPhoneWork->setText(QApplication::translate("KoConfigAuthorPage", "Telephone (work):", 0, QApplication::UnicodeUTF8));
        lblFaxDesc->setText(QApplication::translate("KoConfigAuthorPage", "Fax:", 0, QApplication::UnicodeUTF8));
        lblStreetDesc->setText(QApplication::translate("KoConfigAuthorPage", "Street:", 0, QApplication::UnicodeUTF8));
        lblPostalDesc->setText(QApplication::translate("KoConfigAuthorPage", "Postal code:", 0, QApplication::UnicodeUTF8));
        lblCityDesc->setText(QApplication::translate("KoConfigAuthorPage", "City:", 0, QApplication::UnicodeUTF8));
        lblCountryDesc->setText(QApplication::translate("KoConfigAuthorPage", "Country:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(KoConfigAuthorPage);
    } // retranslateUi

};

namespace Ui {
    class KoConfigAuthorPage: public Ui_KoConfigAuthorPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOCONFIGAUTHORPAGE_H
