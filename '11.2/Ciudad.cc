#include "Ciudad.h"

Ciudad::Ciudad(string nombre) {
	this -> nombre = nombre;
}

Ciudad::Ciudad(const Ciudad &c) {
	nombre = c.nombre;

	for(unsigned int i=0; i < c.partidoVector.size(); i++) {
		if(i == maxPartidos-1) {
			break;
		} else {
			partidoVector.push_back(c.partidoVector[i]);
		}
	}
}

void
Ciudad::setNombre(string nombre) {
	this -> nombre = nombre;
}

string 
Ciudad::getNombre() const {
	return nombre;
}

int buscarPositionPartido(vector<Partido> partidoVector, string nombrePartido) {
	int position = -1;

	for(unsigned int i=0; i < partidoVector.size(); i++) {
		if(nombrePartido == partidoVector[i].getNombre()) {
			position = i;
		}
	}

	return position;
}

void 
Ciudad::anyadirVoto(string nombrePartido) {
	int position = buscarPositionPartido(partidoVector ,nombrePartido);

	if(position != -1) {
		partidoVector[position].anyadirVoto();

	} else  {
		if(partidoVector.size() < maxPartidos){
				Partido p(nombrePartido);
				partidoVector.push_back(p);
		}
	}
}

void
Ciudad::leerVotos(string nombrefichero) {
	ifstream partidoFile(nombrefichero);
	string line;

	if(partidoFile.is_open()) {
		while(getline(partidoFile, line)) {
			Ciudad::anyadirVoto(line);
		}

		partidoFile.close();
	} else {
		cout << "El archivo no se puede abrir" << endl;
	}
}

void
Ciudad::imprimirResultados() const {
	cout << nombre << endl;
	cout << "------------" << endl;

	for(unsigned int i=0; i < partidoVector.size(); i++) {
		cout << partidoVector[i].getNombre() << ":" << partidoVector[i].getNumVotos() << endl; 
	}
}

string
Ciudad::getGanador() const {
	int position = -1;

	for(unsigned int i=0; i<partidoVector.size(); i++) {
		if(position == -1) {
			position = i;
		} else if(partidoVector[position].getNumVotos() < partidoVector[i].getNumVotos()) {
			position = i;
		}
	}

	if(position != -1){	
		return partidoVector[position].getNombre() ;

	} else {
		return "No hay ningún partido anyadido \n";
	}
}