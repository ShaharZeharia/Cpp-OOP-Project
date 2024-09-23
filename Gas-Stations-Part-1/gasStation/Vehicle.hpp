#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <iostream>
using namespace std;

#include "Pump.hpp"

class Vehicle {
public:
    typedef enum {
        ePrivate, eTruck, eMotorcycle, eNofVehicleTypes
    } eVehicleType;
    
    static constexpr const char* vehicleTypeStr[eNofVehicleTypes] = { "Private", "Truck", "Motorcycle" };
    
    // Constructor
    Vehicle(int plate, eVehicleType type, Pump::eFuelType fuel) noexcept(false);
    
    // Getters
    int getLicensePlate() const { return licensePlate; }
    eVehicleType getVehicleType() const { return vehicleType; }
    Pump::eFuelType getFuelType() const { return fuelType; }
    
    // Setters
    void setLicensePlate(int plate) noexcept(false);
    void setVehicleType(eVehicleType type) noexcept(false);
    void setFuelType(Pump::eFuelType fuel) noexcept(false);
    
    friend ostream& operator<<(std::ostream& os, const Vehicle& v);
    
    
private:
    int licensePlate;
    eVehicleType    vehicleType;
    Pump::eFuelType    fuelType;
};

#endif /*Vehicle_hpp*/

