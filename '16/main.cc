#include "Provincia.h"

#include<iostream>

using namespace std;

int main()
{
	Provincia p("Alicante",12);
	p.addVotos("PP 300000");
	p.addVotos("UP-Compromis 192165");
	p.addVotos("PSOE 187056");
	p.addVotos("PP 9000"); // Otro colegio electoral
	p.addVotos("Cs 138063");
	p.addVotos("PP -100"); // Excepción lanzada
	p.addVotos("PACMA 10600");
	p.addVotos("PP 20000");
	p.calcularEscanyos();
	cout << p << endl;
}