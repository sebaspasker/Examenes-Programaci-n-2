#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Pelicula {
	string title;
	string director;
	int year;
};

vector<Pelicula> leerFichero(string nomFichero) {
	ifstream filmFile(nomFichero.c_str());
	int process = 0, position = 0, TAM = 0;
	string fileLine, variable;
	vector<Pelicula> pVector;
	Pelicula p;

	if(filmFile.is_open()) {
		while(getline(filmFile, fileLine) && TAM < 100) {

			position = fileLine.find(':');

			for(unsigned int i=position+2; i< fileLine.size(); i++) {
				variable += fileLine[i];
			}

			if(process == 0) {
				p.title = variable;
				process++;
			} else if(process == 1) {
				p.director = variable;
				process++;
			} else if(process == 2) {
				p.year = atoi(variable.c_str());
				pVector.push_back(p);
				TAM++;
				process = 0;
			}

			variable.clear();
		}

		filmFile.close();
	}

	return pVector;
}	

vector<Pelicula> orderDesc(vector<Pelicula> pVector) {
	vector<Pelicula> newVector;
	Pelicula p;
	int maxPosition = 0, maxYear = 0;

	while(pVector.size() != 0) {
		for(unsigned int i=0; i<pVector.size(); i++) {
			if(pVector[i].year > maxYear) {
				maxYear = pVector[i].year;
				maxPosition = i;
			}
		}

		newVector.push_back(pVector[maxPosition]);
		pVector.erase(pVector.begin() + maxPosition);
		maxPosition = 0;
		maxYear = 0;
	}

	return newVector;
}

int main(int argc, char *argv[]) {
	vector<Pelicula> pVector;

	if(argc == 2) {
		pVector = leerFichero(argv[1]);	

		vector<Pelicula> orderDescP = orderDesc(pVector);

		for(unsigned int i=0; i<orderDescP.size(); i++) {
			cout << orderDescP[i].year << ", " <<  orderDescP[i].title << ", " <<  orderDescP[i].director << endl; 
		}

	} else {
		cout << "Formato incorrecto " << endl;
	}
	
}