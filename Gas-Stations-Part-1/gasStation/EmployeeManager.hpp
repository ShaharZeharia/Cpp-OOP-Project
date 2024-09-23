#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <iostream>
using namespace std;

#include "Employee.hpp"

class EmployeeManager : public Employee
{
private:
    Employee** employeeArr;
    int countOfEmployees;
    
public:
    //Constructor
    EmployeeManager(const Employee& e) noexcept(false);
    EmployeeManager(const EmployeeManager& other);
    EmployeeManager(const EmployeeManager&& other) noexcept;
    ~EmployeeManager();
    
    //Operator
    const EmployeeManager& operator=(const EmployeeManager& other);
    const EmployeeManager& operator=(EmployeeManager&& other);
    
    const EmployeeManager& operator+=(const Employee& emp);
    const EmployeeManager& operator+=(Employee&& emp);
    
    // Getters
    int getCount() const;
    const Employee** getEmployees() const;
    
    int addEmployee(const Employee& emp) noexcept(false);
    
    // Operator
    virtual Person* clone() const override;
    virtual void toOs(ostream& os) const override;
};

#endif

