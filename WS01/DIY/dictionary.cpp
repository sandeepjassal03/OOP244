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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "dictionary.h"

using namespace std;

namespace sdds {

	FILE* sfptr = nullptr;
	dictionary details = {};

	// FILE FUNCTIONS: opens file for read, overwrite and closing it.
	bool openFileForRead(const char* file) {
		sfptr = fopen(file, "r");
		return sfptr != NULL;
	}

	bool openFileForOverwrite(const char* file) {
		sfptr = fopen(file, "w");
		return sfptr != NULL;
	}

	void closeFile() {
		if (sfptr) fclose(sfptr);
	}


	int LoadDictionary(const char* filename)
	{
		// Check variable if file is opened successfully
		int success = 0;

		if (openFileForRead(filename))
		{
			ReadAndLoadFile(&details);
			closeFile();
			success = 0;
		}
		else
		{
			success = 1;
			details = {'\0'};
		}
		return success;
	}

	bool ReadAndLoadFile(dictionary* sysDictionary)
	{
		int scanfReturn = 0, count, i;
		
		bool success;
		bool loadedDefinitions = false;
		bool exitLoop = false;

		char pointerChar;
		char bufferNameString[MAX_WORD_LENGTH + 1] = { '\0' };
		char bufferDefintionString[MAX_DEFINITION_LENGTH + 1] = { '\0' };

		if (sfptr != NULL)
		{
			success = true;
			
			for (count = 0; count < MAX_WORDS && !exitLoop; count++)
			{
				// Gets one file from the filestream and supplies it to bufferNameString
				fgets(bufferNameString, MAX_WORD_LENGTH, sfptr);

				// Scans the line supplied for required data.				
				scanfReturn = sscanf(bufferNameString, "%[^\n]", sysDictionary->collection[count].name);
				sysDictionary->collection[count].totalDefinitions = 0;
				if (scanfReturn == 1)
				{
					sysDictionary->wordNumber++;
					loadedDefinitions = false;
					for (i = 0; i < MAX_DEFINITIONS && !loadedDefinitions; i++)
					{
						// Gets the next line accordingly and sets it into the respective variables.
						fgets(bufferDefintionString, MAX_DEFINITION_LENGTH, sfptr);
						sscanf(bufferDefintionString, "\t%[^:]: %[^\n]\n", sysDictionary->collection[count].list[i].definitionType, sysDictionary->collection[count].list[i].meaning);

						sysDictionary->collection[count].totalDefinitions++;

						pointerChar = fgetc(sfptr);
						if (pointerChar == '\n')
						{
							// If a new word is to begin, a newline separates the two words and this checks for us when to move for the next word.
							loadedDefinitions = true;
						}
						else if (pointerChar == EOF)
						{
							// If the file has ended, set the conditions to exit the loops and complete loading.
							loadedDefinitions = true;
							exitLoop = true;
						}
					}
				}

			}
		}
		else
		{
			// If not loaded, returns false.
			success = false;
		}
		return success;	
	}

	void SaveDictionary(const char* filename)
	{
		if (openFileForOverwrite(filename))
		{
			// Opens file for writing (a new file) and enter data into it.
			createNewDictionary(&details);
			closeFile();
		}
	}
	void createNewDictionary(dictionary* sysDictionary)
	{
		int i,j;
		for (i = 0; i < sysDictionary->wordNumber; i++)
		{
			// fprintf takes the input from the storage directed and prints it to the file using the stream.
			fprintf(sfptr, "%s\n", sysDictionary->collection[i].name);

			for (j = 0; j < sysDictionary->collection[i].totalDefinitions ; j++)
			{
				fprintf(sfptr, "\t%s: %s\n", sysDictionary->collection[i].list[j].definitionType, sysDictionary->collection[i].list[j].meaning );
		
			}
			fprintf(sfptr, "\n");
		}
	}
}