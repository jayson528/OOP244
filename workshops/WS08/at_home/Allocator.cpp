#include "iAccount.h"
#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sict {

	// define interest rate
	const double intRate = 5.0;
	const double transactionFee = 0.5;
	const double monthlyFee = 2.0;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* accountName_, double intialBalance_) {
		iAccount* temp = nullptr;
		switch (accountName_[0]) {
			case 's': 
				temp = new SavingsAccount(intialBalance_, intRate);
				break;
			case 'S':
				temp = new SavingsAccount(intialBalance_, intRate);
				break;
			case 'c':
				temp = new ChequingAccount(intialBalance_, transactionFee, monthlyFee);
				break;
			case 'C':
				temp = new ChequingAccount(intialBalance_, transactionFee, monthlyFee);
				break;
			default:
				break;
		}
		return temp;
	}
}
