#include "sauvegarde.hh"

using namespace std;

sauvegarde::sauvegarde(){

  this->historique = "Début historique \n";
  this->note = 0;
  this->S_Save = new systeme();
}

sauvegarde::~sauvegarde(){
// A faire
}

int sauvegarde::getNote(){
  return this->note;
}

string sauvegarde::getHistorique(){
  return this->historique;
}

systeme* sauvegarde::getSsave(){
  return this->S_Save;
}

void sauvegarde::setNote(int n){
  this->note = n;
}

void sauvegarde::setHistorique(string h){
  this->historique = h;
}

void sauvegarde::setSsave(systeme *s){
  this->S_Save = s;
}

void sauvegarde::addAction(string s){
  string old;
  string unold;
  old = this->historique;
  s = s + "\n";
  unold = old + s;
  this->historique = unold;
}

void sauvegarde::sauvegarder(){
  string nom = "sauvegarde";
  time_t now = time(NULL);
  struct tm * tm = localtime(&now);
  nom = nom + ctime(&now);

  ofstream monFlux("../saves/"+nom);

  if(monFlux)  //On teste si tout est OK
  {
    monFlux << "#NOTE"<< "\n";
    monFlux << this->note<< "\n";
    monFlux << "#HISTORIQUE"<< "\n";
    monFlux << this->historique << "\n";
    monFlux << "#SYSTEME"<< "\n";
    monFlux << "p11 " << this->S_Save->getStatePompe("P11") << "\n"; // 4 char
    monFlux << "p11F " << this->S_Save->getFailureStatePompe("P11")<< "\n"; //5 char

    monFlux << "p12 " << this->S_Save->getStatePompe("P12")<< "\n";
    monFlux << "p12F " << this->S_Save->getFailureStatePompe("P12")<< "\n";

    monFlux << "p21 " << this->S_Save->getStatePompe("P21")<< "\n";
    monFlux << "p21F " << this->S_Save->getFailureStatePompe("P21")<< "\n";

    monFlux << "p22 " << this->S_Save->getStatePompe("P21")<< "\n";
    monFlux << "p22F " << this->S_Save->getFailureStatePompe("P21")<< "\n";

    monFlux << "p31 " << this->S_Save->getStatePompe("P31")<< "\n";
    monFlux << "p31F " << this->S_Save->getFailureStatePompe("P31")<< "\n";

    monFlux << "p32 " << this->S_Save->getStatePompe("P32")<< "\n";
    monFlux << "p32F " << this->S_Save->getFailureStatePompe("P32")<< "\n";

    monFlux << "t1 " << this->S_Save->getStateTank("T1")<< "\n";
    monFlux << "t2 " << this->S_Save->getStateTank("T2")<< "\n";
    monFlux << "t3 " << this->S_Save->getStateTank("T3")<< "\n";

    monFlux << "e1 " << this->S_Save->getStateEngine("E1")<< "\n";
    monFlux << "e2 " << this->S_Save->getStateEngine("E2")<< "\n";
    monFlux << "e3 " << this->S_Save->getStateEngine("E3")<< "\n";
    monFlux << "e1F " << this->S_Save->getFluxEngine("E1")<< "\n";
    monFlux << "e2F " << this->S_Save->getFluxEngine("E2")<< "\n";
    monFlux << "e3F " << this->S_Save->getFluxEngine("E3")<< "\n";

    monFlux << "vt12 " << this->S_Save->getStateVanne("V120")<< "\n";
    monFlux << "vt23 " << this->S_Save->getStateVanne("V230")<< "\n";

    monFlux << "v12 " << this->S_Save->getStateVanne("V12")<< "\n";
    monFlux << "v13 " << this->S_Save->getStateVanne("V13")<< "\n";
    monFlux << "v23 " << this->S_Save->getStateVanne("V23")<< "\n";

    monFlux.close();
  }
    else
  {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
  }
}
