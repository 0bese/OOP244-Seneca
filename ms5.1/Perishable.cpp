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

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Item.h"
#include "Perishable.h"
#include <sstream>
#include <limits>
#include "Utils.h"

#define MAX_CHAR_LENGHT 1000

using namespace std;

namespace sdds
{
    // Implementation of the Perishable class, which is derived from the Item class.
    // This class represents perishable items and includes additional attributes
    // such as handling instructions and expiry date.

    // Constructor initializes the Perishable object with default values,
    // including a default expiry date of December 12, 2023.
    Perishable::Perishable() : Item(),
                               p_instructions(nullptr), p_expiry(Date(23, 12, 12))
    {
    }

    // Destructor clears dynamically allocated memory and performs cleanup.
    Perishable::~Perishable()
    {
        clear();
    }

    // Copy constructor creates a deep copy of the Perishable object.
    Perishable::Perishable(const Perishable &other) : Item(other)
    {
        if (other.p_instructions)
        {
            p_instructions = new char[strlen(other.p_instructions) + 1];
            strcpy(p_instructions, other.p_instructions);
        }
        else
        {
            p_instructions = nullptr;
        }
        p_expiry = other.p_expiry;
    }

    // Assignment operator overloading for assigning the values of another Perishable object.
    Perishable &Perishable::operator=(const Perishable &other)
    {
        if (this != &other)
        {
            Item::operator=(other);
            clear(); // Clear existing data before copying new data.
            if (other.p_instructions)
            {
                p_instructions = new char[strlen(other.p_instructions) + 1];
                strcpy(p_instructions, other.p_instructions);
            }
            else
            {
                p_instructions = nullptr;
            }
            p_expiry = other.p_expiry;
        }
        return *this;
    }

    // Getter function for retrieving the expiry date of the perishable item.
    const Date &Perishable::expiry() const
    {
        return p_expiry;
    }

    // Display function to output the Perishable item information.
    // The format of the output depends on the state and linearity of the item.
    ostream &Perishable::display(ostream &ostr) const
    {
        // Check if the item is in a valid state.
        if (!m_state)
        {
            ostr << m_state;
        }
        else
        {
            if (Item::linear())
            {
                Item::display(ostr);
                ostr << (p_instructions != nullptr && strlen(p_instructions) > 1 ? "*" : " ");
                ostr << p_expiry;
            }
            else
            {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: " << p_expiry << endl;
                if (p_instructions != nullptr && (strlen(p_instructions) > 1))
                {
                    ostr << "Handling Instructions: " << p_instructions << endl;
                }
            }
        }
        return ostr;
    }

    // Save function to write Perishable item information to an output file stream.
    ofstream &Perishable::save(ofstream &ofstr) const
    {
        Item::save(ofstr);

        if (p_instructions != nullptr)
            ofstr << '\t' << p_instructions;
        else
            ofstr << '\t';

        Date copy = p_expiry;
        copy.formatted(false);
        ofstr << '\t' << copy;
        return ofstr;
    }

    // Load function to read Perishable item information from an input file stream.
    ifstream &Perishable::load(ifstream &ifstr)
    {
        Item::load(ifstr);
        clear(); // Clear existing data before loading new data.
        string temp;
        ut.getNextData(ifstr, temp, '\t');
        ut.alocpy(p_instructions, temp.c_str());

        temp.clear();
        ut.getNextData(ifstr, temp, '\t');
        istringstream istr(temp);
        p_expiry.read(istr);

        if (ifstr.fail())
            m_state = "Input file stream read (perishable) failed!";

        return ifstr;
    }

    // Read function to input Perishable item information from the console.
    istream &Perishable::read(istream &istr)
    {
        clear();
        Item::read(istr);

        if (!istr.fail())
        {
            cout << "Expiry date (YYMMDD): ";
            istr >> p_expiry;
            if (istr.fail())
            {
                m_state = "Perishable console date entry failed!";
            }
            else
            {
                istr.ignore();
                cout << "Handling Instructions, ENTER to skip: ";
                char temp[1000];
                istr.getline(temp, 1000);
                if (temp[0] != '\0')
                {
                    p_instructions = new char[strlen(temp) + 1];
                    strcpy(p_instructions, temp);
                }
                else
                {
                    p_instructions = nullptr;
                }
            }
        }

        return istr;
    }

    // Function to read the SKU (Stock Keeping Unit) from the console.
    // Ensures that the SKU is within the specified range.
    int Perishable::readSku(istream &istr)
    {
        int sku = 0;
        bool validInput = false;

        cout << "SKU: ";
        do
        {
            istr >> sku;

            if (istr.fail())
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Integer, retry: ";
            }
            else if (sku < 10000 || sku > 39999)
                cout << "Value out of range [10000<=val<=39999]: ";
            else
                validInput = true;

        } while (!validInput);

        m_sku = sku;

        return sku;
    }

    // Function to clear dynamically allocated memory and reset the state.
    void Perishable::clear()
    {
        if (p_instructions)
        {
            delete[] p_instructions;
            p_instructions = nullptr;
        }
        m_state.clear();
    }

}