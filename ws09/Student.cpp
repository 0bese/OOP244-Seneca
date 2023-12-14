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
#include <cstring>
#include "Student.h"

namespace sdds
{
    // Default constructor
    Student::Student()
    {
        safeEmpty();
    }
    // Parameterized constructor
    Student::Student(const char *studentName, int studentAge)
    {
        setName(studentName);
        age = studentAge;
    }
    // Copy constructor
    Student::Student(const Student &other)
    {
        safeEmpty();
        *this = other;
    }
    // Copy assignment operator
    Student &Student::operator=(const Student &other)
    {
        if (this != &other)
        {
            delete[] name; // Release existing memory
            setName(other.name);
            age = other.age;
        }
        return *this;
    }
    // Destructor
    Student::~Student()
    {
        delete[] name;
        name = nullptr;
    }
    // Display method
    void Student::display() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
    // Private method to set the name dynamically
    void Student::setName(const char *studentName)
    {
        if (studentName != nullptr)
        {
            name = new char[strlen(studentName) + 1];
            strcpy(name, studentName);
        }
        else
        {
            name = nullptr;
        }
    }
    void Student::safeEmpty()
    {
        name = nullptr;
        age = 0;
    }
}
