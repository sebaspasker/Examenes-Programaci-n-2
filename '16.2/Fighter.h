#include <iostream>
#include <cstdlib>

using namespace std;

enum Error {
	ERR_SHIELD_ATTACK
};

class Fighter {
	friend ostream& operator<<(ostream &os, Fighter &f);
	private:
		string type;
		int attack;
		int shield;

	public:
		Fighter(string type, int attack, int shield);
		static int getRandomNumber(int n);
		bool fight(Fighter &enemy);
		int getAttack() const;
		int getShield() const;
		void setAttack(int attack);
		void setShield(int shield);
};