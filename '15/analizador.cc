#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;



vector<string> fileExtraction(bool &continuation, string file) {
	ifstream tweetsFile(file);
	string lineFile;
	vector<string> lineVector;

	if(tweetsFile.is_open()) {
		
		while(getline(tweetsFile, lineFile)) {
			lineVector.push_back(lineFile);
		}

		tweetsFile.close();
	} else {
		continuation = false;
	}

	return lineVector;
}

void buscaTotal(vector<string> tweets, string politico, vector<int> &Vencontrados, vector<int> &Vtotal ,string palabra, int iPosition) {
	int contadorTotal = 0, encontrados = 0;
	int position;
	string lineaTweet;
	bool terminated = false, encontradoPolitico = false;
			
	for(unsigned int j=0; j < tweets.size(); j++) {	
		lineaTweet = tweets[j];
		while(terminated == false) {
			position = lineaTweet.find(politico);

			if(position == -1) {
				terminated = true;
			} else {
				lineaTweet.replace(lineaTweet.begin() + position, lineaTweet.begin() + position + politico.size(), "X");
				contadorTotal++;
				encontradoPolitico = true;
			}
		}
		
		if(encontradoPolitico == true) {
			terminated = false;
			while(terminated == false) {
				position = lineaTweet.find(palabra);

				if(position == -1) {
						terminated = true;
					} else {
						lineaTweet.replace(lineaTweet.begin() + position, lineaTweet.begin() + position + palabra.size(), "X");
						encontrados++;
					
				}
			}
		}

		terminated = false;
		encontradoPolitico = false;
	}

	Vtotal[iPosition] = contadorTotal;
	Vencontrados[iPosition] = encontrados;
}

int main(int argc, char *argv[]) {
	bool continuation = true;

	if(argc == 4) {
		vector<string> tweets = fileExtraction(continuation, argv[1]);

		if(continuation == true) {
			vector<string> politicos = fileExtraction(continuation, argv[2]);

			if(continuation == true) {
				vector<int> vectorTotal;
				vector<int> vectorEncontrados;
				vector<int> vectorRatio;

				for(unsigned int i = 0; i < politicos.size(); i++) {
					vectorTotal.push_back(0);
					vectorEncontrados.push_back(0);
					vectorRatio.push_back(0);
				}

				float ratio = 0;
				for(unsigned int i=0; i < politicos.size(); i++) {
					buscaTotal(tweets, politicos[i], vectorEncontrados, vectorTotal, argv[3], i);	
					if((vectorEncontrados[i] != 0 && vectorEncontrados[i] == 0) 
						|| (vectorEncontrados[i] == 0 && vectorEncontrados[i] != 0)
						|| (vectorEncontrados[i] != 0 && vectorEncontrados[i] != 0)) {
						ratio = (float(vectorEncontrados[i])/float(vectorTotal[i]))*100;
						vectorRatio[i] = ratio;
					}
				}

				
				for(unsigned int i=0; i < politicos.size(); i++) {
					
					cout << politicos[i] << "(Total: " << vectorTotal[i] << "; Ratio: " << vectorRatio[i]<< "%)" << endl;
				}
			}
		} 
	}
}
