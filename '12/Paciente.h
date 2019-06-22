#include <iostream>
#include <fstream>
#include "Medicamento.h"

using namespace std;

class Paciente {
	private:
		const unsigned int MAX_MED = 30;
		vector<Medicamento> mVector;
		string nombre;

	public:
		Paciente(string nombre);
		Paciente(const Paciente &p);
		string getNombre() const;
		void setNombre(string nombre);
		bool recetarMedicamento(const Medicamento &m);
		bool guardar(string nombrefichero) ;
};