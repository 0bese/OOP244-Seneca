/**
 * Name: Kojo Anyane Obese
 * Email: kaobese@myseneca.ca
 * Student ID: 137653227
 * Date: November 17, 2023
 * I have done all the coding by myself and only
 * copied the code that my professor provided to
 * complete my workshops and assignments.
 */

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace sdds
{
    class LblShape : public Shape
    {
        char *m_label{};

    protected:
        char *label() const;

    public:
        LblShape();
        LblShape(const char *cstr);
        LblShape(const LblShape &s) = delete;
        LblShape &operator=(const LblShape &s) = delete;
        void getSpecs(std::istream &istr);
        virtual ~LblShape();
    };
}
#endif /* SDDS_LBLSHAPE_H */
