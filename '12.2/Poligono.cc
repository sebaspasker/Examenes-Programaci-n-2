#include "Poligono.h"

Poligono::Poligono(string nombre) {
	this -> nombre = nombre;
}

Poligono::Poligono(const Poligono &p) {
	nombre = p.nombre;

	for(unsigned int i=0; i < p.coordenadas.size(); i++) {
		if(coordenadas.size() < maxCoordenadas) {
			coordenadas.push_back(p.coordenadas[i]);
		} else {
			break;
		}
	}
}

bool 
Poligono::anyadirCoordenada(const Coordenada &c) {
	bool anyadido = false;

	if(coordenadas.size() < maxCoordenadas) {
		coordenadas.push_back(c);
		anyadido = true;
	} 

	return anyadido;
}

double 
Poligono::calcularPerimetro() const {
	double perimetro = 0;

	for(unsigned int i=0; i < coordenadas.size()-1; i++) {
		perimetro += coordenadas[i+1].distancia(coordenadas[i]);
		
	}

	perimetro += coordenadas[0].distancia(coordenadas[coordenadas.size()-1]);

	return perimetro;
}

string 
Poligono::getNombre() const {
	return nombre;
}

void 
Poligono::setNombre(string nombre) {
	this -> nombre = nombre;
}