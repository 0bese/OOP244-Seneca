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

#ifndef _SDDS_DATE_H
#define _SDDS_DATE_H
#include <iostream>
#include <cstring>
#include <sstream>
#include "Status.h"
using namespace std;
namespace sdds
{
    const int MAXIMUM_YEAR = 2030;
    class Date
    {
    public:
        int year;
        int month;
        int day;
        Status status;
        bool format;
        // Function that validates the date entered and returns the result accordingly
        bool validate();
        // Returns a unique date value
        int uniqueValue() const;
        // Default constructor to set the format to true and get the system date
        Date();
        // Parameterised constructor
        Date(int year, int month, int date);
        // assignment operator check if the unique date value of the passed object is equal to the current object
        bool operator==(const Date &object) const;
        // Operator checks if the unique Date value of the current object is unequal to that of the passed object
        bool operator!=(const Date &object) const;
        // Operator checks if the unique Date value of the current object is less than that of the passed object
        bool operator<(const Date &object) const;
        // Operator checks if the unique Date value of the current object is greater than that of the passed object
        bool operator>(const Date &object) const;
        // Operator checks if the unique Date value of the current object is greater than or equal to that of the passed object
        bool operator>=(const Date &object) const;
        // Operator checks if the unique Date value of the current object is less than or equal to that of the passed object
        bool operator<=(const Date &object) const;
        // Returns the reference to the State of the date
        const Status &state();
        // Formatted modifier to set the formatted flag of the Date
        Date &formatted(bool isDateFormatted);
        // Casting date object to a boolean value
        operator bool() const;

        // function that is used to print the formatted or unformatted date to the screen
        std::ostream &write(std::ostream &object) const;
        // Function that is used to retrieve the date month and year from the integer value entered
        std::istream &read(std::istream &object);
    };
    // Helper insertion operator to write the object through ostream
    std::ostream &operator<<(std::ostream &os, const Date &date);
    // Helper extraction operator to read the date object through istream
    std::istream &operator>>(std::istream &is, Date &date);

}
#endif