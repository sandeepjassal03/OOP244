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
Module: Vehicle
Filename: Vehicle.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include "Vehicle.h"
#include <cstring>
using namespace std;
namespace sdds
{
	void Vehicle::setEmpty()
	{
		parkingSpot = 0;
		licensePlate[0] = '\0';
		if (modelAndMake != nullptr)
		{
			delete[] modelAndMake;
			modelAndMake = nullptr;
		}

	}
	bool Vehicle::isEmpty() const
	{
		// Returns true if licensePlate and modelAndMake are both null values, false otherwise
		return (licensePlate[0] == '\0' && modelAndMake == nullptr);
	}
	/******************************************
				  CONSTRUCTORS
	******************************************/

	// *** DEFAULT CONSTRUCTOR ***
	Vehicle::Vehicle()
	{
		// Sets the values to a safe state
		parkingSpot = 0;
		licensePlate[0] = '\0';
		modelAndMake = nullptr;
	}
	// *** OVERLOADED CONSTRUCTOR ***
	Vehicle::Vehicle(const char* plate, const char* model)
	{
		// IF CONDITION: Checks if the title and model are not nullptrs, set the values as described, otherwise set it to an empty state.
		if (plate != nullptr && model != nullptr)
		{
			// IF CONDITION: Checks if the title or model are empty or have length below the minimum requirement,if yes, set it to an empty state, otherwise, set the values as described,
			if ((strlen(plate) > 8 || plate[0] == '\0') || (strlen(model) < 2 || model[0] == '\0'))
			{
				setEmpty();
			}
			else
			{
				strcpy(licensePlate, plate);
				modelAndMake = new char[strlen(model) + 1];
				strcpy(modelAndMake, model);
			}
		}
		else
		{
			setEmpty();
		}
	}
	// *** COPY CONSTRUCTOR ***
	Vehicle::Vehicle(const Vehicle& source)
	{
		// Sets the object to safe empty state
		setEmpty();

		// CALL TO OVERLOADED ASSIGNMENT OPERATOR to set the current object to the supplied value after validating
		*this = source;
	}

	Vehicle& Vehicle::operator=(const Vehicle& source)
	{
		// check for self-assignment
		if (this != &source) {
			// Set the current object to safe state
			setEmpty();

			// Shallow copy
			parkingSpot = source.parkingSpot;
			strcpy(licensePlate, source.licensePlate);
			setCsv(source.isCsv());
			//Deep Copy
			//If the supplied pointer of modelAndMake isn't a nullptr, allocate new memory and set the value
			if (source.modelAndMake != nullptr) 
			{	
				modelAndMake = new char[strlen(source.modelAndMake) + 1];
				strcpy(modelAndMake, source.modelAndMake);
			}
		}
		// Returns the reference of the current object
		return *this;
	}

	Vehicle::~Vehicle()
	{
		// Deletes the DMA for modelAndMake and sets it to nullptr
		delete[] modelAndMake;
		modelAndMake = nullptr;
	}

	const char* Vehicle::getLicensePlate() const
	{
		// Returns licensePlate
		return licensePlate;
	}
	const char* Vehicle::getMakeModel() const
	{
		// Returns modelAndMake
		return modelAndMake;
	}
	int Vehicle::getParkingSpot() const
	{
		// Returns parkingSpot
		return parkingSpot;
	}
	void Vehicle::setParkingSpot(int value)
	{
		// IF CONDITION: If the supplied value is a positive number, set it to parkingSpot, otherwise set the object to invalid empty state.
		if (value >= 0)
		{
			parkingSpot = value;
		}
		else
		{
			setEmpty();
		}
	}
	void Vehicle::setMakeModel(const char* model)
	{
		// IF CONDITION: Checks if the modelAndMake is not nullptr 
		if (modelAndMake != nullptr)
		{
			// If yes, deletes the memory and sets the pointer to nullptr
			delete[] modelAndMake;
			modelAndMake = nullptr;
		}

		// IF CONDITION: Checks if the model passed is not nullptr and not empty
		if (model != nullptr && model[0] != '\0')
		{
			//If yes, allocate new memory and copy data into it
			modelAndMake = new char[strlen(model) + 1];
			strcpy(modelAndMake, model);
		}
		else
		{
			// If not, set the object to invalid empty state.
			setEmpty();
		}
	}

	bool Vehicle::operator==(const char* string) const
	{
		bool returnVal = false;

		// IF CONDITION: Checks if the string passed is not nullptr and not empty
		if (string != nullptr && string[0] != '\0')
		{
			// If yes, set returnVal equal to the value described ( negate of the return of strcasecmp function)
			// strcasecmp(): Library function to ignore the case while comparing strings
			returnVal = !strcasecmp(licensePlate, string);
		}
		return returnVal;
	}
	bool Vehicle::operator==(const Vehicle& veh) const
	{
		// Returns the return of the overloaded == operator
		return operator==(veh.licensePlate);
	}
	std::istream& Vehicle::read(std::istream& istr)
	{
		char temp[61]{};
		int length = 0;

		// FUNCTION CALL: Calls isCsv() to check if the current object is set to read in Comma separated values or not
		if (isCsv())
		{
			// If yes, read the values in Comma separated mode, ignoring the commas
			istr >> parkingSpot;
			istr.ignore();
			istr.getline(licensePlate, 9, ',');
			istr.getline(temp, 60, ',');
		}
		else
		{
			// If no, read the values as described
			bool flag = false;
			istr.clear();
			std::cout << "Enter License Plate Number: ";
			while (!flag)
			{
				// Reads one line from istream
				istr.getline(temp, 60);
				// Sets length equal to the length of the string read from istream
				length = strlen(temp);

				// If istr fails, set the object to invalid empty state
				if (istr.fail())
				{
					setEmpty();
				}
				// If the string length is greater than 8, clear the istr and print the statement
				else if (!istr.fail() && strlen(temp) > 8)
				{
					istr.clear();
					std::cout << "Invalid License Plate, try again: ";
				}
				// If the string read is a correct value, copy it from temp to licensePlate and set flag to true to exit loop
				else if (!istr.fail() && strlen(temp) < 9)
				{
					strcpy(licensePlate, temp);
					flag = true;
				}
			}
			flag = false;
			std::cout << "Enter Make and Model: ";
			while (!flag)
			{
				// Reads one line from istream
				istr.getline(temp, 60);
				// Sets length equal to the length of the string read from istream
				length = strlen(temp);

				// If istr fails, set the object to invalid empty state
				if (istr.fail())
				{
					setEmpty();
				}
				// If the string read is a correct value, copy it from temp to licensePlate and set flag to true to exit loop
				else if (!istr.fail() && length > 1 && length < 61)
				{
					flag = true;
				}
				// If the string length is not correct, clear the istr and print the statement
				else
				{
					istr.clear();
					std::cout << "Invalid Make and model, try again: ";
				}
			}

			// Set parking spot to zero
			parkingSpot = 0;
		}

		//IF CONDITION: If istr didnot fail during read, set the values as described
		if (istr)
		{
			// FUNCTION CALL: Utils.h => toUpper(char* string): Sets the string to be in Uppercase
			toUpper(licensePlate);

			// FUNCTION CALL: setMakeModel(): sets the modelAndMake string
			setMakeModel(temp);
		}
		else
		{
			// If istr failed during read, set the object to invalid empty state.
			setEmpty();
		}
		return istr;
	}

	std::ostream& Vehicle::write(std::ostream& ostr) const
	{
		// FUNCTION CALL: Calls isEmpty() to check if the current object is in empty state or not4
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else
		{
			writeType(ostr);
			// FUNCTION CALL: Calls isCsv() to check if the current object is set to read in Comma separated values or not
			if (isCsv())
			{
				// If yes, then print values in Comma separated mode.
				ostr << parkingSpot << "," << licensePlate << "," << modelAndMake << ",";
			}
			else
			{
				// If no, print the values as described below:
				ostr << "Parking Spot Number: ";
				if (!parkingSpot)
				{
					ostr << "N/A" << endl;
				}
				else
				{
					ostr << parkingSpot << endl;
				}
				ostr << "License Plate: " << licensePlate << endl;
				ostr << "Make and Model: " << modelAndMake << endl;
			}
		}

		// Returns the reference of the ostream
		return ostr;
	}
}