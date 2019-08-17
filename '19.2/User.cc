#include "User.h"

User::User(string name, string email) {
	for(unsigned int i=0; i < name.size(); i++) {
		if(!isalnum(name[i])) {
			throw exception_name;
		}
	}

	int process = 0;
	bool err = false;
	unsigned int positionArr;

	for(unsigned int i=0; i < email.size(); i++) {
		if(process == 0 && email[i] != '@' && !isalnum(email[i])) {
			err = true;
			break;
		} else if(process == 0 && email[i] == '@') {
			process = 1;
			positionArr = i;
		} else if(process == 1 && email[i] == '.' && i == positionArr+1) {
			err = true;
			break;
		} else if(process == 1 && email[i] == '.' && i == email.size()-1) {
			err = true;
			break;
		} else if(process == 1 && !isalnum(email[i])) {
			err = true;
			break;
		}
	}


	if(err) {
		throw exception_email;
	} else {
		this -> name = name;
		this -> email = email;
	}
}

unsigned int
User::writeTweet(string text, const vector<string> &users) {
	try {
		Tweet t(text, users);
		tweetVector.push_back(t);
		return t.getId();
	} catch(Exception e) {
		if(e == exception_mention) {
			cout << "Incorrect tweet format" << endl;
			
		}
	}

	return 0;
}

void
User::addTweet(Tweet newTweet) {
	tweetVector.push_back(newTweet);
}

Tweet 
User::getTweet(int pos) const {
	if(pos < 0 || unsigned(pos) > tweetVector.size()) {
		throw exception_pos;
	} else {
		return tweetVector[pos];
	}
}

string 
User::getName() const {
	return name;
}

unsigned int 
User::getNumberOfTweets() const {
	return tweetVector.size();
}

ostream& operator<<(ostream &os, const User u) {
	os << u.name << " (" << u.email << ")" << endl;

	for(unsigned int i=0; i<u.tweetVector.size(); i++) {
		os << u.tweetVector[i] << endl;
	}

	return os;
}