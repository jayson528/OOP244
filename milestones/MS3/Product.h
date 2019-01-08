#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <iostream>
#include <fstream>
#include "ErrorState.h"

namespace AMA {
	const int max_sku_length = 7;   
	const int max_unit_length = 10; 
	const int max_name_length = 75;  
	const double tax_rate = 0.13;  

	class Product {
		char type;
		char skuName[max_sku_length + 1];
		char unitName[max_unit_length + 1];
		char* productName;
		int qtyOnHand;
		int qty_Needed;
		double preTaxPrice;
		bool taxable;
		ErrorState errorState;
	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(char type_ = 'N');
		Product(const char*, const char*, const char*, int qtyOnHand_ = 0, bool taxable_ = true, double preTaxPrice = 0.0, int qtyNeeded_ = 0);
		Product(const Product&);
		Product& operator= (const Product&);
		~Product();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool linear = true) const;
		std::istream& read(std::istream&);
		bool operator == (const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};
	std::ostream& operator<< (std::ostream&, const Product&);
	std::istream& operator>> (std::istream&, Product&);
	double operator+= (double&, const Product&);
}
#endif