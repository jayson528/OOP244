// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Date.h"

namespace AMA {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errCode) {
		switch (errCode) {
		case 1:
			errorState = CIN_FAILED;
			break;
		case 2:
			errorState = YEAR_ERROR;
			break;
		case 3:
			errorState = MON_ERROR;
			break;
		case 4:
			errorState = DAY_ERROR;
			break;
		default:
			errorState = NO_ERROR;
			break;
		}
	}

	Date::Date() {
		year = 0;
		monthOfYear = 0;
		dayOfMonth = 0;
		comparator = 0;
		errCode(0);
	}

	Date::Date(int year_, int month_, int day_) {
		if (year_ >= min_year && year_ <= max_year) {
			if (month_ <= 12 && month_ >= 1) {
				if (day_ <= mdays(month_, year_) && day_ >= 1) {
					year = year_;
					monthOfYear = month_;
					dayOfMonth = day_;
					comparator = year_ * 372 + month_ * 13 + day_;
					errCode(0);
				}
				else {
					errCode(4);
				}
			}
			else {
				errCode(3);
			}
		}
		else {
			errCode(2);
		}
	}

	bool Date::operator == (const Date& rhs) const {
		bool result = false;
		if (comparator == rhs.comparator) {
			result = true;
		}
		return result;
	}

	bool Date::operator != (const Date& rhs) const {
		bool result = false;
		if (comparator != rhs.comparator) {
			result = true;
		}
		return result;
	}

	bool Date::operator < (const Date& rhs) const {
		bool result = false;
		if (comparator < rhs.comparator) {
			result = true;
		}
		return result;
	}

	bool Date::operator > (const Date& rhs) const {
		bool result = false;
		if (comparator > rhs.comparator) {
			result = true;
		}
		return result;
	}

	bool Date::operator <= (const Date& rhs) const {
		bool result = false;
		if (comparator <= rhs.comparator) {
			result = true;
		}
		return result;
	}

	bool Date::operator >= (const Date& rhs) const {
		bool result = false;
		if (comparator >= rhs.comparator) {
			result = true;
		}
		return result;
	}

	int Date::errCode() const {
		return errorState;
	}

	bool Date::bad() const {
		bool result = false;
		if (errorState != 0) {
			result = true;
		}
		return result;
	}


	std::istream& Date::read(std::istream& istr) {
		int tempYear = 0;
		int tempMonth = 0;
		int tempDay = 0;
		char garbage = '\0';

		istr >> tempYear 
			 >> garbage 
			 >> tempMonth 
			 >> garbage 
			 >> tempDay;

		Date temp(tempYear, tempMonth, tempDay);
		*this = temp;
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << std::setw(2) << std::setfill('0') << year
			 << "/" << std::setw(2) << std::setfill('0') 
			 << monthOfYear << "/" << std::setw(2) 
			 << std::setfill('0') << dayOfMonth;
		return ostr;
	}

	std::ostream& operator << (std::ostream& ostr, const Date& date) {
		date.write(ostr);
		return ostr;
	}

	std::istream& operator >> (std::istream& istr, Date& date) {
		date.read(istr);
		return istr;
	}
}
