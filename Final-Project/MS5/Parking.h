/*
*****************************************************************************
						MILESTONE 5

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 07/12/2022

Citation and Sources...
Final Project Milestone 5
Module: Parking
Filename: Parking.h
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/09  Preliminary release
2022/12/06  Added declarations of freeSpots and allocateSpot function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Menu.h"
#include "Vehicle.h"
#include <cstring>

namespace sdds
{
	const int MAX_SPOTS = 100;
	class Parking
	{
		/******************************************
					  DATA MEMBERS
		******************************************/
		char* m_filename{};
		Menu m_mainMenu{};
		Menu m_vehicleMenu{};
		int m_noOfSpots = 0;
		Vehicle* m_parkedVehicles[MAX_SPOTS];
		int totalParkedVehicles = 0;

		/******************************************
				   PRIVATE MEMBER FUNCTIONS
		******************************************/
		bool isEmpty() const;
		void setEmpty();
		void parkingStatus() const;
		int freeSpots() const;
		int allocateSpot(Vehicle* src);

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
		Parking(const char* file, int spots);
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