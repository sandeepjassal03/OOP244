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
#define _CRT_SECURE_NO_WARNINGS

#include "HtmlText.h"
using namespace std;

namespace sdds
{
	HtmlText::HtmlText() :Text()
	{
		// Calls the default constructor of Text class and sets the m_title to nullptr.
		m_title = nullptr;
	}
	HtmlText::~HtmlText()
	{
		// Deletes the DMA of m_title and sets it to nullptr.
		delete[] m_title;
		m_title = nullptr;
	}

	bool HtmlText::isEmpty() const
	{
		// returns true if either the m_title is nullptr or it is empty, false otherwise
		return !(m_title != nullptr && m_title[0] != '\0');
	}
	HtmlText::HtmlText(const char* title) :Text()
	{
		// Calls the default constructor of Text class and sets the m_title to the value supplied in the Parameter.
		if (title != nullptr && title[0] != '\0')
		{
			// DMA for copying the value into m_title
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	HtmlText::HtmlText(const HtmlText& source)
	{
		*this = source;
	}
	HtmlText& HtmlText::operator=(const HtmlText& source)
	{
		if (this != &source)
		{
			// Calls the assignment operator overload of Text class
			Text::operator=(source);

			// Sets the object to empty state by deleting the DMA of m_title
			delete[] m_title;
			m_title = nullptr;

			// If the supplied m_title isn't a nullptr
			if (source.m_title != nullptr)
			{
				// Allocate memory and set it to the supplied value
				m_title = new char[strlen(source.m_title) + 1];
				strcpy(m_title, source.m_title);
			}
		}
		
		// Returns the reference of the current object
		return *this;
	}
	std::ostream& HtmlText::write(std::ostream& ostr) const
	{
		bool MS = false;
		ostr << "<html><head><title>";

		// if the Title is not empty, insert it into the ostream, otherwise insert "No Title"
		if (!isEmpty())
		{
			ostr << m_title;
		}
		else
		{
			ostr << "No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (!isEmpty())
		{
			ostr << "<h1>" << m_title << "</h1>\n";
		}

		// For loop to replace special characters with their representations
		for (int i = 0;Text::operator[](i)!='\0'; i++)
		{
			// Switch statement for the special character: If any, change it to its respective representation, otherwise insert the character as is into the ostream
			switch (Text::operator[](i))
			{
			case ' ':
				if (MS)
				{
					ostr << "&nbsp;";
				}
				else
				{
					MS = true;
					ostr << ' ';
				}
				break;
			case '<':
				ostr << "&lt;";
				MS = false;
				break;
			case '>':
				ostr << "&gt;";
				MS = false;
				break;
			case '\n':
				ostr << "<br />\n";
				MS = false;
				break;
			default:
				MS = false;
				ostr << Text::operator[](i);
				break;
			}
		}
		ostr << "</body>\n</html>";
		return ostr;
	}
}