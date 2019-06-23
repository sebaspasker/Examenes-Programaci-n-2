#include "Youtuber.h"
#include <vector>

using namespace std;

class Category {
	friend ostream& operator<<(ostream &os, Category &c);
	private:
		string description;
		int percentage;
		vector<string> forbiddenNicks;
		vector<Youtuber> yVector;

	public:
		Category(string description, int percentage);
		void addForbiddenNick(string nick);
		void addYoutuber(string nick, string url);
		void penalize(string nick);
		void shareProfits(float profits);
};