#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "HealthCard.h"

using namespace std;
namespace sdds {
    //Checks the validity of Health Card information
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
        return name && name[0] && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
    }

    //Deallocate memory and set m_name to NULL
    void HealthCard::setEmpty(){
        delete[] m_name;
        m_name = nullptr;
    }

    //Allocates memory for m_name and copy name to m_name
    void HealthCard::allocateAndCopy(const char* name) {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    //Extracts a character from the input stream 
    void HealthCard::extractChar(istream& istr, char ch) const {
        if (istr.peek() == ch)
            istr.ignore();
        else {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    //Prints health card information
    ostream& HealthCard::printIDInfo(ostream& ostr) const {
        return ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
    }

    //Sets the health card information
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        delete[] m_name;
        m_name = nullptr;
        setEmpty();
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
    }

    //Constructor to initialize the HealthCard
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        set(name, number, vCode, sNumber);
    }

    //Copy constructor
    HealthCard::HealthCard(const HealthCard& hc) {
        *this = hc;
    }

    //Assignment operator
    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this != &hc) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }

    //Destructor to deallocate memory allocated
    HealthCard::~HealthCard() {
        delete[] m_name;
    }

    //Conversion operator to check if HealthCard is valid
    HealthCard::operator bool() const {
        return m_name != nullptr;
    }

    //Print health card information
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
        if (*this) {
            if (toFile) {
                ostr << m_name;
                ostr << ',';
                printIDInfo(ostr);
                ostr << endl;
            }
            else {
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }

    //Reads Health Card information from input stream
    istream& HealthCard::read(istream& istr) {
        char name[MaxNameLength]{ '\0' };
        long long number{ 0 };
        char vCode[3]{ 0 };
        char sNumber[10]{ 0 };
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');
        if (istr) {
            set(name, number, vCode, sNumber);
        }
        else {
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }

    //Overloaded output operation to print Health Card
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc) {
            hc.print(ostr, false);
        }
        else {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }

    //Overloaded input operation to read Health card information
    istream& operator>>(istream& istr, HealthCard& hc) {
        return hc.read(istr);
    }

}
