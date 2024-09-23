#include "District.h"

const string District::areas[eNumOfTypes] = { "East", "West" };

District::District(eAreaType area)
    : area(area)
{
}

void District::setArea(const eAreaType area)noexcept(false) {
    if (area < 0 || area >= eNumOfTypes)
        throw ("Invalid area");

    this->area = area;
}

const District& District::operator+(const Team& toAdd) noexcept(false)
{
    if (teams.size() < NUMBER_OF_TEAMS) 
        teams.push_back(new Team(toAdd));
    else 
        throw("Cannot add more teams. Maximum number reached.");
    return *this;
}


const District& District::operator+(const Match& toAdd)noexcept(false)
{
    if (matches.size() < NUMBER_OF_GAMES_SEASON) 
        matches.push_back(new Match(toAdd));
    else 
        throw("Cannot add more matches. Maximum number reached.");
    return *this;
}
