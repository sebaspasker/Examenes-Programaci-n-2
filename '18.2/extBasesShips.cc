#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

// Modificado, posicion 1 primera posición en vez de cero

struct RegBin {
	char name[15];
	int p;
	int e;
	double x;
	double y;
};

struct RegBaseoShip {
	string name;
	int pos;
};

vector<RegBin> extractionFile(string fileName, vector<RegBaseoShip> referenceVector) {
	ifstream binFile(fileName, ios::binary);
	RegBin bin;
	vector<RegBin> vectorBin;

	if(binFile.is_open()) {

		
		for(unsigned int i=0; i < referenceVector.size(); i++) {
			binFile.seekg(referenceVector[i].pos*sizeof(RegBin), ios::beg);
			binFile.read((char*)&bin, sizeof(RegBin));
			if(bin.name == referenceVector[i].name){
				vectorBin.push_back(bin);
			} else {
				cout << "Error line " << referenceVector[i].pos << ": name " << '"' << referenceVector[i].name << '"' << " does not match with binary file (name=" << '"' << bin.name << '"' << ")" << endl;
			}
		}
		binFile.close();
	}
	
	return vectorBin;
}

void writeFile(string tipo, vector<RegBin> referenceVector) {
	string nameFile, passToString;

	if(tipo == "Base") {
		nameFile = "Base.txt";
	} else {
		nameFile = "Ship.txt";
	}

	ofstream writeFile(nameFile);

	if(writeFile.is_open()) {
		for(unsigned int i=0; i<referenceVector.size(); i++) {
			if(tipo == "Ship") {
				writeFile << '(';
				writeFile << referenceVector[i].p + '0';
				writeFile << ',';
				writeFile << referenceVector[i].e + '0';
				writeFile << ") ";
				writeFile << '"';
				writeFile << referenceVector[i].name;
				writeFile << '"' << endl;
			} else if(tipo == "Base") {
				writeFile << '"';
				writeFile << referenceVector[i].name;
				writeFile << '"';
				writeFile << ',';
				writeFile << referenceVector[i].p + '0';
				writeFile << ':';
				writeFile << referenceVector[i].e + '0';
				writeFile << ",(";
				writeFile << referenceVector[i].x + '0';
				writeFile << ",";
				writeFile << referenceVector[i].y + '0';
				writeFile << ")" << endl;
			}
			
		}
		writeFile.close();
	}
}

void baseAndShipExtraction(string fileName, vector<RegBaseoShip>  &vectorBase, vector<RegBaseoShip>  &vectorShip) {
	ifstream correctFile (fileName);
	string fileLine, type, parameters ;
	int position = 0, position2 = 0,line = 0;
	RegBaseoShip b, s;
	


	if(correctFile.is_open()) {

		while(getline(correctFile, fileLine)) {

			line++;
			position = fileLine.find(':');
			if(position != -1 ){
			for(int i=0; i < position; i++) {
				type += fileLine[i];
			}
			if(type == "Ship" || type == "Base") {
				fileLine.replace(0, position+1, " ");
				
					position = fileLine.find('"');
					position2 = fileLine.find('"', position+1);
					string name;
					name.empty();
					
					for(int i = position+1; i < position2; i++) {
						name += fileLine[i];
					}

					position = fileLine.find(":");
					string positionString;

					for(unsigned int i = position+1; i < fileLine.size(); i++) {
						positionString += fileLine[i];
					}

					int postitionSave = stoi(positionString);

					if(type == "Ship") {
						s.name = name;
						s.pos = postitionSave;
						vectorShip.push_back(s);
					} else if(type == "Base") {
						b.name = name;
						b.pos = postitionSave;
						vectorBase.push_back(b);
					}
				type.clear();
				} else {
					cout << "Error line " << line << ":" << fileLine << endl;
				}

			}

		}

		correctFile.close();
	}
}

int main(int argc, char *argv[]) {
	if(argc == 3) {
		

		vector<RegBaseoShip> vectorBase;
		vector<RegBaseoShip> vectorShip;
		baseAndShipExtraction(argv[2], vectorBase, vectorShip);

		vector<RegBin> vectorExtractionShip = extractionFile(argv[1], vectorShip);
		vector<RegBin> vectorExtractionBase = extractionFile(argv[1], vectorBase);

		writeFile("Base", vectorExtractionBase);
		writeFile("Ship", vectorExtractionShip);

	}
}
