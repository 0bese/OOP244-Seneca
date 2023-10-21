/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    Flight::operator bool() const{
    double minimumFuel = 600 * m_passengers;
    return m_passengers > 0 && m_fuel >= minimumFuel;
    }

Flight::operator int() const{
    return m_passengers;
}

Flight::operator double() const{
    return m_fuel;
}

Flight::operator const char*() const{
    return m_title;
}

bool Flight::operator ~() const{
    return m_passengers == 0;
    
}

Flight& Flight::operator=(Flight& flight){
    m_passengers = flight.m_passengers;
    m_fuel = flight.m_fuel;
    strcpy(m_title, flight.m_title);
    flight.emptyPlane();
    return *this;
}

Flight& Flight::operator=(int newNumberOfPassengers){
    
    if(newNumberOfPassengers > 0 && newNumberOfPassengers <= Boen747Capacity ){
        m_passengers = newNumberOfPassengers;
        
    }
    return *this;
    
}

Flight& Flight::operator=(double newAmountOfFuel){
    if(newAmountOfFuel > 0 && newAmountOfFuel < FuelTankCapacity){
        m_fuel = newAmountOfFuel;
    }
    return *this;
}

Flight& Flight::operator +=(double newAmountOfFuel){
    if (newAmountOfFuel > 0 && m_fuel < FuelTankCapacity ) {
        m_fuel += newAmountOfFuel;
        if( m_fuel > FuelTankCapacity){
            m_fuel = FuelTankCapacity;
            
        }
    }
    return *this;
}

Flight& Flight::operator +=(int newNumberOfPassengers){
    if(newNumberOfPassengers > 0 && m_passengers < newNumberOfPassengers ) {
        m_passengers += newNumberOfPassengers;
        if( m_passengers > Boen747Capacity){
            m_passengers = Boen747Capacity;
            
        }
    }
    return *this;
}

Flight& Flight::operator -=(double newAmountOfFuel){
    if(newAmountOfFuel > 0){
        m_fuel -= newAmountOfFuel;
        if(m_fuel < 0){
            m_fuel = 0;
        }
    }
    return *this;
}

Flight& Flight::operator -=(int newNumberOfPassengers){
    if(newNumberOfPassengers > 0){
        m_passengers -= newNumberOfPassengers;
        if(m_passengers < 0){
            m_passengers = 0;
        }
    }
    return *this;
}
Flight& Flight::operator <<(Flight& flight){
    if(this != &flight && *this && flight){
        m_passengers += flight.m_passengers;
        if ( m_passengers > Boen747Capacity){
            flight.m_passengers = m_passengers - Boen747Capacity;
            m_passengers = Boen747Capacity;
        }
        else{
            flight.m_passengers = 0;
        }
    }
    return *this;
}

Flight& Flight::operator >>(Flight &right){
    
    Flight& left = *this;
    
    if(&left != &right && left && right){
        right.m_passengers += left.m_passengers;
        if(right.m_passengers > Boen747Capacity){
            left.m_passengers = right.m_passengers - Boen747Capacity;
            right.m_passengers = Boen747Capacity;
        }
        else{
            left.m_passengers = 0;
        }
    }
    
    return *this;
    
}

int operator +(const Flight& left, const Flight& right) {
    
    int sum = 0;
    if(left && right){
        sum = (int(left)) + (int(right));
    }
    return sum;
}

int& operator +=(int& left, const Flight& right) {
    
    if(right){
        left += (int(right));
    }
    return left;
    
}
}

