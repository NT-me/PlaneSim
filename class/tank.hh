#include <cstring>
#include <iostream>
#include "pompe.hh"

using namespace std;

class tank{
  /*
  Un réservoir peut être plein ou vide
  */
private:
  string name;
  int id;
  bool state; // 1 si plein, 0 sinon
  pompe *normal;
  pompe *secours;

public:
  // Constructeur
  tank();
  tank(int id);
  tank(int id, bool state);
  tank(int id, bool state, pompe pN, pompe pS);

  // Destructeur
  ~tank();

  //Getter & setter
  string getName();
  int getId();
  bool getState();
  
  // Operateur
  tank & operator=(const tank &t);
};

