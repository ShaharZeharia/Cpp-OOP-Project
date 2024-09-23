#ifndef __LEAGUE_H
#define __LEAGUE_H

#include "District.h"
#include <iostream>
using namespace std;

class League
{
protected:
	static constexpr int NUMBER_OF_DISTRICTS = 2;
	District* pAllDistricts[NUMBER_OF_DISTRICTS];
	int currentNumberOfWorkers;
	int currentNumberOfOwners;
	Person** allWorkers;
	Owner** allOwners;

public:
	League();
	League(const League& other) = delete;
	League(League&& other) = delete;
	~League();

	District*const* getDistricts() { return pAllDistricts; }
	int getCurrentNumberOfWorkers() const { return currentNumberOfWorkers; }
	Person** getAllWorkers() { return allWorkers; }
	Owner** getAllOwners() { return allOwners; }
	Player** getAllPlayers(int* numOfPlayers) noexcept(false);
	Referee** getAllReferees(int* numOfRefs) noexcept(false);
	
	void setDistrict(const District& d);

	const League& operator+=(const Person* p) noexcept(false);
	const League& operator+=(const Owner* o) noexcept(false);

	friend ostream& operator<<(ostream& os, const League& league)
	{
		os << "League details:\n"
			<< "Number of workers: " << league.currentNumberOfWorkers << endl;
		for (int i = 0; i < league.currentNumberOfWorkers; i++)
		{
			os << league.allWorkers[i];
		}
		os << "Number of owners: " << league.currentNumberOfOwners << endl;
		for (int i = 0; i < league.currentNumberOfOwners; i++)
		{
			os << league.allOwners[i];
		}
		os << "League districts: " << endl;
		for (int i = 0; i < league.NUMBER_OF_DISTRICTS; i++)
		{
			os << league.pAllDistricts[i];
		}
		return os;
	}
};

#endif // LEAGUE