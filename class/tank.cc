#include "tank.hh"

using namespace std;

tank::tank(){
	id = 0;
	name = 'T'+ to_string(id);
	state = true;
	normal = new pompe();
	secours = new pompe();
	}

tank::tank(int id){
	this->id = id;
	name = 'T'+ to_string(id);
	state = true;
	normal = new pompe();
	secours = new pompe();
}

tank::tank(int id, bool state){
	this->id = id;
	name = 'T'+ to_string(id);
	this->state = state;
	normal = new pompe();
	secours = new pompe();
}

tank::tank(int id, bool state, pompe pN, pompe pS){
	this->id = id;
	name = 'T'+ to_string(id);
	this->state = state;
	normal  = &pN;
	secours = &pS;
}

tank::~tank(){
delete this;
}

string tank::getName(){
	return this->name;
}

int tank::getId(){
	return this->id;
}

bool tank::getState(){
	return this->state;
}

tank & tank::operator=(const tank &t){
  if (this==&t){
    return *this;
  }

  this->name = t.name;
  this->id = t.id;
  this->state = t.state;
  this->normal = t.normal;
  this->secours = t.secours;

  return *this;
}
