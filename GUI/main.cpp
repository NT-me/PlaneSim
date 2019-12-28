#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *w = new QMainWindow;
    Ui::MainWindow ui;
    ui.setupUi(w);

    w->show();
    return app.exec();
}
