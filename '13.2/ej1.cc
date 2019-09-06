#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Actividad {
	string nombre;
	vector<string> vectorIntegrantes;
};

vector<Actividad> actividadExtraction(string nomFichero, bool &error) {
	ifstream fileActividad(nomFichero.c_str());
	string line, variableCpy;
	bool firstEntrance = true;
	vector<Actividad> vectorActividad;
	Actividad a;
	string integrante;
	int position = -1;

	if(fileActividad.is_open()) {

		while(getline(fileActividad, line)) {
			for(unsigned int i=0; i<line.size(); i++) {
				if(firstEntrance && line[i] == ',') {
					integrante = variableCpy;
					firstEntrance = false;
					variableCpy.clear();
				}	else if(line[i] == ',') {
					for(unsigned int i=0; i<vectorActividad.size(); i++) {
						if(vectorActividad[i].nombre == variableCpy) {
							position = i;
						}
					}

					if(position == -1){
						a.nombre = variableCpy;
						a.vectorIntegrantes.push_back(integrante);
						vectorActividad.push_back(a);
						a.vectorIntegrantes.clear();
						a.nombre.clear();

					} else {
						vectorActividad[position].vectorIntegrantes.push_back(integrante);

					}

					variableCpy.clear();
					position = -1;

 				} else {
 					variableCpy += line[i];
 				}	
			}	

			for(unsigned int i=0; i<vectorActividad.size(); i++) {
			if(vectorActividad[i].nombre == variableCpy) {
					position = i;
				}
			}

			if(position == -1){
				a.nombre = variableCpy;
				a.vectorIntegrantes.push_back(integrante);
				vectorActividad.push_back(a);
				a.vectorIntegrantes.clear();
				a.nombre.clear();

			} else {
				vectorActividad[position].vectorIntegrantes.push_back(integrante);

			}

			variableCpy.clear();
			position = -1;

			integrante.clear();
			firstEntrance = true;
		}

		fileActividad.close();
	} else {
		error = false;
		cout << "El archivo " << nomFichero << " no abre" << endl;
	}

	return vectorActividad;
}

int main(int argc, char *argv[]) {
	bool error = false;

	if(argc == 2){
		vector<Actividad> actividades = actividadExtraction(argv[1], error);

		for(unsigned int i=0; i<actividades.size(); i++) {
			cout << actividades[i].nombre << ": ";

			for(unsigned int j=0; j < actividades[i].vectorIntegrantes.size(); j++) {
				cout << actividades[i].vectorIntegrantes[j];
				if(j < actividades[i].vectorIntegrantes.size()-1) {
					cout << ", " ;
				}
			}

			cout << endl;
		}

	} else {
		cout << "Formato de entrada incorrecto" << endl;
	}
}