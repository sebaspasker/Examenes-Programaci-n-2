#include "Route.h"

Route::Route(string name, const Planet &origin) {
	this -> name = name;
	planetVector.push_back(origin);
}



int 
Route::closest(const Planet &p) const {
	int positionClosest, valueClosest;

	if(!planetVector.empty()) {
		positionClosest = 0;
		valueClosest = planetVector[0].distance(p);

		for(unsigned int i=1; i<planetVector.size(); i++) {
			if(valueClosest > planetVector[i].distance(p)) {
				valueClosest = planetVector[i].distance(p);
				positionClosest = i;
			}
		}

		return positionClosest;

	} else {
		return -1;

	}
} 	

void
Route::addPlanet(const Planet &p) {
	int position = Route::closest(p);

	if(position >= 0) {
		unsigned int unsignedPosition = position;
		vector<Planet> newPlanetVector;
		for(unsigned int i=0; i < planetVector.size(); i++) {
			if(i == unsignedPosition+1) {
				newPlanetVector.push_back(p);
			}

			newPlanetVector.push_back(planetVector[i]);
		}

		planetVector = newPlanetVector;

	} else  {
		planetVector.push_back(p);
	}
}

void
Route::setName(string name) {
	this-> name = name;
}

string 
Route::setName() const {
	return name;
}

ostream& operator<<(ostream &os, Route &r) {
	os << r.name << endl;
	os << "----------" << endl;

	for(unsigned int i=0; i<r.planetVector.size(); i++) {
		os << r.planetVector[i];
	}

	return os;
}