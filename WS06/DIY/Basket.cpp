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
#define _CRT_SECURE_NO_WARNINGS

#include "Basket.h"

using namespace std;

namespace sdds
{
	void Basket::setEmpty()
	{
		// Sets the data members of the Basket class to safe empty state
		m_contents = nullptr;
		m_size = 0;
		m_price = 0;
	}

	/******************************************************
						CONSTRUCTORS
	******************************************************/
	
	// *** DEFAULT CONSTRUCTOR ***
	Basket::Basket()
	{
		// FUNCTION CALL: SetEmpty(): Sets the data members of the Basket class to safe empty state
		setEmpty();
	}

	// *** OVERLOADED CONSTRUCTOR *** 
	Basket::Basket(const Fruit* contents, int size, double price)
	{
		// IF CONDITION: If the basket is not empty (size is not 0), set the data members to the values of the supplied parameters
		if (contents != nullptr && size)
		{
			int i;
			// Sets the m_size and m_price to the supplied values as parameters
			m_size = size;
			setPrice(price);

			// Allocates new memory to the m_contents pointer of size supplied in the parameter
			m_contents = new Fruit[m_size];
			for (i = 0; i < m_size; i++)
			{
				// Copy the m_name
				strcpy(m_contents[i].m_name, contents[i].m_name);
				// Set the null terminator to the end of the name
				m_contents[i].m_name[strlen(m_contents[i].m_name) + 1] = '\0';
				// Copy the m_qty
				m_contents[i].m_qty = contents[i].m_qty;
			}
		}
		else
		{
			// IF the if condition turns false, set the current object to safe empty state
			setEmpty();
		}
	}

	// *** COPY CONSTRUCTOR ***
	Basket::Basket(const Basket& src)
	{
		// Sets the current object to the safe empty state
		setEmpty();

		// Sets the current object to the supplied object using the overloaded copy assignment operator
		*this = src;
	}

	// *** DESTRUCTOR ***
	Basket::~Basket()
	{
		// Delete the DMA of m_contents and set it to nullptr.
		delete[] m_contents;
		m_contents = nullptr;
	}

	/******************************************************
					PUBLIC MEMBER OPERATORS
	******************************************************/

	// *** COPY ASSIGNMENT OPERATOR ***
	Basket& Basket::operator=(const Basket& source)
	{
		// check for self-assignment
		if (this != &source) {

			// Deallocate the previously allocated dynamic memory: m_contents
			delete[] m_contents;
			// Set the current object to safe empty state
			setEmpty();
			// Shallow copy of the non-resource variables
			m_size = source.m_size;

			//If the supplied pointer isn't a nullptr, allocate new memory
			if (source.m_contents != nullptr) {

				// Allocate new memory to the m_contents pointer
				m_contents = new Fruit[m_size];

				// Deep copy the m_contents data from the argument to the current object
				for (int i = 0; i < m_size; i++)
				{
					// Copy the m_name
					strcpy(m_contents[i].m_name, source.m_contents[i].m_name);
					// Set the null terminator to the end of the name
					m_contents[i].m_name[strlen(m_contents[i].m_name) + 1] = '\0';
					// Copy the m_qty
					m_contents[i].m_qty = source.m_contents[i].m_qty;
				}
				// Set the price of the basket for the current object to the supplied value
				setPrice(source.m_price);
			}
		}
		// Returns the reference of the current object
		return *this;
	}

	// *** Boolean operator
	Basket::operator bool() const
	{
		// Returned variable
		bool returnVal = false;

		// IF CONDITION: If the basket is not empty, i.e., if the m_contents isn't nullptr and m_size isn't 0, set returnVal to true.
		if (m_contents != nullptr && m_size)
		{
			returnVal = true;
		}
		return returnVal;
	}

	// *** OVERLOADED += OPERATOR ***
	Basket& Basket::operator+=(Fruit add)
	{
		// IF CONDITION: Calls the overloaded bool operator to check if the current object is not empty
		if (bool(this))
		{
			// A temporary pointer of type Fruit
			Fruit* temp;
			int i;
			// DMA for the temp pointer with an increased size
			temp = new Fruit[m_size + 1];
			for (i = 0; i < m_size; i++)
			{
				// Traverses through the m_contents array and copies data into the newly allocated memory
				temp[i] = m_contents[i];
			}

			// Increment m_size by 1 to update the variable representing size of m_contents in the current object
			m_size++;

			// Adds the value passed as argument to the last index of the temporary array
			temp[m_size - 1] = add;

			// Delete the existing allocated memory for m_contents
			delete[] m_contents;

			//SETS m_contents to temp pointer: so that it points to the newly allocated memory
			m_contents = temp;
		}

		// Returns the reference of the current object
		return *this;
	}


	/******************************************************
					PUBLIC MEMBER FUNCTION
	******************************************************/
	void Basket::setPrice(double price)
	{
		// Sets the price of the basket to the value supplied in the parameter
		m_price = price;
	}
	
	/******************************************************
					FRIEND HELPER FUNCTION
	******************************************************/
	std::ostream& operator<<(std::ostream& os, Basket& list)
	{
		// IF CONDITION: Calls the overloaded bool operator to check if the current object is not empty
		if (bool(list))
		{
			int i;

			os << "Basket Content:" << endl;

			for (i = 0; i < list.m_size; i++)
			{
				// width(): sets the width of the next ostream reference to the supplied value
				os.width(10);

				// Unsetf: Sets the position settings for the ostream: like left, right or fixed.
				os.setf(ios::right);
				os << list.m_contents[i].m_name << ": ";

				// Unsetf: Unsets the position settings made by the setf function.
				os.unsetf(ios::right);

				// setf and precision: ostream functions to set the position of the display data and the number of significant digits it needs to be displayed with (here 2).
				os.setf(ios::fixed);
				os.precision(2);
				os << list.m_contents[i].m_qty << "kg" << endl;

				// Unsetf: Unsets the position settings made by the setf function.
				os.unsetf(ios::fixed);

			}
			os.setf(ios::fixed);
			os.precision(2);
			os << "Price: " << list.m_price << endl;
			os.unsetf(ios::fixed);
		}
		else
		{
			// If the IF CONDITION turns false, print the statement below.
			os << "The basket is empty!" << endl;
		}

		// Returns the reference of the ostream
		return os;
	}
}