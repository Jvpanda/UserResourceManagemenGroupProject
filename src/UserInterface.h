#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <LabEquipment.h>
#include <ResourceManager.h>
#include <SportCourt.h>
#include <iostream>
#include <string>

class UserInterface
{

        private:
                ResourceManager rm;
                int getInput(int lowerBound, int upperBound = 999);

        public:
                void run();
                void runStudent();
                void runAdministrator();

                void addResource();
                void removeResource();
                void editResource();

};

#endif
