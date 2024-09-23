#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>
#include "employee.h"

class Player : public Employee
{
public:
    enum ePositionType { POINT_GUARD, SHOOTING_GUARD, SMALL_FORWARD,
        POWER_FORWARD, CENTER, eNumOfTypes };
    static constexpr const char* positionNames[ePositionType::eNumOfTypes] =
    { "Point Guard", "Shooting Guard", "Small Forward", "Power Forward", "Center" };

    Player(const Employee& e, int playerNumber, ePositionType position,
        int numberOfTitles, int numberOfMatches) noexcept(false);

    int getPlayerNumber() const;
    ePositionType getPlayerPosition() const;
    int getPlayerTitles() const;

    void setPlayerNumber(int number) noexcept(false);
    void setPlayerTitles(int newTitles) noexcept(false);
    void setPlayerPosition(ePositionType pos) noexcept(false);

    Player& operator++();
    virtual Person* clone() const override;

    virtual void toOs(std::ostream& os) const override;

private:
    int playerNumber;
    ePositionType position;
    int numberOfTitles;
    int numberOfMatches;
};

#endif // __PLAYER_H
