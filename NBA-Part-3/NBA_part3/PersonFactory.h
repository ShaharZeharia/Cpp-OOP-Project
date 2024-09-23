#ifndef __PERSON_FACTORY_H
#define __PERSON_FACTORY_H

#include "PlayerOwner.h"
#include "MostAssistAward.h"
#include "SpecialAward.h"
#include "FastestPlayerAward.h"
#include "Referee.h"

class PersonFactory {
public:
    enum PersonType { OWNER, PLAYER, REFEREE };

    static Person* createPerson(PersonType type) noexcept(false);
    
    static void createDate(Date* date);
    static void createPerson(int* pid, string& name, Date* date, Person::eGenderType* gender, string& address);
    static void createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary);
    static Owner* createOwner() noexcept(false);
    static Player* createPlayer() noexcept(false);
    static Player* addAwards(Player& p);
    static Referee* createReferee() noexcept(false);
};

#endif // __PERSON_FACTORY_H