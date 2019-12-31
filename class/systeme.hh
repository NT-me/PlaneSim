#include <cstring>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "tank.hh"
#include "engine.hh"
#include "vanne.hh"

using namespace std;

class systeme{
  /*
  Le système est une classe permettant de gérer les interactions entre les différents
  élements du système
  */

private:
  //   pompes
  pompe* p11;
  pompe* p12;

  pompe* p21;
  pompe* p22;

  pompe* p31;
  pompe* p32 ;

  //   réservoirs
  tank* t1;
  tank* t2;
  tank* t3;

  //   moteurss
  engine* e1;
  engine* e2;
  engine* e3;

  //   vannes
  vanne* vt12; // Id avec un 0 en plus à la fin
  vanne* vt23; // Id avec un 0 en plus à la fin

  vanne* v12;
  vanne* v13;
  vanne* v23;

public:
  //Constructeur
  systeme();
  systeme(pompe* p11, pompe* p12, pompe* p21, pompe* p22, pompe* p31, pompe* p32, tank* t1, tank* t2, tank* t3, vanne* vt12, vanne* vt23, vanne* v12, vanne* v13, vanne* v23, engine* e1, engine* e2, engine* e3);

  void foo();

  //Destructeur
  ~systeme();

  // Getters d'objet
  pompe getPompe(string nomPompe);
  tank getTank(string nomTank);
  engine getEngine(string nomEngine);
  vanne getVanne(string nomVanne);

  //Getters d'état
  bool getStatePompe(string nomPompe);
  bool getFailureStatePompe(string nomPompe);
  bool getStateTank(string nomTank);
  bool getStateVanne(string nomVanne);
  bool getStateEngine(string nomEngine);
  string getFluxEngine(string nomEngine);

  // Opérateur
  systeme & operator=(const systeme &s);

 // # Méthodes
 // ## Commandes de constrôle
 void changeStateVanne(string nomVanne);
 void changeStatePompe(string nomPompe);
 void changeFlux(string m, string h);

 // ## Création des pannes
 void emptyTank(string nomTank); // Vide le réservoir concerné
 void breakPompe(string nomPompe); // Casse la pompe concernée

 // ## Vérification du système
 bool verifEngine(string nomEngine);
 int verifTank(string nomTank);
 //bool verifFlux(string nomEngine);
 void verifAll();
 
 // ## fonction exercice
 string choixPompe(int i); // renvoie le nom d'une pompe en fonction d'un chiffre
 void panne1();			   // envoie 1 panne de maniere aléatoire
 void panne2();			   // envoie 2 panne de maniere aléatoire			
 void panne3();			   // envoie 3 panne de maniere aléatoire
 void panne4();			   // envoie 4 panne de maniere aléatoire
 void panne5();			   // envoie 5 panne de maniere aléatoire
 void exercice();          // creer un nombre de probleme aléatoire
};
