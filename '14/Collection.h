#include "Album.h"

using namespace std;

class Collection {
	friend ostream& operator<<(ostream &os, Collection &c);
	private:
		string name;
		vector<Album> aVector;

	public:
		Collection(string name="");
		bool findAlbum(const Album &album) const;
		bool addAlbum(const Album &album);
		void findSong(const string &song) const;
};