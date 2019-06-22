#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>


using namespace std;

struct Palabra {
	string nombre;
	int nAparece;
};

vector<Palabra> wordExtraction(string fileName) {
	vector<Palabra> vPalabra;
	Palabra p;
	int position = 0;
	string word, line;
	bool repetition = false;

	ifstream wordFile(fileName.c_str());

	if(wordFile.is_open()) {
		while(getline(wordFile, line)) {
			for(unsigned int i=0; i<line.size();i++) {
				if(!isalpha(line[i]) && word.size() >= 1) { // Case finish word
					for(unsigned int i=0; i<vPalabra.size(); i++) { // Word repetition comprobation
						if(vPalabra[i].nombre == word) {
							repetition = true;
							position = i;
						}
					}

					if(repetition == false) { 
						p.nombre = word;
						p.nAparece = 1;
						vPalabra.push_back(p);

					} else { // Case word already saved
						vPalabra[position].nAparece++;
					}

					// Parameter reset
					position = 0;
					word.clear();
					repetition = false;


				} else if((line[i] >= 'a' && line[i] <= 'z') 
							|| 	(line[i] >= 'A' && line[i] <= 'Z')) { // Save alfabetic char
					word += tolower(line[i]);
				}
			}
				for(unsigned int i=0; i<vPalabra.size(); i++) { // Word repetition comprobation
					if(vPalabra[i].nombre == word) {
						repetition = true;
						position = i;
					}
				}

				if(word.size() == 0) {
					position = -1;
				}

				if(repetition == false && word.size() >= 1) { 
					p.nombre = word;
					p.nAparece = 1;
					vPalabra.push_back(p);
				} else if(position == -1){
					continue;
				} else { // Case word already saved
					vPalabra[position].nAparece++;
					cout << word << endl;
				}

				// Parameter reset
				position = 0;
				word.clear();
				repetition = false;
		}

		wordFile.close();

	} else {
		cout << "No abre/existe el archivo" << endl;

	}

	return vPalabra;

}

int main(int argc, char *argv[]) {
	string fileName;

	if(argc != 2) {
		cout << "Dígame el nombre del archivo" << endl;
		getline(cin, fileName);

	} else {
		fileName = argv[1];

	}
	vector<Palabra> vPalabra = wordExtraction(fileName);
	if(vPalabra.size() > 0) {
		for(unsigned int i=0; i < vPalabra.size(); i++) {
			cout << vPalabra[i].nombre << ": " << vPalabra[i].nAparece << endl;
		}
	}
}