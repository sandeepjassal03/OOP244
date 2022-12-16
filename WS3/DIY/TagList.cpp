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
#include <iostream>
#include "TagList.h"

using namespace std;
namespace sdds
{
	int count = 0;

	void TagList::set()
	{
		// Sets the data members of the class TagList to empty state, as nullptr or 0 where ever suitable.
		NameCollection = nullptr;
		totalTags = 0;
		longestTagLength = 0;
	}


	void TagList::set(int num)
	{
		// FUNCTION CALL cleanup(): Cleans any previously existing memory before dynamic allocation.
		cleanup();

		// Dynamic allocation of the NameCollection array using new keyword.
		NameCollection = new NameTag[num];
		totalTags = num;
	}


	void TagList::add(const NameTag& nt)
	{
		int temp = 0;

		// IF condition: If the count is less than the total names in the file, execute the statements
		if (count < totalTags)
		{
			NameCollection[count] = nt; // Setting nt to the NameCollection at the index count.
		}

		temp = strlen(NameCollection[count].returnString()); // Setting temp equal to the length of the name string

		if (temp > longestTagLength)
		{
			// IF condition: If the temp is greater than longestTagLength, set longestTagLength equal to length.
			longestTagLength = temp; 
		}
		count++;
	}

	void TagList::print()
	{
		int i, frame;

		//FOR Loop: Iterates through the NameCollection array.
		for (i = 0; i < totalTags; i++)
		{
			// FOR loop: Increments for longestTagLength + FRAME_SPACE time: 
			// longestTagLength for the number of stars to be printed to create a frame that equals the length of the longest name.
			// FRAME_SPACE for the the 2 stars and 2 spaces before the beginning and ending of any name.
			for (frame = 0; frame < longestTagLength + FRAME_SPACE; frame++)
			{
				cout << "*";
			}

			cout << endl << "* ";
			cout.width(longestTagLength); // Sets width of the cout to the longestTagLength.
			cout.fill(' '); // FILL: Fills the null spaces in the cout with the character passed.
			cout.setf(ios::left); // setf(): Sets the justification of the cout as left (here).
			cout << NameCollection[i].returnString(); // Prints the name stored at that index.
			cout.unsetf(ios::left); // unsetf(): Unsets the justification of the cout as left (here).
			cout << " *" << endl;

			for (frame = 0; frame < longestTagLength + FRAME_SPACE; frame++)
			{
				cout << "*";
			}
			cout << endl;
		}

	}


	void TagList::cleanup()
	{
		// Deallocation of the dynamically allocated memory space using delete keyword.
		delete[] NameCollection;
	}
}