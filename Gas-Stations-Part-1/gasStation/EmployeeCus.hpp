#ifndef EMPLOYEECUS_H
#define EMPLOYEECUS_H

#include <iostream>
using namespace std;

#include "Employee.hpp"
#include "Customer.hpp"

class EmployeeCus : public Employee, public Customer
{
private:
    float discount;
public:
    EmployeeCus(const Employee& e, const Customer& c, float discount) noexcept(false);
    
    // Getters
    float getDiscount() const;
    
    // Setters
    void setDiscount(float discount) noexcept(false);
    
    // Overriding
    void purchase(int amount) override;
    
    // Operator
    virtual Person* clone() const override;
    virtual void toOs(ostream& os) const override;
};

#endif
