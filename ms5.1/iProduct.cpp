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

#include "iProduct.h"

namespace sdds
{
    // Overloaded output stream operator for iProduct, invokes display method.
    std::ostream &operator<<(std::ostream &os, const iProduct &product)
    {
        // Invoke the display method of the iProduct object to output its data.
        return product.display(os);
    }

    // Overloaded input stream operator for iProduct, invokes read method.
    std::istream &operator>>(std::istream &is, iProduct &product)
    {
        // Invoke the read method of the iProduct object to read data from the input stream.
        return product.read(is);
    }

}