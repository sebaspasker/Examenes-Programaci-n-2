#ifndef _PARTIDO_
#define _PARTIDO_

#include <iostream>

enum Error
{	
	ERR_VOTOS
};

using namespace std;

class Partido {
	friend ostream& operator<<(ostream &o, Partido &p);
	private:
		string nombre;
		int votos;
		int escanyos;

	public:
		Partido(string nombre, int votos = 0);
		int getVotosPorEscanyo() const;
		string getNombre() const;
		void setNombre(string nombre);
		int getVotos() const;
		void addVotos(int votos);
		void addEscanyo();
		int getEscanyos() const;
};

#endif