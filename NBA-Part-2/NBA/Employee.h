#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "Person.h"
using namespace std;

class Employee : virtual public Person
{
protected:
	float salary;

public:
	Employee(int pid, const char* name, const Date dob,
		Person::eGenderType gender, const char* address, float salary) noexcept(false);

	float getSalary() const{ return salary; }

	void setSalary(float salary) noexcept(false);

	const Employee& operator+(float valueToAdd) noexcept(false);

	virtual Person* clone() const override { return new Employee(*this); }

	virtual void toOs(ostream& os) const override { os << ", salary: " << salary; }
};

#endif // __EMPLOYEE_H