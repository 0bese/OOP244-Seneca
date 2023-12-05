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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <ostream>
#include "iProduct.h"
#include "Status.h"
namespace sdds
{
    class Item : public iProduct
    {
    protected:
        double price;
        int quantity;
        int neededQty;
        char *desc;
        bool Linear;
        Status statusObj;
        int stockUnit;
        bool linear() const;

    public:
        // Default constuctor
        Item();
        // Copy Assignment operator
        Item &operator=(const Item &itemObj);
        // Copy Constructor
        Item(const Item &itemObj);
        // Clears the state
        void clear();
        // Compares the value with the SKU
        bool operator==(int sku) const;
        // Returns the needed quantity
        int qtyNeeded() const;
        // Returns the on-hand quantity
        int qty() const;
        // Returns the double conversion operator that returns price
        operator double() const;
        // Returns the boolean conversion operator that returns the state of the object
        operator bool() const;
        // Returns the decreased quantity
        int operator-=(int value);
        // Returns the increased quantity
        int operator+=(int value);
        // Returns the linear flag of the item
        void linear(bool isItLinear);

        // Compares the strings passed as an argumen
        bool operator==(const char *descString) const;
        // It will write SKU, description, on-hand quantity, needed quantity and price in tab-separated format.
        std::ofstream &save(std::ofstream &ofs) const;
        // It reads the information from the file
        std::ifstream &load(std::ifstream &ifs);
        // Displays the state
        std::ostream &display(std::ostream &os) const;
        // Reads sku unit from the user
        int readSku(std::istream &is);
        // Reads the rest information in a foolproof way
        std::istream &read(std::istream &is);
        // Destructor
        ~Item();
    };

}
#endif
