#include "Hoguera.h"

int Hoguera::idNextHoguera = 1;

Hoguera::Hoguera(string line) {
	int position = line.find(':');
	string name, timeString;
	
	for( int i=0; i < position; i++) {
		name += line[i];
	}


	for(unsigned int i=position+1; i < line.size(); i++) {
		timeString += line[i];
	}

	int time = stoi(timeString);

	id = Hoguera::idNextHoguera;
	Hoguera::idNextHoguera++;
	this -> name =  name;
	this -> time = time;
}

int
Hoguera::getTime() const {
	return time;
}

string
Hoguera::getTeam() const {
	return team;
}

void
Hoguera::setTime(int time) {
	this -> time = time;
}	

void
Hoguera::setTeam(string team) {
	this -> team = team;
}

ostream& operator<<(ostream &os, Hoguera &h) {
	os << h.name << " (" << h.id << ")=" << h.time << " ";

	return os;
}