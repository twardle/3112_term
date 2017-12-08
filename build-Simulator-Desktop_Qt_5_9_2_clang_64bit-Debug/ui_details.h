/********************************************************************************
** Form generated from reading UI file 'details.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILS_H
#define UI_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Details
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *Details)
    {
        if (Details->objectName().isEmpty())
            Details->setObjectName(QStringLiteral("Details"));
        Details->resize(800, 600);
        gridLayoutWidget = new QWidget(Details);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 801, 611));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Details);

        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QWidget *Details)
    {
        Details->setWindowTitle(QApplication::translate("Details", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Details: public Ui_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILS_H
