#include <iostream>

using namespace std;

enum Genre {
	Action,
	SciFi,
	Drama, 
	Comedy
};

enum Error {
	ERR_SCORE
};

class Movie {
	friend ostream& operator<<(ostream &os, Movie &m);
	private:
		static const int NS = -1;
		string title;
		int score;
		Genre genre;

	public:
		Movie(string title, Genre genre, int score = NS);
		string getTitle() const;
		int getScore() const;
		Genre getGenre() const;
		static string genreToString(Genre genre);

};