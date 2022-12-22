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
Module: Vehicle
Filename: Vehicle.h
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
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include <iostream>
#include "Utils.h"
#include "ReadWritable.h"
#include<string.h>
namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char licensePlate[8+1]{};
		char* modelAndMake = nullptr;
		int parkingSpot = 0;

		void setEmpty();
		bool isEmpty() const;
	public:
		/******************************************
					  CONSTRUCTORS
		******************************************/
		Vehicle();
		Vehicle(const char* plate, const char* model);
		Vehicle(const Vehicle& veh);

		~Vehicle();

		Vehicle& operator=(const Vehicle& source);
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char* model);
		int getParkingSpot() const;

		void setParkingSpot(int value);

		bool operator==(const char* string)const;
		bool operator==(const Vehicle& veh)const;

		virtual std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;

		virtual std::ostream& writeType(std::ostream& ostr) const = 0;

	};
}

#endif