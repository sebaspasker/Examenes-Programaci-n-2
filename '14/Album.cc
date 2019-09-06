#include "Album.h"

Album::Album(string artist, string title, string songLine) {
	this -> artist = artist;
	this -> title = title;

	string parameter;

	for(unsigned int i=0; i<songLine.size(); i++) {
		if(songLine[i] != ',') {
			parameter += songLine[i];

		} else {
			songs.push_back(parameter);
			parameter.clear();

		}
	}

	songs.push_back(parameter);
}

bool 
Album::findSong(string song) const {
	bool finded = false;

	for(unsigned int i=0; i<songs.size(); i++) {
		if(songs[i] == song) {
			finded = true;
		}
	}

	return finded;
}

bool
Album::isEqualTo(const Album &album) const {
	bool equal = false;
	if(album.getArtist() == artist && album.getTitle() == title) {
		equal = true;
	}

	return equal;
}

string 
Album::getArtist() const {
	return artist;
}

string 
Album::getTitle() const {
	return title;
}

void
Album::setArtist(string artist) {
	this -> artist = artist;
}

void 
Album::setTitle(string title) {
	this -> title = title;
}

ostream& operator<<(ostream &os, Album &a) {
	os << a.title << " (" << a.artist << ") : ";

	for(unsigned int i=0; i< a.songs.size(); i++) {
		os << a.songs[i];
		if(i < a.songs.size()-1) {
			os << "-";
		}
	}

	os << endl;

	return os;
}