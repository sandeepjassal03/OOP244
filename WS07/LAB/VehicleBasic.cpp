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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

namespace sdds
{
	VehicleBasic::VehicleBasic()
	{
		licenseNumber[0] = '\0';
		vehicleLocation[0] = '\0';
		builtYear = 0;
	}
	VehicleBasic::VehicleBasic(const char* license, int year)
	{
		strcpy(licenseNumber, license);
		builtYear = year;
		strcpy(vehicleLocation, "Factory\0");
	}
	void VehicleBasic::NewAddress(const char* address)
	{
		cout << "|";
		cout.width(8);
		cout.setf(ios::right);
		cout<< licenseNumber;
		cout << "| |";
		cout.width(20);
		cout << vehicleLocation;
		cout.unsetf(ios::right);
		cout << " ---> ";
		cout.width(20);
		cout.setf(ios::left);
		cout << address;
		cout << "|" << endl;
		cout.unsetf(ios::left);

		if (strcmp(vehicleLocation, address))
		{
			strcpy(vehicleLocation, address);
		}
		
	}
	ostream& VehicleBasic::write(ostream& os) const
	{
		os << "| " << builtYear << " | " << licenseNumber  << " | " << vehicleLocation;
		return os;
	}

	istream& VehicleBasic::read(istream& in)
	{
		cout << "Built year: ";
		in >> builtYear;
		cout << "License plate: ";
		in >> licenseNumber;
		cout << "Current location: ";
		in >> vehicleLocation;
		return in;
	}
	ostream& operator<<(ostream& os, const VehicleBasic& vehicle)
	{
		vehicle.write(os);
		return os;
	}
	istream& operator>>(istream& in, VehicleBasic& vehicle)
	{
		vehicle.read(in);
		return in;
	}

}
