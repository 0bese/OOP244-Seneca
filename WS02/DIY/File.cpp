/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // Counts the number of records in the file
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    // Close file function
    void closeFile() {
        if (fptr) fclose(fptr);
    }


    // Reads an integer from the file
    bool read(int& population) {
        if (fscanf(fptr, "%d,", &population) == 1) {
            return true;
        }
        return false;
    }

    //Reads a string from the file
    bool read(char*& name) {
        //Deallocate previous memory if not nullptr
        if (name != nullptr) {
           delete[] name;
           name = nullptr;
       }

        char temp[128];
        if (fscanf(fptr, "%127[^\n]\n", temp) == 1) 
        {
            temp[strlen(temp)] = '\0';

            name = new char[strlen(temp) + 1];
            strcpy(name, temp);
            return true;
        }
        return false;
    }
}