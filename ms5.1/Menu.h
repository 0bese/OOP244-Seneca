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

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>

namespace sdds
{

    class Menu
    {

        char *m_options{};
        unsigned int m_numOptions;

    public:
        Menu();
        virtual ~Menu();

        unsigned int run() const;

        Menu(const Menu &M) = delete;
        Menu &operator=(const Menu &M) = delete;
        Menu(unsigned int numOptions, const char *options);

        Menu &set(unsigned int numOptions, const char *options);
    };
}

#endif //! SDDS_MENU_H_
