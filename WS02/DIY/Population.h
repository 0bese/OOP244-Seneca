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
***********************************************************************/#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
   struct Postcode {
		char* m_token = nullptr;
		unsigned int m_population = 0;
	};
   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);
   bool load(const char* filename, const char* partial_postal_code_prefix);
   bool getPostalCode(char* postal_code_prefix);
   void display();
   void display(const Postcode &pc);
   void deallocateMemory();   

}
#endif // SDDS_POPULATION_H_