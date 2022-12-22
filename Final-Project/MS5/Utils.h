/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.0
// Date 2022/11/05
// Author Sandeep Singh
// Description
// Extra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Sandeep Singh    2022/11/06     Added intendMenu function
//Sandeep Singh    2022/11/10     Added userInput function
//Sandeep Singh    2022/11/10     Added printHeader function
//Sandeep Singh    2022/11/17     Added toUpper function
//Sandeep Singh    2022/11/29     Modified userInput function
//Sandeep Singh    2022/12/06     Added validatePlate function
//Sandeep Singh    2022/12/06     Added clearBuffer function
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

#include <iostream>
#include <cstring>
namespace sdds {

	void intendMenu(int intendVal);
	void printHeader(const char* str);
	bool userInput(std::istream& istr = std::cin, int length = 1);
	void toUpper(char* str);
	const char* validatePlate(std::istream& istr = std::cin);
	std::istream& clearBuffer(std::istream& istr = std::cin);
}
#endif // !
