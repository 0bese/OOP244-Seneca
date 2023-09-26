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
#include "Population.h"
#include "File.h"
namespace sdds {
   Postcode* postcodes;
   int noOfPostcodes;

   bool startsWith(const char* cstring, const char* subString) {
      return std::strstr(cstring, subString) == cstring;
   }

   bool getPostalCode(char* postal_code_prefix) {
      std::cout << "Population Report\n-----------------\nEnter postal code:\n> ";
      std::cin >> postal_code_prefix;

      return postal_code_prefix[0] != '!';
   }

   bool load(const char* filename, const char* partial_postal_code_prefix) {
      if (openFile(filename)) {
         int numMatches = 0;
         noOfPostcodes = sizeOfList();

         for (int i = 0; i < noOfPostcodes; i++) {
            char* postalCode;
            unsigned int population;

            if (read(postalCode) && read(population) && startsWith(postalCode, partial_postal_code_prefix)) {
               numMatches++;
            }

            delete[] postalCode;
         }

         postcodes = new Postcode[numMatches];
         rewindFile();

         int matchIndex = 0;
         for (int i = 0; i < noOfPostcodes; i++) {
               char* postalCode;
               unsigned int population;

               if (read(postalCode) && read(population) && startsWith(postalCode, partial_postal_code_prefix)) {
                  strcpy(postcodes[matchIndex].m_token, postalCode);
                  postcodes[matchIndex].m_population = population;
                  matchIndex++;
               }

            delete[] postalCode;
         }

         closeFile();
         return true;
      }

      return false;
   }

   void display() {
      std::cout << "Population Report\n-----------------" << std::endl;
      int totalPopulation = 0;

      for (int i = 0; i < noOfPostcodes; i++) {
         std::cout << postcodes[i].m_token << ": " << postcodes[i].m_population << std::endl;
         totalPopulation += postcodes[i].m_population;
      }

      std::cout << "-------------------------" << std::endl; 
      std::cout << "Population of the listed areas: " << totalPopulation << std::endl;
   }

   void deallocateMemory() {
      delete[] postcodes;
      postcodes = nullptr;
   }



}