#include "List.h"

List::List(string name) {
	this -> name = name;
}


bool
List::searchMovie(string title) const {
	bool Exist = false;
	for(unsigned int i=0; i < vectorMovie.size(); i++) {
		if(title == vectorMovie[i].getTitle()) {
			Exist = true;
		}
	}
	return Exist;
}


void 
List::addMovie(string desc, Genre genre) {
	int process = 0;
	string name, stringScore;
	int score;

	for(unsigned int i=0; i < desc.size(); i++) {
		if(process == 0 && desc[i] != ',') {
			name += desc[i];
		} else if(process == 0 && desc[i] == ',') {
			process = 1;
		} else if(process == 1) {
			stringScore += desc[i];
		}
	}
	score = stoi(stringScore);
	bool Exist = List::searchMovie(name);

	if(!Exist){
		try {
			Movie m(name, genre,score);
			vectorMovie.push_back(m);

		} catch(Error e) {
			if(e == ERR_SCORE) {
				cout << "Wrong movie " << name << endl;
			}
		}
	}
}

float
List::getMeanScore() const {
	float sum = 0;

	for(unsigned int i=0; i < vectorMovie.size(); i++) {
		sum += vectorMovie[i].getScore();
	}

	return sum/vectorMovie.size();
}

ostream& operator<<(ostream &os, List &l) {

	os << l.name << endl;
	os << l.getMeanScore() << endl;

	for(unsigned int i=0; i < l.vectorMovie.size(); i++) {
		os << l.vectorMovie[i];
	}

	return os;
}