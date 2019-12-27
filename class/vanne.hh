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

public:
  // Constructeur
  vanne();
  vanne(int id);
  vanne(int id, bool state);

  // Destructeur
  ~vanne();

  // Getter & setter
  string getName();
  int getId();
  bool getState();
  
  // Operateur
  vanne & operator=(const vanne &t);
};
