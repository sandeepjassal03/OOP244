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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Utils.h"
#include "extern.h"

namespace sdds
{

	void allocateMemory(int size)
	{
		//Dynamically allocating memory to create an array of the structure
		report = new populationData[size];
	}

	void allocateMemory(int& population, char* postalCode, int i)
	{
		// Dynamic Memory allocation using new keyword
		report[i].population = new int;
		report[i].postalCode = new char[strlen(postalCode) + 1];

		//Copying data from the parameters into the respective variables
		*report[i].population = population;
		strcpy(report[i].postalCode, postalCode);
	}

	void sortData()
	{
		populationData* tempData = new populationData;

		int i;
		bool swapData = false;
		bool sort;

		while (!swapData)
		{
			sort = false;
			// Iterating Loop: Iterates through the array for the totalRecord times.
			for (i = 0; i < totalRecords - 1; i++)
			{
				// Iterating Loop: Iterates through the array for the totalRecord times.
				if (*report[i].population > *report[i + 1].population)//checking condition if we need to swap or not
				{
					*tempData = report[i];
					report[i] = report[i + 1];
					report[i + 1] = *tempData;
					sort = true;
				}
			}
			if (!sort)
			{
				swapData = true;
			}
		}
		delete tempData;
		tempData = nullptr;
	}

	int calculateTotalPopulation()
	{
		int i;
		int totalPopulation = 0;

		// Iterating Loop: Iterates through the array for the totalRecord times and adds on the population to the totalPopulation variable
		for (i = 0; i < totalRecords; i++)
		{
			totalPopulation += *report[i].population;
		}

		return totalPopulation;
	}
}