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

#ifndef _SDDS_PERISHABLE_H
#define _SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"
namespace sdds
{
    // Derived class inherited from Item
    class Perishable : public Item
    {
        Date expiryDate;
        char *instructions = nullptr;

    public:
        // Default Constructor
        Perishable();
        // Destructor
        ~Perishable();
        // Copy Constructor
        Perishable(const Perishable &source);
        // Copy Assignment Operator
        Perishable &operator=(const Perishable &source);
        // Overrided bool Function
        operator bool() const;
        // Query to return a const reference to expiry Date
        const Date &expiry() const;
        // Overrided readSku function
        int readSku(std::istream &is);
        // Overrided read function
        std::istream &read(std::istream &is);
        // Overrided display function
        std::ostream &display(std::ostream &ostr) const;
        // OVerrided save function
        std::ofstream &save(std::ofstream &ofs) const;
        // Overrided load function
        std::ifstream &load(std::ifstream &ifstr);
    };
}
#endif