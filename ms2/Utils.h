#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
	const int sdds_testYear = 2022;
	const int sdds_testMon = 03;
	const int sdds_testDay = 31;
	class Utils {
		bool m_testMode = false;
	public:
		void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
		int daysOfMon(int mon, int year)const;
		void testMode(bool testmode = true);
		int getInt(const char* prompt = nullptr);
		int getInt(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
	};
	extern Utils ut;
}

#endif // !SDDS_UTILS_H
