#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include <string>
#include <list>
#include "PlayerOwner.h"
#include "Court.h"
using namespace std;

class Team
{
private:
	string teamName;
	Owner owner;
	Court court;
	list<Player*> players;
	int numberOfWins;
	int numberOfLoses;

public:
	Team(const string& teamName, const Owner& owner, const Court& court) noexcept(false);
	Team(const Team&) = default;
	Team(Team&& other) noexcept;

	void setName(const string& name) noexcept(false);
	void setNumberOfWins(int wins) noexcept(false);
	void setNumberOfLoses(int loses) noexcept(false);
	void setCourt(const Court& court) { this->court = court; }
	void setOwner(const Owner& other) { this->owner = other; }

	const Court& getCourt() const { return court; }
	const string& getName() const { return teamName; }
	int getNumberOfWins() const { return numberOfWins; }
	int getNumberOfLoses() const { return numberOfLoses; }
	int	getNumberOfPlayers() const { return (int)players.size(); }

	const Team& operator+=(const Player& other) noexcept(false);
	Team& operator=(const Team&) = default;
	
	friend ostream& operator<<(ostream& os, const Team& team)
	{
		os << "Team " << team.teamName << ", owner by: " << team.owner << ", Home court: " << team.court << endl;
		for (auto player = team.players.begin(); player != team.players.end(); ++player)
		{
			os << **player << endl;
		}
		return os;
	}

};

#endif // __TEAM_H