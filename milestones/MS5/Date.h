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
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#define NO_ERROR 0      	// No error - the date is valid
#define CIN_FAILED 1	    // istream failed on information entry
#define YEAR_ERROR 2	    // Year value is invalid
#define MON_ERROR 3	        // Month value is invalid
#define DAY_ERROR 4	        // day value is invalid

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
	
  class Date {
	  int year;
	  int monthOfYear;
	  int dayOfMonth;
	  int comparator;
	  int errorState;
	  int mdays(int, int)const;
	  void errCode(int);
 
  public:
	  Date();
	  Date(int, int, int);
	  bool operator == (const Date&) const;
	  bool operator != (const Date&) const;
	  bool operator < (const Date&) const;
	  bool operator > (const Date&) const;
	  bool operator <= (const Date&) const;
	  bool operator >= (const Date&) const;
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream&);
	  std::ostream& write(std::ostream&) const;
 
  };
  std::ostream& operator << (std::ostream&, const Date&);
  std::istream& operator >> (std::istream&, Date&);
}
#endif