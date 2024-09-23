#include "Team.h"

Team::Team(const char* teamName, const Owner& owner, const Court& court,
	const Player* players, int numOfPlayers)
	: rOwner(owner), rCourt(court), numberOfPlayers(numOfPlayers), numberOfLoses(0),
	numberOfWins(0)
{
	setName(teamName);
	if (players != nullptr)
	{
		allPlayers = (Player**)malloc(numOfPlayers * sizeof(Player*));
		if (allPlayers == NULL)
			throw "Allocation error";
		for (int i = 0; i < numOfPlayers; i++)
		{
			allPlayers[i] = new Player(players[i]);
		}
	}
}

Team::Team(const Team& other) noexcept: teamName(other.teamName), rOwner(other.rOwner),
rCourt(other.rCourt), allPlayers(other.allPlayers),
numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses),
numberOfPlayers(other.numberOfPlayers) {}

Team::Team(Team&& other) noexcept: teamName(other.teamName), rOwner(other.rOwner),
rCourt(other.rCourt), allPlayers(other.allPlayers),
numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses),
numberOfPlayers(other.numberOfPlayers) 
{
	other.allPlayers = nullptr;
}

Team::~Team()
{
	delete[] teamName;
	delete[] allPlayers;
}

void Team::setName(const char* name)
{
	if (name == nullptr || strlen(name) == 0)
		throw("Invalid name");

	delete[] teamName;
	teamName = new char[strlen(name) + 1];
	strcpy(teamName, name);
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
	for (int i = 0; i < numberOfPlayers; i++)
	{
		if (other.getPID() == allPlayers[i]->getPID())
			throw "Player already in team";
	}
	allPlayers = (Player**)realloc(allPlayers, (size_t)(numberOfPlayers + 1) * sizeof(Player*));
	if (allPlayers == nullptr)
		throw "Error allocating";

	allPlayers[numberOfPlayers++] = new Player(other);
	return *this;
}//Add Player

Team& Team::operator=(const Team& other)
{
	if (this != &other)
	{
		delete[] teamName;
		for (int i = 0; i < numberOfPlayers; i++)
		{
			delete allPlayers[i];
		}
		delete[] allPlayers;

		rOwner = other.rOwner;
		rCourt = other.rCourt;
		numberOfWins = other.numberOfWins;
		numberOfLoses = other.numberOfLoses;
		numberOfPlayers = other.numberOfPlayers;

		teamName = new char[strlen(other.teamName) + 1];
		strcpy(teamName, other.teamName);


		if (other.allPlayers != nullptr)
		{
			allPlayers = new Player * [numberOfPlayers];
			for (int i = 0; i < numberOfPlayers; i++)
			{
				allPlayers[i] = new Player(*other.allPlayers[i]);
			}
		}
		else
		{
			allPlayers = nullptr;
		}
	}
	return *this;
}
