/***********************************************************************
// Utils Module
// File  utils.h
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
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"
using namespace std;
namespace sdds {
	void intendMenu(int intendVal)
	{
		if (intendVal)
		{
			for (int j = 0; j < intendVal; j++)
			{
				cout << "    ";
			}
		}
	}
	void printHeader(const char* str)
	{
		cout << "---------------------------------" << endl;
		cout << str << endl;
		cout << "---------------------------------" << endl << endl;
	}

	bool userInput(std::istream& istr, int length)
	{
		char temp[10]{};
		bool returnVal = false, flag = false;
		int str = 0;
		while (!flag)
		{
			// Gets a line from the istr and stores it in temp variable
			istr.getline(temp, 10, '\n');
			str = strlen(temp);
			// If the input is a valid input (where it has to be just one letter):
			if (str == length)
			{
				// If the user enters y or Y
				if (!strcmp(temp, "y") || !strcmp(temp, "Y"))
				{
					// Set sideCar to 1 and change flag to true to exit loop
					flag = true;
					returnVal = 1;
				}
				// If the user enters n or N
				else if (!strcmp(temp, "n") || !strcmp(temp, "N"))
				{
					// Set sideCar to 0 and change flag to true to exit loop
					flag = true;
					returnVal = 0;
				}
				else
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			}
			// If the input is an invalid input:
			else
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
			
		}
		
		return returnVal;
	}

	void toUpper(char* str)
	{
		int length = 0;
		length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			// If the string character is a lowercase letter, change it to uppercase
			if (str[i] >= 97 && str[i] <= 122)
			{
				// Sets the string value to the value minus 32 to make it uppercase (using ASCII table)
				str[i] = str[i] - 32;
			}
		}
	}

}