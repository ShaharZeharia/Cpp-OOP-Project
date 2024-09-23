#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
using namespace std;

#include "Person.hpp"

class Employee : virtual public Person
{
protected:
    int salary;
    
public:
    Employee(int pid, const char* name, const Date& dob, eGenderType gender,
        const char* address, int salary) noexcept(false);
    
    // Getters
    int getSalary() const;
    
    // Setters
    void setSalary(int salary);
    
    // Operator
    const Employee& operator< (const Employee& employee);
    
    virtual Person* clone() const override;
    virtual void toOs(ostream& os) const override;
};

#endif /*Employee_hpp*/

