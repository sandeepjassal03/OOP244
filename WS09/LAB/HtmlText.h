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
#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_

#include <iostream>
#include "Text.h"
namespace sdds
{
	class HtmlText: public Text
	{
		char* m_title = nullptr;
		bool isEmpty() const;
	public:
		HtmlText();
		~HtmlText();
		HtmlText(const char* title);
		HtmlText(const HtmlText& source);
		HtmlText& operator=(const HtmlText& source);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;

	};
}
#endif // !SDDS_HTMLTEXT_H_
