/*
*****************************************************************************
						MILESTONE 4

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 29/11/2022

Citation and Sources...
Final Project Milestone 4
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/29  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Motorcycle.h"

using namespace std;

namespace sdds
{
	void Motorcycle::setEmpty()
	{
		Vehicle::setEmpty();
		sideCar = 0;
	}
	bool Motorcycle::isEmpty() const
	{
		return (Vehicle::isEmpty());
	}

	/********************************************
					CONSTRUCTORS
	*********************************************/

	// *** DEFAULT CONSTRUCTOR *** 
	// Uses the default constructor of the Vehicle class to initialize the object
	Motorcycle::Motorcycle() :Vehicle()
	{
		sideCar = 0;
	}

	// *** OVERLOADED CONSTRUCTOR *** 
	// Uses the 2-argument constructor of the Vehicle class to initialize the object
	Motorcycle::Motorcycle(const char* plate, const char* model) : Vehicle(plate, model)
	{
		sideCar = 0;
	} 

	// *** COPY CONSTRUCTOR *** 
	Motorcycle::Motorcycle(const Motorcycle& source)
	{
		// Calls the overloaded assignment operator to copy the contents safely
		*this = source;
	}

	// *** ASSIGNMENT OPERATOR *** 
	Motorcycle& Motorcycle::operator=(const Motorcycle& source)
	{
		// Calls the operator of the Vehicle class to copy the contents safely
		Vehicle::operator=(source);

		// Shallow copies the member variable sideCar
		sideCar = source.sideCar;

		// Returns the reference of the current object
		return *this;
	}

	/********************************************
	   		  PUBLIC MEMBER FUNCTIONS
	*********************************************/

	std::ostream& Motorcycle::writeType(std::ostream& ostr) const
	{
		// If the object is in Comma separated mode: print M otherwise print the statement
		if (isCsv())
		{
			ostr << "M,";
		}
		else
		{
			ostr << "Vehicle type: Motorcycle" << endl;
		}

		// Returns the reference of the ostream
		return ostr;
	}
	std::istream& Motorcycle::read(std::istream& istr)
	{
		// If the object is in Comma separated mode:
		if (isCsv())
		{
			// Calls the read function of the base class
			Vehicle::read(istr);

			// Reads an integer from the istream and puts it in sideCar variable
			istr >> sideCar;
			istr.ignore(100, '\n');
		}
		// If the object is not in Comma separated mode:
		else
		{
			cout << endl << "Motorcycle information entry" << endl;

			// Calls the read function of the base class
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			sideCar = userInput(istr, 1);
		}
		// Returns the reference of istream
		return istr;
	}
	std::ostream& Motorcycle::write(std::ostream& ostr) const
	{
		// If the object is in invalid empty state:
		if (isEmpty())
		{
			ostr << "Invalid Motorcycle Object" <<endl;
		}
		// Or if it is in valid state
		else
		{
			// Calls the write function of the Vehicle class
			Vehicle::write();

			if (isCsv())
			{
				ostr << sideCar << endl;
			}
			else
			{
				if (sideCar)
				{
					ostr << "With Sidecar" << endl;
				}
			}
		}
		// Returns the reference of ostream
		return ostr;
	}
}