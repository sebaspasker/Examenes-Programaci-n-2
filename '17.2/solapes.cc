// Examen julio 2017

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

const string FILE_ASIGNATURAS = "asignaturas.bin";
const string FILE_HORARIO = "horario.txt";


struct Asignatura {
	int cuatrimestre;
	char codAsignatura[6];
	int franjaInicio;
	int franjaFin; // 24 franjas dia/ 120 franjas semana
};

struct Alumno {
	string nombre;
	vector<int> numAsignatura;
};

vector<Asignatura> asignaturasExtraction() {
	ifstream fileAs(FILE_ASIGNATURAS.c_str(), ios::binary);
	Asignatura a;
	vector<Asignatura> aVector;


	if(fileAs.is_open()) {

		fileAs.seekg(0, ios::end);
		unsigned int position = fileAs.tellg()/sizeof(Asignatura);
		fileAs.seekg(0, ios::beg);

		for(unsigned int i=0; i < position; i++) {
			fileAs.read((char *)&a, sizeof(Asignatura));
			aVector.push_back(a);
		}

		/*
		a.cuatrimestre = 1;
		strcpy(a.codAsignatura ,"0000A");
		a.franjaInicio = 2;
		a.franjaFin = 6;
		aVector.push_back(a);
		a.cuatrimestre = 1;
		strcpy(a.codAsignatura ,"0000B");
		a.franjaInicio = 2;
		a.franjaFin = 6;
		aVector.push_back(a);

a.cuatrimestre = 1;
		strcpy(a.codAsignatura ,"0000C");
		a.franjaInicio = 8;
		a.franjaFin = 16;
		aVector.push_back(a);

a.cuatrimestre = 2;
		strcpy(a.codAsignatura ,"0000D");
		a.franjaInicio = 7;
		a.franjaFin = 15;
		aVector.push_back(a);  

a.cuatrimestre = 1;
		strcpy(a.codAsignatura ,"0000E");
		a.franjaInicio = 1;
		a.franjaFin = 7;
		aVector.push_back(a);

a.cuatrimestre = 2;
		strcpy(a.codAsignatura ,"0000F");
		a.franjaInicio = 8;   
		aVector.push_back(a);

	  a.cuatrimestre = 1;
		strcpy(a.codAsignatura ,"0000G");
		a.franjaInicio = 12;
		a.franjaFin = 18;
		aVector.push_back(a);

		for(unsigned int i=0; i < aVector.size(); i++) {
			fileAs.write((const char *)&aVector[i], sizeof(Asignatura));
		}*/

	} else {
		cout << "File don't open" << endl;
	}

	return aVector;
}

vector<Alumno> alumnosExtraction() {
	ifstream fileAl(FILE_HORARIO.c_str());
	Alumno a;
	vector<Alumno> alumnos;
	string line, parameter;

	if(fileAl.is_open()) {
		while(getline(fileAl, line)) {
			for(unsigned int i=0; i<line.size(); i++) {
				if(line[i] == ':') { // Case it's a name
					a.nombre = parameter;
					parameter.clear();
				} else if(line[i] == '|') { // Case it's a Asignatura
					a.numAsignatura.push_back(atoi(parameter.c_str()));
					parameter.clear();
				} else {
					parameter += line[i];
				}
			}

			a.numAsignatura.push_back(atoi(parameter.c_str())); // Save actual alu to vector
		 	alumnos.push_back(a);
		 	parameter.clear(); // Variables reset
		 	a.nombre.clear();
		 	a.numAsignatura.clear();
		}


		fileAl.close();
	} else {
		cout << "File don't open" << endl;
	}

	return alumnos;
}

bool asignaturaSolapamiento(Asignatura a1, Asignatura a2) {
	bool sol;

	if((a1.franjaInicio < a2.franjaInicio 
		&& a1.franjaFin < a2.franjaInicio )
	||
		  (a1.franjaInicio > a2.franjaFin 
		&& a1.franjaFin > a2.franjaFin )) {

		sol = false;
	} else {
		if(a1.cuatrimestre == a2.cuatrimestre){
			sol = true;
		}
	}

	return sol;
}

void printSolapamiento(string nombre, int position1, int position2, Asignatura a1, Asignatura a2) {

	cout << "Solapamiento: " << nombre << endl;
	cout << position1 << " " << a1.cuatrimestre << " " << a1.codAsignatura << " " << a1.franjaInicio << "-" << a1.franjaFin << endl;
	cout << position2 << " " << a2.cuatrimestre << " " << a2.codAsignatura << " " << a2.franjaInicio << "-" << a2.franjaFin << endl;
}

void solapamientoComprobation(vector<Asignatura> asignaturas, vector<Alumno> alumnos) {
	int position1, position2;
	bool todoOK = true, boolSolapamiento;

	for(unsigned int i=0; i<alumnos.size(); i++) { // Vector de alumnos
		for(unsigned int j=0; j<alumnos[i].numAsignatura.size(); j++) { // Vector de asignaturas de los ALUMNOS 1
			position1 = alumnos[i].numAsignatura[j]; 															// Guarda la primera posicion de la asignatura

			for(unsigned int k = j+1; k < alumnos[i].numAsignatura.size(); k++) { // Se coge la posicion j+1 para que no haya repetición
																																						// Vector de asignaturas de los ALUMNOS 2
				position2 = alumnos[i].numAsignatura[k];
				boolSolapamiento = asignaturaSolapamiento(asignaturas[position1], asignaturas[position2]); // Comprueba si hay solapamiento
				if(boolSolapamiento){
					todoOK = false;
					printSolapamiento(alumnos[i].nombre, position1, position2, asignaturas[position1], asignaturas[position2]); // En caso que haya solapamiento lo imprime
				}
			}
		}
		if(todoOK) {
			cout << alumnos[i].nombre << ": ok" << endl; // Si no hay ningún solapamiento imprime todo ok
		} else {
			todoOK = true;
		}
	}
}
	



int main() { // Add STOP ERROR CASE
	vector<Asignatura> asignaturas = asignaturasExtraction();
	vector<Alumno> alumnos = alumnosExtraction();	
	solapamientoComprobation(asignaturas, alumnos);
}