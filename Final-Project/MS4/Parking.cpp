/*
*****************************************************************************
						MILESTONE 4

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 09/11/2022

Citation and Sources...
Final Project Milestone 4
Module: Parking
Filename: Parking.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include "Parking.h"

using namespace std;
namespace sdds
{
	/******************************************
			PRIVATE MEMBER FUNCTIONS
	******************************************/
	bool Parking::isEmpty() const
	{
		// Return variable
		bool returnVal = false;

		// IF CONDITION: Checks if the m_filename is null, if yes, set the returnVal to true, false otherwise
		if (m_filename == nullptr)
		{
			returnVal = true;
		}
		return returnVal;
	}

	void Parking::setEmpty()
	{
		//Sets the m_filename in the current object to the nullptr, and calls the clear() functions for menus to set them to empty state.
		m_filename = nullptr;
		m_mainMenu.clear();
		m_vehicleMenu.clear();
	}
	void Parking::printMockup(const char* str) const
	{
		cout << "---------------------------------" << endl;
		// IF CONDITION: Checks if the str is equal to the "Cancel" string, prints the statements as described, otherwise prints the Parking statement for the string passed
		if (!strcmp(str, "Cancel"))
		{
			cout << "Cancelled parking" << endl;
		}
		else
		{
			cout << "Parking " << str << endl;

		}
		cout << "---------------------------------" << endl << endl;
	}

	void Parking::parkingStatus()
	{
		cout << "****** Valet Parking ******" << endl;
	}


	void Parking::parkVehicle()
	{
		int selection;
		// FUNCTION CALL: Calls run() to run the m_vehicleMenu and stores the return value in selection for further use.
		selection = m_vehicleMenu.run();
		// FUNCTION CALL: Calls printMockup() to print the mockup Message for the vehicle selected by the user.
		printMockup(m_vehicleMenu.getMenuItem(selection));
	}
	void Parking::returnVehicle()
	{
		// Prints the statements for returning the vehicle
		printHeader("Returning Vehicle");
	}
	void Parking::listVehicles()
	{
		// Prints the statements for listing the parked vehicles
		printHeader("Listing Parked Vehicles");
	}
	void Parking::searchVehicle()
	{
		// Prints the statements for finding a vehicle
		printHeader("Finding a Vehicle");
	}
	bool Parking::closeParking()
	{
		cout << "This will close the parking; All the vehicles will be removed!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		// FUNCTION CALL: Calls userInput function to validate the user's input of the valid selections and returns boolean based on if the selection is Yes or No.
		return userInput();
	}
	bool Parking::exitParking()
	{
		cout << "This will terminate the application and save the data!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		// FUNCTION CALL: Calls userInput function to validate the user's input of the valid selections and returns boolean based on if the selection is Yes or No.
		return userInput();
	}

	bool Parking::LoadData()
	{
		bool returnVal = false;

		// FUNCTION CALL: Calls isEmpty() to check if the current object is in empty state or not  and prints statements based on the function's return
		if (!isEmpty())
		{
			cout << "---------------------------------" << endl;
			cout << "loading data from " << m_filename << endl;
			cout << "---------------------------------" << endl << endl;
			returnVal = true;
		}
		return returnVal;
	}

	void Parking::saveData()
	{
		// FUNCTION CALL: Calls isEmpty() to check if the current object is in empty state or not and prints statements based on the function's return
		if (!isEmpty())
		{
			cout << "---------------------------------" << endl;
			cout << "Saving data into " << m_filename << endl;
			cout << "---------------------------------" << endl;
		}
	}

	/******************************************
				  CONSTRUCTORS
	******************************************/

	// *** DEFAULT CONSTRUCTOR ***

	// Calls the setEmpty() function to set the object to the empty state.
	Parking::Parking()
	{
		setEmpty();
	}

	// *** OVERLOADED CONSTRUCTOR ***

	// Calls the overloaded constructor of the Menu class for both the menus declared in the Parking class
	Parking::Parking(const char* file) : m_mainMenu("Parking Menu, select an action:"), m_vehicleMenu("Select type of the vehicle:", 1)
	{
		// IF CONDITION: Checks if the file is a nullptr or an empty string, if yes, set the object to an empty state, otherwise set the values as described.
		if (file == nullptr || file[0] == '\0')
		{
			setEmpty();
		}
		else
		{
			m_filename = new char[strlen(file) + 1];
			strcpy(m_filename, file);
		}

		// FUNCTION CALL: Calls LoadData() to load Data from the file and returns true if Data is successfully loaded, false otherwise
		if (LoadData())
		{
			// Adds the new menu Items to the m_mainMenu
			m_mainMenu.add("Park Vehicle");
			m_mainMenu.add("Return Vehicle");
			m_mainMenu.add("List Parked Vehicles");
			m_mainMenu.add("Find Vehicle");
			m_mainMenu.add("Close Parking (End of day)");
			m_mainMenu.add("Exit Program");

			// Adds the new menu Items to the m_vehicleMenu
			m_vehicleMenu.add("Car");
			m_vehicleMenu.add("Motorcycle");
			m_vehicleMenu.add("Cancel");

		}
		else
		{
			// If the load was not successful, set the object to the empty state.
			cout << "Error in data file" << endl;
			setEmpty();
		}
	}

	// *** DESTRUCTOR ***
	Parking::~Parking()
	{
		// Calls saveData() to save data to the file
		saveData();
		// Delete the DMA for m_filename and set the pointer to nullptr.
		delete[] m_filename;
		m_filename = nullptr;
	}

	/******************************************
				 MEMBER FUNCTIONS
	******************************************/
	int Parking::run()
	{
		int selection = 0;
		bool exit = false;
		int returnVal = 0;

		// IF CONDITION: Checks if the current object is not empty, if yes, executes the code block
		if (!isEmpty())
		{
			// FUNCTION CALL: Calls the parkingStatus() function to print the current parking status.
			parkingStatus();

			// FUNCTION CALL: Calls run() to run the m_mainMenu and stores the return value in selection for further use. 
			selection = m_mainMenu.run();

			// SWITCH STATEMENT: Switches the cases based on the user's selection and calls run after the function corresponding to the selection is executed (except for cases 5 and 6)
			switch (selection)
			{
			case 1:
				parkVehicle();
				run();
				break;
			case 2:
				returnVehicle();
				run();
				break;
			case 3:
				listVehicles();
				run();
				break;
			case 4:
				searchVehicle();
				run();
				break;
			case 5:
				// FUNCTION CALL: Calls closeParking() and stores return value in exit variable
				exit = closeParking();
				if (!exit)
				{
					// If the selection was a No, re-call the run() function
					run();
				}
				else
				{
					// If the selection was a yes, end the application.
					cout << "Ending application!" << endl;
					// IF CONDITION: Checks if the current object is empty, if yes, set returnVal to 1, 0 otherwise.
					if (isEmpty())
					{
						returnVal = 1;
					}
				}
				break;
			case 6:
				// FUNCTION CALL: Calls closeParking() and stores return value in exit variable
				exit = exitParking();
				if (!exit)
				{
					// If the selection was a No, re-call the run() function
					run();
				}
				else
				{
					// If the selection was a yes, exit the application.
					cout << "Exiting application!" << endl;
					// IF CONDITION: Checks if the current object is empty, if yes, set returnVal to 1, 0 otherwise.
					if (isEmpty())
					{
						returnVal = 1;
					}
				}
				break;
			}
		}
		return returnVal;
	}
}
