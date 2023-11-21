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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "iProduct.h"

using namespace std;
namespace sdds
{
    // Read Stock-Keeping Units before main data entry
    int iProduct::readSku(std::istream &istr)
    {
        cout << "readSku" << endl;
        return 0;
    }
    // Reduces the quantity
    int iProduct::operator-=(int qty)
    {
        cout << "operator-=" << endl;
        return 0;
    }
    // Increases the quantity
    int iProduct::operator+=(int qty)
    {
        cout << "operator+=" << endl;
        return 0;
    }
    // Returns the price of the produce
    iProduct::operator double() const
    {
        cout << "operator double" << endl;
        return 0.;
    }
    // Returns true or false if the iProduct is in a good state
    iProduct::operator bool() const
    {
        cout << "operator bool" << endl;
        return false;
    }
    // Returns the number of products needed
    int iProduct::qtyNeeded() const
    {
        cout << "qtyNeeded" << endl;
        return 0;
    }
    // Returns the quantity
    int iProduct::qty() const
    {
        cout << "qty" << endl;
        return 0;
    }
    // Determines if the iProduct is displayed in a linear format or descriptive format
    void iProduct::linear(bool isLinear)
    {
        cout << "Linear" << endl;
    }
    // Saves the iProduct into a file
    std::ofstream &iProduct::save(std::ofstream &ofstr) const
    {
        cout << "save" << endl;
        return ofstr;
    }
    // Loads an iProduct from a file
    std::ifstream &iProduct::load(std::ifstream &ifstr)
    {
        cout << "load" << endl;
        return ifstr;
    }
    // Displays the iProduct on the screen
    std::ostream &iProduct::display(std::ostream &ostr) const
    {
        operator bool();
        operator double();
        qtyNeeded();
        qty();
        operator==("");
        operator==(2);
        return ostr;
    }
    // reads the iProduct from the console
    std::istream &iProduct::read(std::istream &istr)
    {
        operator+=(1);
        operator-=(1);
        readSku(istr);
        linear(true);
        test = new char[2345];
        return istr;
    }
    // Returns true if the sku is a match to the iProduct's sku
    bool iProduct::operator==(int sku) const
    {
        cout << "operator==" << endl;
        return false;
    }
    // Returns true if the description is found in the iPorduct's description
    bool iProduct::operator==(const char *description) const
    {
        cout << "operator==(cosnt char*)" << endl;
        return false;
    }
    iProduct::~iProduct()
    {
        delete[] test;
    }
    std::ostream &operator<<(std::ostream &os, const iProduct &prod)
    {
        return prod.display(os);
    }
    std::istream &operator>>(std::istream &is, iProduct &prod)
    {
        return prod.read(is);
    }
}