#ifndef _PROVINCIA_
#define _PROVINCIA_

#include <iostream>
#include <vector>
#include <string>
#include "Partido.h"

using namespace std;

class Provincia {
	friend ostream& operator<<(ostream &o, Provincia &p);

	private:
		string nombre;
		int escanyos;
		vector<Partido> partidoVector;

	public:
		Provincia(string nombre, int escanyos);
		int buscarPartido(string nombre) const;
		void addVotos(string s);
		void calcularEscanyos();

};

#endif