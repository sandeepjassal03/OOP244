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
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include "extern.h"

namespace sdds
{
    // Allocates an array of type structure populationData with a parameter of size
    void allocateMemory(int size);

    // Allocates memory to elements of the array and copies them to the array fields
    //Parameters: population, postalCode and the index at which data is to be stored
    void allocateMemory(int& population, char* postalCode, int index);

    // Sorts the data in the ascending order of the population 
    void sortData();

    // Takes the data in the array and accumulates it to calculate total population
    int calculateTotalPopulation();
}

#endif