#ifndef SICT_DATA_H_
#define SICT_DATA_H_
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	template <typename T>
	T  max(const T* data, int n) {
		T max_data = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++)
			max_data = (data[i] > max_data) ? data[i] : max_data;
		return max_data;
	}


	// min returns the smallest item in data
	template <typename T>
	T  min(const T* data, int n) {
		T min_data = LARGEST_NUMBER;
		for (int i = 0; i < n; i++)
			min_data = (data[i] < min_data) ? data[i] : min_data;
		return min_data;
	}
        
	// sum returns the sum of n items in data    
	template <typename T>
	T sum(const T* data, int n) {
		T sum_data = 0;
		for (int i = 0; i < n; i++)
			sum_data += data[i];
		return sum_data;
	}
	// average returns the average of n items in data
	template <typename T>
	double average(const T* data, int n) {
		double average_data = 0.00;
		if (n > 0) {
			average_data = sum(data, n) / n;
		}
		return average_data;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore(2000, ',');
			input >> data[i];
		}
		return true;
	}

	// display inserts n items of data into std::cout
	template <typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20);
		std::cout << name;
		for (int i = 0; i < n; i++) {
			if (strcmp(name, "ViolentCrime_Rate") == 0 || strcmp(name, "GrandTheftAuto_Rate") == 0) {
				std::cout.setf(std::ios::fixed);
				std::cout.precision(1);
				std::cout.width(15);
				std::cout << data[i];
				std::cout.unsetf(std::ios::fixed);
				std::cout.precision(6);
			}
			else {
				std::cout.width(15);
				std::cout << data[i];
			}
		};
		std::cout << std::endl;
	}

	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
#endif