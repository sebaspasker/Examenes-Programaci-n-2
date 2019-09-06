#include <iostream>
#include <stdlib.h>

using namespace std;

class Project {
	friend ostream& operator<<(ostream &os, const Project &p);
	private:
		static int nextId;
		int id;
		string team;
		int time;
		string name;

	public:
		Project(string line);
		int getTime() const;
		string getName() const;
		string getTeam() const;
		void setTime(int time);
		void setTeam(string team); 
};