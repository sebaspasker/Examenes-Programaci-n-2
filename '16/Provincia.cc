#include "Provincia.h"

Provincia::Provincia(string nombre, int escanyos) {
	this->nombre = nombre;
	this->escanyos = escanyos;
}

int
Provincia::buscarPartido(string nombre) const {
	int partidoPosition = -1;

	for(unsigned int i=0; i<partidoVector.size(); i++) {
		if(partidoVector[i].getNombre() == nombre) {
			partidoPosition = i;
		}
	}

	return partidoPosition;
}

void
Provincia::addVotos(string s) {
	string nombrePartido;
	string votosChar;
	int votos = 0;
	int process = 0;
	for(unsigned int i=0; i < s.size(); i++) {
		if( process == 0
				&& s[i] != ' ' ) {
			nombrePartido += s[i];
		} else if(s[i] == ' ' && process == 0) {
			process = 1;
		} else if(process == 1 && s[i] != ' ') {
			votosChar += s[i];
		}
	}

	votos = stoi(votosChar);
	int position = Provincia::buscarPartido(nombrePartido);
	if(position == -1) {
		try {
			Partido p(nombrePartido, votos);
			partidoVector.push_back(p);

		} catch (Error e) {
			if(e == ERR_VOTOS)
			cout << "Valor " << votos << " incorrecto" << endl;
		} 
	} else {
		if(votos < 0) {
			cout << "Valor " << votos << " incorrecto" << endl;
		} else {
			partidoVector[position].addVotos(votos);
		}
	}
}

void 
Provincia::calcularEscanyos() {
	unsigned int N = escanyos;

	int cont = 1;

	int matrizEscanyos[partidoVector.size()][N+1];
	for(unsigned int i=0; i < partidoVector.size(); i++) {
		for(unsigned int j=0; j < N; j++) {
		
			matrizEscanyos[i][j] = partidoVector[i].getVotos()/cont;
			cont++;
		}
		cont = 1;
	}
		
	vector<int> partidoEscanyo;
	int mayorValor = 0;
	int posicionMayorValori = -1;
	int posicionMayorValorj = -1;


	while(partidoEscanyo.size() <= N) {
		
		for(unsigned int i=0; i < partidoVector.size(); i++) {
			for(unsigned int j=0; j < N; j++) {
				if(matrizEscanyos[i][j] > mayorValor) {
					mayorValor = matrizEscanyos[i][j];
					posicionMayorValori = i;
					posicionMayorValorj = j;	
				}
			}
		}

		matrizEscanyos[posicionMayorValori][posicionMayorValorj] = 0;
		partidoEscanyo.push_back(posicionMayorValori);
		posicionMayorValori = -1;
		posicionMayorValorj = -1;
		mayorValor = 0;
	}

	for(unsigned int i=0; i < partidoEscanyo.size(); i++) {
		partidoVector[partidoEscanyo[i]].addEscanyo();
	}
}

ostream& operator<<(ostream &o, Provincia &p) {
	
	for(unsigned int i=0; i< p.partidoVector.size(); i++) {
		o << p.partidoVector[i];
	}

	return o;
}
