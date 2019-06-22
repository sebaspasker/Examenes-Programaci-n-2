#include "Squadron.h"

Squadron::Squadron(string filename, string name) {
	ifstream squadronFile(filename);
	string fileLine;

	int position, position2;
	if(squadronFile.is_open()) {
		while(getline(squadronFile, fileLine)) {
			position = fileLine.find("-");
			position2 = fileLine.find(" ");

			string typeS;
			for( int i=position+1; i<position2; i++)  {
				typeS += filename[i];
			}

			position = fileLine.find("=");
			position2 = fileLine.find(",");


			string attackS;
			for( int i=position+1; i<position2; i++)  {
				attackS += filename[i];
			}

			fileLine.replace(position, 1, "X");

			position = fileLine.find("=");
			position2 = fileLine.find(")");


			string defenseS;
			for( int i=position+1; i<position2; i++)  {
				defenseS += filename[i];
			}

			int attack = stoi(attackS);
			int defense = stoi(defenseS);

			try{
				Fighter f(typeS, attack, defense);
				vectorFighter.push_back(f);
			} catch(Error e) {
				
			}
		}
	}
}

