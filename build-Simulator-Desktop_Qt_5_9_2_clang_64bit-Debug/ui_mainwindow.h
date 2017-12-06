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
    QLabel *title_biome;
    QLabel *title_season;
    QSpinBox *num_iterations;
    QPushButton *btn_start;
    QLabel *prompt_name;
    QLabel *biome_name;
    QLabel *biome_ws;
    QLabel *prompt_ws;
    QLabel *biome_pop;
    QLabel *prompt_pop;
    QLabel *season_name;
    QLabel *season_temp;
    QLabel *prompt_name_s;
    QLabel *prompt_temp;
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
        MainWindow->resize(1000, 600);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(722, 20, 251, 511));
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
        title_biome = new QLabel(frame_3);
        title_biome->setObjectName(QStringLiteral("title_biome"));
        title_biome->setGeometry(QRect(13, 13, 71, 31));
        QFont font;
        font.setPointSize(25);
        font.setUnderline(true);
        title_biome->setFont(font);
        title_season = new QLabel(frame_3);
        title_season->setObjectName(QStringLiteral("title_season"));
        title_season->setGeometry(QRect(13, 240, 81, 31));
        title_season->setFont(font);
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
        prompt_name = new QLabel(frame_3);
        prompt_name->setObjectName(QStringLiteral("prompt_name"));
        prompt_name->setGeometry(QRect(20, 50, 61, 41));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        prompt_name->setFont(font2);
        biome_name = new QLabel(frame_3);
        biome_name->setObjectName(QStringLiteral("biome_name"));
        biome_name->setGeometry(QRect(100, 60, 131, 21));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setWeight(50);
        biome_name->setFont(font3);
        biome_ws = new QLabel(frame_3);
        biome_ws->setObjectName(QStringLiteral("biome_ws"));
        biome_ws->setGeometry(QRect(110, 120, 121, 21));
        biome_ws->setFont(font3);
        biome_ws->setWordWrap(true);
        prompt_ws = new QLabel(frame_3);
        prompt_ws->setObjectName(QStringLiteral("prompt_ws"));
        prompt_ws->setGeometry(QRect(20, 100, 71, 51));
        prompt_ws->setFont(font2);
        prompt_ws->setWordWrap(true);
        biome_pop = new QLabel(frame_3);
        biome_pop->setObjectName(QStringLiteral("biome_pop"));
        biome_pop->setGeometry(QRect(120, 170, 111, 31));
        biome_pop->setFont(font3);
        prompt_pop = new QLabel(frame_3);
        prompt_pop->setObjectName(QStringLiteral("prompt_pop"));
        prompt_pop->setGeometry(QRect(10, 160, 101, 51));
        prompt_pop->setFont(font2);
        season_name = new QLabel(frame_3);
        season_name->setObjectName(QStringLiteral("season_name"));
        season_name->setGeometry(QRect(100, 290, 131, 21));
        season_name->setFont(font3);
        season_temp = new QLabel(frame_3);
        season_temp->setObjectName(QStringLiteral("season_temp"));
        season_temp->setGeometry(QRect(150, 320, 81, 51));
        season_temp->setFont(font3);
        season_temp->setWordWrap(true);
        prompt_name_s = new QLabel(frame_3);
        prompt_name_s->setObjectName(QStringLiteral("prompt_name_s"));
        prompt_name_s->setGeometry(QRect(20, 280, 61, 41));
        prompt_name_s->setFont(font2);
        prompt_temp = new QLabel(frame_3);
        prompt_temp->setObjectName(QStringLiteral("prompt_temp"));
        prompt_temp->setGeometry(QRect(10, 320, 131, 51));
        prompt_temp->setFont(font2);
        prompt_temp->setWordWrap(true);

        info_layout->addWidget(frame_3);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 20, 661, 511));
        gridLayout_plots = new QGridLayout(gridLayoutWidget);
        gridLayout_plots->setSpacing(6);
        gridLayout_plots->setContentsMargins(11, 11, 11, 11);
        gridLayout_plots->setObjectName(QStringLiteral("gridLayout_plots"));
        gridLayout_plots->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
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
        title_biome->setText(QApplication::translate("MainWindow", "Biome", Q_NULLPTR));
        title_season->setText(QApplication::translate("MainWindow", "Season", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        prompt_name->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        biome_name->setText(QApplication::translate("MainWindow", "place", Q_NULLPTR));
        biome_ws->setText(QApplication::translate("MainWindow", "place", Q_NULLPTR));
        prompt_ws->setText(QApplication::translate("MainWindow", "Water Supply:", Q_NULLPTR));
        biome_pop->setText(QApplication::translate("MainWindow", "place", Q_NULLPTR));
        prompt_pop->setText(QApplication::translate("MainWindow", "Population:", Q_NULLPTR));
        season_name->setText(QApplication::translate("MainWindow", "place", Q_NULLPTR));
        season_temp->setText(QApplication::translate("MainWindow", "place", Q_NULLPTR));
        prompt_name_s->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        prompt_temp->setText(QApplication::translate("MainWindow", "Temperature:", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
