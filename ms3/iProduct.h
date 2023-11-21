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

#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H

namespace sdds
{
    class iProduct
    {
    private:
        char *test{};

    public:
        virtual int readSku(std::istream &is);
        virtual int operator-=(int value);
        virtual int operator+=(int value);
        virtual operator double() const;
        virtual operator bool() const;
        virtual int qtyNeeded() const;
        virtual int qty() const;
        virtual void linear(bool isLinear);
        virtual std::ofstream &save(std::ofstream &ofstr) const;
        virtual std::ifstream &load(std::ifstream &ifstr);
        virtual std::ostream &display(std::ostream &ostr) const;
        virtual std::istream &read(std::istream &istr);
        virtual bool operator==(int sku) const;
        virtual bool operator==(const char *description) const;
        virtual ~iProduct();
    };
    std::ostream &operator<<(std::ostream &os, const iProduct &prod);
    std::istream &operator>>(std::istream &is, iProduct &prod);
}
#endif // IPRODUCT_H