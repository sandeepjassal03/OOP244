/*
*****************************************************************************
						Workshop-3 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 29/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "NameTag.h"

namespace sdds
{
	void NameTag::set(const char* name)
	{
		// IF condition: If the name pointer isn't null, copy the name to the class data member u_name.
		if (name != nullptr)
		{
			strcpy(u_name, name);
		}
	}

	char* NameTag::returnString()
	{
		// Return the pointer to the string stored in the class data member u_name.
		return u_name;
	}

}