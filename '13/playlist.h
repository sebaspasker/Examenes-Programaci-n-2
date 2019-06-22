#include <iostream>
#include <vector>
#include "cancion.h"

using namespace std;

class Playlist {
	friend ostream& operator<<(ostream &os, const Playlist &p);
	private:
		string nombre;
		vector<Cancion> cVector;

	public:
		Playlist(string nombre);
		float getPuntuacionMedia() const;
		vector<string> getArtistas() const;
		bool anyadirCancion(const Cancion &c);
		bool buscarCancion(const Cancion &c);
};