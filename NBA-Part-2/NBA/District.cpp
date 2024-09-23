#include "District.h"

District::District(eAreaType area, Team** teams, int numTeams, Match** matches, int numMatches)
    : area(area), currentNumberOfTeams(0), currentNumberOfMatches(0)
{
    for (int i = 0; i < NUMBER_OF_TEAMS; i++) {
        if (teams != nullptr && i < numTeams) {
            pAllTeams[i] = teams[i];
            currentNumberOfTeams++;
        }
        else {
            pAllTeams[i] = nullptr;
        }
    }

    for (int i = 0; i < NUMBER_OF_GAMES_SEASON; i++) {
        if (matches != nullptr && i < numMatches) {
            pAllMatches[i] = matches[i];
            currentNumberOfMatches++;
        }
        else {
            pAllMatches[i] = nullptr;
        }
    }
}

void District::setArea(const eAreaType area)noexcept(false) {
    if (area < 0 || area >= eNumOfTypes)
        throw ("Invalid area");

    this->area = area;
}

const District& District::operator+(const Team& toAdd) noexcept(false)
{
    if (currentNumberOfTeams < NUMBER_OF_TEAMS) {
        pAllTeams[currentNumberOfTeams] = new Team(toAdd);
        currentNumberOfTeams++;
    }
    else {
        throw("Cannot add more teams. Maximum number reached.");
    }
    return *this;
}


const District& District::operator+(const Match& toAdd)noexcept(false)
{
    if (currentNumberOfMatches < NUMBER_OF_GAMES_SEASON) {
        pAllMatches[currentNumberOfMatches] = new Match(toAdd);
        currentNumberOfMatches++;
    }
    else {
        throw("Cannot add more matches. Maximum number reached.");
    }
    return *this;
}
