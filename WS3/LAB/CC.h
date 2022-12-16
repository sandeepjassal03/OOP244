/*
*****************************************************************************
						Workshop-3 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 26/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CC_H_
#define SDDS_CC_H_

#include "Utils.h"

namespace sdds
{
	class CC
	{
//***********************************************************************************
//                          MEMBER VARIABLES
//***********************************************************************************
		char* u_name;
		short u_cvv;
		short u_expiryMonth;
		short u_expiryYear;
		unsigned long long u_cardNumber;

//***********************************************************************************
//                         PRIVATE MEMBER FUNCTIONS
//***********************************************************************************
		/*
		This function validates the credit card information as follows:
		name: should not be null and should be more than 2 characters long.
		carNo: values between 4000000000000000 and 4099999999999999.
		cvv: a three-digit number.
		expMon: values between 1 and 12.
		expYear: values between 22 and 32.
		it will return true if all the conditions are met, otherwise it will return false.
		This function does not modify the object.
		*/
		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;

		// This function prints a 16-digit number in a set of 4-digit numbers separated by spaces.
		void prnNumber()const;
	

//***********************************************************************************
//                        PUBLIC MEMBER FUNCTIONS
//***********************************************************************************
	public:
		// Sets the object to a safe empty state by setting all the values to zero and nullptr.
		void set();

		// First, it will deallocate the cardholder's name and then calls the set() to set the object to a safe empty state.
		void cleanUp();

		// Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute of the object is nullptr, otherwise, it will return false.
		bool isEmpty() const;

		// First, it will cleanUp() the object. Then if all the arguments are valid using validate(), it will dynamically keep a copy of the name in the name attribute and set the rest of the attributes to their corresponding values.
		// If any of the arguments are invalid, nothing will be set.
		void set(const char* cc_name,
			unsigned long long cc_no,
			short cvv,
			short expMon,
			short expYear); 

		//	Assuming that the names are not longer than 70 characters, this function will attempt to read all the values from the console in local (function scope) variables first and if successful, they will be validated and then stored in the object.
		// The function will return true if the values are stored in the object and false otherwise.
		bool read();

		// If the object isEmpty(), print "Invalid Credit Card Record";
		//If it is not in a safe empty state, depending on the value of the row being greater than zero or not, print the CC information in a row, or in a form format respectively :
		void display(int row = 0) const;

	};
}


#endif
