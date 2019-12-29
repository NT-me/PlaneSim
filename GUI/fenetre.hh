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
#include "../class/systeme.hh"
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
	void changeStateVT12();
	void changeStateVT23();
	void changeStateV12();
	void changeStateV13();
	void changeStateV23();
	
	void changeStateP11();
	void changeStateP12();
	void changeStateP21();
	void changeStateP22();
	void changeStateP31();
	void changeStateP32();
	
	void createPanneP11();
	void createPanneP12();
	void createPanneP21();
	void createPanneP22();
	void createPanneP31();
	void createPanneP32();
	
	void createPanneT1();
	void createPanneT2();
	void createPanneT3();

private:
	systeme *S;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
