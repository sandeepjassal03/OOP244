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
#include "word.h"
#include "extern.h"

using namespace std;

namespace sdds
{
	void DisplayWord(const char* word)
	{
		int i, j;
		bool foundWord = false;
		for (i = 0; i < details.wordNumber && !foundWord; i++)
		{
			// CHECKS if the word supplied matches any word in the existing dictionary
			if (!strcmp(word, details.collection[i].name))
			{
				cout << "FOUND: [" << word << "] has [" << details.collection[i].totalDefinitions << "] definitions:" << endl;
				foundWord = true;
				for (j = 0; j < details.collection[i].totalDefinitions; j++)
				{
					//Prints the description of the word supplied 
					cout << j + 1 << ". {" << details.collection[i].list[j].definitionType << "} " << details.collection[i].list[j].meaning << endl;
				}
			}
		}
		if (!foundWord)
		{
			//NOT FOUND: executed if the word did not exist in the dictionary.
			cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
		}
	}
	void AddWord(const char* word, const char* type, const char* definition)
	{
		int newWordIndex, i;
		bool wordExists = false;
		int totalDef;

		// Set the index for the new word to be added to the last updated wordNumber which is actually the number of words in the dictionary.
		newWordIndex = details.wordNumber ;

		for (i = 0; i < details.wordNumber && !wordExists; i++)
		{
			//IF word already exists, add the new definitions.
			if (!strcmp(word, details.collection[i].name))
			{
				// to decrease complexity in a line, I created totalDef variable which actually represents the totalDefinitions of that word.
				totalDef = details.collection[i].totalDefinitions;
				//Copy the data supplied to their respective positions
				strcpy(details.collection[i].list[totalDef].definitionType, type);
				strcpy(details.collection[i].list[totalDef].meaning, definition);
				details.collection[i].totalDefinitions++;
				wordExists = true;
			}
		}
		if (!wordExists)
		{
			// If the word does not exist, add a new word to the dictionary.
			strcpy(details.collection[newWordIndex].name, word);
			strcpy(details.collection[newWordIndex].list[0].definitionType, type);
			strcpy(details.collection[newWordIndex].list[0].meaning, definition);

			// Increments the word count by 1
			details.wordNumber++;
			// Increments the totalDefinitions by 1
			details.collection[newWordIndex].totalDefinitions++;
		}
	}
	int UpdateDefinition(const char* word, const char* type, const char* definition)
	{
		int i, j, input;
		bool wordExists = false;

		for (i = 0; i < details.wordNumber && !wordExists; i++)
		{
			// Searches for the matching word in the dictionary
			if (!strcmp(word, details.collection[i].name))
			{
				// If the word has multiple definitions
				if (details.collection[i].totalDefinitions > 1)
				{
					cout << "The word [" << word << "] has multiple definitions:" << endl;
					for (j = 0; j < details.collection[i].totalDefinitions; j++)
					{
						cout << j + 1 << ". {" << details.collection[i].list[j].definitionType << "} " << details.collection[i].list[j].meaning << endl;
					}
					cout << "Which one to update? ";
					cin >> input;

					strcpy(details.collection[i].list[input-1].definitionType, type);
					strcpy(details.collection[i].list[input-1].meaning, definition);
				}
				else
				{
					// If the word has a single definition only.
					cout << "The word [" << word << "] has one definition:" << endl;
					cout << "1. {" << details.collection[i].list[0].definitionType << "} " << details.collection[i].list[0].meaning << endl;
					strcpy(details.collection[i].list[0].definitionType, type);
					strcpy(details.collection[i].list[0].meaning, definition);
				}
			}
		}
		return 0;
	}
}