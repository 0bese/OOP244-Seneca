/*
	==================================================
	Mile Stone 2
	==================================================
	Name   : Kojo Anyane Obese
	ID     : 137653226
	Email  : kaobese@myseneca.ca
	Section: NHH
	Date   : 2023/11/16
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "Status.h"
#include "Utils.h"

namespace sdds
{
	const int maximumYear = 2030;
	const int currentYear = 2023;

	class Date : public Status
	{
	private:
		int Year;
		int Month;
		int Day;
		Status State;
		bool Formatted;
		bool validate();
		int uniqDateValue();

	public:
		void setEmpty();
		Date();
		Date(int year, int month, int day);
		bool operator==(Date &date);
		bool operator!=(Date &date);
		bool operator>(Date &date);
		bool operator<(Date &date);
		bool operator>=(Date &date);
		bool operator<=(Date &date);
		const Status &state() const;
		Date &formatted(bool valid);
		operator bool() const;
		std::ostream &write(std::ostream &os) const;
		std::istream &read(std::istream &is);
		~Date();
	};
	std::ostream &operator<<(std::ostream &os, const Date &date);
	std::istream &operator>>(std::istream &is, Date &date);
}
#endif