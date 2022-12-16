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
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_

#include <iostream>

#include "TourTicket.h"

namespace sdds
{
	class TourBus {

		// A pointer of type TourTicket
		TourTicket* Bus;
		int totalPassengers;

	public:
		//************************************************
		//                 CONSTRUCTORS
		//************************************************

		// DEFAULT constructor
		TourBus();
		// OVERLOADED constructor
		TourBus(int passengers);

		//************************************************
		//                 DESTRUCTOR
		//************************************************
		~TourBus();

		//************************************************
		//           PUBLIC MEMBER FUNCTIONS
		//************************************************

		// Returns if the bus is in valid state or not using number of passengers.
		bool validTour() const;

		// board(): Boards the passengers by taking their names and issues tickets to them.
		TourBus& board();

		// This method should check and make sure the bus is in a valid state, then if all the passengers are boarded, it should print their name and ticket number to start the tour. 
		void startTheTour()const;

	};
}

#endif