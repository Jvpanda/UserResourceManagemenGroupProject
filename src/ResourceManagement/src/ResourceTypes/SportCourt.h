#ifndef SPORT_COURT_H
#define SPORT_COURT_H
#include <Resource.h>
#include <ostream>

class SportCourt : public Resource
{
        public:
                SportCourt(const int aID, const std::string aName,
                           const int aBeginningAvailabilityHour,
                           const int aBeginningAvailabilityMinute,
                           const int aEndAvailabilityHour,
                           const int aEndAvailabilityMinute,
                           const int aAvailabilityInterval,
                           const std::string aSport,
                           const int aSeatingCapacity);
                SportCourt();

                ~SportCourt();

                // Getters
                std::string getSportType() const;
                int getSeatingCapacity() const;

                // Setters
                void setSportType(std::string aSportType);
                void setSeatingCapacity(int aSeatingCapacity);

                const void Print(std::ostream &os) override;
                friend std::ostream &operator<<(std::ostream &os,
                                                Resource &resource);

        private:
                std::string SportType;
                int SeatingCapacity;
};

#endif
