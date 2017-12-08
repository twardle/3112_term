#include "detailwindow.h"
#include "ui_detailwindow.h"
#include <QTableWidget>

detailwindow::detailwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::detailwindow)
{
    ui->setupUi(this);
}

detailwindow::~detailwindow()
{
    delete ui;
}

void detailwindow::setcounts(int r, int c)
{
    ui->table_details->setRowCount(r);
    ui->table_details->setColumnCount(c);
}

void detailwindow::setcols(int c)
{
    ui->table_details->setColumnCount(c);
}

void detailwindow::setrows(int r)
{
    ui->table_details->setRowCount(r);
}

void detailwindow::insertrow(int r)
{
    ui->table_details->insertRow(r);
}

void detailwindow::insertitem(int r,int c,QTableWidgetItem *t)
{
    ui->table_details->setItem(r,c,t);
}


