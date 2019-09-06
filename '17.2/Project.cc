#include "Project.h"

int Project::nextId = 1;

Project::Project(string line) {
	string l;

	for(unsigned int i=0; i<line.size(); i++) {
		if(line[i] == '=') {
			this -> name = l;
			l.clear();

		} else {
			l += line[i];

		}
	}

	time = atoi(l.c_str());
	id = Project::nextId;
	Project::nextId++;
	team.empty();
}

int
Project::getTime() const {
	return time;
}

string
Project::getName() const {
	return name;
}

string
Project::getTeam() const {
	return team;
}

void
Project::setTime(int time ) {
	this -> time = time;
}

void
Project::setTeam(string team) {
	this -> team = team;
}

ostream& operator<<(ostream &os, const Project &p) {
	os << p.name << " (" << p.id << ")= " << p.time << " ";

	return os;
}