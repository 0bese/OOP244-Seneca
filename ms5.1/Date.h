/*
    ==================================================
    Mile Stone 5.1
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/12/09
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
namespace sdds
{

    class Date
    {
        const int maxYear = 2030;
        int m_Year;
        int m_Month;
        int m_Day;

        Status m_State;

        bool m_Format = true;
        bool validate();
        int uniqueDateValue();

        bool isMonthValid() const;
        bool isYearValid() const;
        bool isDayValid() const;

        static const int dayInYear = 372;
        static const int dayInMonth = 31;

    public:
        Date(int Year = 0, int Month = 0, int Date = 0);

        Date &operator=(const Date &date);
        bool operator==(const Date &date) const;
        bool operator!=(const Date &d) const;
        bool operator<(const Date &date) const;
        bool operator<=(const Date &date) const;
        bool operator>(const Date &date) const;
        bool operator>=(const Date &date) const;

        const Status &state() const;
        Date &formatted(bool set);

        operator bool() const;

        std::istream &read(std::istream &istr);
        std::ostream &write(std::ostream &ostr) const;
    };

    std::ostream &operator<<(std::ostream &ostr, const Date &date);
    std::istream &operator>>(std::istream &istr, Date &date);

}

#endif //! SDDS_DATE_H_
