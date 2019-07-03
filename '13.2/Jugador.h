#include <iostream>

using namespace std;

class Jugador {
	private:
		int puntuacion;

	public:
		Jugador();
		int getPuntuacion() const;
		bool mover(string palabra, string rack);
};