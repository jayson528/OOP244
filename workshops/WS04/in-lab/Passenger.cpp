// TODO: add file header comments here
//	Jayson Sherry
//	141056176

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
// TODO: continue your namespace here
namespace sict {
	
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		passenger_name[0] = '\0';
		destination[0] = '\0';
	};
	
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest) {
		if (name != nullptr && dest != nullptr && name[0] != '\0' && dest[0] != '\0') {
			strncpy(passenger_name, name, 31);
			strncpy(destination, dest, 31);
		}
		else {
			*this = Passenger();
		}
	};
	
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool result = true;
		if (passenger_name[0] != '\0' && destination[0] != '\0') {
			result = false;
		}
		return result;
	};
	
	// TODO: implement display query here
	void Passenger::display() const {
		if (this->isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << passenger_name << " - " << destination << endl;
		}
	};
}