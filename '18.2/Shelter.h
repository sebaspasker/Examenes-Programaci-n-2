#include <iostream>
#include <vector>
#include "Animal.h"

using namespace std;

class Shelter {
	friend ostream& operator<<(ostream &os, Shelter &s);
	private:
		vector<Animal> animalVector;
		static const unsigned int MAXADOPTED = 3;
		string name;
	
	public:
		Shelter(string name = "Natura Shelter");
		bool add(const Animal &a);
		bool adopt(const Animal &a, string owner);
		int search(const Animal &a) const;
		bool ownerIsValid(string owner) const;

};