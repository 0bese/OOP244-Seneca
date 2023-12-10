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
#include <ctime>
#include <cctype>
#include <cstring>
#include <limits>
#include "Utils.h"
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
namespace sdds
{

    Utils ut;

    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }

    void Utils::getSystemDate(int *year, int *mon, int *day)
    {
        if (m_testMode)
        {
            if (day)
                *day = sdds_testDay;
            if (mon)
                *mon = sdds_testMon;
            if (year)
                *year = sdds_testYear;
        }

        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day)
                *day = lt.tm_mday;
            if (mon)
                *mon = lt.tm_mon + 1;
            if (year)
                *year = lt.tm_year + 1900;
        }
    }

    int Utils::daysOfMon(int month, int year) const
    {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    // Function to allocate memory and copy the contents of a source string to a destination string.
    void Utils::alocpy(char *&destination, const char *source)
    {

        delete[] destination;

        if (source)
        {
            size_t length = std::strlen(source) + 1;
            destination = new char[length];
            std::copy(source, source + length, destination);
        }

        else
        {
            destination = nullptr;
        }
    }

    int Utils::getint(const char *prompt)
    {
        int input = 0;

        // Check if a prompt message is provided.
        if (prompt)
        {
            // Continue prompting until a valid input is provided.
            while (true)
            {
                std::cout << prompt;
                std::cin >> input;

                // Check for input failure (non-integer input).
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid Integer, retry: ";
                }
                else
                {
                    // Clear the input stream and break out of the loop.
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }
        }

        // Return the entered integer value.
        return input;
    }

    // Function to get an integer within a specified range, with optional prompt and error message.
    int Utils::getint(int min, int max, const char *prompt, const char *errMes)
    {
        int val = 0;

        while (true)
        {
            val = getint(prompt);

            if (val >= min && val <= max)
            {
                break;
            }

            else
            {
                if (errMes)
                {
                    std::cout << errMes << ", retry: ";
                }

                else
                {
                    std::cout << "Value out of range [" << min << "<=val<=" << max << "], retry: ";
                }
            }
        }

        return val;
    }

    // Function to copy the contents of a source string to a destination string.
    void Utils::strcpy(char *des, const char *src)
    {
        int i;
        for (i = 0; src[i]; i++)
            des[i] = src[i];
        des[i] = 0;
    }

    // Function to calculate the length of a string.
    int Utils::strlen(const char *str)
    {
        int len;
        for (len = 0; str[len]; len++)
            ;
        return len;
    }

    // Find the first occurrence of a substring in a string.
    const char *Utils::strstr(const char *str, const char *find)
    {
        const char *faddress = nullptr;
        int i, flen = strlen(find), slen = strlen(str);

        // Iterate through the string to find the substring.
        for (i = 0; i <= slen - flen && strncmp(&str[i], find, flen); i++)
            ;

        // Set the address if the substring is found.
        if (i <= slen - flen)
        {
            faddress = &str[i];
        }

        return faddress;
    }

    // Compare the first 'len' characters of two strings.
    int Utils::strncmp(const char *s1, const char *s2, int len)
    {
        int i = 0;

        // Iterate through the strings to compare characters.
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i])
        {
            i++;
        }

        return s1[i] - s2[i];
    }

    int Utils::stringLenght(const char *string)
    {

        const char *start = string;
        while (*string)
        {
            string++;
        }
        return static_cast<int>(string - start);
    }

    void Utils::copyString(char *destination, const char *source)
    {
        while (*source)
        {
            *destination++ = *source++;
        }
        *destination = '\0';
    }

    vector<string> Utils::split(const string &s, char split_char)
    {
        vector<std::string> vec;
        istringstream iss(s);
        string token;
        while (getline(iss, token, split_char))
            vec.push_back(token);
        return vec;
    }

    ifstream &Utils::getNextData(ifstream &is, string &field, char separator)
    {
        char ch;
        field.clear();

        // Read characters until the separator or the end of the stream
        while (is.get(ch) && ch != separator && ch != '\n')
            field.push_back(ch);

        return is;
    }

}