/*
*****************************************************************************
						MILESTONE 4

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 15/11/2022

Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.cpp
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
#include "ReadWritable.h"

namespace sdds
{
	ReadWritable::ReadWritable()
	{
		readMode = false;
	}
	ReadWritable::~ReadWritable(){}

	bool ReadWritable::isCsv()const
	{
		return readMode;
	}
	void ReadWritable::setCsv(bool value)
	{
		readMode = value;
	}

	std::istream& operator>>(std::istream& istr, ReadWritable& obj)
	{
		obj.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, ReadWritable& obj)
	{
		obj.write(ostr);
		return ostr;
	}
}