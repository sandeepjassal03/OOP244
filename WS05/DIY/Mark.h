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
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>
namespace sdds
{
	class Mark
	{
		int m_mark;
		int gpa;
		char grade;
	public:
		/**************************************************
				           CONSTRUCTORS
		**************************************************/
		Mark();
		Mark(int mark);

		/**************************************************
				    TYPE CONVERSION OPERATORS
		**************************************************/
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;

		/**************************************************
						UNARY OPERATORS
		**************************************************/
		Mark& operator++();
		Mark operator++(int);

		Mark& operator--();
		Mark operator--(int);

		bool operator~() const;

		/**************************************************
				    BINARY MEMBER OPERATORS
		**************************************************/
		Mark& operator=(int m1);

		Mark& operator+=(int m1);
		Mark& operator-=(int m1);


		Mark operator+(const Mark& m1) const;
		Mark operator+(int m1) const;

		Mark& operator>>(Mark& m1);
		Mark& operator<<(Mark& m1);

		//Sets the grade and the gpa
		void GPAGradeSetter();
	};

	/**************************************************
		       COMPARISON HELPER OPERATORS
	**************************************************/
	bool operator==(const Mark& m1, const Mark& m2);
	bool operator!=(const Mark& m1, const Mark& m2);
	bool operator>=(const Mark& m1, const Mark& m2);
	bool operator<=(const Mark& m1, const Mark& m2);
	bool operator>(const Mark& m1, const Mark& m2);
	bool operator<(const Mark& m1, const Mark& m2);
	
	/**************************************************
		        BINARY HELPER OPERATORS
	**************************************************/
	int operator+=(int& m1, const Mark& m2);
	int operator-=(int& m1, const Mark& m2);

	int operator+(int m1, const Mark& m2);
}
#endif