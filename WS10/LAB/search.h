/*
*****************************************************************************
						Workshop-10 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 29/11/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

namespace sdds
{
	// Template Syntax for a template with type T
	template <typename T>
	/* Function search:
	*   Return Value: boolean
	*	Number of arguments: 4
	*		1. An array of type T
	*		2. the total elements in that array
	*		3. the string to compare in the array
	*		4. A reference of an array of Collection of type T
	*	Function matches the key value with the elements of the array and puts the matches into the reference array
	*	Returns true if even one match is found, false otherwise
	*/
	bool search(T myarr[], int totalElements, const char* key, Collection<T>& result)
	{
		// Return variable
		bool returnVal = false;
		// FOR LOOP: Iterates through the array
		for (int i = 0; i < totalElements; i++)
		{
			// IF CONDITION: Looks for a match with the key in the array 
			if (myarr[i] == key)
			{
				// If found, add it to the result array and change the returnVal to true
				result.add(myarr[i]);
				returnVal = true;
			}
		}
		// Returns the returnVal
		return returnVal;
	}
}
#endif