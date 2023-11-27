
/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: main.cpp
// Version 1.1
// Date: 11/20/2022
// Author: Razi Iqbal
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2023-11-02       review
// Fardad          2023-11-21       added namespace sdds
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Student.h"
#include "Graduate.h"
using namespace sdds;
void display(Student S)
{
    S.display();
}
void display(Graduate G)
{
    G.display();
}
void deallocate(Student *std)
{
    delete std;
}
int main()
{
    Graduate *graduates[5] = {
        new Graduate("Tim David", 30, "Short range wireless technologies", "Prof. Kim Beth"),
        new Graduate("Eva Jobs", 50, "E-Banking and its impact on developing countries", "Prof. Steve Jobs"),
        new Graduate("Lizzy Stone", 35, "Effects of Dams and Bridges on Flooding", "Prof. Louis Parker"),
        new Graduate("Nile Gates", 32, "Expansion of Urban Population in Canada", "Prof. Bill Gates"),
        new Graduate("Tony Blaire", 40, "Crypto Currency and its future", "Prof. Elon Musk")};

    std::cout << "List of Graduates using Graduate Class Object and" << std::endl;
    std::cout << "Testing copy constructor and copy assignment" << std::endl;
    std::cout << "*************************************************" << std::endl;
    Graduate G;
    for (size_t i = 0; i < 5; i++)
    {
        G = *graduates[i];
        display(G);
    }

    std::cout << "\n\nList of Graduates using Student Class Object and" << std::endl;
    std::cout << "Testing Copy constructor and copy assignment and" << std::endl;
    std::cout << "Destructor" << std::endl;
    std::cout << "*************************************************" << std::endl;

    Student students[5];
    Student S;
    for (size_t i = 0; i < 5; i++)
    {
        students[i] = *graduates[i];
        S = students[i];
        display(S);
        deallocate(graduates[i]);
    }
    return 0;
}