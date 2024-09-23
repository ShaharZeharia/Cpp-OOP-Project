#include "Employee.h"

Employee::Employee(int pid, const char* name, const Date dob,
	Person::eGenderType gender, const char* address, float salary) :
	Person(pid, name, dob, gender, address)
{
	setSalary(salary);
}

void Employee::setSalary(float salary){
	if (salary > 0) 
		this->salary = salary; 
	else 
		throw "Invalid Salary"; 
}

const Employee& Employee::operator+(float valueToAdd) // Increment salary
{
	if (salary + valueToAdd > 0)
		salary += valueToAdd;
	else
		throw "Invalid operation, negative salary";
	return *this;
}