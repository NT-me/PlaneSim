#include "mainwindow.h"
#include "fenetre.hh"
#include "../class/systeme.hh"

#include "QThread"
#include "QTimer"


fenetre::fenetre(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QTimer::singleShot(0, this, SLOT(AfterUI()));

    systeme S;

    QObject::connect(ui->buttonStop, SIGNAL(clicked()), qApp, SLOT(quit())); // On quitte quand on appuie sur QUITTER SANS SAUVEGARDER

    // Pompes
    ui->InfoDisplayer->append("P11");
    ui->InfoDisplayer->append(QString::number(S.getStatePompe("P11")));

    ui->InfoDisplayer->append("P12");
    ui->InfoDisplayer->append(QString::number(S.getStatePompe("P12")));

    ui->InfoDisplayer->append("P21");
    ui->InfoDisplayer->append(QString::number(S.getStatePompe("P21")));

    ui->InfoDisplayer->append("P22");
    ui->InfoDisplayer->append(QString::number(S.getStatePompe("P22")));

    ui->InfoDisplayer->append("P31");
    ui->InfoDisplayer->append(QString::number(S.getStatePompe("P31")));

    ui->InfoDisplayer->append("P32");
    ui->InfoDisplayer->append(QString::number(S.getStatePompe("P32")));

    QObject::connect(ui->buttonP11, SIGNAL(clicked()), this, SLOT (foo()));
}

void fenetre::foo(){
  std::cout << "coucou" << endl;
}

fenetre::~fenetre()
{
    delete ui;
}
