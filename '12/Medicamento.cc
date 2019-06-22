#include "Medicamento.h"

Medicamento::Medicamento(string nombre ) {
	this -> nombre = nombre;
}

Medicamento::Medicamento(const Medicamento &m) {
	nombre = m.nombre;

	for(unsigned int i=0; i<m.incompatibilidades.size() && i < MAX_INCOMP; i++) {
		incompatibilidades.push_back(m.incompatibilidades[i]);
	}
}

string 
Medicamento::getNombre() const {
	return nombre;
}

void 
Medicamento::setNombre(string nombre) {
	this -> nombre = nombre;
}

bool 
Medicamento::nuevaIncompatibilidad(string nombre) {
	bool introduced = false;

	if(incompatibilidades.size() < MAX_INCOMP) {
		incompatibilidades.push_back(nombre);
		introduced = true;
	}	

	return introduced;
}

bool
Medicamento::esIncompatibleCon(string nombre) const {
	bool incompatible = false;
	for(unsigned int i=0; i<incompatibilidades.size(); i++) {
		if(nombre == incompatibilidades[i]) {
			incompatible = true;
		}
	}

	return incompatible;
}
