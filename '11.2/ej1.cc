#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

void fechaSeparation(string fecha, int &dia, int &mes, int &anyo);

struct Datos {
	string transbordador;
	string pieza;
	int dia;
	int mes;
	int anyo;
};

Datos extractionCommandController(string line) {
	Datos d;
	bool firstValue = true;
	string valueCpy;

	for(unsigned int i=0; i<line.size();i++) {
		if(line[i] == ':' && firstValue) {								// Save transbordador
			firstValue = false;
			d.transbordador = valueCpy;
			valueCpy.clear();

		} else if(line[i] == ':' && !firstValue) {				// Save pieza
			d.pieza = valueCpy;
			valueCpy.clear();

		} else {
			valueCpy += line[i];
		}
	}

	fechaSeparation(valueCpy, d.dia, d.mes, d.anyo); // Save and separate fecha

	return d;
}

// Extract datos from file --> transbordador:pieza:fecha format 
vector<Datos> datosExtraction(string fileName, bool &error) {
	ifstream file(fileName);
	string line;
	Datos d;
	vector<Datos> datosVector;

	if(file.is_open()) {
		while(getline(file, line)) {
			d = extractionCommandController(line);
			datosVector.push_back(d);
		}

		file.close();
	} else {
		cout << "File can't open" << endl;
		error = true;
	}

	return datosVector;

}


// Separates fecha format in dia, mes, anyo (fecha --> day/month/year format)
void fechaSeparation(string fecha, int &dia, int &mes, int &anyo) { 
	bool firsEntrance = true;
	string valueCpy;

	for(unsigned int i=0; i < fecha.size(); i++) {
		if(firsEntrance && fecha[i] == '/') {					// Save day
			dia = atoi(valueCpy.c_str());
			valueCpy.clear();
			firsEntrance = false;

		} else if(fecha[i] == '/') {									// Save month
			mes = atoi(valueCpy.c_str());
			valueCpy.clear();

		} else {																
			valueCpy += fecha[i];					

		}
	}

	anyo = atoi(valueCpy.c_str());									// Save year
}

void printPiezas(vector<Datos> datosVector, string transbordador, string fecha, bool &error) {
	int diaP = 0, mesP = 0, anyoP = 0;

	fechaSeparation(fecha, diaP, mesP, anyoP);
	if(diaP == 0 || mesP == 0 || anyoP == 0) {
		cout << "Formato incorrecto de fecha" << endl;
		error = true;
	}

	if(!error) {
		for(unsigned int i=0; i < datosVector.size(); i++) {
			if(transbordador == datosVector[i].transbordador) {
				if(anyoP > datosVector[i].anyo) { // Case < year
					cout << datosVector[i].pieza << endl;

				} else if(anyoP == datosVector[i].anyo) { // Case == year 
					if(mesP > datosVector[i].anyo) {				// < month
						cout << datosVector[i].pieza << endl;

					} else if(mesP == datosVector[i].mes) { // Case == month
						if(diaP >= datosVector[i].dia) {      // <= day
							cout << datosVector[i].pieza << endl;
						}

					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	bool error = false;

	if(argc == 4) {
		vector<Datos> datosVector = datosExtraction(argv[1], error);

		if(!error) {
			printPiezas(datosVector, argv[2], argv[3], error);
		}
	} else {
		cout << "Error, incorrect introduction format" << endl;
	}
}