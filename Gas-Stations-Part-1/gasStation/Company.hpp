#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
using namespace std;

#include "Delivery.hpp"

class Company
{
private:
    char* name;
    Delivery** deliArr;
    int countOfDeli;
    Refinery** refineryArr;
    int countOfRef;
    Vehicle** truckArr;
    int countOfTrucks;
    Station** stationsArr;
    int countOfSta;
public:
    // Constructors
    Company(const char* name);
    
    // Destructor
    ~Company();
    
    // Operators
    const Company& operator=(const Company& other);
    const Company& operator=(Company&& other) noexcept;
    
    const Company& operator+=(const Delivery& deli);
    const Company& operator+=(const Refinery& ref);
    const Company& operator+=(const Vehicle& vehicle);
    const Company& operator+=(const Station& sta);
    
    // Getters
    const char* getName() const noexcept;
    int getDeliCount() const noexcept;
    int getRefCount() const noexcept;
    int getVehCount() const noexcept;
    int getStaCount() const noexcept;
    Delivery** getDeliveries() noexcept;
    Refinery** getRefineries() noexcept;
    Vehicle** getVehicles() noexcept;
    Station** getStations() noexcept;
    
    const Station& findMostProfitable() const noexcept(false);
    void showMostProfitable() const;
    
    // Setters
    void setName(const char* name) noexcept(false);
    
    // Methods
    void addStation(const Station& sta) noexcept(false);
    void addPump(const Pump& pump) noexcept(false);
    void addRefinery(const Refinery& ref) noexcept(false);
    void addDelivery(const Delivery& deli) noexcept(false);
    void addVehicle(const Vehicle& vehicle) noexcept(false);
    
    friend ostream& operator<<(ostream& os, const Company& company);
    
    void printStations() const;
    void printRefineries() const;
    void printDeliveries() const;
    void printVehicles() const;
};

#endif
