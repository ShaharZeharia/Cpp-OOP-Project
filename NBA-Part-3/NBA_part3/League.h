#ifndef __LEAGUE_H
#define __LEAGUE_H

#include "District.h"
#include "LinkedList.h"
#include "MostAssistAward.h"
#include <iostream>
#include <list>
using namespace std;

class League
{
protected:
    static constexpr int NUMBER_OF_DISTRICTS = 2;
    list<District*> allDistricts;
    list<Person*> allWorkers;
    LinkedList<Owner> allOwners;
    static League NBA;

    League(); 

    League(const League& other) = delete;
    League& operator=(const League& other) = delete;

public:
    static League* getInstance() {
        return &NBA;
    }

    League(League&& other) noexcept;

    list<District*>& getDistricts() { return allDistricts; }
    int getCurrentNumberOfWorkers() const { return (int)allWorkers.size(); }
    int getNumberOfOwners() const { return allOwners.getSize(); }
    list<Person*>& getAllWorkers() { return allWorkers; }
    const LinkedList<Owner> getAllOwners() const { return allOwners; }
    list<Referee*>& getAllReferees() noexcept(false);
    list<Player*>& getAllPlayers() noexcept(false);

    void setDistrict(const District& d);

    const League& operator+=(const Person& p) noexcept(false);
    const League& operator+=(const Owner& o) noexcept(false);

    friend ostream& operator<<(ostream& os, const League& league)
    {
        os << "League details:\n"
            << "Number of workers: " << league.getCurrentNumberOfWorkers() << endl;
        for (auto worker = league.allWorkers.begin(); worker != league.allWorkers.end(); ++worker)
            os << **worker << endl;
        os << "Number of owners: " << league.getNumberOfOwners() << endl;
        league.allOwners.print();
        os << "League districts: " << endl;
        for (auto district : league.allDistricts)
            os << *district << endl;
        return os;
    }
};

#endif // LEAGUE