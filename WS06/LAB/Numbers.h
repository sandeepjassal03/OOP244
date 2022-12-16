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
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_

#include <iostream>
#include <cstring>
#include <fstream>
namespace sdds {
   class Numbers {

      /******************************************************
                           DATA MEMBERS
      ******************************************************/
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;

      /******************************************************
                    PRIVATE MEMBER FUNCTIONS
      ******************************************************/
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);

   public:
      /******************************************************
                          CONSTRUCTORS
      ******************************************************/
      Numbers();
      Numbers(const Numbers & n);
      Numbers(const char* filename);

      // *** DESTRUCTOR ***
      ~Numbers();

      /******************************************************
                      MEMBER OPERATORS
      ******************************************************/
      Numbers& operator=(const Numbers& source);
      Numbers& operator+=(double num);
      Numbers operator-()const;
      Numbers operator+()const;

      /******************************************************
                     PUBLIC MEMBER FUNCTIONS
      ******************************************************/
      double average()const;
      double max()const;
      double min()const;

      bool load();
      void save();

      Numbers& sort(bool ascending);
      int numberCount() const;

      std::ostream& display(std::ostream& ostr) const;
   };

   /******************************************************
                      HELPER OPERATORS
   ******************************************************/
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

