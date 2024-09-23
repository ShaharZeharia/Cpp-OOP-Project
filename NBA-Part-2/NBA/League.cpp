#include "League.h"

League::League() : currentNumberOfWorkers(0), currentNumberOfOwners(0)
{
	allWorkers = nullptr;
	allOwners = nullptr;
	for (int i = 0; i < NUMBER_OF_DISTRICTS; i++)
	{
		pAllDistricts[i] = nullptr;
	}
}

League::~League()
{
	delete[] * pAllDistricts;
	for (int i = 0; i < currentNumberOfWorkers; i++) 
		delete allWorkers[i];
	delete[] allWorkers;
	for (int i = 0; i < currentNumberOfOwners; i++)
		delete allOwners[i];
	delete[] allOwners;
}

Referee** League::getAllReferees(int* numOfRefs) {
	int count = 0;
	Referee** refs{};
	for (int i = 0; i < currentNumberOfWorkers; i++) {
		if (typeid(allWorkers[i]) == typeid(Referee*))
		{
			refs = (Referee**)realloc(refs, sizeof(Referee*) * (++count));
			if (refs == NULL)
				throw "allocation error";
			refs[count - 1] = dynamic_cast<Referee*>(allWorkers[i]);
		}
	}
	*numOfRefs = count;
	return refs;
}

Player** League::getAllPlayers(int* numOfPlayers) {
	int count = 0;
	Player** players{};
	for (int i = 0; i < currentNumberOfWorkers; i++) {
		if (typeid(allWorkers[i]) == typeid(Player*))
		{
			players = (Player**)realloc(players, sizeof(Player*) * (++count));
			if (players == NULL)
				throw "allocation error";
			players[count - 1] = dynamic_cast<Player*>(allWorkers[i]);
		}
	}
	*numOfPlayers = count;
	return players;
}

void League::setDistrict(const District& d)
{
	if (d.getArea() == District::eAreaType::EAST)
		pAllDistricts[0] = new District(d);
	else
		pAllDistricts[1] = new District(d);
}

const League& League::operator+=(const Person* p) noexcept(false)
{
	allWorkers = (Person**)realloc(allWorkers, sizeof(allWorkers) * (size_t)(currentNumberOfWorkers + 1));
	if (allWorkers == nullptr)
		throw "Allocation error";
	allWorkers[currentNumberOfWorkers++] = p->clone();
	return *this;
}

const League& League::operator+=(const Owner* o)
{
	allOwners = (Owner**)realloc(allOwners, sizeof(allOwners) * (size_t)(currentNumberOfOwners + 1));
	if (allOwners == nullptr)
		throw "Allocation error";
	allOwners[currentNumberOfOwners++] = new Owner(*o);
	return *this;
}