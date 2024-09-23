#ifndef Refinery_hpp
#define Refinery_hpp

#include <iostream>
using namespace std;

#include "Pump.hpp"

class Refinery
{
private:
    char* name;
    Pump::eFuelType type;
    int price;
    
public:
    
    // Constructor
    Refinery(const char* name, Pump::eFuelType type, int price) noexcept(false);
    Refinery(const Refinery& other);
    Refinery(const Pump&& other)noexcept;
    // Destructor
    ~Refinery();
    
    //Operators
    const Refinery& operator=(const Refinery& other);
    const Refinery& operator=(Refinery&& other);
    
    // Getters
    const char* getName() const;
    Pump::eFuelType getFuelType() const;
    int getPrice() const;
    
    // Setters
    void setName(const char* name) noexcept(false);
    void setFuelType(Pump::eFuelType type) noexcept(false);
    void setPrice(int price) noexcept(false);
    
    friend ostream& operator<<(std::ostream& os, const Refinery& refinery);
};

#endif /*†Refinery_hpp†*/

