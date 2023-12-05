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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    // constructor
    Status::Status()
    {
        description = nullptr;
        code = 0;
    }
    Status::Status(const char *refDescription)
    {
        code = 0;
        if (refDescription != nullptr)
        {
            ut.alocpy(description, refDescription);
        }
        else
        {
            description = nullptr;
        }
    }
    Status::Status(const Status &obj)
    {
        if (obj.description != nullptr)
        {
            ut.alocpy(description, obj.description);
            code = obj.code;
        }
        else
        {
            delete[] description;
            description = nullptr;
            code = 0;
        }
    }
    Status &Status::clear()
    {
        if (description != nullptr)
        {
            delete[] description;
            description = nullptr;
            code = 0;
        }

        return *this;
    }
    Status &Status::operator=(const char *refDescription)
    {
        if (refDescription != nullptr)
        {
            ut.alocpy(description, refDescription);
        }
        return *this;
    }
    Status &Status::operator=(const int refCode)
    {
        code = refCode;
        return *this;
    }
    Status::operator int() const
    {
        return code;
    }
    Status::operator const char *() const
    {
        return description;
    }
    Status::operator bool() const
    {
        return (description == nullptr);
    }

    std::ostream &Status::printStatus(std::ostream &obj) const
    {
        if (code != 0)
        {
            obj << "ERR#" << code << ": ";
            obj << description;
        }
        else
        {
            obj << description;
        }
        return obj;
    }
    Status::~Status()
    {
        if (description != nullptr)
        {
            delete[] description;
            description = nullptr;
        }
    }
    std::ostream &operator<<(std::ostream &os, const Status &obj)
    {
        if (!obj)
        {
            obj.printStatus(os);
        }
        return os;
    }

}