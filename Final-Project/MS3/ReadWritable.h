/*
*****************************************************************************
						MILESTONE 3

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 15/11/2022

Citation and Sources...
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/15  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#ifndef SDDS_READWRITABLE_H_
#define SDDS_READWRITABLE_H_

#include <iostream>
#include "Utils.h"
#include "Parking.h"
#include <cstring>

namespace sdds
{
	class ReadWritable
	{
		bool readMode;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);

		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;

	};
	 std::istream& operator>>(std::istream& istr, ReadWritable& obj);
	 std::ostream& operator<<(std::ostream& ostr, ReadWritable& obj);


}

#endif