#include "systeme.hh"

systeme::systeme(){
  // Création des pompes
  this->p11 = new pompe(11, true, 'N');
  this->p12 = new pompe(12, false, 'S');

  this->p21 = new pompe(21, true, 'N');
  this->p22 = new pompe(22, false, 'S');

  this->p31 = new pompe(31, true, 'N');
  this->p32 = new pompe(32, false, 'S');

  // Création des réservoirs
  this->t1 = new tank(1, true, *p11, *p12);
  this->t2 = new tank(2, true, *p21, *p22);
  this->t3 = new tank(3, true, *p31, *p32);

  // Création des moteurs
  this->e1 = new engine(1, true);
  this->e2 = new engine(2, true);
  this->e3 = new engine(3, true);

  // Création des vannes
  this->vt12 = new vanne(120, false, "T1", "T2");
  this->vt23 = new vanne(230, false, "T2", "T3");

  this->v12 = new vanne(12, false, "T1", "E2");
  this->v13 = new vanne(13, false, "T1", "E3");
  this->v23 = new vanne(23, false, "T2", "E3");
}

systeme::~systeme(){
}

void systeme::changeStateVanne(string nomVanne){
  if (nomVanne.compare(vt12->getName())){
    vt12->changeState();
  }
  else if (nomVanne.compare(vt23->getName())){
    vt23->changeState();
  }
  else if (nomVanne.compare(v12->getName())){
    v12->changeState();
  }
  else if (nomVanne.compare(v13->getName())){
    v13->changeState();
  }
  else if (nomVanne.compare(v23->getName())){
    v23->changeState();
  }
}

void systeme::changeStatePompe(string nomPompe){
  if (nomPompe.compare(p11->getName())){
    p11->changeState();
  }
  else if (nomPompe.compare(p12->getName())){
    p12->changeState();
  }
  else if (nomPompe.compare(p21->getName())){
    p21->changeState();
  }
  else if (nomPompe.compare(p22->getName())){
    p22->changeState();
  }
  else if (nomPompe.compare(p31->getName())){
    p31->changeState();
  }
  else if (nomPompe.compare(p32->getName())){
    p32->changeState();
  }
}

void systeme::emptyTank(string nomTank){
  if (nomTank.compare(t1->getName())){
    t1->dump();
  }
  else if (nomTank.compare(t2->getName())){
    t2->dump();
  }
  else if (nomTank.compare(t3->getName())){
    t3->dump();
  }
}

void systeme::breakPompe(string nomPompe){
  if (nomPompe.compare(p11->getName())){
    p11->setState(false);
    p11->setFailureState(true);
  }
  else if (nomPompe.compare(p12->getName())){
    p12->setState(false);
    p12->setFailureState(true);
  }
  else if (nomPompe.compare(p21->getName())){
    p21->setState(false);
    p21->setFailureState(true);
  }
  else if (nomPompe.compare(p22->getName())){
    p22->setState(false);
    p22->setFailureState(true);
  }
  else if (nomPompe.compare(p31->getName())){
    p31->setState(false);
    p31->setFailureState(true);
  }
  else if (nomPompe.compare(p32->getName())){
    p32->setState(false);
    p32->setFailureState(true);
  }
}


bool systeme::getStateEngine(string nomEngine){
  if (nomEngine.compare(e1->getName())){
    return e1->getState();
  }
  else if (nomEngine.compare(e2->getName())){
    return e2->getState();
  }
  else if (nomEngine.compare(e3->getName())){
    return e3->getState();
  }

  return false; // Retourne false par défaut
}

bool systeme::getStatePompe(string nomPompe){
  if (nomPompe.compare(p11->getName())){
    return p11->getState();
  }
  else if (nomPompe.compare(p12->getName())){
    return p12->getState();
  }
  else if (nomPompe.compare(p21->getName())){
    return p21->getState();
  }
  else if (nomPompe.compare(p22->getName())){
    return p22->getState();
  }
  else if (nomPompe.compare(p31->getName())){
    return p31->getState();
  }
  else if (nomPompe.compare(p32->getName())){
    return p32->getState();
  }

  return false; // Retourne false par défaut
}

bool systeme::getStateVanne(string nomVanne){
  if (nomVanne.compare(vt12->getName())){
    return vt12->getState();
  }
  else if (nomVanne.compare(vt23->getName())){
    return vt23->getState();
  }
  else if (nomVanne.compare(v12->getName())){
    return v12->getState();
  }
  else if (nomVanne.compare(v13->getName())){
    return v13->getState();
  }
  else if (nomVanne.compare(v23->getName())){
    return v23->getState();
  }

  return false; // Retourne false par défaut
}

bool systeme::getStateTank(string nomTank){
  if (nomTank.compare(t1->getName())){
    return t1->getState();
  }
  else if (nomTank.compare(t2->getName())){
    return t2->getState();
  }
  else if (nomTank.compare(t3->getName())){
    return t3->getState();
  }

  return false; // Retourne false
}

bool systeme::getFailureStatePompe(string nomPompe){

  return false;
}
