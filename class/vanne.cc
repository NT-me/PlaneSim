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


vanne::vanne(int id, bool state, string G, string D){
	this->id = id;
	name = 'V'+id;
	this->state = state;
	this->G = G;
	this->D = D;
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

string vanne::getG(){
	return this->G;
}

string vanne::getD(){
	return this->D;
}

void vanne::setG(string item){
	this->G = item;
}

void vanne::setD(string item){
	this->D = item;
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
