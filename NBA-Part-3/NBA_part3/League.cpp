#include "League.h"

League League::NBA;

League::League() // Constructor is private now
{
    allDistricts.push_back(new District());
    allDistricts.push_back(new District(District::eAreaType::WEST));
}

League::League(League&& other) noexcept : allWorkers(other.allWorkers), allOwners(other.allOwners),
allDistricts(other.allDistricts)
{
}

list<Referee*>& League::getAllReferees() {
    list<Referee*> refs;
    for (auto worker : allWorkers) {
        if (typeid(*worker) == typeid(Referee))
            refs.push_back(dynamic_cast<Referee*>(worker->clone()));
    }
    return refs;
}

list<Player*>& League::getAllPlayers()
{
    list<Player*> players;
    for (auto worker : allWorkers) {
        if (typeid(*worker) == typeid(Player))
            players.push_back(dynamic_cast<Player*>(worker->clone()));
    }
    return players;
}

void League::setDistrict(const District& d)
{
    auto it = allDistricts.begin();
    if (d.getArea() == District::eAreaType::EAST)
    {
        delete* it;
        *it = new District(d);
    }
    else
    {
        ++it;
        delete* it;
        *it = new District(d);
    }
}

const League& League::operator+=(const Person& p) noexcept(false)
{
    allWorkers.push_back(p.clone());
    return *this;
}

const League& League::operator+=(const Owner& o)
{
    allOwners.addNodeToEnd(o);
    return *this;
}