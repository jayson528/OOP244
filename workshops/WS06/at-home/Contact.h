//	Jayson Sherry
//	141056176
#ifndef SICT_CONTACT_H	
#define SICT_CONTACT_H

namespace sict {

	class Contact {
		char name[20];
		long long* numbers;
		int numOfNumbers;

	public:
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool validNumber(const long long) const;
		int conCode(const long long) const;
		int areCode(const long long) const;
		int phoneNumber(const long long) const;
		Contact(const Contact*);
		Contact& operator = (const Contact&);
		Contact& operator += (long long);
	};
}
#endif