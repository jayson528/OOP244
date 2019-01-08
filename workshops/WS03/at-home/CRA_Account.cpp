//	Jayson Sherry
//	141056176

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	CRA_Account::CRA_Account() {
		social_Insurance_Number = 0;
		taxReturnYrs[max_yrs] = { 0 };
		balanceOrRefund[max_yrs] = { 0 };
		storedTaxReturnYrs = 0;
	};
	//default destructor
	CRA_Account::~CRA_Account() {

	};
	
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sin > min_sin && sin < max_sin  && *familyName != '\0' && *givenName != '\0') {
			int sinArr[8];
			int firstSetOfAlternates = 0;
			int secondSetOfAlternates = 0;
			int checkDigit = sin % 10; 
			int sum = sin / 10; 
			int intMultiple = 0;

			//split sin into an array
			for (int i = 7; i >= 0; i--) {
				sinArr[i] = sum % 10;
				sum = sum / 10;
			}

			//add the first set of alternates together
			sinArr[1] = (sinArr[1] * 2);
			sinArr[3] = (sinArr[3] * 2);
			sinArr[5] = (sinArr[5] * 2);
			sinArr[7] = (sinArr[7] * 2);

			//add the digits of each sum 
			sinArr[1] = ((sinArr[1] % 10) + (sinArr[1] / 10));
			sinArr[3] = ((sinArr[3] % 10) + (sinArr[3] / 10));
			sinArr[5] = ((sinArr[5] % 10) + (sinArr[5] / 10));
			sinArr[7] = ((sinArr[7] % 10) + (sinArr[7] / 10));
				
			//add all digits together
			firstSetOfAlternates = (sinArr[1] + sinArr[3] + sinArr[5] + sinArr[7]);

			//add the second set of altrenate numbers together
			secondSetOfAlternates = (sinArr[0] + sinArr[2] + sinArr[4] + sinArr[6]);

			//total sum of sin
			sum = firstSetOfAlternates + secondSetOfAlternates;

			//sum converted into the next highest interger multiple of 10
			intMultiple = ((sum / 10) + 1) * 10;
				
			//confirm the entered sin is valid
			if ((intMultiple - sum) == checkDigit) {
				strcpy(family_Name, familyName);
				strcpy(given_Name, givenName);
				social_Insurance_Number = sin;
				storedTaxReturnYrs = 0;
			};
		}

		else {
			social_Insurance_Number = 0;
		}
	};

	void CRA_Account::set(int year, double balance) {
		if (!isEmpty()) {
			taxReturnYrs[storedTaxReturnYrs] = year;
			balanceOrRefund[storedTaxReturnYrs] = balance;
			storedTaxReturnYrs++;
		}	
	};


	bool CRA_Account::isEmpty() const {
		bool result = true;
		if (social_Insurance_Number != 0) {
			result = false;
		};
		return result;
	};

	void CRA_Account::display() const {

		cout << "Family Name: " << family_Name << endl
			 << "Given Name : " << given_Name << endl
			 << "CRA Account: " << social_Insurance_Number << endl;
		
		for (int i = 0; i < storedTaxReturnYrs; i++) {
			cout << "Year (" << taxReturnYrs[i];
			cout.setf(ios::fixed);
			cout.precision(2);
			
			if (balanceOrRefund[i] > 2) {
				cout << ") balance owing: " << balanceOrRefund[i] << endl;
			}

			else if (balanceOrRefund[i] < -2) {
					cout << ") refund due: " << (balanceOrRefund[i] * -1) << endl;
			}

			else if (social_Insurance_Number == 0) {
				cout << "Account object is empty!" << endl;
			}

			else {
				cout << ") No balance owing or refund due!" << endl;
			};
		}
	};
};