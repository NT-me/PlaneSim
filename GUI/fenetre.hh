#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "../class/sauvegarde.hh"
#include <iostream>
#include <cstring>

namespace Ui {
class fenetre;
}

class fenetre : public QMainWindow   // heritage de class Qmainwindow pour les besoins de QT
{
    Q_OBJECT						 // macro qui permet au compilateur d'integrer les mot-clé slot

public:
  explicit fenetre(QWidget *parent = 0);
  ~fenetre();

  void MAJDisplayInfo();  			 
  void MAJ();
  QString motStatePompe(string nomPompe);
  QString motStateVanne(string nom);
  QString motStateTank(string nom);
  QString motStateEngine(string nom);

public slots:                        // fonction spécial qui s'appelle notamment dans la fonction connect de QT
									 // qui permet de lier les boutons a des fonctions
    
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

    void saveButton();
    void launchEx();
    void load();

private:
	systeme *S;
  Ui::MainWindow *ui;
  sauvegarde *save;
};

#endif // MAINWINDOW_H
