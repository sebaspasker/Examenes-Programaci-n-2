#include "Category.h"

Category::Category(string description, int percentage) {
	this -> description = description;
	this -> percentage = percentage;
}

void 
Category::addForbiddenNick(string nick) {
	forbiddenNicks.push_back(nick);
}

void
Category::addYoutuber(string nick, string url) {
	bool repetition = false;
	int position;

	for(unsigned int i=0; i < forbiddenNicks.size(); i++){
		position = nick.find(forbiddenNicks[i]);
		if(position != -1) {
			repetition = true;
		}
	}

	if(repetition) {
		cout << "ERROR: FORBIDDEN NICK "<< nick << endl;
	} else {
		try {
			Youtuber y(nick, url);
			yVector.push_back(y);
		} catch(Error e) {
			if(e == ERR_YOUTUBER) {
				cout << "ERROR: WRONG URL " << url << endl;
			}
		}
	}
}

void 
Category::penalize(string nick) {
	int position = -1;

	for(unsigned int i=0; i<yVector.size(); i++) {
		if(yVector[i].getNick() == nick) {
			position = i;
		}
	}

	if(position != -1) {
		if(yVector[position].isPenalized()) {
			cout  << nick  << "REMOVED" << endl;
			yVector.erase(yVector.begin() + position);
			Category::addForbiddenNick(nick);
		} else {
			yVector[position].setPenalized(true);
		}
	}
}

void 
Category::shareProfits(float profits) {
	float division = (profits/100)*percentage;

	float individualProfit = division/yVector.size();

	for(unsigned int i=0; i<yVector.size(); i++) {
		yVector[i].addProfits(individualProfit);
	}
}

ostream& operator<<(ostream &os, Category &c) {
	os << "---- Category: " << c.description << " ----" << endl;
	for(unsigned int i=0; i < c.yVector.size(); i++) {
		os << c.yVector[i];
	}

	return os;
}