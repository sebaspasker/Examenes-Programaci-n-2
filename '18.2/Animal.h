#include <iostream>
#include <string>

using namespace std;

enum AnimalType {
	Cat,
	Dog,
	Jerbo
};

enum Error {
	ERROR_PARAM
};

class Animal {
	friend ostream& operator<< (ostream &os, Animal &a);
	private:
		string name;
		unsigned int age;
		AnimalType type;
		string owner;
	public:
		Animal(string s);
		string getName() const;
		unsigned int getAge() const;
		AnimalType getAnimalType() const;
		string getOwner() const;
		void adopt(string owner);
		bool isAdopted() const;

};