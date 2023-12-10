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

#ifndef SDDS_AIDMAN_
#define SDDS_AIDMAN_
#include "Menu.h"
#include "iProduct.h"

namespace sdds
{

    const int sdds_max_num_items = 100;

    class AidMan
    {

        char *m_fileName;
        Menu m_themainMenu;

        unsigned int menu() const;

        iProduct *m_iproduct[sdds_max_num_items] = {0};
        int m_numOfIproduct;

    public:
        AidMan();
        AidMan(const AidMan &a) = delete;

        AidMan &operator=(const AidMan &A) = delete;

        virtual ~AidMan();

        void run();
        void save();
        void deallocate();
        void load();
        int list(const char *sub_desc = nullptr);
    };
}
#endif //! SDDS_AIDMAN_