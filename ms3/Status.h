/*
    ==================================================
    Mile Stone 3
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/11/21
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#ifndef STATUS_H
#define STATUS_H
#include <iostream>

namespace sdds
{
    class Status
    {
    private:
        char *statusOfObj;
        int statusCode;

    public:
        void setEmpty();
        Status(const char *description = nullptr);
        Status &operator=(int code);
        Status &operator=(const char *descrption);
        operator int() const;
        operator const char *() const;
        operator bool() const;
        Status &clear();
        std::ostream &print(std::ostream &os) const;
    };
    std::ostream &operator<<(std::ostream &os, const Status &sta);
}
#endif // STATUS_H