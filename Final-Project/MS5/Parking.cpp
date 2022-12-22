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
Filename: Parking.cpp
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/09  Preliminary release
2022/12/06  Added definitions of the menu options
2022/12/06  Added definitions of the findSpot and freeSpots functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Parking.h"
#include "Motorcycle.h"
#include "Car.h"

using namespace std;
namespace sdds
{
	/******************************************
				  CONSTRUCTORS
	******************************************/

	// *** DEFAULT CONSTRUCTOR ***

	// Calls the setEmpty() function to set the object to the empty state.
	Parking::Parking()
	{
		m_filename = nullptr;
		m_mainMenu.clear();
		m_vehicleMenu.clear();
		for (int i = 0; i < MAX_SPOTS; i++)
		{
			m_parkedVehicles[i] = nullptr;
		}
		m_noOfSpots = 0;
		totalParkedVehicles = 0;
	}

	// *** OVERLOADED CONSTRUCTOR ***

	// Calls the overloaded constructor of the Menu class for both the menus declared in the Parking class
	Parking::Parking(const char* file, int spots) : m_mainMenu("Parking Menu, select an action:"), m_vehicleMenu("Select type of the vehicle:", 1)
	{
		for (int i = 0; i < MAX_SPOTS; i++)
		{
			m_parkedVehicles[i] = nullptr;
		}
		m_noOfSpots = 0;
		totalParkedVehicles = 0;
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
		if (spots < 10 || spots > MAX_SPOTS)
		{
			setEmpty();
		}
		else
		{
			m_noOfSpots = spots;
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
		for (int i = 0; i < m_noOfSpots; i++)
		{
			if (m_parkedVehicles[i] != nullptr)
			{
				delete m_parkedVehicles[i];
				m_parkedVehicles[i] = nullptr;
			}
		}
		// Delete the DMA for m_filename and set the pointer to nullptr.
		delete[] m_filename;
		m_filename = nullptr;
	}

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
		// Loop to traverse through the Vehicle pointer array and delete Vehicles, if any and set all to nullptr.
		for (int i = 0; i < MAX_SPOTS; i++)
		{
			if (m_parkedVehicles[i] != nullptr)
			{
				delete m_parkedVehicles[i];
			}
			m_parkedVehicles[i] = nullptr;
		}
		m_noOfSpots = 0;
		totalParkedVehicles = 0;
	}

	void Parking::parkingStatus() const
	{
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << freeSpots();
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}

	int Parking::freeSpots() const
	{
		return m_noOfSpots - totalParkedVehicles;
	}

	int Parking::allocateSpot(Vehicle* src)
	{
		int index = 0;
		bool flag = false;
		src->setCsv(false);
		src->read();
		// Loop to traverse through the array and look for the first empty spot
		for (int i = 0; i < m_noOfSpots && !flag; i++)
		{
			if (m_parkedVehicles[i] == nullptr)
			{
				index = i;
				// Sets the m_parkedVehickes at the particular index found to the src pointer and exits the loop
				m_parkedVehicles[index] = src;
				flag = true;
			}
		}

		// Returns the index found in the loop
		return index;
	}

	/*************************
		   MENU OPTIONS
	**************************/

	// *** 1. PARK OPTION ***
	void Parking::parkVehicle()
	{
		int selection = 0, index = 0;
		// FUNCTION CALL: Calls freeSpots() to check if any spot is available for parking
		if (freeSpots())
		{
			// FUNCTION CALL: Calls run() to run the m_vehicleMenu and stores the return value in selection for further use.
			selection = m_vehicleMenu.run();
			// IF CONDITION: If the user selects 1, which is a car, create a dynamic instance of a Car and set it to the first available index in the pointer array
			if (selection == 1)
			{
				Car* temp = new Car;
				index = allocateSpot(temp);
			}
			// IF CONDITION: If the user selects 2, which is a Motorcycle, create a dynamic instance of a Motorcycle and set it to the first available index in the pointer array
			else if (selection == 2)
			{
				Motorcycle* temp = new Motorcycle;
				index = allocateSpot(temp);
			}
			else if (selection == 3)
			{
				cout << "Parking Cancelled" << endl;
			}

			if (selection == 1 || selection == 2)
			{
				// If a vehicle was parked, print a parking ticket with the details of the vehicle
				totalParkedVehicles++;
				cout << endl << "Parking Ticket" << endl;
				m_parkedVehicles[index]->setParkingSpot(index + 1);
				m_parkedVehicles[index]->write();
				cout << endl;
			}
		}
		else
		{
			cout << "Parking is full" << endl;
		}
		clearBuffer();
	}

	// *** 2. RETURN OPTION ***
	void Parking::returnVehicle()
	{
		// Prints the statements for returning the vehicle
		bool flag = false;
		char temp[9]{};
		int index = 0;
		cout << "Return Vehicle" << endl;
		// FUNCTION CALL: Calls validatePlate() to validate the user entered license Plate and copies it to temp after successful validation
		strcpy(temp, validatePlate());

		// Loop to traverse through the Vehicle array and find the vehicle matching the entered license Plate
		for (int i = 0; i < m_noOfSpots && !flag; i++)
		{
			if (m_parkedVehicles[i] != nullptr)
			{
				if (*m_parkedVehicles[i] == temp)
				{
					// If found, set index to the i at that instance and exit the loop
					index = i;
					flag = true;
				}
			}
		}
		// If a match was found, return the vehicle by first printing the Vehicle and then deleting it.
		if (flag)
		{
			cout << endl << "Returning:" << endl;
			m_parkedVehicles[index]->setCsv(false);
			m_parkedVehicles[index]->write(cout);
			cout << endl;
			delete m_parkedVehicles[index];
			m_parkedVehicles[index] = nullptr;
			totalParkedVehicles--;
		}
		// If no match was found, print the NOT FOUND statement
		else
		{
			toUpper(temp);
			cout << endl << "License plate " << temp << " Not found" << endl << endl;
		}
		clearBuffer();
		cin.ignore();
	}

	// *** 3. LIST OPTION ***
	void Parking::listVehicles()
	{
		// Prints all vehicles in the parking (ignoring indices that point to a nullptr)
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_noOfSpots; i++)
		{
			if (m_parkedVehicles[i] != nullptr)
			{
				m_parkedVehicles[i]->setCsv(false);
				m_parkedVehicles[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
		clearBuffer();
	}

	// *** 4. SEARCH OPTION ***
	void Parking::searchVehicle()
	{
		bool flag = false;
		char temp[9]{};
		int index = 0;
		// Prints the statements for finding a vehicle
		cout << "Vehicle Search" << endl;

		// FUNCTION CALL: Calls validatePlate() to validate the user entered license Plate and copies it to temp after successful validation
		strcpy(temp, validatePlate());
		cout << endl;

		// Loop to traverse through the Vehicle array and find the vehicle matching the entered license Plate
		for (int i = 0; i < m_noOfSpots && !flag; i++)
		{
			if (m_parkedVehicles[i] != nullptr)
			{
				if (*m_parkedVehicles[i] == temp)
				{
					// If found, set index to the i at that instance and exit the loop
					index = i;
					flag = true;
				}
			}
		}
		// If a match was found, print the vehicle
		if (flag)
		{
			cout << "Vehicle found:" << endl;
			m_parkedVehicles[index]->setCsv(false);
			m_parkedVehicles[index]->write();
			cout << endl;
		}
		// If no match was found, print the NOT FOUND statement
		else
		{
			toUpper(temp);
			cout << "License plate " << temp << " Not found" << endl << endl;
		}
		clearBuffer();
		cin.ignore();
	}

	// *** 5. CLOSING OPTION ***
	bool Parking::closeParking()
	{
		bool returnVal = false;
		if (isEmpty())
		{
			cout << "Closing Parking" << endl;
			returnVal = true;
		}
		else
		{
			// FUNCTION CALL: Calls userInput function to validate the user's input of the valid selections and returns boolean based on if the selection is Yes or No.
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			returnVal = userInput();

			// If the user entered yes:
			if (returnVal)
			{
				cout << "Closing Parking" << endl << endl;
				// Loop to traverse through the Vehicle array and empty it by first printing a "TOWING REQUEST" ticket with the details of the vehicle, and then deleting the vehicle from the array
				for (int i = 0; i < m_noOfSpots; i++)
				{
					if (m_parkedVehicles[i] != nullptr)
					{
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						m_parkedVehicles[i]->setCsv(false);
						m_parkedVehicles[i]->write();
						if (i != m_noOfSpots - 1)
						{
							cout << endl;
						}
						delete m_parkedVehicles[i];
						m_parkedVehicles[i] = nullptr;
					}
				}
			}
		}
		return returnVal;
	}

	// *** 6. EXITING OPTION ***
	bool Parking::exitParking()
	{
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		// FUNCTION CALL: Calls userInput function to validate the user's input of the valid selections and returns boolean based on if the selection is Yes or No.
		return userInput();
	}


	/******************************
		LOAD AND SAVE FUNCTIONS
	******************************/
	bool Parking::LoadData()
	{
		bool returnVal = false;
		bool flag = false;
		// FUNCTION CALL: Calls isEmpty() to check if the current object is in empty state or not  and prints statements based on the function's return
		if (!isEmpty())
		{
			// Creates an instance of ifstream to open the file
			ifstream file(m_filename);
			if (!file.is_open())
			{
				returnVal = true;
			}
			else
			{
				char ch = 0;
				for (int i = 0; i < m_noOfSpots && !flag; i++)
				{
					// Get a character from the file and ignore the next.
					ch = file.get();
					file.ignore();
					// If the character got is a M:
					if (ch == 'M')
					{
						// Creates an instance of the Motorcycle and reads its contents from the file
						Motorcycle* temp = new Motorcycle;
						temp->setCsv(true);
						temp->read(file);
						if (file)
						{
							// If the read was successful, set the Vehicle to the particular parking spot in the Vehicle pointer array
							m_parkedVehicles[temp->getParkingSpot() - 1] = temp;
							// Increment the count of total parked vehicles
							totalParkedVehicles++;
							returnVal = true;
						}
						else
						{
							// If the read was unsuccessful, delete the temp pointer and set it to nullptr and also set the returnVal to false
							delete temp;
							temp = nullptr;
							returnVal = false;
							flag = true;
						}
					}
					// If the character got is a C:
					else if (ch == 'C')
					{
						// Creates an instance of the Car and reads its contents from the file
						Car* temp = new Car;
						temp->setCsv(true);
						temp->read(file);
						if (file)
						{
							// If the read was successful, set the Vehicle to the particular parking spot in the Vehicle pointer array
							m_parkedVehicles[temp->getParkingSpot() - 1] = temp;
							totalParkedVehicles++;
							returnVal = true;
						}
						else
						{
							// If the read was unsuccessful, delete the temp pointer and set it to nullptr and also set the returnVal to false
							delete temp;
							temp = nullptr;
							returnVal = false;
							flag = true;
						}
					}
					else if (ch == EOF)
					{
						// If it is the end of file, exit the loop
						flag = true;
					}
				}

				// Close the file
				file.close();
			}
		}
		// Returns the state of the function
		return returnVal;
	}

	void Parking::saveData()
	{
		// FUNCTION CALL: Calls isEmpty() to check if the current object is in empty state or not and prints statements based on the function's return
		if (!isEmpty())
		{
			// Creates an instance of ofstream to open the file
			ofstream file(m_filename);

			// IF file is open
			if (file.is_open())
			{
				// Loop through the elements of the Vehicle array and for all values that are not null, write them to the file in CSV mode.
				for (int i = 0; i < m_noOfSpots; i++)
				{
					if (m_parkedVehicles[i] != nullptr)
					{
						m_parkedVehicles[i]->setCsv(true);
						file << *m_parkedVehicles[i];
					}
				}
			}
			// Close the file after writing
			file.close();
		}
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
					cout << "Exiting program!" << endl;
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