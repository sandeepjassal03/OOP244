/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Sandeep Singh   23/06/2022      Added two new functions for use in other files
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_


namespace sdds {
	
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();

   // Scans an integer from the fptr stream and puts into the value variable
   bool read(int& value, FILE* fptr); 

   // Scans an integer from the fptr stream and puts into the cstr string variable
   bool read(char* cstr, FILE* fptr);
}
#endif // !SDDS_FILE_H_
