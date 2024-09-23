#include "Player.h"
#include <stdexcept>

Player::Player(const Employee& e, int playerNumber, ePositionType position,
    int numberOfTitles, int numberOfMatches)
    : Person(e), Employee(e), playerNumber(playerNumber), position(position),
    numberOfTitles(numberOfTitles), numberOfMatches(numberOfMatches)
{
    if (playerNumber <= 0) {
        throw "Player number must be positive";
    }
    if (numberOfTitles < 0 || numberOfMatches < 0) {
        throw "Number of titles and matches must be non-negative";
    }
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

Player::ePositionType Player::getPlayerPosition() const {
    return position;
}

int Player::getPlayerTitles() const {
    return numberOfTitles;
}

void Player::setPlayerNumber(int number) {
    if (number <= 0) {
        throw invalid_argument("Player number must be positive.");
    }
    playerNumber = number;
}

void Player::setPlayerTitles(int newTitles) {
    if (newTitles < 0) {
        throw invalid_argument("Number of titles must be non-negative.");
    }
    numberOfTitles = newTitles;
}

void Player::setPlayerPosition(ePositionType pos)
{
    if (pos < 0 || pos >= eNumOfTypes) {
        throw invalid_argument("Invalid position type");
    }
    position = pos;
}

Player& Player::operator++() {
    ++numberOfTitles;
    return *this;
}

Person* Player::clone() const {
    return new Player(*this);
}

void Player::toOs(std::ostream& os) const {
    Employee::toOs(os);
    os << ", Player Number: " << playerNumber
        << ", Position: " << positionNames[position]
        << ", Titles: " << numberOfTitles
        << ", Matches: " << numberOfMatches;
}