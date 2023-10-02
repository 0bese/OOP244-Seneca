/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
   // Define a structure to store population data
    struct Population {
        char* postalCode;  
        int population;   
    };

    // Function prototypes
    bool startsWith(const char* cString, const char* subString);
    bool getPostalCode(char* postal_code_prefix);
    bool load(const char* filename, const char* partial_postal_code_prefix);
    void display();
    void deallocateMemory();
}
#endif // SDDS_POPULATION_H_