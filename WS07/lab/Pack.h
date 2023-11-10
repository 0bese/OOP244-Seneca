/**
* Kojo Anyane Obese
* kaobese@myseneca.ca
* 137653226
* Nov. 10, 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef PACK_H
#define PACK_H

#include "Container.h"
using namespace sdds;

namespace sdds {
    class Pack : public Container {
    private:
        int Unit_Size;
        int Size;
        int Number_Of_Units;


    public:
        Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits = 0);
        int operator += (int units);
        int operator -= (int units);
        int unit();
        int noOfUnits();
        int size();
        void clear(int packSize, int unitSize, const char* content);
        ostream& print(ostream& out);
        istream& read(istream& in);
        friend ostream& operator << (ostream& out, Pack& P) {
            return P.print(out);
        }

        friend istream& operator >> (istream& in, Pack& P) {
            return P.read(in);
        }

    };
}


#endif