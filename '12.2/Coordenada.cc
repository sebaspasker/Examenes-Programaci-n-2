#include "Coordenada.h"

bool Coordenada::coordenadaError = false;

Coordenada::Coordenada(double x, double y) {
	this-> x = x;
	this-> y = y;

}

Coordenada::Coordenada(const Coordenada &c) {
	x = c.x;
	y = c.y;
}

double
Coordenada::distancia(const Coordenada &c) const {
	double distancia = sqrt(pow(x-c.x, 2.0) + pow(y-c.y,2.0));

	return distancia;
}

bool
Coordenada::isError() const {
	return Coordenada::coordenadaError;
}

double
Coordenada::getX() const {
	return x;
}

double 
Coordenada::getY() const {
	return y;
}

void
Coordenada::setX(double x) {
	this -> x = x;
}

void 
Coordenada:: setY(double y) {
	this -> y = y;
}