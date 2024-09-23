#include "playerowner.h"

PlayerOwner::PlayerOwner(const Player& p, const Owner& o)
    : Person(p), Player(p), Owner(o)
{}

Person* PlayerOwner::clone() const {
    return new PlayerOwner(*this);
}

void PlayerOwner::toOs(ostream& os) const {
    Owner::toOs(os);
    Player::toOs(os);
}