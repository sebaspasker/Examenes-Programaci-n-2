#include <iostream>

using namespace std;

enum Error {
	ERR_YOUTUBER
};

class Youtuber {
	friend ostream& operator<<(ostream &os, Youtuber &y);
	private:
		string nick;
		string url;
		bool penalized;
		float profits;
	public:
		Youtuber(string nick, string url);
		string getNick() const;
		string getUrl() const;
		bool isPenalized() const;
		void setPenalized(bool penalized);
		void addProfits(float profits);
};