#include "iAccount.h"
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	const double intRate = 5;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* accountName_, double intialBalance_) {
		iAccount* temp = nullptr;
		if (accountName_[0] == 's' || accountName_[0] == 'S') {
			temp = new SavingsAccount(intialBalance_, intRate);
		}
		return temp;
	}
}
