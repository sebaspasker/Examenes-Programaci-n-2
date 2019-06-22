#include "playlist.h"

Playlist::Playlist(string nombre) {
	this -> nombre = nombre;
}

float
Playlist::getPuntuacionMedia() const {
	int total = 0, avg = 0, cont = 0;
	for(unsigned int i=0; i< cVector.size(); i++) {
		if(cVector[i].getPuntuacion() != -1) {
			total += cVector[i].getPuntuacion();
			cont++;
		}
	}

	avg = total / cont;

	return avg;
}	

vector<string>
Playlist::getArtistas() const {
	vector<string> sVector;
	string s;
	bool repetition = false;

	for(unsigned int i=0; i<cVector.size(); i++) {
		s = cVector[i].getArtista();

		for(unsigned int j=0; j<sVector.size(); j++) {
			if(s == sVector[j]) {
				repetition = true;
			}
		}

		if(repetition == false) {
				sVector.push_back(s);
		}

		repetition = false;
	}	

	return sVector;
}

bool 
Playlist::buscarCancion(const Cancion &c) {
	bool encontrado = false;

	for(unsigned int i=0; i<cVector.size(); i++) {
		if(cVector[i].getNombre() == c.getNombre() 
		&& cVector[i].getArtista() == c.getArtista()) {
			encontrado = true;
		}
	}

	return encontrado;
}

bool 
Playlist::anyadirCancion(const Cancion &c) {
	bool encontrado = Playlist::buscarCancion(c), anyadido = false;

	if(!encontrado) {
		cVector.push_back(c);
		anyadido = true;

	} else {
		cout << "Error, cancion repetida" << endl;
	}

	return anyadido;
}

ostream& operator<<(ostream &os, const Playlist &p) {
	os << "Titulo: " << p.nombre << endl;
	os << "Artistas: ";

	vector<string> Artistas = p.getArtistas();

	for(unsigned int i=0; i<Artistas.size(); i++) {
		os << Artistas[i] << ",";
	}

	os << endl << "-----------------" << endl;

	for(unsigned int i=0; i< p.cVector.size(); i++) {
		os << p.cVector[i];
	}

	os << "-----------------" << endl;

	os << "Puntuacion media= ";

	os << p.getPuntuacionMedia() << endl;
}