//	Jayson Sherry
//	141056176



#ifndef SICT_KINGDOM_H	
#define SICT_KINGDOM_H



namespace sict {

	const int max_name_length = 41;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;
	
	class CRA_Account {

		char family_Name[max_name_length];
		char given_Name[max_name_length];
		int social_Insurance_Number;
		int taxReturnYrs[max_yrs];
		double balanceOrRefund[max_yrs];
		int storedTaxReturnYrs;

	public:
		CRA_Account();

		~CRA_Account();

		void set(const char* familyName, const char* givenName, int sin);

		bool isEmpty() const;

		void display() const;
		
		void set(int year, double balance);

	};
}
#endif
