#ifndef __COURT_H
#define __COURT_H

#include <iostream>
using namespace std;

class Court
{
protected:
	char* courtName;
	int numberOfSeats;

public:
	Court(const char* courtName, int numberOfSeats);
	Court(const Court& other) { *this = other; }
	Court(Court&& other) noexcept;
	~Court(){ delete[] courtName; }

	const char* getCourtName() const { return courtName; }
	int getNumberOfSeats() const { return numberOfSeats; }
	void setCourtName(const char* name);
	friend ostream& operator<<(ostream& os, const Court& court);
	Court& operator=(const Court& other);

};

#endif // __COURT_H