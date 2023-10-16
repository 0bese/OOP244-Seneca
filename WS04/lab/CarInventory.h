#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

namespace sdds
{
    class CarInventory
    {
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;

    public:
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
        ~CarInventory();
        void resetInfo();
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };
    int find_similar(CarInventory car[], const int num_cars);
}
#endif