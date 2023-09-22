/***********************************************************************
// OOP244 Workshop #1 DIY: tester program
//
// File  Phone.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Phone.h"

using namespace std;

namespace sdds {
   
       	void phoneDir(const char* programTitle, const char* fileName){
            
            //display the title
            cout << programTitle << " phone direcotry search" << endl;
            cout << "-------------------------------------------------------" << endl;
            
            //Open file that we will be searching as read only
            FILE* file = fopen(fileName, "r");

            if( file == false){
                cout << fileName << " file not found!" << endl;
                cout << "Thank you for using " << programTitle << " directory." << "\n\n"<< endl;
                cout << "Press any key to close this window . . ." << endl;
                return;
            }

            do {            
                char str[51] = { 0 }, find[51] = { 0 };
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
                cout << "> ";
                cin >> str;
                if (strCmp(str, "!") == 0)
                    break;

                char name[51] = { 0 }, lowerName[51] = { 0 }, number[5] = { 0 };
                int area, prefix;
                while (fscanf(file, "%[^\t]\t%d\t%d\t%s\n", name, &area, &prefix, number) != EOF)
                {
                    toLowerCaseAndCopy(lowerName, name);
                    toLowerCaseAndCopy(find, str);
                    if (strStr(lowerName, find))
                        cout << name << ": (" << area << ") " << prefix << "-" << number << endl;
                }
                rewind(file);
            } while (true);

            fclose(file);
            cout << "Thank you for using " << programTitle << " directory." << endl;

        
        }

}