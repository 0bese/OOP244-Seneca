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

#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <limits>
#include "Utils.h"

namespace sdds
{

    Item::Item() : price(0.0), quantity(0), neededQty(0), desc(nullptr), Linear(false), statusObj(), stockUnit(0) {}

    // Copy Assignment operator
    Item::Item(const Item &obj) : price(obj.price), quantity(obj.quantity), neededQty(obj.neededQty),
                                  Linear(obj.Linear), statusObj(obj.statusObj), stockUnit(obj.stockUnit)
    {
        if (obj.desc != nullptr)
        {
            desc = new char[strlen(obj.desc) + 1];
            strcpy(desc, obj.desc);
        }
        else
        {
            desc = nullptr;
        }
    }
    // Copy Constructor
    Item &Item::operator=(const Item &src)
    {
        if (this != &src)
        {
            price = src.price;
            quantity = src.quantity;
            neededQty = src.neededQty;
            Linear = src.Linear;
            statusObj = src.statusObj;
            stockUnit = src.stockUnit;

            delete[] desc;

            if (src.desc != nullptr)
            {
                desc = new char[strlen(src.desc) + 1];
                strcpy(desc, src.desc);
            }
            else
            {
                desc = nullptr;
            }
        }
        return *this;
    }
    // Clears the state
    void Item::clear()
    {
        statusObj.clear();
    }
    // Compares the value with the SKU
    bool Item::operator==(int sku) const
    {
        return stockUnit == sku;
    }
    // Returns the needed quantity
    int Item::qtyNeeded() const
    {
        return neededQty;
    }
    // Returns the on-hand quantity
    int Item::qty() const
    {
        return quantity;
    }
    // Returns the double conversion operator that returns price
    Item::operator double() const
    {
        return price;
    }
    // Returns the boolean conversion operator that returns the state of the object
    Item::operator bool() const
    {
        return statusObj;
    }
    // Returns the decreased quantity
    int Item::operator-=(int qty)
    {
        quantity -= qty;
        return quantity;
    }

    // Returns the increased quantity
    int Item::operator+=(int qty)
    {
        quantity += qty;
        return quantity;
    }
    // Returns the linear flag of the item
    void Item::linear(bool isItLinear)
    {
        Linear = isItLinear;
    }

    // Compares the strings passed as an argumen
    bool Item::operator==(const char *description) const
    {
        if (description == nullptr || desc == nullptr)
        {
            return false;
        }

        if (isdigit(description[0]) && std::stoi(description) == stockUnit)
        {
            return true;
        }

        // Check if the description contains the provided Cstring
        if (strstr(desc, description) != nullptr)
        {
            return true;
        }

        return false;
    }
    // It will write SKU, description, on-hand quantity, needed quantity and price in tab-separated format.
    std::ofstream &Item::save(std::ofstream &ofstr) const
    {
        if (statusObj)
        {
            ofstr << stockUnit << "\t" << desc << "\t" << quantity << "\t" << neededQty << "\t"
                  << fixed << setprecision(2) << price << "\t";
        }
        return ofstr;
    }
    // It reads the information from the file
    std::ifstream &Item::load(std::ifstream &ifstr)
    {
        delete[] desc;

        desc = nullptr;
        ifstr >> stockUnit;
        if (ifstr.fail())
        {
            statusObj = "Input file stream read failed!";
        }
        else
        {
            char stringDesc[1000];
            ifstr.ignore();
            ifstr.getline(stringDesc, 1000, '\t');
            desc = new char[strlen(stringDesc) + 1];
            strcpy(desc, stringDesc);
            ifstr >> quantity;
            ifstr.ignore();

            ifstr >> neededQty;
            ifstr.ignore();

            ifstr >> price;
            ifstr.ignore(1);
        }
        return ifstr;
    }
    // Displays the state
    std::ostream &Item::display(std::ostream &ostr) const
    {
        if (!statusObj)
        {
            ostr << statusObj;
        }
        else
        {
            if (Linear)
            {
                ostr << std::setw(5) << stockUnit << " | "
                     << std::left << std::setw(35) << std::setfill(' ') << (std::strlen(desc) > 35 ? std::string(desc, 35) : desc)
                     << " | " << std::right << std::setw(4) << quantity << " | "
                     << std::right << std::setw(4) << neededQty << " | "
                     << std::right << std::setw(7) << std::setprecision(2) << price << " |";
            }
            else
            {
                ostr << "AMA Item:" << std::endl
                     << std::setw(5) << stockUnit << ": "
                     << desc << std::endl
                     << "Quantity Needed: " << neededQty << std::endl
                     << "Quantity Available: " << quantity << std::endl
                     << "Unit Price: $" << std::fixed << std::setprecision(2) << price << std::endl
                     << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (neededQty * price) - (quantity * price) << std::endl;
            }
        }
        return ostr;
    }
    // Reads sku unit from the user
    int Item::readSku(std::istream &istr)
    {
        statusObj.clear();
        bool quitLoop = false;
        cout << "SKU: ";
        while (!quitLoop)
        {

            if (!(istr >> stockUnit))
            {
                cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else if (stockUnit < 40000 || stockUnit > 99999)
            {
                std::cout << "Value out of range [40000<=val<=99999]: ";
            }
            else
            {
                quitLoop = true;
            }
        }

        return stockUnit;
    }
    // Reads the rest information in a foolproof way
    std::istream &Item::read(std::istream &istr)
    {
        delete[] desc;
        desc = nullptr;

        std::cout << "AMA Item:" << std::endl
                  << "SKU: " << stockUnit << std::endl
                  << "Description: ";

        istr.ignore();
        char stringDesc[1000];
        istr.getline(stringDesc, 1000);
        desc = new char[strlen(stringDesc) + 1];
        strcpy(desc, stringDesc);

        bool quitLoop = false;
        std::cout << "Quantity Needed: ";
        while (!quitLoop)
        {

            if (!(istr >> neededQty))
            {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else if (neededQty < 1 || neededQty > 9999)
            {
                std::cout << "Value out of range [1<=val<=9999]: ";
            }
            else
            {
                quitLoop = true;
            }
        }

        quitLoop = false;
        std::cout << "Quantity On Hand: ";
        while (!quitLoop)
        {

            if (!(istr >> quantity))
            {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else if (quantity < 0 || quantity > neededQty)
            {
                std::cout << "Value out of range [0<=val<=22]: ";
            }
            else
            {
                quitLoop = true;
            }
        }

        quitLoop = false;
        std::cout << "Unit Price: $";
        while (!quitLoop)
        {

            if (!(istr >> price))
            {
                std::cout << "Invalid number, retry: ";
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else if (price < 0.0 || price > 9999.0)
            {
                std::cout << "Value out of range [0.00<=val<=9999.00]: ";
            }
            else
            {
                quitLoop = true;
            }
        }

        return istr;
    }

    bool Item::linear() const
    {
        return Linear;
    }

    Item::~Item()
    {
        delete[] desc;
    }
}
