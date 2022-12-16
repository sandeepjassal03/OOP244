/*
*****************************************************************************
						Workshop-7 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 08/11/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VEHICLEBASIC_H
#define SDDS_VEHICLEBASIC_H
#include<iostream>

using namespace std;
namespace sdds
{
	class VehicleBasic
	{
		char licenseNumber[9 + 1]{};
		char vehicleLocation[64 + 1]{};
		int builtYear;

	public:
		VehicleBasic();
		VehicleBasic(const char* license, int year);
		void NewAddress(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& in);
		

	};

	ostream& operator<<(ostream& os,const VehicleBasic& vehicle);
	istream& operator>>(istream& in, VehicleBasic& vehicle);
}

#endif

