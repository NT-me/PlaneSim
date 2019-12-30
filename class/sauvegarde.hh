#include <cstring>
#include <iostream>
#include "systeme.hh"

using namespace std;

class sauvegarde{
  /*
    L'objet sauvegarde permet d'enrengistrer l'historique et la note.
  */
  private:
    int note; // entre 0 et 10
    string historique;
    systeme S_Save;

  public:

    sauvegarde();

    ~sauvegarde();

    // getters
    int getNote();
    string getHistorique();
    systeme getSsave();

    // setters
    void setNote(int n);
    void setHistorique(string h);
    void setSsave(systeme s);


};
