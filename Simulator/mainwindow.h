/*
 * GUI
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartGlobal>

#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

//Project Imports
#include "environment.h"
#include "creature.h"
#include "trait.h"
#include "carnivore.h"
#include "herbivore.h"
#include "omnivore.h"

#include "detailwindow.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //debug print statements
    bool const PRINT_CREATURES = false;
    bool const PRINT_DEBUG_HUNT = false;
    bool const PRINT_BIOME_SEASON = true;
    bool const DEBUG_PLOT = true;

    //iteration and initial counts
    int const NUMSPECIES = 10;
    int const NUMCREATURES = 100;
    int NUMSEASONS = 20;
    int const sMax = NUMSPECIES * NUMCREATURES * 1000;

    //global variables
    int sUsed;
    int cUsed;
    int hUsed;
    int oUsed;
    int pUsed;

    struct cCoords{
        string species;
        int creature;
        bool alive = true;
    };

    struct cCount{
        string species;
        int count;
    };

    Creature * sList = NULL;
    cCoords * cList = NULL;
    cCoords * hList = NULL;
    cCoords * oList = NULL;
    cCount * plotCount = NULL;
    Environment Env;
    void countSpecies(cCount[],Creature[]);
    void iterateSeason(Environment&,Creature[],cCoords[],cCoords[],cCoords[]);
    void creatureInstantiation(Environment,Creature[],cCoords[],cCoords[],cCoords[]);
    void clearDead(Creature[],cCoords[],cCoords[],cCoords[]);
    int translateSeed(string);
    void runSimulation(int,int);

private slots:
    void on_btn_start_clicked();

    void on_show_details_clicked();

private:
    Ui::MainWindow *ui;
    detailwindow *new_window;
    void clearLayout();
};

#endif // MAINWINDOW_H
