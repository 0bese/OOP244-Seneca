#ifndef STATUS_H
#define STATUS_H
#include <iostream>

namespace sdds
{
	class Status
	{
	private:
		char* statusOfObj;
		int statusCode;
	public:
		void setEmpty();
		Status(const char* description = nullptr);
		Status& operator=(int code);
		Status& operator=(const char* descrption);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<< (std::ostream& os, const Status& sta);
}
#endif//STATUS_H