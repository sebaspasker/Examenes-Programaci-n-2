#include <iostream>
#include <fstream>

using namespace std;

const unsigned int maxEquipos = 20;
const unsigned int maxJugadores = 22;	

struct Jugador {
	string nombre;
	int numero;
};

struct Equipo {
	string nombre;
	unsigned int positionJugador = 0;
	Jugador jugadores[22];
};


void player_and_team_extraction(string line, Equipo equipos[], unsigned int &positionEquipo, bool &fullEquipos) {
	Jugador j;
	bool firstEntrance = true;
	string variableCpy;
	int position = -1;

	for(unsigned int i=0; i<line.size(); i++) {		
		if(line[i] == ':' && firstEntrance) {			// Save player number
			j.numero = atoi(variableCpy.c_str());
			variableCpy.clear();
			firstEntrance = false;

		} else if(line[i] == ':') {								// Save player name & surname
			j.nombre = variableCpy;
			variableCpy.clear();

		} else  {
			variableCpy += line[i];
		}
	}

	for(unsigned int i=0; i < maxEquipos; i++) { // Search futbol team
		if(variableCpy == equipos[i].nombre) {
			position = i;
		}
	}

	if(position == -1) {												// Case futbol team don't exist
		Equipo e;
		e.nombre = variableCpy;
		e.jugadores[e.positionJugador] = j;
		e.positionJugador++;

		if(positionEquipo < maxEquipos){					
			equipos[positionEquipo] = e;
			positionEquipo++;
		} else {

			if(!fullEquipos){ // No more team capacity
				
				cout << "No se pueden introducir mas equipos" << endl;
				fullEquipos = true;
			}
		}

	} else {																	// Case futbol team exist
		if(equipos[position].positionJugador < maxJugadores) {
			equipos[position].jugadores[equipos[position].positionJugador] = j;
			equipos[position].positionJugador++;

		} else { // No more player capacity
			cout << "El jugador " << j.nombre << " no cabe en el" << equipos[position].nombre << endl;
		}
	}
}

// Recordatorio --> en los arrays no hace falta &
void jugadoresExtraction(string fileName, Equipo equipos[] , bool &Error, unsigned int &positionEquipo) {
	ifstream fileEquipos(fileName);
	string line;
	bool fullEquipos = false;

	if(fileEquipos.is_open()) {
		while(getline(fileEquipos, line)) {
			player_and_team_extraction(line, equipos, positionEquipo, fullEquipos); // Extract player and team
		}

		fileEquipos.close();
	} else {
		cout << "El archivo no se puede abrir" << endl;
		Error = true;
	}  
}

int main(int argc, char *argv[]) {
	bool Error = false;

	if(argc == 2) {
		Equipo equipos[20];
		unsigned int positionEquipo = 0;
		jugadoresExtraction(argv[1], equipos, Error, positionEquipo);

		for(unsigned int i=0; i < positionEquipo; i++) {
			cout << "---------" << equipos[i]. nombre <<  "---------" << endl;

			for(unsigned int j=0; j < equipos[i].positionJugador; j++) {
				cout << equipos[i].jugadores[j].numero << " " << equipos[i].jugadores[j].nombre << endl;
			}
		}

	} else {
		cout << "Formato de introduccion incorrecto" << endl;
	}

}