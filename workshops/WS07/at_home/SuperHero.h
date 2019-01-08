//	Jayson Sherry
//	141056176
#ifndef SICT_SUPERHERO_H	
#define SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		int defence;
		int attackBonus;
	public:
		SuperHero();
		SuperHero(const char *, int, int, int, int);
		~SuperHero();
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero&, const SuperHero&);
}
#endif

