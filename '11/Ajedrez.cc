#include "Ajedrez.h"


void
Ajedrez::InicializarTablero()  {
	for(unsigned int y=0; y<8; y++) {
		for(unsigned x=0; x<8; x++) {
			Ptablero[x][y].SetVacia();
		}
	}
}

Ajedrez::Ajedrez(string nombre) {
	this -> nombre = nombre;

	Ajedrez::InicializarTablero();
}

Ajedrez::Ajedrez(string nombre, string nomfichero) {
	this -> nombre = nombre;
	string line;
	bool colorb;
	char color, pieza;
	int x, y;

	ifstream fileAj(nomfichero);

	if(fileAj.is_open()) {
		while(getline(fileAj, line)) {
			for(unsigned int i=0; i<line.size(); i++) {
				if(i==0) {
					pieza = line[i];
				} else if(i==2) {
					color = line[i];
				} else if(i== 4) {
					x = line[i] - '0';
				} else if(i== 6) {
					y = line[i] - '0';
				}
			}

			if(color == 'n') {
				colorb = true;
			} else if(color == 'b') {
				colorb = false;
			}

			Pieza P(pieza, colorb);
			Ptablero[x][y] = P;
		}

		fileAj.close();
	} else {
		cout << "Error, el archivo no se puede abrir" << endl;
 	}
}

bool
Ajedrez::BorrarPieza(int x, int y) {
	bool Borrado = false;

	if(Ajedrez::ComprobarCoordenadas(x, y)) {
		if(Ptablero[x][y].IsVacia() == false) {
			Ptablero[x][y].SetVacia();
		} else {
			cout << "Coordenadas incorrectas" << endl;	
		}
	} else {
		cout << "Coordenadas incorrectas" << endl;
	}

	return Borrado;
}

bool
Ajedrez::AnyadirPieza(Pieza p, int x, int y) {
	bool existe = Ajedrez::ComprobarCoordenadas(x, y);
	bool anyadido = false;

	if(existe == true) {
		if(Ptablero[x][y].IsVacia()) {
			Pieza P(p);
			Ptablero[x][y] = P;
			anyadido = true;
		}
	}	else {
		cout << "No existe esta posicion" << endl;
	}

	return anyadido;
}

void 
Ajedrez::Mostrar() {
	cout << nombre << endl;
	for(unsigned int y=0; y<8; y++) {
		for(unsigned int x=0; x<8; x++) {
			cout << "|" << Ptablero[x][y].getTipo();
			if(!Ptablero[x][y].IsVacia()){
				cout << Ptablero[x][y].getColor(); 
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

bool
ComprobarCoordenadas(int x, int y) {
	if(x <= 7 && x >= 0
	&& y <= 7 && y >= 0) {
		return true;
	} else {
		return false;
	}
}
