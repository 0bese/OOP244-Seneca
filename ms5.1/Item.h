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

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "iProduct.h"
#include "Status.h"

namespace sdds
{

    class Item : public iProduct
    {

    private:
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char *m_desc;
        bool m_linear;

    protected:
        Status m_state;
        int m_sku;
        bool linear() const;

    public:
        Item();
        Item(const Item &other);

        Item &operator=(const Item &I);
        virtual ~Item() override;

        virtual int qtyNeeded() const override;
        virtual int qty() const override;

        virtual operator double() const override;
        virtual operator bool() const override;

        virtual int operator-=(int qty) override;
        virtual int operator+=(int qty) override;

        virtual void linear(bool isLinear) override;

        void clear();

        virtual bool operator==(int sku) const override;
        virtual bool operator==(const char *description) const override;

        virtual std::ofstream &save(std::ofstream &ofstr) const override;
        virtual std::ifstream &load(std::ifstream &ifstr) override;
        virtual std::ostream &display(std::ostream &ostr) const override;
        virtual std::istream &read(std::istream &istr) override;

        int readSku(std::istream &istr) override;
    };

}

#endif //! SDDS_ITEM_H_
