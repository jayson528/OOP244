#ifndef AMA_IPRODUCT_H_
#define AMA_IPRODUCT_H_
#include <iostream>
#include <fstream>
using namespace std;

namespace AMA {

	class iProduct {

	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator == (const char* str) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int _numIProduct) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+= (int numAdded) = 0;
		virtual bool operator> (const iProduct&) const = 0;
	};

	std::ostream& operator<< (std::ostream& os, const iProduct& _iproduct);
	std::istream& operator>> (std::istream& is, iProduct& _iproduct);
	double operator+= (double& _addValue, const iProduct& _iproduct);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();
}
#endif
