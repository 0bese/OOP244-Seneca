//
//  Shape.h
//  WS08
//
//  Created by Kojo Anyane Obese on 2023-11-17.
//

#ifndef Shape_h
#define Shape_h
#include <iostream>

using namespace std;
namespace sdds
{

    struct Shape
    {
        virtual void draw(ostream &os) const = 0;
        virtual void getSpecs(istream &is) const = 0;
        virtual ~Shape();
    };

    ostream &operator<<(ostream &os, const Shape &shape);
    istream &operator>>(istream &is, Shape &shape);

}

#endif /* Shape_h */
