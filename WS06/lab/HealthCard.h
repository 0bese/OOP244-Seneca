#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];

      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
      void setEmpty();
      void allocateAndCopy(const char* name);
      void extractChar(std::istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr)const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
      
   public:
      HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
      HealthCard(const HealthCard& hc);
      HealthCard& operator=(const HealthCard& hc);
      ~HealthCard();
      operator bool() const;
      std::ostream& print(std::ostream& ostr, bool toFile = true) const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SDDS_HealthCard_H


