#include <iostream>

using namespace std;

class Partido {
	private:
		string nombre;
		int votos;

	public:
		Partido(string nombre = "");
		string getNombre() const;
		int getNumVotos() const;
		void setNombre(string nombre);
		void anyadirVoto();
};