#include "Partido.h"
#include <vector>
#include <fstream>

using namespace std;

class Ciudad {
 	private:
 		string nombre;
 		vector<Partido> partidoVector;
 		const unsigned int maxPartidos = 10;

 	public:
 		Ciudad(string nombre);
 		Ciudad(const Ciudad &c);
 		void setNombre(string nombre);
 		string getNombre() const;
 		void anyadirVoto(string nombrePartido);
 		void leerVotos(string nombrefichero);
 		void imprimirResultados() const;
 		string getGanador() const;

};
