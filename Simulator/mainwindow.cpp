//QT Imports
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QInputDialog>
#include <QDir>

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
    bool del = true;
    bool ok;

    //Disable start button
    ui->btn_start->setEnabled(false);

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

//    for(int i = 0; i < iter; i++)
//    {
//        std::cout << i << std::endl;

//        if(i == iter - 1)
//            del = false;

//        createChart(del);
//    }
}

void MainWindow::createChart(bool del)
{
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

    *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                    << QPointF(16, 7) << QPointF(18, 5);
    *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
                    << QPointF(16, 4) << QPointF(18, 3);

    QAreaSeries *series = new QAreaSeries(series0, series1);
    series->setName("Batman");
    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple areachart example");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 20);
    chart->axisY()->setRange(0, 10);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout_plots->addWidget(chartView);

    if(del == true)
        ui->gridLayout_plots->removeWidget(chartView);
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

    int random_biome = (rand() % 5);
    Env = Environment(random_biome);
    Env.readTraits(); //Get traits

    creatureInstantiation(Env,sList,cList,hList,oList);

    //iterate seasons
    for(int i = 0; i < NUMSEASONS; i++){
        if(sUsed == 0)
            break;
        iterateSeason(Env, sList, cList, oList, hList);
        for(int j = 0; j < sUsed; j++){
            float avgWaterNeed=1.0;
            if(sList[j].getHealth() > 0){
                avgWaterNeed *= sList[j].getWaterNeed();
            }
        }
        clearDead(sList,cList,oList,hList);
        Env.changeseason();

        if(PRINT_BIOME_SEASON){
                cout << Env.toString(sUsed);
                cout << Env.get_season().toString() << endl << endl;
            }

        countSpecies(plotCount, sList);

        for(int i = 0; i < pUsed; i++)
            if(DEBUG_PLOT)
                cout << plotCount[i].species << ":\t\t" << plotCount[i].count << endl;

        delete [] plotCount;
        plotCount = new cCount[sMax];
        pUsed = 0;
    }



    delete [] cList;
    delete [] sList;
    delete [] hList;
    delete [] oList;
    delete [] plotCount;
}

void MainWindow::countSpecies(cCount[], Creature[])
{
    for(int i = 0; i < sUsed; i++){
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
            if(sList[oList[i].creature].getHealth() <= 0){
                hList[i].alive = false;
            }
            else{
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
