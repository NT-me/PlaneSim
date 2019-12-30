#include "sauvegarde.hh"

using namespace std;

sauvegarde::sauvegarde(){
  this->historique = "Début historique \n";
  this->note = 0;
  this->S_Save = systeme S;
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

systeme sauvegarde::getSsave(){
  return this->S_Save;
}

void sauvegarde::setNote(int n){
  this->note = n;
}

void sauvegarde::setHistorique(string h){
  this->historique = h;
}

void sauvegarde::setSsave(systeme s){
  this->S_Save = s;
}
