#include <iostream>
using namespace std;
#include "Company.hpp"

static constexpr int MAX_STR_LEN = 255;
static constexpr int EXIT = -1;

// Helpers
void showCompanyMenu(Company& company);
void handleAddCustomer(Company& company);
void handleAddEmployee(Company& company);

// Creators
void createDate(Date* date) noexcept(false);
void createPerson(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address) noexcept(false);
void createStation(Company& company) noexcept(false);
void createRefinery(Company& company) noexcept(false);
void createDelivery(Company& company) noexcept(false);
Vehicle* createVehicle() noexcept(false);
Employee* createEmployee(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, int* salary) noexcept(false);
EmployeeCus* createEmployeeCus(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, int* salary, float* discount) noexcept(false);
Customer* createCustomer(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address) noexcept(false);
void addTruck(Company& company) noexcept(false);

// General Read Functions
int getIntWithPrompt(const char* message);
float getFloatWithPrompt(const char* message);
char* getStrExactName(const char* msg);
char* getDynStr(char* str);
int getEnumSelection(const char* message, const char* const types[], int numOfTypes);
void cleanBuffer();

enum eChoice {
    ADD_STATION = 1,
    ADD_REFINERY,
    ADD_DELIVERY,
    ADD_TRUCK,
    ADD_CUSTOMER,
    ADD_EMPLOYEE,
    PRINT_STATIONS,
    PRINT_REFINERIES,
    PRINT_DELIVERIES,
    PRINT_VEHICLES,
    SHOW_ALL,
    SHOW_MOST_PROFITABLE,
    EXIT_MENU
};

int main() {
    char* companyName = getStrExactName("Please enter company name: ");
    Company* company = new Company(companyName);
    showCompanyMenu(*company);
    return 0;
}

void showCompanyMenu(Company& company) {
    int choice;
    do {
        cout << "\n*** Company Management ***\n";
        cout << "1) Add Station\n";
        cout << "2) Add Refinery\n";
        cout << "3) Schedule Delivery\n";
        cout << "4) Add Truck\n";
        cout << "5) Register New Customer\n";
        cout << "6) Hire New Employee\n";
        cout << "7) Print Stations\n";
        cout << "8) Print Refineries\n";
        cout << "9) Print Deliveries\n";
        cout << "10) Print Vehicles\n";
        cout << "11) Display Company Overview\n";
        cout << "12) Show Most Profitable Station\n";
        cout << "-1) Exit\n";

        cin >> choice;

        try {
            switch (choice) {
            case ADD_STATION:
                createStation(company);
                break;
            case ADD_REFINERY:
                createRefinery(company);
                break;
            case ADD_DELIVERY:
                createDelivery(company);
                break;
            case ADD_TRUCK:
                addTruck(company);
                break;
            case ADD_CUSTOMER:
                handleAddCustomer(company);
                break;
            case ADD_EMPLOYEE:
                handleAddEmployee(company);
                break;
            case PRINT_STATIONS:
                company.printStations();
                break;
            case PRINT_REFINERIES:
                company.printRefineries();
                break;
            case PRINT_DELIVERIES:
                company.printDeliveries();
                break;
            case PRINT_VEHICLES:
                company.printVehicles();
                break;
            case SHOW_ALL:
                cout << company;
                break;
            case SHOW_MOST_PROFITABLE:
                company.showMostProfitable();
                break;
            case EXIT_MENU:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            cleanBuffer();
        }

    } while (choice != EXIT_MENU);
}

void createDate(Date* date) {
    int day, month, year;
    day = getIntWithPrompt("Please enter day: ");
    month = getIntWithPrompt("Please enter month: ");
    year = getIntWithPrompt("Please enter year: ");
    *date = Date(day, month, year);
}

void createPerson(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address)
{
    *pid = getIntWithPrompt("Please enter person ID:");
    name = getStrExactName("Please enter person name: ");
    cout << "Date of Birth" << endl;
    createDate(date);
    *gender = static_cast<Person::eGenderType>(getEnumSelection("Please choose gender:", Person::genders, Person::eNumOfTypes));
    address = getStrExactName("Please enter person's address: ");
}

Employee* createEmployee(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, int* salary)
{
    createPerson(pid, name, date, gender, address);
    *salary = getIntWithPrompt("Please enter salary: ");
    return new Employee(*pid, name, *date, *gender, address, *salary);
}

EmployeeCus* createEmployeeCus(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, int* salary, float* discount) {

    createPerson(pid, name, date, gender, address);
    *salary = getIntWithPrompt("Please enter salary: ");
    Employee employee(*pid, name, *date, *gender, address, *salary);

    Vehicle* vehicle = createVehicle();
    Customer customer(*pid, name, *date, *gender, address, *vehicle);

    *discount = getFloatWithPrompt("Please enter discount for Employee-Customer: ");

    return new EmployeeCus(employee, customer, *discount);
}


Customer* createCustomer(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address)
{
    createPerson(pid, name, date, gender, address);
    Vehicle* vehicle = createVehicle();
    return new Customer(*pid, name, *date, *gender, address, *vehicle);
}

void createStation(Company& company) noexcept(false) {
    char* name = getStrExactName("Enter station name:");
    char* city = getStrExactName("Enter station city:");
    int pid = 0, salary = 0;
    char* mangName = nullptr, * mangAddress = nullptr;
    Date* date = nullptr;
    Person::eGenderType gender = (Person::eGenderType)1;
    EmployeeManager* empMang = new EmployeeManager(*createEmployee(&pid, mangName, date, &gender, mangAddress, &salary));
    Station* station = new Station(name, city, empMang);
    company += *station;
}

void createRefinery(Company& company) noexcept(false) {
    char* name = getStrExactName("Enter refinery name:");
    Pump::eFuelType fuelType = static_cast<Pump::eFuelType>(getEnumSelection("Enter fuel type :", Pump::pumpTypeStr, Pump::eNofFuelTypes));
    int price = getIntWithPrompt("Enter fuel price:");
    Refinery* refinery = new Refinery(name, fuelType, price);
    company += *refinery;
}

void createDelivery(Company& company) noexcept(false)
{
    if (company.getStaCount() == 0) {
        throw "No stations available in the company.";
    }
    if (company.getRefCount() == 0) {
        throw "No refineries available in the company.";
    }
    if (company.getVehCount() == 0) {
        throw "No trucks available";
    }

    int result;
    cout << "Choose truck for delivery: " << endl;
    for (int i = 0; i < company.getVehCount(); i++)
    {
        cout << i + 1 << "for " << company.getVehicles()[i] << endl;
    }
    do {
        cleanBuffer();
        cin >> result;
    } while (result > 1 && result > company.getVehCount());
    Vehicle* vehicle = new Vehicle(*company.getVehicles()[result - 1]);

    cout << "Choose station to deliver: " << endl;
    for (int i = 0; i < company.getStaCount(); i++)
    {
        cout << i + 1 << "for " << company.getStations()[i] << endl;
    }
    do {
        cleanBuffer();
        cin >> result;
    } while (result > 1 && result > company.getStaCount());
    Station* station = new Station(*company.getStations()[result - 1]);

    cout << "Choose refinery for delivery: " << endl;
    for (int i = 0; i < company.getRefCount(); i++)
    {
        cout << i + 1 << "for " << company.getRefineries()[i] << endl;
    }
    do {
        cleanBuffer();
        cin >> result;
    } while (result > 1 && result > company.getRefCount());
    Refinery* refinery = new Refinery(*company.getRefineries()[result - 1]);

    Date* deliveryDate = new Date();
    createDate(deliveryDate);
    Delivery delivery = Delivery(*vehicle, *station, *refinery, *deliveryDate);
    company += delivery;
}

Vehicle* createVehicle() noexcept(false) {
    Vehicle::eVehicleType vehicleType = static_cast<Vehicle::eVehicleType>(getEnumSelection("Enter vehicle type: ", Vehicle::vehicleTypeStr, Vehicle::eNofVehicleTypes));
    Pump::eFuelType fuelType = static_cast<Pump::eFuelType>(getEnumSelection("Enter vehicle fuel type: ", Pump::pumpTypeStr, Pump::eNofFuelTypes));
    int plate = getIntWithPrompt("Enter vehicle license plate:");
    return new Vehicle(plate, vehicleType, fuelType);
}

void addTruck(Company& company) noexcept(false)
{
    Vehicle::eVehicleType vehicleType = Vehicle::eTruck;
    Pump::eFuelType fuelType = (Pump::eFuelType) (getEnumSelection("Enter vehicle fuel type: ", Pump::pumpTypeStr, Pump::eNofFuelTypes));
    int plate = getIntWithPrompt("Enter vehicle license plate:");
    Vehicle* vehicle = new Vehicle(plate, vehicleType, fuelType);
    company += *vehicle;
}

void handleAddCustomer(Company& company) {
    if (company.getStaCount() == 0) {
        throw "No stations available in the company.";
    }

    int stationIndex;
    cout << "Choose a station to add a customer:" << endl;
    for (int i = 0; i < company.getStaCount(); i++) {
        cout << i + 1 << ") " << *company.getStations()[i] << endl;
    }

    do {
        cleanBuffer();
        stationIndex = getIntWithPrompt("Enter station number:");
    } while (stationIndex < 1 || stationIndex > company.getStaCount());

    char* name = nullptr, * address = nullptr;
    int pid;
    Date* date = nullptr;
    Person::eGenderType gender;
    Customer* customer = createCustomer(&pid, name, date, &gender, address);

    *(company.getStations()[stationIndex - 1]) += *customer;
}

void handleAddEmployee(Company& company) {
    if (company.getStaCount() == 0) {
        throw "No stations available in the company.";
    }

    int stationIndex;
    cout << "Choose a station to add an employee:" << endl;
    for (int i = 0; i < company.getStaCount(); i++) {
        cout << i + 1 << ") " << *company.getStations()[i] << endl;
    }

    do {
        cleanBuffer();
        stationIndex = getIntWithPrompt("Enter station number:");
    } while (stationIndex < 1 || stationIndex > company.getStaCount());

    int employeeType;

    do {
        employeeType = getIntWithPrompt("Enter 1 for Employee or 2 for Employee-Customer: ");

        if (employeeType != 1 && employeeType != 2) {
            cout << "Invalid selection. Please try again." << endl;
        }
    } while (employeeType != 1 && employeeType != 2);

    char* name = nullptr;
    char* address = nullptr;
    int pid, salary;
    float discount;
    Date* date = nullptr;
    Person::eGenderType gender;

    Employee* employee = nullptr;
    EmployeeCus* employeeCus = nullptr;

    if (employeeType == 1) {
        employee = createEmployee(&pid, name, date, &gender, address, &salary);
    }
    else if (employeeType == 2) {
        employeeCus = createEmployeeCus(&pid, name, date, &gender, address, &salary, &discount);
    }

    EmployeeManager* empManager = company.getStations()[stationIndex - 1]->getEmployeeManager();
    if (empManager) {
        if (employee) {
            *empManager += *employee;
        }
        else if (employeeCus) {
            *empManager += *employeeCus;
        }
    }
    else {
        cout << "No employee manager available in the selected station.\n";
    }
}


int getEnumSelection(const char* message, const char* const types[], int numOfTypes)
{
    int enumChoice;
    do
    {
        cout << message << endl;
        for (int i = 0; i < numOfTypes; ++i)
        {
            cout << i + 1 << ") " << types[i] << endl;
        }
        cin >> enumChoice;
    } while (enumChoice < 1 || enumChoice > numOfTypes);

    return enumChoice - 1;
}

int getIntWithPrompt(const char* message) {
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}

float getFloatWithPrompt(const char* message) {
    float num;
    cout << message << endl;
    cin >> num;
    return num;
}

char* getStrExactName(const char* msg) {
    char* str;
    char temp[MAX_STR_LEN];
    cout << msg << "\t";
    cin >> temp;
    str = getDynStr(temp);
    return str;
}

char* getDynStr(char* str) {
    char* theStr = new char[strlen(str) + 1];
    strcpy(theStr, str);
    return theStr;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}