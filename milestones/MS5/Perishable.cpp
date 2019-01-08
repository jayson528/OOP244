#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"
#include "Date.h"

using namespace std;
namespace AMA {

	Perishable::Perishable() : Product('P') {
		
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, !(newLine));
		file << ",";
		expiryDate.write(file);
		if (newLine) {
			file << endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		expiryDate.read(file);
		file.get();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (Product::isClear() && !Product::isEmpty()) {
			if (linear) {
				os << expiry();
			}
			else {
				os << endl << " Expiry date: " << expiry();
			}
		}
		return os;
	}

	
	std::istream& Perishable::read(std::istream& is) {
		Date tempDate;
		Product::read(is);
		
		if (isClear()){
			cout << " Expiry date (YYYY/MM/DD): ";
			tempDate.read(is);

			switch (tempDate.errCode()) {
			case 0:
				break;
			case 1:
				Product::message("Invalid Date Entry");
				is.std::istream::setstate(std::ios::failbit);
				break;
			case 2:
				Product::message("Invalid Year in Date Entry");
				is.std::istream::setstate(std::ios::failbit);
				break;
			case 3:
				Product::message("Invalid Month in Date Entry");
				is.std::istream::setstate(std::ios::failbit);
				break;
			case 4:
				Product::message("Invalid Day in Date Entry");
				is.std::istream::setstate(std::ios::failbit);
				break;
			}
		}
		this->expiryDate = tempDate;
		return is;
	}

	const Date& Perishable::expiry() const {
		return expiryDate;
	}
}