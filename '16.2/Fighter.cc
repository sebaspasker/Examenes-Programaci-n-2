#include "Fighter.h"

Fighter::Fighter(string type, int attack, int shield) {
	if(attack >= 0 && attack <= 99 && shield >= 0 && shield <= 99) {
		this -> type = type;
		this -> attack = attack;
		this -> shield = shield;
	} else {
		throw ERR_SHIELD_ATTACK;
	}
}

int 
Fighter::getRandomNumber(int n) {
	int number = rand()%n;
	return number;
}

bool
Fighter::fight(Fighter &enemy) {
	int number = Fighter::getRandomNumber(99);
	enemy.setShield(enemy.getShield() - (attack*number/100));

	if(getShield() <= 0) {
		return true;
	} else {
		return false;
	}
}


int 
Fighter::getAttack() const {
	return attack;
}

int 
Fighter::getShield() const {
	return shield;
}

void 
Fighter::setAttack(int attack) {
	this -> attack = attack;
}


void 
Fighter::setShield(int shield) {
	this -> shield = shield;
}

ostream& operator<<(ostream &os, Fighter &f) {
	os << "TIE-" << f.type << " (a=" << f.attack << ", s=" << f.shield << ").";
	return os;
}