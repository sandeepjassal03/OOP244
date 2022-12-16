/*
*****************************************************************************
                        Workshop-5 DIY

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 13/10/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {
      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }

   Apartment::operator bool() const
   {
       // Check if the apartment number is a 4 digit number and the balance is not negative.
       return m_number > 999 && m_number < 10000 && m_balance >= 0;
   }
   Apartment::operator int() const
   {
       // Returns the apartment Number
       return m_number;
   }

   Apartment::operator double() const
   {
       // Returns the apartment Balance
       return m_balance;
   }
   
   bool Apartment::operator ~() const
   {
       // Returns the boolean result for if the balance is 0.
       return m_balance < 0.00001;
   }

   Apartment& Apartment::operator=(int value)
   {
       //IF CONDITION: Checks if the supplied value is a 4 digit number
       //If true, then set it to m_number
       //If false, then set the object to invalid state
       if (value > 999 && value < 10000)
       {
           m_number = value;
       }
       else
       {
           m_number = -1;
           m_balance = 0;
       }

       //Returns the reference of the current object
       return *this;
   }
   Apartment& Apartment::operator=(Apartment& a2)
   {
       int swapNumber = 0;
       double swapRent = 0;

       //IF CONDITION: Checks if the m_number of the parameter supplied is a 4 digit number
       //If true, then swap the two values: m_balance and m_number in both the objects.
       //If false, then set the current object to invalid state
       if(m_number > 999 && m_number < 10000)
       {
           swapNumber = m_number;
           m_number = a2.m_number;
           a2.m_number = swapNumber;

           swapRent = m_balance;
           m_balance = a2.m_balance;
           a2.m_balance = swapRent;
       }
       else
       {
           m_number = -1;
           m_balance = 0;
       }

       //Returns the reference of the current object
       return *this;
   }
   Apartment& Apartment::operator+=(double value)
   {
       //IF CONDITION: Checks if the value supplied is positive and the apartment balance greater than 0.
       if (value >= 0 && m_balance > 0)
       {
           // Add the value supplied to the m_balance
           m_balance += value;
       }
       
       //Returns the reference of the current object
       return *this;
   }

   Apartment& Apartment::operator-=(double value)
   {
       double localBalance = 0;
       localBalance = m_balance;

       //IF CONDITION: Checks if the value supplied is positive and the apartment balance greater than 0.
       if (value >= 0 && m_balance > 0)
       {
           //Subtract the value supplied from the localBalance variable.
           localBalance -= value;

           // If the localBalance stays more than 0, set it to the m_balance; otherwise do nothing. 
           if (!(localBalance < 0.00001))
           {
               m_balance = localBalance;
           }
       }

       //Returns the reference of the current object
       return *this;
   }

   Apartment& Apartment::operator<<(Apartment& a2)
   {
       //IF CONDITION: Checks if the apartments are not the same: i.e., if the apartment number of the current and argument object is not equal.
       if (m_number != a2.m_number)
       {
           // Add the balance of the argument object to the current object and set the balance of the argument object to 0.
           m_balance += a2.m_balance;
           a2.m_balance -= a2.m_balance;
       }
   
       //Returns the reference of the current object
       return *this;
   }

   Apartment& Apartment::operator>>(Apartment& a2)
   {
       //IF CONDITION: Checks if the apartments are not the same: i.e., if the apartment number of the current and argument object is not equal.
       if (m_number != a2.m_number)
       {
           // Add the balance of the current object to the argument object and set the balance of the current object to 0.
           a2.m_balance += m_balance;
           m_balance -= m_balance;
       }

       //Returns the reference of the current object
       return *this;
   }
   double operator+(const Apartment& a1, const Apartment& a2)
   {
       double sum = 0;

       //IF CONDITION: Checks if the argument apartments are in valid state: using the overloaded bool conversion operator.
       if (bool(a1) && bool(a2))
       {
           // Add the balance of the argument apartments to the sum variable by using the overloaded double conversion operator.
           sum = double(a1) + double(a2);
       }

       // Returns sum
       return sum;
   }
   double operator+=(double& value, const Apartment& a1)
   {
       //IF CONDITION: Checks if the value supplied is positive and the argument apartment is in valid state: using the overloaded bool conversion operator.
       if (bool(a1) && value >= 0)
       {
           // Add the balance of the argument apartment to the reference variable supplied by using the overloaded double conversion operator.
           value += double(a1);
       }

       // Return value
       return value;
   }
}