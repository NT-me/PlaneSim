#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "../class/systeme.hh"
#include <iostream>
#include <cstring>

namespace Ui {
class fenetre;
}

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
  explicit fenetre(QWidget *parent = 0);
  ~fenetre();

  void MAJDisplayInfo();
  void MAJ();
  QString motStatePompe(string nomPompe);
  QString motStateVanne(string nom);
  QString motStateTank(string nom);
  QString motStateEngine(string nom);

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
