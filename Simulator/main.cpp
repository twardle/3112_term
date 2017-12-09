#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>

/**
 * Main Method. Creates GUI and runs program.
 * @param argc
 * @param argv
 * @return a.exec()
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
