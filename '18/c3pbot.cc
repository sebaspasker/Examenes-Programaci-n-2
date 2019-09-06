#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

const string CONST_RESP = "respuestas.txt";

struct palabraPuntos {
	string palabra;
	int puntos;
};

// Extract Question and Answers of file
vector<string> QandAExtraction(vector<string> &aVector) {
	string parameter, line;
	ifstream QAfile(CONST_RESP.c_str());
	vector<string> qVector;
	bool first = false;

	if(QAfile.is_open()) {

		while(getline(QAfile, line)) {
			for(unsigned int i=0; i < line.size(); i++) {
				if(first) {								 // Case reading answer
					parameter += line[i];
				} else if(line[i] == '|') { // Save Question
					qVector.push_back(parameter);
					parameter.clear();
					first = true;
				} else if(isalnum(line[i])) { // Case reading question
					parameter += tolower(line[i]);

				} else if(line[i] == ' ') {   // "       "       " 
					parameter += line[i];

				}
			}

			first = false;
			aVector.push_back(parameter); // Save answer and reset parameter and 
																		// first entrance
			parameter.clear();
		}

		QAfile.close();
	}

	return qVector;
}

// Save words separated and sum points of each word
vector<palabraPuntos> separaPalabras(string line) {
	string parameter;
	int contador = 0;
	vector<palabraPuntos> palabras;
	palabraPuntos p;

	for(unsigned int i=0; i < line.size(); i++) {
		if(line[i] != ' ') {
			parameter += line[i];
			contador++;
		} else {
			p.palabra = parameter;
			p.puntos = contador;
			palabras.push_back(p);
			parameter.clear();
			contador = 0;
		}
	}


	p.palabra = parameter;
	p.puntos = contador;
	palabras.push_back(p);

	return palabras;
}

                                                 
string buscaRespuesta(vector<string> aVector, vector<string> qVector, string pregunta) {
	int puntosLinea = 0, puntosMaxLinea = -1, positionMaxLinea = 0;
	vector<palabraPuntos> palabrasQ;
	vector<palabraPuntos> palabrasPregunta;

	palabrasPregunta = separaPalabras(pregunta);      	// Separate words of particular question
																											// and asign points
	for(unsigned int i=0; i < qVector.size(); i++) {
		palabrasQ = separaPalabras(qVector[i]); 					// Separate words of general 
																											// questions and asign points

		for(unsigned int i=0; i < palabrasPregunta.size(); i++) {
			for(unsigned int j=0; j < palabrasQ.size(); j++) {
				if(palabrasPregunta[i].palabra == palabrasQ[j].palabra) {
					puntosLinea += palabrasPregunta[i].puntos; 	// Comparate particular & general word
				}
			}
		}

		if(puntosLinea > puntosMaxLinea) { // Save position with more points
			puntosMaxLinea = puntosLinea;
			positionMaxLinea = i;
		}

		puntosLinea = 0;
		palabrasQ.clear();
	}

	return aVector[positionMaxLinea];

}

int main() {
	string pregunta, respuesta;

	cout << "Hola, soy C3PBoy. Escribe su pregunta a continuación: " << endl;
	getline(cin, pregunta);

	vector<string> aVector;
	vector<string> qVector = QandAExtraction(aVector); // Save answer and questions

	respuesta = buscaRespuesta(aVector, qVector, pregunta); // Search answer
	cout << respuesta << endl;
}