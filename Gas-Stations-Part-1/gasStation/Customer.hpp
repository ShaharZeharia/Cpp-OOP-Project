#ifndef Customer_hpp
#define Customer_hpp

#include <iostream>
using namespace std;

#include "Person.hpp"
#include "Vehicle.hpp"

class Customer : virtual public Person {
protected:
    int expenses;
    Vehicle car;
    
public:
    Customer(int pid, const char* name, const Date& dob, eGenderType gender, const char* address, const Vehicle& v) noexcept(false);
    
    // Getters
    int getExpenses() const;
    
    // Setters
    void setExpenses(int expenses) noexcept(false);
    
    virtual void purchase(int amount);
    
    const Customer& operator < (const Customer& customer);
    
    virtual Person* clone() const override;
    virtual void toOs(ostream& os) const override;
};

#endif /*Customer_hpp*/

