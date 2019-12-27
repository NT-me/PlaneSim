#include "vanne.hh"

using namespace std;

// constructeur

vanne::vanne(){
	id = 0;
	name = 'V'+to_string(id);
	state = 1;
	}

vanne::vanne(int id){
	this->id = id;
	name = 'V'+ to_string(id);
	state = 1;
}

vanne::vanne(int id, bool state){
	this->id = id;
	name = 'V'+ to_string(id);
	this->state = state;
}


vanne::vanne(int id, bool state, string G, string D){
	this->id = id;
	name = 'V' + to_string(id);
	this->state = state;
	this->G = G;
	this->D = D;
}

// destructeur

vanne::~vanne(){
	delete this;
}

// getter

string vanne::getName(){
	return this->name;
}

int vanne::getId(){
	return this->id;
}

bool vanne::getState(){
	return this->state;
}

string vanne::getG(){
	return this->G;
}

string vanne::getD(){
	return this->D;
}

// setter

void vanne::setG(string item){
	this->G = item;
}

void vanne::setD(string item){
	this->D = item;
}

void vanne::setState(bool b){
	this->state = b;
}

void vanne::changeState(){
	if (this->getState() == true){
		this->setState(false);
	}
	else{
		this->setState(true);
	}
}

// operateur
vanne & vanne::operator=(const vanne &v){
  if (this==&v){
    return *this;
  }

  this->name = v.name;
  this->id = v.id;
  this->state = v.state;

  return *this;
}
