#ifndef LAB_EQUIPMNET_H
#define LAB_EQUIPMNET_H

#include <Resource.h>
#include <ostream>

class LabEquipment : public Resource
{
        public:
                LabEquipment(const int aID, const std::string aName,
                             const int aBeginningAvailabilityHour,
                             const int aBeginningAvailabilityMinute,
                             const int aEndAvailabilityHour,
                             const int aEndAvailabilityMinute,
                             const int aAvailabilityInterval,
                             const std::string aLabName,
                             const int aGroupNumber);

                LabEquipment();
                ~LabEquipment();
                const void Print(std::ostream &os) override;

                friend std::ostream &operator<<(std::ostream &os,
                                                Resource &resource);

                // Getters
                std::string getLabName() const;
                int getGroupNumber() const;

                // Setters
                void setLabName(std::string aLabName);
                void setGroupNumber(int aGroupNumber);

        private:
                std::string LabName;
                int GroupNumber;
};

#endif
