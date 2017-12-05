#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QInputDialog>
#include <QDir>
#include <iostream>

QT_CHARTS_USE_NAMESPACE

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
    QString text = QInputDialog::getText(this,tr("Get Seed"), tr("Enter Seed:"),QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);

    //Display seed
    std::cout << text.toStdString() << std::endl;

    //Get iterations from num_iterations
    siter = ui->num_iterations->text();

    std::cout << siter.toStdString() << std::endl;

    iter = siter.toInt();

    for(int i = 0; i < iter; i++)
    {
        std::cout << i << std::endl;

        if(i == iter - 1)
            del = false;

        createChart(del);
    }
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
