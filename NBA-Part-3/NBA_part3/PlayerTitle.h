#ifndef __PLAYER_TITLE_H
#define __PLAYER_TITLE_H

#include <iostream>
using namespace std;

#include "Player.h"

class PlayerAward : public Player {
protected:
    const Player* awardedPlayer;
    int year;

public:
    PlayerAward(const Player& player, int year) : Person(player), Player(player),
        awardedPlayer(&player) {
        setYear(year);
    }

    void setYear(const int year) noexcept(false)
    {
        if (year >= MIN_YEAR && year <= MAX_YEAR)
            this->year = year;
        else
            throw "Invalid year";
    }

    virtual ~PlayerAward() { delete awardedPlayer; }

    virtual Person* clone() const override { return new PlayerAward(*this); }

    virtual void toOs(ostream& os) const override{
        awardedPlayer->toOs(os);
        os << "Awarded in " << year << " for: " << endl;
    }
};

#endif // __PLAYER_DECORATOR_H