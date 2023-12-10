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

#include <iostream>
#include <vector>
#include "Item.h"
#include "Utils.h"
#include <limits>
#define MAX_CHAR_LENGHT 1000

using namespace std;
namespace sdds
{

    // Default constructor for the Item class.
    Item::Item() : m_price(0.0), m_qty(0), m_qtyNeeded(0), m_desc(nullptr), m_linear(
                                                                                false),
                   m_state(nullptr), m_sku(0)
    {
        m_state = "Empty";
    }

    // Copy constructor for the Item class.
    Item::Item(const Item &I)
    {
        // Copy member variables from the source object (I) to the current object.
        m_price = I.m_price;
        m_qty = I.m_qty;
        m_qtyNeeded = I.m_qtyNeeded;

        // Allocate memory and copy the description from the source object.
        ut.alocpy(m_desc, I.m_desc);

        // Copy the linear flag and state from the source object.
        m_linear = I.m_linear;
        m_state = I.m_state;

        // Copy the SKU from the source object.
        m_sku = I.m_sku;
    }

    // Assignment operator for the Item class.
    Item &Item::operator=(const Item &I)
    {
        // Check for self-assignment.
        if (this != &I)
        {
            // Copy member variables from the source object (I) to the current object.
            m_price = I.m_price;
            m_qty = I.m_qty;
            m_qtyNeeded = I.m_qtyNeeded;

            // Allocate memory and copy the description from the source object.
            ut.alocpy(m_desc, I.m_desc);

            // Copy the linear flag and state from the source object.
            m_linear = I.m_linear;
            m_state = I.m_state;

            // Copy the SKU from the source object.
            m_sku = I.m_sku;
        }
        // Return a reference to the current object.
        return *this;
    }

    // Destructor for the Item class.
    Item::~Item()
    {
        // Deallocate memory for the description.
        if (m_desc)
        {
            delete[] m_desc;
        }
        // Set the description pointer to nullptr to avoid dangling pointers.
        m_desc = nullptr;
    }

    // the qtyNeeded method returns the needed-quantity attribute
    int Item::qtyNeeded() const
    {
        return m_qtyNeeded;
    }

    // the qty method returns the on-hand quantity attribute
    int Item::qty() const
    {
        return m_qty;
    }

    // the double conversion operator overload returns the price
    Item::operator double() const
    {
        return m_price;
    }

    // the boolean conversion operator overload returns the state of the object being good.
    Item::operator bool() const
    {
        return static_cast<bool>(m_state);
    }

    // Subtraction assignment operator for Item class.
    int Item::operator-=(int qty)
    {
        // Decrease the quantity by the specified amount.
        m_qty -= qty;
        // Return the updated quantity.
        return m_qty;
    }

    // Addition assignment operator for Item class.
    int Item::operator+=(int qty)
    {
        // Increase the quantity by the specified amount.
        m_qty += qty;
        // Return the updated quantity.
        return m_qty;
    }

    // Set the linear flag for Item class.
    void Item::linear(bool islinear)
    {
        // Set the linear flag based on the provided parameter.
        m_linear = islinear;
    }

    // Clear function for Item class.
    void Item::clear()
    {
        // Clear the state of the item.
        m_state.clear();
    }

    // Equality comparison operator for Item class with integer SKU.
    bool Item::operator==(int sku) const
    {
        // Check if the provided SKU matches the item's SKU.
        return sku == m_sku;
    }

    bool Item::linear() const
    {
        return m_linear;
    }

    // Constant character pointer comparison searches in the description of the Item for the appearance of the received Cstring. If a match was found it returns true. If any of the descriptions (The Items or the received value) are null or the match is not found, it will return false.
    bool Item::operator==(const char *description) const
    {
        string data = string(m_desc);
        string search = string(description);
        size_t position = data.find(search);
        return (string::npos != position);
    }

    // Save function for Item class, writes the object's data to an output file stream.
    ofstream &Item::save(ofstream &ofstr) const
    {
        // Check if the state of the Item is good
        if (m_state)
            // Write SKU, description, on-hand quantity, needed quantity, and price in tab-separated format
            ofstr << m_sku << '\t' << m_desc << '\t' << m_qty << '\t'
                  << m_qtyNeeded << '\t' << fixed << setprecision(2) << m_price;

        return ofstr;
    }

    ifstream &Item::load(ifstream &ifstr)
    {
        // Deallocate existing description memory.
        delete[] m_desc;
        m_desc = nullptr;

        // Temporary string to store parsed data.
        string temp = "";

        // Read SKU and handle conversion errors.
        ut.getNextData(ifstr, temp, '\t');
        try
        {
            m_sku = stoi(temp);
        }
        catch (exception &e)
        {
        }

        // Read description and allocate memory.
        temp.clear();
        ut.getNextData(ifstr, temp, '\t');
        m_desc = new char[temp.size() + 1];
        strcpy(m_desc, temp.c_str());

        // Read quantity and handle conversion errors.
        temp.clear();
        ut.getNextData(ifstr, temp, '\t');
        try
        {
            m_qty = stoi(temp);
        }
        catch (exception &e)
        {
        }

        // Read quantity needed and handle conversion errors.
        temp.clear();
        ut.getNextData(ifstr, temp, '\t');
        try
        {
            m_qtyNeeded = stoi(temp);
        }
        catch (exception &e)
        {
        }

        // Read price and handle conversion errors.
        temp.clear();
        ut.getNextData(ifstr, temp, '\t');
        try
        {
            m_price = stod(temp);
        }
        catch (exception &e)
        {
        }

        // Check for input file stream errors and update the state.
        if (ifstr.fail())
            m_state = "Input file stream read failed!";
        else
            m_state.clear();

        // Return the input file stream reference.
        return ifstr;
    }

    // Display function for Item class, outputs the object's data to an output stream.
    ostream &Item::display(ostream &ostr) const
    {

        if (!m_state)
        {
            ostr << m_state;
        }

        else
        {
            if (m_linear)
            {
                // Display in linear format
                ostr << setw(5) << setfill('0') << m_sku << " | " << setw(35)
                     << left << setfill(' ')
                     << (m_desc ? (strlen(m_desc) > 35 ? string(m_desc, 35) : m_desc) : "") << " | "
                     << setw(4) << right << m_qty << " | " << setw(4)
                     << m_qtyNeeded << " | " << fixed << setprecision(2)
                     << setw(7) << m_price << " |";
            }
            else
            {

                ostr << "AMA Item:" << endl
                     << m_sku << ": " << (m_desc ? m_desc : "") << endl
                     << "Quantity Needed: " << m_qtyNeeded << endl
                     << "Quantity Available: " << m_qty << endl
                     << "Unit Price: $" << fixed << setprecision(2) << m_price << endl
                     << "Needed Purchase Fund: $" << fixed
                     << setprecision(2) << (m_qtyNeeded - m_qty) * m_price
                     << endl;
            }
        }
        return ostr;
    }

    // Reads the SKU from the screen with the prompt "SKU: ". It makes sure the SKU number begins with digits 4 to 9 and it is 5 digits long.
    int Item::readSku(istream &istr)
    {
        int sku = 0;
        bool validInput = false;

        cout << "SKU: ";
        do
        {
            istr >> sku;

            // Check if the input is an integer
            if (istr.fail())
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Integer, retry: ";
            }

            else if (sku < 40000 || sku > 99999)
                cout << "Value out of range [40000<=val<=99999]: ";
            else
                validInput = true;

        } while (!validInput);

        m_sku = sku;

        return sku;
    }

    // After deleting the description and clearing the state. read will first prompt the user with the title "AMA Item" and then displays the SKU and reads the rest of the information in a foolproof way (the same as SKU).
    istream &Item::read(istream &istr)
    {
        if (m_desc != nullptr)
        {
            delete[] m_desc;
            m_desc = nullptr;
        }

        m_state.clear();
        cout << "AMA Item:" << endl;
        readSku(istr);
        istr.ignore();

        cout << "Description: ";
        m_desc = new char[MAX_CHAR_LENGHT];
        istr.getline(m_desc, MAX_CHAR_LENGHT);

        cout << "Quantity Needed: ";
        istr >> m_qtyNeeded;

        while (true)
        {
            if (istr.fail())
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Integer, retry: ";
            }

            else if (m_qtyNeeded < 1 || m_qtyNeeded > 9999)
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Value out of range [1<=val<=9999]: ";
            }

            else
                break;

            istr >> m_qtyNeeded;
        }

        // Read Quantity On Hand
        cout << "Quantity On Hand: ";
        istr >> m_qty;
        while (true)
        {
            if (istr.fail())
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Integer, retry: ";
            }
            else if (m_qty < 0 || m_qty > 22)
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Value out of range [0<=val<=22]: ";
            }
            else
                break;

            istr >> m_qty;
        }

        // Read Unit Price
        cout << "Unit Price: $";
        istr >> m_price;
        while (true)
        {
            if (istr.fail())
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number, retry: ";
            }
            else if (m_price < 0 || m_price > 9999)
            {
                istr.clear();
                istr.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Value out of range [0.00<=val<=9999.00]: ";
            }
            else
                break;

            istr >> m_price;
        }

        // Check if the istream fails during reading
        if (istr.fail())
            m_state = "Console entry failed!";
        return istr;
    }
}
