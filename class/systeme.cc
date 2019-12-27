#include "systeme.hh"

systeme::systeme(){
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
}

systeme::~systeme(){
}

void systeme::changeStateVanne(string nomVanne){
  if (nomVanne.compare(vt12->getName())){
    vt12->changeState();
  }
  if (nomVanne.compare(vt23->getName())){
    vt23->changeState();
  }
  if (nomVanne.compare(v12->getName())){
    v12->changeState();
  }
  if (nomVanne.compare(v13->getName())){
    v13->changeState();
  }
  if (nomVanne.compare(v23->getName())){
    v23->changeState();
  }
}

void systeme::changeStatePompe(string nomPompe){
  if (nomPompe.compare(p11->getName())){
    p11->changeState();
  }
  if (nomPompe.compare(p12->getName())){
    p12->changeState();
  }
  if (nomPompe.compare(p21->getName())){
    p21->changeState();
  }
  if (nomPompe.compare(p22->getName())){
    p22->changeState();
  }
  if (nomPompe.compare(p31->getName())){
    p31->changeState();
  }
  if (nomPompe.compare(p32->getName())){
    p32->changeState();
  }
}

void systeme::emptyTank(string nomTank){
  if (nomTank.compare(t1->getName())){
    t1->dump();
  }
  if (nomTank.compare(t2->getName())){
    t2->dump();
  }
  if (nomTank.compare(t3->getName())){
    t3->dump();
  }
}

void systeme::breakPompe(string nomPompe){
  if (nomPompe.compare(p11->getName())){
    p11->changeState();
  }
  if (nomPompe.compare(p12->getName())){
    p12->changeState();
  }
  if (nomPompe.compare(p21->getName())){
    p21->changeState();
  }
  if (nomPompe.compare(p22->getName())){
    p22->changeState();
  }
  if (nomPompe.compare(p31->getName())){
    p31->changeState();
  }
  if (nomPompe.compare(p32->getName())){
    p32->changeState();
  }
}
