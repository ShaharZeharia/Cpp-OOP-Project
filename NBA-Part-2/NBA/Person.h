#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include "Date.h"
using namespace std;

class Person
{
public:
	enum  eGenderType { MALE, FEMALE, OTHER, eNumOfTypes };
	static constexpr const char* genders[eNumOfTypes] = { "Male", "Female", "Other" };

	Person(int pid, const char* name, const Date& dob, eGenderType gender, const char* address)noexcept(false);
	Person(const Person& other);
	Person(Person&& other) noexcept;
	virtual ~Person();

	int getPID() const { return id; }
	const char* getName() const { return name; }
	const Date& getDOB() const { return dateOfBirth; }
	const eGenderType getGender() const { return gender; }
	const char* getAddress() const { return address; }

	void setPID(int id) noexcept(false);
	void setName(const char* name) noexcept(false);
	void setDate(const Date& date);
	void setGender(const eGenderType gen) noexcept(false);
	void setAddress(const char* address) noexcept(false);

	const Person& operator=(const Person& other);

	virtual Person* clone() const = 0;

	virtual void toOs(ostream& os) const {}

	friend ostream& operator<<(ostream& os, const Person& s) 
	{
		os << s.name << ", " << Person::genders[s.gender] << ", born in: " << s.dateOfBirth << ", address: " << s.address << ", ID: " << s.id;
		s.toOs(os);
		return os;
	}

protected:
	int id;
	char* name;
	Date dateOfBirth;
	eGenderType gender;
	char* address = nullptr;
};

#endif// __PERSON_H