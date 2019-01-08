#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "SavingsAccount.h"

namespace sict {

	SavingsAccount::SavingsAccount(double balance_, double interestRate_) : Account(balance_) {
		if (interestRate_ > 0) {
			interestRate = interestRate_;
		}
		else {
			interestRate = 0;
		}
	}

	void SavingsAccount::monthEnd() {
		double interestEarned = balance() * (interestRate / 100);
		credit(interestEarned);
	}
		
	void SavingsAccount::display(std::ostream& os_) const {
		os_ << "Account type: Savings" << std::endl << "Balance: $";
		os_.setf(std::ios::fixed);
		os_.precision(2);
		os_ << balance() << std::endl;
		os_ << "Interest Rate (%): ";
		os_ << interestRate << std::endl;
		os_.unsetf(std::ios::fixed);
		os_.precision(6);
	}
}


