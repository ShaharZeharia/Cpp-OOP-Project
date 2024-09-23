#include "Owner.h"

Owner::Owner(int pid, char* name, Date date, Person::eGenderType gender,
	char* address, float budget) noexcept(false) :
	Person(pid, name, date, gender, address)
{
	setBudget(budget);
}

void Owner::setBudget(float budget)
{ 
	if (budget > 0) 
		this->budget = budget; 
	else 
		throw "Invalid budget";
}
