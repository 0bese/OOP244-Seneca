/**
 * Name: Kojo Anyane Obese
 * Email: kaobese@myseneca.ca
 * Student ID: 137653227
 * Date: November 17, 2023
 * I have done all the coding by myself and only
 * copied the code that my professor provided to
 * complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds
{
    char *LblShape::label() const
    {
        return m_label;
    }
    LblShape::LblShape()
    {
    }
    LblShape::LblShape(const char *cstr)
    {
        m_label = new char[strlen(cstr) + 1];
        strcpy(m_label, cstr);
    }
    void LblShape::getSpecs(istream &istr)
    {
        char input[1000];
        istr.getline(input, 1000, ',');
        delete[] m_label;
        m_label = new char[strlen(input) + 1];
        strcpy(m_label, input);
    }
    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label = nullptr;
    }
}