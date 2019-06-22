#include <iostream>
#include <vector>
#include <fstream>
#include "Hoguera.h"

using namespace std;

class Scheduler {
	friend ostream& operator<<(ostream &os, Scheduler &s);
	private:
		vector<string> teams;
		vector<Hoguera> hogueraVector;

	public:
		Scheduler(string fileName);
		void addTeam(string team);
		void distributeTeams();
		int getMinor() const;

};