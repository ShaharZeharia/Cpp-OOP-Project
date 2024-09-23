#ifndef __COURT_H
#define __COURT_H

#include <iostream>
#include <string>
using namespace std;

class Court
{
protected:
	string courtName;
	int numberOfSeats;

public:
	Court(const string& courtName, int numberOfSeats);
	Court(const Court&) = default;
	Court(Court&& other) noexcept;

	const string& getCourtName() const { return courtName; }
	int getNumberOfSeats() const { return numberOfSeats; }

	void setCourtName(const string& name);

	Court& operator=(const Court&) = default;
	friend ostream& operator<<(ostream& os, const Court& court);

};

#endif //__COURT_H