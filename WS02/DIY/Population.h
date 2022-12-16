/*
*****************************************************************************
						Workshop-2 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 23/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#include <iostream>
#include <cstring>

#include "File.h"

namespace sdds {

	//CONSTANT VARIABLES
	const int MAX_LENGTH = 3;

	//STRUCTURE DEFINITION
	struct populationData
	{
		char* postalCode;
		int* population;
	};


	// if loading of the population records into the dynamic memroy is successful
	//Loads data from a file, and returns true if data was successfully loaded, false otherwise.This function receives as a parameter the name of the file
	//If the file cannot be found, print the following error message :
		//Could not open data file : FILENAME<ENDL>
	//If the file doesn't have a correct content, print:
		//Error : incorrect number of records read; the data is possibly corrupted!<ENDL>
	bool load(const char filename[]);

	//a function with no parameters that return nothing and prints the report as shown in DIY Execution example.
	void display();

	//a function with no parameters that return nothing and deallocate all dynamic memory used by the program.
	// in any case delete the dynamic memory if it is allocated
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_