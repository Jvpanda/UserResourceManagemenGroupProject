#include "LabEquipment.h"
#include "Resource.h"
#include <iostream>
#include <ostream>

LabEquipment::LabEquipment(const int aID,
                           const std::string &aName,
                           const std::string &aLocation,
                           const int aBeginningAvailabilityHour,
                           const int aBeginningAvailabilityMinute,
                           const int aEndAvailabilityHour,
                           const int aEndAvailabilityMinute,
                           const int aAvailabilityInterval,
                           const std::string &aLabName,
                           const int aGroupNumber)
      : Resource(aID,
                 aName,
                 aLocation,
                 aBeginningAvailabilityHour,
                 aBeginningAvailabilityMinute,
                 aEndAvailabilityHour,
                 aEndAvailabilityMinute,
                 aAvailabilityInterval),
                 LabName(aLabName),
                 GroupNumber(aGroupNumber)
{
}

LabEquipment::LabEquipment() : Resource(), LabName("Default"), GroupNumber(0)
{
        setResourceType("LabEquipment");
}

LabEquipment::~LabEquipment() = default;

std::string LabEquipment::getLabName() const
{
        return LabName;
}

int LabEquipment::getGroupNumber() const
{
        return GroupNumber;
}

void LabEquipment::setLabName(std::string aLabName)
{
        LabName = aLabName;
}

void LabEquipment::setGroupNumber(int aGroupNumber)
{
        GroupNumber = aGroupNumber;
}

void LabEquipment::Print(std::ostream &os) const
{
        Resource::Print(os);
        os << "Lab Name: " << LabName << "\n"
           << "Group Number: " << GroupNumber << "\n"
           << "\n";
}
