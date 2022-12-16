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

#include "Population.h"
#include "Utils.h"

using namespace std;

namespace sdds {

    // Variables and Structure Object declaration
    int totalRecords = 0;
    populationData* report = nullptr;

    // Load Function Definition
    bool load(const char filename[])
    {
        int i = 0;
        bool success = false;
        
        //openFile: file function to open file with filename passed as parameter
        if (openFile(filename))
        {
            // Temporary variables
            int tempInt = 0;
            char tempCString[3 + 1] = { '\0' };
            
            // noOfRecords: Calculates the totalRecords in the file and returns them into totalRecords variable
            totalRecords = noOfRecords();

            // allocateMemory: Allocates the memory for the array of type structure
            allocateMemory(totalRecords);

            // Iterating Loop: Iterates through the array for the totalRecord times and executes the statements listed
            for (i = 0; i < totalRecords; i++)
            {
                //read: Functions to use the file stream to read a record and returns it to the parameter variables passed
                read(tempCString, fptr);
                read(tempInt, fptr);

                // allocateMemory: Allocates the memory for the members of the array at an index
                allocateMemory(tempInt, tempCString, i);

            }
            success = true;

            //sortData: Sorts the data in the ascending order of the population 
            sortData();

            //closeFile: File function to close the file
            closeFile();
        }

        // If file stream fptr is still nullptr, print an error message
        else if(fptr == nullptr)
        {
            cout << "Could not open data file: " << filename << endl;
        }

        //IF: checks if the totalRecords matches the i  variable, if no, print the error message
        if (i != totalRecords)
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
        }

        return success;
    }

    
    void display()
    {
        int i;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        // Iterating Loop: Iterates through the array for the totalRecord times and prints the data in the structured way.
        for (i = 0; i < totalRecords; i++)
        {
            cout << i + 1 << "- " << report[i].postalCode << ":  " << *report[i].population << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << calculateTotalPopulation() <<  endl;
    }
   
    // in any case delete the dynamic memory if it is allocated
    void deallocateMemory()
    {
        // Iterating Loop: Iterates through the array for the totalRecord times and deletes memory for each variable.
        for (int i = 0; i < totalRecords; i++)
        {
            delete report[i].population;
            delete[] report[i].postalCode;
        }

        // Deletes the array of the type structure
        delete[] report;
    }
}