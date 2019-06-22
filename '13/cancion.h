#include <iostream>

using namespace std;

class Cancion {
	friend ostream& operator<<(ostream &os, const Cancion &c);
	private:
		static const int SP = -1;
		string nombre;
		string artista;
		int puntuacion;

	public:
		Cancion(string nombre, string artista, int punt = SP);
		string getNombre() const;
		string getArtista() const;
		int getPuntuacion() const;
		void setPuntuacion(int puntuacion);
};