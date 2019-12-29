#include "fenetre.hh"
#include "../class/systeme.hh"
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <cstring>
#include <QtCore>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    /*QMainWindow *w = new QMainWindow;

    Ui::MainWindow ui;

    // On setup le système et l'UI
    ui.setupUi(w);
    systeme S;

    QObject::connect(ui.buttonStop, SIGNAL(clicked()), qApp, SLOT(quit())); // On quitte quand on appuie sur QUITTER SANS SAUVEGARDER

    // Pompes
    ui.InfoDisplayer->append("P11");
    ui.InfoDisplayer->append(QString::number(S.getStatePompe("P11")));

    ui.InfoDisplayer->append("P12");
    ui.InfoDisplayer->append(QString::number(S.getStatePompe("P12")));

    ui.InfoDisplayer->append("P21");
    ui.InfoDisplayer->append(QString::number(S.getStatePompe("P21")));

    ui.InfoDisplayer->append("P22");
    ui.InfoDisplayer->append(QString::number(S.getStatePompe("P22")));

    ui.InfoDisplayer->append("P31");
    ui.InfoDisplayer->append(QString::number(S.getStatePompe("P31")));

    ui.InfoDisplayer->append("P32");
    ui.InfoDisplayer->append(QString::number(S.getStatePompe("P32")));

    QObject::connect(ui.buttonP11, SIGNAL(clicked()), qApp, SLOT (S->changeStatePompe("P11")));
    */
    fenetre F;
    F.show();
    return app.exec();
}
