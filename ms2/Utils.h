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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds
{
	const int sdds_testYear = 2023;
	const int sdds_testMon = 12;
	const int sdds_testDay = 9;
	class Utils
	{
		bool m_testMode = false;

	public:
		void getSystemDate(int *year = nullptr, int *mon = nullptr, int *day = nullptr);
		int daysOfMon(int mon, int year) const;
		void testMode(bool testmode = true);
		int getInt(const char *prompt = nullptr);
		int getInt(int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
	};
	extern Utils ut;
}

#endif // !SDDS_UTILS_H
