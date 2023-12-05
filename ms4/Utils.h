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

#ifndef _SDDS_UTILS_H
#define _SDDS_UTILIS_H
#include <iostream>
#include <cstring>
namespace sdds
{
    //
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils
    {
        bool m_testMode = false;

    public:
        void getSystemDate(int *year = nullptr, int *mon = nullptr, int *day = nullptr);
        int daysOfMon(int mon, int year) const;
        void testMode(bool testmode = true);
        void alocpy(char *&destination, const char *source);
        int getint(const char *prompt = nullptr);
        int getint(int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
    };
    extern Utils ut;
}
#endif
