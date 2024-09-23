#ifndef __REFREE_H
#define __REFREE_H

#include <iostream>
#include "employee.h"
using namespace std;

class Referee : public Employee
{
protected:
	float rank;
	int numberOfMatches;

public:
	Referee(const Employee& e, float rank, int numberOfMatches);

	float getRank() const { return rank; }
	int getNumberOfMatches() const { return numberOfMatches; }

	void setRank(float rank) noexcept(false);
	void setNumberOfMatches(int number)  noexcept(false);

	virtual Person* clone() const override { return new Referee(*this); }
	virtual void toOs(ostream& os) const override;

};

#endif // __REFREE_H