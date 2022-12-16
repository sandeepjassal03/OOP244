/*
*****************************************************************************
						Workshop-1 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 18/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

//SAFEGUARDS
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include "word.h"

namespace sdds
{
	// Constant variables
	const int MAX_WORDS = 100;

	//STRUCTURE
	struct dictionary
	{
		int wordNumber;
		word collection[MAX_WORDS];
	};


	//FILE FUNCTIONS
	bool openFileForRead(const char* file);
	bool openFileForOverwrite(const char* file);
	void closeFile();

	// To decrease complexity of LoadDictionary function, I created another function that actually scans data from the file and puts it in the right place.	
	bool ReadAndLoadFile(dictionary* sysDictionary);
	
	/// <summary>
	/// Load from a file a set of words with their definition.  Any previous
	///   existing dictionary is discarded, regardless of the result of the load.
	/// </summary>
	/// <param name="filename">The name of the file containing the dictionary.</param>
	/// <returns>0 if data has been loaded from the file, non-zero otherwise
	///   (null parameter, empty parameter, missing file).</returns>
	int LoadDictionary(const char* filename);

	/// <summary>
	/// Save all the words existing in the dictionary into a file.  The functions
	///   "LoadDictionary" should be able to load from this after the save finished.
	/// </summary>
	/// <param name="filename">The name of the file where to save.</param>
	void SaveDictionary(const char* filename);

	// This function is supposed to be called in the SaveDictionary function and creates a new updated dictionary which is saved into a new file.
	void createNewDictionary(dictionary* sysDictionary);
}
#endif