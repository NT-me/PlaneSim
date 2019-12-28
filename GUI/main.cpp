#include "mainwindow.h"
#include "../class/systeme.hh"
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *w = new QMainWindow;
    Ui::MainWindow ui;

    // On setup le système et l'UI
    ui.setupUi(w);
    systeme *S = new systeme();

    QObject::connect(ui.buttonStop, SIGNAL(clicked()), qApp, SLOT(quit())); // On quitte quand on appuie sur QUITTER SANS SAUVEGARDER
    ui.InfoDisplayer->append("P11");
    ui.InfoDisplayer->append(QString::number(true));


    w->show();
    return app.exec();
}
