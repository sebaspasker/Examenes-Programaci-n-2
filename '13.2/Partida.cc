#include "Partida.h"

Partida::Partida(int numJugadores) {
	this -> numJugadores = numJugadores;
	turno = 0;

	for(int i=0; i < numJugadores; i++) {
		Jugador j;
		jugadores.push_back(j);
	}
}

void
Partida::generarRack() {
	rack.clear();

	for(unsigned int i=0; i < Partida::letrasRack; i++) {
		rack += (char)('A'+rand()%26);
	}
}

void
Partida::jugar() {
	string palabra;

	while(palabra != "q"){
		Partida::generarRack();
	
		cout << "Rack: " << rack << endl;
	
		for(int i=0; i < numJugadores; i++) {
			cout << "Jugador " << i+1 << "= ";
			getline(cin, palabra); 

			if(palabra != "q"){
				jugadores[i].mover(palabra, rack);
			} else {
				break;
			}
		}
	}
}

ostream& operator<<(ostream &os, const Partida &p) {
	for(unsigned int i=0; i < p.jugadores.size(); i++) {
		os << "Puntuacion jugador " << i+1 << "= " << p.jugadores[i].getPuntuacion() << endl;
	}

	return os;
}
