#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"

namespace sict {
	Account::Account(double balance_) {
		if (balance_ > 0) {
			accountBalance = balance_;
		}
		else {
			accountBalance = 0;
		}
	}

	double Account::balance() const {
		return accountBalance;
	 }

	bool Account::credit(double addCredit_) {
		bool result = false;
		if (addCredit_ > 0) {
			accountBalance += addCredit_;
			result = true;
		}
		return result;
	}

	bool Account::debit(double removeCredit_) {
		bool result = false;
		if (removeCredit_ > 0) {
			accountBalance -= removeCredit_;
			result = true;
		}
		return result;
	}
}
