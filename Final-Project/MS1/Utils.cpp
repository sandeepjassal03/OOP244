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
}