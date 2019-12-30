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
  this->t1 = new tank(1, true, p11, p12);
  this->t2 = new tank(2, true, p21, p22);
  this->t3 = new tank(3, true, p31, p32);

  // Création des moteurs
  this->e1 = new engine(1, true, "T1");
  this->e2 = new engine(2, true, "T2");
  this->e3 = new engine(3, true, "T3");

  // Création des vannes
  this->vt12 = new vanne(120, false, "T1", "T2");
  this->vt23 = new vanne(230, false, "T2", "T3");

  this->v12 = new vanne(12, false, "T1", "E2");
  this->v13 = new vanne(13, false, "T1", "E3");
  this->v23 = new vanne(23, false, "T2", "E3");
}

systeme::~systeme(){
}

pompe systeme::getPompe(string nomPompe){
  if (!nomPompe.compare(p11->getName())){
    return *p11;
  }
  else if (!nomPompe.compare(p12->getName())){
    return *p12;
  }
  else if (!nomPompe.compare(p21->getName())){
    return *p21;
  }
  else if (!nomPompe.compare(p22->getName())){
    return *p22;
  }
  else if (!nomPompe.compare(p31->getName())){
    return *p31;
  }
  else if (!nomPompe.compare(p32->getName())){
    return *p32;
  }

  pompe null;
  return null;
}

tank systeme::getTank(string nomTank){
  if (!nomTank.compare(t1->getName())){
    return *t1;
  }
  else if (!nomTank.compare(t2->getName())){
    return *t2;
  }
  else if (!nomTank.compare(t3->getName())){
    return *t3;
  }

  tank null;
  return null;
}

engine systeme::getEngine(string nomEngine){
  if (!nomEngine.compare(e1->getName())){
      return *e1;
  }
  else if (!nomEngine.compare(e2->getName())){
      return *e2;
  }
  else if (!nomEngine.compare(e3->getName())){
      return *e3;
  }

  engine null;
  return null;
}

vanne systeme::getVanne(string nomVanne){
  if (!nomVanne.compare(vt12->getName())){
    return *vt12;
  }
  else if (!nomVanne.compare(vt23->getName())){
    return *vt23;
  }
  else if (!nomVanne.compare(v12->getName())){
    return *v12;
  }
  else if (!nomVanne.compare(v13->getName())){
    return *v13;
  }
  else if (!nomVanne.compare(v23->getName())){
    return *v23;
  }

  vanne null;
  return null;
}

void systeme::changeStateVanne(string nomVanne){
  if (!nomVanne.compare(vt12->getName())){
    vt12->changeState();
  }
  else if (!nomVanne.compare(vt23->getName())){
    vt23->changeState();
  }
  else if (!nomVanne.compare(v12->getName())){
    v12->changeState();
  }
  else if (!nomVanne.compare(v13->getName())){
    v13->changeState();
  }
  else if (!nomVanne.compare(v23->getName())){
    v23->changeState();
  }
}

void systeme::changeStatePompe(string nomPompe){
  if (!nomPompe.compare(p11->getName())){
    p11->changeState();
  }
  else if (!nomPompe.compare(p12->getName())){
    p12->changeState();
  }
  else if (!nomPompe.compare(p21->getName())){
    p21->changeState();
  }
  else if (!nomPompe.compare(p22->getName())){
    p22->changeState();
  }
  else if (!nomPompe.compare(p31->getName())){
    p31->changeState();
  }
  else if (!nomPompe.compare(p32->getName())){
    p32->changeState();
  }
}

void systeme::emptyTank(string nomTank){
  if (!nomTank.compare(t1->getName())){
    t1->dump();
  }
  else if (!nomTank.compare(t2->getName())){
    t2->dump();
  }
  else if (!nomTank.compare(t3->getName())){
    t3->dump();
  }
}

void systeme::breakPompe(string nomPompe){
  if (!nomPompe.compare(p11->getName())){
    p11->setState(false);
    p11->setFailureState(true);
  }
  else if (!nomPompe.compare(p12->getName())){
    p12->setState(false);
    p12->setFailureState(true);
  }
  else if (!nomPompe.compare(p21->getName())){
    p21->setState(false);
    p21->setFailureState(true);
  }
  else if (!nomPompe.compare(p22->getName())){
    p22->setState(false);
    p22->setFailureState(true);
  }
  else if (!nomPompe.compare(p31->getName())){
    p31->setState(false);
    p31->setFailureState(true);
  }
  else if (!nomPompe.compare(p32->getName())){
    p32->setState(false);
    p32->setFailureState(true);
  }
}


bool systeme::getStateEngine(string nomEngine){
  if (!nomEngine.compare(e1->getName())){
    return e1->getState();
  }
  else if (!nomEngine.compare(e2->getName())){
    return e2->getState();
  }
  else if (!nomEngine.compare(e3->getName())){
    return e3->getState();
  }

  return false; // Retourne false par défaut
}

bool systeme::getStatePompe(string nomPompe){
  if (!nomPompe.compare(p11->getName())){
    return p11->getState();
  }
  else if (!nomPompe.compare(p12->getName())){
    return p12->getState();
  }
  else if (!nomPompe.compare(p21->getName())){
    return p21->getState();
  }
  else if (!nomPompe.compare(p22->getName())){
    return p22->getState();
  }
  else if (!nomPompe.compare(p31->getName())){
    return p31->getState();
  }
  else if (!nomPompe.compare(p32->getName())){
    return p32->getState();
  }

  return false; // Retourne false par défaut
}

bool systeme::getStateVanne(string nomVanne){
  if (!nomVanne.compare(vt12->getName())){
    return vt12->getState();
  }
  else if (!nomVanne.compare(vt23->getName())){
    return vt23->getState();
  }
  else if (!nomVanne.compare(v12->getName())){
    return v12->getState();
  }
  else if (!nomVanne.compare(v13->getName())){
    return v13->getState();
  }
  else if (!nomVanne.compare(v23->getName())){
    return v23->getState();
  }

  return false; // Retourne false par défaut
}

bool systeme::getStateTank(string nomTank){
  if (!nomTank.compare(t1->getName())){
    return t1->getState();
  }
  else if (!nomTank.compare(t2->getName())){
    return t2->getState();
  }
  else if (!nomTank.compare(t3->getName())){
    return t3->getState();
  }

  return false; // Retourne false
}

bool systeme::getFailureStatePompe(string nomPompe){
  if (!nomPompe.compare(p11->getName())){
    return p11->getFailureState();
  }
  else if (!nomPompe.compare(p12->getName())){
    return p12->getFailureState();
  }
  else if (!nomPompe.compare(p21->getName())){
    return p21->getFailureState();
  }
  else if (!nomPompe.compare(p22->getName())){
    return p22->getFailureState();
  }
  else if (!nomPompe.compare(p31->getName())){
    return p31->getFailureState();
  }
  else if (!nomPompe.compare(p32->getName())){
    return p32->getFailureState();
  }
  return false;
}

int systeme::verifTank(string nomTank){
    tank* tankName;
    tank* tankName2;
    tank* tankName3;
    vanne* vanneName;
    vanne* vanneName2 = nullptr;

    //engine current = getEngine(nomEngine);

    if (!nomTank.compare(t1->getName())){
    tankName = t1;
    tankName2 = t2; // Tank à droite
		vanneName = vt12; // Vanne à droite
    }
    else if (!nomTank.compare(t2->getName())){
    tankName = t2;
	vanneName = vt12; // Vanne à gauche
    vanneName2 = vt23; // Vanne à droite
    tankName2 = t1; // Tank à gauche
    tankName3 = t3; // Tank à droite

    }
    else if (!nomTank.compare(t3->getName())){
    tankName = t3;
    tankName2 = t2; // Tank à gauche
    vanneName = vt23; // Vanne à gauche
    }
    else {
       std::cout << "Erreur nom du tank n'existe pas" << endl;
       return -100;
    }

      if(tankName->getNormal()->getState()){
        // Si la pompe normale du tank de base est bonne POMPABLE
        return 1;
      }

      else if(tankName->getSec()->getState()){
        // Si la pompe de secours du tank de base est bonne POMPABLE
        return 1;
      }

      return false;
    }
/*
bool systeme::verifFlux(string nomEngine){
    if (!nomEngine.compare(e1->getName())){
      if((!e1->getFlux().compare(e2->getFlux()) & !e1->getFlux().compare(e3->getFlux()))){
        return false;
      }
    }
    else if (!nomEngine.compare(e2->getName())){
      if((!e2->getFlux().compare(e1->getFlux()) & !e2->getFlux().compare(e3->getFlux()))){
        return false;
      }
    }
    else if (!nomEngine.compare(e3->getName())){
      if((!e3->getFlux().compare(e1->getFlux()) & !e3->getFlux().compare(e2->getFlux()))){
        return false;
      }
    }
    return true;
}
*/

void systeme::changeFlux(string nomEngine, string nvFlux){
  if (!nomEngine.compare(e1->getName())){
      e1->setFlux(nvFlux);
  }
  else if (!nomEngine.compare(e2->getName())){
      e2->setFlux(nvFlux);
  }
  else if (!nomEngine.compare(e3->getName())){
      e3->setFlux(nvFlux);
  }
}

bool systeme::verifEngine(string nomEngine){
  tank* tankName;
  tank* tankName2;
  tank* tankName3;
  vanne* vanneName1;
  vanne* vanneName2;

  //engine current = getEngine(nomEngine);

  if (!nomEngine.compare(e1->getName())){
    tankName = t1;
    tankName2 = t2;
    tankName3 = t3;
    vanneName1 = v12;
    vanneName2 = v13;
  }
  else if (!nomEngine.compare(e2->getName())){
    tankName = t2;
    tankName2 = t1;
    tankName3 = t3;
    vanneName1 = v12;
    vanneName2 = v23;
  }
  else if (!nomEngine.compare(e3->getName())){
    tankName = t3;
    tankName2 = t2;
    tankName3 = t1;
    vanneName1 = v23;
    vanneName2 = v13;
  }
  else {
      std::cout << "Erreur nom de moteur n'existe pas" << endl;
      return false;
  }

  if(tankName->getState() & tankName->getPompage()){
    // Si le tank de base est remplit ET en capacité de pomper
    changeFlux(nomEngine, tankName->getName());
	  return true;
  }
  else if(vanneName1->getState() & tankName2->getState() & tankName2->getPompage() & tankName2->getSec()->getState() & tankName2->getNormal()->getState()){
    // Si le tank accessible avec la vanne 1 est remplit ET en état de pomper
    changeFlux(nomEngine, tankName2->getName());
	  return true;
  }
  else if(vanneName2->getState() & tankName3->getState() & tankName3->getPompage()& tankName3->getSec()->getState() & tankName3->getNormal()->getState()){
    // Si le tank accessible avec la vanne 2 est remplit ET en état de pomper
    changeFlux(nomEngine, tankName3->getName());
    return true;
  }
  else{
    return false;
  }

}

string systeme::getFluxEngine(string nomEngine){
    if (!nomEngine.compare(e1->getName())){
      return e1->getFlux();
    }
    else if (!nomEngine.compare(e2->getName())){
      return e2->getFlux();
    }
    else if (!nomEngine.compare(e3->getName())){
      return e3->getFlux();
    }
}


//~ bool systeme::verifFlux(string nomEngine)

void systeme::verifAll(){

  //cout << "E3 : " << t3->get << endl;
  if(vt12->getState()){

    if(t1->getState()){
      t2->setState(true);
    }

    if(t2->getState()){
      t1->setState(true);
    }
  }

  if(vt23->getState()){

    if(t2->getState()){
      t3->setState(true);
    }

    if(t3->getState()){
      t2->setState(true);
    }
  }

  // Verif pompabilité de T1
  if(verifTank("T1") == 1){
    t1->setPompage(true);
  }
  else{
    t1->setPompage(false);
  }

  // Verif pompabilité de T2
  if(verifTank("T2") == 1){
    t2->setPompage(true);
  }
  else{
    t2->setPompage(false);
  }

  // Verif pompabilité de T3
  if(verifTank("T3") == 1){
    t3->setPompage(true);
  }
  else{
    t3->setPompage(false);
  }


  //verif E1
  if(verifEngine("E1")){
    e1->setState(true);

  }
  else{
    e1->setState(false);
  }

  //verif E2
  if(verifEngine("E2")){
    e2->setState(true);
  }
  else{
      e2->setState(false);
    }
  //verif E3
  if(verifEngine("E3")){
      e3->setState(true);
  }
  else{
    e3->setState(false);
  }

  // verif flux
/*
  if (!verifFlux("E1")){
    e1->setState(false);
  }
  if (!verifFlux("E2")){
    e2->setState(false);
  }
  if (!verifFlux("E3")){
    e3->setState(false);
  }
*/
string F1 = e1->getFlux();
string F2 = e2->getFlux();
string F3 = e3->getFlux();

if(F1 == F2 && F1 == F3 && F1 != ""){
  e1->setState(false);
  e2->setState(false);
  e3->setState(false);
  e1->setFlux("");
  e2->setFlux("");
  e3->setFlux("");

}
/*
  cout << "Flux E1 : " << e1->getFlux() << " " << verifFlux("E1") << endl;
  cout << "Flux E2 : " << e2->getFlux() << " " << verifFlux("E2") << endl;
  cout << "Flux E3 : " << e3->getFlux() << " " << verifFlux("E3") << endl;
  */
}

systeme & systeme::operator=(const systeme &s){
  if (this==&s){
    return *this;
  }
  
  this->p11 = s.p11;
  this->p12 = s.p12;
  this->p21 = s.p21;
  this->p22 = s.p22;
  this->p31 = s.p31;
  this->p32 = s.p32;

  this->t1 = s.t1;
  this->t2 = s.t2;
  this->t3 = s.t3;

  this->e1 = s.e1;
  this->e2 = s.e2;
  this->e3 = s.e3;

  this->vt12 = s.vt12;
  this->vt23 = s.vt23;

  this->v12 = s.v12;
  this->v13 = s.v13;
  this->v23 = s.v23;

  return *this;
}
