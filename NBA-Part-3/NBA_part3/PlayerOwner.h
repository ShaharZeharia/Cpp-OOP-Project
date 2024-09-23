#ifndef __PLAYEROWNER_H
#define __PLAYEROWNER_H

#include <iostream>
using namespace std;
#include "Player.h"
#include "owner.h"

class PlayerOwner : public Player, public Owner
{
public:
    PlayerOwner(const Player& p, const Owner& o) noexcept(false);
    PlayerOwner(const PlayerOwner&) = default;

    PlayerOwner& operator=(const PlayerOwner&) = default;
    virtual Person* clone() const override;

    virtual void toOs(ostream& os) const override;
};

#endif // __PLAYEROWNER_H