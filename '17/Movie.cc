#include "Movie.h"

Movie::Movie(string title, Genre genre, int score) {
	if(score < -1 || score > 5) {
		throw ERR_SCORE;
	} else {
		this-> title = title;
		this-> genre = genre;
		this-> score = score;
	}
}

string
Movie::getTitle() const {
	return title;
}

int
Movie::getScore() const {
	return score;
}

Genre
Movie::getGenre() const {
	return genre;
}

string
Movie::genreToString(Genre genre) {
	string stringGenre;

	if(genre == Action) {
		stringGenre = "Action";
	} else if(genre == SciFi) {
		stringGenre = "SciFi";
	} else if(genre == Drama) {
		stringGenre = "Drama";
	} else if(genre == Comedy) {
		stringGenre = "Comedy";
	}

	return stringGenre;
}

ostream& operator<<(ostream &os, Movie &m) {
	os << m.title << " (" << m.score << ") " << m.genreToString(m.genre) << endl;
	return os;
}