#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include "Menu.h"

namespace sdds
{
    class AidMan
    {
    protected:
        char* fileName;
        Menu option;

    public:
        AidMan(const char* filename = nullptr);
        int menu() const;
        void searchList(const char* menu, int select);
        void run();
        ~AidMan();
    };
}

#endif // SDDS_AIDMAN_H

