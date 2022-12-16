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

// SAFEGUARDS

#ifndef SDDS_EXTERN_H
#define SDDS_EXTERN_H
#include "dictionary.h"

// I created this file so that we can access any modified structure that we change in any implementation file across all the modules and files. This basically extends the object details to every file in the project.
namespace sdds
{
	extern dictionary details;
}

#endif
