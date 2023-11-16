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
#include <cstring>
#include "Status.h"

using namespace std;
namespace sdds
{
	void Status::setEmpty()
	{
		statusOfObj = nullptr;
		statusCode = 0;
	}

	Status::Status(const char *description)
	{
		setEmpty();
		if (description)
		{
			delete[] statusOfObj;
			statusOfObj = new char[strlen(description) + 1];
			strcpy(statusOfObj, description);
		}
		statusCode = 0;
	}

	Status &Status::operator=(int code)
	{
		statusCode = code;
		return *this;
	}

	Status &Status::operator=(const char *description)
	{
		if (description)
		{
			delete[] statusOfObj;
			statusOfObj = new char[strlen(description) + 1];
			strcpy(statusOfObj, description);
		}
		return *this;
	}

	Status::operator int() const
	{
		return statusCode;
	}

	Status::operator const char *() const
	{
		return statusOfObj;
	}

	Status::operator bool() const
	{
		bool valid = false;
		if (statusOfObj == nullptr)
		{
			valid = true;
		}
		return valid;
	}

	Status &Status::clear()
	{
		if (statusOfObj)
		{
			delete[] statusOfObj;
			statusOfObj = nullptr;
		}
		statusCode = 0;
		return *this;
	}

	std::ostream &Status::print(std::ostream &os) const
	{
		if (this != nullptr)
		{
			if (statusCode != 0)
			{
				os << "ERR#" << statusCode << ": ";
			}
			if (statusOfObj != nullptr)
			{
				os << statusOfObj;
			}
		}

		return os;
	}

	std::ostream &operator<<(std::ostream &os, const Status &sta)
	{
		return sta.print(os);
	}
}