



#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

		void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

			if (sin > min_sin && sin < max_sin) {
				strcpy(family_Name, familyName);
				strcpy(given_Name, givenName);
				social_Insurance_Number = sin;
			}
			else {
				social_Insurance_Number = 0;
			}
		};

		bool CRA_Account::isEmpty() const {
			bool result = true;

			if (social_Insurance_Number > min_sin && social_Insurance_Number < max_sin) {
				result = false;
			};

			return result;
		};

		void CRA_Account::display() const {
			if (isEmpty() == false) {
				cout << "Family Name: " << family_Name << endl
					<< "Given Name : " << given_Name << endl
					<< "CRA Account: " << social_Insurance_Number << endl;
			}
			else {
				cout << "Account object is empty!" << endl;
			};

		};
};