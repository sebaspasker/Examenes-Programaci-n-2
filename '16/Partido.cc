#include "Partido.h"

Partido::Partido(string nombre, int votos) {
	if(votos < 0) {
		throw ERR_VOTOS;
	} else {
		this->nombre = nombre;
		this->votos = votos;
	}
}

int
Partido::getVotosPorEscanyo() const {
	if(escanyos == 0) {
		return 0;
	} else {
		return votos/escanyos;
	}
}

string 
Partido::getNombre() const {
	return nombre;
}

int
Partido::getVotos() const {
	return votos;
}


int
Partido::getEscanyos() const {
	return escanyos;
}
 
void 
Partido::setNombre(string nombre) {
	this-> nombre = nombre;
} 

void
Partido::addVotos(int votos) {
	this->votos +=votos;
}

void 
Partido::addEscanyo() {
	escanyos += 1;
}

ostream& operator<<(ostream &o, Partido &p) {
	o << p.nombre << ": " << p.escanyos << " escanyos, ";
	o << p.votos << " votos, ";
	o << p.getVotosPorEscanyo() << " votos por escanyo" << endl;

	return o;
}
