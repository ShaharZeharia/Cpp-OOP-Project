#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

#include "Date.hpp"

class Person
{
public:
    enum  eGenderType { MALE, FEMALE, OTHER, eNumOfTypes };
    static constexpr const char* genders[eNumOfTypes] = { "Male", "Female", "Other" };
    
    // Constructors
    Person(int pid, const char* name, const Date& dob, const eGenderType gender, const char* address) noexcept(false);
    Person(const Person& other);
    Person(Person&& other) noexcept;
    
    // Destructor
    virtual ~Person();
    
    // Getters
    int getPID() const noexcept { return id; }
    const char* getName() const noexcept { return name; }
    const Date& getDOB() const noexcept { return dateOfBirth; }
    eGenderType getGender() const noexcept { return gender; }
    const char* getAddress() const noexcept { return address; }
    
    // Setters
    void setPID(const int id) noexcept(false);
    void setName(const char* name) noexcept(false);
    void setDate(const Date& date);
    void setGender(const eGenderType gen) noexcept(false);
    void setAddress(const char* address) noexcept(false);
    
    // Virtual methods
    virtual Person* clone() const = 0;
    virtual void toOs(ostream& os) const = 0;
    
    // Operators
    const Person& operator=(const Person& other) noexcept(false);
    const Person& operator=(Person&& other) noexcept;
    
    friend ostream& operator<<(ostream& os, const Person& s);
    
protected:
    int id;
    char* name;
    Date dateOfBirth;
    eGenderType gender;
    char* address;
};

#endif
