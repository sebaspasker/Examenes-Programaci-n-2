#include "Partido.h"

Partido::Partido(string nombre) {
	this -> nombre = nombre;
	votos = 1;
}

string
Partido::getNombre() const {
	return nombre;
}

int 
Partido::getNumVotos() const {
	return votos;
}

void 
Partido::setNombre(string nombre) {
	this -> nombre = nombre;
}

void 
Partido::anyadirVoto() {
	votos++;
}