#include <iostream>
#include <string>

using namespace std;

class Hoguera {
	friend ostream& operator<<(ostream &os, Hoguera &h);
	private:
		static int idNextHoguera;
		int id;
		string team;
		int time;
		string name;
	public:
		Hoguera(string line);
		int getTime() const;
		string getTeam() const;
		void setTime(int time);
		void setTeam(string team);

};