/***********************************************************************
// OOP244 Workshop #1 lab: tester program
//
// File  WordStat_prof.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Word.h"
#include "Word.h" // This is intentional
using namespace sdds;
using namespace std;
int main() {
   char filename[256];
   cout << "Enter the following file name" << endl
      << "> FoxInSocks.txt" << endl << "---------------------" << endl;
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}
