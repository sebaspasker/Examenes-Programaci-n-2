#include "Tweet.h"

unsigned int Tweet::nextId = 1;

bool noUserRepetition(vector<string> vs, string parameter) {
	bool noRepetition = true;

	for(unsigned int i=0; i < vs.size(); i++) {
		if(vs[i] == parameter) {
			noRepetition = false;
			break;
		}
	}

	return noRepetition;
}

vector<string> searchUsers(string text) {
	bool mention = false;
	vector<string> vs;
	string parameter;

	for(unsigned int i=0; i < text.size(); i++) {
		if(text[i] == '@') {
			mention = true;
		} else if(mention) {
			if(!isalnum(text[i])) {
				mention = false;

				if(noUserRepetition(vs, parameter)){
					vs.push_back(parameter);
				}
				parameter.clear();

			} else if(isalnum(text[i])) {
				parameter += text[i];
			}
		}
	}

	return vs;
}

bool userComparation(vector<string> mentionedUsers, vector<string> users) {
	bool repetition = false, allCorrect = true;

	for(unsigned int i=0; i < mentionedUsers.size(); i++) {
		for(unsigned int j=0; j < users.size(); j++) {
			if(mentionedUsers[i] == users[j]) {
				repetition = true;
			}
		}

		if(!repetition) {
			allCorrect = false;
			break;
		}

		repetition = false;
	}

	return allCorrect;
}

Tweet::Tweet(string text, const vector<string> &users) {
	vector<string> mentionedUsers = searchUsers(text);

	if(!userComparation(mentionedUsers, users)) {
		throw exception_mention;

	} else {
		id = Tweet::nextId;
		Tweet::nextId++;
		this-> text = text;

	}
}

string 
Tweet::getText() const {
	return text;
}

unsigned int 
Tweet::getId() const {
	return id;
}

vector<string>
Tweet::getMentions() const {
	vector<string> mentionedUsers = searchUsers(text);
	return mentionedUsers;
}

ostream& operator<<(ostream &os, const Tweet &t) {
	os << "[" << t.id << "] " << t.text;

	return os;
}	