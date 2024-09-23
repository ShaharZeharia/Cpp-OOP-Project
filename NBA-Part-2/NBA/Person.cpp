#include "Person.h"

static constexpr int MIN_ID = 10000000;
static constexpr int MAX_ID = 999999999;

Person::Person(const int pid, const char* name, const Date& dob, const eGenderType gender, const char* address) noexcept(false) : dateOfBirth(dob)
{
    setGender(gender);
    setPID(pid);
    setName(name);
    if (address == nullptr || strlen(address) == 0)
        delete[] this->name;
    setAddress(address);
}

// Copy constructor
Person::Person(const Person& other)
{
    *this = other;
}

// Move constructor
Person::Person(Person&& other) noexcept(true)
    : id(other.id), name(other.name), dateOfBirth(other.dateOfBirth), gender(other.gender), address(other.address)
{
    other.name = nullptr;
    other.address = nullptr;
}

// Destructor
Person::~Person()
{
    delete[] name;
    delete[] address;
}


static bool isValidID(int id)
{
    //Algorithm for checking the correctness of an ID card in the world I have attached a link to the article- https://www.ynet.co.il/articles/0,7340,L-4483052,00.html
    int sum = 0;
    bool isSecond = false;

    if (id < MIN_ID || id > MAX_ID) {
        return false;
    }

    for (int i = 0; i < 9; i++)
    {
        int digit = id % 10;
        id /= 10;

        if (isSecond)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        isSecond = !isSecond;
    }
    return (sum % 10 == 0);
}

void Person::setPID(int id)noexcept(false)
{
    if (!isValidID(id))
        throw "Invalid ID: does not meet the required criteria";

    this->id = id;
}

void Person::setDate(const Date& date)
{
    dateOfBirth = date;
}

void Person::setGender(const eGenderType gen)noexcept(false)
{
    if (gen < 0 || gen >= eNumOfTypes)
        throw ("Invalid gender");

    this->gender = gen;
}

void Person::setAddress(const char* address)noexcept(false)
{
    if (address == nullptr || strlen(address) == 0)
        throw ("Invalid address");

    delete[] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

void Person::setName(const char* name)noexcept(false)
{
    if (name == nullptr || strlen(name) == 0)
        throw("Invalid name");

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] name;
        delete[] address;

        id = other.id;
        dateOfBirth = other.dateOfBirth;
        gender = other.gender;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
    }
    return *this;
}
