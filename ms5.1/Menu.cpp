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
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds
{

    // Default constructor
    Menu::Menu()
    {
        m_numOptions = 0; // Initialize numOptions to 0
    }

    // Destructor to release memory
    Menu::~Menu()
    {
        delete[] m_options; // Delete the dynamically allocated options array
    }

    // Run the menu and get user selection
    unsigned int Menu::run() const
    {

        // Flag for input validation
        bool invalid = true;

        int val = 0;

        // Display menu options
        cout << m_options << "0- Exit" << endl;

        cout << "> ";

        // Input validation loop
        do
        {

            cin >> val;

            // Check for input failure
            if (!cin)
            {
                cin.clear();            // Clear error flags
                cin.ignore(1000, '\n'); // Discard input
                cout << "Invalid Integer, retry: ";
            }

            // Check value range
            else if (val < 0 || (unsigned int)val > m_numOptions)
            {
                cout << "Value out of range [0<=val<=" << m_numOptions << "]: ";
            }

            // Input is valid
            else
            {
                invalid = false;
            }

        } while (invalid);

        return val; // Return selected option
    }

    // Parameterized constructor
    Menu::Menu(unsigned int numOptions, const char *options)
    {

        // Set the menu
        set(numOptions, options);
    }

    // Setter function
    Menu &Menu::set(unsigned int numOptions, const char *options)
    {

        // Check for errors
        if (numOptions > 15 || options == nullptr)
        {
            m_numOptions = 0; // Invalid state
        }
        else
        {

            // Copy options array
            ut.alocpy(m_options, options);

            // Set valid values
            m_numOptions = numOptions;
        }

        return *this; // Return object reference
    }
}
