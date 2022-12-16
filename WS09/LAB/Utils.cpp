/*
*****************************************************************************
                        Workshop-9 LAB

Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NCC
Date       : 23/11/2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Utils.h"
namespace sdds
{
    unsigned getFileLength(std::istream& is) {
        unsigned len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, std::ios::end);
            // tell what is the positions (end position = size)
            len = unsigned(is.tellg());
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }
}