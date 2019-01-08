// TODO: add file header comments here
//	Jayson Sherry
//	141056176

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H	
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {
		char passenger_name[32];
		char destination[32];
		int yearOfDeparture;
		int monthOfDeparture;
		int dayOfDeparture;

	public:
		Passenger();

		Passenger(const char* name, const char* dest, const int year, const int month, const int day);

		const char* name() const;

		bool canTravelWith(const Passenger& otherPassenger) const;

		Passenger(const char* name, const char* dest);

		bool isEmpty() const;

		void display() const;
	};
}
#endif
