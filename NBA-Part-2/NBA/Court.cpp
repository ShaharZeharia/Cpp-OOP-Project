#include "Court.h"

Court::Court(const char* courtName, int numberOfSeats) : numberOfSeats(numberOfSeats)
{
    setCourtName(courtName);
}

Court::Court(Court&& other) noexcept(true) : courtName(other.courtName), numberOfSeats(other.numberOfSeats)
{
    other.courtName = nullptr;
}

void Court::setCourtName(const char* courtName) noexcept(false)
{
    if (courtName == nullptr || strlen(courtName) == 0)
        throw("Invalid name");

    delete[] this->courtName;
    this->courtName = new char[strlen(courtName) + 1];
    strcpy(this->courtName, courtName);
}

ostream& operator<<(ostream& os, const Court& court)
{
    os << "Court Name: " << court.getCourtName()
        << ", Number of Seats: " << court.getNumberOfSeats();
    return os;
}

Court& Court::operator=(const Court& other)
{
    if (this != &other) {
        delete[] courtName;

        courtName = new char[strlen(other.courtName) + 1];
        strcpy(courtName, other.courtName);

        numberOfSeats = other.numberOfSeats;
    }
    return *this;
}