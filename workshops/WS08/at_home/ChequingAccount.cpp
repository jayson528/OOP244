// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double balance_, double transactionFee_, double monthEndFee_) : Account(balance_) {
		if (transactionFee_ > 0 && monthEndFee_ > 0) {
			transactionFee = transactionFee_;
			monthEndFee = monthEndFee_;
		}
		else {
			transactionFee = 0.0;
			monthEndFee = 0.0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double addCredit_) {
		bool result = false;
		if (Account::credit(addCredit_)) {
			Account::debit(transactionFee);
			result = true;
		}
		return result;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double removeCredit_) {
		bool result = false;
		if (Account::debit(removeCredit_)) {
			Account::debit(transactionFee);
			result = true;
		}
		return result;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		Account::debit(monthEndFee);
		Account::debit(transactionFee);
	}

	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& os_) const {
		os_ << "Account type: Chequing" << std::endl;
		os_ << "Balance: $";
		os_ .setf(std::ios::fixed);
		os_.precision(2);
		os_ << balance() << std::endl;
		os_ << "Per Transaction Fee: ";
		os_ << transactionFee << std::endl;
		os_ << "Monthly Fee: ";
		os_ << monthEndFee << std::endl;
		os_.unsetf(std::ios::fixed);
		os_.precision(6);
	}
}