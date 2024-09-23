#ifndef Pump_hpp
#define Pump_hpp

#include <iostream>
using namespace std;

class Pump
{
public:
    typedef enum {
        ePetrol95, ePetrol98, eDiesel, eNofFuelTypes
    } eFuelType;
    
    static constexpr const char* pumpTypeStr[eNofFuelTypes] = {"Petrol95", "Petrol98", "Diesel"};
    
    // Constructor
    Pump(const char* code, eFuelType type) noexcept(false);
    Pump(const Pump& other);
    Pump(Pump&& other) noexcept;
    
    // Destructor
    ~Pump();
    
    // Getter
    const char* getCode() const noexcept;
    eFuelType getFuelType() const noexcept;
    
    // Setter
    void setCode(const char* code) noexcept(false);
    void setFuelType(eFuelType type) noexcept(false);
    
    // Operators
    const Pump& operator=(const Pump& other);
    const Pump& operator=(Pump&& other);
    
    friend ostream& operator<<(std::ostream& os, const Pump& p);
    
    int isCodeUnique(Pump* pumpArr, int count, const char* code);
    
private:
    static constexpr int PUMP_CODE_LEN = 9;
    char code[PUMP_CODE_LEN + 1];
    eFuelType fuelType;
};

#endif /*Pump_hpp*/

