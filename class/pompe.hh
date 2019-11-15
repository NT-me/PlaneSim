#include <cstring>
#include <iostream>

using namespace std;

class pompe{
  /*
  Les pompes sont soit en marche, soit éteinte, soit en panne
  */
private:
  string name;
  int id;
  char type; // S pour secours ou N pour normal
  bool state; // 1 si allumée, 0 si éteinte
  bool failure; // 1 si en panne, 0 sinon

public:
  // Constructeur
  pompe();
  pompe(const pompe &p);
  pompe(int id);
  pompe(int id, bool state);
  pompe(int id, bool state, char type);

  // Destructeur
  ~pompe();

  //Getter & setter
  string getName();
  int getId();
  bool getSate();
  bool getFailureState();

  // Opérateurs
  pompe &operator=(const pompe &p);
};
