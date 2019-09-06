#include "Youtuber.h"

Youtuber::Youtuber(string nick, string url) {
	if(!nick.empty() && !url.empty()) {
		if(url.find("http://www.youtube.com/channel/") == 0) {
			this -> nick = nick;
			this -> url = url;
			profits = 0;
			penalized = false;

		} else {
			throw ERR_YOUTUBER;
		}
	} else {
		throw ERR_YOUTUBER;
	}
}

string
Youtuber::getNick() const {
 return nick;
}

string
Youtuber::getUrl() const {
 return url;
}

bool
Youtuber::isPenalized() const {
	return penalized;
}

void 
Youtuber::setPenalized(bool penalized) {
	this -> penalized = penalized;
}

void 
Youtuber::addProfits(float profits) {
	this -> profits += profits;
}

ostream& operator<<(ostream &os, Youtuber &y) {
	os << y.nick << ", url=" << y.url << ", profits=" << y.profits << endl;
	return os; 
}