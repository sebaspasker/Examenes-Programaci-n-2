#include "Animal.h"

Animal::Animal(string s) {
	string nombre, tipo, stringEdad;
	int process = 0;
	for(unsigned int i=0; i <s.size(); i++) {
		if(process == 0 && s[i] == ',') {
			process = 1;
		} else if(process == 0) {
			nombre += s[i];
		} else if(process == 1 && s[i] == ',') {
			process = 2;
		} else if(process == 1) {
			tipo += s[i];
		} else if(process == 2) {
			stringEdad += s[i];
		} else {
			throw ERROR_PARAM;
		}
	}

	if(process == 2) {
		age = stoi(stringEdad);
		name = nombre;
		if(tipo == "Cat") {
			this ->type = Cat;
		} else if(tipo == "Dog") {
			this -> type = Dog;
		} if(tipo == "Jerbo") {
			this ->type = Jerbo;
		} else if (tipo != "Cat" && tipo != "Dog" && tipo != "Jerbo") {
			throw tipo;
		}

	} else {
		throw ERROR_PARAM;
	}
}

string Animal::getName() const {
	return name;
}

unsigned int Animal::getAge() const {
	return age;
}

AnimalType Animal::getAnimalType() const {
	return type;
}

string Animal::getOwner() const {
	return owner;
}


void Animal::adopt(string owner) {
	this  -> owner = owner;
}

bool Animal::isAdopted() const {
	bool adopted;

	if(owner.empty()) {
		adopted = false;
	} if(!owner.empty()) {
		adopted = true;
	}

	return adopted;
}

ostream& operator<< (ostream &os, Animal &a) {
	os << a.name << ", age=" << a.age << "";

	if(!a.owner.empty()) {
		os << ", owner=" << a.owner;
	}

	return os;
}


