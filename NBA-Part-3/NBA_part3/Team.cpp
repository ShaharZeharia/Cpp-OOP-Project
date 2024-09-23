#include "Team.h"

Team::Team(const string& teamName, const Owner& owner, const Court& court)
	: owner(owner), court(court), numberOfLoses(0),
	numberOfWins(0) , players(players)
{
	setName(teamName);
}

Team::Team(Team&& other) noexcept : teamName(other.teamName), owner(other.owner),
court(other.court), players(other.players),
numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses)
{
}

void Team::setName(const std::string& name)
{
	if (name.empty())
		throw("Invalid name");

	teamName = name;
}

void Team::setNumberOfWins(int wins)
{
	if (wins >= 0)
		numberOfWins = wins;
	else
		throw "Invalid number of wins";
}

void Team::setNumberOfLoses(int loses)
{
	if (loses >= 0)
		numberOfLoses = loses;
	else
		throw "Invalid number of loses";
}

const Team& Team::operator+=(const Player& other) noexcept(false)
{
	for (auto player : players)
	{
		if (other.getPID() == player->getPID())
			throw "Player already in team";
	}
	players.push_back(new Player(other));
	return *this;
}//Add Player
