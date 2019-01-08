//	Jayson Sherry
//	141056176
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {
	Contact::Contact() {
		name[0] = '\0';
		numbers = 0;
		numOfNumbers = 0;
	};

	Contact::Contact(const char* name_,const long long* numbers_, int totalNums) {
		int numOfValidNumbers = 0;
		int counter = 0;

		//check for valid name
		if (name_ != nullptr && name_ != '\0'){

			//copy valid name
			strncpy(name, name_,20);
			name[19] = '\0';

			if (totalNums > 0) {

				//check to see what numbers are valid
				for (int i = 0; i < totalNums; i++) {
					if (validNumber(&numbers_[i])) {
						numOfValidNumbers++;
					}
				}

				//allocate memory for valid new numbers
				numbers = new long long[numOfValidNumbers];

				//add the valid numbers to memory
				for (int i = 0; i < totalNums; i++) {
					if (validNumber(&numbers_[i])) {
						numbers[counter] = numbers_[i];
						counter++;
					}
				}
				numOfNumbers = numOfValidNumbers;
			}
			else {
				numbers = nullptr;
				numOfNumbers = 0;
			}
		}
		else {
			*this = Contact();
		}
	};

	Contact::~Contact() {
		delete[] numbers;
	};

	bool Contact::isEmpty() const {
		bool result = false;
		if (name[0] == '\0' && numOfNumbers == 0) {
			result = true;
		}
		return result;
	};

	void Contact::display() const {
		if (!isEmpty()) {
			cout << name << endl;
			for (int i = 0; i < numOfNumbers; i++) {
				cout << "(+" << conCode(&numbers[i]) << ") " << areCode(&numbers[i]) << " ";
				cout << (phoneNumber(&numbers[i]) / 10000) << "-" << setw(4) << setfill('0') << (phoneNumber(&numbers[i]) % 10000) << endl;
			}
		}
		else {
			cout << "Empty contact!" << endl;
		}
	};

	bool Contact::validNumber(const long long* num) const {
		bool result = false;
		if (conCode(num) < 100 && conCode(num) != 0 && (int) (areCode(num) / 100) != 0 && (int) (phoneNumber(num) / 1000000) != 0) {
			result = true;
		}
		return result;
	}

	int Contact::conCode(const long long* num) const {
		int result = 0;
		result = *num / 10000000000;
		return result;
	}

	int Contact::areCode(const long long* num) const {
		int result = 0;
		(int) result = (*num % 10000000000) / 10000000;
		return result;
	}

	int Contact::phoneNumber(const long long* num) const {
		int result = 0;
		result = *num % 10000000;
		return result;
	}
};