#define _CRT_SECURE_NO_WARNINGS
#define filename "ms3.txt"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"
#include "ErrorState.h"

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

	Product& Product::operator = (const Product& product_) {
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
		//delete [] productName;
		//productName = nullptr;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << type                                << ","
			 << sku()                               << ","
			 << name()                              << ","
			 << unit()                              << ","
			 << taxed()                             << ","
			 << fixed << setprecision(2) << price() << ","
			 << quantity()                          << ","
			 << qtyNeeded();
		if (newLine) {
			file << std::endl;
		}
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		//char temp_type;
		//char temp_skuName[max_sku_length + 1];
		//char temp_unitName[max_unit_length + 1];
		//char* temp_productName;
		//temp_productName = new char[max_name_length + 1];
		//int temp_qtyOnHand;
		//int temp_qty_Needed;
		//double temp_preTaxPrice;
		//bool temp_taxable;
		//ErrorState temp_errorState;

		Product temp;
		temp.productName = new char[max_name_length + 1];

		//file.open(filename, ios::in);
		
			file >> temp.type;
			file.ignore();
			file.getline(temp.skuName, max_sku_length, ',');
			file.getline(temp.productName, max_name_length, ',');
			file.getline(temp.unitName, max_unit_length, ',');
			file >> temp.taxable;
			file.ignore();
			file >> temp.preTaxPrice;
			file.ignore();
			file >> temp.qtyOnHand;
			file.ignore();
			file >> temp.qty_Needed;
			file.ignore();
			/*
				file >> temp_type;
				file.ignore();
				file >> temp_skuName;
				file.ignore();
				file >> temp_unitName;
				file.ignore();
				file >> temp_productName;
				file.ignore();
				file >> temp_qtyOnHand;
				file.ignore();
				file >> temp_qty_Needed;
				file.ignore();
				file >> temp_preTaxPrice;
				file.ignore();
				file >> temp_taxable;
				file.ignore();
				file.clear();
				file.close();
			*/
			//Product temp = Product(temp_skuName, temp_productName, temp_unitName, temp_qtyOnHand, temp_taxable, temp_preTaxPrice, temp_qty_Needed);
			*this = temp;
			delete[] temp.productName;
		
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		
		if (errorState.message() != nullptr) {
			os << errorState.message();
		}

		else if (linear) {
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
			os << "Sku: "                    << skuName << std::endl;
			os << "Name (no spaces): "       << productName << std::endl;
			os << "Price: "                  << preTaxPrice << std::endl;
			if (taxable) {
				os << "Price after tax: "    << fixed << setprecision(2) << cost() << std::endl;
			}
			else {
				os << "N/A"                  << std::endl;
			}
			os << "Quantity on hand: "       << qtyOnHand << std::endl;
			os << "Quantity needed: "        << qty_Needed << std::endl;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is) {
		bool result = true;
		char temp_taxable;
		Product temp;
		temp.productName = new char[max_name_length + 1];

		std::cout << " Sku: ";
		is.getline(temp.skuName, max_sku_length);
		std::cout << " Name (no spaces): ";
		is.getline(temp.productName, max_name_length);
		std::cout << " Unit: ";
		is.getline(temp.unitName,max_unit_length);

		if (result) {
			std::cout << " Taxed? (y/n): ";
			is >> temp_taxable;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				message("Only (Y)es or (N)o are acceptable");
				result = false;
			}
			else if ((temp_taxable == 'y') || (temp_taxable == 'Y') || (temp_taxable == 'n') || (temp_taxable == 'N')) {
				if (temp_taxable == 'y' || temp_taxable == 'Y') {
					temp.taxable = true;
				}
				else {
					temp.taxable = false;
				}
			}
			else {
				is.setstate(std::ios::failbit);
				message("Only (Y)es or (N)o are acceptable");
				result = false;
			}
		};

		if (result) {
			std::cout << " Price: ";
			is >> temp.preTaxPrice;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				message(" Invalid Price Entry");
				result = false;
			}
		}
		if (result) {
			std::cout << " Quantity on hand: ";
			is >> temp.qtyOnHand;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				message(" Invalid Quantity Entry");
				result = false;
			}
		}
		if (result) {
			std::cout << " Quantity needed: ";
			is >> temp.qty_Needed;
			if (is.fail()) {
				is.setstate(std::ios::failbit);
				message(" Invalid Quantity Needed Entry");
				result = false;
			}
		}

		if (result) {
			*this = temp;
			errorState.clear();
		}
		delete[] temp.productName;
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
		if (productName[0] == '\0') {
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

	bool Product::operator > (const char* sku_) const {
		bool result = false;
		if (strcmp(skuName, sku_) > 0) {
			result = true;
		}
		return result;
	}

	bool Product::operator > (const iProduct& product_) const {
		bool result = false;
		if (strcmp(productName, product_.name()) > 0) {
			result = true;
		}
		return result;
	}

	int Product::operator += (int add_) {
		if (add_ > 0) {
			qtyOnHand += add_;
		}
		return qtyOnHand;
	}

	std::ostream& operator << (std::ostream& os, const iProduct& product_) {
		product_.write(os, true);
		return os;
	}

	std::istream& operator >> (std::istream& is, iProduct& product_) {
		product_.read(is);
		return is;
	}

	double operator += (double& cost_, const iProduct& product_) {
		cost_ += product_.total_cost();
		return cost_;
	}
}