#include "Station.h"

unsigned int Station::nextId = 0;

Station::Station(string filename) {
	ifstream stationFile(filename.c_str());
	string fileLine;
	bool firstEntrance = true;
	int month = 0, value = 0, firstValue;
	string valueS;

	if(stationFile.is_open()) {

		while(getline(stationFile, fileLine)) {
			if(firstEntrance == true) { // Save station name
				name = fileLine;
				firstEntrance = false; 

			} else {
				firstValue = fileLine.find(' ');

				for(unsigned int i=firstValue+1; i<fileLine.size(); i++) {
					if(value == 0 && fileLine[i] != ' ') {
						valueS += fileLine[i];
					} else if(value == 0 && fileLine[i] == ' ') { // Save value T
						data[value][month] = atof(valueS.c_str());
						valueS.clear();
						value++;
					} else if(value == 1 && fileLine[i] != ' ') {
						valueS += fileLine[i];
					} else if(value == 1 && fileLine[i] == ' ') { // Save value TM
						data[value][month] = atof(valueS.c_str());
						valueS.clear();
						value++;
					} else if(value == 2 && fileLine[i] != ' ') { 
						valueS += fileLine[i];
					}
				}
				data[value][month] = atoi(valueS.c_str());			// Save value Tm
				valueS.clear();
				value = 0;
				month++;
			}
		}

		stationFile.close();
	} else {
		throw ERR_FILE;
	}

	id = Station::nextId;
	Station::nextId++; 		// Asign id
}

float 
Station::getValue(Value v, Month m) const {
		return data[v][m];
}

string 
Station::getName() const {
	return name;
}

ostream& operator<<(ostream &os, const Station &s) {

	os << s.name << "(" << s.id << ")" << endl;
	return os;
}