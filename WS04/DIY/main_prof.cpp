/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  main_prof.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
   int noOfLabels;
   // Create a lable for the program title:
   Label 
      theProgram("/-\\|/-\\|"),
      test1,
      test2("ABCDEFGH");
   test1.printLabel();
   test2.printLabel();
   theProgram.printLabel() << endl;
   test1.text("Testing one, two, three");
   test1.printLabel() << endl;
   theProgram.text("Professor's Label Maker Program Tester");
   theProgram.printLabel() << endl << endl;
   cout << "Enter the follwing information:" << endl <<
      "# of Labels > 6\n"
      "1> Applied Problem Solving\n"
      "2> Computer Principles for Programmers\n"
      "3> Communicating Across Contexts (Enriched)\n"
      "4> Introduction to Programming Using C\n"
      "5> Introduction to UNIX/Linux and the Internet\n"
      "6> Computer Programming and Analysis, Co-op (Work-Integrated Learning option only)\n\n";

      // ask for number of labels to get created
   cout << "Number of labels to create: ";
   cin >> noOfLabels;
   cin.ignore(10000, '\n');
   // Create a LabelMaker for the number of 
   // the labels requested
   LabelMaker lblMkr(noOfLabels);
   // Ask for the label texts
   lblMkr.readLabels();
   // Print the labels
   lblMkr.printLabels();
   return 0;
}