#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Extraction {
	vector<string> fechas;
	vector<string> personas;
	vector<string> empresas;
	vector<string> lugares;
};

int typeComprobation(int i, char character, bool &fecha, bool &persona, 
											bool &empresa, bool &lugar, bool &finish) {

	if(character == '@' && fecha == false) {
		fecha = true;
		i++;
	} else if(character == '@' && fecha == true) {
		finish = true;
	} else if(character == '$' && persona == false) {
		persona = true;
		i++;
	} else if(character == '$' && persona == true) {
		finish = true;
	} else if(character == '#' && empresa == false) {
		empresa = true;
		i++;
	} else if(character == '#' && empresa == true) {
		finish = true;
	} else if(character == '*' && lugar == false) {
		lugar = true;
		i++;
	} else if(character == '*' && lugar == true) {
		finish = true;
	}

	return i;

}

void saveValues(char character, bool &fecha, bool &persona, 
								bool &empresa, bool &lugar, bool &finish, Extraction &e, string &parameter) {
	if((fecha == true
		|| empresa == true
		|| persona == true
		|| lugar == true)  && finish == false) {
		parameter += character;
	}	else if(fecha == true && finish == true) {
		fecha = false;
		finish = false;
		e.fechas.push_back(parameter);
		parameter.clear();
	}	else if(persona == true && finish == true) {
		persona = false;
		finish = false;
		e.personas.push_back(parameter);
		parameter.clear();
	}	else if(empresa == true && finish == true) {
		empresa = false;
		finish = false;
		e.empresas.push_back(parameter);
		parameter.clear();
	}	else if(lugar == true && finish == true) {
		lugar = false;
		finish = false;
		e.lugares.push_back(parameter);
		parameter.clear();
	}
}

Extraction extraerFichero(string nameFile) {
	Extraction e;
	ifstream extFich(nameFile.c_str());
	string fileLine, parameter;
	bool fecha = false, persona = false, empresa = false, lugar = false, finish = false;

	if(extFich.is_open()) {
		while(getline(extFich, fileLine)) {
			for(unsigned int i=0; i<fileLine.size(); i++) {
				i = typeComprobation(i, fileLine[i], fecha, persona, empresa, lugar, finish);
				saveValues(fileLine[i], fecha, persona, empresa, lugar, finish, e, parameter);
			}
		}

		extFich.close();
	}

	return e;
} 

void printVector(vector<Extraction> eVector) {
	cout << "Fechas: "; // No me he querido comer la cabeza con el formato
												// Pero el último ' | ' no es correcto
		
		for(unsigned int i=0; i<eVector.size(); i++) {
			for(unsigned int j=0; j<eVector[i].fechas.size(); j++) {
				cout << eVector[i].fechas[j];
				if((j < eVector[i].fechas.size()-1) 
					|| (eVector[i+1].fechas.size() > 0)) {
						cout << " | ";
				}	
			}
		}
	

		cout << endl <<  "Personas: ";

		for(unsigned int i=0; i<eVector.size(); i++) {
			for(unsigned int j=0; j<eVector[i].personas.size(); j++) {
				cout << eVector[i].personas[j];
				if((j < eVector[i].personas.size()-1) 
				|| (eVector[i+1].personas.size() > 0)) {
					cout << " | ";
				}	
			}
		}

		cout << endl <<  "Empresas: ";

		for(unsigned int i=0; i<eVector.size(); i++) {
			for(unsigned int j=0; j<eVector[i].empresas.size(); j++) {
				cout << eVector[i].empresas[j];
				if((j < eVector[i].empresas.size()-1) 
					|| (eVector[i+1].empresas.size() > 0)) {
					cout << " | ";
				}	
			}
		}

		cout << endl <<  "Lugares: ";

		for(unsigned int i=0; i<eVector.size(); i++) {
			for(unsigned int j=0; j<eVector[i].lugares.size(); j++) {
				cout << eVector[i].lugares[j];
				if((j < eVector[i].lugares.size()-1) 
				|| ((eVector[i+1].lugares.size() > 0)
					&& (i < eVector.size() ))) {
					cout << " | ";
				}	
			}
		}

		cout << endl;
}

int main(int argc, char *argv[]) {
	Extraction e;
	vector<Extraction> eVector;
	if(argc >= 2) {
		for(int i=1; i<argc; i++) {
			e = extraerFichero(argv[i]);
			eVector.push_back(e);
		}

		printVector(eVector);

	}
}