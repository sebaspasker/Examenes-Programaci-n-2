#include "Collection.h"

Collection::Collection(string name) {
	this -> name = name;
}

bool 
Collection::findAlbum(const Album &album) const {
	bool founded = false;

	for(unsigned int i=0; i < aVector.size(); i++) {
		if(aVector[i].isEqualTo(album)) {
			founded = true;
		}
	}

	return founded;
}

bool 
Collection::addAlbum (const Album &album) {
	bool added = false, repetition = false;

	for(unsigned int i=0; i <  aVector.size(); i++) {
		if(aVector[i].isEqualTo(album)) {
			repetition = true;
			break;
		}
	}

	if(!repetition) {
		aVector.push_back(album);
	} else { 
		cout << "Ya existe un album igual" << endl;
	}

	return added;
}

void
Collection::findSong(const string &song) const {
	bool finded;
	int position;

	for(unsigned int i=0; i < aVector.size(); i++) {
		finded = aVector[i].findSong(song);
		
		if(finded) {
			position = i;
			break;
		}
	}

	if(finded) {
		cout << "La cancion " << song << " esta en el album " << aVector[position].getTitle();
		cout << " (" << aVector[position].getArtist() << ")" << endl;
	}
}


ostream& operator<<(ostream &os, Collection &c) {
	os << "-----" << c.name << "-----" << endl;

	for(unsigned int i=0; i< c.aVector.size(); i++) {
		os << c.aVector[i];
	}

	return os;
}
