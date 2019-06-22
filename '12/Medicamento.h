#include <iostream>
#include <vector>

using namespace std;

const int MAX_INCOMP = 20;

class Medicamento {
	private:
		string nombre;
		vector<string> incompatibilidades;

	public:
		Medicamento(string nombre = "");
		Medicamento(const Medicamento &m);
		string getNombre() const;
		void setNombre(string nombre) ;
		bool nuevaIncompatibilidad(string nombre);
		bool esIncompatibleCon(string nombre) const; // Creo que hay un error en el enunciado
																								 // porque si es constante no puedes pasar los 
																								 // parámetros

};