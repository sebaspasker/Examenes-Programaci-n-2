#include <iostream>
#include <vector>

using namespace std;

class Album {
	friend ostream& operator<<(ostream &os, Album &a);
	private:
		string artist;
		string title;
		vector<string> songs;

	public:
		Album(string artist, string title, string songLine);
		bool findSong(string song) const;
		bool isEqualTo(const Album &album) const;
		string getArtist() const;
		string getTitle() const;
		void setArtist(string artist);
		void setTitle(string title);		
};