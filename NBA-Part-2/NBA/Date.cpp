#include "Date.h"

const int DAY_MONTHS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int MIN_YEAR = 1900;
const int MAX_YEAR = 2025;

Date::Date(const int day, const int month, const int year) noexcept(false)
{
	setMonth(month);
	setDay(day);
	setYear(year);
}

void Date::setDay(const int day) noexcept(false)
{
	if (DAY_MONTHS[month - 1] >= day && day > 0)
		this->day = day;
	else
		throw "Invalid day";
}

void Date::setMonth(const int month) noexcept(false)
{
	if (month >= 0 && month < 12)
		this->month = month;
	else
		throw "Invalid month";
}

void Date::setYear(const int year) noexcept(false)
{
	if (year >= MIN_YEAR && year <= MAX_YEAR)
		this->year = year;
	else
		throw "Invalid year";
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

istream& operator>>(istream& in, Date& date) noexcept(false)
{
	int day, month, year;
	in >> day >> month >> year;
	date.setYear(year);
	date.setMonth(month);
	date.setDay(day);
	return in;
}
