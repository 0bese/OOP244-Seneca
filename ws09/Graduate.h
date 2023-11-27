/**
 * Name: Kojo Anyane Obese
 * Email: kaobese@myseneca.ca
 * Student ID: 137653227
 * Date: November 24, 2023
 * I have done all the coding by myself and only
 * copied the code that my professor provided to
 * complete my workshops and assignments.
 */
#ifndef _SDDS_GRADUATE_H
#define _SDDS_GRADUATE_H
#include <iostream>
#include <string>
#include "Student.h"

namespace sdds
{
    class Graduate : public Student
    {
        char *supervisor = nullptr;
        char *thesisTitle = nullptr;

        void setSupervisor(const char *sup);
        void setThesisTitle(const char *title);

    public:
        Graduate();
        Graduate(const char *n, int a, const char *title, const char *sup);
        Graduate(const Graduate &other);
        Graduate &operator=(const Graduate &other);
        virtual ~Graduate();

        void display() const;
        void safeEmpty();
    };
}

#endif /* _SDDS_GRADUATE_H */