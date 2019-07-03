#include "Coordenada.h"
#include <vector>

class Poligono {
	private:
		string nombre;
		vector<Coordenada> coordenadas;
		const unsigned int maxCoordenadas = 20;

	public:
		Poligono(string nombre);
		Poligono(const Poligono &p);
		bool anyadirCoordenada(const Coordenada &c);
		double calcularPerimetro() const;
		string getNombre() const;
		void setNombre(string nombre);

};