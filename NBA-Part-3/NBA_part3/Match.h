#ifndef __MATCH_H
#define __MATCH_H

#include <iostream>
#include "Referee.h"
#include "Date.h"
#include "Team.h"
#include "Court.h"

using namespace std;

class Match
{
protected:
	Referee referee;
	Team teamA;
	Team teamB;
	int resultA;
	int resultB;
	Date gameDate;
	Court gameCourt;

public:
	Match(const Referee& ref, const Team& teamA, const Team& teamB, const Date& gameDate, const Court& court);
	Match(const Referee& ref, const Team& teamA, const Team& teamB, const Date& gameDate, const Court& court, int resultA, int resultB) noexcept(false);

	const Referee& getReferee() const { return referee; }
	const Team& getTeamA() const { return teamA; }
	const Team& getTeamB() const { return teamB; }
	const Court& getCourt() const { return gameCourt; }
	int getResultA() const { return resultA; }
	int getResultB() const { return resultB; }
	const Date& getDate() const { return gameDate; }

	void setReferee(const Referee& ref) { referee = ref; }
	void setTeamA(const Team& team) { teamA = team; }
	void setTeamB(const Team& team) { teamB = team; }
	void setDate(const Date& date) { gameDate = date; }
	void setCourt(const Court& court) { gameCourt = court; }
	void setResultA(int result) noexcept(false);
	void setResultB(int result) noexcept(false);

	friend ostream& operator<<(ostream& os, const Match& match)
	{
		os << "Referre details: " << match.referee
			<< ", game date: " << match.gameDate
			<< ", game court: " << match.gameCourt << endl
			<< ", home team: " << match.teamA
			<< ", home score: " << match.resultA << endl
			<< ", away team: " << match.teamB
			<< ", away score: " << match.resultB << endl;
		return os;
	}
};

#endif // __MATCH_H