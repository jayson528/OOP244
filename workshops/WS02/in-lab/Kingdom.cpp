/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2018-05-29
// Author jayson sherry 141056176
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

