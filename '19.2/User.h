#include "Tweet.h"

class User {
	friend ostream& operator<<(ostream &os, const User u);
	private:
		string name;
		string email;
		vector<Tweet> tweetVector;

	public:
		User(string name, string email);
		unsigned int writeTweet(string text, const vector<string> &users);
		void addTweet(Tweet newTweet);
		string getName() const;
		Tweet getTweet(int pos) const;
		unsigned int getNumberOfTweets() const;

};