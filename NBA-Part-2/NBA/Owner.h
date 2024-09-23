#ifndef __OWNER_H
#define __OWNER_H

#include <iostream>
#include "Person.h"
using namespace std;

class Owner : virtual public Person
{
protected:
	float budget;

public:
	Owner(int pid, char* name, Date date, Person::eGenderType gender, char* address, float budget) noexcept(false);
	
	void setBudget(const float budget) noexcept(false);

	float getBudget() const { return budget; }

	virtual Person* clone() const override { return new Owner(*this); }

	virtual void toOs(ostream& os) const override { os << ", " << budget; }
};

#endif // __OWNER_H