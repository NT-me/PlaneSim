#include "engine.hh"

using namespace std;

//constructeur

engine::engine(){
	id = 0;
	name = "E" + to_string(id);
	state = 1;
}

engine::engine(int id){
	this->id = id;
	name = "E" + to_string(id);
	state = 1;
}

engine::engine(int id, bool state){
	this->id = id;
	name = "E" + to_string(id);
	this->state = state;
}

engine::engine(int id, bool state, string f){
	this->id = id;
	name = "E" + to_string(id);
	this->state = state;
	this->flux = f;
}

// destructeur

engine::~engine(){
	delete this;
}

// getter

string engine::getName(){
	return this->name;
}

int engine::getId(){
	return this->id;
}

bool engine::getState(){
	return this->state;
}

string engine::getFlux(){
	return this->flux;
}

// Setter
void engine::setState(bool b){
	this->state = b;
}

void engine::setFlux(string f){
	this->flux = f;
}

// operateur

engine & engine::operator=(const engine &e){
  if (this==&e){
    return *this;
  }

  this->name = e.name;
  this->id = e.id;
  this->state = e.state;

  return *this;
}
