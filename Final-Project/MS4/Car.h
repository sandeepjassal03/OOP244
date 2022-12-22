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
Module: Car
Filename: Car.h
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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include <iostream>
#include "Vehicle.h"
namespace sdds
{
	class Car : public Vehicle
	{
		int carWash = 0;

		/******************************************
				  PRIVATE MEMBER FUNCTIONS
		******************************************/
		void setEmpty();
		bool isEmpty() const;
	public:
		/******************************************
					  CONSTRUCTORS
		******************************************/
		Car();
		Car(const char* plate, const char* model);
		Car(const Car& source);

		// *** ASSIGNMENT OPERATOR *** 
		Car& operator=(const Car& source);

		/******************************************
				  PUBLIC MEMBER FUNCTIONS
		******************************************/
		virtual std::ostream& writeType(std::ostream& ostr) const;
		virtual std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;
	};
}
#endif