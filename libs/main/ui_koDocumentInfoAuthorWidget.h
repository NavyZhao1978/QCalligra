/********************************************************************************
** Form generated from reading UI file 'koDocumentInfoAuthorWidget.ui'
**
** Created: Sat Nov 3 15:25:50 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KODOCUMENTINFOAUTHORWIDGET_H
#define UI_KODOCUMENTINFOAUTHORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KoDocumentInfoAuthorWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *fullNameLabel;
    QLabel *fullName;
    QLabel *lblInitialsDesc;
    QLabel *initials;
    QLabel *lblTitleDesc;
    QLabel *title;
    QLabel *lblPositionDesc;
    QLabel *position;
    QLabel *lblCompanyDesc;
    QLabel *lblEmailDesc;
    QLabel *lblPhoneHome;
    QLabel *lblPhoneWork;
    QLabel *lblFaxDesc;
    QLabel *lblStreetDesc;
    QLabel *lblPostalDesc;
    QLabel *lblCityDesc;
    QLabel *lblCountryDesc;
    QSpacerItem *spacerItem;
    QLabel *company;
    QLabel *email;
    QLabel *phoneHome;
    QLabel *phoneWork;
    QLabel *fax;
    QLabel *street;
    QLabel *postal;
    QLabel *city;
    QLabel *country;

    void setupUi(QWidget *KoDocumentInfoAuthorWidget)
    {
        if (KoDocumentInfoAuthorWidget->objectName().isEmpty())
            KoDocumentInfoAuthorWidget->setObjectName(QString::fromUtf8("KoDocumentInfoAuthorWidget"));
        KoDocumentInfoAuthorWidget->resize(450, 307);
        gridLayout = new QGridLayout(KoDocumentInfoAuthorWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(8);
        fullNameLabel = new QLabel(KoDocumentInfoAuthorWidget);
        fullNameLabel->setObjectName(QString::fromUtf8("fullNameLabel"));
        fullNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(fullNameLabel, 0, 0, 1, 1);

        fullName = new QLabel(KoDocumentInfoAuthorWidget);
        fullName->setObjectName(QString::fromUtf8("fullName"));

        gridLayout->addWidget(fullName, 0, 2, 1, 1);

        lblInitialsDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblInitialsDesc->setObjectName(QString::fromUtf8("lblInitialsDesc"));
        lblInitialsDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblInitialsDesc, 1, 0, 1, 1);

        initials = new QLabel(KoDocumentInfoAuthorWidget);
        initials->setObjectName(QString::fromUtf8("initials"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(initials->sizePolicy().hasHeightForWidth());
        initials->setSizePolicy(sizePolicy);

        gridLayout->addWidget(initials, 1, 2, 1, 1);

        lblTitleDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblTitleDesc->setObjectName(QString::fromUtf8("lblTitleDesc"));
        lblTitleDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblTitleDesc, 2, 0, 1, 1);

        title = new QLabel(KoDocumentInfoAuthorWidget);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout->addWidget(title, 2, 2, 1, 1);

        lblPositionDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblPositionDesc->setObjectName(QString::fromUtf8("lblPositionDesc"));
        lblPositionDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPositionDesc, 3, 0, 1, 1);

        position = new QLabel(KoDocumentInfoAuthorWidget);
        position->setObjectName(QString::fromUtf8("position"));

        gridLayout->addWidget(position, 3, 2, 1, 1);

        lblCompanyDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblCompanyDesc->setObjectName(QString::fromUtf8("lblCompanyDesc"));
        lblCompanyDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCompanyDesc, 4, 0, 1, 1);

        lblEmailDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblEmailDesc->setObjectName(QString::fromUtf8("lblEmailDesc"));
        lblEmailDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblEmailDesc, 5, 0, 1, 1);

        lblPhoneHome = new QLabel(KoDocumentInfoAuthorWidget);
        lblPhoneHome->setObjectName(QString::fromUtf8("lblPhoneHome"));
        lblPhoneHome->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPhoneHome, 6, 0, 1, 1);

        lblPhoneWork = new QLabel(KoDocumentInfoAuthorWidget);
        lblPhoneWork->setObjectName(QString::fromUtf8("lblPhoneWork"));
        lblPhoneWork->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPhoneWork, 7, 0, 1, 1);

        lblFaxDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblFaxDesc->setObjectName(QString::fromUtf8("lblFaxDesc"));
        lblFaxDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblFaxDesc, 8, 0, 1, 1);

        lblStreetDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblStreetDesc->setObjectName(QString::fromUtf8("lblStreetDesc"));
        lblStreetDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblStreetDesc, 9, 0, 1, 1);

        lblPostalDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblPostalDesc->setObjectName(QString::fromUtf8("lblPostalDesc"));
        lblPostalDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPostalDesc, 10, 0, 1, 1);

        lblCityDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblCityDesc->setObjectName(QString::fromUtf8("lblCityDesc"));
        lblCityDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCityDesc, 11, 0, 1, 1);

        lblCountryDesc = new QLabel(KoDocumentInfoAuthorWidget);
        lblCountryDesc->setObjectName(QString::fromUtf8("lblCountryDesc"));
        lblCountryDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCountryDesc, 12, 0, 1, 1);

        spacerItem = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 13, 2, 1, 1);

        company = new QLabel(KoDocumentInfoAuthorWidget);
        company->setObjectName(QString::fromUtf8("company"));

        gridLayout->addWidget(company, 4, 2, 1, 1);

        email = new QLabel(KoDocumentInfoAuthorWidget);
        email->setObjectName(QString::fromUtf8("email"));

        gridLayout->addWidget(email, 5, 2, 1, 1);

        phoneHome = new QLabel(KoDocumentInfoAuthorWidget);
        phoneHome->setObjectName(QString::fromUtf8("phoneHome"));

        gridLayout->addWidget(phoneHome, 6, 2, 1, 1);

        phoneWork = new QLabel(KoDocumentInfoAuthorWidget);
        phoneWork->setObjectName(QString::fromUtf8("phoneWork"));

        gridLayout->addWidget(phoneWork, 7, 2, 1, 1);

        fax = new QLabel(KoDocumentInfoAuthorWidget);
        fax->setObjectName(QString::fromUtf8("fax"));

        gridLayout->addWidget(fax, 8, 2, 1, 1);

        street = new QLabel(KoDocumentInfoAuthorWidget);
        street->setObjectName(QString::fromUtf8("street"));

        gridLayout->addWidget(street, 9, 2, 1, 1);

        postal = new QLabel(KoDocumentInfoAuthorWidget);
        postal->setObjectName(QString::fromUtf8("postal"));

        gridLayout->addWidget(postal, 10, 2, 1, 1);

        city = new QLabel(KoDocumentInfoAuthorWidget);
        city->setObjectName(QString::fromUtf8("city"));

        gridLayout->addWidget(city, 11, 2, 1, 1);

        country = new QLabel(KoDocumentInfoAuthorWidget);
        country->setObjectName(QString::fromUtf8("country"));

        gridLayout->addWidget(country, 12, 2, 1, 1);


        retranslateUi(KoDocumentInfoAuthorWidget);

        QMetaObject::connectSlotsByName(KoDocumentInfoAuthorWidget);
    } // setupUi

    void retranslateUi(QWidget *KoDocumentInfoAuthorWidget)
    {
        fullNameLabel->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Name:", 0, QApplication::UnicodeUTF8));
        fullName->setText(QString());
        lblInitialsDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Initials:", 0, QApplication::UnicodeUTF8));
        initials->setText(QString());
        lblTitleDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Title:", 0, QApplication::UnicodeUTF8));
        title->setText(QString());
        lblPositionDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Position:", 0, QApplication::UnicodeUTF8));
        position->setText(QString());
        lblCompanyDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Company:", 0, QApplication::UnicodeUTF8));
        lblEmailDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Email:", 0, QApplication::UnicodeUTF8));
        lblPhoneHome->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Telephone (home):", 0, QApplication::UnicodeUTF8));
        lblPhoneWork->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Telephone (work):", 0, QApplication::UnicodeUTF8));
        lblFaxDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Fax:", 0, QApplication::UnicodeUTF8));
        lblStreetDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Street:", 0, QApplication::UnicodeUTF8));
        lblPostalDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Postal code:", 0, QApplication::UnicodeUTF8));
        lblCityDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "City:", 0, QApplication::UnicodeUTF8));
        lblCountryDesc->setText(QApplication::translate("KoDocumentInfoAuthorWidget", "Country:", 0, QApplication::UnicodeUTF8));
        company->setText(QString());
        email->setText(QString());
        phoneHome->setText(QString());
        phoneWork->setText(QString());
        fax->setText(QString());
        street->setText(QString());
        postal->setText(QString());
        city->setText(QString());
        country->setText(QString());
        Q_UNUSED(KoDocumentInfoAuthorWidget);
    } // retranslateUi

};

namespace Ui {
    class KoDocumentInfoAuthorWidget: public Ui_KoDocumentInfoAuthorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KODOCUMENTINFOAUTHORWIDGET_H
