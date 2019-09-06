#include "Planet.h"

Planet::Planet(string name, string sector, string coord) {
	this-> name = name;
	this -> sector = sector;
	letter = coord[0];

	string number;

	for(unsigned int i=1; i < coord.size(); i++) {
		number += coord[i];
	}	

	this -> number = atoi(number.c_str());
}

float 
Planet::distance(const Planet &p) const {
	float distance = 100*abs(letter - p.letter) + abs(number - p.number);

	return distance;
}

ostream& operator<<(ostream &os, const Planet &p) {
	os << p.name << " (" << p.sector << ") ," << p.letter << p.number << endl;
	return os;
}