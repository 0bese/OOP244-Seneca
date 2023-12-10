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

#ifndef IPRODUCT_H_
#define IPRODUCT_H_
#include <iostream>
#include <fstream>

namespace sdds
{

    class iProduct
    {

    public:
        virtual ~iProduct() = default;

        virtual int readSku(std::istream &istr) = 0;
        virtual int operator-=(int qty) = 0;
        virtual int operator+=(int qty) = 0;

        virtual operator double() const = 0;
        virtual operator bool() const = 0;

        virtual int qtyNeeded() const = 0;
        virtual int qty() const = 0;

        virtual void linear(bool isLinear) = 0;

        virtual std::ofstream &save(std::ofstream &ofstr) const = 0;
        virtual std::ifstream &load(std::ifstream &ifstr) = 0;
        virtual std::ostream &display(std::ostream &ostr) const = 0;
        virtual std::istream &read(std::istream &istr) = 0;

        virtual bool operator==(int sku) const = 0;
        virtual bool operator==(const char *description) const = 0;

        /*I changed this part. trying out everything i learn to write code efficiently*/
        friend std::ostream &operator<<(std::ostream &os, const iProduct &product);
        friend std::istream &operator>>(std::istream &is, iProduct &product);
    };

}
#endif //! SDDS_IPRODUCT_H_
