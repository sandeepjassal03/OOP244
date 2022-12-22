/*
*****************************************************************************
						MILESTONE 2

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 09/11/2022

Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.h
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include <iostream>
#include "Utils.h"
#include "Menu.h"
#include <cstring>

namespace sdds
{
	class Parking
	{
		/******************************************
					  DATA MEMBERS
		******************************************/
		char* m_filename{};
		Menu m_mainMenu{};
		Menu m_vehicleMenu{};

		/******************************************
				   PRIVATE MEMBER FUNCTIONS
		******************************************/
		bool isEmpty() const;
		void setEmpty();
		void printMockup(const char* str) const;

		void parkingStatus();

		void parkVehicle();
		void returnVehicle();
		void listVehicles();
		void searchVehicle();

		bool closeParking();
		bool exitParking();

		bool LoadData();
		void saveData();

	public:
		/******************************************
					  CONSTRUCTORS
		******************************************/
		Parking();
		Parking(const char* file);
		Parking(const Parking& source) = delete;

		// *** DESTRUCTOR ***
		~Parking();

		/******************************************
					MEMBER OPERATORS
		******************************************/
		Parking& operator=(const Parking& source) = delete;

		/******************************************
				     MEMBER FUNCTIONS
		******************************************/
		int run();
	};
}

#endif