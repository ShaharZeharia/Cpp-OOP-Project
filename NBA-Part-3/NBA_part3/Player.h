#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>
using namespace std;
#include "employee.h"

class Player : public Employee
{
public:
    enum ePositionType { POINT_GUARD, SHOOTING_GUARD, SMALL_FORWARD,
        POWER_FORWARD, CENTER, eNumOfTypes };
    static const string positionNames[ePositionType::eNumOfTypes];;

    Player(const Employee& e, int playerNumber, ePositionType position,
        int numberOfMatches) noexcept(false);
    Player(const Player&) = default;

    int getPlayerNumber() const;
    ePositionType getPlayerPosition() const;

    void setPlayerNumber(int number) noexcept(false);
    void setPlayerPosition(ePositionType pos) noexcept(false);

    Player& operator++();
    Player& operator=(const Player&) = default;
    virtual Person* clone() const override;

    virtual void toOs(ostream& os) const override;

private:
    int playerNumber;
    ePositionType position;
    int numberOfMatches;
};

#endif // __PLAYER_H
