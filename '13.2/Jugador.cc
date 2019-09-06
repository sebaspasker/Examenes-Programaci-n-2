#include "Jugador.h"

Jugador::Jugador() {
	puntuacion = 0;
}

int 
Jugador::getPuntuacion() const {
	return puntuacion;
}

bool
Jugador::mover(string palabra, string rack) {
	bool foundChar = false, allOk = true;

	for(unsigned int i=0; i < palabra.size(); i++) {
		for(unsigned int j=0; j < rack.size(); j++) {
			if(palabra[i] == rack[j]) {
				foundChar = true;
				break;
			}
		}

		if(!foundChar) {
			allOk = false;
			break;
		}

		foundChar = false;
	}

	if(allOk) {
		puntuacion += palabra.size();
	} else {
		cout << "Palabra incorrecta" << endl;
	}

	return allOk;

}