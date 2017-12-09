#include "detailwindow.h"
#include "ui_detailwindow.h"
#include <QTableWidget>

/**
 * Constructor. Sets up QWidget and UI for the DetailWindow.
 * @param parent
 * @return none
 */
detailwindow::detailwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::detailwindow)
{
    ui->setupUi(this);
}

/**
 * Destructor for DetailWindow.
 * @param none
 * @return none
 */
detailwindow::~detailwindow()
{
    delete ui;
}

/**
 * Setter. Sets counts for columns and rows in the table.
 * @param r
 * @param c
 * @return none
 */
void detailwindow::setcounts(int r, int c)
{
    ui->table_details->setRowCount(r);
    ui->table_details->setColumnCount(c);
}

/**
 * Setter. Sets columns for table.
 * @param c
 * @return none
 */
void detailwindow::setcols(int c)
{
    ui->table_details->setColumnCount(c);
}

/**
 * Setter. Sets rows for table.
 * @param r
 * @return none
 */
void detailwindow::setrows(int r)
{
    ui->table_details->setRowCount(r);
}

/**
 * Method. Inserts row into specified spot.
 * @param r
 * @return none
 */
void detailwindow::insertrow(int r)
{
    ui->table_details->insertRow(r);
}

/**
 * Method. Inserts item into row and column in table.
 * @param r
 * @param c
 * @param t
 * @return none
 */
void detailwindow::insertitem(int r,int c,QTableWidgetItem *t)
{
    ui->table_details->setItem(r,c,t);
}
