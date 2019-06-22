#include "Paciente.h"

Paciente::Paciente(string nombre) {
	this -> nombre = nombre;
}

Paciente::Paciente(const Paciente &p) {
	nombre = p.nombre;

	for(unsigned int i=0; i< p.mVector.size() && i < MAX_MED; i++) {
		mVector.push_back(p.mVector[i]);
	}
}

string 
Paciente::getNombre() const {
	return nombre;
}

void
Paciente::setNombre(string nombre) {
	this -> nombre = nombre;
}

bool
Paciente::recetarMedicamento(const Medicamento &m) {
	bool introduced = false;

	if(mVector.size() < MAX_MED) {
		mVector.push_back(m);
		introduced = true;
	}

	return introduced;
}

// Falla

bool
Paciente::guardar(string nombrefichero) {
	ifstream fileM(nombrefichero);
	bool open, firstEntrance = true;
	string fileLine, parameter;

	if(fileM.is_open()) {
		open = true;
		int position;

		while(getline(fileM, fileLine) && mVector.size() < MAX_MED) {
			position = fileLine.find(' ');

			for(unsigned int i=position +1 ; i<fileLine.size(); i++) {
				parameter += fileLine[i];
			}

			if(firstEntrance == false) {
				Medicamento m(parameter);
				mVector.push_back(m);
				parameter.clear();

			} else {	
				nombre = parameter;
				parameter.clear();
				firstEntrance = false;
			}
		}

		fileM.close();
	} else {
		open = false;
	}

	return open;
}