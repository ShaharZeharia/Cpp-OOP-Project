#ifndef __OWNER_H
#define __OWNER_H

#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

class Owner : virtual public Person
{
protected:
	float budget;

public:
	//	Owner(int pid, char* name, Date date, Person::eGenderType gender, char* address, float budget) noexcept(false);

	Owner(int pid, const string& name, const Date& date, Person::eGenderType gender, const string& address, float budget) noexcept(false);
	Owner(const Owner&) = default;

	void setBudget(const float budget) noexcept(false);

	float getBudget() const { return budget; }

	virtual Person* clone() const override { return new Owner(*this); }

	virtual void toOs(ostream& os) const override { os << "\nOwner of a team with a budget of: " << budget << endl; }

	Owner& operator=(const Owner&) = default;
};

#endif // __OWNER_H