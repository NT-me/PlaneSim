#include "mainwindow.h"
#include <QMainWindow>

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ui::MainWindow w;
    w.show();

    return a.exec();
}
