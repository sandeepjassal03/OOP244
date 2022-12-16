/*
*****************************************************************************
						    Workshop-5 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 13/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
	class Apartment
	{
		int m_number = -1;
		double m_balance = 0.0;

	public:
		Apartment(int number, double balance);
		std::ostream& display()const;

		//***************************************************************
		//                TYPE CONVERSION OPERATORS
		//***************************************************************

		//This operator returns true if the apartment object is valid; otherwise, it will return false. This operator cannot modify the apartment object.
		operator bool() const;

		//returns the apartment number. This operator cannot modify the apartment object.
		operator int() const;

		//returns the rent balance value. This operator cannot modify the apartment object.
		operator double() const;

		//***************************************************************
		//                   UNARY MEMBER OPERATOR
		//***************************************************************
		//returns true if the apartment balance is zero; otherwise, it returns false. This operator cannot modify the apartment object.
		bool operator ~() const;

		//***************************************************************
		//                   BINARY MEMBER OPERATORS
		//***************************************************************

		/*
		overload the assignment operator so an apartment can be set to an integer. Doing so should set the apartment number of the apartment to the integer value.
		If the integer value is an invalid apartment number, the object should be set to an invalid empty state instead.
		In any case, a reference of the current object (apartment) should be returned.
		*/
		Apartment& operator=(int value);

		/*
			overload the assignment operator so an apartment can be set to another apartment object. This action should swap the rent balance and the apartment number of one apartment to another.Therefore, unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the rent balance and the number of the left apartment will be swapped with the balance and the number of the right apartment
			In any case, a reference of the current object (apartment) should be returned.
		*/
		Apartment& operator=(Apartment& a2);

		/*
		overload the += operator to add a double value to an apartment. This should act like adding to the balance of the rent of an apartment. (i.e., the value of the double should be added to the rent balance)
		if the apartment is invalid or the double value is negative, no action should be taken.
		In any case, a reference of the current object (apartment) should be returned.
		*/
		Apartment& operator+=(double value);

		/*
		overload the -= operator to reduce an apartment rent balance by a double value. This should act like decreasing the rent balance of an apartment account. (i.e., the value of the balance should be reduced by the double value)
		if the apartment is in an invalid state, the double value is negative, or there is not enough money in the apartment account - no action should be taken.
I		In any case, a reference of the current object (apartment) should be returned.
		*/
		Apartment& operator-=(double value);

		/*
		overload the << operator (left shift operator) to move the balance from the right apartment to the left apartment. After this operation, the balance of the left apartme account will be the sum of both the left and right apartment, and the balance of the right apartment account will be zero. The balance of an apartment should not be able to be "moved" to itself and this operation will not affect the account in this situation.
		In any case, a reference of the current object (apartment) should be returned.
		*/
		Apartment& operator<<(Apartment& a2);
		
		/*
		overload the >> operator (right shift operator) to move the balance from the left apartment to the right apartment. After this operation, the balance of the right apartment account will be the sum of both the right and left apartment and the balance of the left apartment account will be zero.
			Funds of an Apartment should not be able to be moved to itself and this operation does not affect the Apartment.
		In any case, a reference of the current object (Apartment) should be returned.
		*/
		Apartment& operator>>(Apartment& a2);


	};

	/*
		create a binary stand-alone helper + operator that accepts a constant apartment reference on the left and another constant apartment reference on the right that returns a double value.
		The double value should be the sum of the balances of the two apartments accounts.
		If any of the two apartments is invalid, then zero is returned.
	*/
	double operator+(const Apartment& a1, const Apartment& a2);

	/*
		create a binary stand-alone helper += operator that accepts a double reference on the left and a constant apartment reference on the right that returns a double value.
	The value of the rent balance of the right operand (apartment reference) should be added to the left operand and then the sum will be returned.
	*/
	double operator+=(double& value, const Apartment& a1);
}

#endif // SDDS_APARTMENT_H_