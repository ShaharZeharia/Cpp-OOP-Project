#ifndef __FASTEST_PLAYER_TITLE_H
#define __FASTEST_PLAYER_TITLE_H

#include <iostream>
using namespace std;

#include "PlayerTitle.h"

class FastestPlayerAward : public PlayerAward {
protected:
    float speed;

public:
    FastestPlayerAward(const Player& player, float speed, int year) noexcept(false) : Person(player),
        PlayerAward(player, year)
    {
        setSpeed(speed);
    }

    float getSpeed() const { return speed; }

    void setSpeed(float speed) noexcept(false)
    {
        if (speed <= 0)
            throw "Invalid speed, must be a positive number";
        this->speed = speed;
    }

    virtual Person* clone() const override { return new FastestPlayerAward(*this); }

    virtual void toOs(ostream& os) const override {
        PlayerAward::toOs(os);
        os << "Fastest player title, with a time of: " << speed << " seconds in 200 feet dash\n";
    }
};

#endif // __FASTEST_PLAYER_TITLE_H