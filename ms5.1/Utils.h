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

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <string>
#include <vector>
#include <fstream>

using namespace std;

namespace sdds
{

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

        /*Added Methods for Utils Starts Here*/

        void alocpy(char *&destination, const char *source);
        int getint(const char *prompt = nullptr);
        int getint(int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
        void strcpy(char *des, const char *src);
        int strlen(const char *str);

        /*Added Methods for MS3

        double getdouble(double min, double max, const char* prompt = nullptr);

        */
        int strncmp(const char *s1, const char *s2, int len);
        const char *strstr(const char *str, const char *find);

        int stringLenght(const char *string);
        void copyString(char *destination, const char *source);
        vector<string> split(const string &s, char split_char);
        ifstream &getNextData(ifstream &is, string &field, char separator);
    };

    extern Utils ut;
}

#endif // !SDDS_UTILS_H_