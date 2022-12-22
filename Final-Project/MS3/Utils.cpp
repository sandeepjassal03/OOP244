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

	bool userInput()
	{
		char selection = 0;
		bool returnVal = false, flag = false;
		do
		{
			// cin to ask for the user choice
			cin >> selection;
			// If cin passes, set the returnVal and flag accordingly
			if (cin && (selection == 'Y' || selection == 'y' || selection == 'N' || selection == 'n'))
			{
				switch (selection)
				{
				case 'Y':
				case 'y':
					returnVal = true;
					flag = true;
					break;
				case 'N':
				case 'n':
					returnVal = false;
					flag = true;
				}

			}
			// If cin passes but choice entered is not a valid choice, say the print statement
			else
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}

			// In any case, flush the input stream
			cin.clear();
			cin.ignore(1000, '\n');
		} while (!flag);// LOOPING CONDITION: Continue looping until flag is false.
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