/*
    ==================================================
    Mile Stone 3
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/11/21
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"

namespace sdds
{
    class Item : public iProduct
    {
    private:
        double Price;
        int Quantity;
        int neededQty;
        char *Description;
        bool flag;

    protected:
        Status state;
        int unitNum;
        void linear(bool valid);

    public:
        Item();
        int readSku(std::istream &is);
        int qtyNeeded() const;
        int qty() const;
        operator double() const;
        operator bool() const;
        int operator-=(int value);
        int operator+=(int value);
        void linearModi();
        bool operator==(int sku) const;
        bool operator==(const char *description) const;
        std::ofstream &save(std::ofstream &ofstr) const;
        std::ifstream &load(std::ifstream &ifstr);
        std::ostream &display(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        void clear();
        virtual ~Item();
    };

    class Perishable
    {
    private:
        int expiryDate;
    };

}

#endif // ITEM_H