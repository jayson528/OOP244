// TODO: insert header files
#include <iostream>
#include "Fraction.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num,int den) {
		if (num >= 0 && den > 0) {
			numerator = num;
			denominator = den;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		int result = 0;
		if (numerator > denominator) {
			result = numerator;
		}
		else {
			result = denominator;
		}
		return result;
	}
	
	// TODO: implement the min query
	int Fraction::min() const {
		int result = 0;
		if (numerator < denominator) {
			result = numerator;
		}
		else {
			result = denominator;
		}
		return result;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int div = gcd();
		numerator = numerator / div;
		denominator = denominator / div;
	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool result = false;
		if (numerator == 0 && denominator == 0) {
			result = true;
		}
		return result;
	}

	// TODO: implement the display query
	void Fraction::display() const {
		if (!isEmpty() && denominator != 1) {
			cout << numerator << "/" << denominator;
		}
		else if (!isEmpty() && denominator == 1){
			cout << numerator;
		}
		else {
			cout << "no fraction stored";
		}
	}

	// TODO: implement the + operator
	Fraction Fraction::operator + (const Fraction& rhs) const {
		int addedNumerator = 0;
		int addedDenominator = 0;
		if (!this->isEmpty() && !rhs.isEmpty()) {
			addedNumerator = (this->numerator * rhs.denominator) + (this->denominator * rhs.numerator);
			addedDenominator = (this->denominator * rhs.denominator);
		}
		Fraction result(addedNumerator, addedDenominator);
		return result;
	}
}