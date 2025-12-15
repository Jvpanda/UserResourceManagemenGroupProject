#ifndef RESOURCE_H
#define RESOURCE_H

#include "Reservation.h"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Resource
{
        public:
                ~Resource();

                Resource(const int ID, const std::string aName,
                         const int aBeginningAvailabilityHour,
                         const int aBeginningAvailabilityMinute,
                         const int aEndAvailabilityHour,
                         const int aEndAvailabilityMinute,
                         const int aAvailabilityInterval);
                Resource();

                // Getters
                const std::vector<std::unique_ptr<Reservation>> &
                getReservationList();
                std::vector<std::unique_ptr<Reservation>> &
                getMutableReservationList();
                int getID() const;
                std::string getName() const;
                std::string getLocation() const;
                int getBeginningAvailabilityHour() const;
                int getBeginningAvailabilityMinute() const;
                int getEndAvailabilityHour() const;
                int getEndAvailabilityMinute() const;
                int getAvailabilityInterval() const;
                std::string getResourceType() const;

                // Setters
                void setID(const int aID);
                void setName(const std::string aName);
                void setLocation(const std::string aLocation);
                void setBeginningAvailabilityHour(
                    const int aBeginningAvailabilityHour);
                void setBeginningAvailabilityMinute(
                    const int aBeginningAvailabilityMinute);
                void setEndAvailabilityHour(const int aEndAvailabilityHour);
                void setEndAvailabilityMinute(const int aEndAvailabilityMinute);
                void setAvailabilityInterval(const int aAvailabilityInterval);
                void setResourceType(const std::string rt);

                void PrintResource(std::ostream &os);
                const virtual void Print(std::ostream &os);
                void PrintReservationList(std::ostream &os);
                friend std::ostream &operator<<(std::ostream &os,
                                                Resource &resource);

        private:
                std::vector<std::unique_ptr<Reservation>> ReservationList;

                std::string ResourceType = "Default";
                int ID;
                std::string Name;
                std::string Location;
                int BeginningAvailabilityHour;
                int BeginningAvailabilityMinute;
                int EndAvailabilityHour;
                int EndAvailabilityMinute;
                int AvailabilityInterval;
};

#endif
