/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

// TODO: the sict namespace
using namespace std;
using namespace sict;


// TODO:definition for display(...) 
void sict::display(const Kingdom& kd) {
	cout << kd.m_name << ", population " << kd.m_population;
	cout << endl;
}

void sict::display(Kingdom kingdom[], int noOfKingdoms)
{
	int totalPopulation = 0;
	cout << "------------------------------" << endl;
	cout << "Kingdoms of SICT" << endl;
	cout << "------------------------------" << endl;

	for (int i = 0; i < noOfKingdoms; i++) {
		totalPopulation += kingdom[i].m_population;
		cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
	}
	cout << "------------------------------" << endl;
	cout << "Total population of SICT: " << totalPopulation << endl;
	cout << "------------------------------" << endl;
}

