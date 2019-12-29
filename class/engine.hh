#include <cstring>
#include <iostream>

using namespace std;

class engine{
  /*
  Le Moteur est soit en fonctionnement normal soit en panne.
  */
private:
  string name;
  int id;
  bool state; // 1 si tout est normal, 0 sinon

public:
  // Constructeur
  engine();
  engine(int id);
  engine(int id, bool state);

  // Destructeur
  ~engine();

  //Getter & setter
  string getName();
  int getId();
  bool getState();

  void setState(bool b);

  // Opérateurs
  engine &operator=(const engine &e);
};
