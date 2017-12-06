/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *info_layout;
    QFrame *frame_3;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *num_iterations;
    QPushButton *btn_start;
    QTextEdit *biome_text;
    QTextEdit *season_text;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_plots;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(540, 20, 251, 511));
        info_layout = new QHBoxLayout(horizontalLayoutWidget);
        info_layout->setSpacing(6);
        info_layout->setContentsMargins(11, 11, 11, 11);
        info_layout->setObjectName(QStringLiteral("info_layout"));
        info_layout->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(horizontalLayoutWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setEnabled(true);
        frame_3->setMinimumSize(QSize(100, 0));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(13, 13, 61, 26));
        QFont font;
        font.setPointSize(22);
        label_5->setFont(font);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(13, 244, 71, 26));
        label_6->setFont(font);
        num_iterations = new QSpinBox(frame_3);
        num_iterations->setObjectName(QStringLiteral("num_iterations"));
        num_iterations->setGeometry(QRect(50, 430, 51, 21));
        num_iterations->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        num_iterations->setMinimum(1);
        num_iterations->setMaximum(1000);
        num_iterations->setValue(10);
        btn_start = new QPushButton(frame_3);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(130, 420, 91, 51));
        QFont font1;
        font1.setPointSize(20);
        btn_start->setFont(font1);
        btn_start->setCheckable(false);
        biome_text = new QTextEdit(frame_3);
        biome_text->setObjectName(QStringLiteral("biome_text"));
        biome_text->setGeometry(QRect(13, 49, 225, 185));
        QFont font2;
        font2.setPointSize(15);
        biome_text->setFont(font2);
        biome_text->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        biome_text->setTextInteractionFlags(Qt::NoTextInteraction);
        season_text = new QTextEdit(frame_3);
        season_text->setObjectName(QStringLiteral("season_text"));
        season_text->setEnabled(true);
        season_text->setGeometry(QRect(13, 280, 225, 121));
        season_text->setFont(font2);
        season_text->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        season_text->setAutoFillBackground(false);
        season_text->setTextInteractionFlags(Qt::NoTextInteraction);

        info_layout->addWidget(frame_3);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 511, 511));
        gridLayout_plots = new QGridLayout(gridLayoutWidget);
        gridLayout_plots->setSpacing(6);
        gridLayout_plots->setContentsMargins(11, 11, 11, 11);
        gridLayout_plots->setObjectName(QStringLiteral("gridLayout_plots"));
        gridLayout_plots->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Evolution Simulator", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("MainWindow", "Biome", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Season", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        biome_text->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Biome Name</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Water Supply</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Population</p></body></html>", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        season_text->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        season_text->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:13pt;\">Season Name</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:13pt;\">Temperature</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:13pt;\"><br /></p></body></html>", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
