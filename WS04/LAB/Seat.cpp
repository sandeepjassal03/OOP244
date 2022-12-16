/*
*****************************************************************************
						Workshop-4 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 04/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Seat.h"

namespace sdds {

	bool Seat::validate(int row, char letter)const
	{
		//return variable
		bool returnVal = false;

		// IF CONDITION: Checks if the conditions of validating the parameters supplied are met as per the given pattern, if true then returns true otherwise false.
		if (row >= 1 && row <= 4)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')
			{
				returnVal = true;
			}
		}
		else if ((row >= 7 && row <= 15) || (row >= 20 && row <= 38))
		{
			if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')
			{
				returnVal = true;
			}
		}
		return returnVal;
	}

	Seat& Seat::alAndCp(const char* str)
	{
		name = nullptr;
		// IF CONDITION: Checks if str is not null and not empty : if true, then memory is allocated to the name data member and value is assigned
		if (str && str[0] != '\0')
		{
			name = new char[strlen(str) + 1];
			strcpy(name, str);
		}
		return *this;
	}

	Seat::Seat()
	{
		// Default CONSTRUCTOR: Sets name to nullptr and resets data by calling reset()
		name = nullptr;
		reset();
	}
	Seat::Seat(const char* passengerName)
	{
		// Overloaded CONSTRUCTOR: Recieves name as parameter and sets name as the value passed by calling alAndCp() and sets other two members to 0.
		alAndCp(passengerName);
		rowNumber = 0;
		seatLetter = '\0';
	}
	Seat::Seat(const char* passengerName, int row, char letter)
	{
		// Overloaded CONSTRUCTOR: Recieves name, row and letter as parameters and sets name as the value passed by calling alAndCp() and sets other two membersby calling set() function.
		alAndCp(passengerName);
		set(row, letter);
	}
	Seat:: ~Seat()
	{
		// DESTRUCTOR: Deletes name and sets it to nullptr.
		delete[] name;
		name = nullptr;
	}

	Seat& Seat::reset()
	{
		// Deletes name and sets it to nullptr. Also, sets rowNumber and seatLetter to safe state -> 0 and \0 respectively.
		delete[] name;
		name = nullptr;
		rowNumber = 0;
		seatLetter = '\0';

		// Returns the reference of current object.
		return *this;
	}

	bool Seat::isEmpty() const
	{
		// Returns true or false based on if name is nullptr or not.
		return name == nullptr;
	}

	bool Seat::assigned() const
	{
		// Returns the return value of the validate() function: to check if data can be assigned.
		return validate(rowNumber, seatLetter);
	}

	Seat& Seat::set(int row, char letter)
	{
		// IF CONDITION: Runs the validate() function to check if the values are valid. If true, sets the data members to the parameters else sets them to safe empty state.
		if (validate(row, letter))
		{
			rowNumber = row;
			seatLetter = letter;
		}
		else
		{
			rowNumber = 0;
			seatLetter = '\0';
		}

		// Returns the reference of current object.
		return *this;
	}

	int Seat::row()const
	{
		// Returns the rowNumber
		return rowNumber;
	}

	char Seat::letter()const
	{
		// Returns the seatLetter
		return seatLetter;
	}

	const char* Seat::passenger()const
	{
		// Returns the name
		return name;
	}

	std::ostream& Seat::display(std::ostream& coutRef)const
	{
		// Checks if the object is in safe empty state or not: If yes, prints invalid else displays the data.
		if (isEmpty())
		{
			coutRef << "Invalid Seat!";
		}
		else
		{
			char passengerName[40 + 1] = { '\0' };

			// strncpy: copies the data in the data member to the local Variable uptil the length specified.
			strncpy(passengerName, passenger(), 40);


			coutRef.setf(std::ios::left);
			coutRef.width(40);
			coutRef.fill('.');
			coutRef << passengerName;
			coutRef.fill(' ');
			coutRef.unsetf(std::ios::left);

			//IF condition: Calls the assigned() function to return true or false if the seats are assigned and valid or unassigned and invalid by returning the validate() call result.
			if (assigned())
			{
				coutRef << " " << row() << letter();
			}
			else
			{
				coutRef << " ___";
			}

		}

		// Returns the reference of the ostream
		return coutRef;
	}

	std::istream& Seat::read(std::istream& cinRef)
	{
		char p_name[70 + 1] = { '\0' };
		int rowNum = 0;
		char letter = '\0';

		bool success = false;

		reset();

		// Reads one line delimited to ',' from istream into p_name 
		cinRef.getline(p_name, 71, ',');
		if (cinRef)
		{
			// If cinRef is valid, it reads row
			cinRef >> rowNum;
			if (cinRef)
			{
				// If cinRef is valid, it reads letter
				cinRef >> letter;
				if (cinRef)
				{
					// If cinRef is valid, it sets success to true and ignores to newline
					success = true;
					cinRef.ignore(100, '\n');
				}
			}

			if (success)
			{
				// If success is true, allocate and copy data into the data members
				alAndCp(p_name);
			}

			if (!isEmpty())
			{
				// If name is not empty, set row and letter in the data members
				set(rowNum, letter);
			}
		}

		// Returns the reference of the istream
		return cinRef;
	}
}