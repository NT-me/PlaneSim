#include "vanne.hh"

using namespace std;

vanne::vanne(){
	id = 0;
	name = 'V'+id;
	state = 1;
	}
	
vanne::vanne(int id){
	this->id = id;
	name = 'V'+id;
	state = 1;
}

vanne::vanne(int id, bool state){
	this->id = id;
	name = 'V'+id;
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
