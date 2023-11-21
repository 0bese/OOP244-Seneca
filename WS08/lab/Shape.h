/**
 * Name: Kojo Anyane Obese
 * Email: kaobese@myseneca.ca
 * Student ID: 137653227
 * Date: November 17, 2023
 * I have done all the coding by myself and only
 * copied the code that my professor provided to
 * complete my workshops and assignments.
 */

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds
{
    class Shape
    {
    public:
        virtual void draw(std::ostream &ostr) const = 0;
        virtual void getSpecs(std::istream &istr) = 0;
        virtual ~Shape();
    };
    std::ostream &operator<<(std::ostream &ostr, Shape &s);
    std::istream &operator>>(std::istream &istr, Shape &s);
}

#endif /* SDDS_SHAPE_H */
