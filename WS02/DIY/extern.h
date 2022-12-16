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
#ifndef SDDS_EXTERN_H_
#define SDDS_EXTERN_H_

#include "Population.h"

namespace sdds
{
	// I created this file so that we can access any modified structure that we change in any implementation file across all the modules and files. This basically extends the variable details to every file in the project. This also extends the file stream and the totalRecords variable
	extern FILE* fptr;
	extern populationData* report;
	extern int totalRecords;
}

#endif 