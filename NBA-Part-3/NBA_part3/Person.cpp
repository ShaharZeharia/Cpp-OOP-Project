#include "Person.h"

static constexpr int MIN_ID = 10000000;
static constexpr int MAX_ID = 999999999;

const string Person::genders[eNumOfTypes] = { "Male", "Female", "Other" };

Person::Person(const int pid, const string& name, const Date& dob, const eGenderType gender, const string& address) noexcept(false) : dateOfBirth(dob)
{
    setGender(gender);
    setPID(pid);
    setName(name);
    setAddress(address);
}

Person::Person(Person&& other) noexcept(true)
    : id(other.id), name(move(other.name)), dateOfBirth(other.dateOfBirth), gender(other.gender), address(move(other.address))
{

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


void Person::setAddress(const string& address) noexcept(false)
{
    if (address.empty())
        throw ("Invalid address");

    this->address = address;
}

void Person::setName(const string& name) noexcept(false)
{
    if (name.empty())
        throw("Invalid name");

    this->name = name;
}
