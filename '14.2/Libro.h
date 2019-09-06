#include <iostream>

using namespace std;

class Libro {
	friend ostream& operator<<(ostream &os, const Libro &l);
	private:
		string titulo;
		string autor;
		int numEjemplares;
		int numPrestados;
	public:
		Libro(string titulo, string autor, int numEjemplares = 1);
		bool prestar();
		bool devolver();
		int getNumDisponibles() const;
		void anyadirEjemplares(int numEjemplaresNuevos);
		int getNumEjemplares() const;
		bool isEqualTo(const Libro &libro) const;
};