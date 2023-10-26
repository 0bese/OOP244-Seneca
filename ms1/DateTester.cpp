/***********************************************************************
// Final project Milestone 1
// Module: Date
// File: DateTester.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include "Date.h"
#include "Utils.h"
using namespace std;
using namespace sdds;
void testDate() {
   Date D;
   cout << "> ";
   cin >> D;
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << D.state() << endl;
   }
   else {
      cout << "Date enterd: " << D << endl;
   }
}
int main() {
   cout << "Current Date: " << Date() << endl;
   cout << "Test mode: " << endl;
   ut.testMode();
   Date C;
   Date F(2024, 2, 3);
   cout << "Current Date formatted (C): " << C << endl;
   C.formatted(false);
   cout << "Current Date unformatted (C): " << C << endl;
   cout << "Future Date formatted (F): " << F << endl;
   F.formatted(false);
   cout << "Future Date unformatted (F): " << F << endl;
   cout << "The current date is" << (C != F ? " NOT" : "") << " the same as the future date" << endl;
   cout << "The current date is" << (C == C ? "" : " NOT") << " the same as the current date" << endl;
   cout << "The current date is" << (C <= F ? " Less than or equal to" : " greater than") << " the future date" << endl;;
   cout << "The current date is" << (C <= C ? " Less than or equal to" : " greater than") << " the current date" << endl;;
   cout << "The current date is" << (C < F ? " Less than" : " greater than or equal to") << " the future date" << endl;;
   cout << "The future date is" << (F >= C ? " greater than or equal to" : " Less than") << " the current date" << endl;;
   cout << "The future date is" << (F >= F ? " greater than or equal to" : " Less than") << " the future date" << endl;;
   cout << "The future date is" << (F > C ? " greater than" : " Less than or equal to") << " the current date" << endl;;
   cout << "--------------\nAssigning the Current date to the future date!" << endl;
   C = F;
   if (C == F)
      cout << "Now both of the dates are the same!" << endl;
   else
      cout << "The two dates are different after assignment!!!!!" << endl;
   cout << "Enter the following:\n1- abc\n2- 12\n3- 1212\n4- 121212"
      "\n5- 231312\n6- 250229\n7- 240229" << endl;
   for (int i = 0; i < 7; i++) {
      testDate();
   }
   return 0;
}