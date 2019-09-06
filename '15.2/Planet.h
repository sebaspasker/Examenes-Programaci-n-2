#include <iostream>
#include <stdlib.h>

using namespace std;

class Planet  {
	friend ostream& operator<<(ostream &os, const Planet &p);
	private:
		string name;
		string sector;
		char letter;
		int number;

	public:
		Planet(string name="Odik", string sector="", string coord = "K11");
		float distance(const Planet &p) const;
};