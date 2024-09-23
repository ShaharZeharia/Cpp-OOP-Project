#include "Referee.h"

Referee::Referee(const Employee& e, float rank, int numberOfMatches) 
	: Person(e), Employee(e) 
{ 
	setRank(rank); 
	setNumberOfMatches(numberOfMatches); 
}

void Referee::setRank(float rank)
{
	if (rank > 0.0 && rank <= 10.0)
		this->rank = rank;
	else
		throw "Invalid rank";
}

void Referee::setNumberOfMatches(int number)
{
	if (number >= 0)
		numberOfMatches = number;
	else
		throw "Invalid number of matches";
}

void Referee::toOs(ostream& os) const
{
	os << endl << "Nubmer of matches: " << numberOfMatches << ", referee rank: " << rank << endl;
}