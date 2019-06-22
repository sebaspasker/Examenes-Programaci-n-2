#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

struct Relaciones {
	char nombre1[40];
	int relacion;
	char nombre2[40];
};

struct Personaje {
	string name;
	vector<string> relatives;
	vector<string> enemies;
	vector<string> friends;
};

vector<Relaciones> extractRelaciones(string fileName) {
	vector<Relaciones> vectorRelaciones;
	Relaciones r;
	
	ifstream fileRelaciones (fileName, ios::binary);
	
	if(fileRelaciones.is_open()) {
		fileRelaciones.seekg(0, ios::end);

		unsigned int TAM = fileRelaciones.tellg()/sizeof(Relaciones);
		fileRelaciones.seekg(0, ios::beg);
		for(unsigned int i=0; i < TAM; i++) {
			fileRelaciones.read((char*)&r, sizeof(Relaciones));
			vectorRelaciones.push_back(r);
		}

		fileRelaciones.close();
	}/*
	ofstream fileRelaciones (fileName, ios::binary);	

	if(fileRelaciones.is_open()) {
		strcpy(r.nombre2 ,"Juan\0");
		strcpy(r.nombre1 ,"Esteban\0");
		r.relacion = 0;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Esteban\0");
		strcpy(r.nombre1 ,"Maria\0");
		r.relacion = 1;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Maria\0");
		strcpy(r.nombre1 ,"Juan\0");
		r.relacion = 0;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Juana\0");
		strcpy(r.nombre1 ,"Maria\0");
		r.relacion = 1;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Maria\0");
		strcpy(r.nombre1 ,"Esteban\0");
		r.relacion = 0;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Sebas\0");
		strcpy(r.nombre1 ,"Javi\0");
		r.relacion = 2;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Sebas\0");
		strcpy(r.nombre1 ,"Esteban\0");
		r.relacion = 2;
		vectorRelaciones.push_back(r);
		strcpy(r.nombre2 ,"Sebas\0");
		strcpy(r.nombre1 ,"Maria\0");
		r.relacion = 1;
		vectorRelaciones.push_back(r);

		for(unsigned int i=0; i < vectorRelaciones.size(); i++) {
			fileRelaciones.write((const char*)&vectorRelaciones[i], sizeof(Relaciones));
		}


		fileRelaciones.close();
	}*/
	return vectorRelaciones;
}

bool buscarCopia(string name, vector<Personaje> vectorPersonajes) {
	bool existe = false;
	for(unsigned int i=0; i<vectorPersonajes.size(); i++) {	
		if(name == vectorPersonajes[i].name) {
			existe = true;
		}
	}
	return existe;
}

vector<Personaje> creaPersonajes(vector<Relaciones> vectorRelaciones) {
	vector<Personaje> vectorPersonajes;
	Personaje p;
	bool existe = false;

	for(unsigned int i=0; i < vectorRelaciones.size(); i++) {
		existe = buscarCopia(vectorRelaciones[i].nombre1, vectorPersonajes);
		if(!existe) {
			p.name = vectorRelaciones[i].nombre1;
			vectorPersonajes.push_back(p);
		}
		existe = buscarCopia(vectorRelaciones[i].nombre2, vectorPersonajes);
		if(!existe) {
			p.name = vectorRelaciones[i].nombre2;
			vectorPersonajes.push_back(p);
		}
	}

	for(unsigned int i=0; i < vectorPersonajes.size(); i++) {
		for(unsigned int j=0; j < vectorRelaciones.size(); j++) {
			if(vectorPersonajes[i].name == vectorRelaciones[j].nombre1
				&& vectorRelaciones[i].relacion == 0) {
				vectorPersonajes[i].relatives.push_back(vectorRelaciones[j].nombre2);

			} else if(vectorPersonajes[i].name == vectorRelaciones[j].nombre2
				&& vectorRelaciones[i].relacion == 0) {
				vectorPersonajes[i].relatives.push_back(vectorRelaciones[j].nombre1);

			} else if(vectorPersonajes[i].name == vectorRelaciones[j].nombre1
				&& vectorRelaciones[i].relacion == 1) {
				vectorPersonajes[i].enemies.push_back(vectorRelaciones[j].nombre2);

			} else if(vectorPersonajes[i].name == vectorRelaciones[j].nombre2
				&& vectorRelaciones[i].relacion == 1) {
				vectorPersonajes[i].enemies.push_back(vectorRelaciones[j].nombre1);

			} else if(vectorPersonajes[i].name == vectorRelaciones[j].nombre1
				&& vectorRelaciones[i].relacion == 2) {
				vectorPersonajes[i].friends.push_back(vectorRelaciones[j].nombre2);

			} else if(vectorPersonajes[i].name == vectorRelaciones[j].nombre2
				&& vectorRelaciones[i].relacion == 2) {
				vectorPersonajes[i].friends.push_back(vectorRelaciones[j].nombre1);

			}
		}
	}
	return vectorPersonajes;
	
} 

void imprimRelaciones(vector<Personaje> vectorPersonajes) {
	for(unsigned int i=0; i <vectorPersonajes.size(); i++) {
		cout << "Name: " << vectorPersonajes[i].name << endl;
		
		if(vectorPersonajes[i].relatives.size() != 0) {
			cout << "Relatives: " ;

			for(unsigned int j=0; j < vectorPersonajes[i].relatives.size(); j++) {
				cout << vectorPersonajes[i].relatives[j];

				if(j != vectorPersonajes[i].relatives.size()-1)
					cout << ", ";
			}
			cout << endl;
		}
		if(vectorPersonajes[i].enemies.size() != 0) {
			cout << "Enemies: ";

			for(unsigned int j=0; j < vectorPersonajes[i].enemies.size(); j++) {
				cout << vectorPersonajes[i].enemies[j];

				if(j != vectorPersonajes[i].enemies.size()-1)
					cout << ", ";
			}
			cout << endl;
		}

		if(vectorPersonajes[i].friends.size() != 0) {
			cout << "Friends ";

			for(unsigned int j=0; j < vectorPersonajes[i].friends.size(); j++) {
				cout << vectorPersonajes[i].friends[j];

				if(j != vectorPersonajes[i].friends.size()-1)
					cout << ", ";
			}
			cout << endl;
		}

		cout << endl;
	}
}


void imprimRelaciones(vector<Relaciones> vectorRelaciones) {
}

int main(int argc, char *argv[]) {	
	if(argc == 2) {
		vector<Relaciones> vectorRelaciones = extractRelaciones(argv[1]);
		vector<Personaje> vectorPersonaje = creaPersonajes(vectorRelaciones);

		imprimRelaciones(vectorPersonaje);
	}
}

