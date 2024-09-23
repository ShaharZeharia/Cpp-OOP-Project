#ifndef __PLAYER_ASSISTS_H
#define __PLAYER_ASSISTS_H

#include <iostream>
using namespace std;

#include "PlayerTitle.h"

class MostAssistsAward : public PlayerAward {
protected:
    int numOfAssists;

public:
    MostAssistsAward(const Player& player, int numOfAssists, int year) noexcept(false) : Person(player),
        PlayerAward(player, year)
    {
        setNumOfAssists(numOfAssists);
    }

    int getNumOfAssists() const { return numOfAssists; }

    void setNumOfAssists(int numOfAssists) noexcept(false)
    {
        if (numOfAssists < 0)
            throw "Invalid number of assists, cannot be a negative number";
        this->numOfAssists = numOfAssists;
    }

    virtual Person* clone() const override { return new MostAssistsAward(*this); }

    virtual void toOs(ostream& os) const override {
        PlayerAward::toOs(os);
        os << "Most assists title, with " << numOfAssists << " assists\n";
    }
};

#endif // __PLAYER_DECORATOR_H