#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class detailwindow;
}

class detailwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit detailwindow(QWidget *parent = 0);
    ~detailwindow();
    void setcounts(int, int);
    void setcols(int);
    void setrows(int);
    void insertrow(int);
    void insertitem(int,int,QTableWidgetItem *);

private:
    Ui::detailwindow *ui;
};

#endif // DETAILWINDOW_H
