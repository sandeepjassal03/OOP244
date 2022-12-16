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
*/#define _CRT_SECURE_NO_WARNINGS

#include "Text.h"
using namespace std;

namespace sdds
{
	void Text::setEmpty()
	{
		// Deletes m_content and sets it to nullptr
		delete[] m_content;
		m_content = nullptr;
	}

	Text::Text()
	{
		m_content = nullptr;
	}
	Text::~Text()
	{
		setEmpty();
	}
	Text::Text(const Text& source)
	{
		*this = source;
	}
	const char& Text::operator[](int index) const
	{
		// Returns m_content at the specified index
		return m_content[index];
	}
	Text& Text::operator=(const Text& source)
	{
		if (this != &source)
		{
			// Sets the object to empty state
			setEmpty();
			// If the supplied m_content isn't a nullptr
			if (source.m_content != nullptr)
			{
				// Allocate memory and set it to the supplied value
				m_content = new char[strlen(source.m_content) + 1];
				strcpy(m_content, source.m_content);
			}
		}

		// Return the reference of the current object
		return *this;
	}
	std::istream& Text::read(std::istream& istr)
	{
		// Sets the object to empty state
		setEmpty();
		int i = 0;
		bool flag = false;

		// Sets size equal to the file size
		int size = getFileLength(istr);

		// Allocates memory to the m_content
		m_content = new char[size + 1];
		for (i = 0; i < size && !flag; i++)
		{
			char ch = 0;

			// Get the character and put it into ch
			istr.get(ch);
			if (ch != '\0')
			{
				// If the character is not a null terminator, set it to m_content at that index and clear istr
				m_content[i] = ch;
				istr.clear();
			}
			else
			{
				// Otherwise, set flag to true to exit loop
				flag = true;
			}
		}
		// End the string with the null terminator
		m_content[i] = 0;
		return istr;
	}
	std::ostream& Text::write(std::ostream& ostr) const 
	{
		// If the m_content is not nullptr, insert it into ostream
		if (m_content != nullptr)
		{
			ostr << m_content;
		}
		//Return the reference of the ostream
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Text& source) 
	{
		// Calls the read operator of the Text class
		source.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Text& source) 
	{
		// Calls the write operator of the Text class
		source.write(ostr);
		return ostr;
	}
}
