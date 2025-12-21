#ifndef LAB_EQUIPMENT_H
#define LAB_EQUIPMENT_H

#include <Resource.h>
#include <ostream>

class LabEquipment : public Resource
{
        public:
                LabEquipment(const int aID,
                             const std::string &aName,
                             const std::string &aLocation,
                             const int aBeginningAvailabilityHour,
                             const int aBeginningAvailabilityMinute,
                             const int aEndAvailabilityHour,
                             const int aEndAvailabilityMinute,
                             const int aAvailabilityInterval,
                             const std::string &aLabName,
                             const int aGroupNumber);
                LabEquipment();
                ~LabEquipment();

                // Getters
                std::string getLabName() const;
                int getGroupNumber() const;

                // Setters
                void setLabName(std::string aLabName);
                void setGroupNumber(int aGroupNumber);

                void Print(std::ostream &os) const override;

        private:
                std::string LabName;
                int GroupNumber;
};

#endif
