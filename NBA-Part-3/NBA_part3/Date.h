#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;

const int MIN_YEAR = 1900;
const int MAX_YEAR = 2025;

class Date
{
	private:
		int day;
		int month;
		int year;

	public:

		Date(int day = 1, int month = 1, int year = 1970) noexcept(false);

		int getDay() const { return day; }
		int getMonth() const { return month; }
		int getYear() const { return year; }

		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);

		friend ostream& operator<<(ostream& os, const Date& date);

		friend istream& operator>>(istream& in, Date& date) noexcept(false);
};

#endif // __DATE_H