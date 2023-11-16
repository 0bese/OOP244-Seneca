/*
    ==================================================
    Mile Stone 2
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/11/16
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include "Menu.h"

namespace sdds
{
    class AidMan : public Menu
    {
    private:
        char *fileName;
        Menu option;

    public:
        AidMan(const char *filename = nullptr);
        int menu() const;
        void searchList(const char *menu, int select);
        void run();
        ~AidMan();
    };
}

#endif // SDDS_AIDMAN_H
