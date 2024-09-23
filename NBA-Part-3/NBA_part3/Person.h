#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Person
{
public:
	enum  eGenderType { MALE, FEMALE, OTHER, eNumOfTypes };
	static const string genders[eNumOfTypes];

	Person(int pid, const string& name, const Date& dob, eGenderType gender, const std::string& address) noexcept(false);
	Person(const Person&) = default;
	Person(Person&& other) noexcept;

	int getPID() const { return id; }
	const string& getName() const { return name; }
	const Date& getDOB() const { return dateOfBirth; }
	const eGenderType getGender() const { return gender; }
	const string& getAddress() const { return address; }

	void setPID(int id) noexcept(false);

	void setName(const string& name) noexcept(false);
	void setDate(const Date& date);
	void setGender(const eGenderType gen) noexcept(false);
	void setAddress(const string& address) noexcept(false);

	virtual Person* clone() const = 0;

	virtual void toOs(ostream& os) const {}

	Person& operator=(const Person&) = default;
	friend ostream& operator<<(ostream& os, const Person& s)
	{
		os << s.name << ", " << Person::genders[s.gender] << ", born in: " << s.dateOfBirth << ", address: " << s.address << ", ID: " << s.id;
		s.toOs(os);
		return os;
	}

protected:
	int id;
	string name;
	Date dateOfBirth;
	eGenderType gender;
	string address;
};

#endif//†__PERSON_H