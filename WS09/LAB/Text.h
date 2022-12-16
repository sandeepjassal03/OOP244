/*
*****************************************************************************
						Workshop-9 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 23/11/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_

#include "Utils.h"
#include <cstring>
namespace sdds
{
	class Text
	{
		char* m_content = nullptr;
		void setEmpty();
	protected:
		const char& operator[](int index) const;
	public:
		Text();
		~Text();
		Text(const Text& source);
		Text& operator=(const Text& source);
		std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;

	};
	std::istream& operator>>(std::istream& istr, Text& source);
	std::ostream& operator<<(std::ostream& ostr, const Text& source);
}
#endif // !SDDS_TEXT_H_
