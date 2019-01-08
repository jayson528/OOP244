#include "Data.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

namespace sict {
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << "Population change from " << year[0] << " to " << year[n - 1] << " is " << (population[n - 1] - population[0]) / 1000000.00 << " million" << std::endl;




		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		std::cout << "Violent Crime trend is " << ((violentCrimeRate[n - 1] > violentCrimeRate[0]) ? "up" : "down") << std::endl;





		// Q3 print the GTA number accurate to 0 decimal places
		std::cout << "There are " << average(grandTheftAuto, n) / 1000000.00 << " million Grand Theft Auto incidents on average a year" << std::endl;



		// Q4. Print the min and max violentCrime rates
		int minData = min(violentCrimeRate, n);
		int maxData = max(violentCrimeRate, n);
		std::cout.precision(0);
		std::cout << "The Minimum Violent Crime rate was " << minData << std::endl;
		std::cout << "The Maximum Violent Crime rate was " << maxData << std::endl;
		std::cout.unsetf(std::ios::fixed);
		std::cout.precision(6);


	}
}
