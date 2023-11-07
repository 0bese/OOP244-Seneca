/* ------------------------------------------------------
Final project Milestone 4
Module: Perishable
Filename: main.cpp
Version 1.0
Author: Fardad Soleimanloo   2022-03-27
Revision History
-----------------------------------------------------------
Date          Reason
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Perishable.h"
using namespace std;
using namespace sdds;
void resetToOriginal();
void entryAndSave();
void descriptive();
int main() {
   resetToOriginal();
   entryAndSave();
   cout << "------------------------" << endl;
   descriptive();
   return 0;
}
void resetToOriginal() {
   ifstream in("dataOriginal.dat");
   ofstream out("data.dat");
   char ch;
   while (in.get(ch)) out.put(ch);
}
void entryAndSave() {
   ofstream file("data.dat", ios::app);
   iProduct* p = new Perishable;
   cout << "Enter the following values: " << endl
      << 
      "4444\n"
      "44444\n"
      "11111\n"
      "Advil Extra Strength Caplets\n"
      "22\n"
      "2\n"
      "22.22\n"
      "221212\n"
      "<ENTER>\n"<< "------------------------" << endl;
   p->readSku(cin);
   cin >> *p;
   cout << "------------------------" << endl;
   cout << *p;
   cout << "------------------------" << endl;
   p->linear(true);
   cout << *p << endl;
   p->save(file) << endl;
   cout << "Enter the following values: " << endl
      <<
      "22222\n"
      "Advil\n"
      "33\n"
      "3\n"
      "33.33\n"
      "221212\n"
      "Keep in room temperature\n" << "------------------------" << endl;
   p->readSku(cin);
   cin >> *p ;
   cout << "------------------------" << endl;
   p->linear(false);
   cout << *p << endl;
   cout << "------------------------" << endl;
   p->linear(true);
   cout << *p << endl;
   p->save(file) << endl;
   file.flush();
   file.close();
   delete p;
}
void descriptive() {
   ifstream file("data.dat");
   Perishable p;
   while (p.load(file)) {
      cout << p << endl;
      cout << "----------------------------------\nExpiry date: " << p.expiry() << "\n----------------------------------\n";
   }
}
