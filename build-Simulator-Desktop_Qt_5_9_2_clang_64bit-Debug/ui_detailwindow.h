/********************************************************************************
** Form generated from reading UI file 'detailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILWINDOW_H
#define UI_DETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detailwindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *table_details;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *detailwindow)
    {
        if (detailwindow->objectName().isEmpty())
            detailwindow->setObjectName(QStringLiteral("detailwindow"));
        detailwindow->resize(800, 600);
        centralwidget = new QWidget(detailwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 561));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        table_details = new QTableWidget(gridLayoutWidget);
        table_details->setObjectName(QStringLiteral("table_details"));
        table_details->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(table_details, 0, 0, 1, 1);

        detailwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(detailwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        detailwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(detailwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        detailwindow->setStatusBar(statusbar);

        retranslateUi(detailwindow);

        QMetaObject::connectSlotsByName(detailwindow);
    } // setupUi

    void retranslateUi(QMainWindow *detailwindow)
    {
        detailwindow->setWindowTitle(QApplication::translate("detailwindow", "Population Details", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class detailwindow: public Ui_detailwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILWINDOW_H
