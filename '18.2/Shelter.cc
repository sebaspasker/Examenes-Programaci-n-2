#include "Shelter.h"

Shelter::Shelter(string name) {
	this -> name = name;
}

int
Shelter::search(const Animal &a) const{
	int position = -1;

	for(unsigned int i=0; i < animalVector.size(); i++) {
		if(a.getName() == animalVector[i].getName() && a.getAnimalType() && animalVector[i].getAnimalType()) {
			position = i;
		}
	}

	return position;
}

bool 
Shelter::add(const Animal &a) {
	int repetition = Shelter::search(a);
	bool added = false;

	if(repetition == -1) {
		animalVector.push_back(a);
		added = true;
	}

	return added;
}

bool
Shelter::adopt(const Animal &a, string owner) {
	bool adopted = false;
	int positionAnimal = Shelter::search(a);

	if(positionAnimal != -1) {
		if(!animalVector[positionAnimal].isAdopted()) {
			bool valid = Shelter::ownerIsValid(owner);
			if(valid) {
				animalVector[positionAnimal].adopt(owner);
				adopted = true;
			}
		}
	}

	if(adopted == false) {
		cout << "<" << a.getName() << "> cannot be adopted " << endl;
	}

	return adopted;
}

bool
Shelter::ownerIsValid(string owner) const {
	int adopted = 0;
	bool valid = true;
	for(unsigned int i=0; i < animalVector.size(); i++) {
		if(owner == animalVector[i].getOwner()) {
			adopted++;
		}
	}

	if(adopted == MAXADOPTED) {
		valid = false;
	}

	return valid;
}

ostream& operator<< (ostream &os, Shelter &s) {
	os << "------ Adopted -------" << endl;

	for(unsigned int i=0; i < s.animalVector.size(); i++) {
		if(s.animalVector[i].isAdopted()) {
			os << s.animalVector[i] << endl;
		}
	}
	os << "------ Not Adopted -------" << endl;

	for(unsigned int i=0; i < s.animalVector.size(); i++) {
		if(!s.animalVector[i].isAdopted()) {
			os << s.animalVector[i] << endl;
		}
	}

	return os;
}