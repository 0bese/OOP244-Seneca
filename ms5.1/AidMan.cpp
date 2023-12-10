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
#include <fstream>
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
#include "Perishable.h"
#include "Menu.h"
#include <limits>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

namespace sdds
{

    unsigned int AidMan::menu() const
    {

        // Print header info
        cout << "Aid Management System" << endl
             << "Date: " << Date() << endl
             << "Data file: " << (m_fileName == nullptr ? "No file" : m_fileName) << endl
             << "---------------------------------\n";

        // Run and return menu selection
        return m_themainMenu.run();
    }

    AidMan::AidMan()
    {

        // Configure main menu with options
        m_themainMenu.set(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");

        // Initialize data members
        // m_fileName starts null indicating no file loaded
        m_fileName = nullptr;

        // Number of inventory products starts at 0
        m_numOfIproduct = 0;
    }

    AidMan::~AidMan()
    {

        // Deallocate memory
        delete[] m_fileName;

        // Clean up inventory products
        deallocate();
    }

    void AidMan::run()
    {

        int numList;
        int input;
        // Menu selection variable

        int val = 999;

        do
        {
            // Display menu and get selection

            val = menu();
            // Validate selection if no file loaded

            if (val != 0 && val != 7 && m_fileName == nullptr)
                val = 7;
            switch (val)
            {

            case 0: // Exit application
                cout << "Exiting Program!" << endl;
                save();
                break;

            case 1: // List items
                    // Display list header
                cout << endl
                     << "****List Items****\n";
                // Get and validate item selection
                // Display details if valid
                numList = list();

                if (numList)
                {
                    cout << "Enter row number to display details or <ENTER> to continue:" << endl
                         << "> ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string lineInput;
                    getline(cin, lineInput);
                    stringstream ss(lineInput);

                    if (ss >> input)
                    {

                        if (input >= 1 && input <= numList)
                        {
                            m_iproduct[input - 1]->linear(false);
                            m_iproduct[input - 1]->display(cout);
                            cout << endl;
                        }
                        else
                        {
                            cout << "Value out of range [1<=val<=" << numList << "], retry: ";
                        }
                    }
                }

                cout << endl;
                break;

            case 2: // Add item
                cout << endl
                     << "****Add Item****\n\n";
                break;
            case 3: // Remove item
                cout << endl
                     << "****Remove Item****\n\n";
                break;
            case 4: // Update quality
                cout << endl
                     << "****Update Quantity****\n\n";
                break;
            case 5: // Sorting
                cout << endl
                     << "****Sort****\n\n";
                break;
            case 6: // Ship items
                cout << endl
                     << "****Ship Items****\n\n";
                break;
            case 7: // New or Open Aid database
                cout << endl
                     << "****New/Open Aid Database****\n";
                load(); // loaded
                cout << m_numOfIproduct << " records loaded!\n"
                     << endl;
                break;
            }

        } while (val != 0); // Repeat while exit not chosen
    }

    void AidMan::save()
    {

        if (m_fileName != nullptr)
        {

            // Open output filestream in write mode
            std::ofstream fileStream(m_fileName);

            // Iterate through inventory pointer array
            for (int i = 0; m_iproduct[i] != nullptr; ++i)
            {

                // Save each current object to file
                m_iproduct[i]->save(fileStream);

                // Write new line separating records
                fileStream << '\n';
            }
        }
    }

    void AidMan::deallocate()
    {
        // Loop through the product array to deallocate memory
        for (int i = 0; i < sdds_max_num_items; ++i)
        {
            // Delete the dynamically allocated product
            delete m_iproduct[i];

            // Ensure the pointer is set to nullptr after deletion to avoid dangling pointers
            m_iproduct[i] = nullptr;
        }

        // Reset the count of products to zero
        m_numOfIproduct = 0;
    }

    void AidMan::load()
    {
        char fileName[100];
        bool valid;

        // Save the current state, deallocate memory, and prepare for loading
        save();
        deallocate();

        // Get the file name from the user
        cout << "Enter file name: ";
        cin >> fileName;

        // Copy the file name to member variable m_fileName
        ut.alocpy(m_fileName, fileName);

        // Open the input file stream
        ifstream ifstr(m_fileName);

        // Check if the file is open successfully
        if (ifstr.is_open())
        {
            while (ifstr)
            {
                // Peek at the next character in the file
                char input = ifstr.peek();
                valid = false;

                // Loop to determine the type of product to be loaded
                for (unsigned int i = 0; !valid; ++i)
                {
                    if (input == '1')
                    {
                        // Create a new Perishable product if the type is '1'
                        if (m_iproduct[i] == nullptr)
                        {
                            m_iproduct[i] = new Perishable;
                            valid = true;
                        }
                    }
                    else if (input >= '0' && input <= '9')
                    {
                        // Create a new Item product if the type is a digit
                        if (m_iproduct[i] == nullptr)
                        {
                            m_iproduct[i] = new Item;
                            valid = true;
                        }
                    }
                    else
                    {
                        // Set the stream state to indicate a failure if the type is invalid
                        ifstr.setstate(std::ios::badbit);
                        valid = true;
                    }
                }

                // Load the product details from the file
                if (m_iproduct[m_numOfIproduct])
                {
                    m_iproduct[m_numOfIproduct]->load(ifstr);

                    // Check if the loaded product is valid, and update the count
                    if (m_iproduct[m_numOfIproduct]->operator bool())
                    {
                        ++m_numOfIproduct;
                    }
                    else
                    {
                        // Delete the invalid product if loading fails
                        delete m_iproduct[m_numOfIproduct];
                    }
                }
            }
        }
        else
        {
            // Display a message if the file failed to open
            cout << "Failed to open " << m_fileName << " for reading!" << endl
                 << "Would you like to create a new data file?" << endl
                 << "1- Yes!" << endl
                 << "0 - Exit" << endl
                 << "> ";
            cin >> valid;

            // Create a new file if the user chooses to proceed
            if (valid)
            {
                ofstream ofstr(m_fileName);
            }
        }
    }

    int AidMan::list(const char *sub_desc)
    {
        unsigned int i = 0;

        // Display the header for the product list
        cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl
             << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

        // Check if sub_desc is nullptr
        if (!sub_desc)
        {
            // Loop through the product array and display product information
            for (i = 0; m_iproduct[i] != nullptr; ++i)
            {
                cout << "   " << i + 1 << " | ";
                m_iproduct[i]->linear(true);
                cout << *m_iproduct[i] << endl;
            }
        }
        else
        {
            // Loop through the product array and display product information that matches sub_desc
            for (i = 0; m_iproduct[i] != nullptr; ++i)
            {
                cout << "   " << i + 1 << " | ";
                if (*m_iproduct[i] == sub_desc)
                    cout << *m_iproduct[i] << endl;
            }
        }

        // Display the footer for the product list
        cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

        // Display a message if the list is empty
        if (i == 0)
        {
            cout << "The list is empty!" << endl;
        }

        // Return the count of products
        return i;
    }

}