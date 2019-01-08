#define _CRT_SECURE_NO_WARNINGS
#define filename "ms3.txt"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"

using namespace std;

namespace AMA {
	void Product::name(const char* name_) {
		if (name_ == nullptr) {
			productName = nullptr;
		}
		else {
			delete[] productName;
			productName = nullptr;
			productName = new char[max_name_length + 1];
			strncpy(productName, name_, max_name_length + 1);
			productName[max_name_length] = '\0';
		}
	}

	const char* Product::name() const {
		return productName;
	}

	const char* Product::sku() const {
		return skuName;
	}

	const char* Product::unit() const {
		return unitName;
	}

	bool Product::taxed() const {
		return taxable;
	}

	double Product::price() const {
		return preTaxPrice;
	}

	double Product::cost() const {
		if (taxable) {
			return preTaxPrice * (tax_rate + 1);
		}
		else {
			return preTaxPrice;
		}
	}

	void Product::message(const char* errorState_) {
		errorState.message(errorState_);
	}

	bool Product::isClear() const {
		bool result = false;
		if (errorState.message() == '\0') {
			result = true;
		}
		return result;
	}

	Product::Product(char type_) {
		type = type_;
		skuName[0] = '\0';
		unitName[0] = '\0';
		productName = nullptr;
		qtyOnHand = 0;
		qty_Needed = 0;
		preTaxPrice = 0.00;
		taxable = false;
	}

	Product::Product(const char* sku_, const char* name_, const char* unit_, int qtyOnHand_, bool taxable_, double preTaxPrice_, int qtyNeeded_) {
		strncpy(skuName, sku_, max_sku_length + 1);
		productName = nullptr;
		productName = new char[max_name_length + 1];
		strncpy(productName, name_, max_name_length + 1);
		strncpy(unitName, unit_, max_unit_length + 1);
		qtyOnHand = qtyOnHand_;
		taxable = taxable_;
		preTaxPrice = preTaxPrice_;
		qty_Needed = qtyNeeded_;
	}

	Product::Product(const Product& product_) {
		if (product_.productName != nullptr) {
			type = product_.type;
			strncpy(skuName, product_.skuName, max_sku_length + 1);
			strncpy(unitName, product_.unitName, max_unit_length + 1);
			productName = nullptr;
			productName = new char[max_name_length + 1];
			strncpy(productName, product_.productName, max_name_length + 1);
			qtyOnHand = product_.qtyOnHand;
			qty_Needed = product_.qty_Needed;
			preTaxPrice = product_.preTaxPrice;
			taxable = product_.taxable;
		}
	}

	Product& Product::operator= (const Product& product_) {
		if (this != &product_) {
			type = product_.type;
			strncpy(skuName, product_.skuName, max_sku_length + 1);
			strncpy(unitName, product_.unitName, max_unit_length + 1);
			qtyOnHand = product_.qtyOnHand;
			qty_Needed = product_.qty_Needed;
			preTaxPrice = product_.preTaxPrice;
			taxable = product_.taxable;
			delete[] productName;
			productName = nullptr;
			productName = new char[max_name_length + 1];
			strncpy(productName, product_.productName, max_name_length + 1);
		}
		return *this;
	}

	Product::~Product() {
		delete [] productName;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file.open(filename, ios::out | ios::app);
		file << type          << ",";
		file << skuName       << ",";
		file << productName   << ",";
		file << unitName      << ",";
		file << taxable       << ",";
		file << preTaxPrice   << ",";
		file << qtyOnHand     << ",";
		file << qty_Needed    << ",";
		if (newLine) {
			file << std::endl;
		}
		file.clear();
		file.close();
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		Product temp;

		file.open(filename, ios::in);
		file.getline(temp.skuName, 200, ',');
		file.getline(temp.productName, 200, ',');
		file.getline(temp.unitName, 200, ',');
		//file.getline(temp.taxable, ',');
		file >> temp.taxable;
		file.ignore();
		file >> temp.preTaxPrice;
		file.ignore();
		file >> temp.qtyOnHand;
		file.ignore();
		file >> temp.qty_Needed;
		file.ignore();

		*this = temp;
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (linear) {
			os << left << setw(max_sku_length) << sku() << "|";
			os << left << setw(20) << name() << right << "|";
			os << setw(7) << fixed << setprecision(2) << cost() << "|";
			os.std::ios::unsetf(std::ios::fixed);
			os << setprecision(6);
			os << setw(4) << quantity() << "|";
			os << setw(10) << left << unit() << right << "|";
			os << setw(4) << qtyNeeded() << "|";
		}
		else {
			os << std::endl << "Sku: " << skuName << std::endl;
			os << std::endl << "Name (no spaces): " << productName << std::endl;
			os << std::endl << "Price: " << preTaxPrice << std::endl;
			os << std::endl << "either of : " << std::endl;
			if (taxable) {
				os << std::endl << "Price after tax: " << fixed << preTaxPrice << std::endl;
			}
			else {
				os << std::endl << "N/A" << std::endl;
			}
			os << std::endl << "Quantity on hand: " << qtyOnHand << std::endl;
			os << std::endl << "Quantity needed: " << qty_Needed << std::endl;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is) {
		bool result = true;
		char temp_skuName[max_sku_length + 1];
		char temp_unitName[max_unit_length + 1];
		char* temp_productName = new char[max_name_length + 1];
		int temp_qtyOnHand;
		int temp_qty_Needed;
		double temp_preTaxPrice;
		bool temp_taxable;

		std::cout << " Sku: ";
		is.getline(temp_skuName, max_sku_length);
		std::cout << " Name (no spaces): ";
		is.getline(temp_productName, max_name_length);
		std::cout << " Unit: ";
		is >> temp_unitName;
		char inputTaxable;
		std::cout << " Taxed? (y/n): ";
		is >> inputTaxable;
		if (is.fail()) {
			is.setstate(std::ios::failbit);
			message(" Only (Y)es or (N)o are acceptable");
			result = false;
		} 
		else if ((inputTaxable == 'y') || (inputTaxable == 'Y') || (inputTaxable == 'n') || (inputTaxable == 'N')) {
			if (inputTaxable == 'y' || inputTaxable == 'Y') {
				temp_taxable = true;
			}
			else {
				temp_taxable = false;
			}
		}
		else {
			is.setstate(std::ios::failbit);
			message("Only (Y)es or (N)o are acceptable");
			result = false;
		}

		if (result) {
			double inputPreTaxPrice;
			std::cout << " Price: ";
			is >> inputPreTaxPrice;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				//cerr << " Invalid Price Entry" << endl;
				message(" Invalid Price Entry");
				result = false;
			}
			else {
				temp_preTaxPrice = inputPreTaxPrice;
			}
		}
		
		if (result) {
			is.clear();
			is.ignore(2000, '\n');
			std::cout << " Quantity on hand: ";
			is >> temp_qtyOnHand;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				cerr << " Invalid Quantity Entry" << endl;
				message(" Invalid Quantity Entry");
				result = false;
			}
			else {
				
			}

		}
		
		if (result) {
			is.clear();
			is.ignore(2000, '\n');
			std::cout << " Quantity needed: ";
			is >> temp_qty_Needed;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				cerr << " Invalid Quantity Needed Entry" << endl;
				message(" Invalid Quantity Needed Entry");
				result = false;
			}
			else {
		
			}
			is.clear();
			is.ignore(2000, '\n');
		}
	

		if (result) {
			*this = Product(temp_skuName, temp_productName, temp_unitName, temp_qtyOnHand, temp_taxable, temp_preTaxPrice, temp_qty_Needed);
		}
		delete[] temp_productName;
		return is;
	}

	bool Product::operator == (const char* sku_) const {
		bool result = false;
		if (strcmp(sku_, skuName) == 0) {
			result = true;
		}
		return result;
	}

	double Product::total_cost() const {
		double cost = 0.0;
		if (taxable) {
			cost = qtyOnHand * preTaxPrice * 1.13;
		}
		else {
			cost = qtyOnHand * preTaxPrice;
		}
		return cost;
	}

	void Product::quantity(int qty_) {
		qtyOnHand = qty_;
	}

	bool Product::isEmpty() const {
		bool result = false;
		if (skuName[0] == '\0') {
			result = true;
		}
		return result;
	}

	int Product::qtyNeeded() const {
		return qty_Needed;
	}

	int Product::quantity() const {
		return qtyOnHand;
	}

	bool Product::operator>(const char* sku_) const {
		bool result = false;
		if (strcmp(skuName, sku_) > 0) {
			result = true;
		}
		return result;
	}

	bool Product::operator>(const Product& product_) const {
		bool result = false;
		if (strcmp(productName, product_.productName) > 0) {
			result = true;
		}
		return result;
	}

	int Product::operator+=(int add_) {
		if (add_ > 0) {
			qtyOnHand += add_;
		}
		return qtyOnHand;
	}

	std::ostream& operator << (std::ostream& os, const Product& product_) {
		product_.write(os, true);
		return os;
	}

	std::istream& operator>> (std::istream& is, Product& product_) {
		product_.read(is);
		return is;
	}

	double operator+= (double& cost_, const Product& product_) {
		cost_ += product_.total_cost();
		return cost_;
	}
}