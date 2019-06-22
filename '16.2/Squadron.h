#include <iostream>
#include "Fighter.h"
#include <vector>
#include <fstream>


using namespace std;

class Squadron {
	friend ostream& operator<<(ostream &os, Squadron &s);
	private: 
		string name;
		int wins;
		int losses;
		vector<Fighter> vectorFighter;
	public:
		Squadron(string filename, string name = "");
		void fight(Squadron &enemy);
};