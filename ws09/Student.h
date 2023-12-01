/**
 * Name: Kojo Anyane Obese
 * Email: kaobese@myseneca.ca
 * Student ID: 137653227
 * Date: November 24, 2023
 * I have done all the coding by myself and only
 * copied the code that my professor provided to
 * complete my workshops and assignments.
 */
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <iostream>
#include <string>
namespace sdds
{
    class Student
    {
    private:
        char *name{};
        int age;

        void setName(const char *studentName);

    public:
        Student();
        Student(const char *studentName, int studentAge);
        Student(const Student &other);
        Student &operator=(const Student &other);
        virtual ~Student();
        void display() const;
        void safeEmpty();
    };
}
#endif /* SDDS_STUDENT_H */
