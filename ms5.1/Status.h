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

#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_
#include <iostream>
namespace sdds
{

    class Status
    {

        char *m_errorDesc{};
        int m_errorCode;

    public:
        Status(const char *c = nullptr);
        Status(const Status &s);
        Status &operator=(const Status &s);

        ~Status();
        Status &operator=(int num);
        Status &operator=(const char *str);

        operator int() const;
        operator const char *() const;
        operator bool() const;
        Status &clear();
    };

    std::ostream &operator<<(std::ostream &ostr, const Status &s);
}
#endif // !SDDS_STATUS_H_
