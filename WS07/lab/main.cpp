/***********************************************************************
// OOP244 Workshop #7 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo 
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include "Container.h"
#include "Pack.h"
using namespace std;
using namespace sdds;
void ContainerTest();
void PackTest();

int main() {
   ContainerTest();
   PackTest();
}

void PackTest() {
   Pack P("Pepsi", 24);
   Pack W("Olive Oil", 10, 150, 12);
   cout << "Pack Tester........................." << endl;
   cout << P << endl;
   cout << "Added " << (P += 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << P << endl;
   cout << "Added " << (P += 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << P << endl;
   cout << "Removed " << (P -= 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << P << endl;
   cout << "Removed " << (P -= 14) << " cans of " << P.unit() << " CCs" << endl;
   cout << endl << "Enter 14" << endl;
   cin >> P;
   cout << P << endl;
   cout << endl << "Enter 14 and then 10" << endl;
   cin >> P;
   cout << P << endl;
   cout << "Trying to add to a full pack..." << endl;
   cin >> P;
   cout << "Printing the broken pack of Olive oil..." << endl;
   cin >> W;
   cout << "Clearing the broken pack and filling it with wine..." << endl;
   W.clear(12, 750, "Wine");
   cout << "Now pack has " << W << endl;
   cout << "Adding 5 to the pack" << endl; 
   W += 5;
   cout << W << endl;
}
void ContainerTest() {
   Container B("Bad one!", 200, 300);
   Container C("Milk", 250);
   cout << "Container Tester........................." << endl;
   cout << C << endl;
   cout << B << endl;
   cout << "Adding " << (C += 200) << " CCs" << endl;
   cout << C << endl;
   cout << "Adding another " << (C += 200) << " CCs" << endl;
   cout << C << endl;
   cout << "Removing " << (C -= 200) << " CCs" << endl;
   cout << C << endl;
   cout << "Removing another " << (C -= 200) << " CCs" << endl;
   cout << C << endl;
   cout << endl << "Enter 222" << endl;
   cin >> C;
   cout << C << endl;
   cout << endl << "Enter 222" << endl;
   cin >> C;
   cout << C << endl;
   cout << "Trying to read into broken container..." << endl;
   cin >> B;
   cout << "Clearing the broken container, setting it to an empty 200 CC water container..." << endl;
   B.clear(200, "Water");
   cout << "Adding 150 CCs of water..." << endl;
   B += 150;
   cout << "Now the container has: " << endl;
   cout << B << endl;
}