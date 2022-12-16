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
#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_

#include <iostream>
#include <cstring>

namespace sdds {
	class Seat {

		char* name;
		int rowNumber;
		char seatLetter;

		//***************************************************************************
		//                        PRIVATE MEMBER FUNCTIONS                                   
		//***************************************************************************
		/*
		Code a private method to return true if the row number and the seating letter, together correctly address a seat in the airplane. Validations:

		 row numbers 1 to 4, 7 to 15 and 20 to 38 are considered valid seat values.
		 for rows 1 to 4, letters A, B, E and F are acceptable values.
		 for the rest, the acceptable values are A, B, C, D, E and F.
		 If the row number and letter fall into the above pattern return true, otherwise, return false.

		 This method is a query, hence it does not modify the current object.
		 */
		bool validate(int row, char letter)const;

		/*
		Since on many occasions you need to allocate memory for passenger name and copy the value into the allocated memory, it is better to create a private method to modularize this action.

		 before validating the str argument to be a valid Cstring set the passenger name pointer attribute to nullptr so the passenger name pointer will be set to nullptr if allocation fails.
		 then validate the str argument. If it is not null and not empty, then allocate memory to the length of the str argument (plus one for null) and keep the address in the passenger pointer attribute.
		 copy the content of the str Cstring into the newly allocated memory.

		 return the reference of the current object in case it is needed in the caller function.
		*/
		Seat& alAndCp(const char* str);

	public:

		//***************************************************************************
		//                            CONSTRUCTORS                                   
		//***************************************************************************
		/*
		sets the object to the safe empty state as in reset method.
			If you are using the reset method here, make sure to set the passenger pointer attribute to nullptr before calling the reset().
		*/
		Seat();

		/*
		If passengerName argument is a valid and non-empty Cstring, this constructor will allocate memory for passenger name in the passenger name pointer attribute and then copies the content of the passenger name argument into the newly allocated memory. See alAndCp() function!
			Then sets the seat row and letter to zero.
		*/
		Seat(const char* passengerName);

		/*
		Works exactly like the one argument constructor but instead of setting setting row and letter to zero, it will set them to the corresponding values after validating them. If values are not valid, it will set ONLY the row and letter to zero. see the set() method!
		*/
		Seat(const char* passengerName, int row, char letter);


		//***************************************************************************
		//                            DESTRUCTORS                                   
		//***************************************************************************
		~Seat();


		//***************************************************************************
		//                            PUBLIC MEMBER FUNCTIONS                                   
		//***************************************************************************


		/*
		This function resets the object into a safe empty state as follows:
			deallocates the passenger name
			sets passenger name to nullptr
			sets row and letter to zero
			Then it will return the reference of the current object for possible future use.
		*/
		Seat& reset();


		//This query returns if the object is in an empty state by returning true if the passenger name pointer attribute is nullptr and false otherwise.
		bool isEmpty() const;

		//This query returns true if the seats are assigned and valid by returning the validate method call result.
		bool assigned() const;

		/*The set function will validate the row and letter, if they are valid the corresponding attributes will be set to these argument values. If not, the attributes will be set to zero.

			At the end set will return the address of the current object.
		*/
		Seat& set(int row, char letter);

		//Returns the row attribute value.
		int row()const;

		//Returns the letter attribute value.
		char letter()const;

		//Returns the value of the passenger name pointer attribute.
		const char* passenger()const;

		//Receives the reference of the cout object by default and using the reference instead of cout, prints the passenger and seat information.
		std::ostream& display(std::ostream& coutRef = std::cout)const;

		// Reads data from the file and puts it in the data members after validating.
		std::istream& read(std::istream& cinRef = std::cin);
	};
}
#endif // !SDDS_SEAT_H_


