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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"

using namespace std;
namespace sdds
{
	void Date::setEmpty()
	{
		Year = 0;
		Month = 0;
		Day = 0;
		State = nullptr;
		Formatted = true;
	}

	bool Date::validate()
	{
		State.clear();
		bool valid = true;
		if (!(Year >= currentYear && Year <= maximumYear))
		{
			State = "Invalid year in date";
			State = 1;
			valid = false;
		}
		else if (!(Month >= 1 && Month <= 12))
		{
			State = "Invalid month in date";
			State = 2;
			valid = false;
		}
		else if (!(Day >= 1 && Day <= ut.daysOfMon(Month, Year)))
		{
			State = "Invalid day in date";
			State = 3;
			valid = false;
		}

		return valid;
	}

	int Date::uniqDateValue()
	{
		return Year * 372 + Month * 31 + Day;
	}

	Date::Date()
	{
		Date::setEmpty();
		ut.getSystemDate(&Year, &Month, &Day);
	}

	Date::Date(int year, int month, int day) : Status()
	{
		Year = year;
		Month = month;
		Day = day;
		Formatted = true;

		if (!validate())
		{
			Year = 0;
			Month = 0;
			Day = 0;
		}
	}

	bool Date::operator==(Date &date)
	{
		bool valid = false;
		if (uniqDateValue() == date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator!=(Date &date)
	{
		bool valid = false;
		if (uniqDateValue() != date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator>(Date &date)
	{
		bool valid = false;
		if (uniqDateValue() > date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator<(Date &date)
	{
		bool valid = false;
		if (uniqDateValue() < date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator>=(Date &date)
	{
		bool valid = false;
		if (uniqDateValue() >= date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator<=(Date &date)
	{
		bool valid = false;
		if (uniqDateValue() <= date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	const Status &Date::state() const
	{
		return this->State;
	}

	Date &Date::formatted(bool valid)
	{
		Formatted = valid;
		return *this;
	}

	Date::operator bool() const
	{
		return Formatted;
	}

	std::ostream &Date::write(std::ostream &os) const
	{
		if (Formatted)
		{
			os << Year << "/";
			os.width(2);
			os.fill('0');
			os << Month << "/";
			os.width(2);
			os.fill('0');
			os << Day;
		}
		else
		{
			os << Year - 2000;
			os.width(2);
			os.fill('0');
			os << Month;
			os.width(2);
			os.fill('0');
			os << Day;
		}
		return os;
	}

	std::istream &Date::read(std::istream &is)
	{
		int date;
		is >> date;
		if (is)
		{
			if (date >= 100000 && date <= 999999)
			{
				Day = date % 100;
				Month = (date % 10000 - Day) / 100;
				Year = date / 10000 + 2000;
			}
			else if (date >= 100 && date <= 9999)
			{
				Year = currentYear;
				Day = date % 100;
				Month = (date % 10000 - Day) / 100;
			}
			else if (date < 100)
			{
				Year = currentYear;
				Month = 0;
				Day = date;
			}
			if (!validate())
			{
				is.setstate(ios::badbit);
			}
		}
		else
		{
			State = "Invalid date value";
			State = 0;
		}
		is.ignore(1000, '\n');

		return is;
	}
	Date::~Date()
	{
		State.clear();
	}

	std::ostream &operator<<(std::ostream &os, const Date &date)
	{
		return date.write(os);
	}

	std::istream &operator>>(std::istream &is, Date &date)
	{
		return date.read(is);
	}
}