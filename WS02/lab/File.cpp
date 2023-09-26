/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here   
   bool read(char *nameEmp) {
       int ret = fscanf(fptr, "%[^\n]\n", nameEmp);
       return ret ? 1 : 0;   
   
   }
   bool read(int& numEmp) {
      int ret = fscanf(fptr, "%d,", &numEmp);
       return ret ? 1 : 0;
   }
   bool read(double& salEmp) {
      int ret = fscanf(fptr, "%lf,", &salEmp);
       return ret ? 1 : 0;
   }
   
}