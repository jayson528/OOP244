#ifndef AMA_PERISHABLE_H_
#define AMA_PERISHABLE_H_
#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"

using namespace std;
namespace AMA {

	class Perishable :public Product {  
		Date expiryDate;
	public:
		Perishable();           
		std::fstream& store(std::fstream& file, bool newLine = true) const;    
		std::fstream& load(std::fstream& file);                                 
		std::ostream& write(std::ostream& os, bool linear) const;               
		std::istream& read(std::istream& is);                                   
		const Date& expiry() const;                                             
	};
}
#endif
