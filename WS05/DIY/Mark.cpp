/******************************************************************************
						 Workshop-5 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 18/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
******************************************************************************/
#include "Mark.h"

using namespace std;

namespace sdds
{
	/**************************************************
					   CONSTRUCTORS
	**************************************************/
	Mark::Mark()
	{
		m_mark = 0;
		gpa = 0;
		grade = '\0';
	}
	Mark::Mark(int mark)
	{
		//IF CONDITION: Checks if mark is between 0 and 100 inclusive
		if (mark >= 0 && mark <= 100)
		{
			//IF TRUE: Sets m_mark to the mark parameter
			m_mark = mark;
			Mark::GPAGradeSetter();
		}
		else
		{		
			//IF FALSE: Sets m_mark to -1 (invalid state)
			m_mark = -1;
			gpa = -1;
			grade = '\0';
		}
	}

	/**************************************************
				TYPE CONVERSION OPERATORS
	**************************************************/
	Mark::operator int() const
	{
		int returnVal = 0;
		//IF condition: Checks if the m_mark is in the valid range 
		if (m_mark >= 0 && m_mark <= 100)
		{
			//IF yes: returns m_mark
			returnVal = m_mark;
		}
		//IF m_mark is -1, return 0
		else if(m_mark == -1)
		{
			returnVal = 0;
		}
		return returnVal;
	}

	Mark::operator double() const
	{
		return gpa;
	}

	Mark::operator char() const
	{
		return grade;
	}

	Mark::operator bool() const
	{
		//Return true or false based on if m_mark is in valid state or not: If valid, return true, else false
		return m_mark != -1;
	}

	/**************************************************
					UNARY OPERATORS
	**************************************************/
	Mark& Mark::operator++() {

		//Checks if the current object is valid
		if (*this)
		{
			//IF yes: increment m_mark by 1.
			m_mark += 1;
		}
		//IF no: do nothing!

		//returns the reference of the current object
		return *this;
	}
	Mark Mark::operator++(int) 
	{
		//Create a temporary object and set it to the current object.
		Mark m = *this;
		++(*this); // Increment the current object

		//IF CONDITION: IF m_mark is greater than 100, set m_mark to invalid state.
		if (m_mark > 100)
		{
			m_mark = -1;
		}
		
		//Return the temporary object.
		return m;
	}
	Mark& Mark::operator--()
	{
		//Checks if the current object is valid
		if (*this)
		{		
			//IF yes: increment m_mark by 1.
			m_mark -= 1;
		}
		//IF no: do nothing!
		
		//returns the reference of the current object
		return *this;
	}
	Mark Mark::operator--(int)
	{
		//Create a temporary object and set it to the current object.
		Mark m = *this;
		--(*this); // Decrement the current object.

		//IF CONDITION: IF m_mark is greater than 100, set m_mark to invalid state.
		if (m_mark > 100)
		{
			m_mark = -1;
		}

		//Return the temporary object.
		return m;
	}
	bool Mark::operator~() const
	{
		// return if m_mark is greater than or equal to 50, i.e., if the student passes or fails
		return m_mark >= 50;
	}

	/**************************************************
				BINARY MEMBER OPERATORS
	**************************************************/
	Mark& Mark::operator=(int m1)
	{
		// Sets the current object to an object created by the Overloaded constructor call
		*this = Mark(m1);

		//returns the reference of the current object
		return *this;
	}

	Mark& Mark::operator+=(int m1)
	{
		//Checks if the current object is valid
		if (*this)
		{
			//IF yes: add m1 to m_mark.
			m_mark += m1;
		}
		//IF no: do nothing!

		//returns the reference of the current object
		return *this;
	}

	Mark& Mark::operator-=(int m1)
	{
		//Checks if the current object is valid
		if (*this)
		{
			//IF yes: subtract m1 from m_mark.
			m_mark -= m1;
		}
		//IF no: do nothing!

		//returns the reference of the current object
		return *this;
	}

	Mark Mark::operator+(const Mark& m1) const
	{
		// Returns a new object created by the Overloaded Constructor call
		return Mark(m_mark + int(m1));
	}

	Mark Mark::operator+(int m1) const
	{
		// Returns a new object created by the Overloaded Constructor call
		return Mark(m_mark + m1);
	}

	Mark& Mark::operator<<(Mark& m1)
	{
		// IF Condition: Checks if the current object and the supplied object reference are not same
		if (m_mark != m1.m_mark)
		{
			//IF yes: Add m_mark from the parameter object to the current object's m_mark
			m_mark += m1.m_mark;
			//Set the source m_mark to 0.
			m1.m_mark = 0;
		}

		//Return the reference of the current object.
		return *this;
	}
	Mark& Mark::operator>>(Mark& m1)
	{
		// IF Condition: Checks if the current object and the supplied object reference are not same
		if (m_mark != m1.m_mark)
		{
			//IF yes: Add m_mark from the current object to the parameter's object m_mark
			m1.m_mark += m_mark;
			// Set the source m_mark to 0.
			m_mark = 0;
		}

		//Return the reference of the current object.
		return *this;
	}

	/**************************************************
			   COMPARISON HELPER OPERATORS
	**************************************************/
	bool operator==(const Mark& m1, const Mark& m2)
	{
		bool returnVal = false;

		//IF condition: Checks if the supplied parameter objects are in valid state
		if(bool(m1) && bool(m2))
		{
			//If yes: set the returnVal true if integer casting of m1 and m2 are equal; false otherwise.
			returnVal =  int(m1) == int(m2);
		}

		//Return the returnVal variable
		return returnVal;
	}
	bool operator!=(const Mark& m1, const Mark& m2)
	{
		bool returnVal = false;

		//IF condition: Checks if the supplied parameter objects are in valid state
		if (bool(m1) && bool(m2))
		{
			//If yes: set the returnVal true if integer casting of m1 and m2 are not equal; false otherwise.
			returnVal = int(m1) != int(m2);
		}

		//Return the returnVal variable
		return returnVal;
	}
	bool operator>=(const Mark& m1, const Mark& m2)
	{
		bool returnVal = false;

		//IF condition: Checks if the supplied parameter objects are in valid state
		if (bool(m1) && bool(m2))
		{
			//If yes: set the returnVal true if integer casting of m1 is greater than or equal to m2; false otherwise.
			returnVal = int(m1) >= int(m2);
		}

		//Return the returnVal variable
		return returnVal;
	}
	bool operator<=(const Mark& m1, const Mark& m2)
	{
		bool returnVal = false;

		//IF condition: Checks if the supplied parameter objects are in valid state
		if (bool(m1) && bool(m2))
		{
			//If yes: set the returnVal true if integer casting of m1 is less than or equal to m2; false otherwise.
			returnVal = int(m1) <= int(m2);
		}

		//Return the returnVal variable
		return returnVal;
	}
	bool operator>(const Mark& m1, const Mark& m2)
	{
		bool returnVal = false;

		//IF condition: Checks if the supplied parameter objects are in valid state
		if (bool(m1) && bool(m2))
		{
			//If yes: set the returnVal true if integer casting of m1 is greater than m2; false otherwise.
			returnVal = int(m1) > int(m2);
		}

		//Return the returnVal variable
		return returnVal;
	}
	bool operator<(const Mark& m1, const Mark& m2)
	{
		bool returnVal = false;

		//IF condition: Checks if the supplied parameter objects are in valid state
		if (bool(m1) && bool(m2))
		{
			//If yes: set the returnVal true if integer casting of m1 is less than m2; false otherwise.
			returnVal = int(m1) < int(m2);
		}

		//Return the returnVal variable
		return returnVal;
	}
	/**************************************************
				   MEMBER FUNCTION
	**************************************************/
	void Mark::GPAGradeSetter()
	{
		//IF-ELSE IF: Sets the grade and the gpa based on the conditions provided in the table.
		if (m_mark >= 0 && m_mark < 50)
		{
			grade = 'F';
			gpa = 0.0;
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			grade = 'D';
			gpa = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 'C';
			gpa = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			grade = 'B';
			gpa = 3.0;
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			grade = 'A';
			gpa = 4.0;
		}
		else if (m_mark == -1)
		{
			grade = 'X';
			gpa = 0.0;
		}
	}
	/**************************************************
				BINARY HELPER OPERATORS
	**************************************************/
	int operator+=(int& m1, const Mark& m2)
	{
		//Adds the integer cast of the supplied parameter object m2 to m1.
		m1 += int(m2);

		//Return the variable m1
		return m1;
	}

	int operator-=(int& m1, const Mark& m2)
	{
		//Subtracts the integer cast of the supplied parameter object m2 from m1.
		m1 -= int(m2);

		//Return the variable m1
		return m1;
	}	

	int operator+(int m1, const Mark& m2)
	{
		//Returns the addition of the m1 parameter and the integer cast of the object m2
		return m1 + int(m2);
	}

	
}