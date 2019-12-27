#include "vanne.hh"

using namespace std;

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

vanne::~vanne(){
	delete this;
}


string vanne::getName(){
	return this->name;
}

int vanne::getId(){
	return this->id;
}

bool vanne::getState(){
	return this->state;
}

vanne & vanne::operator=(const vanne &v){
  if (this==&v){
    return *this;
  }

  this->name = v.name;
  this->id = v.id;
  this->state = v.state;

  return *this;
}
