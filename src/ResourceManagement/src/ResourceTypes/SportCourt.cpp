#include "SportCourt.h"
#include <iostream>

SportCourt::SportCourt(const int aID,
                       const std::string &aName,
                       const std::string &aLocation,
                       const int aBeginningAvailabilityHour,
                       const int aBeginningAvailabilityMinute,
                       const int aEndAvailabilityHour,
                       const int aEndAvailabilityMinute,
                       const int aAvailabilityInterval,
                       const std::string &aSport,
                       const int aSeatingCapacity)
     : Resource(aID,
                aName,
                aLocation,
                aBeginningAvailabilityHour,
                aBeginningAvailabilityMinute,
                aEndAvailabilityHour,
                aEndAvailabilityMinute,
                aAvailabilityInterval),
                SportType(aSport),
                SeatingCapacity(aSeatingCapacity)
{
        setResourceType("SportCourt");
}

SportCourt::SportCourt() : Resource(), SportType(""), SeatingCapacity(0)
{
        setResourceType("SportCourt");
}

SportCourt::~SportCourt() = default;

std::string SportCourt::getSportType() const
{
        return SportType;
}

int SportCourt::getSeatingCapacity() const
{
        return SeatingCapacity;
}

void SportCourt::setSportType(std::string aSportType)
{
        SportType = aSportType;
}

void SportCourt::setSeatingCapacity(int aSeatingCapacity)
{
        SeatingCapacity = aSeatingCapacity;
}

void SportCourt::Print(std::ostream &os) const
{
        PrintResource(os);
        os << "Sport Type: " << SportType << "\n"
           << "Seating Capacity: " << SeatingCapacity << "\n"
           << "\n";
}
