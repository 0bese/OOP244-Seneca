/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
      Portfolio();
      void emptyPortfolio();
      Portfolio(double value, const char* stock, char type);
      void dispPortfolio() const;
      std::ostream& display() const;
      operator double() const;
      operator const char*() const;
      operator const char() const;
      operator bool() const;
      Portfolio& operator +=(double newValue);
      Portfolio& operator -=(double newValue);
      bool operator ~() const;
      Portfolio& operator <<(Portfolio& departure);
      Portfolio& operator >>(Portfolio& arrival);
   };

   double operator +(const Portfolio& left, const Portfolio& right);
   double& operator +=(double& left, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_