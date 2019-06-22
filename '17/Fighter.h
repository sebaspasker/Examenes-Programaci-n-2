#include <iostream>

using namespace std;

class Fighter {
	friend ostream& operator<<(ostream &os, Fighter &f);
	private:
		string type;
		int attack;
		shield int;

	public:
		Fighter(string type, int attack, int shield);
		static int getRandomNumber(int n);
		bool fight(Fighter &enemy);
		int getAttack() const;
		int getShield() const;
		void setAttack(int attack);
		void setShield(int shield);
}