#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    
public:
    // Constructors
    Date(int day = 1, int month = 1, int year = 1999) noexcept(false);
    
    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    // Setters
    void setDay(int day) noexcept(false);
    void setMonth(int month) noexcept(false);
    void setYear(int year) noexcept(false);
    
    // Operators
    friend istream& operator>>(istream& in, Date& date) noexcept(false);
    friend ostream& operator<<(ostream& os, const Date& date);
};

#endif

