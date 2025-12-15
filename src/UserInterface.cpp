#include "UserInterface.h"
#include <limits>

int UserInterface::getInput(int lowerBound, int upperBound)
{
        bool valid = false;
        int input = -1;
        constexpr std::streamsize maxCharLimit =
            std::numeric_limits<std::streamsize>::max();

        do
        {
                if (!(std::cin >> input) || input < lowerBound ||
                    input > upperBound)
                {
                        std::cin.clear();
                        std::cin.ignore(maxCharLimit, '\n');
                        valid = false;
                        std::cout << "Invalid Input, Try Again\n";
                }
                else
                {
                        valid = true;
                }

        } while (!valid);
        std::cin.ignore(1, '\n');

        return input;
}

void UserInterface::run()
{
        while (true)
        {
                std::cout << "User Login:\n";
                std::cout << "1. Student\n";
                std::cout << "2. Administrator\n";
                std::cout << "3. Exit\n";
                int choice = getInput(1, 3);

                switch (choice)
                {
                        case 1:
                                runStudent();
                                break;
                        case 2:
                                runAdministrator();
                                break;
                        case 3:
                                return;
                }
        }
}

void UserInterface::runStudent()
{

}

void UserInterface::runAdministrator()
{
        while (true)
        {
                std::cout << "\nChoose An Option:\n";
                std::cout << "1. Add Resource\n";
                std::cout << "2. Remove Resource\n";
                std::cout << "3. Edit Resource\n";
                std::cout << "4. List All Resources\n";
                std::cout << "5. Exit\n";
                int choice = getInput(1, 5);
                std::cout << "\n";

                switch (choice)
                {
                        case 1:
                                addResource();
                                break;
                        case 2:
                                removeResource();
                                break;
                        case 3:
                                editResource();
                                break;
                        case 4:
                                rm.listResources();
                                break;
                        case 5:
                                return;
                }
        }
}

void UserInterface::addResource()
{
        std::unique_ptr<Resource> resource;

        int ID;
        std::string name;
        int beginningAvailabilityHour;
        int beginningAvailabilityMinute;
        int endAvailabilityHour;
        int endAvailabilityMinute;
        int availabilityInterval;

        std::cout << "Enter ID: ";
        std::cin >> ID;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Beginning Availability Hour: ";
        std::cin >> beginningAvailabilityHour;
        std::cout << "Enter Beginning Availability Minute: ";
        std::cin >> beginningAvailabilityMinute;
        std::cout << "Enter End Availability Hour: ";
        std::cin >> endAvailabilityHour;
        std::cout << "Enter End Availability Minute: ";
        std::cin >> endAvailabilityMinute;
        std::cout << "Enter Availability Interval: ";
        std::cin >> availabilityInterval;

        std::cout << "\nChoose A Resource Type:\n";
        std::cout << "1. Sports Court\n";
        std::cout << "2. Lab Equipment\n";
        int choice = getInput(1, 2);

        switch (choice)
        {
                case 1:
                        {
                                std::string sport;
                                int seatingCapacity;
                                std::cout << "Enter Sport: ";
                                std::getline(std::cin, sport);
                                std::cout << "Enter Seating Capacity: ";
                                std::cin >> seatingCapacity;
                                std::unique_ptr<SportCourt> sportCourt =
                                    std::make_unique<SportCourt>(
                                        ID, name, beginningAvailabilityHour,
                                        beginningAvailabilityMinute,
                                        endAvailabilityHour,
                                        endAvailabilityMinute,
                                        availabilityInterval, sport,
                                        seatingCapacity);
                                resource = std::move(sportCourt);
                                break;
                        }

                case 2:
                        {
                                std::string labName;
                                int groupNumber;
                                std::cout << "Enter Lab Name: ";
                                std::getline(std::cin, labName);
                                std::cout << "Enter Group Number: ";
                                std::cin >> groupNumber;
                                std::unique_ptr<LabEquipment> labEquipment =
                                    std::make_unique<LabEquipment>(
                                        ID, name, beginningAvailabilityHour,
                                        beginningAvailabilityMinute,
                                        endAvailabilityHour,
                                        endAvailabilityMinute,
                                        availabilityInterval, labName,
                                        groupNumber);
                                resource = std::move(labEquipment);
                                break;
                        }
        }

        rm.createResource(std::move(resource));
}

void UserInterface::removeResource()
{
        std::cout << "Enter the ID of the resource to delete: ";
        int id = getInput(0);
        rm.deleteResource(id);
}

void UserInterface::editResource()
{

}
