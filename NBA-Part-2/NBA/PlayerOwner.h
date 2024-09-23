#ifndef __PLAYEROWNER_H
#define __PLAYEROWNER_H

#include "player.h"
#include "owner.h"

class PlayerOwner : public Player, public Owner
{
public:
    PlayerOwner(const Player& p, const Owner& o) noexcept(false);

    virtual Person* clone() const override;

    virtual void toOs(ostream& os) const override;
};

#endif // __PLAYEROWNER_H