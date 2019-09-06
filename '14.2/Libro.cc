#include "Libro.h"

Libro::Libro(string titulo, string autor, int numEjemplares) {
	this -> titulo = titulo;
	this -> autor = autor;
	this -> numEjemplares = numEjemplares;
	numPrestados = 0;
}

bool
Libro::prestar() {
	if(numPrestados == numEjemplares) {
		cout << "No se puede prestar este libro" << endl;
		return false;
	} else {
		numPrestados++;
		return true;
	}
}

bool 
Libro::devolver() {
	if(numPrestados > 0) {
		numPrestados--;
		return true;
	} else  {
		return false;
	}

}

int
Libro::getNumDisponibles() const {
	return numEjemplares-numPrestados;
}

void
Libro::anyadirEjemplares(int numEjemplaresNuevos) {
	numEjemplares += numEjemplaresNuevos;
}

int
Libro::getNumEjemplares() const {
	return numEjemplares;
}

bool
Libro::isEqualTo(const Libro &libro) const {

	if(titulo == libro.titulo && autor == libro.autor) {
		return true;
	} else {
		return false;
	}
}

ostream& operator<<(ostream &os, const Libro &l) {
	os << l.getNumDisponibles() << ": " << l.titulo << " ( " << l.autor << " ) " << endl;
	return os;
}