/*
*****************************************************************************
						Workshop-2 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 21/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

namespace sdds
{
	bool read(int& value, FILE* fptr)
	{
		return (fscanf(fptr, "%d\n", &value)==1); // Scans an integer from the fptr stream and puts into the value variable
	}

	bool read(double& value, FILE* fptr)
	{
		return (fscanf(fptr, "%lf\n", &value)==1); // Scans a double from the fptr stream and puts into the value variable
	}

	bool read(char* cstr, FILE* fptr)
	{
		return (fscanf(fptr, ",%60[^\n]\n", cstr)==1); // Scans a string from the fptr stream and puts into the cstr string
	}
	
	bool read(Assessment& asmnt, FILE* fptr)
	{
		// Temporart Variable Declarations
		double tempDouble;
		char tempCString[MAX_LENGTH + 1] = {'\0'};

		//Function Return value variable
		bool success;

		// Read functions return value to this variable
		int returnValue = 0;

		// Read functions to read the Marks and the Course title from the file stream. Value is added to the returnValue variable
		returnValue = int(read(tempDouble, fptr));
		returnValue += int(read(tempCString, fptr));
		
		if (returnValue==2)
		{
			// Dynamically allocated memory to the structure variables using new keyword
			asmnt.m_mark = new double;
			asmnt.m_title = new char[strlen(tempCString) + 1];

			// Copying data from the temporary variables into the structure array variables at the parameter received
			*asmnt.m_mark = tempDouble;
			strcpy(asmnt.m_title, tempCString);

			success = true;
		}
		else
		{
			success = false;
		}
		return success;
	}

	void freeMem(Assessment*& aptr, int size)
	{
		// Loop to iterate through the array of the structure to deallocate every memory space allocated for the structure variables.
		for (int i = 0; i < size; i++)
		{
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}
		delete[] aptr; // Deallocation of the array
	}

	int read(Assessment*& aptr, FILE* fptr)
	{
		// Variable declarations
		int totalRecords, i;
		bool returnValue = true;
		bool success;
		int count = 0;

		// Reads the first integer telling the totalRecords in that file
 		success = read(totalRecords, fptr);

		// If condition: If the above read is successful, execute the block of statements
		if (success)
		{
			// Dynmanically Allocate memory for the array of structure using its pointer 
			aptr = new Assessment[totalRecords];
			
			for (i = 0; i < totalRecords && returnValue; i++)
			{
				// Function Call: Reads the data from the file stream and puts into the arguments passed as per the data.
				returnValue = read(aptr[i], fptr);
				if (returnValue)
				{
					//If condition: If the read is successful, increment count by 1 for further use.
					count++;
				}
			}
		}
		
		// IF condition: Check if the number of fields read is equal to the totalRecords or not:
		// If they are not equal: Free the memory allocated and return zero.
		if (count != totalRecords)
		{
			freeMem(aptr, count);  
			return 0;
		}
		else
		{
			// Else return the number of fields read so as to deallocate memory accordingly in the freeMem function call in main
			return count;
		}
	}
}