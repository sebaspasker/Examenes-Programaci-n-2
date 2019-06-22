#include <iostream>
#include "Region.h"

int main() {
	Region r("Comunitat Valenciana");

	r.addStation("station.txt");
	r.addStation("station2.txt");
	r.addStation("inventado.txt");

	cout << r.getValue("Alicante", Tm, Sep) << endl;
	cout << r.getAvgTemp(Dec) << endl;
	cout << r.getWarmestStation(Dec) << endl;
}