#include <iostream>
#include <string>
using namespace std;
#include "League.h"
#include "GeneralFunctions.h"
#include "PersonFactory.h"
/*
* C++ project - NBA league
* by: MAX FELDMAN AND SHACHAR ZEHARIA
*/

// Statics
//static constexpr int MAX_STR_LEN = 255;
static constexpr int EXIT = -1;

// Helpers
void addPlayerToTeamMenu(District& d, Player* p) noexcept(false);
void showLeagueMenu(League& l);
void showDistrictMenu(League& l, District& d);
void showNewWorkerMenu(League& l, District& d);

Team* createTeam(list<Player*> players, LinkedList<Owner> allOwners) noexcept(false);
Match* createMatch(const list<Team*> teams, list<Referee*> refs) noexcept(false);

void displayMenu();
void cleanBuffer();

enum eChoice { NEW_TEAM = 1, NEW_WORKER, NEW_MATCH, PRINT_TEAM, PRINT_WORKER, PRINT_MATCH };
enum eChoiceInner { NEW_OWNER = 1, NEW_PLAYER, NEW_REFREE };


int main()
{
    League& l1 = *League::getInstance();
    showLeagueMenu(l1);
    return 0;
}

/* Helpers */

void showLeagueMenu(League& l)
{
    int choice;
    list<District*> d = l.getDistricts();
    cout << "*** NBA League Creator ***" << endl;
    cout << "*** each NBA League has 2 districts (East, West) ***" << endl;
    do
    {
        cout << "Select district:" << endl;
        cout << "1) East" << endl;
        cout << "2) West" << endl;
        cout << "-1) Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case (District::EAST + 1):
        {
            showDistrictMenu(l, **d.begin());
            break;
        }

        case District::WEST + 1:
        {
            showDistrictMenu(l, **d.end());
            break;
        }

        case EXIT:
            cout << "Thanks for using me, bye :)";
            return;

        default:
        {
            cout << "Invalid input ,please enter the correct number" << endl;
            cleanBuffer();
            break;
        }
        }
    } while (choice < 1 || choice > 2);
}


void showDistrictMenu(League& l, District& d)
{
    int selection = 0;
    cout << "*** NBA District Creator ***" << endl;
    while (true)
    {
        displayMenu();
        try {
            cin >> selection;

            switch (selection)
            {
            case NEW_TEAM:
            {
                cout << "*** Team Creation ***" << endl;
                Team* t = createTeam(l.getAllPlayers(), l.getAllOwners());
                d + *t;
                break;
            }

            case NEW_WORKER:
            {
                showNewWorkerMenu(l, d);
                break;
            }

            case NEW_MATCH:
            {
                cout << "*** Match Creation ***" << endl;
                int numOfRefs = 0;
                d = d + *createMatch(d.getTeams(), l.getAllReferees());
                break;
            }

            case PRINT_TEAM:
            {
                for (auto team : d.getTeams())
                    cout << *team << endl;
                break;
            }

            case PRINT_WORKER:
            {
                list<Person*> workers = l.getAllWorkers();
                for (Person* worker : workers)
                    cout << *worker << endl;
                break;
            }

            case PRINT_MATCH:
            {
                for (auto match : d.getMatches())
                    cout << *match << endl;
                break;
            }

            case EXIT:
                return;

            default:
            {
                cout << "Invalid input, please enter the correct number" << endl;
                cleanBuffer();
                break;
            }
            }
        }
        catch (const char* msg) {
            cleanBuffer();
            cout << msg << endl;
        }
    }
}

void displayMenu() {
    cout << "Select district:" << endl;
    cout << "1) Create a new Team" << endl;
    cout << "2) Create a new Worker (Owner | Refree | Player)" << endl;
    cout << "3) Create a new Match" << endl;
    cout << "4) Print Team" << endl;
    cout << "5) Print Workers" << endl;
    cout << "6) Print Matches" << endl;
    cout << "-1) Exit" << endl;
}


void showNewWorkerMenu(League& l, District& d)
{
    int selection;
    cout << "*** Worker Creation ***" << endl;
    cout << "Enter kind of worker:" << endl;
    do
    {
        cout << "1) Owner" << endl;
        cout << "2) Player" << endl;
        cout << "3) Refree" << endl;
        cout << "-1) Exit" << endl;
        cin >> selection;
        try {
            switch (selection)
            {
            case NEW_OWNER:
            {
                Owner* o = dynamic_cast<Owner*>(PersonFactory::createPerson(PersonFactory::OWNER));
                l += o;
                break;
            }
            case NEW_PLAYER:
            {
                Player* p = dynamic_cast<Player*>(PersonFactory::createPerson(PersonFactory::PLAYER));
                l += p;
                addPlayerToTeamMenu(d, p);
                break;
            }

            case NEW_REFREE:
            {
                Referee* r = dynamic_cast<Referee*>(PersonFactory::createPerson(PersonFactory::REFEREE));
                l += r;
                break;
            }

            case EXIT:
                return;

            default:
            {
                cout << "Invalid input ,please enter the correct number" << endl;
                cleanBuffer();
                break;
            }
            }
        }
        catch (char* msg) {
            cleanBuffer();
            cout << msg << endl;
        }
    } while (selection < 1 || selection > 3);
}



//void createPerson(int* pid, char** name, Date* date, Person::eGenderType* gender, char** address)
//{
//    *pid = getIntWithPrompt("Please enter person ID - must be a valid ID number:");
//    *name = getStrExactName("Please enter person name: ");
//    cout << "Date of Birth" << endl;
//    createDate(date);
//    *gender = static_cast<Person::eGenderType>(getEnumSelection("Please choose gender:", Person::genders, Person::eNumOfTypes));
//    *address = getStrExactName("Please enter person's address: ");
//}




//void createEmployee(int* pid, char** name, Date* date, Person::eGenderType* gender, char** address, float* salary)
//{
//    createPerson(pid, name, date, gender, address);
//    do
//    {
//        *salary = getFloatWithPrompt("Please enter salary - must be positive: ");
//        cleanBuffer();
//    } while (*salary <= 0.0);
//}




//Owner* createOwner()
//{
//    float budget;
//    int pid;
//    char* name[MAX_STR_LEN],* address[MAX_STR_LEN];
//    Person::eGenderType gender;
//    Date* date = new Date();
//
//    createPerson(&pid, name, date, &gender, address);
//    do
//    {
//        budget = getFloatWithPrompt("Please enter budget - must be non negative float: ");
//        cleanBuffer();
//    } while (budget < 0.0);
//    return new Owner(pid, *name, *date, gender, *address, budget);
//}



//Player* createPlayer()
//{
//    Owner* o;
//    float salary;
//    int selection, playerNumber, numOfTitles, numOfMatches;
//    Player::ePositionType position;
//
//    playerNumber = getIntWithPrompt("Please enter player's number:");
//    position = static_cast<Player::ePositionType>(getEnumSelection("Please choose player's position:", Player::positionNames, Player::eNumOfTypes));
//    do
//    {
//        numOfTitles = getIntWithPrompt("Please enter player's number of titles - must be a non negative number: ");
//        cleanBuffer();
//    } while (numOfTitles < 0);
//    do
//    {
//        numOfMatches = getIntWithPrompt("Please enter player's number of games:");
//        cleanBuffer();
//    } while (numOfMatches < 0);
//    do
//    {
//        cout << "Is the player an owner? [1: Yes, 2: No]" << endl;
//        cin >> selection;
//        cleanBuffer();
//    } while (selection != 1 && selection != 2);
//    if (selection % 2 == 1)        //Player is an owner
//    {
//        o = createOwner();
//        do
//        {
//            salary = getFloatWithPrompt("Please enter salary - must be positive:");
//            cleanBuffer();
//        } while (salary < 0.0);
//        return new PlayerOwner(Player(Employee(o->getPID(), o->getName(), o->getDOB(), o->getGender(), o->getAddress(), salary), playerNumber, position, numOfTitles, numOfMatches), *o);
//    }
//    else                        //Player is a new employee
//    {
//        int pid;
//        char* name[MAX_STR_LEN],* address[MAX_STR_LEN];
//        Person::eGenderType gender;
//        Date* date = new Date();
//        createEmployee(&pid, name, date, &gender, address, &salary);
//        return new Player(Employee(pid, *name, *date, gender, *address, salary), playerNumber, position, numOfTitles, numOfMatches);
//    }
//}





//Referee* createRefree()
//{
//    int pid, numOfMatches;
//    float rank, salary;
//    char* name[MAX_STR_LEN],* address[MAX_STR_LEN];
//    Person::eGenderType gender;
//    Date* date = new Date();
//    createEmployee(&pid, name, date, &gender, address, &salary);
//    rank = getFloatWithPrompt("Please enter rank - a float bigger than 0.0 and smaller than 10.0:");
//    do
//    {
//        numOfMatches = getIntWithPrompt("Please enter number of matches - must be non negative number:");
//        cleanBuffer();
//    } while (numOfMatches < 0);
//    return new Referee(Employee(pid, *name, *date, gender, *address, salary), rank, numOfMatches);
//}





//Team* createTeam(list<Player*> players, LinkedList<Owner> allOwners)
//{
//    if (allOwners.getSize() == 0)
//        throw "no owners to create team.";
//    int selected, numOfSeats = -1;
//    char* teamName = getStrExactName("Please enter team's name: ");
//    cout << "Please choose an owner of the team" << endl;
//    const LinkedList<Owner>::Node* node = allOwners.getHead();
//    int index = 1;
//    while (node)
//    {
//        cout << index << " for " << node->data << endl;
//        node = node->next;
//    }
//    do {
//        cin >> selected;
//        cleanBuffer();
//    } while (selected < 1 && selected > allOwners.getSize());
//    Owner o = allOwners.getIndex(selected)->data;
//    char* courtName = getStrExactName("Please enter court's name: ");
//    do {
//        numOfSeats = getIntWithPrompt("Please enter court's number of seats - must be positive number: ");
//        cleanBuffer();
//    } while (numOfSeats < 1);
//    Team* team = new Team(teamName, o, Court(courtName, numOfSeats));
//    cout << "Team successfully added" << endl;
//    selected = 0;
//    do {
//        cout << "Would you like to add existing players to the new team? [1:yes | 2:no]" << endl;
//        cin >> selected;
//        cleanBuffer();
//    } while (selected != 1 && selected != 2);
//    if (selected == 1)
//    {
//        selected = 0;
//        do {
//            cout << "Please choose a player to add to the team: " << endl;
//            int i = 0;
//            for (auto playerIt : players)
//                cout << i + 1 << " for " << *playerIt << endl;
//            do {
//                cin >> selected;
//                cleanBuffer();
//            } while (selected < 1 && selected > players.size());
//            i = 1;
//            auto playerIt = players.begin();
//            while (i < selected) {
//                ++playerIt;
//                ++i;
//            }
//            *team += **playerIt;
//            do {
//                cout << "Would you like to add another player? [1: yes | 2: no]";
//                cin >> selected;
//                cleanBuffer();
//            } while (selected != 1 && selected != 2);
//        } while (selected != 2);
//    }
//    return team;
//}

Team* createTeam(list<Player*> players, LinkedList<Owner> allOwners)
{
    if (allOwners.getSize() == 0)
        throw "no owners to create team.";
    int selected, numOfSeats = -1;
    string teamName = getStrExactName("Please enter team's name: ");
    cout << "Please choose an owner of the team" << endl;
    const LinkedList<Owner>::Node* node = allOwners.getHead();
    int index = 1;
    while (node)
    {
        cout << index << " for " << node->data << endl;
        node = node->next;
    }
    do {
        cin >> selected;
        cleanBuffer();
    } while (selected < 1 && selected > allOwners.getSize());
    Owner o = allOwners.getIndex(selected)->data;
    string courtName = getStrExactName("Please enter court's name: ");
    do {
        numOfSeats = getIntWithPrompt("Please enter court's number of seats - must be positive number: ");
        cleanBuffer();
    } while (numOfSeats < 1);
    Team* team = new Team(teamName, o, Court(courtName, numOfSeats));
    cout << "Team successfully added" << endl;
    selected = 0;
    do {
        cout << "Would you like to add existing players to the new team? [1:yes | 2:no]" << endl;
        cin >> selected;
        cleanBuffer();
    } while (selected != 1 && selected != 2);
    if (selected == 1)
    {
        selected = 0;
        do {
            cout << "Please choose a player to add to the team: " << endl;
            int i = 0;
            for (auto playerIt : players)
                cout << i + 1 << " for " << *playerIt << endl;
            do {
                cin >> selected;
                cleanBuffer();
            } while (selected < 1 && selected > players.size());
            i = 1;
            auto playerIt = players.begin();
            while (i < selected) {
                ++playerIt;
                ++i;
            }
            *team += **playerIt;
            do {
                cout << "Would you like to add another player? [1: yes | 2: no]";
                cin >> selected;
                cleanBuffer();
            } while (selected != 1 && selected != 2);
        } while (selected != 2);
    }
    return team;
}


//Match* createMatch(const Team* teams, int numOfTeams, list<Referee*> refs)
//{
//    if (numOfTeams < 2)
//        throw "Unable to create match, too few teams";
//    if (refs.size() < 1)
//        throw "Unable to create match, no referees available";
//    Team* teamA = nullptr, * teamB = nullptr;
//    Date* date = new Date();
//    Referee* ref;
//    Court* court;
//    int resultA, resultB, result, choice, firstChoice;
//    printTeams(teams);
//    for (int i = 0; i < 2; i++)
//    {
//        do
//        {
//            if (i == 0)
//            {
//                cout << "Please choose home team: " << endl;
//                cin >> firstChoice;
//                choice = firstChoice;
//                cleanBuffer();
//            }
//            else {
//                do
//                {
//                    cout << "Please choose away team (must be a different team): " << endl;
//                    cin >> choice;
//                    cleanBuffer();
//                } while (choice == firstChoice); // Checking that our second team is different from the first picked one
//            }
//        } while (choice > 0 && choice < numOfTeams);
//        if (i == 0)
//            teamA = new Team(teams[choice]);//copy c'tor
//        else
//            teamB = new Team(teams[choice]);//copy c'tor
//
//        do
//        {
//            cout << "please choose team result - must be positive number: " << endl;
//            cin >> result;
//        } while (result > 0);
//        if (i == 0)
//            resultA = result;
//        else
//            resultB = result;
//    }
//    *court = teamA->getCourt();
//    createDate(date);
//    cout << "Please choose referee: " << endl;
//    int i = 0;
//    for (auto refIt : refs)
//        cout << ++i << " for referee " << *refIt << endl;
//    do {
//        cin >> result;
//    } while (result < 1 && result > refs.size());
//    i = 1;
//    auto refIt = refs.begin();
//    while (i < result) {
//        ++refIt;
//        ++i;
//    }
//    ref = new Referee(**refIt);
//    return new Match(*ref, *teamA, *teamB, *date, *court);
//}

Match* createMatch(const list<Team*> teams, list<Referee*> refs)
{
    if (teams.size() < 2)
        throw "Unable to create match, too few teams";
    if (refs.size() < 1)
        throw "Unable to create match, no referees available";

    Team* teamA = nullptr;
    Team* teamB = nullptr;
    Date* date = new Date();
    Referee* ref;
    Court* court;
    int resultA, resultB, result, choice, firstChoice;

    int index = 1;
    for (auto team : teams)
        cout << index++ << ")" << *team << endl;

    for (int i = 0; i < 2; i++)
    {
        do
        {
            if (i == 0)
            {
                cout << "Please choose home team: " << endl;
                cin >> firstChoice;
                choice = firstChoice;
                cleanBuffer();
            }
            else {
                do
                {
                    cout << "Please choose away team (must be a different team): " << endl;
                    cin >> choice;
                    cleanBuffer();
                } while (choice == firstChoice); // Checking that our second team is different from the first picked one
            }
        } while (choice < 1 || choice > teams.size());

        index = 1;
        auto teamIt = teams.begin();
        ++teamIt;
        while (index < choice)
            ++teamIt;
        if (i == 0) 
            teamA = new Team(**teamIt);
        else
            teamB = new Team(**teamIt);
        do
        {
            cout << "Please choose team result - must be a positive number: " << endl;
            cin >> result;
        } while (result <= 0);

        if (i == 0)
            resultA = result;
        else
            resultB = result;
    }

    court = new Court(teamA->getCourt());
    PersonFactory::createDate(date);

    cout << "Please choose referee: " << endl;
    int i = 0;
    for (auto refIt : refs)
        cout << ++i << " for referee " << *refIt << endl;

    do {
        cin >> result;
    } while (result < 1 || result > refs.size());

    i = 1;
    auto refIt = refs.begin();
    while (i < result) {
        ++refIt;
        ++i;
    }
    ref = new Referee(**refIt);

    return new Match(*ref, *teamA, *teamB, *date, *court);
}


void addPlayerToTeamMenu(District& d, Player* p)
{
    cout << "Would you like to add the new player to a team? [1: Yes | 2: No]" << endl;
    int result;
    do {
        cleanBuffer();
        cin >> result;
    } while (result != 1 && result != 2);
    if (result == 1) {
        if (d.getNumberOfTeams() == 0)
            throw "No available teams in the district";
        cout << "Please a choose team from the district:";
        int i = 1;
        for (auto team : d.getTeams())
            cout << i++ << " for " << *team << endl;
        do {
            cin >> result;
            cleanBuffer();
        } while (result < 1 && result > d.getNumberOfTeams());
        
        int index = 1;
        list<Team*> teams = d.getTeams();
        auto teamIt = teams.begin();
        ++teamIt;
        while (index < result)
            ++teamIt;
        **teamIt += *p;
    }
}

//#include <iostream>
//using namespace std;
//#include "League.h"
///*
//* C++ project - NBA league
//* by: MAX FELDMAN AND SHACHAR ZEHARIA
//*/
//
//// Statics
//static constexpr int MAX_STR_LEN = 255;
//static constexpr int EXIT = -1;
//
//// Helpers
//void addPlayerToTeamMenu(District& d, Player* p) noexcept(false);
//void showLeagueMenu(League& l);
//void showDistrictMenu(League& l, District& d);
//void showNewWorkerMenu(League& l, District& d);
//void printTeams(const Team* teams);
//
//// Creators
//void createDate(Date* date) noexcept(false);
//void createPerson(int* pid, char** name, Date* date, Person::eGenderType* gender, char** address) noexcept(false);
//void createEmployee(int* pid, char** name, Date* date, Person::eGenderType* gender, char** address, float* salary) noexcept(false);
//Owner* createOwner() noexcept(false);
//Player* createPlayer() noexcept(false);
//Referee* createRefree() noexcept(false);
//Team* createTeam(list<Player*> players, LinkedList<Owner> allOwners) noexcept(false);
//Match* createMatch(const Team* teams, int numOfTeams, list<Referee*> refs) noexcept(false);
//
//// General Read Functions
//int getIntWithPrompt(const char* message);
//float getFloatWithPrompt(const char* message);
//int getEnumSelection(const string& message, const string const types[], const int numOfTypes);
//char* getStrExactName(const char* msg);
//char* getDynStr(char* str);
//char* myGets(char* buffer, int size, FILE* source);
//void displayMenu();
//void cleanBuffer();
//
//enum eChoice { NEW_TEAM = 1, NEW_WORKER, NEW_MATCH, PRINT_TEAM, PRINT_WORKER, PRINT_MATCH };
//enum eChoiceInner { NEW_OWNER = 1, NEW_PLAYER, NEW_REFREE };
//
//
//int main()
//{
//	League* l1 = new League();
//	showLeagueMenu(*l1);
//	return 0;
//}
//
///* Helpers */
//
//void showLeagueMenu(League& l)
//{
//	int choice;
//	list<District*> d = l.getDistricts();
//	cout << "*** NBA League Creator ***" << endl;
//	cout << "*** each NBA League has 2 districts (East, West) ***" << endl;
//	do
//	{
//		cout << "Select district:" << endl;
//		cout << "1) East" << endl;
//		cout << "2) West" << endl;
//		cout << "-1) Exit" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case (District::EAST + 1):
//		{
//			showDistrictMenu(l, **d.begin());
//			break;
//		}
//
//		case District::WEST + 1:
//		{
//			showDistrictMenu(l, **d.end());
//			break;
//		}
//
//		case EXIT:
//			cout << "Thanks for using me, bye :)";
//			return;
//
//		default:
//		{
//			cout << "Invalid input ,please enter the correct number" << endl;
//			cleanBuffer();
//			break;
//		}
//		}
//	} while (choice < 1 || choice > 2);
//}
//
//
//void showDistrictMenu(League& l, District& d)
//{
//	int selection = 0;
//	cout << "*** NBA District Creator ***" << endl;
//	while (true)
//	{
//		displayMenu();
//		try {
//			cin >> selection;
//
//			switch (selection)
//			{
//			case NEW_TEAM:
//			{
//				cout << "*** Team Creation ***" << endl;
//				Team* t = createTeam(l.getAllPlayers(), l.getAllOwners());
//				d + *t;
//				break;
//			}
//
//			case NEW_WORKER:
//			{
//				showNewWorkerMenu(l, d);
//				break;
//			}
//
//			case NEW_MATCH:
//			{
//				cout << "*** Match Creation ***" << endl;
//				int numOfRefs = 0;
//				d = d + *createMatch(*d.getTeams(), d.NUMBER_OF_TEAMS, l.getAllReferees());
//				break;
//			}
//
//			case PRINT_TEAM:
//			{
//				printTeams(*d.getTeams());
//				break;
//			}
//
//			case PRINT_WORKER:
//			{
//				list<Person*> workers = l.getAllWorkers();
//				for (Person* worker : workers)
//					cout << *worker << endl;
//				break;
//			}
//
//			case PRINT_MATCH:
//			{
//				const Match* matches = *d.getMatches();
//				for (int i = 0; i < District::NUMBER_OF_GAMES_SEASON; i++)
//					cout << matches[i] << endl;
//				break;
//			}
//
//			case EXIT:
//				return;
//
//			default:
//			{
//				cout << "Invalid input, please enter the correct number" << endl;
//				cleanBuffer();
//				break;
//			}
//			}
//		}
//		catch (const char* msg) {
//			cleanBuffer();
//			cout << msg << endl;
//		}
//	}
//}
//
//void displayMenu() {
//	cout << "Select district:" << endl;
//	cout << "1) Create a new Team" << endl;
//	cout << "2) Create a new Worker (Owner | Refree | Player)" << endl;
//	cout << "3) Create a new Match" << endl;
//	cout << "4) Print Team" << endl;
//	cout << "5) Print Workers" << endl;
//	cout << "6) Print Matches" << endl;
//	cout << "-1) Exit" << endl;
//}
//
//
//void showNewWorkerMenu(League& l, District& d)
//{
//	int selection;
//	cout << "*** Worker Creation ***" << endl;
//	cout << "Enter kind of worker:" << endl;
//	do
//	{
//		cout << "1) Owner" << endl;
//		cout << "2) Player" << endl;
//		cout << "3) Refree" << endl;
//		cout << "-1) Exit" << endl;
//		cin >> selection;
//		try {
//			switch (selection)
//			{
//			case NEW_OWNER:
//			{
//				Owner* o = createOwner();
//				l += o;
//				break;
//			}
//			case NEW_PLAYER:
//			{
//				Player* p = createPlayer();
//				l += p;
//				addPlayerToTeamMenu(d, p);
//				break;
//			}
//
//			case NEW_REFREE:
//			{
//				Referee* r = createRefree();
//				l += r;
//				break;
//			}
//
//			case EXIT:
//				return;
//
//			default:
//			{
//				cout << "Invalid input ,please enter the correct number" << endl;
//				cleanBuffer();
//				break;
//			}
//			}
//		}
//		catch (char* msg) {
//			cleanBuffer();
//			cout << msg << endl;
//		}
//	} while (selection < 1 || selection > 3);
//}
//
//void createDate(Date* date) {
//	int day = -1, month = -1, year = -1;
//	do
//	{
//		day = getIntWithPrompt("Please enter day: ");
//		cleanBuffer();
//	} while (day == -1);
//	do
//	{
//		month = getIntWithPrompt("Please enter month: ");
//		cleanBuffer();
//	} while (month == -1);
//	do
//	{
//		year = getIntWithPrompt("Please enter year: ");
//		cleanBuffer();
//	} while (year == -1);
//	*date = Date(day, month, year);
//}
//
//void createPerson(int* pid, char** name, Date* date, Person::eGenderType* gender, char** address)
//{
//	*pid = getIntWithPrompt("Please enter person ID - must be a valid ID number:");
//	*name = getStrExactName("Please enter person name: ");
//	cout << "Date of Birth" << endl;
//	createDate(date);
//	*gender = static_cast<Person::eGenderType>(getEnumSelection("Please choose gender:", Person::genders, Person::eNumOfTypes));
//	*address = getStrExactName("Please enter person's address: ");
//}
//
//void createEmployee(int* pid, char** name, Date* date, Person::eGenderType* gender, char** address, float* salary)
//{
//	createPerson(pid, name, date, gender, address);
//	do 
//	{
//		*salary = getFloatWithPrompt("Please enter salary - must be positive: ");
//		cleanBuffer();
//	} while (*salary <= 0.0);
//}
//
//Owner* createOwner()
//{
//	float budget;
//	int pid;
//	char* name[MAX_STR_LEN],* address[MAX_STR_LEN];
//	Person::eGenderType gender;
//	Date* date = new Date();
//
//	createPerson(&pid, name, date, &gender, address);
//	do
//	{
//		budget = getFloatWithPrompt("Please enter budget - must be non negative float: ");
//		cleanBuffer();
//	} while (budget < 0.0);
//	return new Owner(pid, *name, *date, gender, *address, budget);
//}
//
//
//Player* createPlayer()
//{
//	Owner* o;
//	float salary;
//	int selection, playerNumber, numOfTitles, numOfMatches;
//	Player::ePositionType position;
//
//	playerNumber = getIntWithPrompt("Please enter player's number:");
//	position = static_cast<Player::ePositionType>(getEnumSelection("Please choose player's position:", Player::positionNames, Player::eNumOfTypes));
//	do 
//	{
//		numOfTitles = getIntWithPrompt("Please enter player's number of titles - must be a non negative number: ");
//		cleanBuffer();
//	} while (numOfTitles < 0);
//	do
//	{
//		numOfMatches = getIntWithPrompt("Please enter player's number of games:");
//		cleanBuffer();
//	} while (numOfMatches < 0);
//	do
//	{
//		cout << "Is the player an owner? [1: Yes, 2: No]" << endl;
//		cin >> selection;
//		cleanBuffer();
//	} while (selection != 1 && selection != 2);
//	if (selection % 2 == 1)		//Player is an owner
//	{
//		o = createOwner();
//		do
//		{
//			salary = getFloatWithPrompt("Please enter salary - must be positive:");
//			cleanBuffer();
//		} while (salary < 0.0);
//		return new PlayerOwner(Player(Employee(o->getPID(), o->getName(), o->getDOB(), o->getGender(), o->getAddress(), salary), playerNumber, position, numOfTitles, numOfMatches), *o);
//	}
//	else						//Player is a new employee
//	{
//		int pid;
//		char* name[MAX_STR_LEN],* address[MAX_STR_LEN];
//		Person::eGenderType gender;
//		Date* date = new Date();
//		createEmployee(&pid, name, date, &gender, address, &salary);
//		return new Player(Employee(pid, *name, *date, gender, *address, salary), playerNumber, position, numOfTitles, numOfMatches);
//	}
//}
//
//Referee* createRefree()
//{
//	int pid, numOfMatches;
//	float rank, salary;
//	char* name[MAX_STR_LEN],* address[MAX_STR_LEN];
//	Person::eGenderType gender;
//	Date* date = new Date();
//	createEmployee(&pid, name, date, &gender, address, &salary);
//	rank = getFloatWithPrompt("Please enter rank - a float bigger than 0.0 and smaller than 10.0:");
//	do 
//	{
//		numOfMatches = getIntWithPrompt("Please enter number of matches - must be non negative number:");
//		cleanBuffer();
//	} while (numOfMatches < 0);
//	return new Referee(Employee(pid, *name, *date, gender, *address, salary), rank, numOfMatches);
//}
//
//
//Team* createTeam(list<Player*> players, LinkedList<Owner> allOwners)
//{
//	if (allOwners.getSize() == 0)
//		throw "no owners to create team.";
//	int selected, numOfSeats = -1;
//	char* teamName = getStrExactName("Please enter team's name: ");
//	cout << "Please choose an owner of the team" << endl;
//	const LinkedList<Owner>::Node* node = allOwners.getHead();
//	int index = 1;
//	while (node)
//	{
//		cout << index << " for " << node->data << endl;
//		node = node->next;
//	}
//	do {
//		cin >> selected;
//		cleanBuffer();
//	} while (selected < 1 && selected > allOwners.getSize());
//	Owner o = allOwners.getIndex(selected)->data;
//	char* courtName = getStrExactName("Please enter court's name: ");
//	do {
//		numOfSeats = getIntWithPrompt("Please enter court's number of seats - must be positive number: ");
//		cleanBuffer();
//	} while (numOfSeats < 1);
//	Team* team = new Team(teamName, o, Court(courtName, numOfSeats));
//	cout << "Team successfully added" << endl;
//	selected = 0;
//	do {
//		cout << "Would you like to add existing players to the new team? [1:yes | 2:no]" << endl;
//		cin >> selected;
//		cleanBuffer();
//	} while (selected != 1 && selected != 2);
//	if (selected == 1) 
//	{
//		selected = 0;
//		do {
//			cout << "Please choose a player to add to the team: " << endl;
//			int i = 0;
//			for (auto playerIt : players)
//				cout << i + 1 << " for " << *playerIt << endl;
//			do {
//				cin >> selected;
//				cleanBuffer();
//			} while (selected < 1 && selected > players.size());
//			i = 1;
//			auto playerIt = players.begin();
//			while (i < selected) {
//				++playerIt;
//				++i;
//			}
//			*team += **playerIt;
//			do {
//				cout << "Would you like to add another player? [1: yes | 2: no]";
//				cin >> selected;
//				cleanBuffer();
//			} while (selected != 1 && selected != 2);
//		} while (selected != 2);
//	}
//	return team;
//}
//
//Match* createMatch(const Team* teams, int numOfTeams, list<Referee*> refs)
//{
//	if (numOfTeams < 2)
//		throw "Unable to create match, too few teams";
//	if (refs.size() < 1)
//		throw "Unable to create match, no referees available";
//	Team* teamA = nullptr, * teamB = nullptr;
//	Date* date = new Date();
//	Referee* ref;
//	Court* court;
//	int resultA, resultB, result, choice, firstChoice;
//	printTeams(teams);
//	for (int i = 0; i < 2; i++)
//	{
//		do
//		{
//			if (i == 0) 
//			{
//				cout << "Please choose home team: " << endl;
//				cin >> firstChoice;
//				choice = firstChoice;
//				cleanBuffer();
//			}
//			else {
//				do 
//				{
//					cout << "Please choose away team (must be a different team): " << endl;
//					cin >> choice;
//					cleanBuffer();
//				} while (choice == firstChoice); // Checking that our second team is different from the first picked one
//			}
//		} while (choice > 0 && choice < numOfTeams);
//		if (i == 0)
//			teamA = new Team(teams[choice]);//copy c'tor
//		else
//			teamB = new Team(teams[choice]);//copy c'tor
//
//		do
//		{
//			cout << "please choose team result - must be positive number: " << endl;
//			cin >> result;
//		} while (result > 0);
//		if (i == 0)
//			resultA = result;
//		else
//			resultB = result;
//	}
//	*court = teamA->getCourt();
//	createDate(date);
//	cout << "Please choose referee: " << endl;
//	int i = 0;
//	for (auto refIt : refs) 
//		cout << ++i << " for referee " << *refIt << endl;
//	do {
//		cin >> result;
//	} while (result < 1 && result > refs.size());
//	i = 1;
//	auto refIt = refs.begin();
//	while (i < result) {
//		++refIt;
//		++i;
//	}
//	ref = new Referee(**refIt);
//	return new Match(*ref, *teamA, *teamB, *date, *court);
//}
//
//void addPlayerToTeamMenu(District& d, Player* p)
//{
//	cout << "Would you like to add the new player to a team? [1: Yes | 2: No]" << endl;
//	int result;
//	do {
//		cin >> result;
//		cleanBuffer();
//	} while (result != 1 && result != 2);
//	if (result == 1) {
//		if (d.getNumberOfTeams() == 0)
//			throw "No available teams in the district";
//		cout << "Please a choose team from the district: ";
//		for (int i = 0; i < d.getNumberOfTeams(); i++) {
//			cout << i << " for" << d.getTeams()[i];
//		}
//		do {
//			cin >> result;
//			cleanBuffer();
//		} while (result < 1 && result > d.getNumberOfTeams());
//		*d.getTeams()[result] += *p;
//	}
//}
//
//void printTeams(const Team* teams)
//{
//	cout << "All teams : " << endl;
//	for (int i = 0; i < District::NUMBER_OF_TEAMS; i++)
//		cout << i + 1 << ". " << teams[i] << endl;
//}
//
////General Functions
//int getIntWithPrompt(const char* message)
//{
//	int num;
//	cout << message << endl;
//	cin >> num;
//	return num;
//}
//
//
//float getFloatWithPrompt(const char* message)
//{
//	float num;
//	cout << message << endl;
//	cin >> num;
//	return num;
//}
//
//int getEnumSelection(const string& message, const string types[], const int numOfTypes) {
//	int enumChoice;
//	do {
//		cout << message << endl;
//		for (int i = 0; i < numOfTypes; ++i) {
//			cout << i + 1 << ") " << types[i] << endl;
//		}
//		cin >> enumChoice;
//	} while (enumChoice < 1 || enumChoice > numOfTypes);
//
//	return enumChoice - 1;  // Adjust to zero-based index
//}
//
////int getEnumSelection(const char* message, const char* const types[], const int numOfTypes)
////{
////	int enumChoice;
////	do
////	{
////		cout << message << endl;
////		for (int i = 0; i < numOfTypes; ++i)
////		{
////			cout << i + 1 << ") " << types[i] << endl;
////		}
////		cin >> enumChoice;
////	} while (enumChoice < 1 || enumChoice > numOfTypes);
////
////	return enumChoice - 1;  // Adjust to zero-based index
////}
//
//char* getStrExactName(const char* msg)
//{
//	char* str;
//	char temp[MAX_STR_LEN];
//	printf("%s\t", msg);
//	myGets(temp, MAX_STR_LEN, stdin);
//	str = getDynStr(temp);
//	return str;
//}
//
//char* getDynStr(char* str)
//{
//	char* theStr;
//	theStr = (char*)malloc(sizeof(char) * (strlen(str) + 1));
//	if (!theStr)
//		return NULL;
//
//	strcpy(theStr, str);
//	return theStr;
//}
//
//char* myGets(char* buffer, int size, FILE* source)
//{
//	char* ok;
//	if (buffer != NULL && size > 0)
//	{
//		do { //skip only '\n' strings
//			ok = fgets(buffer, size, source);
//		} while (ok && ((strlen(buffer) <= 1) || (isspace(buffer[0]))));
//		if (ok)
//		{
//			char* back = buffer + strlen(buffer);
//			//trim end spaces
//			while ((buffer < back) && (isspace(*--back)));
//			*(back + 1) = '\0';
//			return buffer;
//		}
//		buffer[0] = '\0';
//	}
//	return NULL;
//}
//
//void cleanBuffer()
//{
//	int c;
//	do
//	{
//		c = getchar();
//	} while (c != EOF && c != '\n');
//}
