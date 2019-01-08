#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"SuperHero.h"

using namespace std;
using namespace sict;

namespace sict {

	SuperHero::SuperHero() {
		attackBonus = 0;
		defence = 0;
	}

	SuperHero::SuperHero(const char* name_, int health_, int attackStrength_, int attackBonus_, int defence_) : Hero(name_,health_,attackStrength_) {
		if (name_[0] != '\0' && health_ > 0 && attackStrength_ > 0 && attackBonus_ > 0 && defence_ > 0) {
			attackBonus = attackBonus_;
			defence = defence_;
		}
		else {
			*this = SuperHero();
		}
	}

	SuperHero::~SuperHero() {
	}

	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() > 0) {
			return (Hero::attackStrength() + attackBonus);
		}
		else return 0;
	}

	int SuperHero::defend() const {
		if (defence > 0) {
			return defence;
		}
		else return 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero first_ = first;
		SuperHero second_ = second;
		int roundCounter = 0;
		for (int i = 0; (i < max_rounds) && first_.isAlive() && second_.isAlive(); i++) {
			first_ -= (second_.attackStrength() - first_.defend());
			second_ -= (first_.attackStrength() - second_.defend());
			roundCounter++;
		}
		std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
		if (first_.isAlive()) {
			std::cout << first << " in " << roundCounter << " rounds." << endl;
			return first;
		}
		else {
			std::cout << second << " in " << roundCounter << " rounds." << endl;
			return second;
		}
	}
}