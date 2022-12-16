/*
*****************************************************************************
						Workshop-3 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 26/09/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "CC.h" //Header file

using namespace std;

namespace sdds
{
	
	bool CC::validate(const char* name,
		unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear) const
	{
		// IF CONDITION: Checks if the conditions of validating the input are met, if true then returns true otherwise false.
		if (name != nullptr && strlen(name) > 2
			&& cardNo > 4000000000000000 && cardNo < 4099999999999999
			&& cvv > 99 && cvv < 1000
			&& expMon > 0 && expMon < 13
			&& expYear > 21 && expYear < 33)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CC::prnNumber()const
	{

		unsigned long long temp; // Creating temporary variable for use ahead
		
		temp = u_cardNumber / 1000000000000; // Extracting 1st set of 4 digits of the Card Number
		cout.fill('0'); // FILL: Prints the required output but makes sure the length required is met by filling the null spaces with '0'.
		cout.width(4); // WIDTH: Sets the length of the output to be printed to fill null spaces with the character supplied in fill.
		cout << temp << " ";
		temp = u_cardNumber % 1000000000000; 
		
		temp = temp / 100000000; // Extracting 2nd set of 4 digits of the Card Number
		cout.fill('0');
		cout.width(4);
		cout << temp << " ";
		temp = u_cardNumber % 100000000; 
		
		temp = temp / 10000; // Extracting 3rd set of 4 digits of the Card Number
		cout.fill('0');
		cout.width(4);
		cout << temp << " ";

		temp = u_cardNumber % 10000; // Extracting the last set of 4 digits of the Card Number
		cout.fill('0');
		cout.width(4);
		cout << temp;
	}

	void CC::set()
	{
		// Sets the class members to safe empty state upon call.
		u_name = nullptr;
		u_cardNumber = 0;
		u_cvv = 0;
		u_expiryMonth = 0;
		u_expiryYear = 0;

	}
	void CC::cleanUp()
	{
		// Deletes the dynamically allocated memory to the member u_name 
		delete[] u_name;
		set(); // Function call set(): Function to put back the members into safe empty state.
	}
	bool CC::isEmpty() const
	{
		// Checks if the member u_name is nullptr or not to check if the object is empty or not. Returns boolean value accordingly.
		if (u_name == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short cvv,
		short expMon,
		short expYear)
	{
		bool valid = false;
	
		// Function call cleanUp(): Deallocates existing memory space and sets the members to safe empty space.
		cleanUp();

		// Function call validate(): Validates the inputted set of values and returns boolean accordingly.
		valid = validate(cc_name, cc_no, cvv, expMon, expYear);
		if (valid)
		{
			//If validation is successful, allocate dynamic memory to the name and set the member variables to the supplied values.
			u_name = new char[strlen(cc_name) + 1];
			strcpy(u_name, cc_name);
			u_cvv = cvv;
			u_expiryMonth = expMon;
			u_expiryYear = expYear;
			u_cardNumber = cc_no;
		}
	}
	bool CC::read()
	{
		bool success = false;
		char cName[72] = { '\0' };
		int cvv;
		int expMon;
		int expYear;
		unsigned long long cNumber;

		// Function call cleanUp(): Deallocates existing memory space and sets the members to safe empty space.
		cleanUp();

		cout << "Card holder name: ";
		
		// Reads one line from the input buffer till 72 characters and sets it to cName
		cin.getline(cName, 72);
		if (cin) // If cin passed, control moves inside otherwise exited
		{
			cout << "Credit card number: ";
			cin >> cNumber; // Reads the number entered and sets it to cNumber
			if (cin)
			{
				cout << "Card Verification Value (CVV): ";
				cin >> cvv; // Reads the number entered and sets it to cvv
				if (cin)
				{
					cout << "Expiry month and year (MM/YY): ";
					cin >> expMon; // Reads the number entered and sets it to expMon
					cin.ignore(1, '\n'); // Ignores 1 character nex to the previous input 
					cin >> expYear; // Scans the next part after ignore from the input buffer
					if (cin)
					{
						success = true; // Success turns true only if all if blocks pass, else it remains false.
					}
				}
			}
		}

		if (success)
		{
			// FUNCTION CALL set(): If the inputs are read successfully, set the values into the object members.
			set(cName, cNumber, cvv, expMon, expYear);
			cin.ignore(256, '\n'); // Ignores the next inputs until a new end of line is found or 256 characters are discarded.
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n'); // Ignores the next inputs until a new end of line is found or 256 characters are discarded.
		}

		//IF condition: calls function isEmpty() to check if the object has data inside or not. If it has data, return true otherwise false.
		if (!isEmpty() && success)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void CC::display(int row) const
	{
		// IF CONDITION: Checks if the object passed is not empty
		if (!isEmpty())
		{
			// If rows are more than zero, prints the data in tabular form
			if (row > 0)
			{
				char temp[31] = { '\0' }; // Temporary string to print just 30 characters of name.

				strcpy(temp, u_name,30); // strncpy: copies the specified length of chars from u_name to temp
				cout << "| ";
				cout.fill(' '); // FILL: Prints the required output but makes sure the length required is met by filling the null spaces with ' ' (empty space).
				cout.width(3); // WIDTH: Sets the length of the output to be printed to fill null spaces with the character supplied in fill.
				cout.setf(ios::right); // SETF: Sets the justification of the cout as right, left or fixed depending on the passed argument.
				cout << row << " | ";
				cout.unsetf(ios::right);// UNSETF: Unsets the justification of the cout to neutral: requires the previous cout justification as the parameter.
				cout.fill(' ');
				cout.width(30);
				cout.setf(ios::left);
				cout << temp << " | ";
				cout.unsetf(ios::left);
				prnNumber(); // Function call: Prints the card number in formatted set of 4 digits
				cout << " | " << u_cvv << " | ";
				cout.fill(' ');
				cout.width(2);
				cout.setf(ios::right);
				cout << u_expiryMonth;
				cout.unsetf(ios::right);
				cout << "/" << u_expiryYear << " |" << endl;
			}
			//If rows are less than or equal to 0, print the data in the form format
			else if (row <= 0)
			{
				cout << "Name: " << u_name << endl << "Creditcard No: ";
				prnNumber();
				cout << endl << "Card Verification Value: " << u_cvv << endl << "Expiry Date: " << u_expiryMonth << "/" << u_expiryYear << endl;
			}
		}
		else
		{
			cout << "Invalid Credit Card Record" << endl;
		}
	}
}