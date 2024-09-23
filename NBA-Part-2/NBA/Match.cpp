#include "Match.h"

Match::Match(const Referee& ref, const Team& teamA, const Team& teamB,
    const Date& gameDate, const Court& court) 
    : referee(ref), teamA(teamA), teamB(teamB), gameDate(gameDate),
    gameCourt(court), resultA(0), resultB(0)
{}

Match::Match(const Referee& ref, const Team& teamA, const Team& teamB,
    const Date& gameDate, const Court& court, int resultA, int resultB) noexcept(false)
    : referee(ref), teamA(teamA), teamB(teamB), gameDate(gameDate), gameCourt(court)
{
    setResultA(resultA);
    setResultB(resultB);
}

void Match::setResultA(int result) noexcept(false) {
    if (result < 0) {
        throw("Result cannot be negative");
    }
    resultA = result;
}

void Match::setResultB(int result) noexcept(false) {
    if (result < 0) {
        throw("Result cannot be negative");
    }
    resultB = result;
}
