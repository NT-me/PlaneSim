#include "tank.hh"

using namespace std;

// constructeur

tank::tank(){
	id = 0;
	name = 'T'+ to_string(id);
	state = true;
	pompage = true;
	normal = new pompe();
	secours = new pompe();
	}

tank::tank(int id){
	this->id = id;
	name = 'T'+ to_string(id);
	state = true;
	pompage = true;
	normal = new pompe();
	secours = new pompe();
}

tank::tank(int id, bool state){
	this->id = id;
	name = 'T'+ to_string(id);
	this->state = state;
	this->pompage = true;
	normal = new pompe();
	secours = new pompe();
}

tank::tank(int id, bool state, pompe *pN, pompe *pS){
	this->id = id;
	name = 'T'+ to_string(id);
	this->state = state;
	normal  = pN;
	secours = pS;
	if (pN->getState() | pS->getState()){
		this->pompage = true;
	}
	else{
		this->pompage = false;
	}
}

// destructeur

tank::~tank(){
	delete this->normal;
	delete this->secours;
	delete this;
}

//getter

string tank::getName(){
	return this->name;
}

int tank::getId(){
	return this->id;
}

bool tank::getState(){
	return this->state;
}

pompe* tank::getNormal(){
	return this->normal;
}

pompe* tank::getSec(){
  return this->secours;
  }

bool tank::getPompage(){
	return this->pompage;
}


//

void tank::dump(){
	if (this->getState()){
		this->state = 0;
	}
}

void tank::setPompage(bool b){
	this->pompage = b;
}

void tank::setState(bool b){
	this->state = b;
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
