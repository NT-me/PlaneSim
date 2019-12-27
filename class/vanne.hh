#include <cstring>
#include <iostream>

using namespace std;

class vanne{
  /*
  Les vannes sont soit ouvertes, soit fermées
  */
private:
  string name;
  int id;
  bool state; // 1 si ouverte, 0 si fermée
  string G; // nom composant se trouvant à gauche de la vanne
  string D; // nom composant se trouvant à droit de la vanne

public:
  // Constructeur
  vanne();
  vanne(int id);
  vanne(int id, bool state);
  vanne(int id, bool state, string G, string D);

  // Destructeur
  ~vanne();

  // Getter & setter
  string getName();
  int getId();
  bool getState();
  string getG();
  string getD();

  void setG(string item);
  void setD(string item);
  void setState(bool b);

  void changeState();


  // Operateur
  vanne & operator=(const vanne &t);
};
