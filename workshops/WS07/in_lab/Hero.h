//	Jayson Sherry
//	141056176
#ifndef SICT_CONTACT_H	
#define SICT_CONTACT_H
#include <iostream>

namespace sict {
	const int max_rounds = 100;

	class Hero {
		char name[41];
		int health;
		int attack_Strength;
	public:
		Hero();
		Hero(const char*, const int, const int);
		~Hero();
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		void display(std::ostream&) const;
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif