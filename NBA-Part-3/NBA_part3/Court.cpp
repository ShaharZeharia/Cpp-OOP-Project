#include "Court.h"

Court::Court(const string& courtName, int numberOfSeats) : numberOfSeats(numberOfSeats)
{
    setCourtName(courtName);
}

Court::Court(Court&& other) noexcept(true) : courtName(move(other.courtName)), numberOfSeats(other.numberOfSeats)
{
}

void Court::setCourtName(const string& courtName) noexcept(false)
{
    if (courtName.empty())
        throw("Invalid name");

    this->courtName = courtName;
}

ostream& operator<<(ostream& os, const Court& court)
{
    os << "Court Name: " << court.getCourtName()
        << ", Number of Seats: " << court.getNumberOfSeats();
    return os;
}
