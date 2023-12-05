/*
    ==================================================
    Mile Stone 4
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/12/3
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#ifndef _SDDS_STATUS_H
#define _SDDS_STATUS_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{
    class Status
    {
        char *description{};
        int code;

    public:
        // constructors
        Status();
        //
        Status(const char *refDescription);
        //
        // copy Constructor
        Status(const Status &obj);
        //
        //
        // destructor
        ~Status();
        //
        Status &clear();
        // Overloading
        Status &operator=(const char *description);
        Status &operator=(int code);
        //
        // casting
        operator int() const;
        operator bool() const;
        operator const char *() const;
        // Helper functions
        std::ostream &printStatus(std::ostream &obj) const;
    };
    // helper
    std::ostream &operator<<(std::ostream &os, const Status &obj);
}
#endif