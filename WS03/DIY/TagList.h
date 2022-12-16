/*
*****************************************************************************
						Workshop-3 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 29/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "NameTag.h"

namespace sdds
{
	class TagList
	{
		// Class DATA MEMBERS

		NameTag* NameCollection; // Pointer definition of an object of class NameTag.
		int totalTags;
		int longestTagLength;

	public:
		// Sets the TagList to an empty state
		void set();

		// Calls CleanUp() and then dynamically creates an array of num NameTags.
		void set(int num);

		// Adds up to num (of the set method) NameTags to the TagList.
		void add(const NameTag& nt);

		// Prints all the tags with the same size that is the frame size of the longest name in the list.
		void print();

		// Deallocates the NameTags and put the TagList back to a safe empty state.
		void cleanup();

	};
}