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
#include <iomanip>
#include "Date.h"
#include "Utils.h"

using namespace std;

namespace sdds
{

    bool Date::isMonthValid() const
    {
        // Check if the month is within the valid range (1 to 12).
        return m_Month >= 1 && m_Month <= 12;
    }

    bool Date::isYearValid() const
    {
        // Check if the year is within the valid range (current year to maxYear).
        int currentYear;
        ut.getSystemDate(&currentYear);
        return m_Year >= currentYear && m_Year <= maxYear;
    }

    bool Date::isDayValid() const
    {
        // Check if the day is within the valid range for the given month and year.
        return m_Day >= 1 && m_Day <= ut.daysOfMon(m_Month, m_Year);
    }

    bool Date::validate()
    {
        // Validate the date by checking month, year, and day validity.
        // Set the state and return false if validation fails.
        if (!isMonthValid())
        {
            m_State = "Invalid month in date";
            return false;
        }

        if (!isYearValid())
        {
            m_State = "Invalid year in date";
            return false;
        }

        if (!isDayValid())
        {
            m_State = "Invalid day in date";
            return false;
        }

        return true;
    }

    int Date::uniqueDateValue()
    {
        // Calculate a unique value representing the date based on year, month, and day.
        return m_Year * dayInYear + m_Month * dayInMonth + m_Day;
    }

    Date::Date(int year, int month, int day) : m_Year(year), m_Month(month), m_Day(day)
    {
        // Constructor with default values; sets the current system date if all arguments are zero.
        if (year == 0 && month == 0 && day == 0)
        {
            ut.getSystemDate(&m_Year, &m_Month, &m_Day);
        }
        // Validate the date after initialization.
        validate();
    }

    Date &Date::operator=(const Date &date)
    {
        // Assignment operator; copies values from another Date object.
        if (this == &date)
        {
            return *this;
        }
        // Copy values from the source Date object.
        m_Year = date.m_Year;
        m_Month = date.m_Month;
        m_Day = date.m_Day;
        m_State = date.m_State;
        m_Format = date.m_Format;
        return *this;
    }

    bool Date::operator==(const Date &date) const
    {
        // Equality comparison operator; returns true if years, months, and days are equal.
        return (m_Year == date.m_Year) && (m_Month == date.m_Month) && (m_Day == date.m_Day);
    }

    bool Date::operator!=(const Date &date) const
    {
        // Inequality comparison operator; returns true if the dates are not equal.
        return !(*this == date);
    }

    bool Date::operator<(const Date &date) const
    {
        // Less than comparison operator; compares dates in the order of year, month, and day.
        if (m_Year != date.m_Year)
            return m_Year < date.m_Year;
        if (m_Month != date.m_Month)
            return m_Month < date.m_Month;
        return m_Day < date.m_Day;
    }

    bool Date::operator<=(const Date &date) const
    {
        // Less than or equal to comparison operator; uses the < operator for comparison.
        return !(*this > date);
    }

    bool Date::operator>(const Date &date) const
    {
        // Greater than comparison operator; reverses the < operator for comparison.
        return date < *this;
    }

    bool Date::operator>=(const Date &date) const
    {
        // Greater than or equal to comparison operator; uses the > operator for comparison.
        return !(*this < date);
    }

    const Status &Date::state() const
    {
        // Get the current state of the date.
        return m_State;
    }

    Date &Date::formatted(bool set)
    {
        // Set or unset the formatted flag for date output.
        m_Format = set;
        return *this;
    }

    Date::operator bool() const
    {
        // Conversion to bool; checks if the date is in a valid state.
        return state();
    }

    istream &Date::read(istream &istr)
    {
        // Read a date value from the input stream and validate it.
        int input;
        istr >> input;

        if (istr.fail())
        {
            m_State = "Invalid date value";
            return istr;
        }

        // Parse the input value into year, month, and day components.
        // Adjust the year if it is less than 100. Validate the date after parsing.
        if (input > 999 && input < 10000)
        {
            m_Month = input / 100;
            m_Day = input % 100;
            ut.getSystemDate(&m_Year);
        }
        else
        {
            m_Year = input / 10000;
            if (m_Year < 100)
            {
                m_Year += 2000;
            }
            m_Month = (input % 10000) / 100;
            m_Day = input % 100;
        }

        if (!validate())
        {
            istr.setstate(ios::failbit);
        }
        return istr;
    }

    ostream &Date::write(ostream &ostr) const
    {
        // Write the date to the output stream with optional formatting.
        ostr << setw(m_Format ? 4 : 2) << setfill('0') << (m_Format ? m_Year : m_Year % 100)
             << (m_Format ? "/" : "") << setw(2) << m_Month
             << (m_Format ? "/" : "") << setw(2) << m_Day;
        return ostr;
    }

    ostream &operator<<(ostream &ostr, const Date &date)
    {
        // Output stream operator overload for Date objects.
        return date.write(ostr);
    }

    istream &operator>>(istream &istr, Date &date)
    {
        // Input stream operator overload for Date objects.
        return date.read(istr);
    }
}
