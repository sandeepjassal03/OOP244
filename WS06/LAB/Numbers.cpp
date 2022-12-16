/*
*****************************************************************************
						Workshop-6 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 26/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Numbers.h"
using namespace std;
namespace sdds {


	Numbers::Numbers() {
		setEmpty();
		m_isOriginal = false;
	}

	Numbers::Numbers(const char* filename) {
		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		m_numCount = numberCount();
		if (m_numCount == 0 || !load()) {
			deallocate();
			setEmpty();
			m_isOriginal = false;
		}
	}

	Numbers::~Numbers() {
		save();
		deallocate();
	}

	bool Numbers::isEmpty() const {
		return m_numbers == nullptr;
	}

	void Numbers::setEmpty() {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;
	}

	void Numbers::deallocate() {
		delete[] m_filename;
		delete[] m_numbers;
	}

	void Numbers::setFilename(const char* filename) {
		delete[] m_filename;
		m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);
	}



	double Numbers::average() const {
		double aver = 0.0;
		if (!isEmpty()) {
			for (int i = 0; i < m_numCount; i++)
				aver += m_numbers[i];
			aver = aver / m_numCount;
		}
		return aver;
	}

	double Numbers::min() const {
		double minVal = 0.0;
		if (!isEmpty()) {
			minVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (minVal > m_numbers[i]) minVal = m_numbers[i];
		}
		return minVal;
	}
	double Numbers::max() const {
		double maxVal = 0.0;
		if (!isEmpty()) {
			maxVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
		}
		return maxVal;
	}

	Numbers::Numbers(const Numbers& n)
	{
		//Set the current object to empty state, and set current object to the passed parameter.
		setEmpty();
		*this = n;
	}



	Numbers& Numbers::operator=(const Numbers& source) {

		// check for self-assignment
		if (this != &source) {

			// Deallocate the previously allocated dynamic memory: m_numbers and m_filename
			delete[] m_numbers;
			delete[] m_filename;
			// Set the current object to safe state
			setEmpty();
			m_isOriginal = false;
			//If the supplied pointer isn't a nullptr, allocate new memory
			if (source.m_numbers != nullptr) {
				m_numCount = source.m_numCount;
				m_numbers = new double[m_numCount];

				// copy the m_numbers data from the argument to the current object
				for (int i = 0; i < m_numCount; i++)
				{
					m_numbers[i] = source.m_numbers[i];
				}
			}
		}

		// Returns the reference of the current object
		return *this;
	}

	ostream& operator<<(ostream& os, const Numbers& N)
	{
		// Calls the display function for the parameter N
		N.display(os);

		// Returns the reference of the ostream
		return os;
	}
	istream& operator>>(istream& istr, Numbers& N)
	{
		double value = 0;

		// Reads a value from the input stream
		istr >> value;

		// If the input is valid, add it to the parameter N using the overloaded += operator
		if (istr)
		{
			N += value;
		}

		// Returns the reference of the istream
		return istr;
	}


	Numbers Numbers::operator-()const
	{
		// Creating a temporary object of the class Numbers with the current object as the initialiser values
		Numbers temp(*this);

		// Since the operator is -, the value passed is false since we need a descending list of numbers
		temp.sort(false);

		// Returns the temp object
		return temp;
	}

	Numbers Numbers::operator+()const
	{
		// Creating a temporary object of the class Numbers with the current object as the initialiser values
		Numbers temp(*this);

		// Since the operator is +, the value passed is true since we need a ascending list of numbers
		temp.sort(true);

		// Returns the temp object
		return temp;
	}

	Numbers& Numbers::operator+=(double num)
	{
		int i;

		//IF CONDITION: If the current object is not in safe empty state, execute the block of code
		if (!isEmpty())
		{
			// A temporary pointer of type double
			double* temp;

			// DMA for the temp pointer with an increased size
			temp = new double[m_numCount + 1];
			for (i = 0; i < m_numCount; i++)
			{
				// Traverses through the m_numbers array and copies data into the newly allocated memory
				temp[i] = m_numbers[i];
			}

			// Increment m_numCount by 1 to update the variable representing size of m_numbers in the current object
			m_numCount++;

			// Adds the value passed as argument to the last index of the temporary array
			temp[m_numCount - 1] = num;

			// Delete the existing allocated memory for m_numbers
			delete[] m_numbers;

			//SETS m_numbers to temp pointer: so that it points to the newly allocated memory
			m_numbers = temp;
		}

		return *this;
	}


	Numbers& Numbers::sort(bool ascending)
	{
		int i, j;
		double temp;

		// IF CONDITION: Checks if the supplied parameter is true or false, to decide whether sorting is to be in ascending or descending order
		if (ascending)
		{
		// ASCENDING
			// USING BUBBLE SORT TECHNIQUE, compares a number with the next one, swapping them when the condition to swap is met.
			for (i = m_numCount - 1; i > 0; i--)
			{
				for (j = 0; j < i; j++)
				{
					if (m_numbers[j] > m_numbers[j + 1])
					{
						temp = m_numbers[j];
						m_numbers[j] = m_numbers[j + 1];
						m_numbers[j + 1] = temp;
					}
				}
			}
		}
		else
		{
		// DESCENDING
			// USING BUBBLE SORT TECHNIQUE, compares a number with the next one, swapping them when the condition to swap is met.
			for (i = m_numCount - 1; i > 0; i--)
			{
				for (j = 0; j < i; j++)
				{
					if (m_numbers[j] < m_numbers[j + 1])
					{
						temp = m_numbers[j];
						m_numbers[j] = m_numbers[j + 1];
						m_numbers[j + 1] = temp;
					}
				}
			}
		}

		// Returns the reference of the current object
		return *this;
	}
	int Numbers::numberCount() const
	{
		int totalNums = 0;

		// Creates an instance of the ifstream class and opens the file specified in the parameter
		ifstream file("numbers.txt");

		// Do-WHILE LOOP: Iterates through the file and reads one character
		do
		{
			// IF CONDITION: If the character returned is a newline character, increase totalNums by 1
			if (file.get() == '\n')
			{
				totalNums++;
			}
		} while (!file.fail()); // LOOP CONDITION: Until the character read is valid, loop runs, otherwise it terminates.
		return totalNums;
	}
	bool Numbers::load()
	{
		bool returnVal = false;
		int count = 0;

		// Creating an instance of the ifstream with the filename as the constructor argument
		ifstream file(m_filename);

		// IF CONDITION: If the m_numCount is greater than 0, execute the block of code
		if (m_numCount > 0)
		{
			//Delete any previous allocation to the m_numbers pointer and allocate a new memory space for an array of size m_numCount
			delete[] m_numbers;
			m_numbers = nullptr;
			m_numbers = new double[m_numCount];
		}

		// IF CONDITION: If the file is open: execute the block of code
		if (file.is_open())
		{
			// WHILE LOOP: Until the count variable remains less than m_numCount and file remains valid, keep iterating
			while (file && count < m_numCount)
			{
				//Reads a number from the file into the m_numbers array at the specified index
				file >> m_numbers[count];

				// Until the character read is valid, increment the count variable by 1.
				if (!file.fail())
				{
					count++;
				}
			}
		}

		// IF CONDITION: If count equals m_numCount, return true (meaning all data is read successfully)
		if (count == m_numCount)
		{
			returnVal = true;
		}
		file.close();
		return returnVal;
	}

	void Numbers::save()
	{
		// IF CONDITION: If the current object is original and not a copy, and also is not in safe empty state, execute the block of code
		if (m_isOriginal && !isEmpty())
		{
			int i;

			// Creating an instance of the ofstream with the filename as the constructor argument
			ofstream writeFile(m_filename);

			// IF CONDITION: If the file is open: execute the block of code
			if (writeFile.is_open())
			{
				// setf and precision: Sets the justification and the precision of the writeFile instance
				writeFile.setf(ios::fixed);
				writeFile.precision(2);

				for (i = 0; i < m_numCount; i++)
				{
					// FOR Loop to traverse through the array and print the data in the array to the file.
					writeFile << m_numbers[i];

					// Inserts a newline character after every number
					writeFile << "\n";
				}
				writeFile.close();
			}
		}
	}


	ostream& Numbers::display(ostream& ostr) const
	{
		int i;

		//IF CONDITION: If the current object is not in safe empty state, execute the block of code
		if (!isEmpty())
		{
			ostr << "=========================" << endl;

			// IF CONDITION: If the object is original and not a copy, display the filename associated with the object, otherwise display COPY
			if (m_isOriginal)
			{
				ostr << m_filename << endl;
			}
			else
			{
				ostr << "*** COPY ***" << endl;
			}

			// FOR loop to display the items in the m_numbers array
			for (i = 0; i < m_numCount; i++)
			{
				// setf and precision: ostream functions to set the position of the display data and the number of decimal places it needs to be displayed to (here 2).
				ostr.setf(ios::fixed);
				ostr.precision(2);

				if (i == m_numCount - 1)
				{

					ostr << m_numbers[i];
				}
				else
				{
					ostr << m_numbers[i] << ", ";
				}

				// Unsetf: Unsets the position settings made by the setf function.
				ostr.unsetf(ios::fixed);
			}
			ostr << endl << "-------------------------" << endl;
			ostr << "Total of " << m_numCount << " number(s)" << endl;

			// width(): sets the width of the next ostream reference to the supplied value
			ostr.width(17);
			ostr.setf(ios::left);
			ostr << "Largest number: ";
			ostr.unsetf(ios::left);

			// fill(): Sets the print statement's fill character with the supplied character to fill it till the width of the print statement
			ostr.fill(' ');
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << max() << endl;  // max(): displays the largest number in the array
			ostr.unsetf(ios::fixed);

			ostr.width(17);
			ostr.setf(ios::left);
			ostr << "Smallest number: ";
			ostr.unsetf(ios::left);
			ostr.fill(' ');
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << min() << endl; // min(): displays the smallest number in the array
			ostr.unsetf(ios::fixed);

			ostr.width(17);
			ostr.setf(ios::left);
			ostr << "Average: ";
			ostr.unsetf(ios::left);
			ostr.fill(' ');
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << average() << endl; // average(): displays the average of all the numbers in the array
			ostr.unsetf(ios::fixed);

			ostr << "=========================";
		}
		else
		{
			ostr << "Empty list";
		}
		return ostr;
	}
}