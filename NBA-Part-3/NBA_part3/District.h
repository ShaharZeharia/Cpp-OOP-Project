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
	enum eAreaType { EAST, WEST, eNumOfTypes };
	static const string areas[eNumOfTypes];

	District(eAreaType area = EAST);
	District(const District&) = default;

	const District& operator+(const Team& toAdd) noexcept(false);
	const District& operator+(const Match& toAdd) noexcept(false);

	eAreaType getArea() const { return area; }
	list<Team*> getTeams() const { return teams; }
	list<Match*> getMatches() const { return matches; }
	int getNumberOfTeams() const { return (int)teams.size(); }
	int getNumberOfMatches() const { return (int)matches.size(); }

	void setArea(eAreaType area) noexcept(false);

	District& operator=(const District&) = default;
	friend ostream& operator<<(ostream& os, const District& district)
	{
		os << "District Area: " << District::areas[district.area] << endl;
		os << "Teams (" << district.getNumberOfTeams() << "):" << endl;
		for (auto team : district.teams) {
			os << *team << endl;
		}
		os << "Matches (" << district.getNumberOfMatches() << "):" << endl;
		for (auto match : district.matches) {
			os << *match << endl;
		}
		return os;
	}

protected:
	eAreaType area;
	list<Team*> teams;
	list<Match*> matches;
};

#endif //__DISTRICT_H