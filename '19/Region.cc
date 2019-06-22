#include "Region.h"

Region::Region(string name) {
	this -> name = name;

}

bool 
Region::addStation(string filename) {
	bool notError = true;
	int position = -1;

	try {
		Station s(filename);

		for(unsigned int i=0; i<stationVector.size(); i++) { // Search same name
			if(s.getName() == stationVector[i].getName()) {
				position = i;
			}
		}

		if(position != -1) { // No se como hacerlo para que no cambie de valor el id porque
												 // data es un valor privado que no se puede modificar si no se crea
												 // una función especifica para ello 

			stationVector.erase(stationVector.begin() + position);
			stationVector.push_back(s);

		} else {
			stationVector.push_back(s); // Add station to Region
		}

	} catch(Error e) {
		if(e == ERR_FILE) {
			cout << "Error opening file" << endl;
			notError = false;												// Case file can't open
		}
	}

	return notError;
}

int 
Region::findStation(string name) const { // Search Station in Region
	int position = -1;

	for(unsigned int i=0; i<stationVector.size(); i++) {
		if(stationVector[i].getName() == name) {
			position = i;
		}
	}

	if(position == -1) {
		cout << "Wrong station name" << endl;
	}

	return position;
}

float 
Region::getAvgTemp(Month m) const { // Return avg of a month Temperature
	float sum;

	for(unsigned int i=0; i<stationVector.size(); i++) {
		sum += stationVector[i].getValue(T, m);
	}

	int avg = sum/stationVector.size();
	return avg;
}

string
Region::getWarmestStation(Month m) const { // Return max Temperature of a introduced month
	string stationName;
	float value = 0;

	for(unsigned int i=0; i< stationVector.size(); i++) {
		if(stationVector[i].getValue(TM, m) > value) {
			value = stationVector[i].getValue(TM, m);
			stationName = stationVector[i].getName();
		}
	}

	return stationName;
}

float
Region::getValue(string name, Value v, Month m) const { 
	int position = Region::findStation(name);

	if(position != -1) {
		float value = stationVector[position].getValue(v, m);
		return value;
	} else {
		return -1.0;
	}
}