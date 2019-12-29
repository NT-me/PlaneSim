/*
#include "mainwindow.h"
#include "../class/systeme.hh"
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <cstring>
#include <QtCore>
using namespace std;

class fenetre : public QWidget{
  Q_OBJECT

public:
  fenetre();

};
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <iostream>

namespace Ui {
class fenetre;
}

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
    explicit fenetre(QWidget *parent = 0);
    ~fenetre();

public slots:
    void foo();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
