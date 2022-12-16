/*
*****************************************************************************
						Workshop-4 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 07/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "TourBus.h"

using namespace std;

namespace sdds
{
	//************************************************
	//                 CONSTRUCTORS
	//************************************************

	// Default Constructor: Sets the data members to safe emoty state.
	TourBus::TourBus()
	{
		Bus = nullptr;
		totalPassengers = 0;
	}

	// Overloaded Constructor: integer passed which is the size of the bus (number of passengers)
	TourBus::TourBus(int passengers)
	{
		if (passengers) // Check if value passed isn't null/0.
		{
			Bus = new TourTicket[passengers]; // Allocate memory of an array to the Bus pointer.
		}
		totalPassengers = passengers; // Set total passengers to the parameter.
	}

	//************************************************
	//                 DESTRUCTOR
	//************************************************
	TourBus::~TourBus()
	{
		// Delete memory allocated to bus and set it to nullptr.
		delete[] Bus;
		Bus = nullptr;
	}

	//************************************************
	//              MEMBER FUNCTIONS
	//************************************************

	bool TourBus::validTour() const
	{
		// IF totalPassengers is 4 or 16 or 22 return true else false.
		return (totalPassengers == 4 || totalPassengers == 16 || totalPassengers == 22);
	}
	
	TourBus& TourBus::board()
	{
		// Local Variables
		int i;
		char name[40 + 1]{};

		cout << "Boarding " << totalPassengers << " Passengers:" << endl;
		for (i = 0; i < totalPassengers; i++)
		{
			cout << i+1 << "/" << totalPassengers << "- Passenger Name: ";
			cin.getline(name, 41, '\n');
			if (cin)
			{
				if (name[0]!='\0')
				{
					Bus[i].issue(name); // FUNCTION CALL issue(): If the cin returns true and name isn't null, copy the name entered to the index described.
				}
			}
		}
		return *this; // Returning the reference of the current object.
	}
	void TourBus::startTheTour() const
	{
		int i;
		// IF CONDITION: If validTour() returns true but passengers isn't equal to 4, print the statement.
		if (validTour() && totalPassengers != 4)
		{
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
		else // If the IF BLOCK is false, start the tour.
		{
			cout << "Starting the tour...." << endl;
			cout << "Passenger List:" << endl;
			cout << "|Row ";
			cout << "| ";
			cout.width(40);
			cout.setf(ios::left);
			cout << "Passenger Name" << " | " << "Num" << " |" << endl;
			cout.unsetf(ios::left);
			cout << "+----+------------------------------------------+-----+" << endl;

			for (i = 0; i < totalPassengers; i++)
			{ 
				cout << "|";
				cout.width(3);
				cout.setf(ios::right);
				cout << i + 1 << " ";
				cout.unsetf(ios::right);
				
				// FUNCTION CALL: display(): Display the data at the specified index in a formatted order.
				Bus[i].display();
				cout << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;
		}
	}
}