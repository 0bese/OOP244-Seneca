/**
 * Name: Kojo Anyane Obese
 * Email: kaobese@myseneca.ca
 * Student ID: 137653227
 * Date: November 24, 2023
 * I have done all the coding by myself and only
 * copied the code that my professor provided to
 * complete my workshops and assignments.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Graduate.h"

namespace sdds
{
    // Default constructor
    Graduate::Graduate() : Student()
    {
        safeEmpty();
    }

    // Parameterized constructor
    Graduate::Graduate(const char *n, int a, const char *title, const char *sup) : Student(n, a)
    {
        safeEmpty();
        setThesisTitle(title);
        setSupervisor(sup);
    }

    // Copy constructor
    Graduate::Graduate(const Graduate &other) : Student(other)
    {
        safeEmpty();
        *this = other;
    }

    // Copy assignment operator
    Graduate &Graduate::operator=(const Graduate &other)
    {
        if (this != &other)
        {
            Student::operator=(other); // Call the base class assignment operator
            setThesisTitle(other.thesisTitle);
            setSupervisor(other.supervisor);
        }
        return *this;
    }

    // Destructor
    Graduate::~Graduate()
    {
        delete[] thesisTitle;
        thesisTitle = nullptr;
        delete[] supervisor;
        supervisor = nullptr;
    }

    // Display method
    void Graduate::display() const
    {
        Student::display(); // Call the base class display method
        std::cout << "Thesis Title: " << thesisTitle << std::endl;
        std::cout << "Supervisor: " << supervisor << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }

    // Private method to set the thesis title dynamically
    void Graduate::setThesisTitle(const char *title)
    {
        delete[] thesisTitle;
        if (title != nullptr)
        {
            thesisTitle = new char[strlen(title) + 1];
            strcpy(thesisTitle, title);
        }
        else
        {
            safeEmpty();
        }
    }

    // Private method to set the supervisor dynamically
    void Graduate::setSupervisor(const char *sup)
    {
        delete[] supervisor;
        if (sup != nullptr)
        {
            supervisor = new char[strlen(sup) + 1];
            strcpy(supervisor, sup);
        }
        else
        {
            safeEmpty();
        }
    }

    void Graduate::safeEmpty()
    {
        supervisor = nullptr;
        thesisTitle = nullptr;
    }
}
