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
  // Création des pompes
  pompe* p11 = new pompe(11, true, 'N');
  pompe* p12 = new pompe(12, false, 'S');

  pompe* p21 = new pompe(21, true, 'N');
  pompe* p22 = new pompe(22, false, 'S');

  pompe* p31 = new pompe(31, true, 'N');
  pompe* p32 = new pompe(32, false, 'S');

  // Création des réservoirs
  tank* t1 = new tank(1, true, *p11, *p12);
  tank* t2 = new tank(2, true, *p21, *p22);
  tank* t3 = new tank(3, true, *p31, *p32);

  // Création des moteurs
  engine* e1 = new engine(1, true);
  engine* e2 = new engine(2, true);
  engine* e3 = new engine(3, true);

  // Création des vannes
  vanne* vt12 = new vanne(120, false, "T1", "T2");
  vanne* vt23 = new vanne(230, false, "T2", "T3");

  vanne* v12 = new vanne(12, false, "T1", "E2");
  vanne* v13 = new vanne(13, false, "T1", "E3");
  vanne* v23 = new vanne(23, false, "T2", "E3");


public:
};
