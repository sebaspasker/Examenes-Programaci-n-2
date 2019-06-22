#include "cancion.h"

Cancion::Cancion(string nombre, string artista, int punt) {
	if(punt >= 0 && punt <= 5) {
		this -> nombre = nombre;
		this -> artista = artista;
		puntuacion = punt;
	}
}

string 
Cancion::getNombre() const {
	return nombre;
}

string 
Cancion::getArtista() const {
	return artista;
}

int 
Cancion::getPuntuacion() const {
	return puntuacion;
}

void
Cancion::setPuntuacion (int puntuacion) {
	if(puntuacion >= 0 && puntuacion <= 5) {
		this -> puntuacion = puntuacion;
	} else {
		cout << "Incorrect puntuation" << endl;
	}
 }

 ostream& operator<<(ostream &os, const Cancion &c) {
 	os << c.nombre << " - " << c.artista << " - " << c.puntuacion << endl;
 	return os;
 }