/*
    ==================================================
    Mile Stone 4
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/12/3
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#include <iostream>
#include "iProduct.h"
using namespace std;
namespace sdds
{

    std::ostream &operator<<(std::ostream &os, const iProduct &obj)
    {
        return obj.display(os);
    }

    std::istream &operator>>(std::istream &is, iProduct &obj)
    {
        return obj.read(is);
    }
}