/*
*****************************************************************************
						Workshop-6 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 31/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_

#include <iostream>
#include <cstring>

namespace sdds
{
	/******************************************************
				     STRUCTURE DEFINITION
	 ******************************************************/
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket
	{
		/******************************************************
						   DATA MEMBERS
		******************************************************/
		Fruit* m_contents;
		int m_size;
		double m_price;

		// *** PRIVATE MEMBER FUNCTION ***
		void setEmpty();

	public:

		/******************************************************
							CONSTRUCTORS
		******************************************************/
		Basket();
		Basket(const Fruit* contents, int size, double price);
		Basket(const Basket& src);

		// *** DESTRUCTOR ***
		~Basket();

		/******************************************************
						PUBLIC MEMBER OPERATORS
		******************************************************/
		Basket& operator=(const Basket& source);
		operator bool() const;
		Basket& operator+=(Fruit add);

		/******************************************************
						PUBLIC MEMBER FUNCTION
		******************************************************/
		void setPrice(double price);

		/******************************************************
						FRIEND HELPER FUNCTION
		******************************************************/
		friend std::ostream& operator<<(std::ostream& os, Basket& list);
	};
}
#endif