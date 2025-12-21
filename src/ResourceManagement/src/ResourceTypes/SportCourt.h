#ifndef SPORT_COURT_H
#define SPORT_COURT_H
#include <Resource.h>
#include <ostream>

class SportCourt : public Resource
{
        public:
                SportCourt(const int aID,
                           const std::string &aName,
                           const std::string &aLocation,
                           const int aBeginningAvailabilityHour,
                           const int aBeginningAvailabilityMinute,
                           const int aEndAvailabilityHour,
                           const int aEndAvailabilityMinute,
                           const int aAvailabilityInterval,
                           const std::string &aSport,
                           const int aSeatingCapacity);
                SportCourt();
                ~SportCourt();

                // Getters
                std::string getSportType() const;
                int getSeatingCapacity() const;

                // Setters
                void setSportType(std::string aSportType);
                void setSeatingCapacity(int aSeatingCapacity);

                void Print(std::ostream &os) const override;

        private:
                std::string SportType;
                int SeatingCapacity;
};

#endif
