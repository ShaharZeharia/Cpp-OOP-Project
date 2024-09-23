#ifndef __DISTRICT_H
#define __DISTRICT_H

#include <iostream>
#include "Team.h"
#include "Match.h"
using namespace std;

class District
{
public:
	static constexpr int NUMBER_OF_TEAMS = 12;
	static constexpr int NUMBER_OF_GAMES_SEASON = 72;
	enum eAreaType { EAST = 1, WEST, eNumOfTypes };
	static constexpr const char* areas[eNumOfTypes] = { "East", "West" };

	District(eAreaType area = EAST, Team** teams = nullptr, int numTeams = 0,
		Match** matches = nullptr, int numMatches = 0);

	const District& operator+(const Team& toAdd) noexcept(false);
	const District& operator+(const Match& toAdd) noexcept(false);

	eAreaType getArea() const { return area; }
	Team*const* getTeams() const { return pAllTeams; }
	const Match*const* getMatches() const { return pAllMatches; }
	int getNumberOfTeams() const { return currentNumberOfTeams; }
	int getNumberOfMatches() const { return currentNumberOfMatches; }

	void setArea(eAreaType area) noexcept(false);

	friend ostream& operator<<(ostream& os, const District& district)
	{
		os << "District Area: " << District::areas[district.area] << endl;
		os << "Teams (" << district.currentNumberOfTeams << "):" << endl;
		for (int i = 0; i < district.currentNumberOfTeams; i++) {
			os << district.pAllTeams[i] << endl;
		}
		os << "Matches (" << district.currentNumberOfMatches << "):" << endl;
		for (int i = 0; i < district.currentNumberOfMatches; i++) {
			os << district.pAllMatches[i] << endl;
		}
		return os;
	}

protected:
	eAreaType area;
	Team* pAllTeams[NUMBER_OF_TEAMS];
	Match* pAllMatches[NUMBER_OF_GAMES_SEASON];
	int currentNumberOfTeams;
	int currentNumberOfMatches;
};

#endif //__DISTRICT_H