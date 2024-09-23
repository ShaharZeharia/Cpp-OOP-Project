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

	Employee(int pid, const string& name, const Date dob,
		Person::eGenderType gender, const string& address, float salary) noexcept(false);
	Employee(const Employee&) = default;

	float getSalary() const { return salary; }

	void setSalary(float salary) noexcept(false);

	const Employee& operator+(float valueToAdd) noexcept(false);
	Employee& operator=(const Employee&) = default;

	virtual Person* clone() const override { return new Employee(*this); }

	virtual void toOs(ostream& os) const override { os << "Salary: " << salary << ", "; }
};

#endif // __EMPLOYEE_H