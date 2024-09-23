#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include "PlayerOwner.h"
#include "Court.h"
using namespace std;

class Team
{
private:
	char* teamName;
	Owner rOwner;
	Court rCourt;
	Player** allPlayers;
	int numberOfWins;
	int numberOfLoses;
	int numberOfPlayers;

public:
	Team(const char* teamName, const Owner& owner, const Court& court,
		const Player* players = nullptr, int numOfPlayers = 0) noexcept(false);
	Team(const Team& other) noexcept;
	Team(Team&& other) noexcept;
	~Team();

	void setName(const char* name) noexcept(false);
	void setNumberOfWins(int wins) noexcept(false);
	void setNumberOfLoses(int loses) noexcept(false);
	void setCourt(const Court& court) { rCourt = court; }
	void setOwner(const Owner& other) { rOwner = other; }

	const Court& getCourt() const { return rCourt; }
	const char* getName() const { return teamName; }
	int getNumberOfWins() const { return numberOfWins; }
	int getNumberOfLoses() const { return numberOfLoses; }
	int	getNumberOfPlayers() const { return numberOfPlayers; }

	const Team& operator+=(const Player& other) noexcept(false);
	Team& operator=(const Team& other);

	friend ostream& operator<<(ostream& os, const Team& team) 
	{
		os << "Team " << team.teamName << ", owner by: " << team.rOwner << ", Home court: " << team.rCourt << endl;
		for (int i = 0; i < team.numberOfPlayers; i++)
		{
			os << team.allPlayers[i] << endl;
		}
		return os;
	}
	
};

#endif // __TEAM_H