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
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

#include "Utils.h"

namespace sdds {
	
	// CONSTANT VARIABLES
	const int MAX_NAME_LENGTH = 50;
	const int FRAME_SPACE = 4;

	class NameTag {

		// MEMBER VARIABLES
		char u_name[MAX_NAME_LENGTH + 1] = {'\0'};

	public: 

		// This method sets the name, held by the NameTag object.
		void set(const char* name);

		// This method returns the name, held by the NameTag object.
		char* returnString();
	};

}
#endif // !SDDS_NAMETAG_H_

