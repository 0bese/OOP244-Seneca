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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <limits>
#include "Item.h"
#include "Perishable.h"
#include "Date.h"
#include "Status.h"
namespace sdds
{

    Perishable::Perishable() : Item()
    {
        instructions = nullptr;
    }
    // Destructor
    Perishable::~Perishable()
    {
        delete[] instructions;
    }
    // Copy Constructor
    Perishable::Perishable(const Perishable &source) : Item(source)
    {
        instructions = nullptr;
        *this = source;
    }
    // Copy Assignment Operator
    Perishable &Perishable::operator=(const Perishable &source)
    {
        if (this != &source)
        {
            Item::operator=(source);
            delete[] instructions;
            instructions = nullptr;
            expiryDate = source.expiryDate;
            if (source.instructions != nullptr)
            {
                instructions = new char[strlen(source.instructions) + 1];
                strcpy(instructions, source.instructions);
            }
        }
        return *this;
    }

    // Overrided bool Function
    Perishable::operator bool() const
    {
        return stockUnit != 0;
    }
    // Query thar returns the const reference to Expiry Date
    const Date &Perishable::expiry() const
    {
        return expiryDate;
    }
    // Overrided readSku function
    int Perishable::readSku(std::istream &is)
    {
        statusObj.clear();
        bool quitLoop = false;
        cout << "SKU: ";
        while (!quitLoop)
        {

            if (!(is >> stockUnit))
            {
                cout << "Invalid Integer, retry: ";
                is.clear();
                is.ignore(1000, '\n');
            }
            else if (stockUnit < 10000 || stockUnit > 39999)
            {
                std::cout << "Value out of range [10000<=val<=39999]: ";
            }

            else
            {
                quitLoop = true;
            }
        }

        return stockUnit;
    }
    // Overrided read function
    std::istream &Perishable::read(std::istream &is)
    {
        Item::read(is);
        delete[] instructions;
        instructions = nullptr;
        cout << "Expiry date (YYMMDD): ";
        is >> expiryDate;
        is.ignore();
        cout << "Handling Instructions, ENTER to skip: ";
        char character = is.peek();
        if (character != '\n')
        {
            instructions = new char[2000];
            is.getline(instructions, 2000);
        }
        else
        {
            is.ignore();
        }
        if (is.fail())
        {
            statusObj = "Perishable console date enry failed!";
        }
        return is;
    }
    // Overrided display function
    std::ostream &Perishable::display(std::ostream &os) const
    {
        if (!statusObj)
        {
            os << statusObj;
        }
        else
        {
            if (Item::linear())
            {
                Item::display(os);
                os << (instructions && *instructions ? '*' : ' ');
                os << expiryDate;
            }
            else
            {
                os << "Perishable ";
                Item::display(os);
                os << "Expiry date: ";
                os << expiryDate;
                std::cout << std::endl;
                if (instructions && *instructions)
                {
                    os << "Handling Instructions: " << instructions << endl;
                }
            }
        }
        return os;
    }
    // Overrided save function
    std::ofstream &Perishable::save(std::ofstream &ofs) const
    {
        if (statusObj)
        {
            Item::save(ofs);
            if (instructions != nullptr)
            {
                ofs << instructions << "\t";
            }
            else
            {
                ofs << "\t";
            }
            ofs << setw(2) << setfill('0') << (expiryDate.year % 100) << setw(2) << setfill('0') << expiryDate.month << setw(2)
                << setw(2) << setfill('0') << expiryDate.day << "\t";
            return ofs;
        }
        return ofs;
    }
    // Overrided load function
    std::ifstream &Perishable::load(std::ifstream &ifs)
    {
        Item::load(ifs);
        if (ifs.fail())
        {
            statusObj = "Input file stream read (perishable) failed!";
            return ifs;
        }
        delete[] instructions;
        instructions = nullptr;
        char input[1000];
        if (ifs.getline(input, 1000, '\t') && isalpha(input[0]))
        {
            instructions = new char[strlen(input) + 1];
            strcpy(instructions, input);
        }
        ifs >> expiryDate;
        ifs.ignore();

        return ifs;
    }
}