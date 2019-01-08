//	Jayson Sherry
//	141056176
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Hero.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {
	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attack_Strength = 0;
	}

	Hero::Hero(const char* name_, const int health_, const int attackStrength_) {
		if (name_ != '\0' && health_ > 0 && attackStrength_ > 0) {
			strcpy(name, name_);
			health = health_;
			attack_Strength = attackStrength_;
		}
		else {
			*this = Hero();
		}
	}

	Hero::~Hero() {
	}

	void Hero::operator-=(int attackStrength_) {
		if (attackStrength_ > 0) {
			health -= attackStrength_;
		}
		if (health < 0) {
			health = 0;
		}
	}

	bool Hero::isAlive() const {
		bool result = false;
		if (health > 0) {
			result = true;
		}
		return result;
	}

	int Hero::attackStrength() const {
		int result = 0;
		if (name[0] != '\0') {
			result = attack_Strength;
		}
		return result;
	}

	void Hero::display(std::ostream& os) const {
		if (name[0] == '\0') {
			os << "No hero" << std::endl;
		}
		else {
			os << name;
		}
	}

	std::ostream& operator << (std::ostream& os, const Hero& hero) {
			hero.display(os);
			return os;
	}

	const Hero& operator * (const Hero& first_, const Hero& second_) {
		int roundCounter = 0;
		Hero first = first_;
		Hero second = second_;

		for (int i = 0; roundCounter < max_rounds && first.isAlive() && second.isAlive(); i++) {
			first -= second.attackStrength();
			second -= first.attackStrength();
			roundCounter++;
		}
		std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
		if (first.isAlive()) {
			std::cout << first << " in " << roundCounter << " rounds." << endl;
			return first_;
		}
		else {
			std::cout << second << " in " << roundCounter << " rounds." << endl;
			return second_;
		}
	}
}

