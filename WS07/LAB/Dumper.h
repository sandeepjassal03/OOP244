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
#ifndef SDDS_DUMPER_H
#define SDDS_DUMPER_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper : public VehicleBasic 
	{
		double maxLoad;
		double currentLoad;
	public:
		Dumper();
		Dumper(const char* license, int year, int maxLoad, const char* vehicleLocation);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	
	ostream& operator<<(ostream& os, const Dumper& vehicle);
	istream& operator>>(istream& in, Dumper& vehicle);
	
}
#endif

