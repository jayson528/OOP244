


#ifndef SICT_KINGDOM_H	
#define SICT_KINGDOM_H



namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	
	class CRA_Account {

		char family_Name[max_name_length];
		char given_Name[max_name_length];
		int social_Insurance_Number;

	public:
		void set(const char* familyName, const char* givenName, int sin);

		bool isEmpty() const;

		void display() const;
	};
}
#endif
