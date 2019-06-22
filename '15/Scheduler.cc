#include "Scheduler.h"

Scheduler::Scheduler(string fileName) {
	ifstream fileHoguera(fileName);
	string fileLine, name, timeString;


	if(fileHoguera.is_open()) {

		while(getline(fileHoguera, fileLine)) {
			Hoguera  h(fileLine);
			hogueraVector.push_back(h);

		}

		fileHoguera.close();
	}
}

void
Scheduler::addTeam(string team) {
	teams.push_back(team);
}

void 
Scheduler::distributeTeams() {
	int position; 
	bool finish = false;

	while(!finish) {
		for(unsigned int i=0; i < teams.size(); i++) {
			position = Scheduler::getMinor();	
			
			if(position != -1) {
				hogueraVector[position].setTeam(teams[i]);
			} else {
				finish = true;
			}
		}
	}
}

int
Scheduler::getMinor() const {
	int position = -1;
	bool firstEntrance = true;

	for(unsigned int i=0; i<hogueraVector.size(); i++) {
		if(firstEntrance == true && hogueraVector[i].getTeam().empty()){
			firstEntrance = false;
			position = i;
		}

		if(hogueraVector[position].getTime() > hogueraVector[i].getTime() && hogueraVector[i].getTeam().empty()) {
			position = i;
		}
	}

	return position;
}

ostream& operator<<(ostream &os, Scheduler &s) {
	for(unsigned int i=0; i < s.teams.size(); i++) {
		os << "[ " << s.teams[i] << " ] : ";
		for(unsigned int j=0; j < s.hogueraVector.size(); j++) {
			if(s.hogueraVector[j].getTeam() == s.teams[i]) {
				os << s.hogueraVector[j];
			}
		}
		os << endl;
	}

	return os;
}