/*
*****************************************************************************
						MILESTONE 1

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 05/11/2022

Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/05  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
using namespace std;

namespace sdds
{
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					 MENU ITEM
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


	/******************************************
				  CONSTRUCTORS
	******************************************/

	// *** DEFAULT CONSTRUCTOR ***
	MenuItem::MenuItem()
	{
		// FUNCTION CALL: Calls setEmpty() to set the object to the empty state
		setEmpty();
	}

	// *** OVERLOADED CONSTRUCTOR ***
	MenuItem::MenuItem(const char* item)
	{
		// IF CONDITION: Checks if the string passed is not a nullptr, set the current object's string to the value passed, otherwise setEmpty()
		if (item != nullptr)
		{
			strncpy(m_item, item, MAX_LENGTH);
		}
		else
		{
			setEmpty();
		}
	}

	/******************************************
			PRIVATE MEMBER FUNCTIONS
	******************************************/

	void MenuItem::setEmpty()
	{
		//Sets the string in the current object to the null terminator
		strcpy(m_item, "\0");
	}

	bool MenuItem::isEmpty() const
	{
		// Return variable
		bool returnVal = false;

		// IF CONDITION: Checks if the m_item is null, if yes, set the returnVal to true, false otherwise
		if (m_item[0] == '\0')
		{
			returnVal = true;
		}
		return returnVal;
	}
	void MenuItem::display() const
	{
		// FUNCTION CALL: Calls isEmpty() to check if the current object is in empty state or not
		if (!isEmpty())
		{
			// If the current object is not empty, print the m_item string
			cout << m_item << endl;
		}
	}


	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					  MENU
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

	/******************************************
				  CONSTRUCTORS
	******************************************/

	// *** DEFAULT CONSTRUCTOR ***
	Menu::Menu()
	{
		// FUNCTION CALL: Calls setEmpty() to set the object to the empty state
		clear();
	}

	// *** OVERLOADED CONSTRUCTOR ***
	Menu::Menu(const char* title, int intendVal)
	{
		// IF CONDITION: Checks if the title is not a nullptr, set the values as described, otherwise set it to an empty state.
		if (title)
		{
			strncpy(m_title, title, MAX_LENGTH);
			m_size = 0;
			m_intendVal = intendVal;
			m_list->setEmpty();
		}
		else
		{
			clear();
		}
	}

	Menu::operator bool() const
	{
		// Return variable
		bool returnVal = false;

		// IF CONDITION: Checks if the m_item is null, if yes, set the returnVal to true, false otherwise
		if (m_title[0] != '\0')
		{
			returnVal = true;
		}
		return returnVal;
	}
	bool Menu::isEmpty() const
	{
		// Return variable
		bool returnVal = false;

		// IF CONDITION: Checks if the current object is empty, if yes, set the returnVal to true, false otherwise
		if (!*this)
		{
			returnVal = true;
		}
		return returnVal;
	}
	void Menu::display() const
	{
		// IF CONDITION: Checks if the current object is empty, if yes, print the statement
		if (isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		// IF CONDITION: Checks if the m_title is not null and m_size is not 0
		else if (m_title && !m_size)
		{
			// If yes, print the title and the statement
			cout << m_title << endl;
			cout << "No Items to display!" << endl;
		}
		// If none of the above condition is true, it means menu is valid and usable and will be printed as this:
		else
		{
			// FUNCTION CALL: Calls intendMenu() to intend 4 spaces for every 1 value of intend value supplied while construction
			intendMenu(m_intendVal);
			cout << m_title << endl;

			for (int i = 0; i < m_size; i++)
			{
				// FUNCTION CALL: Calls intendMenu() to intend 4 spaces for every 1 value of intend value supplied while construction
				intendMenu(m_intendVal);
				cout << i + 1 << "- ";
				m_list[i].display();
			}
			// FUNCTION CALL: Calls intendMenu() to intend 4 spaces for every 1 value of intend value supplied while construction
			intendMenu(m_intendVal);
			cout << "> ";
		}
	}
	Menu& Menu::operator=(const char* string)
	{
		// IF CONDITION: Checks if the string passed is not nullptr
		if (string != nullptr)
		{
			// If yes, sets the title to the m_title data member
			strncpy(m_title, string, MAX_LENGTH);
		}
		else
		{
			// If no, sets the object to the empty state
			clear();
		}

		// Returns the reference of the current object
		return *this;
	}

	void Menu::add(const char* string)
	{
		// IF CONDITION: Checks if the string passed is not nullptr
		if (string != nullptr)
		{
			// If yes, another IF CONDITION: Checks if the m_size is not equal to the maximum items
			if (m_size != MAX_NO_OF_ITEMS)
			{
				// If yes, another if to check if the m_title is not null
				if (m_title[0] != '\0')
				{
					// If yes, copies the string at the particular index, sets the last index of the item to null terminator and increments m_size by 1
					strncpy(m_list[m_size].m_item, string, MAX_LENGTH);
					m_list[m_size].m_item[strlen(m_list[m_size].m_item) + 1] = '\0';
					m_size++;
				}
				else
				{
					// If not, sets the m_list string at the particular index to empty state
					m_list[m_size].setEmpty();
				}
			}
		}
		else
		{
			// If no, sets the object to empty state
			clear();
		}
	}

	Menu& Menu::operator<<(const char* string)
	{
		// Calls the add function to add the string passed to the m_list
		add(string);

		// Returns the reference of the current object
		return *this;
	}

	int Menu::run() const
	{
		int choice, flag = 0;

		// FUNCTION CALL: Displays the menu
		display();

		// IF CONDITION: If the m_size is not 0, execute the statements
		if (m_size)
		{
			// DO-WHILE LOOP: Loops until flag is 0.
			do
			{
				// cin to ask for the user choice
				cin >> choice;
				// If cin fails, say the statement
				if (cin.fail())
				{
					cout << "Invalid Integer, try again: ";
				}
				// If cin passes but choice entered is not in the range, say the print statement
				else if (!cin.fail() && (choice <= 0 || choice > m_size))
				{
					cout << "Invalid selection, try again: ";
				}
				// If cin passes and the entered value is in the range, set the flag to 1 to exit loop
				else if (!cin.fail() && choice > 0 && choice <= m_size)
				{
					flag = 1;
				}

				// In any case, flush the input stream
				cin.clear();
				cin.ignore(1000, '\n');
			} while (!flag);

			// Return the user's choice
			return choice;
		}
		else
		{
			return 0;
		}

	}

	Menu::operator int() const
	{
		int choice;

		// FUNCTION CALL: Calls the run() function for menu execution to ask for the user choice if the menu is casted to int
		choice = run();
		// Returns choice returned from run() execution
		return choice;
	}
	void Menu::clear()
	{
		for (int i = 0; i < m_size; i++)
		{
			// Sets all the elements of the m_list array to an empty state
			m_list[i].setEmpty();
		}
		// Sets the title of the menu list to empty state
		strcpy(m_title, "\0");
		m_size = 0;
		m_intendVal = 0;
	}
}