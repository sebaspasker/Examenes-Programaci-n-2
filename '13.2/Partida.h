#include "Jugador.h" 
#include <vector>
#include <stdlib.h>

class Partida {
	friend ostream& operator<<(ostream &os, const Partida &p);
	private:
		vector<Jugador> jugadores;
		static const int letrasRack = 9;
		int turno;
		int numJugadores;
		string rack;

	public:
		Partida(int numJugadores = 1);
		void jugar();
		void generarRack();

};