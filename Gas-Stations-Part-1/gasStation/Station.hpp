#ifndef STATION_H
#define STATION_H

#include <iostream>
using namespace std;

#include "Pump.hpp"
#include "Customer.hpp"
#include "EmployeeManager.hpp"
#include "EmployeeCus.hpp"

class Station
{
private:
    char* name;
    char* city;
    Pump** pumpsArr;
    int countOfPumps;
    EmployeeManager* empMang;
    Customer** customerArr;
    int countOfCustomers;
    
public:
    // Constructors
    Station(const char* name, const char* city, EmployeeManager* pEmpMang)noexcept(false);
    Station(const Station& other);
    Station(const Station&& other) noexcept;
    
    // Destructor
    ~Station();

    //Operators
    const Station& operator=(const Station& other);
    const Station& operator=(Station&& other);
    const Station& operator+=(const Pump& pump);
    const Station& operator+=(const Customer& cus);

    //Getters
    const char* getName() const;
    int getCusCount() const;
    int getPumpCount() const;
    const Pump *const* getPumps() const;
    const Customer *const* getCustomers() const;
    EmployeeManager* getEmployeeManager() const;

    
    // Setters
    void setName(char* name) noexcept(false);
    void setCity(const char* city) noexcept(false);
    void setEmployeeManager(EmployeeManager* pEmpMang) noexcept(false);
    void setPumps(Pump** pumpsArr, int count) noexcept(false);
    void setCustomers(Customer** customerArr, int count) noexcept(false);
    
    friend ostream& operator<<(ostream& os, const Station& station);
};

#endif

