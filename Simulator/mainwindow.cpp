//QT Imports
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detailwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QInputDialog>
#include <QDir>
#include <QValueAxis>
#include <QTableWidget>

QT_CHARTS_USE_NAMESPACE

using namespace std;

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new_window = new detailwindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_start_clicked()
{
    //Variables
    QString siter; //Default value
    int iter = 0;
    bool ok;

    //Disable start button
    ui->btn_start->setEnabled(false);

    //Clear the layout
    clearLayout();

    //Get player input via QInputDialog
    QString seed = QInputDialog::getText(this,tr("Get Seed"), tr("Enter Seed:"),QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);

    //Display seed
    std::cout << seed.toStdString() << std::endl;

    //Get iterations from num_iterations
    siter = ui->num_iterations->text();

    std::cout << siter.toStdString() << std::endl;

    iter = siter.toInt();

    runSimulation(iter,translateSeed(seed.toStdString()));
}

void MainWindow::createChart()
{   
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

    *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                    << QPointF(16, 7) << QPointF(18, 5);
    *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
                    << QPointF(16, 4) << QPointF(18, 3);

    //QAreaSeries *series = new QAreaSeries(series0, series1);
    //series->setName("Batman");
    //series->setPen(pen);

    QChart *chart = new QChart();
    chart->addSeries(series0);
    chart->addSeries(series1);
    chart->setTitle("Population Over Time");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 20);
    chart->axisY()->setRange(0, 10);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout_plots->addWidget(chartView);
}

void MainWindow::clearLayout()
{
    for(int i = 0; i < ui->gridLayout_plots->count(); i++)
    {
        ui->gridLayout_plots->itemAt(i)->widget()->deleteLater();
    }
}

void MainWindow::runSimulation(int numIterations,int seed){
    NUMSEASONS = numIterations;
    srand( seed );
    sUsed = 0;
    cUsed = 0;
    hUsed = 0;
    oUsed = 0;
    pUsed = 0;
    //initialization of global variables

    //Main Variables
    Env = Environment(); //Create environment
    sList = new Creature[sMax];
    cList = new cCoords[sMax];
    hList = new cCoords[sMax];
    oList = new cCoords[sMax];
    plotCount = new cCount[sMax];

    //Variable
    int number = NUMSPECIES; //Number represents default numspecies
    int maxCount = NUMCREATURES;

    //Create array to hold largest values for each species
    int *largest = new int[sMax];

    //Create random biome
    int random_biome = (rand() % 5);
    Env = Environment(random_biome);
    Env.readTraits(); //Get traits

    creatureInstantiation(Env,sList,cList,hList,oList);

    //Create table stuff
    new_window->setcols(numIterations+2);
    new_window->setrows(NUMSPECIES+1);

    //Create default list of lineseries
    QLineSeries *series[sMax];
    QChart *chart = new QChart();

    for(int i = 0; i < NUMSPECIES; i++)
    {
        series[i] = new QLineSeries();
        series[i]->append(0,NUMCREATURES);
        largest[i] = NUMCREATURES;
        QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(NUMCREATURES));
        new_window->insertitem(i+1,1,item);
    }

    //iterate seasons
    for(int i = 0; i < NUMSEASONS; i++)
    {
        if(sUsed == 0)
            break;
        iterateSeason(Env, sList, cList, oList, hList);

        clearDead(sList,cList,oList,hList);
        Env.changeseason();

        if(PRINT_BIOME_SEASON)
        {
                //Print to Console
                cout << Env.toString(sUsed);
                cout << Env.get_season().toString() << endl << endl;

                //Change GUI to Reflect Updates
                QString biome = QString::fromStdString(Env.get_biome());
                QString water_supply = QString::number(Env.get_water_supply());
                QString water_refill = QString::number(Env.get_water_refill_speed());
                QString water = water_supply;
                water.append("(+");
                water.append(water_refill);
                water.append(")");
                QString pop = QString::number(sUsed);
                QString season = QString::fromStdString(Env.get_season().getSeason());
                QString temp = QString::number(Env.get_temp());

                ui->biome_name->setText(biome);
                ui->biome_ws->setText(water);
                ui->biome_pop->setText(pop);
                ui->season_name->setText(season);
                ui->season_temp->setText(temp);
        }

        countSpecies(plotCount, sList);

        if(pUsed > number)
        {
            for(int k = number; k < pUsed; k++)
            {
                series[k] = new QLineSeries();
                largest[k] = plotCount[k].count;
                new_window->insertrow(k+1);
                QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(plotCount[k].count));
                new_window->insertitem(k+1,i+2,item);
            }

            number = pUsed;
        }

        for(int j = 0; j < pUsed; j++)
        {
            series[j]->append(i+1,plotCount[j].count);
            QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(plotCount[j].count));
            new_window->insertitem(j+1,i+2,item);

            if(largest[j] < plotCount[j].count)
                largest[j] = plotCount[j].count;

            //Get maximum count
            if(plotCount[j].count > maxCount)
                maxCount = plotCount[j].count;

            if(DEBUG_PLOT)
                cout << plotCount[j].species << ":\t\t" << plotCount[j].count << endl;
        }
    }

    //Set beginning values for row 1
    for(int i = 0; i <= numIterations+1; i++)
    {
        QTableWidgetItem *item;
        if(i == 0) //Species Name
        {
            item = new QTableWidgetItem(tr("Species"));
        }
        else
        {
            item = new QTableWidgetItem(tr("Iteration %1").arg(i-1));
        }
        new_window->insertitem(0,i,item);
    }

    for(int i = 0; i <= pUsed+2; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(tr(plotCount[i].species.c_str()));
        new_window->insertitem(i+1,0,item);
    }

    //Add each series to the chart
    //Set up name for each series
    for(int i = 0; i < pUsed; i++)
    {
        //Randomly generate colors
        int red = (rand() % 255);
        int green = (rand() % 255);
        int blue = (rand() % 255);

        //Create pen
        QPen pen(QColor(red,green,blue));

        if(largest[i] >= 20) //Display on chart
        {
            series[i]->setName(QString::fromStdString(plotCount[i].species));
            series[i]->setPen(pen);
            chart->addSeries(series[i]);
        }
    }

    //Add each series to the chart
    chart->setTitle("Population Over Time");
    chart->createDefaultAxes();
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->axisX()->setRange(0,numIterations);
    chart->axisY()->setRange(0,maxCount);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout_plots->addWidget(chartView);

    //Reenable Start Button
    ui->btn_start->setEnabled(true);
    ui->btn_start->setText("Restart");

    delete [] cList;
    delete [] sList;
    delete [] hList;
    delete [] oList;
    delete [] plotCount;
}

void MainWindow::countSpecies(cCount[], Creature[])
{
    for(int i = 0; i < pUsed; i++)
    {
        plotCount[i].count = 0;
    }

    for(int i = 0; i < sUsed; i++)
    {
                int found = false;
                int j;
                for(j = 0; j < pUsed; j++){
                    for(int k = 0; k < 5; k++){
                        if(plotCount[j].species.at(k) != sList[i].getSpecies().at(k)){
                            found = false;
                            break;
                        }
                        else
                            found = true;
                    }
                    if(found)
                        break;
                }
                if(found){
                    plotCount[j].count++;
                }
                else{
                    cCount temp;
                    temp.count = 1;
                    temp.species = sList[i].getSpecies();
                    plotCount[pUsed++] = temp;
                }
        }
}

int MainWindow::translateSeed(string userSeed)
{
    int seed = 0;
    for (unsigned int i = 0; i < userSeed.length(); i++)
            {
                char x = userSeed.at(i);
                seed += int(x);
            }
    return seed;
}

void MainWindow::iterateSeason(Environment & Env, Creature sList[], cCoords cList[], cCoords oList[], cCoords hList[]){

    for(int i = 0; i < cUsed; i++){
        if(cList[i].alive){
            if(sList[cList[i].creature].getHealth() < 0){
                cList[i].alive = false;
            }
            else{
                sList[cList[i].creature].setAge(sList[cList[i].creature].getAge() + 0.25);
                int breed = rand() % cUsed;
                bool breeding = ((((rand() % 200) + 1) / 100.0) <= sList[cList[i].creature].getBreedChance(Env));
                if(breeding){
                    if(sUsed < sMax)
                        if(hUsed < sMax){
                            cCoords temp;
                            //TODO:  Consider passing reference creature
                            sList[cList[i].creature].breed(sList[cList[breed].creature],rand());
                            sList[sUsed].setSpecies();
                            sList[sUsed].calcStats(Env);
                            temp.species = sList[sUsed].getSpecies();
                            temp.creature = sUsed++;
                            cList[cUsed++] = temp;
                        }
                }
                int creature = rand() % sUsed;
                if(creature != cList[i].creature && sList[creature].getHealth() > 0){
                    if(PRINT_DEBUG_HUNT)
                        cout << "pre-hunt" << sList[creature].getHealth() << endl;
                    ((Carnivore)(sList[cList[i].creature])).hunt(sList[creature]);
                    if(PRINT_DEBUG_HUNT)
                        cout << "hunted" << sList[creature].getHealth() << endl;

                }
            }
        }
    }

    for(int i = 0; i < oUsed; i++){
        if(oList[i].alive){
            if(sList[oList[i].creature].getHealth() < 0){
                oList[i].alive = false;
            }
            else{
                sList[oList[i].creature].setAge(sList[oList[i].creature].getAge() + 0.25);
                int breed = rand() % oUsed;
                bool breeding = ((((rand() % 200) + 1) / 100.0) <= sList[oList[i].creature].getBreedChance(Env));
                if(breeding){
                    if(sUsed < sMax)
                        if(oUsed < sMax){
                            cCoords temp;
                            //TODO:  Consider passing reference creature
                            sList[sUsed] = sList[oList[i].creature].breed(sList[oList[breed].creature],rand());
                            sList[sUsed].setSpecies();
                            sList[sUsed].calcStats(Env);
                            temp.species = sList[sUsed].getSpecies();
                            temp.creature = sUsed++;
                            oList[oUsed++] = temp;
                        }
                }
                int creature = rand() % sUsed;
                if(creature != oList[i].creature && sList[creature].getHealth() > 0){
                    if(PRINT_DEBUG_HUNT)
                        cout << "pre-hunt" << sList[creature].getHealth() << endl;
                    ((Omnivore)(sList[oList[i].creature])).hunt(sList[creature]);
                    if(PRINT_DEBUG_HUNT)
                        cout << "hunted" << sList[creature].getHealth() << endl;

                }
            }
        }
    }

    for(int i = 0; i < hUsed; i++){
        if(hList[i].alive){
            if(sList[hList[i].creature].getHealth() <= 0){
                hList[i].alive = false;
            }
            else{
                sList[hList[i].creature].setAge(sList[hList[i].creature].getAge() + 0.25);
                int breed = rand() % hUsed;
                bool breeding = ((((rand() % 200) + 1) / 100.0) <= sList[hList[i].creature].getBreedChance(Env));
                if(breeding){
                    if(sUsed < sMax)
                        if(hUsed < sMax){
                            cCoords temp;
                            //TODO:  Consider passing reference creature
                            sList[sUsed] = sList[hList[i].creature].breed(sList[hList[breed].creature],rand());
                            sList[sUsed].setSpecies();
                            sList[sUsed].calcStats(Env);
                            temp.species = sList[sUsed].getSpecies();
                            temp.creature = sUsed++;
                            hList[hUsed++] = temp;
                        }
                }
            }
        }
    }

    for(int i = 0; i < sUsed; i++){
        if(sList[i].getHealth() > 0)
            if (sList[i].updateHealth(Env) && PRINT_CREATURES){
                cout << sList[i].toString() << endl;
            }
        }
}

void MainWindow::creatureInstantiation(Environment Env, Creature sList[], cCoords cList[], cCoords hList[], cCoords oList[]){
    for(int i = 0; i < NUMSPECIES; i++)
    {
        int cType = rand() % 3;
        bool dominance;
        Carnivore newCarnivore;
        Omnivore newOmnivore;
        Herbivore newHerbivore;
        switch (cType){
        case 0:
            newCarnivore.setTrait(0,Env.traitList[0][2]);
            for(int i = 1; i < 5 ; i++){
                for(int j = 0; j < 6; j++){
                    dominance = rand() % 2;
                    if(Env.traitList[i][j].getAnimalType() == 2)
                            if(Env.traitList[i][j].getDominance() == dominance){
                                newCarnivore.setTrait(i,Env.traitList[i][j]);
                            }
                }
            }
            newCarnivore.setSpecies();
            for(int j = 0; j < NUMCREATURES; j++){
                cCoords temp;
                temp.creature = sUsed;
                temp.species = newCarnivore.getSpecies();
                newCarnivore.index = cUsed;
                sList[sUsed++] = newCarnivore;
                cList[cUsed++] = temp;
            }
            break;
        case 1:
            newOmnivore.setTrait(0,Env.traitList[0][1]);
            for(int i = 1; i < 5 ; i++){
                for(int j = 0; j < 6; j++){
                    dominance = rand() % 2;
                    if(Env.traitList[i][j].getAnimalType() == 1)
                        if(Env.traitList[i][j].getDominance() == dominance)
                            newOmnivore.setTrait(i,Env.traitList[i][j]);
                }
            }
            newOmnivore.setSpecies();
            for(int j = 0; j < NUMCREATURES; j++){
                cCoords temp;
                temp.creature = sUsed;
                temp.species = newOmnivore.getSpecies();
                newOmnivore.index = cUsed;
                sList[sUsed++] = newOmnivore;
                oList[oUsed++] = temp;
            }
            break;
        case 2:
            newHerbivore.setTrait(0,Env.traitList[0][0]);
            for(int i = 1; i < 5 ; i++){
                for(int j = 0; j < 6; j++){
                    dominance = rand() % 2;
                    if(Env.traitList[i][j].getAnimalType() == 0)
                            if(Env.traitList[i][j].getDominance() == dominance)
                                newHerbivore.setTrait(i,Env.traitList[i][j]);
                }
            }
            newHerbivore.setSpecies();
            for(int j = 0; j < NUMCREATURES; j++){
                cCoords temp;
                temp.creature = sUsed;
                temp.species = newHerbivore.getSpecies();
                newHerbivore.index = cUsed;
                sList[sUsed++] = newHerbivore;
                hList[hUsed++] = temp;
            }
            break;
        default:
            cout << "err" << std::endl;
        }
    }

    for(int i = 0; i < sUsed; i++){
        sList[i].calcStats(Env);
    }
}

void MainWindow::clearDead(Creature * sList,cCoords * cList,cCoords * oList,cCoords * hList){
    int currUsed = 0;
    int numDead = 0;
    for(int i = 0; i < sUsed; i++){
        if(sList[i].getHealth() > 0){
            sList[currUsed] = sList[i];
            if(sList[currUsed].getSpecies().at(0) == 'C'){
                cList[sList[i].index].creature = currUsed;
            }
            else if(sList[currUsed].getSpecies().at(0) == 'H'){
                hList[sList[i].index].creature = currUsed;
            }
            else if(sList[currUsed].getSpecies().at(0) == 'O'){
                oList[sList[i].index].creature = currUsed;
            }
            currUsed++;
        }
        else numDead++;
    }
    sUsed = currUsed;
}

void MainWindow::on_show_details_clicked()
{

    new_window->show();

}
