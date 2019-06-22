#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>



using namespace std;

const string CONST_INDEX = "index.txt";
const string CONST_DOCUMENTS = "documents.bin";

// Struct siempre primero mayúsculas

struct Index {
	string nombre;
	vector<int> documento; // Registado por orden en el documento
	vector<int> veces;
};

struct Document {
	char title[50];
	char url[50];
	int length;
};

Index extraePalabra(string palabra) {
	ifstream fileIndex(CONST_INDEX.c_str());
	string lineaFile;
	string nameCpy;
	Index indexReturn;
	int process = 0, documento = 0, veces = 0;

	if(fileIndex.is_open()) {
		while(getline(fileIndex, lineaFile)) {
			for(unsigned int i=0; i < lineaFile.size(); i++) {
				if(process == 0 && lineaFile[i] != '|') {
					nameCpy += lineaFile[i];
				} else if(process == 0 && lineaFile[i] == '|') {
					if(nameCpy == palabra) {
						process = 1;
						indexReturn.nombre = nameCpy;
					} else {
						break;
					}
				} else if(process == 1 && lineaFile[i] != ':') {
					documento = documento*10 + (lineaFile[i] - '0');
				} else if(process == 1 && lineaFile[i] == ':') {
					process = 2;
					indexReturn.documento.push_back(documento);
					documento = 0;
				} else if(process == 2 && i == lineaFile.size()-1 ) {
					veces = veces*10 + (lineaFile[i] - '0');
					indexReturn.veces.push_back(veces);	
				} else if(process == 2 && lineaFile[i] != '|') {
					veces = veces*10 + (lineaFile[i] - '0');				
				} else if(process == 2 && lineaFile[i] == '|' ) {
					process = 1;
					indexReturn.veces.push_back(veces);
					veces = 0;
				}
			}

			if(palabra == indexReturn.nombre) {
				break;
			} else {
				process = 0;
				nameCpy.clear();
			}
		}

		fileIndex.close();
	}

	return indexReturn;
}

vector<Document> extraeDocument(Index indexWord) {
	ifstream fileDocument(CONST_DOCUMENTS, ios::binary);
	vector<Document> vectorDocument;
	Document documentExtraction;

	if(fileDocument.is_open()) {

		for(unsigned int i=0; i<indexWord.documento.size(); i++) {
			fileDocument.seekg((indexWord.documento[i])*sizeof(Document), ios::beg);
			fileDocument.read((char*)&documentExtraction, sizeof(documentExtraction));
			vectorDocument.push_back(documentExtraction);
		}

		fileDocument.close();
	}

	return vectorDocument;
}


void saveDocument() {
	Document documento;
	vector<Document> vectorDocumento;
	char title[50] = "HOLA QUE TAL\0", url[50] = "https://www.holaquetal.com/";
	strcpy(documento.title,title);
	strcpy(documento.url,url);
	documento.length = 50;
	vectorDocumento.push_back(documento);
	strcpy(documento.title,"ADIOS MUY BUENAS");
	strcpy(documento.url,"https://www..............com/\0");
	documento.length = 10;
vectorDocumento.push_back(documento);
	strcpy(documento.title,"ME ALEGRO");
	strcpy(documento.url,"https://www.-------.com/\0");
	documento.length = 20;
vectorDocumento.push_back(documento);
	strcpy(documento.title,"CHAOR");
	strcpy(documento.url,"https://www.ḉḉḉḉḉḉç.com/\0");
	documento.length = 40;
vectorDocumento.push_back(documento);

	strcpy(documento.title,"CHAOR");
	strcpy(documento.url,"https://www.ḉḉḉḉḉḉç.com/\0");
	documento.length = 40;
vectorDocumento.push_back(documento);
	strcpy(documento.title,"go");
	strcpy(documento.url,"https://www.ññññ.com/\0");
	documento.length = 34;
vectorDocumento.push_back(documento);
	ofstream fileSave(CONST_DOCUMENTS, ios::binary);

	if(fileSave.is_open()) {
		for(unsigned int i=0; i < vectorDocumento.size(); i++) {
		fileSave.write((const char *)&vectorDocumento[i], sizeof(Document));
		}

		fileSave.close();
	}
}



int main(int argc, char *argv[]) {
	Index indexWord;
	if(argc == 2) {
		indexWord = extraePalabra(argv[1]);	
		if(!indexWord.nombre.empty()) {
			vector<Document> DocumentWord = extraeDocument(indexWord);
			
			int position = 0;
			float frecuenciaInicial;

			
			for(unsigned int i=0; i < DocumentWord.size(); i++) {
				float vecesCpy = indexWord.veces[i];
				float lengthCpy = DocumentWord[i].length;
				if((indexWord.veces[i]/DocumentWord[i].length)*100 > frecuenciaInicial) {
					frecuenciaInicial = vecesCpy/lengthCpy;
					position = i;
				}
			}	
			
			cout << DocumentWord[position].title << " (" << DocumentWord[position].url << ") [" << frecuenciaInicial << "] " << endl;

		} else {
			cout << "Error, no se ha encontrado la palabra" << endl;
		}
	}
	
	return 0;
}
