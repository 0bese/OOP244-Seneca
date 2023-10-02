/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm> 
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
    Population* populationData = nullptr;
    int populationCount = 0;  
    extern FILE* fptr;  

    // Function to check if a string starts with another string
    bool startsWith(const char* cstring, const char* subString) {
        return strncmp(cstring, subString, strlen(subString)) == 0;
    }

    // Gets a postal code from user input
    bool getPostalCode(char* postal_code_prefix) {
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << "> ";
        cin.getline(postal_code_prefix, 4);

        if (strcmp(postal_code_prefix, "!") == 0) {
            return false;
        }

        return true;
    }

    // Loads population data from a file
    bool load(const char* filename, const char* partial_postal_code_prefix) {
        if (openFile(filename)) {
            const int maxRecords = noOfRecords();
            populationData = new Population[maxRecords];

            int matchCount = 0;
            char line[100];

            while (matchCount < maxRecords && fgets(line, sizeof(line), fptr)) {
                char postalCode[4] = { 0 };
                int population = 0;

                if (sscanf(line, "%3[^,],%d", postalCode, &population) == 2) {
                    if (strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(postalCode, partial_postal_code_prefix)) {
                        populationData[matchCount].postalCode = new char[4];
                        strcpy(populationData[matchCount].postalCode, postalCode);
                        populationData[matchCount].population = population;
                        matchCount++;
                    } 
                }
            }

            populationCount = matchCount;
            closeFile();
            return true;
            
        }
        else {
            std::cerr << "Could not open data file: " << filename << std::endl;
            return false;
        }
    }

        
   // Display population data sorted by population and postal code
    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        // Sort populationData using a custom comparison function
        std::sort(populationData, populationData + populationCount, [](const Population& a, const Population& b) {
            if (a.population != b.population) {
                return a.population < b.population;  
            }
            return strcmp(a.postalCode, b.postalCode) < 0; 
            });

        int totalPopulation = 0;
        for (int i = 0; i < populationCount; i++) {
            cout << i + 1 << "- " << populationData[i].postalCode << ":  " << populationData[i].population << endl;
            totalPopulation += populationData[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << totalPopulation << "\n" << endl;
    }



    // Deallocate memory used for population data
    void deallocateMemory() {
        for (int i = 0; i < populationCount; i++) {
            delete[] populationData[i].postalCode;
        }

        delete[] populationData;  
        populationData = nullptr;
        populationCount = 0;      

    }
}