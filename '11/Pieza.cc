#include "Pieza.h"

Pieza::Pieza(char tipo, bool color) {
	if(		(tipo == ' ')
		 || (tipo == 'p')
		 || (tipo == 't')
		 || (tipo == 'c')
		 || (tipo == 'a')
		 || (tipo == 'r')
		 || (tipo == 'd')	) {

		this-> tipo = tipo;
		this-> color = color;
	}
}

char 
Pieza::getTipo() const {
	return tipo;
}

bool 
Pieza::getColor() const {
	return color;
}

bool 
Pieza::IsVacia() const {
	if(tipo == ' ') {
		return true;
	} else {
		return false;
	}
}

void 
Pieza::SetVacia() {
	tipo = ' ';
}