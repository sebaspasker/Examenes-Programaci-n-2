#include "Planet.h"
#include <vector>

using namespace std;

class Route {
	friend ostream& operator<<(ostream &os, Route &r);
	private:
		string name;
		vector<Planet> planetVector;

	public:
		Route(string name, const Planet &origin);
		int closest(const Planet &p) const;
		void addPlanet(const Planet &p);
		string getName() const;
		void setName(string name);
};  