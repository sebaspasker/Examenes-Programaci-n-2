#include <iostream>
#include "Movie.h"
#include <string.h>
#include <vector>

using namespace std;

class List {
	friend ostream& operator<<(ostream &os, List &l);
	private:
		string name;
		vector<Movie> vectorMovie;

	public:
		List(string name);
		void addMovie(string desc, Genre genre);
		bool searchMovie(string title) const;
		float getMeanScore() const;
}; 