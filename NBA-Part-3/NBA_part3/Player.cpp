#include "Player.h"
#include <stdexcept>

const string Player::positionNames[ePositionType::eNumOfTypes] =
{ "Point Guard", "Shooting Guard", "Small Forward", "Power Forward", "Center" };

Player::Player(const Employee& e, int playerNumber, ePositionType position,
    int numberOfMatches)
    : Person(e), Employee(e), playerNumber(playerNumber), position(position),
    numberOfMatches(numberOfMatches)
{
    if (playerNumber <= 0) {
        throw "Player number must be positive";
    }
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

Player::ePositionType Player::getPlayerPosition() const {
    return position;
}

void Player::setPlayerNumber(int number) {
    if (number <= 0) {
        throw invalid_argument("Player number must be positive.");
    }
    playerNumber = number;
}

void Player::setPlayerPosition(ePositionType pos)
{
    if (pos < 0 || pos >= eNumOfTypes) {
        throw invalid_argument("Invalid position type");
    }
    position = pos;
}

Player& Player::operator++() {
    ++numberOfMatches;
    return *this;
}

Person* Player::clone() const {
    return new Player(*this);
}

void Player::toOs(ostream& os) const {
    Employee::toOs(os);
    os << "player Number: " << playerNumber
        << ", position: " << positionNames[position]
        << ", matches: " << numberOfMatches << endl;
}