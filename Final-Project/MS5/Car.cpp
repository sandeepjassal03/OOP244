/*
*****************************************************************************
						MILESTONE 5

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 29/11/2022

Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.cpp
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

#include "Car.h"

using namespace std;

namespace sdds
{
	void Car::setEmpty()
	{
		Vehicle::setEmpty();
		carWash = 0;
	}
	bool Car::isEmpty() const
	{
		return (Vehicle::isEmpty());
	}
	/********************************************
					CONSTRUCTORS
	*********************************************/

	// *** DEFAULT CONSTRUCTOR *** 
	// Uses the default constructor of the Vehicle class to initialize the object
	Car::Car():Vehicle()
	{
		carWash = 0;
	}

	// *** OVERLOADED CONSTRUCTOR *** 
	// Uses the 2-argument constructor of the Vehicle class to initialize the object
	Car::Car(const char* plate, const char* model):Vehicle(plate, model) 
	{

	}

	// *** COPY CONSTRUCTOR *** 
	Car::Car(const Car& source)
	{
		// Calls the overloaded assignment operator to copy the contents safely
		*this = source;
	}

	// *** ASSIGNMENT OPERATOR *** 
	Car& Car::operator=(const Car& source)
	{
		// Calls the operator of the Vehicle class to copy the contents safely
		Vehicle::operator=(source);

		// Shallow copies the member variable sideCar
		carWash = source.carWash;

		return *this;
	}

	/********************************************
			  PUBLIC MEMBER FUNCTIONS
	*********************************************/

	std::ostream& Car::writeType(std::ostream& ostr) const
	{
		// If the object is in Comma separated mode: print C otherwise print the statement
		if (Vehicle::isCsv())
		{
			ostr << "C,";
		}
		else
		{
			ostr << "Vehicle type: Car" << endl;
		}

		// Returns the reference of the ostream
		return ostr;
	}
	std::istream& Car::read(std::istream& istr)
	{
		// If the object is in Comma separated mode:
		if (isCsv())
		{
			// Calls the read function of the base class
			Vehicle::read(istr);

			// Reads an integer from the istream and puts it in carWash variable
			istr >> carWash;
			istr.ignore(100, '\n');
		}
		// If the object is not in Comma separated mode:
		else
		{
			cout << endl << "Car information entry" << endl;

			// Calls the read function of the base class
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			carWash = userInput(istr, 1);
		}
		// Returns the reference of istream
		return istr;
	}
	std::ostream& Car::write(std::ostream& ostr) const
	{
		// If the object is in invalid empty state:
		if (isEmpty())
		{
			ostr << "Invalid Car Object" << endl;
		}
		// Or if it is in valid state
		else
		{
			// Calls the write function of the Vehicle class
			Vehicle::write(ostr);

			if (isCsv())
			{
				ostr << carWash << endl;
			}
			else
			{
				carWash ? ostr << "With Carwash" : ostr << "Without Carwash";
				cout << endl;
			}
		}
		// Returns the reference of ostream
		return ostr;
	}
}