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
  string tps;
  time_t now = time(NULL);
  struct tm * tm = localtime(&now);

  tps = to_string(tm->tm_hour) + ":" + to_string(tm->tm_min) + ":" + to_string(tm->tm_sec);

  old = this->historique;
  s = "[" + tps + "]" + s + "\n";
  unold = old + s;
  this->historique = unold;
}

void sauvegarde::sauvegarder(){
  string nom = "sauvegarde";
  time_t now = time(NULL);
  struct tm * tm = localtime(&now);
  nom = nom + to_string(tm->tm_hour) + ":" + to_string(tm->tm_min) + ":" + to_string(tm->tm_sec);

  ofstream monFlux("../saves/"+nom+".save");

  if(monFlux)  //On teste si tout est OK
  {
    monFlux << "#NOTE"<< "\n";
    monFlux << this->note<< "\n";
    monFlux << "#HISTORIQUE"<< "\n";
    monFlux << this->historique << "\n";
    monFlux << "#SYSTEME"<< "\n";
    monFlux << ";" << this->S_Save->getStatePompe("P11") << "p11 " << "\n"; // 4 char
    monFlux << ";" << this->S_Save->getFailureStatePompe("P11") << "p11F "<< "\n"; //5 char

    monFlux << ";" << this->S_Save->getStatePompe("P12") << "p12 "<< "\n";
    monFlux << ";" << this->S_Save->getFailureStatePompe("P12")<< "p12F "<< "\n";

    monFlux << ";" << this->S_Save->getStatePompe("P21") << "p21 " << "\n";
    monFlux << ";" << this->S_Save->getFailureStatePompe("P21")<< "p21F " << "\n";

    monFlux << ";" << this->S_Save->getStatePompe("P22")<< "p22 " << "\n";
    monFlux << ";" << this->S_Save->getFailureStatePompe("P22")<< "p22F "<< "\n";

    monFlux << ";" << this->S_Save->getStatePompe("P31")<< "p31 "<< "\n";
    monFlux << ";" << this->S_Save->getFailureStatePompe("P31")<< "p31F "<< "\n";

    monFlux << ";" << this->S_Save->getStatePompe("P32")<< "p32 "<< "\n";
    monFlux << ";" << this->S_Save->getFailureStatePompe("P32")<< "p32F "<< "\n";

    monFlux << ";" << this->S_Save->getStateTank("T1")<< "t1 "<< "\n";
    monFlux << ";" << this->S_Save->getStateTank("T2")<< "t2 "<< "\n";
    monFlux << ";" << this->S_Save->getStateTank("T3")<< "t3 "<< "\n";

    monFlux << ";" << this->S_Save->getStateEngine("E1") << "e1 "<< "\n";
    monFlux << ";" << this->S_Save->getStateEngine("E2") << "e2 "<< "\n";
    monFlux << ";" << this->S_Save->getStateEngine("E3") << "e3 "<< "\n";
    monFlux << ";" << this->S_Save->getFluxEngine("E1") << "e1F " << "\n";
    monFlux << ";" << this->S_Save->getFluxEngine("E2") << "e2F "<< "\n";
    monFlux << ";" << this->S_Save->getFluxEngine("E3") << "e3F "<< "\n";

    monFlux << ";" << this->S_Save->getStateVanne("V120") << "vt12 "<< "\n";
    monFlux << ";" << this->S_Save->getStateVanne("V230") << "vt23 "<< "\n";

    monFlux << ";" << this->S_Save->getStateVanne("V12") << "v12 "<< "\n";
    monFlux << ";" << this->S_Save->getStateVanne("V13") << "v13 "<< "\n";
    monFlux << ";" << this->S_Save->getStateVanne("V23") << "v23 "<< "\n";

    monFlux.close();
  }
    else
  {
    cerr << "Error: " << strerror(errno) << endl;
  }
}

bool char_to_bool(char c){
  if(c == '1'){
    return true;
  }
  else if (c == '0'){
    return false;
  }
  return false;
}

string two_first_char(string l){
  string res = "";
  res=res+l[0];
  res=res+l[1];

  return res;
}

void sauvegarde::load(string filename){
  ifstream monFlux("../saves/"+filename+".save");  //Ouverture d'un fichier en lecture

  this->historique = "";

  // Création des pompes
  pompe* p11 = new pompe(11, true, 'N');
  pompe* p12 = new pompe(12, false, 'S');

  pompe* p21 = new pompe(21, true, 'N');
  pompe*p22 = new pompe(22, false, 'S');

  pompe*p31 = new pompe(31, true, 'N');
  pompe*p32 = new pompe(32, false, 'S');

  // Création des réservoirs
  tank* t1 = new tank(1, true, p11, p12);
  tank* t2 = new tank(2, true, p21, p22);
  tank* t3 = new tank(3, true, p31, p32);

  // Création des moteurs
  engine* e1 = new engine(1, true, "T1");
  engine* e2 = new engine(2, true, "T2");
  engine* e3 = new engine(3, true, "T3");

  // Création des vannes
  vanne* vt12 = new vanne(120, false, "T1", "T2");
  vanne* vt23 = new vanne(230, false, "T2", "T3");

  vanne* v12 = new vanne(12, false, "T1", "E2");
  vanne* v13 = new vanne(13, false, "T1", "E3");
  vanne* v23 = new vanne(23, false, "T2", "E3");

  int inc = 0;

 if(monFlux)
   {
      //L'ouverture s'est bien passée, on peut donc lire
      string ligne;

    while(getline(monFlux, ligne)) //Tant qu'on n'est pas à la fin, on lit
    {
      if (ligne[0] == '#' & ligne[1] == 'N'){
        // Lit NOTE
        int n;
        monFlux >> n;
        this->note = n;
      }
      else if (ligne[0] == '['){
        this->historique = this->historique + ligne + "\n";
      }
      else if (ligne[0] == ';'){

        switch(inc){
          case 0: p11->setState(char_to_bool(ligne[1]));
          case 1: p11->setFailureState(char_to_bool(ligne[1]));
          case 2: p12->setState(char_to_bool(ligne[1]));
          case 3: p12->setFailureState(char_to_bool(ligne[1]));
          case 4: p21->setState(char_to_bool(ligne[1]));
          case 5: p21->setFailureState(char_to_bool(ligne[1]));
          case 6: p22->setState(char_to_bool(ligne[1]));
          case 7: p22->setFailureState(char_to_bool(ligne[1]));
          case 8: p31->setState(char_to_bool(ligne[1]));
          case 9: p31->setFailureState(char_to_bool(ligne[1]));
          case 10: p32->setState(char_to_bool(ligne[1]));
          case 11: p32->setFailureState(char_to_bool(ligne[1]));
          case 12: t1->setState(char_to_bool(ligne[1]));
          case 13: t2->setState(char_to_bool(ligne[1]));
          case 14: t3->setState(char_to_bool(ligne[1]));
          case 15: e1->setState(char_to_bool(ligne[1]));
          case 16: e2->setState(char_to_bool(ligne[1]));
          case 17: e3->setState(char_to_bool(ligne[1]));
          case 18: e1->setFlux(two_first_char(ligne));
          case 19: e2->setFlux(two_first_char(ligne));
          case 20: e3->setFlux(two_first_char(ligne));
          case 21: vt12->setState(char_to_bool(ligne[1]));
          case 22: vt23->setState(char_to_bool(ligne[1]));
          case 23: v12->setState(char_to_bool(ligne[1]));
          case 24: v13->setState(char_to_bool(ligne[1]));
          case 25: v23->setState(char_to_bool(ligne[1]));
        }
        inc = inc + 1;
      }

    }
   }
   else
   {
      cerr << "Error: " << strerror(errno) << endl;
   }
   systeme* S_sa = new systeme(p11, p12, p21, p22, p31, p32, t1, t2, t3, vt12, vt23, v12, v13, v23, e1, e2, e3);
   this->S_Save = S_sa;


}
