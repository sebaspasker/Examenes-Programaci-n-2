#include <iostream>
#include "Station.h"
#include <vector>

using namespace std;

class Region {
	private:
		string name;
		vector<Station> stationVector;
	public:
		Region(string name);
		bool addStation(string filename);
		int findStation(string name) const;
		float getValue(string name, Value v, Month m) const;
		float getAvgTemp(Month m) const;
		string getWarmestStation(Month m) const;

};