#include "Biblioteca.h"

Biblioteca::Biblioteca(string nombre) {
	this -> nombre = nombre;
}

int 
Biblioteca::buscar(const Libro &libro) const{
	int position = -1;

	for(unsigned int i=0; i < lVector.size(); i++) {
		if(lVector[i].isEqualTo(libro)) {
			position = i;
		}
	}

	return position;
}

void
Biblioteca::anyadir(const Libro &libro) {
	int position = Biblioteca::buscar(libro);

	if(position != -1) {
		lVector[position].anyadirEjemplares(libro.getNumEjemplares());
	} else {
		lVector.push_back(libro);
	}
}

bool
Biblioteca::prestar(const Libro &libro) {
	int position = Biblioteca::buscar(libro);

	if(position != -1)  {
		bool prestado = lVector[position].prestar();
		return prestado;
	} else {
		cout << "Este libro no se encuentra en la biblioteca" << endl;
		return false;
	}
}

ostream& operator<<(ostream &os, const Biblioteca &b) {
	os << b.nombre << endl;
	os << "------------" << endl;

	for(unsigned int i=0; i<b.lVector.size(); i++) {
		if(b.lVector[i].getNumDisponibles() != 0)
			os << b.lVector[i];
	}

	return os;
}