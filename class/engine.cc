#include "engine.hh"

using namespace std;

engine::engine(){
	id = 0;
	name = "E"+id;
	state = 1;
}

engine::engine(int id){
	this->id = id;
	name = "E"+id;
	state = 1;
}

engine::engine(int id, bool state){
	this->id = id;
	name = 'E'+id;
	this->state = state;
}

engine::~engine(){
	delete this;
}

string engine::getName(){
	return this->name;
}

int engine::getId(){
	return this->id;
}

bool engine::getState(){
	return this->state;
}

pompe & engine::operator=(const engine &e){
  if (this==&e){
    return *this;
  }

  this->name = p.name;
  this->id = p.id;
  this->state = p.state;

  return *this;
}
