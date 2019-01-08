// TODO: add file header comments here
//	Jayson Sherry
//	141056176

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		passenger_name[0] = '\0';
		destination[0] = '\0';
		yearOfDeparture = 0;
		monthOfDeparture = 0;
		dayOfDeparture = 0;
	};


	Passenger::Passenger(const char* name, const char* dest, const int year, const int month, const int day) {
		if (name != nullptr && dest != nullptr && name[0] != '\0' && dest[0] != '\0'
			&& year <= 2020 && year >= 2017 && month <= 12 && month >= 1 && day <= 31 && day >= 1) {
			strncpy_s(passenger_name, name, 31);
			strncpy_s(destination, dest, 31);
			yearOfDeparture = year;
			monthOfDeparture = month;
			dayOfDeparture = day;
		}
		else {
			*this = Passenger();
		}
	}

	const char* Passenger::name() const {
		return passenger_name;
	};

	bool Passenger::canTravelWith(const Passenger& otherPassenger) const {
		bool result = false;

		if (strcmp(otherPassenger.destination, destination) == 0 && otherPassenger.yearOfDeparture == yearOfDeparture
			&& otherPassenger.monthOfDeparture == monthOfDeparture && otherPassenger.dayOfDeparture == dayOfDeparture) {
			result = true;
		};
		return result;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest) {
		if (name != nullptr && dest != nullptr && name[0] != '\0' && dest[0] != '\0') {
			strncpy_s(passenger_name, name, 31);
			strncpy_s(destination, dest, 31);
			yearOfDeparture = 2017;
			monthOfDeparture = 3;
			dayOfDeparture = 1;
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
			cout << passenger_name << " - " << destination << " on " << yearOfDeparture << "/";
			if (monthOfDeparture < 10) {
				cout << setw(2) << setfill('0') << monthOfDeparture << "/";
			}
			else {
				cout << monthOfDeparture << "/";
			}
			if (dayOfDeparture < 10) {
				cout << setw(2) << setfill('0') << dayOfDeparture << "/";
			}
			else {
				cout << dayOfDeparture << endl;
			}
		}
	};
}