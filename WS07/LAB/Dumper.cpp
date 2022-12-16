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
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

namespace sdds
{
	Dumper::Dumper(): VehicleBasic()
	{
		maxLoad = 0;
		currentLoad = 0;
	}
	Dumper::Dumper(const char* license, int year, int capacity, const char* vehicleLocation): VehicleBasic(license, year)
	{
		currentLoad = 0;
		maxLoad = capacity;
		NewAddress(vehicleLocation);
	}

	bool Dumper::loaddCargo(double cargo)
	{
		bool returnVal = false;
		// Checks if the existing load and the current load combined are less than the maxLoad, if yes sets currentLoad as the sum of two otherwise no changes made.
		if (cargo + currentLoad <= maxLoad)
		{
			currentLoad += cargo;
			returnVal = true;
		}
		return returnVal;
	}
	bool Dumper::unloadCargo()
	{
		bool returnVal = false;
		// if current load is not zero, set it to zero.
		if (currentLoad)
		{
			currentLoad = 0;
			returnVal = true;
		}
		return returnVal;
	}

	ostream& Dumper::write(ostream& os) const
	{
		VehicleBasic::write(os);
		os << " | " << currentLoad << "/" << maxLoad; 
		return os;
	}
	istream& Dumper::read(istream& in)
	{
		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> maxLoad;
		cout << "Cargo: ";
		in >> currentLoad;
		return in;
	}
	
	ostream& operator<<(ostream& os, const Dumper& vehicle) 
	{
		vehicle.write(os);
		return os;
	}
	istream& operator>>(istream& in, Dumper& vehicle)
	{
		vehicle.read(in);
		return in;
	}
	
}

