#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
namespace sdds
{
   class Status
   {
      char* m_errDesc{};
      int m_errCode;
   public:
      Status(const char* c = nullptr);
      Status(const Status& s);
      Status& operator=(const Status& s);
      ~Status();
      Status& operator=(int num);
      Status& operator=(const char* str);
      operator int()const;
      operator const char* ()const;
      operator bool()const;
      Status& clear();
   };
   std::ostream& operator<< (std::ostream& ostr, const Status& s);
}
#endif