#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

const char CONST_TROOP_FILE[30] = "Troops.dat";
const char CONST_LOSSES_FILE[30] = "losses.txt";

struct Troops {
	char family[40];
	char type[20];
	unsigned int units;
};

vector<Troops> troopsExtraction(bool &fileError) {
	ifstream troopsFile(CONST_TROOP_FILE, ios::binary);
	vector<Troops> extractedTroops;
	Troops troop;

	if(troopsFile.is_open()) {

		// Messure size of file
		troopsFile.seekg(0, ios::end);
		int lengthTroops = troopsFile.tellg()/sizeof(Troops);
		troopsFile.seekg(0, ios::beg);

		// Extract troops from file
		for(int i=0; i<lengthTroops; i++) {
			troopsFile.read((char *)&troop, sizeof(Troops));
			extractedTroops.push_back(troop);
		}

		troopsFile.close();
	} else {
		fileError = true;
	}

	return extractedTroops;
}

vector<Troops> searchLossedTroops(string fileLine) {
	vector<Troops> lossedTroops;
	Troops Ltroop;
	int process = 0; // 0 --> family, 1 --> type, 2 --> units and reset
	string family, type, units;

	int jump = fileLine.find("|"); // Jump location

	for(unsigned int i=jump+1; i<fileLine.size(); i++) {

		if(process == 0 && fileLine[i] != '-') {
			family += fileLine[i];
		} else if(process == 0 && fileLine[i] == '-') {
			strcpy(Ltroop.family, family.c_str());
			process++;
			family.clear();
		} else if(process == 1 && fileLine[i] != ':') {
			type += fileLine[i];
		} else if(process == 1 && fileLine[i] == ':') {
			strcpy(Ltroop.type, type.c_str());
			process++;
			type.clear();
		} else if(process == 2 && fileLine[i] != '|') {
			units += fileLine[i];
		} else if(process == 2 && fileLine[i] == '|') {
			Ltroop.units = atoi(units.c_str());
			units.clear();
			lossedTroops.push_back(Ltroop);
			process = 0;
		}
	}

	return lossedTroops;
}

int searchRepetition(Troops T,vector<Troops> troops) {
	int position = -1;
	for(unsigned int i=0; i<troops.size(); i++) {
		if(strcmp(T.family, troops[i].family) == 0 
			&& strcmp(T.type, troops[i].type) == 0
			&& T.units <= troops[i].units) { // Case same family and type and units are infer of general units

			position = i;
		}
	}

	return position;
}

void restTroops(vector<Troops> &troops, vector<Troops> lossedTroops) {
	Troops T;
	int position;

	for(unsigned int i=0; i<lossedTroops.size(); i++) {
		T = lossedTroops[i];
		position = searchRepetition(T, troops); // Search a repetition in troops and save position

		if(position != -1) {
			troops[position].units = troops[position].units - T.units; // Rest units

		} else {
			cout << "Error wrong troops" << endl;
		}

		position = -1;
	}
}

void lossesExtraction(bool &fileError, vector<Troops> &troops) {
	ifstream fileLosses(CONST_LOSSES_FILE);
	vector<Troops> lossedTroops;
	vector<Troops> newTroops;

	if(fileLosses.is_open()) {
		string fileLine;
		
		while(getline(fileLosses, fileLine)) {
			lossedTroops = searchLossedTroops(fileLine); // Search troops in battle
			restTroops(troops, lossedTroops); // Rest lossed troops of general Troops

		}

		fileLosses.close();
	} else {
		fileError = true;
	}
}

vector<Troops> unitTroops(vector<Troops> troops) {
	bool repetition = false;

	vector<Troops> troopsUnited;
	Troops T;

	for(unsigned int i=0; i<troops.size(); i++) { 
		if(i==0) {
			strcpy(T.family, troops[i].family);
			strcpy(T.type, troops[i].type);
			T.units = 0;

			troopsUnited.push_back(T);
		} if(i!=0) {
			for(unsigned int j=0; j<troopsUnited.size(); j++) {
				if(strcmp(troopsUnited[j].family, troops[i].family) == 0 
					&& strcmp(troopsUnited[j].type, troops[i].type) == 0 )
					repetition = true;
			} 

			if(repetition == false) {
				strcpy(T.family, troops[i].family);
				strcpy(T.type, troops[i].type);
				T.units = 0;
				troopsUnited.push_back(T);
			}
			repetition = false;
		}
	} // Save names and type in a new vector

	for(unsigned int i=0; i<troopsUnited.size(); i++) {
		for(unsigned int j=0; j<troops.size(); j++) {
			if(strcmp(troopsUnited[i].family, troops[j].family) == 0
				&& strcmp(troopsUnited[i].type, troops[j].type) == 0) {
				troopsUnited[i].units += troops[j].units;
			}
		}
	} // Add units add at each troop

	return troopsUnited;
}

vector<Troops> TroopDivision(vector<Troops> unitedTroops) {
	Troops T, T50, Tmixed;
	vector<Troops> troopsDivided;

	strcpy(Tmixed.family, "Mixed");
	Tmixed.type[0] = '\0';
	Tmixed.units = 0;


	for(unsigned int i=0; i<unitedTroops.size(); i++) {
		T = unitedTroops[i];

		while(T.units != 0) {

			if(T.units >= 50) { // 50 division
				strcpy(T50.family, T.family);
				strcpy(T50.type, T.type);
				T50.units = 50;
				T.units -= 50;
				troopsDivided.push_back(T50);

			} else if(T.units >= 30) { // >30 division
				strcpy(T50.family, T.family);
				strcpy(T50.type, T.type);
				T50.units = T.units;
				T.units = 0;
				troopsDivided.push_back(T50);

			} else if(T.units > 0) { // <30 && > 0 division ---> mixed troup
				Tmixed.units += T.units;
				T.units = 0;
			}
		}

	}
	if(Tmixed.units != 0)
		troopsDivided.push_back(Tmixed);	

	return(troopsDivided);
}	

void printTroops(vector<Troops> troops) { // Print troops

	for(unsigned int i=0; i<troops.size(); i++) {
		if(strcmp(troops[i].family, "Mixed") != 0) {
			cout << i << ". " << troops[i].family << "|" << troops[i].type << "|" << troops[i].units << endl;
		} else {
			cout << i << ". " << troops[i].family << "|" << troops[i].units << endl;
		}

	}
}

int main() {
	bool fileError = false;

	// Extract troops from file
	vector<Troops> troops = troopsExtraction(fileError), troopsUnited;

	vector<Troops> unitedTroops = unitTroops(troops);

	if(fileError == false) {

		lossesExtraction(fileError, unitedTroops);

		if(fileError == false) {
			vector<Troops> troopsDivided = TroopDivision(unitedTroops);
			printTroops(troopsDivided);

		} else {
			cout << "File Error, can't open" << endl;
		}
	} else {
		cout << "File Error, can't open" << endl;
	}
}

// CODIGO PARA GUARDAR EN TROOPS.DAT

	/*
	strcpy(t.family, "Gonzalez");
	strcpy(t.type, "caballeria");
	t.units = 200;

	troopsVector.push_back(t);


	strcpy(t.family, "Gonzalez");
	strcpy(t.type, "caballeria");
	t.units = 10;

	troopsVector.push_back(t);

	strcpy(t.family, "Gonzalez");
	strcpy(t.type, "caballeria");
	t.units = 50;

	troopsVector.push_back(t);

	strcpy(t.family, "Pasker");
	strcpy(t.type, "escudero");
	t.units = 34;

	troopsVector.push_back(t);

	strcpy(t.family, "Gonzalez");
	strcpy(t.type, "caballeria");
	t.units = 32442;

	troopsVector.push_back(t);

	strcpy(t.family, "Pasker");
	strcpy(t.type, "escudero");
	t.units = 123;

	troopsVector.push_back(t);

	strcpy(t.family, "Gonzalez");
	strcpy(t.type, "escudero");
	t.units = 32;


	troopsVector.push_back(t);

	strcpy(t.family, "Gomez");
	strcpy(t.type, "caballeria");
	t.units = 200;

	troopsVector.push_back(t);

	for(unsigned int i=0; i < troopsVector.size(); i++) {
		troopsFile.write((const char *)&troopsVector[i], sizeof(Troops));
}*/


