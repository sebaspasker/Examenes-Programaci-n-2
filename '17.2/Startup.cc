#include "Startup.h"

Startup::Startup(string filename) {
	ifstream fileStart(filename.c_str());
	string line;
	bool firstEntrance = true;

	if(fileStart.is_open()) {
		while(getline(fileStart, line)) {
			if(firstEntrance) {
				firstEntrance = false;
				name = line;
			} else {
				Project p(line);
				if(!Startup::projectExists(p)) {
					projects.push_back(p);
				}
			}
		}
	}
}

bool 
Startup::projectExists(Project p) const {
	bool exist = false;

	for(unsigned int i=0; i < projects.size(); i++) {
		if(projects[i].getName() == p.getName()) {
			exist = true;
		}
	}

	return exist;
}

void
Startup::addTeam(string teams) {
	this -> teams.push_back(teams);
}

void 
Startup::distributeTeams() {
	int position = 0, i = 0;
	bool exit = false;

	while(!exit) {
		position = Startup::getMinor();

		if(position != -1) {
			projects[position].setTeam(teams[i]);
		} else {
			exit = true;
		}

		i++;

		if(unsigned(i) == teams.size()) {
			i = 0;
		}
	}
}

int
Startup::getMinor() const {
	int minorPosition = -1, minorValue;
	bool firstEntrance = true, allTeam = true;

	for(unsigned int i=0; i < projects.size(); i++) {
		if(projects[i].getTeam().empty()) {
			allTeam = false;
		}
	}

	if(!allTeam) {
		for(unsigned int i=0; i < projects.size(); i++) {
			if(firstEntrance && projects[i].getTeam().empty()) {
				minorPosition = i;
				minorValue = projects[i].getTime();
				firstEntrance = false;

			} else if(minorValue > projects[i].getTime() && projects[i].getTeam().empty()) {
				minorPosition = i;
				minorValue = projects[i].getTime();

			}
		}
	}

	return minorPosition;
}

ostream& operator<<(ostream &os, const Startup &s) {
	os << s.name << endl;
	os << "--------------" << endl;
	for(unsigned int i=0; i < s.teams.size(); i++) {
		os << s.teams[i] << ": ";

		for(unsigned int j=0; j < s.projects.size(); j++) {
			if(s.teams[i] == s.projects[j].getTeam()) {
				os << s.projects[j];
			}
		}
		cout << endl;
	}

	return os;
}