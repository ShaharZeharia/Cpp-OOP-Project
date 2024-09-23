
#include "PersonFactory.h"
#include "GeneralFunctions.h"
#include "League.h"

Person* PersonFactory::createPerson(PersonType type) {

    switch (type) {
    case OWNER:
        // Use your existing createOwner function
        return createOwner();

    case PLAYER:
        // Use your existing helper functions for creating a Player
        return createPlayer();

    case REFEREE:
        // Use your existing helper functions for creating a Referee
        return createReferee();

    default:
        throw "Unknown PersonType";
    }
}

void PersonFactory::createDate(Date* date) {
    int day = -1, month = -1, year = -1;
    do
    {
        day = getIntWithPrompt("Please enter day: ");
    } while (day == -1);
    do
    {
        month = getIntWithPrompt("Please enter month: ");
    } while (month == -1);
    do
    {
        year = getIntWithPrompt("Please enter year: ");
    } while (year == -1);
    *date = Date(day, month, year);
}

void PersonFactory::createPerson(int* pid, string& name, Date* date, Person::eGenderType* gender, string& address)
{
    *pid = getIntWithPrompt("Please enter person ID - must be a valid ID number:");
    name = getStrExactName("Please enter person name:");
    cout << "Date of Birth" << endl;
    createDate(date);
    *gender = static_cast<Person::eGenderType>(getEnumSelection("Please choose gender:", Person::genders, Person::eNumOfTypes));
    address = getStrExactName("Please enter person's address:");
}

void PersonFactory::createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary)
{
    createPerson(pid, name, date, gender, address);
    do
    {
        *salary = getFloatWithPrompt("Please enter salary - must be positive: ");
    } while (*salary <= 0.0);
}

Owner* PersonFactory::createOwner()
{
    float budget;
    int pid;
    string name, address;
    Person::eGenderType gender;
    Date* date = new Date();

    createPerson(&pid, name, date, &gender, address);
    do
    {
        budget = getFloatWithPrompt("Please enter budget - must be non-negative float: ");
    } while (budget < 0.0);
    return new Owner(pid, name, *date, gender, address, budget);
}

Player* PersonFactory::createPlayer()
{
    float salary;
    int selection, playerNumber, numOfMatches;
    Player::ePositionType position;
    Player* p;
    playerNumber = getIntWithPrompt("Please enter player's number:");
    position = static_cast<Player::ePositionType>(getEnumSelection("Please choose player's position:",
        Player::positionNames, Player::eNumOfTypes));
    do
    {
        numOfMatches = getIntWithPrompt("Please enter player's number of games:");
    } while (numOfMatches < 0);
    do
    {
        cleanBuffer();
        cout << "Is the player an owner? [1: Yes, 2: No]" << endl;
        cin >> selection;
    } while (selection != 1 && selection != 2);
    if (selection % 2 == 1)     //Player is an owner
    {
        Owner* o = createOwner();
        do
        {
            salary = getFloatWithPrompt("Please enter salary - must be positive:");
        } while (salary < 0.0);
        p = new PlayerOwner(Player(Employee(o->getPID(), o->getName(), o->getDOB(),
            o->getGender(), o->getAddress(), salary), playerNumber, position, numOfMatches), *o);
    }
    else                        //Player is a new employee
    {
        int pid;
        string name, address;
        Person::eGenderType gender;
        Date* date = new Date();
        createEmployee(&pid, name, date, &gender, address, &salary);
        p = new Player(Employee(pid, name, *date, gender, address, salary),
            playerNumber, position, numOfMatches);
    }
    return addAwards(*p);
}

Player* PersonFactory::addAwards(Player& p)
{
    int selection;
    Player* currentPlayer = &p;

    do
    {
        cout << "Do you want to add awards to player? [1: Yes, 2: No]" << endl;
        cin >> selection;
        cleanBuffer();

        if (selection == 1)
        {
            cout << "Choose award to add: " << endl;
            cout << "1) Most assists award" << endl;
            cout << "2) Fastest player award" << endl;
            cout << "3) Special award" << endl;
            cout << "4) Exit adding awards" << endl;
            cin >> selection;

            switch (selection)
            {
                int year = getIntWithPrompt("Enter year for award: ");
            case(1):
            {
                int assists = getIntWithPrompt("Enter number of assists: ");
                currentPlayer = new MostAssistsAward(*currentPlayer, assists, year);
                break;
            }
            case(2):
            {
                float speed = getFloatWithPrompt("Enter the player's speed: ");
                currentPlayer = new FastestPlayerAward(*currentPlayer, speed, year);
                break;
            }
            case(3):
            {
                string specialAward = getStrExactName("Enter the special award description:");
                currentPlayer = new SpecialAward(*currentPlayer, specialAward, year);
                break;
            }
            case(4):
                cout << "Exiting award addition." << endl;
                return currentPlayer;
            default:
                cout << "Invalid input ,please enter the correct number" << endl;
                cleanBuffer();
                break;
            }
        }
        else if (selection == 2)
            return currentPlayer;
    } while (true);
}

Referee* PersonFactory::createReferee()
{
    int pid, numOfMatches;
    float rank, salary;
    string name, address;
    Person::eGenderType gender;
    Date* date = new Date();
    createEmployee(&pid, name, date, &gender, address, &salary);
    rank = getFloatWithPrompt("Please enter rank - a float bigger than 0.0 and smaller than 10.0:");
    do
    {
        numOfMatches = getIntWithPrompt("Please enter number of matches - must be non-negative number:");
    } while (numOfMatches < 0);
    return new Referee(Employee(pid, name, *date, gender, address, salary), rank, numOfMatches);
}