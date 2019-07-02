#include "Libro.h"
#include <vector>

class Biblioteca {
	friend ostream& operator<<(ostream &os, const Biblioteca &b);
	private:
		string nombre;
		vector<Libro> lVector;

	public:
		Biblioteca(string nombre);
		void anyadir(const Libro &libro);
		bool prestar(const Libro &libro);
		int buscar(const Libro &libro) const;

};