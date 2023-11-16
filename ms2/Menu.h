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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include "Utils.h"
namespace sdds
{
    const int MAX_MENU = 15;
    class Menu : public Utils
    {
        int numOfOption;

    protected:
        char *menuContent;

    public:
        void setEmpty();
        Menu(const char *menu = nullptr);
        int run() const;
        const char *getMenuContent() const;
        int getNumOfOpt() const;
        Menu &operator=(int num);
        Menu &operator=(const char *menu);
        Menu &clear();
        bool isValid() const;
        ~Menu();
    };

}

#endif // SDDS_MENU_H
