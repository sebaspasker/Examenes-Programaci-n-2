#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int MAX_NOM = 10;
const string fileCompra = "compra.dat";

struct ProductoBin {
	char nombre[MAX_NOM];
	int precio;
	int unidades;
};

int searchValue(string paramater, vector<ProductoBin> pVector) {
	int position = -1;
	for(unsigned int j=0; j < pVector.size(); j++) {
		if(strncmp(pVector[j].nombre, paramater.c_str(), 10) == 0) {
			position = j;
		}
	}

	return position;
}

// Save name and unity of defected values
vector<ProductoBin> productCant(string fileNameCant, bool &Error) {
	ifstream file(fileNameCant.c_str());
	string line, paramater;
	ProductoBin p;
	vector<ProductoBin> pVector;
	int position = 0;

	if(file.is_open()) {

		while(getline(file, line)) {
			for(unsigned int i=0; i < line.size(); i++) {
				if(line[i] != ' ') { 
					paramater += line[i];
				} else {	// Case it's a space save name if no repetition and count number of ç
									// defectous products

					position = searchValue(paramater, pVector);

					if(position != -1) {
						pVector[position].unidades++;
					} else {
						strncpy(p.nombre, paramater.c_str(), 10);
						p.nombre[10] = '\0';
						p.unidades = 1;

						pVector.push_back(p);
					}

					paramater.clear(); 
				}
			}

			// Save last value --> No space
			position = searchValue(paramater, pVector);

			if(position != -1) {
				pVector[position].unidades++;
			} else {
				strncpy(p.nombre, paramater.c_str(), 10);
				p.nombre[10] = '\0';
				p.unidades = 1;

				pVector.push_back(p);
			}

			paramater.clear(); 
		}

		file.close();
	} else {
		cout << "Error, file can't open" << endl;
		Error = true;

	}

	return pVector;
}


// Save price of each product
vector<ProductoBin> productPrecio(string fileNamePrecio, vector<ProductoBin> pVector, bool &Error) {
	ifstream file(fileNamePrecio.c_str());
	string line, paramater;
	int position = 0;
	bool number = false;

	if(file.is_open()) {

		while(getline(file, line)) {
			for(unsigned int i=0; i < line.size(); i++) {
				if(line[i] != ' ') {
					paramater += line[i];

				} else if(!number && line[i] == ' ') { // First search value of name and save value
																							 // Create new search function here

				position = searchValue(paramater, pVector);

				paramater.clear(); 
				number = true;

				} 
			}

			if(position != -1) { // Case name founded save value in X position
				pVector[position].precio = atoi(paramater.c_str());
			}

			paramater.clear();
			number = false;
		}
		

		file.close();
	} else {
		cout << "Error, file can't open" << endl;
		Error = true;

	}

	return pVector;
}


void productImportation(vector<ProductoBin> pVector) {
	ofstream pFile(fileCompra.c_str(), ios::binary);
	
	if(pFile.is_open()) {

		for(unsigned int i=0; i < pVector.size(); i++) {
			pFile.write((const char *)&pVector[i], sizeof(ProductoBin) ); 
		}

		pFile.close();
	} else {
		cout << "Error, file can't open" << endl;
	} 

	/*
	ProductoBin p;
	ifstream pFile(fileCompra.c_str(), ios::binary);

	if(pFile.is_open()) {

		pFile.seekg(0, ios::end);
		int size = pFile.tellg()/sizeof(ProductoBin);
		pFile.seekg(0, ios::beg);

		for(unsigned int i=0; i < size; i++) {
			pFile.read((char *)&p, sizeof(ProductoBin) ); 
			cout << p.nombre << " " << p.precio << " " << p.unidades << endl;
		}

		pFile.close();
	} else {
		cout << "Error, file can't open" << endl;
	}

	READING FOR CORRECT DATA COMPROVATION

	*/


}

void printProducts(vector<ProductoBin> pVector) {
	int costeTotal = 0;
	cout << endl;


	for(unsigned int i=0; i < pVector.size(); i++) {
		cout << pVector[i].nombre << ": " << pVector[i].unidades << " x " << pVector[i].precio << " = " << pVector[i].unidades*pVector[i].precio << endl;
		costeTotal += pVector[i].unidades*pVector[i].precio;
	}

	cout << "------------------------" << endl;
	cout << "Coste: " << costeTotal << endl;
	cout << "------------------------" << endl;
	cout << endl;
}

int main(int argc, char *argv[]) {	
	bool Error = false;

	if(argc == 3) {
		vector<ProductoBin> pVector = productCant(argv[1], Error);
		if(!Error) {
			pVector = productPrecio(argv[2], pVector, Error);		
			if(!Error) {
				printProducts(pVector);
				productImportation(pVector);	
			}
			
		}

  } else  {
  	cout << "Incorrect input parameters" << endl;

  }


}  
