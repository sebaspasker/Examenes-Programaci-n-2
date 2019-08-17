#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

enum Exception { 
	exception_mention,
	exception_name,
	exception_email,
	exception_pos
};

class Tweet {
	friend ostream& operator<<(ostream &os, const Tweet t);
	private:
		string text;
		static unsigned int nextId;
		unsigned int id;

	public:
		Tweet(string text, const vector<string> &users);
		string getText() const;
		unsigned int getId() const;
		vector<string> getMentions() const;
};