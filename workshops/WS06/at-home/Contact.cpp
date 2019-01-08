//	Jayson Sherry
//	141056176
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {
	//default constructor
	Contact::Contact() {
		name[0] = '\0';
		numbers = nullptr;
		numOfNumbers = 0;
	};

	//3 Parameter constructor
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
					if (validNumber(numbers_[i])) {
						numOfValidNumbers++;
					}
				}
				//allocate memory for valid new numbers
				numbers = new long long[numOfValidNumbers];
				//add the valid numbers to memory
				for (int i = 0; i < totalNums; i++) {
					if (validNumber(numbers_[i])) {
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

	//destructor
	Contact::~Contact() {
		delete[] numbers;
	};

	//query member to check if object is empty
	bool Contact::isEmpty() const {
		bool result = false;
		if (name[0] == '\0') {
			result = true;
		}
		return result;
	};

	//member that displays the objects info
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			for (int i = 0; i < numOfNumbers; i++) {
				cout << "(+" << conCode(numbers[i]) << ") " << areCode(numbers[i]) << " ";
				cout << (phoneNumber(numbers[i]) / 10000) << "-" << setw(4) << setfill('0') << (phoneNumber(numbers[i]) % 10000) << endl;
			}
		}
	};

	//memeber that checks to see if passed in number is valid
	bool Contact::validNumber(const long long num) const {
		bool result = false;
		if (conCode(num) < 100 && conCode(num) != 0 && (int) (areCode(num) / 100) != 0 && (int) (phoneNumber(num) / 1000000) != 0) {
			result = true;
		}
		return result;
	}

	//memeber that recives a number and returns the country code
	int Contact::conCode(const long long num) const {
		int result = 0;
		result = num / 10000000000;
		return result;
	}

	//memeber that recives a number and returns the area code
	int Contact::areCode(const long long num) const {
		int result = 0;
		(int) result = (num % 10000000000) / 10000000;
		return result;
	}

	//memeber that recives a number and returns just the phone number portion
	int Contact::phoneNumber(const long long num) const {
		int result = 0;
		result = num % 10000000;
		return result;
	}

	//copy constructor
	Contact::Contact(const Contact* con) {
		strncpy(name, con->name,20);
		numOfNumbers = con->numOfNumbers;
		if (con->numbers != nullptr) {
			numbers = new long long[numOfNumbers];
			for (int i = 0; i < con->numOfNumbers; i++) {
				numbers[i] = con->numbers[i];
			}
		}
		else {
			numbers = nullptr;
		}
	}

	//copy assignment operator
	Contact& Contact::operator = (const Contact& con) {
		if (this != &con) {
			name[0] = '\0';
			numbers = 0;
			numOfNumbers = 0;
			strncpy(name, con.name, 20);
			numOfNumbers = con.numOfNumbers;
			delete[] numbers;
			if (con.numbers != nullptr) {
				numbers = new long long[numOfNumbers];
				for (int i = 0; i < numOfNumbers; i++) {
					numbers[i] = con.numbers[i];
				}
			}
		}
		return *this;
	}

	//overloaded += operator
	Contact& Contact::operator += (long long num) {
		if (validNumber(num)) {
			long long temp[10];
			for (int i = 0; i < numOfNumbers; i++) {
				temp[i] = numbers[i];
			}
			delete[] numbers;
			numbers = new long long[numOfNumbers + 1];
			for (int i = 0; i < numOfNumbers; i++) {
				numbers[i] = temp[i];
			}
			numbers[numOfNumbers] = num;
			numOfNumbers++;
		}
		return *this;
	}
};