/*
*****************************************************************************
						MILESTONE 5

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 05/11/2022

Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author	Sandeep Singh
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/05  Preliminary release
2022/11/10  Added getMenuItem() function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*****************************************************************************
*/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>
#include "Utils.h"
#include <cstring>

namespace sdds
{
	// CONSTANT VARIABLES
	const int MAX_LENGTH = 50;
	const int MAX_NO_OF_ITEMS = 10;

	// Forward declaration of Menu class
	class Menu;


	class MenuItem
	{
		/******************************************
					  DATA MEMBERS
		******************************************/
		char m_item[MAX_LENGTH + 1];

		/******************************************
					  CONSTRUCTORS
		******************************************/
		MenuItem();
		MenuItem(const char* item);
		MenuItem(const MenuItem& source) = delete;
		/******************************************
					MEMBER OPERATORS
		******************************************/
		MenuItem& operator=(const MenuItem& source) = delete;

		/******************************************
					PRIVATE MEMBER FUNCTIONS
		******************************************/
		
		void display() const;
		bool isEmpty() const;
		void setEmpty();

		// Making Menu a friend of MenuItem class to access its content
		friend class Menu;
	};

	class Menu
	{
		/******************************************
					  DATA MEMBERS
		******************************************/
		char m_title[MAX_LENGTH + 1];
		MenuItem m_list[MAX_NO_OF_ITEMS];
		int m_size;
		int m_intendVal;

		/******************************************
				   PRIVATE MEMBER FUNCTIONS
		******************************************/
		bool isEmpty() const;
	public:

		/******************************************
					  CONSTRUCTORS
		******************************************/
		Menu();
		Menu(const char* title, int intendVal = 0);
		Menu(const Menu& source) = delete;

		/******************************************
				    MEMBER OPERATORS
		******************************************/
		Menu& operator=(const Menu& source) = delete;
		Menu& operator=(const char* string);
		Menu& operator<<(const char* string);
		operator bool() const;
		operator int() const;

		/******************************************
				     MEMBER FUNCTIONS
		******************************************/
		void display() const;
		void clear();
		void add(const char* string);
		int run() const;

		const char* getMenuItem(int i);
	};
}

#endif