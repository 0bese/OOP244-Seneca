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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Status.h"
#include "Utils.h"
using namespace std;

namespace sdds
{

    // Constructor that initializes Status with a given error description.
    Status::Status(const char *c)
    {
        ut.alocpy(m_errorDesc, c);
        m_errorCode = 0;
    }

    // Copy constructor to create a copy of an existing Status object.
    Status::Status(const Status &s) : m_errorDesc(nullptr), m_errorCode(s.m_errorCode)
    {
        if (s.m_errorDesc != nullptr)
        {
            ut.alocpy(m_errorDesc, s.m_errorDesc);
        }
    }

    // Assignment operator to assign the values of one Status object to another.
    Status &Status::operator=(const Status &s)
    {
        m_errorCode = s.m_errorCode;
        ut.alocpy(m_errorDesc, s.m_errorDesc);
        return *this;
    }

    // Destructor to clean up and release any dynamically allocated resources.
    Status::~Status()
    {
        clear();
    }

    // Assignment operator to set the error code of a Status object from an integer.
    Status &Status::operator=(int num)
    {
        m_errorCode = num;
        return *this;
    }

    // Assignment operator to set the error description of a Status object from a string.
    Status &Status::operator=(const char *str)
    {
        ut.alocpy(m_errorDesc, str);
        return *this;
    }

    // Conversion operator to convert a Status object to an integer (error code).
    Status::operator int() const
    {
        return m_errorCode;
    }

    // Conversion operator to convert a Status object to a const char* (error description).
    Status::operator const char *() const
    {
        return m_errorDesc;
    }

    // Conversion operator to convert a Status object to a boolean value(true if no error description).
    Status::operator bool() const
    {
        return m_errorDesc == nullptr;
    }

    // Function to clear the Status object by releasing any allocated resources and resetting values.
    Status &Status::clear()
    {
        delete[] m_errorDesc;
        m_errorDesc = nullptr;
        m_errorCode = 0;
        return *this;
    }

    // Overloaded output stream operator to display a Status object.
    ostream &operator<<(ostream &ostr, const Status &s)
    {
        if (!s)
        {
            if (int(s) != 0)
            {
                ostr << "ERR#" << int(s) << ": " << (const char *)s;
            }
            else
            {
                ostr << (const char *)s;
            }
        }
        return ostr;
    }

}
