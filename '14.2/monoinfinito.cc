#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <fstream>

const char dccFile[] = "diccionario.txt";

using namespace std;

struct charWords {
	int wordSize;
	vector<string> wordVector;
	vector<string> dictionaryWord;
};

// Creates a random word vector of input size (vector size 10000)
charWords wordsCreator(int size) {
	charWords w;
	string word;
	char c;

	w.wordSize = size;

	for(unsigned int i=0; i<10000; i++) {
		for(int j=0; j<size; j++) {
			c = rand()%26+'a';
			word += c;
		}

		w.wordVector.push_back(word);
		word.clear();
	}


	return w;
}

// Save words with same in range size
vector<charWords> dictionaryExtraction(vector<charWords> oldVector) {
	vector<charWords> newVector = oldVector;
	ifstream dictionaryFile(dccFile);
	string line;

	if(dictionaryFile.is_open()) {
		while(getline(dictionaryFile, line)) {
			for(unsigned int i=0; i<newVector.size(); i++) {
				if(line.size() == unsigned(newVector[i].wordSize)) {
					newVector[i].dictionaryWord.push_back(line);
				}
			}
		}

		dictionaryFile.close();
	}

	return newVector;
}

// Prints when random word and dictionary word concur
void printSameWords(vector<charWords> charWordsVector) {
	bool firstEntrance = true;

	for(unsigned int i=0; i<charWordsVector.size(); i++) {  
		for(unsigned int j=0; j<charWordsVector[i].dictionaryWord.size(); j++) {
			for(unsigned k=0; k<charWordsVector[i].wordVector.size(); k++) {
				if(charWordsVector[i].dictionaryWord[j] == charWordsVector[i].wordVector[k]) {
					if(firstEntrance) {
						cout << "- Longitud " << charWordsVector[i].wordSize << ":"<< endl;
						firstEntrance = false;
					}

					cout << charWordsVector[i].dictionaryWord[j] << endl;
					break;
				} 
			}
		}

		firstEntrance = true;
	}
}

int main(int argc, char *argv[]) {
	vector<charWords> charWordsVector;
	charWords words;
	if(argc == 3)  {

		for(int i= atoi(argv[1]); i <= atoi(argv[2]); i++) {
			words = wordsCreator(i);
			charWordsVector.push_back(words);
		}

		charWordsVector = dictionaryExtraction(charWordsVector);
		printSameWords(charWordsVector);
		
	} else {
		cout << "Incorrect parameters" << endl;
	}
}