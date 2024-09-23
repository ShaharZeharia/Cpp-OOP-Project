#ifndef Delivery_hpp
#define Delivery_hpp

#include <iostream>
using namespace std;

#include "Date.hpp"
#include "Vehicle.hpp"
#include "Station.hpp"
#include "Refinery.hpp"

class Delivery {
private:
    Station* dest;
    Refinery* origin;
    Date date;
    Vehicle* truck;
    
public:
    // Constructors
    Delivery(Vehicle& theVehicle, Station& dest, Refinery& origin, const Date& date) noexcept(false);
    Delivery(const Delivery& other);
    Delivery(const Delivery&& other) noexcept;
    
    // Destructor
    ~Delivery();
    
    const Delivery& operator=(const Delivery& other);
    const Delivery& operator=(Delivery&& other);
    
    // Getters
    Station* getDestination() const;
    Refinery* getOrigin() const;
    Date getDate() const;
    Vehicle* getTruck() const;
    
    // Setters
    void setDestination(Station& dest) noexcept(false);
    void setOrigin(Refinery& origin) noexcept(false);
    void setDate(const Date& date) noexcept(false);
    void setTruck(Vehicle& truck) noexcept(false);
    
    friend ostream& operator<<(std::ostream& os, const Delivery& delivery);
};

#endif /*Delivery_hpp*/

