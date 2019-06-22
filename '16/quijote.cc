#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;



struct mejoresCitas {
	string cita;
	unsigned int Capitulo;
	int nota;
};

vector<mejoresCitas> guardaCitas(string nombreFichero, int notaImpuesta) {
	ifstream fileText(nombreFichero);
	string lineaText;
	int process = 0;
	mejoresCitas mcCpy;
	vector<mejoresCitas> mcVectorCpy;
	string citaCpy;
	int numCpy = 0;


	if(fileText.is_open()) {
		while(getline(fileText, lineaText)) {
			for(unsigned int i = 0; i < lineaText.size(); i++) {
				if(process == 0 && lineaText[i] != '$') {
					citaCpy += lineaText[i];

				} else if(process == 0 && lineaText[i] == '$') {
					process = 1;
					mcCpy.cita = citaCpy;
					citaCpy.clear();

				} else if((process == 1 || process == 2) && lineaText[i] != '$') {
					numCpy = numCpy*10 + (lineaText[i] - '0');

				} else if(process == 1 && lineaText[i] == '$') {
					process = 2;
					mcCpy.Capitulo = numCpy;
					numCpy = 0;
				}
			}
			
			if(numCpy >= notaImpuesta) {
				mcCpy.nota = numCpy;
				mcVectorCpy.push_back(mcCpy);
			}

			numCpy = 0;
			process = 0;
			mcCpy.cita.clear();
			mcCpy.Capitulo = 0;
			mcCpy.nota = 0;
		}
	
		fileText.close();
	}

	return mcVectorCpy;
}


int main(int argc, char **argv) {
	int numNota = 0;
	string nombreFichero;
	if(argc == 2) {
		nombreFichero = argv[1];
	} else if(argc == 3) {
		nombreFichero = argv[1];
		numNota = atoi(argv[2]);
	}

	if(numNota < 0 || numNota > 10) {
		cout << "Error, 'nota' tiene que ser entre 0 y 10" << endl;
	}	else {
		vector<mejoresCitas> recopilatorio;
		recopilatorio = guardaCitas(nombreFichero, numNota);
		unsigned int maxCapitulo = 0;

		for(unsigned int i=0; i <recopilatorio.size(); i++) {
			if(recopilatorio[i].Capitulo > maxCapitulo) {
				maxCapitulo = recopilatorio[i].Capitulo ;
			}
		}

		bool entrado = false;
		for(unsigned int  i= 0; i<maxCapitulo+1; i++) {
			
			for(unsigned int j=0; j<recopilatorio.size(); j++){
				if(i == recopilatorio[j].Capitulo && entrado == false) {
					entrado = true;
					cout << "Capitulo " << i << endl;
					j = 0;
				}

				if(i == recopilatorio[j].Capitulo) {
					cout << "- " << recopilatorio[j].cita << endl;
				}
			
			}
			entrado = false;
		}
	}

}