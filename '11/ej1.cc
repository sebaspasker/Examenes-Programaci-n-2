#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;


// Line extraction from file
vector<string> lineExtraction(string fileName, bool &error) {
	ifstream lineFile(fileName.c_str());
	string line;
	vector<string> lineVector;

	if(lineFile.is_open()) {
		while(getline(lineFile, line)) {
			lineVector.push_back(line);
		}

		lineFile.close();
	} else {	
		error = true;
	}

	return lineVector; 
}

// Diferent word count
vector<int> countWords(vector<string> lineVector) {
	vector<int> distinctWordN;
	vector<string> distinctWord;
	int distinctWordLine = 0;
	string word;
	bool repetition = false;


	for(unsigned int i=0; i < lineVector.size(); i++) {
		for(unsigned int j=0; j < lineVector[i].size(); j++) {
			if(lineVector[i][j] != ' ') { 
				if((   lineVector[i][j] >= 'a'
					 && lineVector[i][j] <= 'z')
					 || ( lineVector[i][j] >= 'A'
					 && lineVector[i][j] <= 'Z')) {

					word += toupper(lineVector[i][j]);
				}
			} else if(lineVector[i][j] == ' ') {
				for(unsigned int k=0; k<distinctWord.size(); k++) {
					if(word == distinctWord[k]) {
						repetition = true;
					}
				}

				if(repetition == false && word.size() >= 2) {
					distinctWord.push_back(word);
					distinctWordLine++;
				}

				repetition = false;

				word.clear();
			}
		}

		for(unsigned int k=0; k<distinctWord.size(); k++) {
			if(word.compare(distinctWord[k]) == 0) {
				repetition = true;
			}
		}

		if(repetition == false) {
			distinctWordLine++;
			distinctWord.push_back(word);
		}
		repetition = false;

		word.clear();
		distinctWord.clear();
		distinctWordN.push_back(distinctWordLine);
		distinctWordLine = 0;
	}

	return distinctWordN;
}

int main(int argc, char *argv[]) {
	bool error = false;

	if(argc == 2) {

		vector<string> lineVector = lineExtraction(argv[1], error);
		if(error == false) {

			vector<int> distinctWordVector = countWords(lineVector);

			for(unsigned int i=0; i< distinctWordVector.size(); i++) {
				cout << distinctWordVector[i] << " " << lineVector[i] << endl;
			}
		}
	} else {
		cout << "Error, no/too many arguments introduced" << endl;
	}
}