#include "Resource.h"
#include "Reservation.h"

Resource::Resource(const int aID,
                   const std::string &aName,
                   const std::string &aLocation,
                   const int aBeginningAvailabilityHour,
                   const int aBeginningAvailabilityMinute,
                   const int aEndAvailabilityHour,
                   const int aEndAvailabilityMinute,
                   const int aAvailabilityInterval)
      : ID(aID),
        Name(aName),
        Location(""),
        BeginningAvailabilityHour(aBeginningAvailabilityHour),
        BeginningAvailabilityMinute(aBeginningAvailabilityMinute),
        EndAvailabilityHour(aEndAvailabilityHour),
        EndAvailabilityMinute(aEndAvailabilityMinute),
        AvailabilityInterval(aAvailabilityInterval),
        ResourceType("Generic")
{
}

Resource::Resource()
      : ID(0),
        Name(""),
        Location(""),
        BeginningAvailabilityHour(0),
        BeginningAvailabilityMinute(0),
        EndAvailabilityHour(23),
        EndAvailabilityMinute(59),
        AvailabilityInterval(30),
        ResourceType("Default")
{
}

Resource::~Resource() = default;

const std::vector<std::unique_ptr<Reservation>> &Resource::getReservationList()
{
        return ReservationList;
}

std::vector<std::unique_ptr<Reservation>> &Resource::getMutableReservationList()
{
        return ReservationList;
}

int Resource::getID() const
{
        return ID;
}

std::string Resource::getName() const
{
        return Name;
}

std::string Resource::getLocation() const
{
        return Location;
}

int Resource::getBeginningAvailabilityHour() const
{
        return BeginningAvailabilityHour;
}

int Resource::getBeginningAvailabilityMinute() const
{
        return BeginningAvailabilityMinute;
}

int Resource::getEndAvailabilityHour() const
{
        return EndAvailabilityHour;
}

int Resource::getEndAvailabilityMinute() const
{
        return EndAvailabilityMinute;
}

int Resource::getAvailabilityInterval() const
{
        return AvailabilityInterval;
}

std::string Resource::getResourceType() const
{
        return ResourceType;
}

void Resource::setID(const int aID)
{
        ID = aID;
}

void Resource::setName(const std::string aName)
{
        Name = aName;
}

void Resource::setLocation(const std::string aLocation)
{
        Location = aLocation;
}

void Resource::setBeginningAvailabilityHour(const int v)
{
        BeginningAvailabilityHour = v;
}

void Resource::setBeginningAvailabilityMinute(const int v)
{
        BeginningAvailabilityMinute = v;
}

void Resource::setEndAvailabilityHour(const int v)
{
        EndAvailabilityHour = v;
}

void Resource::setEndAvailabilityMinute(const int v)
{
        EndAvailabilityMinute = v;
}

void Resource::setAvailabilityInterval(const int v)
{
        AvailabilityInterval = v;
}

void Resource::setResourceType(const std::string rt)
{
        ResourceType = rt;
}

void Resource::PrintResource(std::ostream &os) const
{
        os << "ID: " << ID << "\n"
           << "Name: " << Name << "\n"
           << "Location: " << Location << "\n"
           << "Availability: " << BeginningAvailabilityHour << ":"
           << BeginningAvailabilityMinute << " - " << EndAvailabilityHour << ":"
           << EndAvailabilityMinute << "\n"
           << "Interval: " << AvailabilityInterval << " minutes\n"
           << "\n";
}

void Resource::Print(std::ostream &os) const
{
        PrintResource(os);
}

void Resource::PrintReservationList(std::ostream &os) const
{
        if (ReservationList.empty())
        {
                os << "No reservations.\n";
                return;
        }

        for (const auto &r : ReservationList) os << *r << "\n";
}

std::ostream &operator<<(std::ostream &os, const Resource &resource)
{
        resource.Print(os);
        return os;
}
