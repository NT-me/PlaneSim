#include <cstring>
#include <iostream>

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

  //Destructeur
  ~systeme();

  //Getters d'état
  bool getStatePompe(string nomPompe);
  bool getFailureStatePompe(string nomPompe);
  bool getStateTank(string nomTank);
  bool getStateVanne(string nomVanne);
  bool getStateEngine(string nomEngine);

 // # Méthodes
 // ## Commandes de constrôle
 void changeStateVanne(string nomVanne);
 void changeStatePompe(string nomPompe);

 // ## Création des pannes
 void emptyTank(string nomTank); // Vide le réservoir concerné
 void breakPompe(string nomPompe); // Casse la pompe concernée

};
