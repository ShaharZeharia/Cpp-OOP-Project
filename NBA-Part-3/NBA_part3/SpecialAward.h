#ifndef __PLAYER_SPECIAL_H
#define __PLAYER_SPECIAL_H

#include <iostream>
using namespace std;

#include "PlayerTitle.h"

class SpecialAward : public PlayerAward {
protected:
    string specialAward;

public:
    SpecialAward(const Player& player, const string& specialAward, int year) noexcept(false) : Person(player),
        PlayerAward(player, year)
    {
        setSpecialAward(specialAward);
    }

    const string& getSpecialAward() const { return specialAward; }

    void setSpecialAward(const string& specialAward) noexcept(false)
    {
        if (specialAward.empty())
            throw "Invalid award, must not be empty";
        this->specialAward = specialAward;
    }

    virtual Person* clone() const override { return new SpecialAward(*this); }

    virtual void toOs(ostream& os) const override {
        PlayerAward::toOs(os);
        os << "Special award: " << specialAward << endl;
    }
};

#endif // __PLAYER_DECORATOR_H