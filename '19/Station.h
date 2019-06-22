#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

enum Value {T, TM, Tm};
enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
enum Error {ERR_FILE};

class Station {
	friend ostream& operator<<(ostream &os, const Station &s);

	private:
		string name;
		unsigned int id;
		static unsigned int nextId;
		float data[3][12];

	public:
		Station(string filename);
		float getValue(Value v, Month m) const;
		string getName() const;
};