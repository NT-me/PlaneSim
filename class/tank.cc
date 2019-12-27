#include "tank.hh"

using namespace std;

tank::tank(){
	id = 0;
	name = 'M'+id;
	state = true;
	normal = pompe();
	secours = pompe();
	}
	
tank::tank(int id){
	this->id = id;
	name = 'M'+id;
	state = true;
	normal = pompe();
	secours = pompe();
}

tank::tank(int id, bool state){
	this->id = id;
	name = 'M'+id;
	this->state = state;
	normal = pompe();
	secours = pompe();
}

tank::tank(int id, bool state, pompe pN, pompe pS){
	this->id = id;
	name = 'M'+id;
	this->state = state;
	normal = pN;
	secours = pS;
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
