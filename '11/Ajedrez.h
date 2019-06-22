#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Pieza.h"

using namespace std;

class Ajedrez {
	private:
		string nombre;
		Pieza Ptablero[8][8];

	public:
		Ajedrez(string nombre);
		Ajedrez(string nombre, string nomfichero);
		void InicializarTablero();
		bool LeerFichero(string nomfichero); // Me falta pero me da pereza
		bool AnyadirPieza(Pieza p, int x, int y);
		bool MoverPieza(int ox, int oy, int dx, int dy);
		bool BorrarPieza(int x, int y);
		void Mostrar();
		bool ComprobarCoordenadas(int x, int y);

};