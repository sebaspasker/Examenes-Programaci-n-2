#include "Project.h"
#include <vector>
#include <fstream>

class Startup {
	friend ostream& operator<<(ostream &os, const Startup &s);
	private:
		string name;
		vector<string> teams;
		vector<Project> projects;

	public:
		Startup(string filename);
		bool projectExists(Project p) const;
		void addTeam(string teams);
		void distributeTeams();
		int getMinor() const;
};